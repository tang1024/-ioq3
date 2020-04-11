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
#include "g_local.h"

// this file is only included when building a dll
// g_syscalls.asm is included instead when building a qvm
#ifdef Q3_VM
#error "Do not use in VM build"
#endif

/// Traps's function point whose value is assigned at run time by dllEntry().
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

/**
 * trap_Print prints the string pointed to by fmt to the Q3 Console.
 *
 * This should not usually be used directly by the user;
 * the G_Printf function provides its functionality and more.
 *
 * @param text Text to be displayed.
 */
void trap_Print(const char* text)
{
    syscall(G_PRINT, text);
}

/**
 * This is very similar to the trap_Print function with the exception
 * that this will halt execution of the module it is called from.
 *
 * Usually the user shouldn't call this directly, but using G_Error instead.
 *
 * @param text Text to be displayed.
 */
void trap_Error(const char* text)
{
    syscall(G_ERROR, text);
    // shut up GCC warning about returning functions, because we know better
    exit(1);
}

/**
 * Returns the number of milliseconds that have elapsed since Quake 3 was executed.
 * A Quake 3, multi-platform version of the Win32 function timeGetTime,
 * which also returns the number of milliseconds since the program was executed.
 *
 * @return The number of milliseconds that have elapsed since Quake 3 was executed.
 */
int trap_Milliseconds(void)
{
    return syscall(G_MILLISECONDS);
}

/**
 * Whenever a client issues a console command it can have arguments passed with it.
 *
 * @return The number of arguments identically to the argc found in C programs with this prototype for main:
 * int main( int argc, char **argv ).
 */
int trap_Argc(void)
{
    return syscall(G_ARGC);
}

/**
 * This will fill the buffer pointed to by buffer with an argument to a client command where n is the argument to return.
 * 0 is the command itself, 1 is the first argument and so on... Very similiar to char **argv in a C program.
 *
 * @param n The argument number to return.
 * @param buffer A point to a buffer to fill.
 * @param bufferLength The size of the buffer.
 */
void trap_Argv(int n, char* buffer, int bufferLength)
{
    syscall(G_ARGV, n, buffer, bufferLength);
}

/**
 * This opens a file specified by the string qpath and allocates a fileHandle_t (just a typedef int) to that file.
 * This is then used in subsequent operations involving the file.
 * The fsMode_t enumeration refers to the mode the file is opened in.
 * FS_READ for reading the file. FS_WRITE will create the file qpath if it doesn't exist or 0 length it if it does.
 * FS_APPEND allows writing to the end of an existing file.
 * FS_APPEND_SYNC is similar to FS_APPEND except you can read from the file at the same time.
 *
 * An int is returned representing the length of the file being opened.
 *
 * @param qpath The file to be opened.
 * @param f Reference to a local fileHandle_t.
 * @param mode Mode to open the file in.
 * @return
 */
int trap_FS_FOpenFile(const char* qpath, fileHandle_t* f, fsMode_t mode)
{
    return syscall(G_FS_FOPEN_FILE, qpath, f, mode);
}

/**
 * This reads len bytes of data from the file specified by f and fills buffer with it.
 *
 * @param buffer A buffer to fill.
 * @param len he amount to read from the file.
 * @param f A file handle provided by trap_FS_FOpenFile.
 */
void trap_FS_Read(void* buffer, int len, fileHandle_t f)
{
    syscall(G_FS_READ, buffer, len, f);
}

/**
 * This writes len bytes of data from buffer to the file specified by f.
 *
 * @param buffer A buffer to read from.
 * @param len The amount to write to the file.
 * @param f A file handle provided by trap_FS_FOpenFile.
 */
void trap_FS_Write(const void* buffer, int len, fileHandle_t f)
{
    syscall(G_FS_WRITE, buffer, len, f);
}

/**
 * Closes the file specified by f.
 *
 * @param f The file to be closed.
 */
void trap_FS_FCloseFile(fileHandle_t f)
{
    syscall(G_FS_FCLOSE_FILE, f);
}

/**
 * This fills listbuf with a NULL delimited list of all the files in the directory specified by path ending in extension.
 * The number of files listed is returned.
 *
 * @param path String reflecting a directory.
 * @param extension File extension to list (incluing a leading period).
 * @param listbuf Pointer to a buffer to fill.
 * @param bufsize Length of the buffer.
 * @return
 */
int trap_FS_GetFileList(const char* path, const char* extension, char* listbuf, int bufsize)
{
    return syscall(G_FS_GETFILELIST, path, extension, listbuf, bufsize);
}

int trap_FS_Seek(fileHandle_t f, long offset, int origin)
{
    return syscall(G_FS_SEEK, f, offset, origin);
}

/**
 * This call adds a command to the command buffer i.e.
 * so that the programmer may issue server commands that would normally need to be entered into the console.
 * exec_when takes an element of the cbufExec_t enumeration:
 *
 * Description of the EXEC_* values are described in q_shared.h.
 *
 * In general, EXEC_APPEND is the most common use, simulating the user typing in the command.
 * The string is stored to a buffer (appended) until a game frame is completed,
 * then the engine will examine the buffered strings to run.
 *
 * EXEC_NOW is a bad idea, as it can lead to an infinite loop: EXEC_NOW causes an immediate jump into engine space,
 * which then jumps back to QVM/mod space to execute commands,
 * which could lead to an immediate jump right back to engine space, which would lead to... and so on.
 *
 * Useless examples:
 * trap_SendConsoleCommand(EXEC_APPEND, "team free");
 * trap_SendConsoleCommand(EXEC_APPEND, "say Vini vidi vici.; quit");.
 *
 * @param exec_when When to execute this command: EXEC_NOW, EXEC_INSERT, EXEC_APPEND.
 * @param text The command to be executed.
 */
void trap_SendConsoleCommand(int exec_when, const char* text)
{
    syscall(G_SEND_CONSOLE_COMMAND, exec_when, text);
}

/**
 * This function is used to create a new vmCvar.
 * It sends all the information to the engine's main database and
 * then it stores a local copy of the data into the vmCvar_t passed as the first argument.
 *
 * @param cvar A pointer the location in which to store the local data.
 * @param var_name A null-terminated string that will be used to set the vmCvar's name field.
 * @param value A null-terminated string that will be used to set both the floating point and integer value fields of the vmCvar.
 * @param flags ?.
 */
