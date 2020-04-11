/*
===========================================================================
Copyright (C) 1999-2005 Id Software, Inc.

This file is part of Quake III Arena source code.

Quake III Arena source code is free software; you can redistribute it
and/or modify it under the terms of the GNU General Public License as
published by the Free Software Foundation; either version 2 of the License,
or (at your option) any later version.

Quake III Arena source code is distributed in the hope that it will be
useful, but WITHOUT ANY WARRANTY; without even the implied warranty of
MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
GNU General Public License for more details.

You should have received a copy of the GNU General Public License
along with Quake III Arena source code; if not, write to the Free Software
Foundation, Inc., 51 Franklin St, Fifth Floor, Boston, MA  02110-1301  USA
===========================================================================
*/
//
// cg_syscalls.c -- this file is only included when building a dll
// cg_syscalls.asm is included instead when building a qvm
#ifdef Q3_VM
#error "Do not use in VM build"
#endif

#include "cg_local.h"

static intptr_t(QDECL* syscall)(intptr_t arg, ...) = (intptr_t(QDECL*)(intptr_t, ...)) - 1;

Q_EXPORT void dllEntry(intptr_t(QDECL* syscallptr)(intptr_t arg, ...))
{
    syscall = syscallptr;
}

int PASSFLOAT(float x)
{
    floatint_t fi;
    fi.f = x;
    return fi.i;
}

void trap_Print(const char* fmt)
{
    syscall(CG_PRINT, fmt);
}

void trap_Error(const char* fmt)
{
    syscall(CG_ERROR, fmt);
    // shut up GCC warning about returning functions, because we know better
    exit(1);
}

int trap_Milliseconds(void)
{
    return syscall(CG_MILLISECONDS);
}

void trap_Cvar_Register(vmCvar_t* vmCvar, const char* varName, const char* defaultValue, int flags)
{
    syscall(CG_CVAR_REGISTER, vmCvar, varName, defaultValue, flags);
}

void trap_Cvar_Update(vmCvar_t* vmCvar)
{
    syscall(CG_CVAR_UPDATE, vmCvar);
}

void trap_Cvar_Set(const char* var_name, const char* value)
{
    syscall(CG_CVAR_SET, var_name, value);
}

/**
 * This trap copies the content of a cvar named by var_name into a mod-space string.
 * This is useful for obtaining cvar contents that are not bound, or cannot be bound,
 * to a vmCvar_t variable in the mod code.
 *
 * The terminating NULL is attached to the end of the copied string by this trap,
 * guaranteeing buffer holds a null-terminated string. The total number of characters copied,
 * including terminating NULL, fits within the size specified by bufsize, truncating the string if necessary.
 *
 * A nonexistent cvar provides an empty string. An existing cvar with empty content also provides an empty string.
 * Thus, this trap is not sufficient to determine if a cvar actually exists or not.
 *
 * This trap does not create a new cvar; to create a new cvar during run-time,
 * you can use trap_Cvar_Set or trap_SendConsoleCommand.
 *
 * @param var_name name of cvar (console variable).
 * @param buffer destination string buffer.
 * @param bufsize maximum limit of string buffer.
 */
void trap_Cvar_VariableStringBuffer(const char* var_name, char* buffer, int bufsize)
{
    syscall(CG_CVAR_VARIABLESTRINGBUFFER, var_name, buffer, bufsize);
}

int trap_Argc(void)
{
    return syscall(CG_ARGC);
}

void trap_Argv(int n, char* buffer, int bufferLength)
{
    syscall(CG_ARGV, n, buffer, bufferLength);
}

void trap_Args(char* buffer, int bufferLength)
{
    syscall(CG_ARGS, buffer, bufferLength);
}

int trap_FS_FOpenFile(const char* qpath, fileHandle_t* f, fsMode_t mode)
{
    return syscall(CG_FS_FOPENFILE, qpath, f, mode);
}

void trap_FS_Read(void* buffer, int len, fileHandle_t f)
{
    syscall(CG_FS_READ, buffer, len, f);
}

void trap_FS_Write(const void* buffer, int len, fileHandle_t f)
{
    syscall(CG_FS_WRITE, buffer, len, f);
}