void trap_Cvar_Register(vmCvar_t* cvar, const char* var_name, const char* value, int flags)
{
    syscall(G_CVAR_REGISTER, cvar, var_name, value, flags);
}

/**
 * This function first parses out the name of the vmCvar and then searches for the corresponding database entry.
 * Once it finds the vmCvar it will copy the "master copy" of the vmCvar into the local address provided.
 *
 * @param cvar A pointer to the vmCvar to update.
 */
void trap_Cvar_Update(vmCvar_t* cvar)
{
    syscall(G_CVAR_UPDATE, cvar);
}

/**
 * This function searchs for the name of the vmCvar and
 * stores the value into both the float and integer fields of the corresponding vmCvar entry.
 * The only way to effectly change the value of a vmCvar is to use this function,
 * the ANSI storage operator only modifies the local buffer and not the "master copy".
 *
 * @param var_name A null-terminated string containing the name of the vmCvar to set.
 * @param value A null-terminated string containing the desired value.
 */
void trap_Cvar_Set(const char* var_name, const char* value)
{
    syscall(G_CVAR_SET, var_name, value);
}

/**
 * This function returns the integer value of var_name that is currently stored in the "master copy".
 *
 * @param var_name A null-terminated string containing the name of the vmCvar to retrieve a value from.
 * @return The integer value of var_name that is currently stored in the "master copy".
 */
int trap_Cvar_VariableIntegerValue(const char* var_name)
{
    return syscall(G_CVAR_VARIABLE_INTEGER_VALUE, var_name);
}

/**
 *
 * @param var_name
 * @param buffer
 * @param bufsize
 */
void trap_Cvar_VariableStringBuffer(const char* var_name, char* buffer, int bufsize)
{
    syscall(G_CVAR_VARIABLE_STRING_BUFFER, var_name, buffer, bufsize);
}

/**
 * It would be very unusual for a mod programmer to want to call this -
 * especially with parameters other than those outlined above.
 * Its purpose it to notify the Q3 binary when new entities are created.
 * In the Q3 source it is used twice -
 * once on level load and in G_Spawn where it is called whenever an entity is created.
 *
 * @param gEnts Usually level.gentities.
 * @param numGEntities Usually level.num_entities.
 * @param sizeofGEntity_t Usually sizeof( gentity_t ).
 * @param clients Usually &level.clients;[0].ps.
 * @param sizeofGClient Usually sizeof( level.clients[0] ).
 */
void trap_LocateGameData(gentity_t* gEnts, int numGEntities, int sizeofGEntity_t,
    playerState_t* clients, int sizeofGClient)
{
    syscall(G_LOCATE_GAME_DATA, gEnts, numGEntities, sizeofGEntity_t, clients, sizeofGClient);
}

/**
 * This provides a mechanism to unconditionally drop a client from a server via their clientNum ( ent->client->ps.clientNum).
 * The reason is displayed to the client when they are dropped.
 *
 * @param clientNum The client to drop.
 * @param reason The reason for the drop.
 */
void trap_DropClient(int clientNum, const char* reason)
{
    syscall(G_DROP_CLIENT, clientNum, reason);
}

/**
 * This has the same effect as typing a command in a clients console for evaluation by the server.
 * This includes the commands evaluated in g_cmds.c.
 * Its main use in the Q3 source is to print information to a specific client's console via the "print" command.
 * Passing -1 as the clientNum sends the command to every client.
 *
 * @param clientNum The client that the command is being sent from.
 * @param text The command to be sent.
 */
void trap_SendServerCommand(int clientNum, const char* text)
{
    syscall(G_SEND_SERVER_COMMAND, clientNum, text);
}

/**
 * The Q3 Engine provides a mechanism for communicating data from the server to the client via config strings.
 * This is (presumably) an array of strings within the engine that are indexed by the CS_* values in bg_public.c.
 * This trap call sets one of these strings to a value.
 * Config strings should usually be used to communicate complex data that changes relatively rarely.
 *
 * @param num The config string to set.
 * @param string The value to set it to.
 */
void trap_SetConfigstring(int num, const char* string)
{
    syscall(G_SET_CONFIGSTRING, num, string);
}

/**
 * This is a server side callback used to get the value of a config string.
 * It is only used once in the q3 source,
 * by the G_FindConfigstringIndex function which in turn is used by the G_ModelIndex and G_SoundIndex functions.
 *
 * @param num The config string to be read.
 * @param buffer A pointer to a buffer to fill with the config string value.
 * @param bufferSize The size of the buffer.
 */
void trap_GetConfigstring(int num, char* buffer, int bufferSize)
{
    syscall(G_GET_CONFIGSTRING, num, buffer, bufferSize);
}

/**
 * Each client has a "user info" string which is a backslash delimited key/value pair for the various options the user can set.
 * For example, model, skin and weapon colour.
 * trap_GetUserinfo fills the buffer pointed to by *buffer with the userinfo of the client referenced by num.
 * Key values are then retrieved using Info_ValueForKey( buffer, keyname ).
 *
 * @param num clientNum of the userinfo to retrieve.
 * @param buffer Pointer to a buffer to fill.
 * @param bufferSize Size of the buffer.
 */
void trap_GetUserinfo(int num, char* buffer, int bufferSize)
{
    syscall(G_GET_USERINFO, num, buffer, bufferSize);
}

/**
 * This does the opposite to trap_GetUserinfo and sets a userinfo string for a user.
 * However, it is not used much in the Q3 source,
 * where config strings seem to be the prefered method to transfer userinfo to the client.
 *
 * @param num clientNum of userinfo to change.
 * @param buffer Userinfo string to set.
 */
void trap_SetUserinfo(int num, const char* buffer)
{
    syscall(G_SET_USERINFO, num, buffer);
}

/**
 * The "server info" string is a backslash delimited list of server variables such as g_gametype and mapname.
 * Besides the bot code, its only other use in the Q3 source is to print to the value of serverinfo to the logfile.
 *
 * @param buffer A buffer to fill with the server info.
 * @param bufferSize The size of the buffer.
 */
void trap_GetServerinfo(char* buffer, int bufferSize)
{
    syscall(G_GET_SERVERINFO, buffer, bufferSize);
}

/**
 * This function does several special things to an entity which should not be done any other way.
 *
 * - It sets the clipping bounds of the entity to use the collision map contained in the brush model specified.
 * Brush models have a complex collision map which is far more detailed than a regular bounding-box (doors, plats, movers etc).
 * The mins and maxes of a brush-model entity may differ wildly from reality.
 * - It sets the entity to have the SOLID_BMODEL type which serves to alert clients that
 * the modelindex used to render this entity is not in the regular list,
 * but instead is the index into the cgs.inlineDrawModel list which is built on start-up.
 * This list is zero-indexed from *1 and therefore does not contain the map itself.
 * Another method must be used to get the client to render the map a second time.
 * - It sets the "bmodel" member of the entityShared_t structure to 1
 * (entityShared_t is the "r" member of the gentity_t structure).
 * This allows a simple method of checking if an entity uses a brush model.
 *
 * There is nothing to prevent an entity from using a brush model which is not built into the map (not inline).
 * However this ability is not used anywhere in Q3A or Q3TA.
 * The map compilers have special command-line switches to build BSPs which are externally lit and
 * designed to be stand-alone models.
 * If this is attempted the cgame QVM will require special code
 * (a bit-flag or similar) to allow it to know the difference between a brush-model index that
 * is inline and one that is external.
 *
 * And thats' the last function in the game list!!.
 *
 * @param ent The entity to apply the collision map to.
 * @param name The name of the brush model. If the model is inline (built into the map) it will "*0", "*1", "*n".
 *             These names are generated by the map compiler and cannot be changed. "*0" is always the map itself.
 *             If the model is external to the map then it is the filename of the BSP
 *             (another map is technically valid as a stand-alone model
 *             though it is not externally lit and all external surfaces are backfaced culled).
 */
void trap_SetBrushModel(gentity_t* ent, const char* name)
{
    syscall(G_SET_BRUSH_MODEL, ent, name);
}

/**
 * This function is used to trace from one position to another in the BSP tree and store the results in a trace_t structure.
 *
 * The results consist of the following information (where tr is a variable of type trace_t):
 * 
 * - tr.allsolid:     If this is qtrue, then the area (or some part of it) between the mins and maxs is inside a solid (a brush).
 * - tr.contents:     The contents mask of the plane that the trace hit.
 * - tr.endpos:       Position where the trace ended.
 * - tr.entityNum:    Entity number of the entity that the trace hit.
 *                    If it hit solid geometry then this will equal ENTITYNUM_WORLD.
 * - tr.fraction:     This is the fraction of the vector between start and end where the trace ended.
 *                    Therefore if this is less than 1.0 the trace hit something.
 * - tr.plane:        Information about the plane that was hit (most notably the surface normal) stored in a cplane_t structure.
 * - tr.startsolid:   If this is qtrue, then the trace started in a solid (brush).
 * - tr.surfaceFlags: surfaceflags of the surface that was hit (look in surfaceflags.h at the SURF_* constants to see the which ones there are).
 *
 * If the mins and maxs are NULL then the trace is treated as purely linear from point to point.
 * 
 * If mins and maxs are defined however a bounding box trace is performed whereby rather than
 * a point the entire bounding box is traced so that it is possible to detect the collision between solid entities.
 * For example, tracing directly downwards onto a floor with mins and maxs set to { -15, -15, -15 } and
 * { 15, 15, 15 } respectively starting at some point above the floor will result in a trace_t with an endpoint 15 units from the floor.
 *
 * @param results       Pointer to a variable of type trace_t where the result of the trace will be stored.
 * @param start         Vector representing the starting position of the trace.
 * @param mins          Vector representing the mins of the bounding box the trace will have.
 * @param maxs          Vector representing the maxs of the bounding box the trace will have.
 * @param end           Vector representing the end position of the trace (it's destination).
 * @param passEntityNum The trace will not collide against the entity with this number
 *                      (usually set to the entity number of the entity that initiated the trace so it won't collide against itself).
 * @param contentmask   The content mask it should collide against. Use any of the MASK_ or CONTENTS_ constants.
 *                      You can logical OR several of them together if needed.
 */
void trap_Trace(trace_t* results,
    const vec3_t start,
    const vec3_t mins, const vec3_t maxs,
    const vec3_t end, int passEntityNum, int contentmask)
{
    syscall(G_TRACE, results, start, mins, maxs, end, passEntityNum, contentmask);
}

void trap_TraceCapsule(trace_t* results, const vec3_t start, const vec3_t mins, const vec3_t maxs,
    const vec3_t end, int passEntityNum, int contentmask)
{
    syscall(G_TRACECAPSULE, results, start, mins, maxs, end, passEntityNum, contentmask);
}

/**
 * This trap call returns the CONTENTS_* of a specific point in space -
 * it is commonly used to avoid spawning items in CONTENTS_NODROP areas.
 *
 * The second parameter specifies an entityNum (ent->s.number) which is ignored when evaluating the contents for a point.
 *
 * @param point The point in space to be examined.
 * @param passEntityNum An entityNum to be ignored.
 * @return The CONTENTS_* of the specific point in space.
 */
int trap_PointContents(const vec3_t point, int passEntityNum)
{
    return syscall(G_POINT_CONTENTS, point, passEntityNum);
}

/**
 * Returns true if point1 can _potentially_ see point2.
 * Two points can return true, but not be visible to each other due to detail brushes, curves, etc.
 * A return value of false guarantees that the points can not see each other.
 * Normally used to test if two entities can potentially see each other,
 * point1 would be the currentOrigin of the first entitiy and point2 the currentOrigin of the second entity.
 * This function relies on the Potentially Visible Set,
 * and areaportal data generated during the BSP compiling of a map.
 *
 * @param p1 Absolute coordinates of point 1.
 * @param p2 Absolute coordinates of point 2.
 * @return
 */
qboolean trap_InPVS(const vec3_t p1, const vec3_t p2)
{
    return syscall(G_IN_PVS, p1, p2);
}

/**
 * Returns true if point1 can _potentially_ see point2.
 * This function does not check areaportals.
 * Points hidden by closed doors (and other areaportals) will still return true.
 *
 * @param p1 Absolute coordinates of point 1.
 * @param p2 Absolute coordinates of point 2.
 * @return
 */
qboolean trap_InPVSIgnorePortals(const vec3_t p1, const vec3_t p2)
{
    return syscall(G_IN_PVS_IGNORE_PORTALS, p1, p2);
}

/**
 * Adjusts the state of a portal connecting two areas.
 * Set "open" to true to allow visibility through the portal and false to block visibility.
 * This is normally used to adjust visibility when opening and closing doors. When the door is open;
 * "open" is set true and entities are visible through the door,
 * when the door is closed; "open" is set false and trap_InPVS will not see entities through the door.
 * See Use_BinaryMover in the game source for an example.
 *
 * @param ent Entity to adjust.
 * @param open State to adjust to.
 */