void trap_FS_FCloseFile(fileHandle_t f)
{
    syscall(CG_FS_FCLOSEFILE, f);
}

int trap_FS_Seek(fileHandle_t f, long offset, int origin)
{
    return syscall(CG_FS_SEEK, f, offset, origin);
}

/**
 * The string provided by text is run as if typed as a command into the console. A leading slash (/) is not required.
 *
 * @param text The command to be executed.
 */
void trap_SendConsoleCommand(const char* text)
{
    syscall(CG_SENDCONSOLECOMMAND, text);
}

/**
 * The string cmdName is added to a tab-completion list for the console. Tab completion is case-insensitive,
 * but the completed string is rewritten with the stored capitalization.
 *
 * Commands added to the commands[] array are automatically addded for tab-completion
 * by the function CG_InitConsoleCommands(), and, in fact,
 * this is the only function that calls this trap in the baseq3 game source.
 *
 * @param cmdName Command name.
 */
void trap_AddCommand(const char* cmdName)
{
    syscall(CG_ADDCOMMAND, cmdName);
}

/**
 * Although this trap is not actually used anywhere in baseq3 game source,
 * a reasonable assumption, based on function name and parameters,
 * is that this trap removes a command name from the list of command completions.
 * That is, the inverse of trap_AddCommand().
 *
 * Unknown: case sensitivity (i.e. if capitalization matters for string matching).
 *
 * @param cmdName command name.
 */
void trap_RemoveCommand(const char* cmdName)
{
    syscall(CG_REMOVECOMMAND, cmdName);
}

/**
 * Sends command string as a client command directly to server.
 * In contrast, trap_SendConsoleCommand() sends the string to the local console first,
 * and, if not recognized there, sends to the server as a client command.
 *
 * This trap makes no distinction among EXEC_NOW, EXEC_INSERT,
 * or EXEC_APPEND as with trap_SendConsoleCommand(),
 * since the command is sent "somewhere else".
 *
 * The set of "client commands" is separate from "console commands",
 * so that a misbehaving client cannot kill a server by attempting to send "quit" as a command.
 *
 * In baseq3, the common SendClientCommand commands are "score" (to obtain information for scoreboard),
 * "tell" (chat, commands), and "vtell" (Q3TA chat with WAV playback).
 *
 * Beware of the server cvar sv_floodProtect. With it set to 1 (the default),
 * commands sent to the server using SendClientCommand in rapid succession will be silently dropped by the server.
 * In the case where some critical client->server communication is implemented using SendClientCommand,
 * it is important that sv_floodProtect is off.
 *
 * Note that chat flood protection can be fairly trivially implemented in the game module.
 *
 * @param s Command string.
 */
void trap_SendClientCommand(const char* s)
{
    syscall(CG_SENDCLIENTCOMMAND, s);
}

/**
 * trap_UpdateScreen updates the screen.
 *
 * cg_local.h says:
 * // force a screen update, only used during gamestate load
 * void trap_UpdateScreen( void );
 *
 * the Trap_UpdateScreen itself appears to be:
 * cg_syscalls.c
 * void trap_UpdateScreen( void ) {
 * syscall( CG_UPDATESCREEN );
 * }
 *
 * This is also called by:
 * UI_Atoms.C
 *
 * void UI_UpdateScreen( void ) {
 * trap_UpdateScreen();
 * }
 *
 *
 * it is also called by:
 * ui_local.h
 * void trap_R_DrawStretchPic(float x, float y, float w, float h, float s1, float t1, float s2, float t2, qhandle_t hShader);
 * void trap_UpdateScreen( void );
 * int trap_CM_LerpTag(orientation_t *tag, clipHandle_t mod, int startFrame, int endFrame, float frac, const char *tagName);
 *
 *
 * The locations of the calls and the remarks placed around it imply that
 * this trap is ONLY for updating the screen during connection to local or remote host.
 *
 * (eg: Loading....shotgun ; Loading.... Gauntlet ect... during the load of a map.)
 */
void trap_UpdateScreen(void)
{
    syscall(CG_UPDATESCREEN);
}

void trap_CM_LoadMap(const char* mapname)
{
    syscall(CG_CM_LOADMAP, mapname);
}