void trap_AdjustAreaPortalState(gentity_t* ent, qboolean open)
{
    syscall(G_ADJUST_AREA_PORTAL_STATE, ent, open);
}

/**
 * This functions tests whether or not the areas (presumably leaf nodes of the bsp tree) are adjacent physically.
 * FIXME: the values of area1 and area2 are unknown, however.
 *
 * @param area1 First area to test.
 * @param area2 Second area to test.
 * @return
 */
qboolean trap_AreasConnected(int area1, int area2)
{
    return syscall(G_AREAS_CONNECTED, area1, area2);
}

/**
 * When an entity is "linked" it is subject to all evaluations that the world performs on it.
 * For example, all linked entities are accounted for when performing a trace.
 * Newly created entities are not linked into the world - they must be explcitly linked using this call.
 * Linking an entity that is already linked into the world has no effect unless the following properties have changed:
 * - Its origin or angles have changed which might cause a change in the entity's PVS (ent->r.currentOrigin is used to calculate the entity's PVS cluster)
 * - Its bounds have changed (again, is used in PVS cluster calculations, and to set abs(min/max))
 * - Its contents have changed (will set ent->s.solid)
 * - Its brush model has changed (again, sets ent->s.solid)
 *
 * @param ent Entity to be linked.
 */
void trap_LinkEntity(gentity_t* ent)
{
    syscall(G_LINKENTITY, ent);
}

/**
 * When an entity is "unlinked" from the world it remains in memory,
 * but ceases to exist from the point of view of the world.
 * This is useful for temporarily deleting an entity or when performing major alterations to an entity's fields.
 * Unlinking an entity that is already unlinked has no effect.
 *
 * @param ent Entity to be unlinked.
 */
void trap_UnlinkEntity(gentity_t* ent)
{
    syscall(G_UNLINKENTITY, ent);
}

/**
 * This fills an array of ints with the entity numbers (ent->s.number) of all the entities currently
 * within the cuboid defined by mins and maxs.
 *
 * Two vectors - mins and maxs - to be passed in,
 * representing the extents (or farthest points) of an invisible box in the world of Q3.
 *
 * @param[in] mins      The position of the corner of a cuboid.
 * @param[in] maxs      The position of the opposite corner of this cuboid.
 * @param[in, out] list A array of integers(entityNum's (entity indices)) to hold any entities that positively past the
 *                      test for existence within the box’s boundaries.
 * @param[in] maxcount  The maximum amount of entities that will be returned by the parameter, list.
 * @return              The number of all entities that were successfully found in the box.
 */
int trap_EntitiesInBox(const vec3_t mins, const vec3_t maxs, int* list, int maxcount)
{
    return syscall(G_ENTITIES_IN_BOX, mins, maxs, list, maxcount);
}

qboolean trap_EntityContact(const vec3_t mins, const vec3_t maxs, const gentity_t* ent)
{
    return syscall(G_ENTITY_CONTACT, mins, maxs, ent);
}

/**
 * If the entity pointed to by ent is physically within the bounds specified by mins and maxs then this function returns qtrue.
 *
 * @param mins Lower bounds.
 * @param maxs Upper bounds.
 * @param ent The entity to test.
 * @return
 */
qboolean trap_EntityContactCapsule(const vec3_t mins, const vec3_t maxs, const gentity_t* ent)
{
    return syscall(G_ENTITY_CONTACTCAPSULE, mins, maxs, ent);
}

/**
 * Allocates a free client slot and returns the client number.
 * Also marks the client as bot in the engine
 * (arg2 will be 1 when a GAME_CLIENT_CONNECT message is dispatched to vmMain for this client).
 *
 * On failure, -1 is returned.
 */
int trap_BotAllocateClient(void)
{
    return syscall(G_BOT_ALLOCATE_CLIENT);
}

void trap_BotFreeClient(int clientNum)
{
    syscall(G_BOT_FREE_CLIENT, clientNum);
}

/**
 * This function will retrieve the usercmd_t generated by the client portion of the Q3 binary and place it in what it pointed to by cmd.
 *
 * @param clientNum The clientNum to retreive cmd from.
 * @param cmd Pointer to a usercmd_t to fill.
 */
void trap_GetUsercmd(int clientNum, usercmd_t* cmd)
{
    syscall(G_GET_USERCMD, clientNum, cmd);
}

/**
 * This call fills the buffer pointed to by buffer with all the key/value pairs of every map entity.
 * The string returned has a very similar format to that of the tail end of a GTKRadiant .map file before it is compiled to a bsp.
 * It is unlikely that a user would ever need to call this since it is handled already in g_spawn.c.
 *
 * @param buffer A buffer to fill.
 * @param bufferSize The size of the buffer.
 * @return
 */
qboolean trap_GetEntityToken(char* buffer, int bufferSize)
{
    return syscall(G_GET_ENTITY_TOKEN, buffer, bufferSize);
}

/**
 * Creates a solid coloured permanent polygon in the renderer (and world) based on the given array of vertices/points.
 * it returns a reference handle to the polygon as it appears in the renderlist.
 * This function should be disabled, but it may still work.
 *
 * In Q3 1.31, only a single debug polygon can be displayed at once.
 * Calling trap_DebugPolygonCreate() to draw a second polygon causes none of them to be drawn on the screen.
 * Delete the old polygon before trying to draw the new one.
 *
 * @param color
 * @param numPoints
 * @param points
 * @return
 */
int trap_DebugPolygonCreate(int color, int numPoints, vec3_t* points)
{
    return syscall(G_DEBUG_POLYGON_CREATE, color, numPoints, points);
}

/**
 * Removes a polygon that was previously created via trap_DebugPolygonCreate.
 *
 * @param id a value previously returned by trap_DebugPolygonCreate.
 */
void trap_DebugPolygonDelete(int id)
{
    syscall(G_DEBUG_POLYGON_DELETE, id);
}

/**
 * Returns current system time and date at server.
 *
 * @param qtime Point in time - look at q_shared.h qtime_t for details.
 * @return The current system time and date at server.
 */
int trap_RealTime(qtime_t* qtime)
{
    return syscall(G_REAL_TIME, qtime);
}