int trap_CM_NumInlineModels(void)
{
    return syscall(CG_CM_NUMINLINEMODELS);
}

clipHandle_t trap_CM_InlineModel(int index)
{
    return syscall(CG_CM_INLINEMODEL, index);
}

clipHandle_t trap_CM_TempBoxModel(const vec3_t mins, const vec3_t maxs)
{
    return syscall(CG_CM_TEMPBOXMODEL, mins, maxs);
}

clipHandle_t trap_CM_TempCapsuleModel(const vec3_t mins, const vec3_t maxs)
{
    return syscall(CG_CM_TEMPCAPSULEMODEL, mins, maxs);
}

int trap_CM_PointContents(const vec3_t p, clipHandle_t model)
{
    return syscall(CG_CM_POINTCONTENTS, p, model);
}

int trap_CM_TransformedPointContents(const vec3_t p, clipHandle_t model, const vec3_t origin, const vec3_t angles)
{
    return syscall(CG_CM_TRANSFORMEDPOINTCONTENTS, p, model, origin, angles);
}

void trap_CM_BoxTrace(trace_t* results, const vec3_t start, const vec3_t end,
    const vec3_t mins, const vec3_t maxs,
    clipHandle_t model, int brushmask)
{
    syscall(CG_CM_BOXTRACE, results, start, end, mins, maxs, model, brushmask);
}

void trap_CM_CapsuleTrace(trace_t* results, const vec3_t start, const vec3_t end,
    const vec3_t mins, const vec3_t maxs,
    clipHandle_t model, int brushmask)
{
    syscall(CG_CM_CAPSULETRACE, results, start, end, mins, maxs, model, brushmask);
}

void trap_CM_TransformedBoxTrace(trace_t* results, const vec3_t start, const vec3_t end,
    const vec3_t mins, const vec3_t maxs,
    clipHandle_t model, int brushmask,
    const vec3_t origin, const vec3_t angles)
{
    syscall(CG_CM_TRANSFORMEDBOXTRACE, results, start, end, mins, maxs, model, brushmask, origin, angles);
}

void trap_CM_TransformedCapsuleTrace(trace_t* results, const vec3_t start, const vec3_t end,
    const vec3_t mins, const vec3_t maxs,
    clipHandle_t model, int brushmask,
    const vec3_t origin, const vec3_t angles)
{
    syscall(CG_CM_TRANSFORMEDCAPSULETRACE, results, start, end, mins, maxs, model, brushmask, origin, angles);
}

int trap_CM_MarkFragments(int numPoints, const vec3_t* points,
    const vec3_t projection,
    int maxPoints, vec3_t pointBuffer,
    int maxFragments, markFragment_t* fragmentBuffer)
{
    return syscall(CG_CM_MARKFRAGMENTS, numPoints, points, projection, maxPoints, pointBuffer, maxFragments, fragmentBuffer);
}

void trap_S_StartSound(vec3_t origin, int entityNum, int entchannel, sfxHandle_t sfx)
{
    syscall(CG_S_STARTSOUND, origin, entityNum, entchannel, sfx);
}

void trap_S_StartLocalSound(sfxHandle_t sfx, int channelNum)
{
    syscall(CG_S_STARTLOCALSOUND, sfx, channelNum);
}

void trap_S_ClearLoopingSounds(qboolean killall)
{
    syscall(CG_S_CLEARLOOPINGSOUNDS, killall);
}

void trap_S_AddLoopingSound(int entityNum,
    const vec3_t origin, const vec3_t velocity, sfxHandle_t sfx)
{
    syscall(CG_S_ADDLOOPINGSOUND, entityNum, origin, velocity, sfx);
}

void trap_S_AddRealLoopingSound(int entityNum,
    const vec3_t origin, const vec3_t velocity, sfxHandle_t sfx)
{
    syscall(CG_S_ADDREALLOOPINGSOUND, entityNum, origin, velocity, sfx);
}

void trap_S_StopLoopingSound(int entityNum)
{
    syscall(CG_S_STOPLOOPINGSOUND, entityNum);
}

void trap_S_UpdateEntityPosition(int entityNum, const vec3_t origin)
{
    syscall(CG_S_UPDATEENTITYPOSITION, entityNum, origin);
}

void trap_S_Respatialize(int entityNum, const vec3_t origin, vec3_t axis[3], int inwater)
{
    syscall(CG_S_RESPATIALIZE, entityNum, origin, axis, inwater);
}

sfxHandle_t    trap_S_RegisterSound(const char* sample, qboolean compressed)
{
    return syscall(CG_S_REGISTERSOUND, sample, compressed);
}

void trap_S_StartBackgroundTrack(const char* intro, const char* loop)
{
    syscall(CG_S_STARTBACKGROUNDTRACK, intro, loop);
}

void trap_R_LoadWorldMap(const char* mapname)
{
    syscall(CG_R_LOADWORLDMAP, mapname);
}

qhandle_t trap_R_RegisterModel(const char* name)
{
    return syscall(CG_R_REGISTERMODEL, name);
}

qhandle_t trap_R_RegisterSkin(const char* name)
{
    return syscall(CG_R_REGISTERSKIN, name);
}

/**
 * This function registers the name shader and gives it a unique qhandle_t.
 *
 * @param name pointer to the name of the shader (?).
 * @return
 */
qhandle_t trap_R_RegisterShader(const char* name)
{
    return syscall(CG_R_REGISTERSHADER, name);
}

qhandle_t trap_R_RegisterShaderNoMip(const char* name)
{
    return syscall(CG_R_REGISTERSHADERNOMIP, name);
}

void trap_R_RegisterFont(const char* fontName, int pointSize, fontInfo_t* font)
{
    syscall(CG_R_REGISTERFONT, fontName, pointSize, font);
}

void trap_R_ClearScene(void)
{
    syscall(CG_R_CLEARSCENE);
}

/**
 * Physically added to the visuals in the game, after a new shader is set.
 * 
 * @param[in] Updated entity.
 */
void trap_R_AddRefEntityToScene(const refEntity_t* re)
{
    syscall(CG_R_ADDREFENTITYTOSCENE, re);
}

void trap_R_AddPolyToScene(qhandle_t hShader, int numVerts, const polyVert_t* verts)
{
    syscall(CG_R_ADDPOLYTOSCENE, hShader, numVerts, verts);
}

void trap_R_AddPolysToScene(qhandle_t hShader, int numVerts, const polyVert_t* verts, int num)
{
    syscall(CG_R_ADDPOLYSTOSCENE, hShader, numVerts, verts, num);
}

int        trap_R_LightForPoint(vec3_t point, vec3_t ambientLight, vec3_t directedLight, vec3_t lightDir)
{
    return syscall(CG_R_LIGHTFORPOINT, point, ambientLight, directedLight, lightDir);
}

/**
 * This function will add a light to the game at org, which has a radius of intensity units,
 * and the colour data which is shown in the variables r, g, and b. The highest number for an RGB index is 255,
 * but in Quake 3 the colour's index is divided by 255 to give a normalized value.
 *
 * Say I want to make a purple light. The colour data for purple in RGB is 255,0,255. So the normalized values for this colour are:
 *
 * 255/255 = 1.0
 * 0/255 = 0.0
 * 255/255 = 1.0
 *
 * o to add a purple light at the vector x, and radius 2.4 I would write:
 *
 * trap_R_AddLightToScene( x, 2.4, 1.0, 0.0, 1.0 );.
 *
 * @param org origin of the light - where the light will be.
 * @param intensity not the exact intensity of the light,
 *                  but the radius of the light -
 *                  the light is a sphere-like object and points within that object are lighted up,
 *                  and the closer something is to the origin of the light (org) the closer the
 *                  light will be to the actual colour data of the light.
 * @param r this is the colour data of the light (normalized, so the highest value, 255, is 1.0) -
 *        r is the amount of red light.
 * @param g green light.
 * @param b blue light.
 */
void trap_R_AddLightToScene(const vec3_t org, float intensity, float r, float g, float b)
{
    syscall(CG_R_ADDLIGHTTOSCENE, org, PASSFLOAT(intensity), PASSFLOAT(r), PASSFLOAT(g), PASSFLOAT(b));
}