/**
 * This simply removes the fractional part of each axis of v - a form of "snap to grid".
 * Its purpose is to save network bandwidth by exploiting the fact that
 * delta compression will only transmit the changes in state of a struct.
 * A changing vector will change less frequently if only the integral part is taken into account.
 *
 * @param v Vector to snap.
 */
void trap_SnapVector(float* v)
{
    syscall(G_SNAPVECTOR, v);
}

// BotLib traps start here
int trap_BotLibSetup(void)
{
    return syscall(BOTLIB_SETUP);
}

int trap_BotLibShutdown(void)
{
    return syscall(BOTLIB_SHUTDOWN);
}

int trap_BotLibVarSet(char* var_name, char* value)
{
    return syscall(BOTLIB_LIBVAR_SET, var_name, value);
}

int trap_BotLibVarGet(char* var_name, char* value, int size)
{
    return syscall(BOTLIB_LIBVAR_GET, var_name, value, size);
}

int trap_BotLibDefine(char* string)
{
    return syscall(BOTLIB_PC_ADD_GLOBAL_DEFINE, string);
}

int trap_BotLibStartFrame(float time)
{
    return syscall(BOTLIB_START_FRAME, PASSFLOAT(time));
}

int trap_BotLibLoadMap(const char* mapname)
{
    return syscall(BOTLIB_LOAD_MAP, mapname);
}

int trap_BotLibUpdateEntity(int ent, void /* struct bot_updateentity_s */* bue)
{
    return syscall(BOTLIB_UPDATENTITY, ent, bue);
}

int trap_BotLibTest(int parm0, char* parm1, vec3_t parm2, vec3_t parm3)
{
    return syscall(BOTLIB_TEST, parm0, parm1, parm2, parm3);
}

int trap_BotGetSnapshotEntity(int clientNum, int sequence)
{
    return syscall(BOTLIB_GET_SNAPSHOT_ENTITY, clientNum, sequence);
}

int trap_BotGetServerCommand(int clientNum, char* message, int size)
{
    return syscall(BOTLIB_GET_CONSOLE_MESSAGE, clientNum, message, size);
}

void trap_BotUserCommand(int clientNum, usercmd_t* ucmd)
{
    syscall(BOTLIB_USER_COMMAND, clientNum, ucmd);
}

void trap_AAS_EntityInfo(int entnum, void /* struct aas_entityinfo_s */* info)
{
    syscall(BOTLIB_AAS_ENTITY_INFO, entnum, info);
}

int trap_AAS_Initialized(void)
{
    return syscall(BOTLIB_AAS_INITIALIZED);
}

void trap_AAS_PresenceTypeBoundingBox(int presencetype, vec3_t mins, vec3_t maxs)
{
    syscall(BOTLIB_AAS_PRESENCE_TYPE_BOUNDING_BOX, presencetype, mins, maxs);
}

float trap_AAS_Time(void)
{
    floatint_t fi;
    fi.i = syscall(BOTLIB_AAS_TIME);
    return fi.f;
}

int trap_AAS_PointAreaNum(vec3_t point)
{
    return syscall(BOTLIB_AAS_POINT_AREA_NUM, point);
}

int trap_AAS_PointReachabilityAreaIndex(vec3_t point)
{
    return syscall(BOTLIB_AAS_POINT_REACHABILITY_AREA_INDEX, point);
}

int trap_AAS_TraceAreas(vec3_t start, vec3_t end, int* areas, vec3_t* points, int maxareas)
{
    return syscall(BOTLIB_AAS_TRACE_AREAS, start, end, areas, points, maxareas);
}

int trap_AAS_BBoxAreas(vec3_t absmins, vec3_t absmaxs, int* areas, int maxareas)
{
    return syscall(BOTLIB_AAS_BBOX_AREAS, absmins, absmaxs, areas, maxareas);
}

int trap_AAS_AreaInfo(int areanum, void /* struct aas_areainfo_s */* info)
{
    return syscall(BOTLIB_AAS_AREA_INFO, areanum, info);
}

int trap_AAS_PointContents(vec3_t point)
{
    return syscall(BOTLIB_AAS_POINT_CONTENTS, point);
}

int trap_AAS_NextBSPEntity(int ent)
{
    return syscall(BOTLIB_AAS_NEXT_BSP_ENTITY, ent);
}

int trap_AAS_ValueForBSPEpairKey(int ent, char* key, char* value, int size)
{
    return syscall(BOTLIB_AAS_VALUE_FOR_BSP_EPAIR_KEY, ent, key, value, size);
}

int trap_AAS_VectorForBSPEpairKey(int ent, char* key, vec3_t v)
{
    return syscall(BOTLIB_AAS_VECTOR_FOR_BSP_EPAIR_KEY, ent, key, v);
}

int trap_AAS_FloatForBSPEpairKey(int ent, char* key, float* value)
{
    return syscall(BOTLIB_AAS_FLOAT_FOR_BSP_EPAIR_KEY, ent, key, value);
}

int trap_AAS_IntForBSPEpairKey(int ent, char* key, int* value)
{
    return syscall(BOTLIB_AAS_INT_FOR_BSP_EPAIR_KEY, ent, key, value);
}

int trap_AAS_AreaReachability(int areanum)
{
    return syscall(BOTLIB_AAS_AREA_REACHABILITY, areanum);
}

int trap_AAS_AreaTravelTimeToGoalArea(int areanum, vec3_t origin, int goalareanum, int travelflags)
{
    return syscall(BOTLIB_AAS_AREA_TRAVEL_TIME_TO_GOAL_AREA, areanum, origin, goalareanum, travelflags);
}

int trap_AAS_EnableRoutingArea(int areanum, int enable)
{
    return syscall(BOTLIB_AAS_ENABLE_ROUTING_AREA, areanum, enable);
}

int trap_AAS_PredictRoute(void /*struct aas_predictroute_s*/* route, int areanum, vec3_t origin,
    int goalareanum, int travelflags, int maxareas, int maxtime,
    int stopevent, int stopcontents, int stoptfl, int stopareanum)
{
    return syscall(BOTLIB_AAS_PREDICT_ROUTE, route, areanum, origin, goalareanum, travelflags, maxareas,
        maxtime, stopevent, stopcontents, stoptfl, stopareanum);
}