void trap_R_AddAdditiveLightToScene(const vec3_t org, float intensity, float r, float g, float b)
{
    syscall(CG_R_ADDADDITIVELIGHTTOSCENE, org, PASSFLOAT(intensity), PASSFLOAT(r), PASSFLOAT(g), PASSFLOAT(b));
}

void trap_R_RenderScene(const refdef_t* fd)
{
    syscall(CG_R_RENDERSCENE, fd);
}

void trap_R_SetColor(const float* rgba)
{
    syscall(CG_R_SETCOLOR, rgba);
}

void trap_R_DrawStretchPic(float x, float y, float w, float h,
    float s1, float t1, float s2, float t2, qhandle_t hShader)
{
    syscall(CG_R_DRAWSTRETCHPIC, PASSFLOAT(x), PASSFLOAT(y), PASSFLOAT(w), PASSFLOAT(h), PASSFLOAT(s1), PASSFLOAT(t1), PASSFLOAT(s2), PASSFLOAT(t2), hShader);
}

void trap_R_ModelBounds(clipHandle_t model, vec3_t mins, vec3_t maxs)
{
    syscall(CG_R_MODELBOUNDS, model, mins, maxs);
}

int        trap_R_LerpTag(orientation_t* tag, clipHandle_t mod, int startFrame, int endFrame,
    float frac, const char* tagName)
{
    return syscall(CG_R_LERPTAG, tag, mod, startFrame, endFrame, PASSFLOAT(frac), tagName);
}

void trap_R_RemapShader(const char* oldShader, const char* newShader, const char* timeOffset)
{
    syscall(CG_R_REMAP_SHADER, oldShader, newShader, timeOffset);
}

void     trap_GetGlconfig(glconfig_t* glconfig)
{
    syscall(CG_GETGLCONFIG, glconfig);
}

void     trap_GetGameState(gameState_t* gamestate)
{
    syscall(CG_GETGAMESTATE, gamestate);
}

void     trap_GetCurrentSnapshotNumber(int* snapshotNumber, int* serverTime)
{
    syscall(CG_GETCURRENTSNAPSHOTNUMBER, snapshotNumber, serverTime);
}

qboolean    trap_GetSnapshot(int snapshotNumber, snapshot_t* snapshot)
{
    return syscall(CG_GETSNAPSHOT, snapshotNumber, snapshot);
}

qboolean    trap_GetServerCommand(int serverCommandNumber)
{
    return syscall(CG_GETSERVERCOMMAND, serverCommandNumber);
}

int            trap_GetCurrentCmdNumber(void)
{
    return syscall(CG_GETCURRENTCMDNUMBER);
}

qboolean    trap_GetUserCmd(int cmdNumber, usercmd_t* ucmd)
{
    return syscall(CG_GETUSERCMD, cmdNumber, ucmd);
}

void     trap_SetUserCmdValue(int stateValue, float sensitivityScale)
{
    syscall(CG_SETUSERCMDVALUE, stateValue, PASSFLOAT(sensitivityScale));
}

void     testPrintInt(char* string, int i)
{
    syscall(CG_TESTPRINTINT, string, i);
}

void     testPrintFloat(char* string, float f)
{
    syscall(CG_TESTPRINTFLOAT, string, PASSFLOAT(f));
}

int trap_MemoryRemaining(void)
{
    return syscall(CG_MEMORY_REMAINING);
}

/**
 * Returns true is the indicated key is held down, returns false if not held down (released).
 *
 * The values of keynum range from 0 to 255, inclusive.
 * For the most part, a key's keynum corresponds to its character's ASCII value (e.g. the 'A' key is 65).
 *
 * I have a list of keynames used by the bind command with their keynums which I may append at a later date.
 * In the meantime, if you want to know them now, you can do this:
 *
 * Create a keynums.cfg with a pattern like:
 * bind 0x00 Key 0x00
 * bind 0x01 Key 0x01
 * ...
 * bind 0xfe Key 0xfe
 * bind 0xff Key 0xff
 * (case matters for the hex values, and a scripting language to automate this really helps).
 *
 * Back up your q3config.cfg, run Q3, "/exec keynums.cfg; bindlist; condump keynums.txt; quit".
 *
 * In the file "keynums.txt" you should now have lines like:
 * UPARROW "Key 0x84"
 *
 * There's your keynum list.
 *
 * (Generating keynums.cfg in GNU bash:
 * for i in $(seq 0 255); do x=$(printf "%02x" $i); echo bind 0x$x Key 0x$x; done > keynums.cfg).
 *
 * @param keynum A key keynum.
 * @return
 */