int trap_AAS_AlternativeRouteGoals(vec3_t start, int startareanum, vec3_t goal, int goalareanum, int travelflags,
    void /*struct aas_altroutegoal_s*/* altroutegoals, int maxaltroutegoals, int type)
{
    return syscall(BOTLIB_AAS_ALTERNATIVE_ROUTE_GOAL, start, startareanum, goal, goalareanum, travelflags,
        altroutegoals, maxaltroutegoals, type);
}

int trap_AAS_Swimming(vec3_t origin)
{
    return syscall(BOTLIB_AAS_SWIMMING, origin);
}

int trap_AAS_PredictClientMovement(void /* struct aas_clientmove_s */* move, int entnum, vec3_t origin,
    int presencetype, int onground, vec3_t velocity, vec3_t cmdmove, int cmdframes,
    int maxframes, float frametime, int stopevent, int stopareanum, int visualize)
{
    return syscall(BOTLIB_AAS_PREDICT_CLIENT_MOVEMENT, move, entnum, origin, presencetype, onground, velocity,
        cmdmove, cmdframes, maxframes, PASSFLOAT(frametime), stopevent, stopareanum, visualize);
}

void trap_EA_Say(int client, char* str)
{
    syscall(BOTLIB_EA_SAY, client, str);
}

void trap_EA_SayTeam(int client, char* str)
{
    syscall(BOTLIB_EA_SAY_TEAM, client, str);
}

void trap_EA_Command(int client, char* command)
{
    syscall(BOTLIB_EA_COMMAND, client, command);
}

void trap_EA_Action(int client, int action)
{
    syscall(BOTLIB_EA_ACTION, client, action);
}

void trap_EA_Gesture(int client)
{
    syscall(BOTLIB_EA_GESTURE, client);
}

void trap_EA_Talk(int client)
{
    syscall(BOTLIB_EA_TALK, client);
}

void trap_EA_Attack(int client)
{
    syscall(BOTLIB_EA_ATTACK, client);
}

void trap_EA_Use(int client)
{
    syscall(BOTLIB_EA_USE, client);
}

void trap_EA_Respawn(int client)
{
    syscall(BOTLIB_EA_RESPAWN, client);
}

void trap_EA_Crouch(int client)
{
    syscall(BOTLIB_EA_CROUCH, client);
}

void trap_EA_MoveUp(int client)
{
    syscall(BOTLIB_EA_MOVE_UP, client);
}

void trap_EA_MoveDown(int client)
{
    syscall(BOTLIB_EA_MOVE_DOWN, client);
}

void trap_EA_MoveForward(int client)
{
    syscall(BOTLIB_EA_MOVE_FORWARD, client);
}

void trap_EA_MoveBack(int client)
{
    syscall(BOTLIB_EA_MOVE_BACK, client);
}

void trap_EA_MoveLeft(int client)
{
    syscall(BOTLIB_EA_MOVE_LEFT, client);
}

void trap_EA_MoveRight(int client)
{
    syscall(BOTLIB_EA_MOVE_RIGHT, client);
}

void trap_EA_SelectWeapon(int client, int weapon)
{
    syscall(BOTLIB_EA_SELECT_WEAPON, client, weapon);
}

void trap_EA_Jump(int client)
{
    syscall(BOTLIB_EA_JUMP, client);
}

void trap_EA_DelayedJump(int client)
{
    syscall(BOTLIB_EA_DELAYED_JUMP, client);
}

void trap_EA_Move(int client, vec3_t dir, float speed)
{
    syscall(BOTLIB_EA_MOVE, client, dir, PASSFLOAT(speed));
}

void trap_EA_View(int client, vec3_t viewangles)
{
    syscall(BOTLIB_EA_VIEW, client, viewangles);
}

void trap_EA_EndRegular(int client, float thinktime)
{
    syscall(BOTLIB_EA_END_REGULAR, client, PASSFLOAT(thinktime));
}

void trap_EA_GetInput(int client, float thinktime, void /* struct bot_input_s */* input)
{
    syscall(BOTLIB_EA_GET_INPUT, client, PASSFLOAT(thinktime), input);
}

void trap_EA_ResetInput(int client)
{
    syscall(BOTLIB_EA_RESET_INPUT, client);
}

int trap_BotLoadCharacter(char* charfile, float skill)
{
    return syscall(BOTLIB_AI_LOAD_CHARACTER, charfile, PASSFLOAT(skill));
}

void trap_BotFreeCharacter(int character)
{
    syscall(BOTLIB_AI_FREE_CHARACTER, character);
}

float trap_Characteristic_Float(int character, int index)
{
    floatint_t fi;
    fi.i = syscall(BOTLIB_AI_CHARACTERISTIC_FLOAT, character, index);
    return fi.f;
}

float trap_Characteristic_BFloat(int character, int index, float min, float max)
{
    floatint_t fi;
    fi.i = syscall(BOTLIB_AI_CHARACTERISTIC_BFLOAT, character, index, PASSFLOAT(min), PASSFLOAT(max));
    return fi.f;
}

int trap_Characteristic_Integer(int character, int index)
{
    return syscall(BOTLIB_AI_CHARACTERISTIC_INTEGER, character, index);
}

int trap_Characteristic_BInteger(int character, int index, int min, int max)
{
    return syscall(BOTLIB_AI_CHARACTERISTIC_BINTEGER, character, index, min, max);
}

void trap_Characteristic_String(int character, int index, char* buf, int size)
{
    syscall(BOTLIB_AI_CHARACTERISTIC_STRING, character, index, buf, size);
}

int trap_BotAllocChatState(void)
{
    return syscall(BOTLIB_AI_ALLOC_CHAT_STATE);
}

void trap_BotFreeChatState(int handle)
{
    syscall(BOTLIB_AI_FREE_CHAT_STATE, handle);
}

void trap_BotQueueConsoleMessage(int chatstate, int type, char* message)
{
    syscall(BOTLIB_AI_QUEUE_CONSOLE_MESSAGE, chatstate, type, message);
}

void trap_BotRemoveConsoleMessage(int chatstate, int handle)
{
    syscall(BOTLIB_AI_REMOVE_CONSOLE_MESSAGE, chatstate, handle);
}

int trap_BotNextConsoleMessage(int chatstate, void /* struct bot_consolemessage_s */* cm)
{
    return syscall(BOTLIB_AI_NEXT_CONSOLE_MESSAGE, chatstate, cm);
}

int trap_BotNumConsoleMessages(int chatstate)
{
    return syscall(BOTLIB_AI_NUM_CONSOLE_MESSAGE, chatstate);
}