qboolean trap_Key_IsDown(int keynum)
{
    return syscall(CG_KEY_ISDOWN, keynum);
}

/**
 * Returns a bitmask representing active key catchers.
 *
 * Bitmask values are:
 * KEYCATCH_CONSOLE
 * KEYCATCH_UI
 * KEYCATCH_MESSAGE
 * KEYCATCH_CGAME
 *
 * (see also trap_Key_SetCatcher())

 * To check if CGAME key-catching is active:
 * if (trap_Key_GetCatcher() & KEYCATCH_UI) {
 * //happy happy
 * }
 *
 * @return A bitmask representing active key catchers.
 */
int trap_Key_GetCatcher(void)
{
    return syscall(CG_KEY_GETCATCHER);
}

/**
 * Redirects key events to different module(s).
 *
 * Normally, key events are interpreted by the engine, affected by the key bindings.
 * This trap allows you redirect key events to other components.
 *
 * Valid catchers are:
 * KEYCATCH_CONSOLE: the console
 * KEYCATCH_UI: the ui module
 * KEYCATCH_MESSAGE: the little message editor thingy
 * KEYCATCH_CGAME: the cgame module
 *
 * These are bitmasked values, meaning you can combine them with the OR operator (|),
 * as in (KEYCATCH_UI|KEYCATCH_CGAME),
 * but I recommend against trying multiple catchers (it may get confusing).
 *
 * As a mods programmer, you may be most interested in KEYCATCH_CGAME, and on this I will concentrate this entry.
 *
 * --- The Keyboard ---

 * When key-catching is enabled (trap_Key_SetCatcher(KEYCATCH_CGAME);),
 * upon a change in key state (gets pressed or gets released),
 * the engine calls the vmMain() function in cg_main.c with the following parameters:
 * command = CG_KEY_EVENT
 * arg0 = keynum
 * arg1 = 1 if pressed, 0 if released.
 *
 * In baseq3 game source, this event is already handled and delegated to CG_KeyEvent(), which is empty.
 *
 * The values for keynum are the same as for trap_Key_IsDown().
 *
 * Key catching is disabled by calling with a parameter of 0 (as in, no catchers).
 * Key catching is also terminated if the user presses the ESC key, which means you won't receive events on the ESC key.
 *
 * --- The Mouse ---
 *
 * When key-catching is enabled, mouse movement is also redirected to the specified module.
 * When the engine detects mouse movement, it calls vmMain() with the following parameters:
 * command = CG_MOUSE_EVENT
 * arg0 = relative X position
 * arg1 = relative Y position
 *
 * The game source for baseq3 delegates this event to CG_MouseEvent().
 *
 * Pointer Device Movement - Reported Value:
 * Left - Negative X
 * Right - Positive X
 * Up - Negative Y
 * Down - Positive Y
 *
 * The engine only reports mouse movement -- if the mouse doesn't move, there is no mouse event.
 * The engine reports mouse buttons and wheels (if any) as key events, for binding purposes.
 *
 * Cvars do not influence the reported values.
 *
 * @param catcher Key catchers bitmask.
 */
void trap_Key_SetCatcher(int catcher)
{
    syscall(CG_KEY_SETCATCHER, catcher);
}

/**
 * Returns keynum of the key that has the binding specified by binding. Case-sensitive.
 *
 * Unknown: what happens when many keys have this binding.
 *
 * @param binding command string presumably bound to a key.
 * @return keynum of the key that has the binding specified by binding. Case-sensitive.
 */
int trap_Key_GetKey(const char* binding)
{
    return syscall(CG_KEY_GETKEY, binding);
}

int trap_PC_AddGlobalDefine(char* define)
{
    return syscall(CG_PC_ADD_GLOBAL_DEFINE, define);
}

int trap_PC_LoadSource(const char* filename)
{
    return syscall(CG_PC_LOAD_SOURCE, filename);
}

int trap_PC_FreeSource(int handle)
{
    return syscall(CG_PC_FREE_SOURCE, handle);
}

int trap_PC_ReadToken(int handle, pc_token_t* pc_token)
{
    return syscall(CG_PC_READ_TOKEN, handle, pc_token);
}

int trap_PC_SourceFileAndLine(int handle, char* filename, int* line)
{
    return syscall(CG_PC_SOURCE_FILE_AND_LINE, handle, filename, line);
}

void trap_S_StopBackgroundTrack(void)
{
    syscall(CG_S_STOPBACKGROUNDTRACK);
}

int trap_RealTime(qtime_t* qtime)
{
    return syscall(CG_REAL_TIME, qtime);
}

void trap_SnapVector(float* v)
{
    syscall(CG_SNAPVECTOR, v);
}

/**
 * This function loads up and begins playing an ROQ file at the coordinates given.
 * if the CIN_hold flag is specified, the ROQ is loaded in a paused state.
 * The function returns a handle to the cinematic instance or zero on failure.
 *
 * This returns a handle.  arg0 is the name in the format "idlogo.roq", set arg1 to NULL, alteredstates to qfalse (do not alter gamestate)
 *
 * @param arg0 The name of the .RoQ file to load.
 * @param xpos The X coordinate on-screen for the left edge of the cinematic display.
 * @param ypos The Y coordinate on-screen for the top edge of the cinematic display.
 * @param width The screen width of the cinematic display.
 * @param height The screen height of the cinematic display.
 * @param bits Combinations of the following flags: CIN_system, CIN_loop, CIN_hold, CIN_silent, CIN_shader.
 * @return
 */
int trap_CIN_PlayCinematic(const char* arg0, int xpos, int ypos, int width, int height, int bits)
{
    return syscall(CG_CIN_PLAYCINEMATIC, arg0, xpos, ypos, width, height, bits);
}

/**
 * Stops playing the cinematic and ends it.
 * Should always return FMV_EOF.
 * cinematics must be stopped in reverse order of when they are started.
 *
 * @param handle The handle returned by a previous call to trap_CIN_PlayCinematic.
 * @return
 */
e_status trap_CIN_StopCinematic(int handle)
{
    return syscall(CG_CIN_STOPCINEMATIC, handle);
}

/**
 * Will run a frame of the cinematic but will not draw it.
 * Will return FMV_EOF if the end of the cinematic has been reached.
 * @param handle A handle returned by a previous call to trap_CIN_PlayCinematic.
 * @return
 */
e_status trap_CIN_RunCinematic(int handle)
{
    return syscall(CG_CIN_RUNCINEMATIC, handle);
}

/**
 * This function renders the current frame of the cinematic to the screen with the current position coordinates.
 * Draws the current frame.
 *
 * @param handle A handle returned by a previous call to trap_CIN_PlayCinematic.
 */
void trap_CIN_DrawCinematic(int handle)
{
    syscall(CG_CIN_DRAWCINEMATIC, handle);
}

/**
 * Allows you to resize the animation dynamically.
 *
 * @param handle A handle returned by a previous call to trap_CIN_PlayCinematic
 * @param x the new X coordinate on-screen of the left edge of the cinematic.
 * @param y the new Y coordinate on-screen of the top edge of the cinematic.
 * @param w the new width on-screen of the cinematic.
 * @param h the new height on-screen of the cinematic.
 */
void trap_CIN_SetExtents(int handle, int x, int y, int w, int h)
{
    syscall(CG_CIN_SETEXTENTS, handle, x, y, w, h);
}

/*
qboolean trap_loadCamera( const char *name )
{
    return syscall( CG_LOADCAMERA, name );
}

void trap_startCamera(int time)
{
    syscall(CG_STARTCAMERA, time);
}

qboolean trap_getCameraInfo( int time, vec3_t *origin, vec3_t *angles)
{
    return syscall( CG_GETCAMERAINFO, time, origin, angles );
}
*/

qboolean trap_GetEntityToken(char* buffer, int bufferSize)
{
    return syscall(CG_GET_ENTITY_TOKEN, buffer, bufferSize);
}

qboolean trap_R_inPVS(const vec3_t p1, const vec3_t p2)
{
    return syscall(CG_R_INPVS, p1, p2);
}