void trap_BotInitialChat(int chatstate, char* type, int mcontext, char* var0, char* var1, char* var2, char* var3,
    char* var4, char* var5, char* var6, char* var7)
{
    syscall(BOTLIB_AI_INITIAL_CHAT, chatstate, type, mcontext, var0, var1, var2, var3, var4, var5, var6, var7);
}

int trap_BotNumInitialChats(int chatstate, char* type)
{
    return syscall(BOTLIB_AI_NUM_INITIAL_CHATS, chatstate, type);
}

int trap_BotReplyChat(int chatstate, char* message, int mcontext, int vcontext, char* var0, char* var1, char* var2,
    char* var3, char* var4, char* var5, char* var6, char* var7)
{
    return syscall(BOTLIB_AI_REPLY_CHAT, chatstate, message, mcontext, vcontext, var0, var1, var2, var3, var4, var5, var6, var7);
}

int trap_BotChatLength(int chatstate)
{
    return syscall(BOTLIB_AI_CHAT_LENGTH, chatstate);
}

void trap_BotEnterChat(int chatstate, int client, int sendto)
{
    syscall(BOTLIB_AI_ENTER_CHAT, chatstate, client, sendto);
}

void trap_BotGetChatMessage(int chatstate, char* buf, int size)
{
    syscall(BOTLIB_AI_GET_CHAT_MESSAGE, chatstate, buf, size);
}

int trap_StringContains(char* str1, char* str2, int casesensitive)
{
    return syscall(BOTLIB_AI_STRING_CONTAINS, str1, str2, casesensitive);
}

int trap_BotFindMatch(char* str, void /* struct bot_match_s */* match, unsigned long int context)
{
    return syscall(BOTLIB_AI_FIND_MATCH, str, match, context);
}

void trap_BotMatchVariable(void /* struct bot_match_s */* match, int variable, char* buf, int size)
{
    syscall(BOTLIB_AI_MATCH_VARIABLE, match, variable, buf, size);
}

void trap_UnifyWhiteSpaces(char* string)
{
    syscall(BOTLIB_AI_UNIFY_WHITE_SPACES, string);
}

void trap_BotReplaceSynonyms(char* string, unsigned long int context)
{
    syscall(BOTLIB_AI_REPLACE_SYNONYMS, string, context);
}

int trap_BotLoadChatFile(int chatstate, char* chatfile, char* chatname)
{
    return syscall(BOTLIB_AI_LOAD_CHAT_FILE, chatstate, chatfile, chatname);
}

void trap_BotSetChatGender(int chatstate, int gender)
{
    syscall(BOTLIB_AI_SET_CHAT_GENDER, chatstate, gender);
}

void trap_BotSetChatName(int chatstate, char* name, int client)
{
    syscall(BOTLIB_AI_SET_CHAT_NAME, chatstate, name, client);
}

void trap_BotResetGoalState(int goalstate)
{
    syscall(BOTLIB_AI_RESET_GOAL_STATE, goalstate);
}

void trap_BotResetAvoidGoals(int goalstate)
{
    syscall(BOTLIB_AI_RESET_AVOID_GOALS, goalstate);
}

void trap_BotRemoveFromAvoidGoals(int goalstate, int number)
{
    syscall(BOTLIB_AI_REMOVE_FROM_AVOID_GOALS, goalstate, number);
}

void trap_BotPushGoal(int goalstate, void /* struct bot_goal_s */* goal)
{
    syscall(BOTLIB_AI_PUSH_GOAL, goalstate, goal);
}

void trap_BotPopGoal(int goalstate)
{
    syscall(BOTLIB_AI_POP_GOAL, goalstate);
}

void trap_BotEmptyGoalStack(int goalstate)
{
    syscall(BOTLIB_AI_EMPTY_GOAL_STACK, goalstate);
}

void trap_BotDumpAvoidGoals(int goalstate)
{
    syscall(BOTLIB_AI_DUMP_AVOID_GOALS, goalstate);
}

void trap_BotDumpGoalStack(int goalstate)
{
    syscall(BOTLIB_AI_DUMP_GOAL_STACK, goalstate);
}

void trap_BotGoalName(int number, char* name, int size)
{
    syscall(BOTLIB_AI_GOAL_NAME, number, name, size);
}

int trap_BotGetTopGoal(int goalstate, void /* struct bot_goal_s */* goal)
{
    return syscall(BOTLIB_AI_GET_TOP_GOAL, goalstate, goal);
}

int trap_BotGetSecondGoal(int goalstate, void /* struct bot_goal_s */* goal)
{
    return syscall(BOTLIB_AI_GET_SECOND_GOAL, goalstate, goal);
}

int trap_BotChooseLTGItem(int goalstate, vec3_t origin, int* inventory, int travelflags)
{
    return syscall(BOTLIB_AI_CHOOSE_LTG_ITEM, goalstate, origin, inventory, travelflags);
}

int trap_BotChooseNBGItem(int goalstate, vec3_t origin, int* inventory, int travelflags, void /* struct bot_goal_s */* ltg, float maxtime)
{
    return syscall(BOTLIB_AI_CHOOSE_NBG_ITEM, goalstate, origin, inventory, travelflags, ltg, PASSFLOAT(maxtime));
}

int trap_BotTouchingGoal(vec3_t origin, void /* struct bot_goal_s */* goal)
{
    return syscall(BOTLIB_AI_TOUCHING_GOAL, origin, goal);
}

int trap_BotItemGoalInVisButNotVisible(int viewer, vec3_t eye, vec3_t viewangles, void /* struct bot_goal_s */* goal)
{
    return syscall(BOTLIB_AI_ITEM_GOAL_IN_VIS_BUT_NOT_VISIBLE, viewer, eye, viewangles, goal);
}

int trap_BotGetLevelItemGoal(int index, char* classname, void /* struct bot_goal_s */* goal)
{
    return syscall(BOTLIB_AI_GET_LEVEL_ITEM_GOAL, index, classname, goal);
}

int trap_BotGetNextCampSpotGoal(int num, void /* struct bot_goal_s */* goal)
{
    return syscall(BOTLIB_AI_GET_NEXT_CAMP_SPOT_GOAL, num, goal);
}

int trap_BotGetMapLocationGoal(char* name, void /* struct bot_goal_s */* goal)
{
    return syscall(BOTLIB_AI_GET_MAP_LOCATION_GOAL, name, goal);
}

float trap_BotAvoidGoalTime(int goalstate, int number)
{
    floatint_t fi;
    fi.i = syscall(BOTLIB_AI_AVOID_GOAL_TIME, goalstate, number);
    return fi.f;
}

void trap_BotSetAvoidGoalTime(int goalstate, int number, float avoidtime)
{
    syscall(BOTLIB_AI_SET_AVOID_GOAL_TIME, goalstate, number, PASSFLOAT(avoidtime));
}

void trap_BotInitLevelItems(void)
{
    syscall(BOTLIB_AI_INIT_LEVEL_ITEMS);
}

void trap_BotUpdateEntityItems(void)
{
    syscall(BOTLIB_AI_UPDATE_ENTITY_ITEMS);
}

int trap_BotLoadItemWeights(int goalstate, char* filename)
{
    return syscall(BOTLIB_AI_LOAD_ITEM_WEIGHTS, goalstate, filename);
}

void trap_BotFreeItemWeights(int goalstate)
{
    syscall(BOTLIB_AI_FREE_ITEM_WEIGHTS, goalstate);
}

void trap_BotInterbreedGoalFuzzyLogic(int parent1, int parent2, int child)
{
    syscall(BOTLIB_AI_INTERBREED_GOAL_FUZZY_LOGIC, parent1, parent2, child);
}

void trap_BotSaveGoalFuzzyLogic(int goalstate, char* filename)
{
    syscall(BOTLIB_AI_SAVE_GOAL_FUZZY_LOGIC, goalstate, filename);
}

void trap_BotMutateGoalFuzzyLogic(int goalstate, float range)
{
    syscall(BOTLIB_AI_MUTATE_GOAL_FUZZY_LOGIC, goalstate, PASSFLOAT(range));
}

int trap_BotAllocGoalState(int state)
{
    return syscall(BOTLIB_AI_ALLOC_GOAL_STATE, state);
}

void trap_BotFreeGoalState(int handle)
{
    syscall(BOTLIB_AI_FREE_GOAL_STATE, handle);
}

void trap_BotResetMoveState(int movestate)
{
    syscall(BOTLIB_AI_RESET_MOVE_STATE, movestate);
}

void trap_BotAddAvoidSpot(int movestate, vec3_t origin, float radius, int type)
{
    syscall(BOTLIB_AI_ADD_AVOID_SPOT, movestate, origin, PASSFLOAT(radius), type);
}

void trap_BotMoveToGoal(void /* struct bot_moveresult_s */* result, int movestate,
    void /* struct bot_goal_s */* goal, int travelflags)
{
    syscall(BOTLIB_AI_MOVE_TO_GOAL, result, movestate, goal, travelflags);
}

int trap_BotMoveInDirection(int movestate, vec3_t dir, float speed, int type)
{
    return syscall(BOTLIB_AI_MOVE_IN_DIRECTION, movestate, dir, PASSFLOAT(speed), type);
}

void trap_BotResetAvoidReach(int movestate)
{
    syscall(BOTLIB_AI_RESET_AVOID_REACH, movestate);
}

void trap_BotResetLastAvoidReach(int movestate)
{
    syscall(BOTLIB_AI_RESET_LAST_AVOID_REACH, movestate);
}

int trap_BotReachabilityArea(vec3_t origin, int testground)
{
    return syscall(BOTLIB_AI_REACHABILITY_AREA, origin, testground);
}

int trap_BotMovementViewTarget(int movestate, void /* struct bot_goal_s */* goal, int travelflags, float lookahead, vec3_t target)
{
    return syscall(BOTLIB_AI_MOVEMENT_VIEW_TARGET, movestate, goal, travelflags, PASSFLOAT(lookahead), target);
}

int trap_BotPredictVisiblePosition(vec3_t origin, int areanum, void /* struct bot_goal_s */* goal, int travelflags, vec3_t target)
{
    return syscall(BOTLIB_AI_PREDICT_VISIBLE_POSITION, origin, areanum, goal, travelflags, target);
}

int trap_BotAllocMoveState(void)
{
    return syscall(BOTLIB_AI_ALLOC_MOVE_STATE);
}

void trap_BotFreeMoveState(int handle)
{
    syscall(BOTLIB_AI_FREE_MOVE_STATE, handle);
}

void trap_BotInitMoveState(int handle, void /* struct bot_initmove_s */* initmove)
{
    syscall(BOTLIB_AI_INIT_MOVE_STATE, handle, initmove);
}

int trap_BotChooseBestFightWeapon(int weaponstate, int* inventory)
{
    return syscall(BOTLIB_AI_CHOOSE_BEST_FIGHT_WEAPON, weaponstate, inventory);
}

void trap_BotGetWeaponInfo(int weaponstate, int weapon, void /* struct weaponinfo_s */* weaponinfo)
{
    syscall(BOTLIB_AI_GET_WEAPON_INFO, weaponstate, weapon, weaponinfo);
}

int trap_BotLoadWeaponWeights(int weaponstate, char* filename)
{
    return syscall(BOTLIB_AI_LOAD_WEAPON_WEIGHTS, weaponstate, filename);
}

int trap_BotAllocWeaponState(void)
{
    return syscall(BOTLIB_AI_ALLOC_WEAPON_STATE);
}

void trap_BotFreeWeaponState(int weaponstate)
{
    syscall(BOTLIB_AI_FREE_WEAPON_STATE, weaponstate);
}

void trap_BotResetWeaponState(int weaponstate)
{
    syscall(BOTLIB_AI_RESET_WEAPON_STATE, weaponstate);
}

int trap_GeneticParentsAndChildSelection(int numranks, float* ranks, int* parent1, int* parent2, int* child)
{
    return syscall(BOTLIB_AI_GENETIC_PARENTS_AND_CHILD_SELECTION, numranks, ranks, parent1, parent2, child);
}

int trap_PC_LoadSource(const char* filename)
{
    return syscall(BOTLIB_PC_LOAD_SOURCE, filename);
}

int trap_PC_FreeSource(int handle)
{
    return syscall(BOTLIB_PC_FREE_SOURCE, handle);
}

int trap_PC_ReadToken(int handle, pc_token_t* pc_token)
{
    return syscall(BOTLIB_PC_READ_TOKEN, handle, pc_token);
}

int trap_PC_SourceFileAndLine(int handle, char* filename, int* line)
{
    return syscall(BOTLIB_PC_SOURCE_FILE_AND_LINE, handle, filename, line);
}
