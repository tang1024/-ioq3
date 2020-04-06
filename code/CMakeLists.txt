cmake_minimum_required(VERSION 3.13.0 FATAL_ERROR)

project(ioquake3 C)

################################################################################
# Set target arch type if empty. Visual studio solution generator provides it.
################################################################################
if(NOT CMAKE_VS_PLATFORM_NAME)
    set(CMAKE_VS_PLATFORM_NAME "x64")
endif()
message("${CMAKE_VS_PLATFORM_NAME} architecture in use")

if(NOT ("${CMAKE_VS_PLATFORM_NAME}" STREQUAL "Win32"
     OR "${CMAKE_VS_PLATFORM_NAME}" STREQUAL "x64"))
    message(FATAL_ERROR "${CMAKE_VS_PLATFORM_NAME} arch is not supported!")
endif()

################################################################################
# Global configuration types
################################################################################
set(CMAKE_CONFIGURATION_TYPES
    "Debug"
    "Release"
    CACHE STRING "" FORCE
)

################################################################################
# Global compiler options
################################################################################
if(MSVC)
    # remove default flags provided with CMake for MSVC
    set(CMAKE_C_FLAGS "")
    set(CMAKE_C_FLAGS_DEBUG "")
    set(CMAKE_C_FLAGS_RELEASE "")
endif()

################################################################################
# Global linker options
################################################################################
if(MSVC)
    # remove default flags provided with CMake for MSVC
    set(CMAKE_EXE_LINKER_FLAGS "")
    set(CMAKE_MODULE_LINKER_FLAGS "")
    set(CMAKE_SHARED_LINKER_FLAGS "")
    set(CMAKE_STATIC_LINKER_FLAGS "")
    set(CMAKE_EXE_LINKER_FLAGS_DEBUG "${CMAKE_EXE_LINKER_FLAGS}")
    set(CMAKE_MODULE_LINKER_FLAGS_DEBUG "${CMAKE_MODULE_LINKER_FLAGS}")
    set(CMAKE_SHARED_LINKER_FLAGS_DEBUG "${CMAKE_SHARED_LINKER_FLAGS}")
    set(CMAKE_STATIC_LINKER_FLAGS_DEBUG "${CMAKE_STATIC_LINKER_FLAGS}")
    set(CMAKE_EXE_LINKER_FLAGS_RELEASE "${CMAKE_EXE_LINKER_FLAGS}")
    set(CMAKE_MODULE_LINKER_FLAGS_RELEASE "${CMAKE_MODULE_LINKER_FLAGS}")
    set(CMAKE_SHARED_LINKER_FLAGS_RELEASE "${CMAKE_SHARED_LINKER_FLAGS}")
    set(CMAKE_STATIC_LINKER_FLAGS_RELEASE "${CMAKE_STATIC_LINKER_FLAGS}")
endif()

################################################################################
# Nuget packages function stub.
################################################################################
function(use_package TARGET PACKAGE VERSION)
    message(WARNING "No implementation of use_package. Create yours. "
                    "Package \"${PACKAGE}\" with version \"${VERSION}\" "
                    "for target \"${TARGET}\" is ignored!")
endfunction()

################################################################################
# Common utils
################################################################################
include(CMake/Utils.cmake)

################################################################################
# Additional Global Settings(add specific info there)
################################################################################
include(CMake/GlobalSettingsInclude.cmake OPTIONAL)

################################################################################
# Use solution folders feature
################################################################################
set_property(GLOBAL PROPERTY USE_FOLDERS ON)

################################################################################
# Sub-projects
################################################################################



























project(ioquake3 C)

################################################################################
# Source groups
################################################################################
set(botlib
    "../../../ioq3/code/botlib/aasfile.h"
    "../../../ioq3/code/botlib/be_aas.h"
    "../../../ioq3/code/botlib/be_aas_bsp.h"
    "../../../ioq3/code/botlib/be_aas_bspq3.c"
    "../../../ioq3/code/botlib/be_aas_cluster.c"
    "../../../ioq3/code/botlib/be_aas_cluster.h"
    "../../../ioq3/code/botlib/be_aas_debug.c"
    "../../../ioq3/code/botlib/be_aas_debug.h"
    "../../../ioq3/code/botlib/be_aas_def.h"
    "../../../ioq3/code/botlib/be_aas_entity.c"
    "../../../ioq3/code/botlib/be_aas_entity.h"
    "../../../ioq3/code/botlib/be_aas_file.c"
    "../../../ioq3/code/botlib/be_aas_file.h"
    "../../../ioq3/code/botlib/be_aas_funcs.h"
    "../../../ioq3/code/botlib/be_aas_main.c"
    "../../../ioq3/code/botlib/be_aas_main.h"
    "../../../ioq3/code/botlib/be_aas_move.c"
    "../../../ioq3/code/botlib/be_aas_move.h"
    "../../../ioq3/code/botlib/be_aas_optimize.c"
    "../../../ioq3/code/botlib/be_aas_optimize.h"
    "../../../ioq3/code/botlib/be_aas_reach.c"
    "../../../ioq3/code/botlib/be_aas_reach.h"
    "../../../ioq3/code/botlib/be_aas_route.c"
    "../../../ioq3/code/botlib/be_aas_route.h"
    "../../../ioq3/code/botlib/be_aas_routealt.c"
    "../../../ioq3/code/botlib/be_aas_routealt.h"
    "../../../ioq3/code/botlib/be_aas_sample.c"
    "../../../ioq3/code/botlib/be_aas_sample.h"
    "../../../ioq3/code/botlib/be_ai_char.c"
    "../../../ioq3/code/botlib/be_ai_char.h"
    "../../../ioq3/code/botlib/be_ai_chat.c"
    "../../../ioq3/code/botlib/be_ai_chat.h"
    "../../../ioq3/code/botlib/be_ai_gen.c"
    "../../../ioq3/code/botlib/be_ai_gen.h"
    "../../../ioq3/code/botlib/be_ai_goal.c"
    "../../../ioq3/code/botlib/be_ai_goal.h"
    "../../../ioq3/code/botlib/be_ai_move.c"
    "../../../ioq3/code/botlib/be_ai_move.h"
    "../../../ioq3/code/botlib/be_ai_weap.c"
    "../../../ioq3/code/botlib/be_ai_weap.h"
    "../../../ioq3/code/botlib/be_ai_weight.c"
    "../../../ioq3/code/botlib/be_ai_weight.h"
    "../../../ioq3/code/botlib/be_ea.c"
    "../../../ioq3/code/botlib/be_ea.h"
    "../../../ioq3/code/botlib/be_interface.c"
    "../../../ioq3/code/botlib/be_interface.h"
    "../../../ioq3/code/botlib/botlib.h"
    "../../../ioq3/code/botlib/l_crc.c"
    "../../../ioq3/code/botlib/l_crc.h"
    "../../../ioq3/code/botlib/l_libvar.c"
    "../../../ioq3/code/botlib/l_libvar.h"
    "../../../ioq3/code/botlib/l_log.c"
    "../../../ioq3/code/botlib/l_log.h"
    "../../../ioq3/code/botlib/l_memory.c"
    "../../../ioq3/code/botlib/l_memory.h"
    "../../../ioq3/code/botlib/l_precomp.c"
    "../../../ioq3/code/botlib/l_precomp.h"
    "../../../ioq3/code/botlib/l_script.c"
    "../../../ioq3/code/botlib/l_script.h"
    "../../../ioq3/code/botlib/l_struct.c"
    "../../../ioq3/code/botlib/l_struct.h"
    "../../../ioq3/code/botlib/l_utils.h"
)
source_group("botlib" FILES ${botlib})

set(client
    "../../../ioq3/code/client/cl_avi.c"
    "../../../ioq3/code/client/cl_cgame.c"
    "../../../ioq3/code/client/cl_cin.c"
    "../../../ioq3/code/client/cl_console.c"
    "../../../ioq3/code/client/cl_curl.c"
    "../../../ioq3/code/client/cl_curl.h"
    "../../../ioq3/code/client/cl_input.c"
    "../../../ioq3/code/client/cl_keys.c"
    "../../../ioq3/code/client/cl_main.c"
    "../../../ioq3/code/client/cl_net_chan.c"
    "../../../ioq3/code/client/cl_parse.c"
    "../../../ioq3/code/client/cl_scrn.c"
    "../../../ioq3/code/client/cl_ui.c"
    "../../../ioq3/code/client/client.h"
    "../../../ioq3/code/client/keycodes.h"
    "../../../ioq3/code/client/keys.h"
    "../../../ioq3/code/client/qal.c"
    "../../../ioq3/code/client/qal.h"
    "../../../ioq3/code/client/snd_adpcm.c"
    "../../../ioq3/code/client/snd_altivec.c"
    "../../../ioq3/code/client/snd_codec.c"
    "../../../ioq3/code/client/snd_codec.h"
    "../../../ioq3/code/client/snd_codec_ogg.c"
    "../../../ioq3/code/client/snd_codec_opus.c"
    "../../../ioq3/code/client/snd_codec_wav.c"
    "../../../ioq3/code/client/snd_dma.c"
    "../../../ioq3/code/client/snd_local.h"
    "../../../ioq3/code/client/snd_main.c"
    "../../../ioq3/code/client/snd_mem.c"
    "../../../ioq3/code/client/snd_mix.c"
    "../../../ioq3/code/client/snd_openal.c"
    "../../../ioq3/code/client/snd_public.h"
    "../../../ioq3/code/client/snd_wavelet.c"
)
source_group("client" FILES ${client})

set(qcommon
    "../../../ioq3/code/qcommon/cm_load.c"
    "../../../ioq3/code/qcommon/cm_local.h"
    "../../../ioq3/code/qcommon/cm_patch.c"
    "../../../ioq3/code/qcommon/cm_patch.h"
    "../../../ioq3/code/qcommon/cm_polylib.c"
    "../../../ioq3/code/qcommon/cm_polylib.h"
    "../../../ioq3/code/qcommon/cm_public.h"
    "../../../ioq3/code/qcommon/cm_test.c"
    "../../../ioq3/code/qcommon/cm_trace.c"
    "../../../ioq3/code/qcommon/cmd.c"
    "../../../ioq3/code/qcommon/common.c"
    "../../../ioq3/code/qcommon/cvar.c"
    "../../../ioq3/code/qcommon/files.c"
    "../../../ioq3/code/qcommon/huffman.c"
    "../../../ioq3/code/qcommon/ioapi.c"
    "../../../ioq3/code/qcommon/ioapi.h"
    "../../../ioq3/code/qcommon/json.h"
    "../../../ioq3/code/qcommon/md4.c"
    "../../../ioq3/code/qcommon/md5.c"
    "../../../ioq3/code/qcommon/msg.c"
    "../../../ioq3/code/qcommon/net_chan.c"
    "../../../ioq3/code/qcommon/net_ip.c"
    "../../../ioq3/code/qcommon/puff.c"
    "../../../ioq3/code/qcommon/puff.h"
    "../../../ioq3/code/qcommon/q_math.c"
    "../../../ioq3/code/qcommon/q_platform.h"
    "../../../ioq3/code/qcommon/q_shared.c"
    "../../../ioq3/code/qcommon/q_shared.h"
    "../../../ioq3/code/qcommon/qcommon.h"
    "../../../ioq3/code/qcommon/qfiles.h"
    "../../../ioq3/code/qcommon/surfaceflags.h"
    "../../../ioq3/code/qcommon/unzip.c"
    "../../../ioq3/code/qcommon/unzip.h"
    "../../../ioq3/code/qcommon/vm.c"
    "../../../ioq3/code/qcommon/vm_interpreted.c"
    "../../../ioq3/code/qcommon/vm_local.h"
    "../../../ioq3/code/qcommon/vm_x86.c"
)
source_group("qcommon" FILES ${qcommon})

set(res
    "../../res/win_manifest.manifest"
    "../../res/win_resource.h"
)
source_group("res" FILES ${res})

set(sdl
    "../../../ioq3/code/sdl/sdl_input.c"
    "../../../ioq3/code/sdl/sdl_snd.c"
)
source_group("sdl" FILES ${sdl})

set(server
    "../../../ioq3/code/server/server.h"
    "../../../ioq3/code/server/sv_bot.c"
    "../../../ioq3/code/server/sv_ccmds.c"
    "../../../ioq3/code/server/sv_client.c"
    "../../../ioq3/code/server/sv_game.c"
    "../../../ioq3/code/server/sv_init.c"
    "../../../ioq3/code/server/sv_main.c"
    "../../../ioq3/code/server/sv_net_chan.c"
    "../../../ioq3/code/server/sv_snapshot.c"
    "../../../ioq3/code/server/sv_world.c"
)
source_group("server" FILES ${server})

set(sys
    "../../../ioq3/code/sys/con_log.c"
    "../../../ioq3/code/sys/con_passive.c"
    "../../../ioq3/code/sys/sys_autoupdater.c"
    "../../../ioq3/code/sys/sys_loadlib.h"
    "../../../ioq3/code/sys/sys_local.h"
    "../../../ioq3/code/sys/sys_main.c"
    "../../../ioq3/code/sys/sys_win32.c"
)
source_group("sys" FILES ${sys})

set(ALL_FILES
    ${botlib}
    ${client}
    ${qcommon}
    ${res}
    ${sdl}
    ${server}
    ${sys}
)

################################################################################
# Target
################################################################################
add_executable(${PROJECT_NAME} ${ALL_FILES})
set_target_properties(${PROJECT_NAME} PROPERTIES FOLDER "engine")

use_props(${PROJECT_NAME} "${CMAKE_CONFIGURATION_TYPES}" "${DEFAULT_CXX_PROPS}")
set(ROOT_NAMESPACE ioquake3)

set_target_properties(${PROJECT_NAME} PROPERTIES
    VS_GLOBAL_KEYWORD "Win32Proj"
)
################################################################################
# Target name
################################################################################
if("${CMAKE_VS_PLATFORM_NAME}" STREQUAL "Win32")
    set_target_properties(${PROJECT_NAME} PROPERTIES
        TARGET_NAME_DEBUG   "ioquake3.x86"
        TARGET_NAME_RELEASE "ioquake3.x86"
    )
elseif("${CMAKE_VS_PLATFORM_NAME}" STREQUAL "x64")
    set_target_properties(${PROJECT_NAME} PROPERTIES
        TARGET_NAME_DEBUG   "ioquake3.x86_64"
        TARGET_NAME_RELEASE "ioquake3.x86_64"
    )
endif()
################################################################################
# Output directory
################################################################################
if("${CMAKE_VS_PLATFORM_NAME}" STREQUAL "Win32")
    set_target_properties(${PROJECT_NAME} PROPERTIES
        OUTPUT_DIRECTORY_DEBUG   "${CMAKE_CURRENT_SOURCE_DIR}/bin_x86_debug/"
        OUTPUT_DIRECTORY_RELEASE "${CMAKE_CURRENT_SOURCE_DIR}/bin_x86/"
    )
elseif("${CMAKE_VS_PLATFORM_NAME}" STREQUAL "x64")
    set_target_properties(${PROJECT_NAME} PROPERTIES
        OUTPUT_DIRECTORY_DEBUG   "${CMAKE_CURRENT_SOURCE_DIR}/bin_x64_debug/"
        OUTPUT_DIRECTORY_RELEASE "${CMAKE_CURRENT_SOURCE_DIR}/bin_x64/"
    )
endif()
################################################################################
# Include directories
################################################################################
if("${CMAKE_VS_PLATFORM_NAME}" STREQUAL "Win32")
    target_include_directories(${PROJECT_NAME} PUBLIC
        "${CMAKE_CURRENT_SOURCE_DIR}/../../../ioq3/code/AL;"
        "${CMAKE_CURRENT_SOURCE_DIR}/../../../ioq3/code/jpeg-8c;"
        "${CMAKE_CURRENT_SOURCE_DIR}/../../../ioq3/code/curl-7.54.0;"
        "${CMAKE_CURRENT_SOURCE_DIR}/../../../ioq3/code/SDL2/include;"
        "${CMAKE_CURRENT_SOURCE_DIR}/../../../ioq3/code/zlib;"
        "${CMAKE_CURRENT_SOURCE_DIR}/../../../ioq3/code/libogg-1.3.3/include;"
        "${CMAKE_CURRENT_SOURCE_DIR}/../../../ioq3/code/opus-1.2.1/include;"
        "${CMAKE_CURRENT_SOURCE_DIR}/../../../ioq3/code/opusfile-0.9/include;"
        "${CMAKE_CURRENT_SOURCE_DIR}/../../../ioq3/code/libvorbis-1.3.6/include"
    )
elseif("${CMAKE_VS_PLATFORM_NAME}" STREQUAL "x64")
    target_include_directories(${PROJECT_NAME} PUBLIC
        "${CMAKE_CURRENT_SOURCE_DIR}/../../../ioq3/code/AL;"
        "${CMAKE_CURRENT_SOURCE_DIR}/../../../ioq3/code/jpeg-8c;"
        "${CMAKE_CURRENT_SOURCE_DIR}/../../../ioq3/code/curl-7.54.0;"
        "${CMAKE_CURRENT_SOURCE_DIR}/../../../ioq3/code/SDL2/include;"
        "${CMAKE_CURRENT_SOURCE_DIR}/../../../ioq3/code/zlib;"
        "${CMAKE_CURRENT_SOURCE_DIR}/../../../ioq3/code/libogg-1.3.3/include;"
        "${CMAKE_CURRENT_SOURCE_DIR}/../../../ioq3/code/opus-1.2.1/include;"
        "${CMAKE_CURRENT_SOURCE_DIR}/../../../ioq3/code/opusfile-0.9/include;"
        "${CMAKE_CURRENT_SOURCE_DIR}/../../../ioq3/code/libvorbis-1.3.6/include"
    )
endif()

################################################################################
# Compile definitions
################################################################################
if("${CMAKE_VS_PLATFORM_NAME}" STREQUAL "Win32")
    target_compile_definitions(${PROJECT_NAME} PRIVATE
        "$<$<CONFIG:Debug>:"
            "_DEBUG"
        ">"
        "$<$<CONFIG:Release>:"
            "NDEBUG"
        ">"
        "_CRT_SECURE_NO_DEPRECATE;"
        "__i386__;"
        "_WIN32;"
        "WIN32;"
        "_WINSOCK_DEPRECATED_NO_WARNINGS;"
        "BOTLIB;"
        "USE_CURL;"
        "USE_CURL_DLOPEN;"
        "USE_OPENAL;"
        "USE_OPENAL_DLOPEN;"
        "USE_RENDERER_DLOPEN;"
        "USE_LOCAL_HEADERS;"
        "USE_CODEC_OPUS;"
        "USE_CODEC_VORBIS;"
        "USE_VOIP;"
        "_MBCS"
    )
elseif("${CMAKE_VS_PLATFORM_NAME}" STREQUAL "x64")
    target_compile_definitions(${PROJECT_NAME} PRIVATE
        "$<$<CONFIG:Debug>:"
            "_DEBUG"
        ">"
        "$<$<CONFIG:Release>:"
            "NDEBUG"
        ">"
        "_CRT_SECURE_NO_DEPRECATE;"
        "_WIN64;"
        "__WIN64__;"
        "__x86_64__;"
        "_WIN32;"
        "WIN32;"
        "_WINSOCK_DEPRECATED_NO_WARNINGS;"
        "BOTLIB;"
        "USE_CURL;"
        "USE_CURL_DLOPEN;"
        "USE_OPENAL;"
        "USE_OPENAL_DLOPEN;"
        "USE_RENDERER_DLOPEN;"
        "USE_LOCAL_HEADERS;"
        "USE_CODEC_OPUS;"
        "USE_CODEC_VORBIS;"
        "USE_VOIP;"
        "_MBCS"
    )
endif()

################################################################################
# Compile and link options
################################################################################
if(MSVC)
    if("${CMAKE_VS_PLATFORM_NAME}" STREQUAL "Win32")
        target_compile_options(${PROJECT_NAME} PRIVATE
            $<$<CONFIG:Debug>:
                /Od;
                ${DEFAULT_CXX_DEBUG_RUNTIME_LIBRARY};
                /ZI
            >
            $<$<CONFIG:Release>:
                /Gm-;
                /Ox;
                /Oi;
                /GF;
                ${DEFAULT_CXX_RUNTIME_LIBRARY};
                /Gy;
                ${DEFAULT_CXX_DEBUG_INFORMATION_FORMAT}
            >
            /W3;
            ${DEFAULT_CXX_EXCEPTION_HANDLING};
            /Y-
        )
    elseif("${CMAKE_VS_PLATFORM_NAME}" STREQUAL "x64")
        target_compile_options(${PROJECT_NAME} PRIVATE
            $<$<CONFIG:Debug>:
                /Od;
                ${DEFAULT_CXX_DEBUG_RUNTIME_LIBRARY};
                /ZI
            >
            $<$<CONFIG:Release>:
                /Gm-;
                /Ox;
                /Oi;
                /GF;
                ${DEFAULT_CXX_RUNTIME_LIBRARY};
                /Gy;
                ${DEFAULT_CXX_DEBUG_INFORMATION_FORMAT}
            >
            /W3;
            ${DEFAULT_CXX_EXCEPTION_HANDLING};
            /Y-
        )
    endif()
    if("${CMAKE_VS_PLATFORM_NAME}" STREQUAL "Win32")
        target_link_options(${PROJECT_NAME} PRIVATE
            $<$<CONFIG:Debug>:
                /DEBUG;
                /INCREMENTAL
            >
            $<$<CONFIG:Release>:
                /DEBUG:FULL;
                /OPT:REF;
                /OPT:ICF;
                /INCREMENTAL:NO
            >
            /SUBSYSTEM:WINDOWS;
            /SAFESEH:NO
        )
    elseif("${CMAKE_VS_PLATFORM_NAME}" STREQUAL "x64")
        target_link_options(${PROJECT_NAME} PRIVATE
            $<$<CONFIG:Debug>:
                /DEBUG;
                /INCREMENTAL
            >
            $<$<CONFIG:Release>:
                /DEBUG:FULL;
                /OPT:REF;
                /OPT:ICF;
                /INCREMENTAL:NO
            >
            /SUBSYSTEM:WINDOWS;
            /SAFESEH:NO
        )
    endif()
endif()

################################################################################
# Dependencies
################################################################################
add_dependencies(${PROJECT_NAME}
    SDL2
    SDL2main
    zlib
    ogg
    opus
    vorbis
)

# Link with other targets.
target_link_libraries(${PROJECT_NAME} PUBLIC
    SDL2
    SDL2main
    zlib
    ogg
    opus
    vorbis
)

if("${CMAKE_VS_PLATFORM_NAME}" STREQUAL "Win32")
    set(ADDITIONAL_LIBRARY_DEPENDENCIES
        "user32;"
        "advapi32;"
        "winmm;"
        "wsock32;"
        "ws2_32;"
        "OpenGL32;"
        "psapi;"
        "gdi32"
    )
elseif("${CMAKE_VS_PLATFORM_NAME}" STREQUAL "x64")
    set(ADDITIONAL_LIBRARY_DEPENDENCIES
        "user32;"
        "advapi32;"
        "winmm;"
        "wsock32;"
        "ws2_32;"
        "OpenGL32;"
        "psapi;"
        "gdi32"
    )
endif()
target_link_libraries(${PROJECT_NAME} PUBLIC "${ADDITIONAL_LIBRARY_DEPENDENCIES}")



























project(ioq3ded C)

################################################################################
# Source groups
################################################################################
set(botlib
    "../../../ioq3/code/botlib/aasfile.h"
    "../../../ioq3/code/botlib/be_aas.h"
    "../../../ioq3/code/botlib/be_aas_bsp.h"
    "../../../ioq3/code/botlib/be_aas_bspq3.c"
    "../../../ioq3/code/botlib/be_aas_cluster.c"
    "../../../ioq3/code/botlib/be_aas_cluster.h"
    "../../../ioq3/code/botlib/be_aas_debug.c"
    "../../../ioq3/code/botlib/be_aas_debug.h"
    "../../../ioq3/code/botlib/be_aas_def.h"
    "../../../ioq3/code/botlib/be_aas_entity.c"
    "../../../ioq3/code/botlib/be_aas_entity.h"
    "../../../ioq3/code/botlib/be_aas_file.c"
    "../../../ioq3/code/botlib/be_aas_file.h"
    "../../../ioq3/code/botlib/be_aas_funcs.h"
    "../../../ioq3/code/botlib/be_aas_main.c"
    "../../../ioq3/code/botlib/be_aas_main.h"
    "../../../ioq3/code/botlib/be_aas_move.c"
    "../../../ioq3/code/botlib/be_aas_move.h"
    "../../../ioq3/code/botlib/be_aas_optimize.c"
    "../../../ioq3/code/botlib/be_aas_optimize.h"
    "../../../ioq3/code/botlib/be_aas_reach.c"
    "../../../ioq3/code/botlib/be_aas_reach.h"
    "../../../ioq3/code/botlib/be_aas_route.c"
    "../../../ioq3/code/botlib/be_aas_route.h"
    "../../../ioq3/code/botlib/be_aas_routealt.c"
    "../../../ioq3/code/botlib/be_aas_routealt.h"
    "../../../ioq3/code/botlib/be_aas_sample.c"
    "../../../ioq3/code/botlib/be_aas_sample.h"
    "../../../ioq3/code/botlib/be_ai_char.c"
    "../../../ioq3/code/botlib/be_ai_char.h"
    "../../../ioq3/code/botlib/be_ai_chat.c"
    "../../../ioq3/code/botlib/be_ai_chat.h"
    "../../../ioq3/code/botlib/be_ai_gen.c"
    "../../../ioq3/code/botlib/be_ai_gen.h"
    "../../../ioq3/code/botlib/be_ai_goal.c"
    "../../../ioq3/code/botlib/be_ai_goal.h"
    "../../../ioq3/code/botlib/be_ai_move.c"
    "../../../ioq3/code/botlib/be_ai_move.h"
    "../../../ioq3/code/botlib/be_ai_weap.c"
    "../../../ioq3/code/botlib/be_ai_weap.h"
    "../../../ioq3/code/botlib/be_ai_weight.c"
    "../../../ioq3/code/botlib/be_ai_weight.h"
    "../../../ioq3/code/botlib/be_ea.c"
    "../../../ioq3/code/botlib/be_ea.h"
    "../../../ioq3/code/botlib/be_interface.c"
    "../../../ioq3/code/botlib/be_interface.h"
    "../../../ioq3/code/botlib/botlib.h"
    "../../../ioq3/code/botlib/l_crc.c"
    "../../../ioq3/code/botlib/l_crc.h"
    "../../../ioq3/code/botlib/l_libvar.c"
    "../../../ioq3/code/botlib/l_libvar.h"
    "../../../ioq3/code/botlib/l_log.c"
    "../../../ioq3/code/botlib/l_log.h"
    "../../../ioq3/code/botlib/l_memory.c"
    "../../../ioq3/code/botlib/l_memory.h"
    "../../../ioq3/code/botlib/l_precomp.c"
    "../../../ioq3/code/botlib/l_precomp.h"
    "../../../ioq3/code/botlib/l_script.c"
    "../../../ioq3/code/botlib/l_script.h"
    "../../../ioq3/code/botlib/l_struct.c"
    "../../../ioq3/code/botlib/l_struct.h"
    "../../../ioq3/code/botlib/l_utils.h"
)
source_group("botlib" FILES ${botlib})

set(null
    "../../../ioq3/code/null/null_client.c"
    "../../../ioq3/code/null/null_input.c"
    "../../../ioq3/code/null/null_snddma.c"
)
source_group("null" FILES ${null})

set(qcommon
    "../../../ioq3/code/qcommon/cm_load.c"
    "../../../ioq3/code/qcommon/cm_local.h"
    "../../../ioq3/code/qcommon/cm_patch.c"
    "../../../ioq3/code/qcommon/cm_patch.h"
    "../../../ioq3/code/qcommon/cm_polylib.c"
    "../../../ioq3/code/qcommon/cm_polylib.h"
    "../../../ioq3/code/qcommon/cm_public.h"
    "../../../ioq3/code/qcommon/cm_test.c"
    "../../../ioq3/code/qcommon/cm_trace.c"
    "../../../ioq3/code/qcommon/cmd.c"
    "../../../ioq3/code/qcommon/common.c"
    "../../../ioq3/code/qcommon/cvar.c"
    "../../../ioq3/code/qcommon/files.c"
    "../../../ioq3/code/qcommon/huffman.c"
    "../../../ioq3/code/qcommon/ioapi.c"
    "../../../ioq3/code/qcommon/ioapi.h"
    "../../../ioq3/code/qcommon/json.h"
    "../../../ioq3/code/qcommon/md4.c"
    "../../../ioq3/code/qcommon/md5.c"
    "../../../ioq3/code/qcommon/msg.c"
    "../../../ioq3/code/qcommon/net_chan.c"
    "../../../ioq3/code/qcommon/net_ip.c"
    "../../../ioq3/code/qcommon/puff.c"
    "../../../ioq3/code/qcommon/puff.h"
    "../../../ioq3/code/qcommon/q_math.c"
    "../../../ioq3/code/qcommon/q_platform.h"
    "../../../ioq3/code/qcommon/q_shared.c"
    "../../../ioq3/code/qcommon/q_shared.h"
    "../../../ioq3/code/qcommon/qcommon.h"
    "../../../ioq3/code/qcommon/qfiles.h"
    "../../../ioq3/code/qcommon/surfaceflags.h"
    "../../../ioq3/code/qcommon/unzip.c"
    "../../../ioq3/code/qcommon/unzip.h"
    "../../../ioq3/code/qcommon/vm.c"
    "../../../ioq3/code/qcommon/vm_interpreted.c"
    "../../../ioq3/code/qcommon/vm_local.h"
    "../../../ioq3/code/qcommon/vm_x86.c"
)
source_group("qcommon" FILES ${qcommon})

set(res
    "../../res/win_manifest.manifest"
    "../../res/win_resource.h"
)
source_group("res" FILES ${res})

set(server
    "../../../ioq3/code/server/server.h"
    "../../../ioq3/code/server/sv_bot.c"
    "../../../ioq3/code/server/sv_ccmds.c"
    "../../../ioq3/code/server/sv_client.c"
    "../../../ioq3/code/server/sv_game.c"
    "../../../ioq3/code/server/sv_init.c"
    "../../../ioq3/code/server/sv_main.c"
    "../../../ioq3/code/server/sv_net_chan.c"
    "../../../ioq3/code/server/sv_snapshot.c"
    "../../../ioq3/code/server/sv_world.c"
)
source_group("server" FILES ${server})

set(sys
    "../../../ioq3/code/sys/con_log.c"
    "../../../ioq3/code/sys/con_win32.c"
    "../../../ioq3/code/sys/sys_autoupdater.c"
    "../../../ioq3/code/sys/sys_loadlib.h"
    "../../../ioq3/code/sys/sys_local.h"
    "../../../ioq3/code/sys/sys_main.c"
    "../../../ioq3/code/sys/sys_win32.c"
)
source_group("sys" FILES ${sys})

set(ALL_FILES
    ${botlib}
    ${null}
    ${qcommon}
    ${res}
    ${server}
    ${sys}
)

################################################################################
# Target
################################################################################
add_executable(${PROJECT_NAME} ${ALL_FILES})
set_target_properties(${PROJECT_NAME} PROPERTIES FOLDER "engine")

use_props(${PROJECT_NAME} "${CMAKE_CONFIGURATION_TYPES}" "${DEFAULT_CXX_PROPS}")
set(ROOT_NAMESPACE ioq3ded)

set_target_properties(${PROJECT_NAME} PROPERTIES
    VS_GLOBAL_KEYWORD "Win32Proj"
)
################################################################################
# Target name
################################################################################
if("${CMAKE_VS_PLATFORM_NAME}" STREQUAL "Win32")
    set_target_properties(${PROJECT_NAME} PROPERTIES
        TARGET_NAME_DEBUG   "ioq3ded.x86"
        TARGET_NAME_RELEASE "ioq3ded.x86"
    )
elseif("${CMAKE_VS_PLATFORM_NAME}" STREQUAL "x64")
    set_target_properties(${PROJECT_NAME} PROPERTIES
        TARGET_NAME_DEBUG   "ioq3ded.x86_64"
        TARGET_NAME_RELEASE "ioq3ded.x86_64"
    )
endif()
################################################################################
# Output directory
################################################################################
if("${CMAKE_VS_PLATFORM_NAME}" STREQUAL "Win32")
    set_target_properties(${PROJECT_NAME} PROPERTIES
        OUTPUT_DIRECTORY_DEBUG   "${CMAKE_CURRENT_SOURCE_DIR}/bin_x86_debug/"
        OUTPUT_DIRECTORY_RELEASE "${CMAKE_CURRENT_SOURCE_DIR}/bin_x86/"
    )
elseif("${CMAKE_VS_PLATFORM_NAME}" STREQUAL "x64")
    set_target_properties(${PROJECT_NAME} PROPERTIES
        OUTPUT_DIRECTORY_DEBUG   "${CMAKE_CURRENT_SOURCE_DIR}/bin_x64_debug/"
        OUTPUT_DIRECTORY_RELEASE "${CMAKE_CURRENT_SOURCE_DIR}/bin_x64/"
    )
endif()
################################################################################
# Include directories
################################################################################
if("${CMAKE_VS_PLATFORM_NAME}" STREQUAL "Win32")
    target_include_directories(${PROJECT_NAME} PUBLIC
        "${CMAKE_CURRENT_SOURCE_DIR}/../../../ioq3/code/zlib"
    )
elseif("${CMAKE_VS_PLATFORM_NAME}" STREQUAL "x64")
    target_include_directories(${PROJECT_NAME} PUBLIC
        "${CMAKE_CURRENT_SOURCE_DIR}/../../../ioq3/code/zlib"
    )
endif()

################################################################################
# Compile definitions
################################################################################
if("${CMAKE_VS_PLATFORM_NAME}" STREQUAL "Win32")
    target_compile_definitions(${PROJECT_NAME} PRIVATE
        "$<$<CONFIG:Debug>:"
            "_DEBUG"
        ">"
        "$<$<CONFIG:Release>:"
            "NDEBUG"
        ">"
        "_CRT_SECURE_NO_DEPRECATE;"
        "_WINSOCK_DEPRECATED_NO_WARNINGS;"
        "DEDICATED;"
        "BOTLIB;"
        "USE_VOIP;"
        "USE_LOCAL_HEADERS;"
        "_MBCS"
    )
elseif("${CMAKE_VS_PLATFORM_NAME}" STREQUAL "x64")
    target_compile_definitions(${PROJECT_NAME} PRIVATE
        "$<$<CONFIG:Debug>:"
            "_DEBUG"
        ">"
        "$<$<CONFIG:Release>:"
            "NDEBUG"
        ">"
        "_CRT_SECURE_NO_DEPRECATE;"
        "_WIN64;"
        "__WIN64__;"
        "_WINSOCK_DEPRECATED_NO_WARNINGS;"
        "DEDICATED;"
        "BOTLIB;"
        "USE_VOIP;"
        "USE_LOCAL_HEADERS;"
        "_MBCS"
    )
endif()

################################################################################
# Compile and link options
################################################################################
if(MSVC)
    if("${CMAKE_VS_PLATFORM_NAME}" STREQUAL "Win32")
        target_compile_options(${PROJECT_NAME} PRIVATE
            $<$<CONFIG:Debug>:
                /Od;
                ${DEFAULT_CXX_DEBUG_RUNTIME_LIBRARY};
                /ZI
            >
            $<$<CONFIG:Release>:
                /Gm-;
                /Ox;
                /Oi;
                /GF;
                ${DEFAULT_CXX_RUNTIME_LIBRARY};
                /Gy;
                ${DEFAULT_CXX_DEBUG_INFORMATION_FORMAT}
            >
            /W3;
            ${DEFAULT_CXX_EXCEPTION_HANDLING};
            /Y-
        )
    elseif("${CMAKE_VS_PLATFORM_NAME}" STREQUAL "x64")
        target_compile_options(${PROJECT_NAME} PRIVATE
            $<$<CONFIG:Debug>:
                /Od;
                ${DEFAULT_CXX_DEBUG_RUNTIME_LIBRARY};
                /ZI
            >
            $<$<CONFIG:Release>:
                /Gm-;
                /Ox;
                /Oi;
                /GF;
                ${DEFAULT_CXX_RUNTIME_LIBRARY};
                /Gy;
                ${DEFAULT_CXX_DEBUG_INFORMATION_FORMAT}
            >
            /W3;
            ${DEFAULT_CXX_EXCEPTION_HANDLING};
            /Y-
        )
    endif()
    if("${CMAKE_VS_PLATFORM_NAME}" STREQUAL "Win32")
        target_link_options(${PROJECT_NAME} PRIVATE
            $<$<CONFIG:Debug>:
                /DEBUG;
                /INCREMENTAL
            >
            $<$<CONFIG:Release>:
                /DEBUG:FULL;
                /OPT:REF;
                /OPT:ICF;
                /INCREMENTAL:NO
            >
            /SUBSYSTEM:CONSOLE;
            /SAFESEH:NO
        )
    elseif("${CMAKE_VS_PLATFORM_NAME}" STREQUAL "x64")
        target_link_options(${PROJECT_NAME} PRIVATE
            $<$<CONFIG:Debug>:
                /DEBUG;
                /INCREMENTAL
            >
            $<$<CONFIG:Release>:
                /DEBUG:FULL;
                /OPT:REF;
                /OPT:ICF;
                /INCREMENTAL:NO
            >
            /SUBSYSTEM:CONSOLE;
            /SAFESEH:NO
        )
    endif()
endif()

################################################################################
# Dependencies
################################################################################
add_dependencies(${PROJECT_NAME}
    zlib
)

# Link with other targets.
target_link_libraries(${PROJECT_NAME} PUBLIC
    zlib
)

if("${CMAKE_VS_PLATFORM_NAME}" STREQUAL "Win32")
    set(ADDITIONAL_LIBRARY_DEPENDENCIES
        "winmm;"
        "wsock32;"
        "ws2_32;"
        "psapi"
    )
elseif("${CMAKE_VS_PLATFORM_NAME}" STREQUAL "x64")
    set(ADDITIONAL_LIBRARY_DEPENDENCIES
        "winmm;"
        "wsock32;"
        "ws2_32;"
        "psapi"
    )
endif()
target_link_libraries(${PROJECT_NAME} PUBLIC "${ADDITIONAL_LIBRARY_DEPENDENCIES}")



























project(baseq3_cgame_dll C)

################################################################################
# Source groups
################################################################################
set(cgame
    "../../../ioq3/code/cgame/cg_consolecmds.c"
    "../../../ioq3/code/cgame/cg_draw.c"
    "../../../ioq3/code/cgame/cg_drawtools.c"
    "../../../ioq3/code/cgame/cg_effects.c"
    "../../../ioq3/code/cgame/cg_ents.c"
    "../../../ioq3/code/cgame/cg_event.c"
    "../../../ioq3/code/cgame/cg_info.c"
    "../../../ioq3/code/cgame/cg_local.h"
    "../../../ioq3/code/cgame/cg_localents.c"
    "../../../ioq3/code/cgame/cg_main.c"
    "../../../ioq3/code/cgame/cg_marks.c"
    "../../../ioq3/code/cgame/cg_particles.c"
    "../../../ioq3/code/cgame/cg_players.c"
    "../../../ioq3/code/cgame/cg_playerstate.c"
    "../../../ioq3/code/cgame/cg_predict.c"
    "../../../ioq3/code/cgame/cg_public.h"
    "../../../ioq3/code/cgame/cg_scoreboard.c"
    "../../../ioq3/code/cgame/cg_servercmds.c"
    "../../../ioq3/code/cgame/cg_snapshot.c"
    "../../../ioq3/code/cgame/cg_syscalls.c"
    "../../../ioq3/code/cgame/cg_view.c"
    "../../../ioq3/code/cgame/cg_weapons.c"
)
source_group("cgame" FILES ${cgame})

set(game
    "../../../ioq3/code/game/bg_local.h"
    "../../../ioq3/code/game/bg_misc.c"
    "../../../ioq3/code/game/bg_pmove.c"
    "../../../ioq3/code/game/bg_public.h"
    "../../../ioq3/code/game/bg_slidemove.c"
)
source_group("game" FILES ${game})

set(qcommon
    "../../../ioq3/code/qcommon/q_math.c"
    "../../../ioq3/code/qcommon/q_shared.c"
    "../../../ioq3/code/qcommon/q_shared.h"
    "../../../ioq3/code/qcommon/surfaceflags.h"
)
source_group("qcommon" FILES ${qcommon})

set(ALL_FILES
    ${cgame}
    ${game}
    ${qcommon}
)

################################################################################
# Target
################################################################################
add_library(${PROJECT_NAME} SHARED ${ALL_FILES})
set_target_properties(${PROJECT_NAME} PROPERTIES FOLDER "game_dll")

use_props(${PROJECT_NAME} "${CMAKE_CONFIGURATION_TYPES}" "${DEFAULT_CXX_PROPS}")
set(ROOT_NAMESPACE baseq3_cgame_dll)

set_target_properties(${PROJECT_NAME} PROPERTIES
    VS_GLOBAL_KEYWORD "Win32Proj"
)
################################################################################
# Target name
################################################################################
if("${CMAKE_VS_PLATFORM_NAME}" STREQUAL "Win32")
    set_target_properties(${PROJECT_NAME} PROPERTIES
        TARGET_NAME_DEBUG   "cgamex86"
        TARGET_NAME_RELEASE "cgamex86"
    )
elseif("${CMAKE_VS_PLATFORM_NAME}" STREQUAL "x64")
    set_target_properties(${PROJECT_NAME} PROPERTIES
        TARGET_NAME_DEBUG   "cgamex86_64"
        TARGET_NAME_RELEASE "cgamex86_64"
    )
endif()
################################################################################
# Output directory
################################################################################
if("${CMAKE_VS_PLATFORM_NAME}" STREQUAL "Win32")
    set_target_properties(${PROJECT_NAME} PROPERTIES
        OUTPUT_DIRECTORY_DEBUG   "${CMAKE_CURRENT_SOURCE_DIR}/bin_x86_debug/baseq3/"
        OUTPUT_DIRECTORY_RELEASE "${CMAKE_CURRENT_SOURCE_DIR}/bin_x86/baseq3/"
    )
elseif("${CMAKE_VS_PLATFORM_NAME}" STREQUAL "x64")
    set_target_properties(${PROJECT_NAME} PROPERTIES
        OUTPUT_DIRECTORY_DEBUG   "${CMAKE_CURRENT_SOURCE_DIR}/bin_x64_debug/baseq3/"
        OUTPUT_DIRECTORY_RELEASE "${CMAKE_CURRENT_SOURCE_DIR}/bin_x64/baseq3/"
    )
endif()
if("${CMAKE_VS_PLATFORM_NAME}" STREQUAL "Win32")
    set_target_properties(${PROJECT_NAME} PROPERTIES
        ARCHIVE_OUTPUT_DIRECTORY_DEBUG   "${CMAKE_CURRENT_SOURCE_DIR}/bin_x86_debug/baseq3"
        ARCHIVE_OUTPUT_DIRECTORY_RELEASE "${CMAKE_CURRENT_SOURCE_DIR}/bin_x86/baseq3"
    )
elseif("${CMAKE_VS_PLATFORM_NAME}" STREQUAL "x64")
    set_target_properties(${PROJECT_NAME} PROPERTIES
        ARCHIVE_OUTPUT_DIRECTORY_DEBUG   "${CMAKE_CURRENT_SOURCE_DIR}/bin_x64_debug/baseq3"
        ARCHIVE_OUTPUT_DIRECTORY_RELEASE "${CMAKE_CURRENT_SOURCE_DIR}/bin_x64/baseq3"
    )
endif()
if("${CMAKE_VS_PLATFORM_NAME}" STREQUAL "Win32")
    set_target_properties(${PROJECT_NAME} PROPERTIES
        ARCHIVE_OUTPUT_NAME_DEBUG   "cgamex86"
        ARCHIVE_OUTPUT_NAME_RELEASE "cgamex86"
    )
elseif("${CMAKE_VS_PLATFORM_NAME}" STREQUAL "x64")
    set_target_properties(${PROJECT_NAME} PROPERTIES
        ARCHIVE_OUTPUT_NAME_DEBUG   "cgamex86_64"
        ARCHIVE_OUTPUT_NAME_RELEASE "cgamex86_64"
    )
endif()
################################################################################
# Compile definitions
################################################################################
if("${CMAKE_VS_PLATFORM_NAME}" STREQUAL "Win32")
    target_compile_definitions(${PROJECT_NAME} PRIVATE
        "$<$<CONFIG:Debug>:"
            "_DEBUG"
        ">"
        "$<$<CONFIG:Release>:"
            "NDEBUG"
        ">"
        "_CRT_SECURE_NO_DEPRECATE;"
        "UNICODE;"
        "_UNICODE"
    )
elseif("${CMAKE_VS_PLATFORM_NAME}" STREQUAL "x64")
    target_compile_definitions(${PROJECT_NAME} PRIVATE
        "$<$<CONFIG:Debug>:"
            "_DEBUG"
        ">"
        "$<$<CONFIG:Release>:"
            "NDEBUG"
        ">"
        "_CRT_SECURE_NO_DEPRECATE;"
        "_WIN64;"
        "__WIN64__;"
        "UNICODE;"
        "_UNICODE"
    )
endif()

################################################################################
# Compile and link options
################################################################################
if(MSVC)
    if("${CMAKE_VS_PLATFORM_NAME}" STREQUAL "Win32")
        target_compile_options(${PROJECT_NAME} PRIVATE
            $<$<CONFIG:Debug>:
                /Od;
                ${DEFAULT_CXX_DEBUG_RUNTIME_LIBRARY};
                /ZI
            >
            $<$<CONFIG:Release>:
                /Gm-;
                /Ox;
                /Oi;
                /GF;
                ${DEFAULT_CXX_RUNTIME_LIBRARY};
                /Gy;
                ${DEFAULT_CXX_DEBUG_INFORMATION_FORMAT}
            >
            /W3;
            ${DEFAULT_CXX_EXCEPTION_HANDLING};
            /Y-
        )
    elseif("${CMAKE_VS_PLATFORM_NAME}" STREQUAL "x64")
        target_compile_options(${PROJECT_NAME} PRIVATE
            $<$<CONFIG:Debug>:
                /Od;
                ${DEFAULT_CXX_DEBUG_RUNTIME_LIBRARY};
                /ZI
            >
            $<$<CONFIG:Release>:
                /Gm-;
                /Ox;
                /Oi;
                /GF;
                ${DEFAULT_CXX_RUNTIME_LIBRARY};
                /Gy;
                ${DEFAULT_CXX_DEBUG_INFORMATION_FORMAT}
            >
            /W3;
            ${DEFAULT_CXX_EXCEPTION_HANDLING};
            /Y-
        )
    endif()
    if("${CMAKE_VS_PLATFORM_NAME}" STREQUAL "Win32")
        target_link_options(${PROJECT_NAME} PRIVATE
            $<$<CONFIG:Debug>:
                /DEBUG;
                /INCREMENTAL
            >
            $<$<CONFIG:Release>:
                /DEBUG:FULL;
                /OPT:REF;
                /OPT:ICF;
                /INCREMENTAL:NO
            >
            /SUBSYSTEM:WINDOWS
        )
    elseif("${CMAKE_VS_PLATFORM_NAME}" STREQUAL "x64")
        target_link_options(${PROJECT_NAME} PRIVATE
            $<$<CONFIG:Debug>:
                /DEBUG;
                /INCREMENTAL
            >
            $<$<CONFIG:Release>:
                /DEBUG:FULL;
                /OPT:REF;
                /OPT:ICF;
                /INCREMENTAL:NO
            >
            /SUBSYSTEM:WINDOWS
        )
    endif()
endif()

################################################################################
# Dependencies
################################################################################
if("${CMAKE_VS_PLATFORM_NAME}" STREQUAL "Win32")
    set(ADDITIONAL_LIBRARY_DEPENDENCIES
        "winmm"
    )
elseif("${CMAKE_VS_PLATFORM_NAME}" STREQUAL "x64")
    set(ADDITIONAL_LIBRARY_DEPENDENCIES
        "winmm"
    )
endif()
target_link_libraries(${PROJECT_NAME} PUBLIC "${ADDITIONAL_LIBRARY_DEPENDENCIES}")



























project(baseq3_qagame_dll C)

################################################################################
# Source groups
################################################################################
set(game
    "../../../ioq3/code/game/ai_chat.c"
    "../../../ioq3/code/game/ai_chat.h"
    "../../../ioq3/code/game/ai_cmd.c"
    "../../../ioq3/code/game/ai_cmd.h"
    "../../../ioq3/code/game/ai_dmnet.c"
    "../../../ioq3/code/game/ai_dmnet.h"
    "../../../ioq3/code/game/ai_dmq3.c"
    "../../../ioq3/code/game/ai_dmq3.h"
    "../../../ioq3/code/game/ai_main.c"
    "../../../ioq3/code/game/ai_main.h"
    "../../../ioq3/code/game/ai_team.c"
    "../../../ioq3/code/game/ai_team.h"
    "../../../ioq3/code/game/ai_vcmd.c"
    "../../../ioq3/code/game/ai_vcmd.h"
    "../../../ioq3/code/game/bg_local.h"
    "../../../ioq3/code/game/bg_misc.c"
    "../../../ioq3/code/game/bg_pmove.c"
    "../../../ioq3/code/game/bg_public.h"
    "../../../ioq3/code/game/bg_slidemove.c"
    "../../../ioq3/code/game/chars.h"
    "../../../ioq3/code/game/g_active.c"
    "../../../ioq3/code/game/g_arenas.c"
    "../../../ioq3/code/game/g_bot.c"
    "../../../ioq3/code/game/g_client.c"
    "../../../ioq3/code/game/g_cmds.c"
    "../../../ioq3/code/game/g_combat.c"
    "../../../ioq3/code/game/g_items.c"
    "../../../ioq3/code/game/g_local.h"
    "../../../ioq3/code/game/g_main.c"
    "../../../ioq3/code/game/g_mem.c"
    "../../../ioq3/code/game/g_misc.c"
    "../../../ioq3/code/game/g_missile.c"
    "../../../ioq3/code/game/g_mover.c"
    "../../../ioq3/code/game/g_public.h"
    "../../../ioq3/code/game/g_rankings.h"
    "../../../ioq3/code/game/g_session.c"
    "../../../ioq3/code/game/g_spawn.c"
    "../../../ioq3/code/game/g_svcmds.c"
    "../../../ioq3/code/game/g_syscalls.c"
    "../../../ioq3/code/game/g_target.c"
    "../../../ioq3/code/game/g_team.c"
    "../../../ioq3/code/game/g_team.h"
    "../../../ioq3/code/game/g_trigger.c"
    "../../../ioq3/code/game/g_utils.c"
    "../../../ioq3/code/game/g_weapon.c"
    "../../../ioq3/code/game/inv.h"
    "../../../ioq3/code/game/match.h"
    "../../../ioq3/code/game/syn.h"
)
source_group("game" FILES ${game})

set(qcommon
    "../../../ioq3/code/qcommon/q_math.c"
    "../../../ioq3/code/qcommon/q_shared.c"
    "../../../ioq3/code/qcommon/q_shared.h"
    "../../../ioq3/code/qcommon/surfaceflags.h"
)
source_group("qcommon" FILES ${qcommon})

set(ALL_FILES
    ${game}
    ${qcommon}
)

################################################################################
# Target
################################################################################
add_library(${PROJECT_NAME} SHARED ${ALL_FILES})
set_target_properties(${PROJECT_NAME} PROPERTIES FOLDER "game_dll")

use_props(${PROJECT_NAME} "${CMAKE_CONFIGURATION_TYPES}" "${DEFAULT_CXX_PROPS}")
set(ROOT_NAMESPACE baseq3_qagame_dll)

set_target_properties(${PROJECT_NAME} PROPERTIES
    VS_GLOBAL_KEYWORD "Win32Proj"
)
################################################################################
# Target name
################################################################################
if("${CMAKE_VS_PLATFORM_NAME}" STREQUAL "Win32")
    set_target_properties(${PROJECT_NAME} PROPERTIES
        TARGET_NAME_DEBUG   "qagamex86"
        TARGET_NAME_RELEASE "qagamex86"
    )
elseif("${CMAKE_VS_PLATFORM_NAME}" STREQUAL "x64")
    set_target_properties(${PROJECT_NAME} PROPERTIES
        TARGET_NAME_DEBUG   "qagamex86_64"
        TARGET_NAME_RELEASE "qagamex86_64"
    )
endif()
################################################################################
# Output directory
################################################################################
if("${CMAKE_VS_PLATFORM_NAME}" STREQUAL "Win32")
    set_target_properties(${PROJECT_NAME} PROPERTIES
        OUTPUT_DIRECTORY_DEBUG   "${CMAKE_CURRENT_SOURCE_DIR}/bin_x86_debug/baseq3/"
        OUTPUT_DIRECTORY_RELEASE "${CMAKE_CURRENT_SOURCE_DIR}/bin_x86/baseq3/"
    )
elseif("${CMAKE_VS_PLATFORM_NAME}" STREQUAL "x64")
    set_target_properties(${PROJECT_NAME} PROPERTIES
        OUTPUT_DIRECTORY_DEBUG   "${CMAKE_CURRENT_SOURCE_DIR}/bin_x64_debug/baseq3/"
        OUTPUT_DIRECTORY_RELEASE "${CMAKE_CURRENT_SOURCE_DIR}/bin_x64/baseq3/"
    )
endif()
if("${CMAKE_VS_PLATFORM_NAME}" STREQUAL "Win32")
    set_target_properties(${PROJECT_NAME} PROPERTIES
        ARCHIVE_OUTPUT_DIRECTORY_DEBUG   "${CMAKE_CURRENT_SOURCE_DIR}/bin_x86_debug/baseq3"
        ARCHIVE_OUTPUT_DIRECTORY_RELEASE "${CMAKE_CURRENT_SOURCE_DIR}/bin_x86/baseq3"
    )
elseif("${CMAKE_VS_PLATFORM_NAME}" STREQUAL "x64")
    set_target_properties(${PROJECT_NAME} PROPERTIES
        ARCHIVE_OUTPUT_DIRECTORY_DEBUG   "${CMAKE_CURRENT_SOURCE_DIR}/bin_x64_debug/baseq3"
        ARCHIVE_OUTPUT_DIRECTORY_RELEASE "${CMAKE_CURRENT_SOURCE_DIR}/bin_x64/baseq3"
    )
endif()
if("${CMAKE_VS_PLATFORM_NAME}" STREQUAL "Win32")
    set_target_properties(${PROJECT_NAME} PROPERTIES
        ARCHIVE_OUTPUT_NAME_DEBUG   "qagamex86"
        ARCHIVE_OUTPUT_NAME_RELEASE "qagamex86"
    )
elseif("${CMAKE_VS_PLATFORM_NAME}" STREQUAL "x64")
    set_target_properties(${PROJECT_NAME} PROPERTIES
        ARCHIVE_OUTPUT_NAME_DEBUG   "qagamex86_64"
        ARCHIVE_OUTPUT_NAME_RELEASE "qagamex86_64"
    )
endif()
################################################################################
# Compile definitions
################################################################################
if("${CMAKE_VS_PLATFORM_NAME}" STREQUAL "Win32")
    target_compile_definitions(${PROJECT_NAME} PRIVATE
        "$<$<CONFIG:Debug>:"
            "_DEBUG"
        ">"
        "$<$<CONFIG:Release>:"
            "NDEBUG"
        ">"
        "_CRT_SECURE_NO_DEPRECATE;"
        "UNICODE;"
        "_UNICODE"
    )
elseif("${CMAKE_VS_PLATFORM_NAME}" STREQUAL "x64")
    target_compile_definitions(${PROJECT_NAME} PRIVATE
        "$<$<CONFIG:Debug>:"
            "_DEBUG"
        ">"
        "$<$<CONFIG:Release>:"
            "NDEBUG"
        ">"
        "_CRT_SECURE_NO_DEPRECATE;"
        "_WIN64;"
        "__WIN64__;"
        "UNICODE;"
        "_UNICODE"
    )
endif()

################################################################################
# Compile and link options
################################################################################
if(MSVC)
    if("${CMAKE_VS_PLATFORM_NAME}" STREQUAL "Win32")
        target_compile_options(${PROJECT_NAME} PRIVATE
            $<$<CONFIG:Debug>:
                /Od;
                ${DEFAULT_CXX_DEBUG_RUNTIME_LIBRARY};
                /ZI
            >
            $<$<CONFIG:Release>:
                /Gm-;
                /Ox;
                /Oi;
                /GF;
                ${DEFAULT_CXX_RUNTIME_LIBRARY};
                /Gy;
                ${DEFAULT_CXX_DEBUG_INFORMATION_FORMAT}
            >
            /W3;
            ${DEFAULT_CXX_EXCEPTION_HANDLING};
            /Y-
        )
    elseif("${CMAKE_VS_PLATFORM_NAME}" STREQUAL "x64")
        target_compile_options(${PROJECT_NAME} PRIVATE
            $<$<CONFIG:Debug>:
                /Od;
                ${DEFAULT_CXX_DEBUG_RUNTIME_LIBRARY};
                /ZI
            >
            $<$<CONFIG:Release>:
                /Gm-;
                /Ox;
                /Oi;
                /GF;
                ${DEFAULT_CXX_RUNTIME_LIBRARY};
                /Gy;
                ${DEFAULT_CXX_DEBUG_INFORMATION_FORMAT}
            >
            /W3;
            ${DEFAULT_CXX_EXCEPTION_HANDLING};
            /Y-
        )
    endif()
    if("${CMAKE_VS_PLATFORM_NAME}" STREQUAL "Win32")
        target_link_options(${PROJECT_NAME} PRIVATE
            $<$<CONFIG:Debug>:
                /DEBUG;
                /INCREMENTAL
            >
            $<$<CONFIG:Release>:
                /DEBUG:FULL;
                /OPT:REF;
                /OPT:ICF;
                /INCREMENTAL:NO
            >
            /SUBSYSTEM:WINDOWS
        )
    elseif("${CMAKE_VS_PLATFORM_NAME}" STREQUAL "x64")
        target_link_options(${PROJECT_NAME} PRIVATE
            $<$<CONFIG:Debug>:
                /DEBUG;
                /INCREMENTAL
            >
            $<$<CONFIG:Release>:
                /DEBUG:FULL;
                /OPT:REF;
                /OPT:ICF;
                /INCREMENTAL:NO
            >
            /SUBSYSTEM:WINDOWS
        )
    endif()
endif()

################################################################################
# Dependencies
################################################################################
if("${CMAKE_VS_PLATFORM_NAME}" STREQUAL "Win32")
    set(ADDITIONAL_LIBRARY_DEPENDENCIES
        "winmm"
    )
elseif("${CMAKE_VS_PLATFORM_NAME}" STREQUAL "x64")
    set(ADDITIONAL_LIBRARY_DEPENDENCIES
        "winmm"
    )
endif()
target_link_libraries(${PROJECT_NAME} PUBLIC "${ADDITIONAL_LIBRARY_DEPENDENCIES}")



























project(baseq3_ui_dll C)

################################################################################
# Source groups
################################################################################
set(game
    "../../../ioq3/code/game/bg_misc.c"
)
source_group("game" FILES ${game})

set(q3_ui
    "../../../ioq3/code/q3_ui/ui_addbots.c"
    "../../../ioq3/code/q3_ui/ui_atoms.c"
    "../../../ioq3/code/q3_ui/ui_cdkey.c"
    "../../../ioq3/code/q3_ui/ui_cinematics.c"
    "../../../ioq3/code/q3_ui/ui_confirm.c"
    "../../../ioq3/code/q3_ui/ui_connect.c"
    "../../../ioq3/code/q3_ui/ui_controls2.c"
    "../../../ioq3/code/q3_ui/ui_credits.c"
    "../../../ioq3/code/q3_ui/ui_demo2.c"
    "../../../ioq3/code/q3_ui/ui_display.c"
    "../../../ioq3/code/q3_ui/ui_gameinfo.c"
    "../../../ioq3/code/q3_ui/ui_ingame.c"
    "../../../ioq3/code/q3_ui/ui_local.h"
    "../../../ioq3/code/q3_ui/ui_main.c"
    "../../../ioq3/code/q3_ui/ui_menu.c"
    "../../../ioq3/code/q3_ui/ui_mfield.c"
    "../../../ioq3/code/q3_ui/ui_mods.c"
    "../../../ioq3/code/q3_ui/ui_network.c"
    "../../../ioq3/code/q3_ui/ui_options.c"
    "../../../ioq3/code/q3_ui/ui_playermodel.c"
    "../../../ioq3/code/q3_ui/ui_players.c"
    "../../../ioq3/code/q3_ui/ui_playersettings.c"
    "../../../ioq3/code/q3_ui/ui_preferences.c"
    "../../../ioq3/code/q3_ui/ui_qmenu.c"
    "../../../ioq3/code/q3_ui/ui_removebots.c"
    "../../../ioq3/code/q3_ui/ui_serverinfo.c"
    "../../../ioq3/code/q3_ui/ui_servers2.c"
    "../../../ioq3/code/q3_ui/ui_setup.c"
    "../../../ioq3/code/q3_ui/ui_sound.c"
    "../../../ioq3/code/q3_ui/ui_sparena.c"
    "../../../ioq3/code/q3_ui/ui_specifyserver.c"
    "../../../ioq3/code/q3_ui/ui_splevel.c"
    "../../../ioq3/code/q3_ui/ui_sppostgame.c"
    "../../../ioq3/code/q3_ui/ui_spreset.c"
    "../../../ioq3/code/q3_ui/ui_spskill.c"
    "../../../ioq3/code/q3_ui/ui_startserver.c"
    "../../../ioq3/code/q3_ui/ui_team.c"
    "../../../ioq3/code/q3_ui/ui_teamorders.c"
    "../../../ioq3/code/q3_ui/ui_video.c"
)
source_group("q3_ui" FILES ${q3_ui})

set(qcommon
    "../../../ioq3/code/qcommon/q_math.c"
    "../../../ioq3/code/qcommon/q_shared.c"
    "../../../ioq3/code/qcommon/q_shared.h"
)
source_group("qcommon" FILES ${qcommon})

set(ui
    "../../../ioq3/code/ui/ui_syscalls.c"
)
source_group("ui" FILES ${ui})

set(ALL_FILES
    ${game}
    ${q3_ui}
    ${qcommon}
    ${ui}
)

################################################################################
# Target
################################################################################
add_library(${PROJECT_NAME} SHARED ${ALL_FILES})
set_target_properties(${PROJECT_NAME} PROPERTIES FOLDER "game_dll")

use_props(${PROJECT_NAME} "${CMAKE_CONFIGURATION_TYPES}" "${DEFAULT_CXX_PROPS}")
set(ROOT_NAMESPACE baseq3_ui_dll)

set_target_properties(${PROJECT_NAME} PROPERTIES
    VS_GLOBAL_KEYWORD "Win32Proj"
)
################################################################################
# Target name
################################################################################
if("${CMAKE_VS_PLATFORM_NAME}" STREQUAL "Win32")
    set_target_properties(${PROJECT_NAME} PROPERTIES
        TARGET_NAME_DEBUG   "uix86"
        TARGET_NAME_RELEASE "uix86"
    )
elseif("${CMAKE_VS_PLATFORM_NAME}" STREQUAL "x64")
    set_target_properties(${PROJECT_NAME} PROPERTIES
        TARGET_NAME_DEBUG   "uix86_64"
        TARGET_NAME_RELEASE "uix86_64"
    )
endif()
################################################################################
# Output directory
################################################################################
if("${CMAKE_VS_PLATFORM_NAME}" STREQUAL "Win32")
    set_target_properties(${PROJECT_NAME} PROPERTIES
        OUTPUT_DIRECTORY_DEBUG   "${CMAKE_CURRENT_SOURCE_DIR}/bin_x86_debug/baseq3/"
        OUTPUT_DIRECTORY_RELEASE "${CMAKE_CURRENT_SOURCE_DIR}/bin_x86/baseq3/"
    )
elseif("${CMAKE_VS_PLATFORM_NAME}" STREQUAL "x64")
    set_target_properties(${PROJECT_NAME} PROPERTIES
        OUTPUT_DIRECTORY_DEBUG   "${CMAKE_CURRENT_SOURCE_DIR}/bin_x64_debug/baseq3/"
        OUTPUT_DIRECTORY_RELEASE "${CMAKE_CURRENT_SOURCE_DIR}/bin_x64/baseq3/"
    )
endif()
if("${CMAKE_VS_PLATFORM_NAME}" STREQUAL "Win32")
    set_target_properties(${PROJECT_NAME} PROPERTIES
        ARCHIVE_OUTPUT_DIRECTORY_DEBUG   "${CMAKE_CURRENT_SOURCE_DIR}/bin_x86_debug/baseq3"
        ARCHIVE_OUTPUT_DIRECTORY_RELEASE "${CMAKE_CURRENT_SOURCE_DIR}/bin_x86/baseq3"
    )
elseif("${CMAKE_VS_PLATFORM_NAME}" STREQUAL "x64")
    set_target_properties(${PROJECT_NAME} PROPERTIES
        ARCHIVE_OUTPUT_DIRECTORY_DEBUG   "${CMAKE_CURRENT_SOURCE_DIR}/bin_x64_debug/baseq3"
        ARCHIVE_OUTPUT_DIRECTORY_RELEASE "${CMAKE_CURRENT_SOURCE_DIR}/bin_x64/baseq3"
    )
endif()
if("${CMAKE_VS_PLATFORM_NAME}" STREQUAL "Win32")
    set_target_properties(${PROJECT_NAME} PROPERTIES
        ARCHIVE_OUTPUT_NAME_DEBUG   "uix86"
        ARCHIVE_OUTPUT_NAME_RELEASE "uix86"
    )
elseif("${CMAKE_VS_PLATFORM_NAME}" STREQUAL "x64")
    set_target_properties(${PROJECT_NAME} PROPERTIES
        ARCHIVE_OUTPUT_NAME_DEBUG   "uix86_64"
        ARCHIVE_OUTPUT_NAME_RELEASE "uix86_64"
    )
endif()
################################################################################
# Compile definitions
################################################################################
if("${CMAKE_VS_PLATFORM_NAME}" STREQUAL "Win32")
    target_compile_definitions(${PROJECT_NAME} PRIVATE
        "$<$<CONFIG:Debug>:"
            "_DEBUG"
        ">"
        "$<$<CONFIG:Release>:"
            "NDEBUG"
        ">"
        "_CRT_SECURE_NO_DEPRECATE;"
        "UNICODE;"
        "_UNICODE"
    )
elseif("${CMAKE_VS_PLATFORM_NAME}" STREQUAL "x64")
    target_compile_definitions(${PROJECT_NAME} PRIVATE
        "$<$<CONFIG:Debug>:"
            "_DEBUG"
        ">"
        "$<$<CONFIG:Release>:"
            "NDEBUG"
        ">"
        "_CRT_SECURE_NO_DEPRECATE;"
        "_WIN64;"
        "__WIN64__;"
        "UNICODE;"
        "_UNICODE"
    )
endif()

################################################################################
# Compile and link options
################################################################################
if(MSVC)
    if("${CMAKE_VS_PLATFORM_NAME}" STREQUAL "Win32")
        target_compile_options(${PROJECT_NAME} PRIVATE
            $<$<CONFIG:Debug>:
                /Od;
                ${DEFAULT_CXX_DEBUG_RUNTIME_LIBRARY};
                /ZI
            >
            $<$<CONFIG:Release>:
                /Gm-;
                /Ox;
                /Oi;
                /GF;
                ${DEFAULT_CXX_RUNTIME_LIBRARY};
                /Gy;
                ${DEFAULT_CXX_DEBUG_INFORMATION_FORMAT}
            >
            /W3;
            ${DEFAULT_CXX_EXCEPTION_HANDLING};
            /Y-
        )
    elseif("${CMAKE_VS_PLATFORM_NAME}" STREQUAL "x64")
        target_compile_options(${PROJECT_NAME} PRIVATE
            $<$<CONFIG:Debug>:
                /Od;
                ${DEFAULT_CXX_DEBUG_RUNTIME_LIBRARY};
                /ZI
            >
            $<$<CONFIG:Release>:
                /Gm-;
                /Ox;
                /Oi;
                /GF;
                ${DEFAULT_CXX_RUNTIME_LIBRARY};
                /Gy;
                ${DEFAULT_CXX_DEBUG_INFORMATION_FORMAT}
            >
            /W3;
            ${DEFAULT_CXX_EXCEPTION_HANDLING};
            /Y-
        )
    endif()
    if("${CMAKE_VS_PLATFORM_NAME}" STREQUAL "Win32")
        target_link_options(${PROJECT_NAME} PRIVATE
            $<$<CONFIG:Debug>:
                /DEBUG;
                /INCREMENTAL
            >
            $<$<CONFIG:Release>:
                /DEBUG:FULL;
                /OPT:REF;
                /OPT:ICF;
                /INCREMENTAL:NO
            >
            /SUBSYSTEM:WINDOWS
        )
    elseif("${CMAKE_VS_PLATFORM_NAME}" STREQUAL "x64")
        target_link_options(${PROJECT_NAME} PRIVATE
            $<$<CONFIG:Debug>:
                /DEBUG;
                /INCREMENTAL
            >
            $<$<CONFIG:Release>:
                /DEBUG:FULL;
                /OPT:REF;
                /OPT:ICF;
                /INCREMENTAL:NO
            >
            /SUBSYSTEM:WINDOWS
        )
    endif()
endif()

################################################################################
# Dependencies
################################################################################
if("${CMAKE_VS_PLATFORM_NAME}" STREQUAL "Win32")
    set(ADDITIONAL_LIBRARY_DEPENDENCIES
        "winmm"
    )
elseif("${CMAKE_VS_PLATFORM_NAME}" STREQUAL "x64")
    set(ADDITIONAL_LIBRARY_DEPENDENCIES
        "winmm"
    )
endif()
target_link_libraries(${PROJECT_NAME} PUBLIC "${ADDITIONAL_LIBRARY_DEPENDENCIES}")



























project(missionpack_cgame_dll C)

################################################################################
# Source groups
################################################################################
set(cgame
    "../../../ioq3/code/cgame/cg_consolecmds.c"
    "../../../ioq3/code/cgame/cg_draw.c"
    "../../../ioq3/code/cgame/cg_drawtools.c"
    "../../../ioq3/code/cgame/cg_effects.c"
    "../../../ioq3/code/cgame/cg_ents.c"
    "../../../ioq3/code/cgame/cg_event.c"
    "../../../ioq3/code/cgame/cg_info.c"
    "../../../ioq3/code/cgame/cg_local.h"
    "../../../ioq3/code/cgame/cg_localents.c"
    "../../../ioq3/code/cgame/cg_main.c"
    "../../../ioq3/code/cgame/cg_marks.c"
    "../../../ioq3/code/cgame/cg_newdraw.c"
    "../../../ioq3/code/cgame/cg_particles.c"
    "../../../ioq3/code/cgame/cg_players.c"
    "../../../ioq3/code/cgame/cg_playerstate.c"
    "../../../ioq3/code/cgame/cg_predict.c"
    "../../../ioq3/code/cgame/cg_public.h"
    "../../../ioq3/code/cgame/cg_scoreboard.c"
    "../../../ioq3/code/cgame/cg_servercmds.c"
    "../../../ioq3/code/cgame/cg_snapshot.c"
    "../../../ioq3/code/cgame/cg_syscalls.c"
    "../../../ioq3/code/cgame/cg_view.c"
    "../../../ioq3/code/cgame/cg_weapons.c"
)
source_group("cgame" FILES ${cgame})

set(game
    "../../../ioq3/code/game/bg_local.h"
    "../../../ioq3/code/game/bg_misc.c"
    "../../../ioq3/code/game/bg_pmove.c"
    "../../../ioq3/code/game/bg_public.h"
    "../../../ioq3/code/game/bg_slidemove.c"
)
source_group("game" FILES ${game})

set(qcommon
    "../../../ioq3/code/qcommon/q_math.c"
    "../../../ioq3/code/qcommon/q_shared.c"
    "../../../ioq3/code/qcommon/q_shared.h"
    "../../../ioq3/code/qcommon/surfaceflags.h"
)
source_group("qcommon" FILES ${qcommon})

set(ui
    "../../../ioq3/code/ui/ui_shared.c"
    "../../../ioq3/code/ui/ui_shared.h"
)
source_group("ui" FILES ${ui})

set(ALL_FILES
    ${cgame}
    ${game}
    ${qcommon}
    ${ui}
)

################################################################################
# Target
################################################################################
add_library(${PROJECT_NAME} SHARED ${ALL_FILES})
set_target_properties(${PROJECT_NAME} PROPERTIES FOLDER "game_dll")

use_props(${PROJECT_NAME} "${CMAKE_CONFIGURATION_TYPES}" "${DEFAULT_CXX_PROPS}")
set(ROOT_NAMESPACE missionpack_cgame_dll)

set_target_properties(${PROJECT_NAME} PROPERTIES
    VS_GLOBAL_KEYWORD "Win32Proj"
)
################################################################################
# Target name
################################################################################
if("${CMAKE_VS_PLATFORM_NAME}" STREQUAL "Win32")
    set_target_properties(${PROJECT_NAME} PROPERTIES
        TARGET_NAME_DEBUG   "cgamex86"
        TARGET_NAME_RELEASE "cgamex86"
    )
elseif("${CMAKE_VS_PLATFORM_NAME}" STREQUAL "x64")
    set_target_properties(${PROJECT_NAME} PROPERTIES
        TARGET_NAME_DEBUG   "cgamex86_64"
        TARGET_NAME_RELEASE "cgamex86_64"
    )
endif()
################################################################################
# Output directory
################################################################################
if("${CMAKE_VS_PLATFORM_NAME}" STREQUAL "Win32")
    set_target_properties(${PROJECT_NAME} PROPERTIES
        OUTPUT_DIRECTORY_DEBUG   "${CMAKE_CURRENT_SOURCE_DIR}/bin_x86_debug/missionpack/"
        OUTPUT_DIRECTORY_RELEASE "${CMAKE_CURRENT_SOURCE_DIR}/bin_x86/missionpack/"
    )
elseif("${CMAKE_VS_PLATFORM_NAME}" STREQUAL "x64")
    set_target_properties(${PROJECT_NAME} PROPERTIES
        OUTPUT_DIRECTORY_DEBUG   "${CMAKE_CURRENT_SOURCE_DIR}/bin_x64_debug/missionpack/"
        OUTPUT_DIRECTORY_RELEASE "${CMAKE_CURRENT_SOURCE_DIR}/bin_x64/missionpack/"
    )
endif()
if("${CMAKE_VS_PLATFORM_NAME}" STREQUAL "Win32")
    set_target_properties(${PROJECT_NAME} PROPERTIES
        ARCHIVE_OUTPUT_DIRECTORY_DEBUG   "${CMAKE_CURRENT_SOURCE_DIR}/bin_x86_debug/missionpack"
        ARCHIVE_OUTPUT_DIRECTORY_RELEASE "${CMAKE_CURRENT_SOURCE_DIR}/bin_x86/missionpack"
    )
elseif("${CMAKE_VS_PLATFORM_NAME}" STREQUAL "x64")
    set_target_properties(${PROJECT_NAME} PROPERTIES
        ARCHIVE_OUTPUT_DIRECTORY_DEBUG   "${CMAKE_CURRENT_SOURCE_DIR}/bin_x64_debug/missionpack"
        ARCHIVE_OUTPUT_DIRECTORY_RELEASE "${CMAKE_CURRENT_SOURCE_DIR}/bin_x64/missionpack"
    )
endif()
if("${CMAKE_VS_PLATFORM_NAME}" STREQUAL "Win32")
    set_target_properties(${PROJECT_NAME} PROPERTIES
        ARCHIVE_OUTPUT_NAME_DEBUG   "cgamex86"
        ARCHIVE_OUTPUT_NAME_RELEASE "cgamex86"
    )
elseif("${CMAKE_VS_PLATFORM_NAME}" STREQUAL "x64")
    set_target_properties(${PROJECT_NAME} PROPERTIES
        ARCHIVE_OUTPUT_NAME_DEBUG   "cgamex86_64"
        ARCHIVE_OUTPUT_NAME_RELEASE "cgamex86_64"
    )
endif()
################################################################################
# Compile definitions
################################################################################
if("${CMAKE_VS_PLATFORM_NAME}" STREQUAL "Win32")
    target_compile_definitions(${PROJECT_NAME} PRIVATE
        "$<$<CONFIG:Debug>:"
            "_DEBUG"
        ">"
        "$<$<CONFIG:Release>:"
            "NDEBUG"
        ">"
        "_CRT_SECURE_NO_DEPRECATE;"
        "MISSIONPACK;"
        "UNICODE;"
        "_UNICODE"
    )
elseif("${CMAKE_VS_PLATFORM_NAME}" STREQUAL "x64")
    target_compile_definitions(${PROJECT_NAME} PRIVATE
        "$<$<CONFIG:Debug>:"
            "_DEBUG"
        ">"
        "$<$<CONFIG:Release>:"
            "NDEBUG"
        ">"
        "_CRT_SECURE_NO_DEPRECATE;"
        "_WIN64;"
        "__WIN64__;"
        "MISSIONPACK;"
        "UNICODE;"
        "_UNICODE"
    )
endif()

################################################################################
# Compile and link options
################################################################################
if(MSVC)
    if("${CMAKE_VS_PLATFORM_NAME}" STREQUAL "Win32")
        target_compile_options(${PROJECT_NAME} PRIVATE
            $<$<CONFIG:Debug>:
                /Od;
                ${DEFAULT_CXX_DEBUG_RUNTIME_LIBRARY};
                /ZI
            >
            $<$<CONFIG:Release>:
                /Gm-;
                /Ox;
                /Oi;
                /GF;
                ${DEFAULT_CXX_RUNTIME_LIBRARY};
                /Gy;
                ${DEFAULT_CXX_DEBUG_INFORMATION_FORMAT}
            >
            /W3;
            ${DEFAULT_CXX_EXCEPTION_HANDLING};
            /Y-
        )
    elseif("${CMAKE_VS_PLATFORM_NAME}" STREQUAL "x64")
        target_compile_options(${PROJECT_NAME} PRIVATE
            $<$<CONFIG:Debug>:
                /Od;
                ${DEFAULT_CXX_DEBUG_RUNTIME_LIBRARY};
                /ZI
            >
            $<$<CONFIG:Release>:
                /Gm-;
                /Ox;
                /Oi;
                /GF;
                ${DEFAULT_CXX_RUNTIME_LIBRARY};
                /Gy;
                ${DEFAULT_CXX_DEBUG_INFORMATION_FORMAT}
            >
            /W3;
            ${DEFAULT_CXX_EXCEPTION_HANDLING};
            /Y-
        )
    endif()
    if("${CMAKE_VS_PLATFORM_NAME}" STREQUAL "Win32")
        target_link_options(${PROJECT_NAME} PRIVATE
            $<$<CONFIG:Debug>:
                /DEBUG;
                /INCREMENTAL
            >
            $<$<CONFIG:Release>:
                /DEBUG:FULL;
                /OPT:REF;
                /OPT:ICF;
                /INCREMENTAL:NO
            >
            /SUBSYSTEM:WINDOWS
        )
    elseif("${CMAKE_VS_PLATFORM_NAME}" STREQUAL "x64")
        target_link_options(${PROJECT_NAME} PRIVATE
            $<$<CONFIG:Debug>:
                /DEBUG;
                /INCREMENTAL
            >
            $<$<CONFIG:Release>:
                /DEBUG:FULL;
                /OPT:REF;
                /OPT:ICF;
                /INCREMENTAL:NO
            >
            /SUBSYSTEM:WINDOWS
        )
    endif()
endif()

################################################################################
# Dependencies
################################################################################
if("${CMAKE_VS_PLATFORM_NAME}" STREQUAL "Win32")
    set(ADDITIONAL_LIBRARY_DEPENDENCIES
        "winmm"
    )
elseif("${CMAKE_VS_PLATFORM_NAME}" STREQUAL "x64")
    set(ADDITIONAL_LIBRARY_DEPENDENCIES
        "winmm"
    )
endif()
target_link_libraries(${PROJECT_NAME} PUBLIC "${ADDITIONAL_LIBRARY_DEPENDENCIES}")



























project(missionpack_qagame_dll C)

################################################################################
# Source groups
################################################################################
set(game
    "../../../ioq3/code/game/ai_chat.c"
    "../../../ioq3/code/game/ai_chat.h"
    "../../../ioq3/code/game/ai_cmd.c"
    "../../../ioq3/code/game/ai_cmd.h"
    "../../../ioq3/code/game/ai_dmnet.c"
    "../../../ioq3/code/game/ai_dmnet.h"
    "../../../ioq3/code/game/ai_dmq3.c"
    "../../../ioq3/code/game/ai_dmq3.h"
    "../../../ioq3/code/game/ai_main.c"
    "../../../ioq3/code/game/ai_main.h"
    "../../../ioq3/code/game/ai_team.c"
    "../../../ioq3/code/game/ai_team.h"
    "../../../ioq3/code/game/ai_vcmd.c"
    "../../../ioq3/code/game/ai_vcmd.h"
    "../../../ioq3/code/game/bg_local.h"
    "../../../ioq3/code/game/bg_misc.c"
    "../../../ioq3/code/game/bg_pmove.c"
    "../../../ioq3/code/game/bg_public.h"
    "../../../ioq3/code/game/bg_slidemove.c"
    "../../../ioq3/code/game/chars.h"
    "../../../ioq3/code/game/g_active.c"
    "../../../ioq3/code/game/g_arenas.c"
    "../../../ioq3/code/game/g_bot.c"
    "../../../ioq3/code/game/g_client.c"
    "../../../ioq3/code/game/g_cmds.c"
    "../../../ioq3/code/game/g_combat.c"
    "../../../ioq3/code/game/g_items.c"
    "../../../ioq3/code/game/g_local.h"
    "../../../ioq3/code/game/g_main.c"
    "../../../ioq3/code/game/g_mem.c"
    "../../../ioq3/code/game/g_misc.c"
    "../../../ioq3/code/game/g_missile.c"
    "../../../ioq3/code/game/g_mover.c"
    "../../../ioq3/code/game/g_public.h"
    "../../../ioq3/code/game/g_rankings.h"
    "../../../ioq3/code/game/g_session.c"
    "../../../ioq3/code/game/g_spawn.c"
    "../../../ioq3/code/game/g_svcmds.c"
    "../../../ioq3/code/game/g_syscalls.c"
    "../../../ioq3/code/game/g_target.c"
    "../../../ioq3/code/game/g_team.c"
    "../../../ioq3/code/game/g_team.h"
    "../../../ioq3/code/game/g_trigger.c"
    "../../../ioq3/code/game/g_utils.c"
    "../../../ioq3/code/game/g_weapon.c"
    "../../../ioq3/code/game/inv.h"
    "../../../ioq3/code/game/match.h"
    "../../../ioq3/code/game/syn.h"
)
source_group("game" FILES ${game})

set(qcommon
    "../../../ioq3/code/qcommon/q_math.c"
    "../../../ioq3/code/qcommon/q_shared.c"
    "../../../ioq3/code/qcommon/q_shared.h"
    "../../../ioq3/code/qcommon/surfaceflags.h"
)
source_group("qcommon" FILES ${qcommon})

set(ALL_FILES
    ${game}
    ${qcommon}
)

################################################################################
# Target
################################################################################
add_library(${PROJECT_NAME} SHARED ${ALL_FILES})
set_target_properties(${PROJECT_NAME} PROPERTIES FOLDER "game_dll")

use_props(${PROJECT_NAME} "${CMAKE_CONFIGURATION_TYPES}" "${DEFAULT_CXX_PROPS}")
set(ROOT_NAMESPACE missionpack_qagame_dll)

set_target_properties(${PROJECT_NAME} PROPERTIES
    VS_GLOBAL_KEYWORD "Win32Proj"
)
################################################################################
# Target name
################################################################################
if("${CMAKE_VS_PLATFORM_NAME}" STREQUAL "Win32")
    set_target_properties(${PROJECT_NAME} PROPERTIES
        TARGET_NAME_DEBUG   "qagamex86"
        TARGET_NAME_RELEASE "qagamex86"
    )
elseif("${CMAKE_VS_PLATFORM_NAME}" STREQUAL "x64")
    set_target_properties(${PROJECT_NAME} PROPERTIES
        TARGET_NAME_DEBUG   "qagamex86_64"
        TARGET_NAME_RELEASE "qagamex86_64"
    )
endif()
################################################################################
# Output directory
################################################################################
if("${CMAKE_VS_PLATFORM_NAME}" STREQUAL "Win32")
    set_target_properties(${PROJECT_NAME} PROPERTIES
        OUTPUT_DIRECTORY_DEBUG   "${CMAKE_CURRENT_SOURCE_DIR}/bin_x86_debug/missionpack/"
        OUTPUT_DIRECTORY_RELEASE "${CMAKE_CURRENT_SOURCE_DIR}/bin_x86/missionpack/"
    )
elseif("${CMAKE_VS_PLATFORM_NAME}" STREQUAL "x64")
    set_target_properties(${PROJECT_NAME} PROPERTIES
        OUTPUT_DIRECTORY_DEBUG   "${CMAKE_CURRENT_SOURCE_DIR}/bin_x64_debug/missionpack/"
        OUTPUT_DIRECTORY_RELEASE "${CMAKE_CURRENT_SOURCE_DIR}/bin_x64/missionpack/"
    )
endif()
if("${CMAKE_VS_PLATFORM_NAME}" STREQUAL "Win32")
    set_target_properties(${PROJECT_NAME} PROPERTIES
        ARCHIVE_OUTPUT_DIRECTORY_DEBUG   "${CMAKE_CURRENT_SOURCE_DIR}/bin_x86_debug/missionpack"
        ARCHIVE_OUTPUT_DIRECTORY_RELEASE "${CMAKE_CURRENT_SOURCE_DIR}/bin_x86/missionpack"
    )
elseif("${CMAKE_VS_PLATFORM_NAME}" STREQUAL "x64")
    set_target_properties(${PROJECT_NAME} PROPERTIES
        ARCHIVE_OUTPUT_DIRECTORY_DEBUG   "${CMAKE_CURRENT_SOURCE_DIR}/bin_x64_debug/missionpack"
        ARCHIVE_OUTPUT_DIRECTORY_RELEASE "${CMAKE_CURRENT_SOURCE_DIR}/bin_x64/missionpack"
    )
endif()
if("${CMAKE_VS_PLATFORM_NAME}" STREQUAL "Win32")
    set_target_properties(${PROJECT_NAME} PROPERTIES
        ARCHIVE_OUTPUT_NAME_DEBUG   "qagamex86"
        ARCHIVE_OUTPUT_NAME_RELEASE "qagamex86"
    )
elseif("${CMAKE_VS_PLATFORM_NAME}" STREQUAL "x64")
    set_target_properties(${PROJECT_NAME} PROPERTIES
        ARCHIVE_OUTPUT_NAME_DEBUG   "qagamex86_64"
        ARCHIVE_OUTPUT_NAME_RELEASE "qagamex86_64"
    )
endif()
################################################################################
# Compile definitions
################################################################################
if("${CMAKE_VS_PLATFORM_NAME}" STREQUAL "Win32")
    target_compile_definitions(${PROJECT_NAME} PRIVATE
        "$<$<CONFIG:Debug>:"
            "_DEBUG"
        ">"
        "$<$<CONFIG:Release>:"
            "NDEBUG"
        ">"
        "_CRT_SECURE_NO_DEPRECATE;"
        "MISSIONPACK;"
        "UNICODE;"
        "_UNICODE"
    )
elseif("${CMAKE_VS_PLATFORM_NAME}" STREQUAL "x64")
    target_compile_definitions(${PROJECT_NAME} PRIVATE
        "$<$<CONFIG:Debug>:"
            "_DEBUG"
        ">"
        "$<$<CONFIG:Release>:"
            "NDEBUG"
        ">"
        "_CRT_SECURE_NO_DEPRECATE;"
        "_WIN64;"
        "__WIN64__;"
        "MISSIONPACK;"
        "UNICODE;"
        "_UNICODE"
    )
endif()

################################################################################
# Compile and link options
################################################################################
if(MSVC)
    if("${CMAKE_VS_PLATFORM_NAME}" STREQUAL "Win32")
        target_compile_options(${PROJECT_NAME} PRIVATE
            $<$<CONFIG:Debug>:
                /Od;
                ${DEFAULT_CXX_DEBUG_RUNTIME_LIBRARY};
                /ZI
            >
            $<$<CONFIG:Release>:
                /Gm-;
                /Ox;
                /Oi;
                /GF;
                ${DEFAULT_CXX_RUNTIME_LIBRARY};
                /Gy;
                ${DEFAULT_CXX_DEBUG_INFORMATION_FORMAT}
            >
            /W3;
            ${DEFAULT_CXX_EXCEPTION_HANDLING};
            /Y-
        )
    elseif("${CMAKE_VS_PLATFORM_NAME}" STREQUAL "x64")
        target_compile_options(${PROJECT_NAME} PRIVATE
            $<$<CONFIG:Debug>:
                /Od;
                ${DEFAULT_CXX_DEBUG_RUNTIME_LIBRARY};
                /ZI
            >
            $<$<CONFIG:Release>:
                /Gm-;
                /Ox;
                /Oi;
                /GF;
                ${DEFAULT_CXX_RUNTIME_LIBRARY};
                /Gy;
                ${DEFAULT_CXX_DEBUG_INFORMATION_FORMAT}
            >
            /W3;
            ${DEFAULT_CXX_EXCEPTION_HANDLING};
            /Y-
        )
    endif()
    if("${CMAKE_VS_PLATFORM_NAME}" STREQUAL "Win32")
        target_link_options(${PROJECT_NAME} PRIVATE
            $<$<CONFIG:Debug>:
                /DEBUG;
                /INCREMENTAL
            >
            $<$<CONFIG:Release>:
                /DEBUG:FULL;
                /OPT:REF;
                /OPT:ICF;
                /INCREMENTAL:NO
            >
            /SUBSYSTEM:WINDOWS
        )
    elseif("${CMAKE_VS_PLATFORM_NAME}" STREQUAL "x64")
        target_link_options(${PROJECT_NAME} PRIVATE
            $<$<CONFIG:Debug>:
                /DEBUG;
                /INCREMENTAL
            >
            $<$<CONFIG:Release>:
                /DEBUG:FULL;
                /OPT:REF;
                /OPT:ICF;
                /INCREMENTAL:NO
            >
            /SUBSYSTEM:WINDOWS
        )
    endif()
endif()

################################################################################
# Dependencies
################################################################################
if("${CMAKE_VS_PLATFORM_NAME}" STREQUAL "Win32")
    set(ADDITIONAL_LIBRARY_DEPENDENCIES
        "winmm"
    )
elseif("${CMAKE_VS_PLATFORM_NAME}" STREQUAL "x64")
    set(ADDITIONAL_LIBRARY_DEPENDENCIES
        "winmm"
    )
endif()
target_link_libraries(${PROJECT_NAME} PUBLIC "${ADDITIONAL_LIBRARY_DEPENDENCIES}")



























project(missionpack_ui_dll C)

################################################################################
# Source groups
################################################################################
set(game
    "../../../ioq3/code/game/bg_misc.c"
    "../../../ioq3/code/game/bg_public.h"
)
source_group("game" FILES ${game})

set(qcommon
    "../../../ioq3/code/qcommon/q_math.c"
    "../../../ioq3/code/qcommon/q_shared.c"
    "../../../ioq3/code/qcommon/q_shared.h"
)
source_group("qcommon" FILES ${qcommon})

set(ui
    "../../../ioq3/code/ui/ui_atoms.c"
    "../../../ioq3/code/ui/ui_gameinfo.c"
    "../../../ioq3/code/ui/ui_local.h"
    "../../../ioq3/code/ui/ui_main.c"
    "../../../ioq3/code/ui/ui_players.c"
    "../../../ioq3/code/ui/ui_public.h"
    "../../../ioq3/code/ui/ui_shared.c"
    "../../../ioq3/code/ui/ui_shared.h"
    "../../../ioq3/code/ui/ui_syscalls.c"
)
source_group("ui" FILES ${ui})

set(ALL_FILES
    ${game}
    ${qcommon}
    ${ui}
)

################################################################################
# Target
################################################################################
add_library(${PROJECT_NAME} SHARED ${ALL_FILES})
set_target_properties(${PROJECT_NAME} PROPERTIES FOLDER "game_dll")

use_props(${PROJECT_NAME} "${CMAKE_CONFIGURATION_TYPES}" "${DEFAULT_CXX_PROPS}")
set(ROOT_NAMESPACE missionpack_ui_dll)

set_target_properties(${PROJECT_NAME} PROPERTIES
    VS_GLOBAL_KEYWORD "Win32Proj"
)
################################################################################
# Target name
################################################################################
if("${CMAKE_VS_PLATFORM_NAME}" STREQUAL "Win32")
    set_target_properties(${PROJECT_NAME} PROPERTIES
        TARGET_NAME_DEBUG   "uix86"
        TARGET_NAME_RELEASE "uix86"
    )
elseif("${CMAKE_VS_PLATFORM_NAME}" STREQUAL "x64")
    set_target_properties(${PROJECT_NAME} PROPERTIES
        TARGET_NAME_DEBUG   "uix86_64"
        TARGET_NAME_RELEASE "uix86_64"
    )
endif()
################################################################################
# Output directory
################################################################################
if("${CMAKE_VS_PLATFORM_NAME}" STREQUAL "Win32")
    set_target_properties(${PROJECT_NAME} PROPERTIES
        OUTPUT_DIRECTORY_DEBUG   "${CMAKE_CURRENT_SOURCE_DIR}/bin_x86_debug/missionpack/"
        OUTPUT_DIRECTORY_RELEASE "${CMAKE_CURRENT_SOURCE_DIR}/bin_x86/missionpack/"
    )
elseif("${CMAKE_VS_PLATFORM_NAME}" STREQUAL "x64")
    set_target_properties(${PROJECT_NAME} PROPERTIES
        OUTPUT_DIRECTORY_DEBUG   "${CMAKE_CURRENT_SOURCE_DIR}/bin_x64_debug/missionpack/"
        OUTPUT_DIRECTORY_RELEASE "${CMAKE_CURRENT_SOURCE_DIR}/bin_x64/missionpack/"
    )
endif()
if("${CMAKE_VS_PLATFORM_NAME}" STREQUAL "Win32")
    set_target_properties(${PROJECT_NAME} PROPERTIES
        ARCHIVE_OUTPUT_DIRECTORY_DEBUG   "${CMAKE_CURRENT_SOURCE_DIR}/bin_x86_debug/missionpack"
        ARCHIVE_OUTPUT_DIRECTORY_RELEASE "${CMAKE_CURRENT_SOURCE_DIR}/bin_x86/missionpack"
    )
elseif("${CMAKE_VS_PLATFORM_NAME}" STREQUAL "x64")
    set_target_properties(${PROJECT_NAME} PROPERTIES
        ARCHIVE_OUTPUT_DIRECTORY_DEBUG   "${CMAKE_CURRENT_SOURCE_DIR}/bin_x64_debug/missionpack"
        ARCHIVE_OUTPUT_DIRECTORY_RELEASE "${CMAKE_CURRENT_SOURCE_DIR}/bin_x64/missionpack"
    )
endif()
if("${CMAKE_VS_PLATFORM_NAME}" STREQUAL "Win32")
    set_target_properties(${PROJECT_NAME} PROPERTIES
        ARCHIVE_OUTPUT_NAME_DEBUG   "uix86"
        ARCHIVE_OUTPUT_NAME_RELEASE "uix86"
    )
elseif("${CMAKE_VS_PLATFORM_NAME}" STREQUAL "x64")
    set_target_properties(${PROJECT_NAME} PROPERTIES
        ARCHIVE_OUTPUT_NAME_DEBUG   "uix86_64"
        ARCHIVE_OUTPUT_NAME_RELEASE "uix86_64"
    )
endif()
################################################################################
# Compile definitions
################################################################################
if("${CMAKE_VS_PLATFORM_NAME}" STREQUAL "Win32")
    target_compile_definitions(${PROJECT_NAME} PRIVATE
        "$<$<CONFIG:Debug>:"
            "_DEBUG"
        ">"
        "$<$<CONFIG:Release>:"
            "NDEBUG"
        ">"
        "_CRT_SECURE_NO_DEPRECATE;"
        "MISSIONPACK;"
        "UNICODE;"
        "_UNICODE"
    )
elseif("${CMAKE_VS_PLATFORM_NAME}" STREQUAL "x64")
    target_compile_definitions(${PROJECT_NAME} PRIVATE
        "$<$<CONFIG:Debug>:"
            "_DEBUG"
        ">"
        "$<$<CONFIG:Release>:"
            "NDEBUG"
        ">"
        "_CRT_SECURE_NO_DEPRECATE;"
        "_WIN64;"
        "__WIN64__;"
        "MISSIONPACK;"
        "UNICODE;"
        "_UNICODE"
    )
endif()

################################################################################
# Compile and link options
################################################################################
if(MSVC)
    if("${CMAKE_VS_PLATFORM_NAME}" STREQUAL "Win32")
        target_compile_options(${PROJECT_NAME} PRIVATE
            $<$<CONFIG:Debug>:
                /Od;
                ${DEFAULT_CXX_DEBUG_RUNTIME_LIBRARY};
                /ZI
            >
            $<$<CONFIG:Release>:
                /Gm-;
                /Ox;
                /Oi;
                /GF;
                ${DEFAULT_CXX_RUNTIME_LIBRARY};
                /Gy;
                ${DEFAULT_CXX_DEBUG_INFORMATION_FORMAT}
            >
            /W3;
            ${DEFAULT_CXX_EXCEPTION_HANDLING};
            /Y-
        )
    elseif("${CMAKE_VS_PLATFORM_NAME}" STREQUAL "x64")
        target_compile_options(${PROJECT_NAME} PRIVATE
            $<$<CONFIG:Debug>:
                /Od;
                ${DEFAULT_CXX_DEBUG_RUNTIME_LIBRARY};
                /ZI
            >
            $<$<CONFIG:Release>:
                /Gm-;
                /Ox;
                /Oi;
                /GF;
                ${DEFAULT_CXX_RUNTIME_LIBRARY};
                /Gy;
                ${DEFAULT_CXX_DEBUG_INFORMATION_FORMAT}
            >
            /W3;
            ${DEFAULT_CXX_EXCEPTION_HANDLING};
            /Y-
        )
    endif()
    if("${CMAKE_VS_PLATFORM_NAME}" STREQUAL "Win32")
        target_link_options(${PROJECT_NAME} PRIVATE
            $<$<CONFIG:Debug>:
                /DEBUG;
                /INCREMENTAL
            >
            $<$<CONFIG:Release>:
                /DEBUG:FULL;
                /OPT:REF;
                /OPT:ICF;
                /INCREMENTAL:NO
            >
            /SUBSYSTEM:WINDOWS
        )
    elseif("${CMAKE_VS_PLATFORM_NAME}" STREQUAL "x64")
        target_link_options(${PROJECT_NAME} PRIVATE
            $<$<CONFIG:Debug>:
                /DEBUG;
                /INCREMENTAL
            >
            $<$<CONFIG:Release>:
                /DEBUG:FULL;
                /OPT:REF;
                /OPT:ICF;
                /INCREMENTAL:NO
            >
            /SUBSYSTEM:WINDOWS
        )
    endif()
endif()

################################################################################
# Dependencies
################################################################################
if("${CMAKE_VS_PLATFORM_NAME}" STREQUAL "Win32")
    set(ADDITIONAL_LIBRARY_DEPENDENCIES
        "winmm;"
        "odbc32;"
        "odbccp32"
    )
elseif("${CMAKE_VS_PLATFORM_NAME}" STREQUAL "x64")
    set(ADDITIONAL_LIBRARY_DEPENDENCIES
        "winmm;"
        "odbc32;"
        "odbccp32"
    )
endif()
target_link_libraries(${PROJECT_NAME} PUBLIC "${ADDITIONAL_LIBRARY_DEPENDENCIES}")



























project(baseq3_cgame_qvm)

################################################################################
# Source groups
################################################################################
set(cgame
    "../../../ioq3/code/cgame/cg_local.h"
    "../../../ioq3/code/cgame/cg_public.h"
)
source_group("cgame" FILES ${cgame})

set(game
    "../../../ioq3/code/game/bg_lib.h"
    "../../../ioq3/code/game/bg_local.h"
    "../../../ioq3/code/game/bg_public.h"
)
source_group("game" FILES ${game})

set(qcommon
    "../../../ioq3/code/qcommon/q_shared.h"
    "../../../ioq3/code/qcommon/surfaceflags.h"
)
source_group("qcommon" FILES ${qcommon})

set(ALL_FILES
    ${cgame}
    ${game}
    ${qcommon}
)

add_custom_target(${PROJECT_NAME} SOURCES ${ALL_FILES})



























project(baseq3_qagame_qvm)

################################################################################
# Source groups
################################################################################
set(game
    "../../../ioq3/code/game/ai_chat.h"
    "../../../ioq3/code/game/ai_cmd.h"
    "../../../ioq3/code/game/ai_dmnet.h"
    "../../../ioq3/code/game/ai_dmq3.h"
    "../../../ioq3/code/game/ai_main.h"
    "../../../ioq3/code/game/ai_team.h"
    "../../../ioq3/code/game/ai_vcmd.h"
    "../../../ioq3/code/game/bg_lib.h"
    "../../../ioq3/code/game/bg_local.h"
    "../../../ioq3/code/game/bg_public.h"
    "../../../ioq3/code/game/chars.h"
    "../../../ioq3/code/game/g_local.h"
    "../../../ioq3/code/game/g_public.h"
    "../../../ioq3/code/game/g_team.h"
    "../../../ioq3/code/game/inv.h"
    "../../../ioq3/code/game/match.h"
    "../../../ioq3/code/game/syn.h"
)
source_group("game" FILES ${game})

set(qcommon
    "../../../ioq3/code/qcommon/q_shared.h"
    "../../../ioq3/code/qcommon/surfaceflags.h"
)
source_group("qcommon" FILES ${qcommon})

set(ALL_FILES
    ${game}
    ${qcommon}
)

add_custom_target(${PROJECT_NAME} SOURCES ${ALL_FILES})



























project(baseq3_ui_qvm)

################################################################################
# Source groups
################################################################################
set(game
    "../../../ioq3/code/game/bg_lib.h"
)
source_group("game" FILES ${game})

set(q3_ui
    "../../../ioq3/code/q3_ui/ui_local.h"
)
source_group("q3_ui" FILES ${q3_ui})

set(qcommon
    "../../../ioq3/code/qcommon/q_shared.h"
)
source_group("qcommon" FILES ${qcommon})

set(ALL_FILES
    ${game}
    ${q3_ui}
    ${qcommon}
)

add_custom_target(${PROJECT_NAME} SOURCES ${ALL_FILES})



























project(missionpack_cgame_qvm)

################################################################################
# Source groups
################################################################################
set(cgame
    "../../../ioq3/code/cgame/cg_local.h"
    "../../../ioq3/code/cgame/cg_public.h"
)
source_group("cgame" FILES ${cgame})

set(game
    "../../../ioq3/code/game/bg_lib.h"
    "../../../ioq3/code/game/bg_local.h"
    "../../../ioq3/code/game/bg_public.h"
)
source_group("game" FILES ${game})

set(qcommon
    "../../../ioq3/code/qcommon/q_shared.h"
    "../../../ioq3/code/qcommon/surfaceflags.h"
)
source_group("qcommon" FILES ${qcommon})

set(ui
    "../../../ioq3/code/ui/ui_shared.h"
)
source_group("ui" FILES ${ui})

set(ALL_FILES
    ${cgame}
    ${game}
    ${qcommon}
    ${ui}
)

add_custom_target(${PROJECT_NAME} SOURCES ${ALL_FILES})



























project(missionpack_qagame_qvm)

################################################################################
# Source groups
################################################################################
set(game
    "../../../ioq3/code/game/ai_chat.h"
    "../../../ioq3/code/game/ai_cmd.h"
    "../../../ioq3/code/game/ai_dmnet.h"
    "../../../ioq3/code/game/ai_dmq3.h"
    "../../../ioq3/code/game/ai_main.h"
    "../../../ioq3/code/game/ai_team.h"
    "../../../ioq3/code/game/ai_vcmd.h"
    "../../../ioq3/code/game/bg_lib.h"
    "../../../ioq3/code/game/bg_local.h"
    "../../../ioq3/code/game/bg_public.h"
    "../../../ioq3/code/game/chars.h"
    "../../../ioq3/code/game/g_local.h"
    "../../../ioq3/code/game/g_public.h"
    "../../../ioq3/code/game/g_team.h"
    "../../../ioq3/code/game/inv.h"
    "../../../ioq3/code/game/match.h"
    "../../../ioq3/code/game/syn.h"
)
source_group("game" FILES ${game})

set(qcommon
    "../../../ioq3/code/qcommon/q_shared.h"
    "../../../ioq3/code/qcommon/surfaceflags.h"
)
source_group("qcommon" FILES ${qcommon})

set(ALL_FILES
    ${game}
    ${qcommon}
)

add_custom_target(${PROJECT_NAME} SOURCES ${ALL_FILES})



























project(missionpack_ui_qvm)

################################################################################
# Source groups
################################################################################
set(game
    "../../../ioq3/code/game/bg_lib.h"
    "../../../ioq3/code/game/bg_public.h"
)
source_group("game" FILES ${game})

set(qcommon
    "../../../ioq3/code/qcommon/q_shared.h"
)
source_group("qcommon" FILES ${qcommon})

set(ui
    "../../../ioq3/code/ui/ui_local.h"
    "../../../ioq3/code/ui/ui_public.h"
    "../../../ioq3/code/ui/ui_shared.h"
)
source_group("ui" FILES ${ui})

set(ALL_FILES
    ${game}
    ${qcommon}
    ${ui}
)

add_custom_target(${PROJECT_NAME} SOURCES ${ALL_FILES})



























project(SDL2 C)

################################################################################
# Source groups
################################################################################
set(include
    "../../SDL2/include/begin_code.h"
    "../../SDL2/include/close_code.h"
    "../../SDL2/include/SDL.h"
    "../../SDL2/include/SDL_assert.h"
    "../../SDL2/include/SDL_atomic.h"
    "../../SDL2/include/SDL_audio.h"
    "../../SDL2/include/SDL_bits.h"
    "../../SDL2/include/SDL_blendmode.h"
    "../../SDL2/include/SDL_clipboard.h"
    "../../SDL2/include/SDL_config.h"
    "../../SDL2/include/SDL_config_android.h"
    "../../SDL2/include/SDL_config_iphoneos.h"
    "../../SDL2/include/SDL_config_macosx.h"
    "../../SDL2/include/SDL_config_minimal.h"
    "../../SDL2/include/SDL_config_os2.h"
    "../../SDL2/include/SDL_config_pandora.h"
    "../../SDL2/include/SDL_config_psp.h"
    "../../SDL2/include/SDL_config_windows.h"
    "../../SDL2/include/SDL_config_winrt.h"
    "../../SDL2/include/SDL_config_wiz.h"
    "../../SDL2/include/SDL_copying.h"
    "../../SDL2/include/SDL_cpuinfo.h"
    "../../SDL2/include/SDL_egl.h"
    "../../SDL2/include/SDL_endian.h"
    "../../SDL2/include/SDL_error.h"
    "../../SDL2/include/SDL_events.h"
    "../../SDL2/include/SDL_filesystem.h"
    "../../SDL2/include/SDL_gamecontroller.h"
    "../../SDL2/include/SDL_gesture.h"
    "../../SDL2/include/SDL_haptic.h"
    "../../SDL2/include/SDL_hints.h"
    "../../SDL2/include/SDL_joystick.h"
    "../../SDL2/include/SDL_keyboard.h"
    "../../SDL2/include/SDL_keycode.h"
    "../../SDL2/include/SDL_loadso.h"
    "../../SDL2/include/SDL_log.h"
    "../../SDL2/include/SDL_main.h"
    "../../SDL2/include/SDL_messagebox.h"
    "../../SDL2/include/SDL_metal.h"
    "../../SDL2/include/SDL_mouse.h"
    "../../SDL2/include/SDL_mutex.h"
    "../../SDL2/include/SDL_name.h"
    "../../SDL2/include/SDL_opengl.h"
    "../../SDL2/include/SDL_opengl_glext.h"
    "../../SDL2/include/SDL_opengles.h"
    "../../SDL2/include/SDL_opengles2.h"
    "../../SDL2/include/SDL_opengles2_gl2.h"
    "../../SDL2/include/SDL_opengles2_gl2ext.h"
    "../../SDL2/include/SDL_opengles2_gl2platform.h"
    "../../SDL2/include/SDL_opengles2_khrplatform.h"
    "../../SDL2/include/SDL_pixels.h"
    "../../SDL2/include/SDL_platform.h"
    "../../SDL2/include/SDL_power.h"
    "../../SDL2/include/SDL_quit.h"
    "../../SDL2/include/SDL_rect.h"
    "../../SDL2/include/SDL_render.h"
    "../../SDL2/include/SDL_revision.h"
    "../../SDL2/include/SDL_rwops.h"
    "../../SDL2/include/SDL_scancode.h"
    "../../SDL2/include/SDL_sensor.h"
    "../../SDL2/include/SDL_shape.h"
    "../../SDL2/include/SDL_stdinc.h"
    "../../SDL2/include/SDL_surface.h"
    "../../SDL2/include/SDL_system.h"
    "../../SDL2/include/SDL_syswm.h"
    "../../SDL2/include/SDL_test.h"
    "../../SDL2/include/SDL_test_assert.h"
    "../../SDL2/include/SDL_test_common.h"
    "../../SDL2/include/SDL_test_compare.h"
    "../../SDL2/include/SDL_test_crc32.h"
    "../../SDL2/include/SDL_test_font.h"
    "../../SDL2/include/SDL_test_fuzzer.h"
    "../../SDL2/include/SDL_test_harness.h"
    "../../SDL2/include/SDL_test_images.h"
    "../../SDL2/include/SDL_test_log.h"
    "../../SDL2/include/SDL_test_md5.h"
    "../../SDL2/include/SDL_test_memory.h"
    "../../SDL2/include/SDL_test_random.h"
    "../../SDL2/include/SDL_thread.h"
    "../../SDL2/include/SDL_timer.h"
    "../../SDL2/include/SDL_touch.h"
    "../../SDL2/include/SDL_types.h"
    "../../SDL2/include/SDL_version.h"
    "../../SDL2/include/SDL_video.h"
    "../../SDL2/include/SDL_vulkan.h"
)
source_group("include" FILES ${include})

set(src
    "../../SDL2/src/SDL.c"
    "../../SDL2/src/SDL_assert.c"
    "../../SDL2/src/SDL_dataqueue.c"
    "../../SDL2/src/SDL_error.c"
    "../../SDL2/src/SDL_hints.c"
    "../../SDL2/src/SDL_log.c"
)
source_group("src" FILES ${src})

set(src__atomic
    "../../SDL2/src/atomic/SDL_atomic.c"
    "../../SDL2/src/atomic/SDL_spinlock.c"
)
source_group("src\\atomic" FILES ${src__atomic})

set(src__audio
    "../../SDL2/src/audio/SDL_audio.c"
    "../../SDL2/src/audio/SDL_audiocvt.c"
    "../../SDL2/src/audio/SDL_audiodev.c"
    "../../SDL2/src/audio/SDL_audiotypecvt.c"
    "../../SDL2/src/audio/SDL_mixer.c"
    "../../SDL2/src/audio/SDL_wave.c"
)
source_group("src\\audio" FILES ${src__audio})

set(src__audio__directsound
    "../../SDL2/src/audio/directsound/SDL_directsound.c"
)
source_group("src\\audio\\directsound" FILES ${src__audio__directsound})

set(src__audio__disk
    "../../SDL2/src/audio/disk/SDL_diskaudio.c"
)
source_group("src\\audio\\disk" FILES ${src__audio__disk})

set(src__audio__dummy
    "../../SDL2/src/audio/dummy/SDL_dummyaudio.c"
)
source_group("src\\audio\\dummy" FILES ${src__audio__dummy})

set(src__audio__wasapi
    "../../SDL2/src/audio/wasapi/SDL_wasapi.c"
    "../../SDL2/src/audio/wasapi/SDL_wasapi_win32.c"
)
source_group("src\\audio\\wasapi" FILES ${src__audio__wasapi})

set(src__audio__winmm
    "../../SDL2/src/audio/winmm/SDL_winmm.c"
)
source_group("src\\audio\\winmm" FILES ${src__audio__winmm})

set(src__core__windows
    "../../SDL2/src/core/windows/SDL_windows.c"
    "../../SDL2/src/core/windows/SDL_xinput.c"
)
source_group("src\\core\\windows" FILES ${src__core__windows})

set(src__cpuinfo
    "../../SDL2/src/cpuinfo/SDL_cpuinfo.c"
)
source_group("src\\cpuinfo" FILES ${src__cpuinfo})

set(src__dynapi
    "../../SDL2/src/dynapi/SDL_dynapi.c"
)
source_group("src\\dynapi" FILES ${src__dynapi})

set(src__events
    "../../SDL2/src/events/SDL_clipboardevents.c"
    "../../SDL2/src/events/SDL_displayevents.c"
    "../../SDL2/src/events/SDL_dropevents.c"
    "../../SDL2/src/events/SDL_events.c"
    "../../SDL2/src/events/SDL_gesture.c"
    "../../SDL2/src/events/SDL_keyboard.c"
    "../../SDL2/src/events/SDL_mouse.c"
    "../../SDL2/src/events/SDL_quit.c"
    "../../SDL2/src/events/SDL_touch.c"
    "../../SDL2/src/events/SDL_windowevents.c"
)
source_group("src\\events" FILES ${src__events})

set(src__file
    "../../SDL2/src/file/SDL_rwops.c"
)
source_group("src\\file" FILES ${src__file})

set(src__filesystem__windows
    "../../SDL2/src/filesystem/windows/SDL_sysfilesystem.c"
)
source_group("src\\filesystem\\windows" FILES ${src__filesystem__windows})

set(src__haptic
    "../../SDL2/src/haptic/SDL_haptic.c"
)
source_group("src\\haptic" FILES ${src__haptic})

set(src__haptic__windows
    "../../SDL2/src/haptic/windows/SDL_dinputhaptic.c"
    "../../SDL2/src/haptic/windows/SDL_windowshaptic.c"
    "../../SDL2/src/haptic/windows/SDL_xinputhaptic.c"
)
source_group("src\\haptic\\windows" FILES ${src__haptic__windows})

set(src__hidapi__windows
    "../../SDL2/src/hidapi/windows/hid.c"
)
source_group("src\\hidapi\\windows" FILES ${src__hidapi__windows})

set(src__joystick
    "../../SDL2/src/joystick/SDL_gamecontroller.c"
    "../../SDL2/src/joystick/SDL_joystick.c"
)
source_group("src\\joystick" FILES ${src__joystick})

set(src__joystick__hidapi
    "../../SDL2/src/joystick/hidapi/SDL_hidapi_gamecube.c"
    "../../SDL2/src/joystick/hidapi/SDL_hidapi_ps4.c"
    "../../SDL2/src/joystick/hidapi/SDL_hidapi_rumble.c"
    "../../SDL2/src/joystick/hidapi/SDL_hidapi_steam.c"
    "../../SDL2/src/joystick/hidapi/SDL_hidapi_switch.c"
    "../../SDL2/src/joystick/hidapi/SDL_hidapi_xbox360.c"
    "../../SDL2/src/joystick/hidapi/SDL_hidapi_xbox360w.c"
    "../../SDL2/src/joystick/hidapi/SDL_hidapi_xboxone.c"
    "../../SDL2/src/joystick/hidapi/SDL_hidapijoystick.c"
)
source_group("src\\joystick\\hidapi" FILES ${src__joystick__hidapi})

set(src__joystick__windows
    "../../SDL2/src/joystick/windows/SDL_dinputjoystick.c"
    "../../SDL2/src/joystick/windows/SDL_mmjoystick.c"
    "../../SDL2/src/joystick/windows/SDL_windowsjoystick.c"
    "../../SDL2/src/joystick/windows/SDL_xinputjoystick.c"
)
source_group("src\\joystick\\windows" FILES ${src__joystick__windows})

set(src__libm
    "../../SDL2/src/libm/e_atan2.c"
    "../../SDL2/src/libm/e_exp.c"
    "../../SDL2/src/libm/e_fmod.c"
    "../../SDL2/src/libm/e_log.c"
    "../../SDL2/src/libm/e_log10.c"
    "../../SDL2/src/libm/e_pow.c"
    "../../SDL2/src/libm/e_rem_pio2.c"
    "../../SDL2/src/libm/e_sqrt.c"
    "../../SDL2/src/libm/k_cos.c"
    "../../SDL2/src/libm/k_rem_pio2.c"
    "../../SDL2/src/libm/k_sin.c"
    "../../SDL2/src/libm/k_tan.c"
    "../../SDL2/src/libm/s_atan.c"
    "../../SDL2/src/libm/s_copysign.c"
    "../../SDL2/src/libm/s_cos.c"
    "../../SDL2/src/libm/s_fabs.c"
    "../../SDL2/src/libm/s_floor.c"
    "../../SDL2/src/libm/s_scalbn.c"
    "../../SDL2/src/libm/s_sin.c"
    "../../SDL2/src/libm/s_tan.c"
)
source_group("src\\libm" FILES ${src__libm})

set(src__loadso__windows
    "../../SDL2/src/loadso/windows/SDL_sysloadso.c"
)
source_group("src\\loadso\\windows" FILES ${src__loadso__windows})

set(src__power
    "../../SDL2/src/power/SDL_power.c"
)
source_group("src\\power" FILES ${src__power})

set(src__power__windows
    "../../SDL2/src/power/windows/SDL_syspower.c"
)
source_group("src\\power\\windows" FILES ${src__power__windows})

set(src__render
    "../../SDL2/src/render/SDL_d3dmath.c"
    "../../SDL2/src/render/SDL_render.c"
    "../../SDL2/src/render/SDL_yuv_sw.c"
)
source_group("src\\render" FILES ${src__render})

set(src__render__direct3d
    "../../SDL2/src/render/direct3d/SDL_render_d3d.c"
    "../../SDL2/src/render/direct3d/SDL_shaders_d3d.c"
)
source_group("src\\render\\direct3d" FILES ${src__render__direct3d})

set(src__render__opengl
    "../../SDL2/src/render/opengl/SDL_render_gl.c"
    "../../SDL2/src/render/opengl/SDL_shaders_gl.c"
)
source_group("src\\render\\opengl" FILES ${src__render__opengl})

set(src__render__opengles2
    "../../SDL2/src/render/opengles2/SDL_render_gles2.c"
    "../../SDL2/src/render/opengles2/SDL_shaders_gles2.c"
)
source_group("src\\render\\opengles2" FILES ${src__render__opengles2})

set(src__render__software
    "../../SDL2/src/render/software/SDL_blendfillrect.c"
    "../../SDL2/src/render/software/SDL_blendline.c"
    "../../SDL2/src/render/software/SDL_blendpoint.c"
    "../../SDL2/src/render/software/SDL_drawline.c"
    "../../SDL2/src/render/software/SDL_drawpoint.c"
    "../../SDL2/src/render/software/SDL_render_sw.c"
    "../../SDL2/src/render/software/SDL_rotate.c"
)
source_group("src\\render\\software" FILES ${src__render__software})

set(src__sensor
    "../../SDL2/src/sensor/SDL_sensor.c"
)
source_group("src\\sensor" FILES ${src__sensor})

set(src__sensor__dummy
    "../../SDL2/src/sensor/dummy/SDL_dummysensor.c"
)
source_group("src\\sensor\\dummy" FILES ${src__sensor__dummy})

set(src__stdlib
    "../../SDL2/src/stdlib/SDL_getenv.c"
    "../../SDL2/src/stdlib/SDL_iconv.c"
    "../../SDL2/src/stdlib/SDL_malloc.c"
    "../../SDL2/src/stdlib/SDL_qsort.c"
    "../../SDL2/src/stdlib/SDL_stdlib.c"
    "../../SDL2/src/stdlib/SDL_string.c"
    "../../SDL2/src/stdlib/SDL_strtokr.c"
)
source_group("src\\stdlib" FILES ${src__stdlib})

set(src__thread
    "../../SDL2/src/thread/SDL_thread.c"
)
source_group("src\\thread" FILES ${src__thread})

set(src__thread__generic
    "../../SDL2/src/thread/generic/SDL_syscond.c"
)
source_group("src\\thread\\generic" FILES ${src__thread__generic})

set(src__thread__windows
    "../../SDL2/src/thread/windows/SDL_sysmutex.c"
    "../../SDL2/src/thread/windows/SDL_syssem.c"
    "../../SDL2/src/thread/windows/SDL_systhread.c"
    "../../SDL2/src/thread/windows/SDL_systls.c"
)
source_group("src\\thread\\windows" FILES ${src__thread__windows})

set(src__timer
    "../../SDL2/src/timer/SDL_timer.c"
)
source_group("src\\timer" FILES ${src__timer})

set(src__timer__windows
    "../../SDL2/src/timer/windows/SDL_systimer.c"
)
source_group("src\\timer\\windows" FILES ${src__timer__windows})

set(src__video
    "../../SDL2/src/video/SDL_blit.c"
    "../../SDL2/src/video/SDL_blit_0.c"
    "../../SDL2/src/video/SDL_blit_1.c"
    "../../SDL2/src/video/SDL_blit_A.c"
    "../../SDL2/src/video/SDL_blit_auto.c"
    "../../SDL2/src/video/SDL_blit_copy.c"
    "../../SDL2/src/video/SDL_blit_N.c"
    "../../SDL2/src/video/SDL_blit_slow.c"
    "../../SDL2/src/video/SDL_bmp.c"
    "../../SDL2/src/video/SDL_clipboard.c"
    "../../SDL2/src/video/SDL_egl.c"
    "../../SDL2/src/video/SDL_fillrect.c"
    "../../SDL2/src/video/SDL_pixels.c"
    "../../SDL2/src/video/SDL_rect.c"
    "../../SDL2/src/video/SDL_RLEaccel.c"
    "../../SDL2/src/video/SDL_shape.c"
    "../../SDL2/src/video/SDL_stretch.c"
    "../../SDL2/src/video/SDL_surface.c"
    "../../SDL2/src/video/SDL_video.c"
    "../../SDL2/src/video/SDL_vulkan_utils.c"
    "../../SDL2/src/video/SDL_yuv.c"
)
source_group("src\\video" FILES ${src__video})

set(src__video__dummy
    "../../SDL2/src/video/dummy/SDL_nullevents.c"
    "../../SDL2/src/video/dummy/SDL_nullframebuffer.c"
    "../../SDL2/src/video/dummy/SDL_nullvideo.c"
)
source_group("src\\video\\dummy" FILES ${src__video__dummy})

set(src__video__windows
    "../../SDL2/src/video/windows/SDL_windowsclipboard.c"
    "../../SDL2/src/video/windows/SDL_windowsevents.c"
    "../../SDL2/src/video/windows/SDL_windowsframebuffer.c"
    "../../SDL2/src/video/windows/SDL_windowskeyboard.c"
    "../../SDL2/src/video/windows/SDL_windowsmessagebox.c"
    "../../SDL2/src/video/windows/SDL_windowsmodes.c"
    "../../SDL2/src/video/windows/SDL_windowsmouse.c"
    "../../SDL2/src/video/windows/SDL_windowsopengl.c"
    "../../SDL2/src/video/windows/SDL_windowsopengles.c"
    "../../SDL2/src/video/windows/SDL_windowsshape.c"
    "../../SDL2/src/video/windows/SDL_windowsvideo.c"
    "../../SDL2/src/video/windows/SDL_windowsvulkan.c"
    "../../SDL2/src/video/windows/SDL_windowswindow.c"
)
source_group("src\\video\\windows" FILES ${src__video__windows})

set(src__video__yuv2rgb
    "../../SDL2/src/video/yuv2rgb/yuv_rgb.c"
)
source_group("src\\video\\yuv2rgb" FILES ${src__video__yuv2rgb})

set(ALL_FILES
    ${include}
    ${src}
    ${src__atomic}
    ${src__audio}
    ${src__audio__directsound}
    ${src__audio__disk}
    ${src__audio__dummy}
    ${src__audio__wasapi}
    ${src__audio__winmm}
    ${src__core__windows}
    ${src__cpuinfo}
    ${src__dynapi}
    ${src__events}
    ${src__file}
    ${src__filesystem__windows}
    ${src__haptic}
    ${src__haptic__windows}
    ${src__hidapi__windows}
    ${src__joystick}
    ${src__joystick__hidapi}
    ${src__joystick__windows}
    ${src__libm}
    ${src__loadso__windows}
    ${src__power}
    ${src__power__windows}
    ${src__render}
    ${src__render__direct3d}
    ${src__render__opengl}
    ${src__render__opengles2}
    ${src__render__software}
    ${src__sensor}
    ${src__sensor__dummy}
    ${src__stdlib}
    ${src__thread}
    ${src__thread__generic}
    ${src__thread__windows}
    ${src__timer}
    ${src__timer__windows}
    ${src__video}
    ${src__video__dummy}
    ${src__video__windows}
    ${src__video__yuv2rgb}
)

################################################################################
# Target
################################################################################
add_library(${PROJECT_NAME} SHARED ${ALL_FILES})
set_target_properties(${PROJECT_NAME} PROPERTIES FOLDER "lib")

use_props(${PROJECT_NAME} "${CMAKE_CONFIGURATION_TYPES}" "${DEFAULT_CXX_PROPS}")
set(ROOT_NAMESPACE SDL2)

set_target_properties(${PROJECT_NAME} PROPERTIES
    VS_GLOBAL_KEYWORD "Win32Proj"
)
################################################################################
# Target name
################################################################################
if("${CMAKE_VS_PLATFORM_NAME}" STREQUAL "Win32")
    set_target_properties(${PROJECT_NAME} PROPERTIES
        TARGET_NAME_DEBUG   "SDL2"
        TARGET_NAME_RELEASE "SDL2"
    )
elseif("${CMAKE_VS_PLATFORM_NAME}" STREQUAL "x64")
    set_target_properties(${PROJECT_NAME} PROPERTIES
        TARGET_NAME_DEBUG   "SDL2"
        TARGET_NAME_RELEASE "SDL2"
    )
endif()
################################################################################
# Output directory
################################################################################
if("${CMAKE_VS_PLATFORM_NAME}" STREQUAL "Win32")
    set_target_properties(${PROJECT_NAME} PROPERTIES
        OUTPUT_DIRECTORY_DEBUG   "${CMAKE_CURRENT_SOURCE_DIR}/bin_x86_debug/"
        OUTPUT_DIRECTORY_RELEASE "${CMAKE_CURRENT_SOURCE_DIR}/bin_x86/"
    )
elseif("${CMAKE_VS_PLATFORM_NAME}" STREQUAL "x64")
    set_target_properties(${PROJECT_NAME} PROPERTIES
        OUTPUT_DIRECTORY_DEBUG   "${CMAKE_CURRENT_SOURCE_DIR}/bin_x64_debug/"
        OUTPUT_DIRECTORY_RELEASE "${CMAKE_CURRENT_SOURCE_DIR}/bin_x64/"
    )
endif()
if("${CMAKE_VS_PLATFORM_NAME}" STREQUAL "Win32")
    set_target_properties(${PROJECT_NAME} PROPERTIES
        ARCHIVE_OUTPUT_DIRECTORY_DEBUG   "${CMAKE_CURRENT_SOURCE_DIR}/bin_x86_debug"
        ARCHIVE_OUTPUT_DIRECTORY_RELEASE "${CMAKE_CURRENT_SOURCE_DIR}/bin_x86"
    )
elseif("${CMAKE_VS_PLATFORM_NAME}" STREQUAL "x64")
    set_target_properties(${PROJECT_NAME} PROPERTIES
        ARCHIVE_OUTPUT_DIRECTORY_DEBUG   "${CMAKE_CURRENT_SOURCE_DIR}/bin_x64_debug"
        ARCHIVE_OUTPUT_DIRECTORY_RELEASE "${CMAKE_CURRENT_SOURCE_DIR}/bin_x64"
    )
endif()
if("${CMAKE_VS_PLATFORM_NAME}" STREQUAL "Win32")
    set_target_properties(${PROJECT_NAME} PROPERTIES
        ARCHIVE_OUTPUT_NAME_DEBUG   "SDL2"
        ARCHIVE_OUTPUT_NAME_RELEASE "SDL2"
    )
elseif("${CMAKE_VS_PLATFORM_NAME}" STREQUAL "x64")
    set_target_properties(${PROJECT_NAME} PROPERTIES
        ARCHIVE_OUTPUT_NAME_DEBUG   "SDL2"
        ARCHIVE_OUTPUT_NAME_RELEASE "SDL2"
    )
endif()
################################################################################
# Include directories
################################################################################
if("${CMAKE_VS_PLATFORM_NAME}" STREQUAL "Win32")
    target_include_directories(${PROJECT_NAME} PUBLIC
        "${CMAKE_CURRENT_SOURCE_DIR}/../../SDL2/include;"
        "${CMAKE_CURRENT_SOURCE_DIR}/../../SDL2/src"
    )
elseif("${CMAKE_VS_PLATFORM_NAME}" STREQUAL "x64")
    target_include_directories(${PROJECT_NAME} PUBLIC
        "${CMAKE_CURRENT_SOURCE_DIR}/../../SDL2/include;"
        "${CMAKE_CURRENT_SOURCE_DIR}/../../SDL2/src"
    )
endif()

################################################################################
# Compile definitions
################################################################################
if("${CMAKE_VS_PLATFORM_NAME}" STREQUAL "Win32")
    target_compile_definitions(${PROJECT_NAME} PRIVATE
        "$<$<CONFIG:Debug>:"
            "_DEBUG"
        ">"
        "$<$<CONFIG:Release>:"
            "NDEBUG"
        ">"
        "_CRT_SECURE_NO_DEPRECATE;"
        "_MBCS"
    )
elseif("${CMAKE_VS_PLATFORM_NAME}" STREQUAL "x64")
    target_compile_definitions(${PROJECT_NAME} PRIVATE
        "$<$<CONFIG:Debug>:"
            "_DEBUG"
        ">"
        "$<$<CONFIG:Release>:"
            "NDEBUG"
        ">"
        "_CRT_SECURE_NO_DEPRECATE;"
        "_WIN64;"
        "__WIN64__;"
        "_MBCS"
    )
endif()

################################################################################
# Compile and link options
################################################################################
if(MSVC)
    if("${CMAKE_VS_PLATFORM_NAME}" STREQUAL "Win32")
        target_compile_options(${PROJECT_NAME} PRIVATE
            $<$<CONFIG:Debug>:
                /Od;
                ${DEFAULT_CXX_DEBUG_RUNTIME_LIBRARY};
                /ZI
            >
            $<$<CONFIG:Release>:
                /Gm-;
                /Ox;
                /Oi;
                /GF;
                ${DEFAULT_CXX_RUNTIME_LIBRARY};
                /Gy;
                ${DEFAULT_CXX_DEBUG_INFORMATION_FORMAT}
            >
            /W3;
            ${DEFAULT_CXX_EXCEPTION_HANDLING};
            /Y-
        )
    elseif("${CMAKE_VS_PLATFORM_NAME}" STREQUAL "x64")
        target_compile_options(${PROJECT_NAME} PRIVATE
            $<$<CONFIG:Debug>:
                /Od;
                ${DEFAULT_CXX_DEBUG_RUNTIME_LIBRARY};
                /ZI
            >
            $<$<CONFIG:Release>:
                /Gm-;
                /Ox;
                /Oi;
                /GF;
                ${DEFAULT_CXX_RUNTIME_LIBRARY};
                /Gy;
                ${DEFAULT_CXX_DEBUG_INFORMATION_FORMAT}
            >
            /W3;
            ${DEFAULT_CXX_EXCEPTION_HANDLING};
            /Y-
        )
    endif()
    if("${CMAKE_VS_PLATFORM_NAME}" STREQUAL "Win32")
        target_link_options(${PROJECT_NAME} PRIVATE
            $<$<CONFIG:Debug>:
                /DEBUG;
                /INCREMENTAL
            >
            $<$<CONFIG:Release>:
                /DEBUG:FULL;
                /OPT:REF;
                /OPT:ICF;
                /INCREMENTAL:NO
            >
            /SUBSYSTEM:WINDOWS
        )
    elseif("${CMAKE_VS_PLATFORM_NAME}" STREQUAL "x64")
        target_link_options(${PROJECT_NAME} PRIVATE
            $<$<CONFIG:Debug>:
                /DEBUG;
                /INCREMENTAL
            >
            $<$<CONFIG:Release>:
                /DEBUG:FULL;
                /OPT:REF;
                /OPT:ICF;
                /INCREMENTAL:NO
            >
            /SUBSYSTEM:WINDOWS
        )
    endif()
endif()

################################################################################
# Dependencies
################################################################################
if("${CMAKE_VS_PLATFORM_NAME}" STREQUAL "Win32")
    set(ADDITIONAL_LIBRARY_DEPENDENCIES
        "$<$<CONFIG:Debug>:"
            "ucrtd;"
            "vcruntimed"
        ">"
        "$<$<CONFIG:Release>:"
            "ucrt"
        ">"
        "imm32;"
        "setupapi;"
        "version;"
        "winmm"
    )
elseif("${CMAKE_VS_PLATFORM_NAME}" STREQUAL "x64")
    set(ADDITIONAL_LIBRARY_DEPENDENCIES
        "$<$<CONFIG:Debug>:"
            "ucrtd;"
            "vcruntimed"
        ">"
        "$<$<CONFIG:Release>:"
            "ucrt"
        ">"
        "imm32;"
        "setupapi;"
        "version;"
        "winmm"
    )
endif()
target_link_libraries(${PROJECT_NAME} PUBLIC "${ADDITIONAL_LIBRARY_DEPENDENCIES}")



























project(SDL2main C)

################################################################################
# Source groups
################################################################################
set(Sources
    "../../SDL2/src/main/windows/SDL_windows_main.c"
)
source_group("Sources" FILES ${Sources})

set(ALL_FILES
    ${Sources}
)

################################################################################
# Target
################################################################################
add_library(${PROJECT_NAME} STATIC ${ALL_FILES})
set_target_properties(${PROJECT_NAME} PROPERTIES FOLDER "lib")

use_props(${PROJECT_NAME} "${CMAKE_CONFIGURATION_TYPES}" "${DEFAULT_CXX_PROPS}")
set(ROOT_NAMESPACE SDL2main)

set_target_properties(${PROJECT_NAME} PROPERTIES
    VS_GLOBAL_KEYWORD "Win32Proj"
)
################################################################################
# Target name
################################################################################
if("${CMAKE_VS_PLATFORM_NAME}" STREQUAL "Win32")
    set_target_properties(${PROJECT_NAME} PROPERTIES
        TARGET_NAME_DEBUG   "SDL2main"
        TARGET_NAME_RELEASE "SDL2main"
    )
elseif("${CMAKE_VS_PLATFORM_NAME}" STREQUAL "x64")
    set_target_properties(${PROJECT_NAME} PROPERTIES
        TARGET_NAME_DEBUG   "SDL2main"
        TARGET_NAME_RELEASE "SDL2main"
    )
endif()
################################################################################
# Output directory
################################################################################
if("${CMAKE_VS_PLATFORM_NAME}" STREQUAL "Win32")
    set_target_properties(${PROJECT_NAME} PROPERTIES
        OUTPUT_DIRECTORY_DEBUG   "${CMAKE_CURRENT_SOURCE_DIR}/bin_x86_debug/"
        OUTPUT_DIRECTORY_RELEASE "${CMAKE_CURRENT_SOURCE_DIR}/bin_x86/"
    )
elseif("${CMAKE_VS_PLATFORM_NAME}" STREQUAL "x64")
    set_target_properties(${PROJECT_NAME} PROPERTIES
        OUTPUT_DIRECTORY_DEBUG   "${CMAKE_CURRENT_SOURCE_DIR}/bin_x64_debug/"
        OUTPUT_DIRECTORY_RELEASE "${CMAKE_CURRENT_SOURCE_DIR}/bin_x64/"
    )
endif()
################################################################################
# Include directories
################################################################################
if("${CMAKE_VS_PLATFORM_NAME}" STREQUAL "Win32")
    target_include_directories(${PROJECT_NAME} PUBLIC
        "${CMAKE_CURRENT_SOURCE_DIR}/../../SDL2/include"
    )
elseif("${CMAKE_VS_PLATFORM_NAME}" STREQUAL "x64")
    target_include_directories(${PROJECT_NAME} PUBLIC
        "${CMAKE_CURRENT_SOURCE_DIR}/../../SDL2/include"
    )
endif()

################################################################################
# Compile definitions
################################################################################
if("${CMAKE_VS_PLATFORM_NAME}" STREQUAL "Win32")
    target_compile_definitions(${PROJECT_NAME} PRIVATE
        "$<$<CONFIG:Debug>:"
            "_DEBUG"
        ">"
        "$<$<CONFIG:Release>:"
            "NDEBUG"
        ">"
        "_CRT_SECURE_NO_DEPRECATE;"
        "_MBCS"
    )
elseif("${CMAKE_VS_PLATFORM_NAME}" STREQUAL "x64")
    target_compile_definitions(${PROJECT_NAME} PRIVATE
        "$<$<CONFIG:Debug>:"
            "_DEBUG"
        ">"
        "$<$<CONFIG:Release>:"
            "NDEBUG"
        ">"
        "_CRT_SECURE_NO_DEPRECATE;"
        "_WIN64;"
        "__WIN64__;"
        "_MBCS"
    )
endif()

################################################################################
# Compile and link options
################################################################################
if(MSVC)
    if("${CMAKE_VS_PLATFORM_NAME}" STREQUAL "Win32")
        target_compile_options(${PROJECT_NAME} PRIVATE
            $<$<CONFIG:Debug>:
                /Od;
                ${DEFAULT_CXX_DEBUG_RUNTIME_LIBRARY};
                /ZI
            >
            $<$<CONFIG:Release>:
                /Gm-;
                /Ox;
                /Oi;
                /GF;
                ${DEFAULT_CXX_RUNTIME_LIBRARY};
                /Gy;
                ${DEFAULT_CXX_DEBUG_INFORMATION_FORMAT}
            >
            /W3;
            ${DEFAULT_CXX_EXCEPTION_HANDLING};
            /Y-
        )
    elseif("${CMAKE_VS_PLATFORM_NAME}" STREQUAL "x64")
        target_compile_options(${PROJECT_NAME} PRIVATE
            $<$<CONFIG:Debug>:
                /Od;
                ${DEFAULT_CXX_DEBUG_RUNTIME_LIBRARY};
                /ZI
            >
            $<$<CONFIG:Release>:
                /Gm-;
                /Ox;
                /Oi;
                /GF;
                ${DEFAULT_CXX_RUNTIME_LIBRARY};
                /Gy;
                ${DEFAULT_CXX_DEBUG_INFORMATION_FORMAT}
            >
            /W3;
            ${DEFAULT_CXX_EXCEPTION_HANDLING};
            /Y-
        )
    endif()
    if("${CMAKE_VS_PLATFORM_NAME}" STREQUAL "Win32")
        target_link_options(${PROJECT_NAME} PRIVATE
            $<$<CONFIG:Release>:
                /OPT:REF;
                /OPT:ICF
            >
            /SUBSYSTEM:WINDOWS
        )
    elseif("${CMAKE_VS_PLATFORM_NAME}" STREQUAL "x64")
        target_link_options(${PROJECT_NAME} PRIVATE
            $<$<CONFIG:Release>:
                /OPT:REF;
                /OPT:ICF
            >
            /SUBSYSTEM:WINDOWS
        )
    endif()
endif()



























project(ogg C)

################################################################################
# Source groups
################################################################################
set(Sources
    "../../../ioq3/code/libogg-1.3.3/src/bitwise.c"
    "../../../ioq3/code/libogg-1.3.3/src/framing.c"
)
source_group("Sources" FILES ${Sources})

set(ALL_FILES
    ${Sources}
)

################################################################################
# Target
################################################################################
add_library(${PROJECT_NAME} STATIC ${ALL_FILES})
set_target_properties(${PROJECT_NAME} PROPERTIES FOLDER "lib")

use_props(${PROJECT_NAME} "${CMAKE_CONFIGURATION_TYPES}" "${DEFAULT_CXX_PROPS}")
set(ROOT_NAMESPACE ogg)

set_target_properties(${PROJECT_NAME} PROPERTIES
    VS_GLOBAL_KEYWORD "Win32Proj"
)
################################################################################
# Target name
################################################################################
if("${CMAKE_VS_PLATFORM_NAME}" STREQUAL "Win32")
    set_target_properties(${PROJECT_NAME} PROPERTIES
        TARGET_NAME_DEBUG   "ogg"
        TARGET_NAME_RELEASE "ogg"
    )
elseif("${CMAKE_VS_PLATFORM_NAME}" STREQUAL "x64")
    set_target_properties(${PROJECT_NAME} PROPERTIES
        TARGET_NAME_DEBUG   "ogg"
        TARGET_NAME_RELEASE "ogg"
    )
endif()
################################################################################
# Output directory
################################################################################
if("${CMAKE_VS_PLATFORM_NAME}" STREQUAL "Win32")
    set_target_properties(${PROJECT_NAME} PROPERTIES
        OUTPUT_DIRECTORY_DEBUG   "${CMAKE_CURRENT_SOURCE_DIR}/bin_x86_debug/"
        OUTPUT_DIRECTORY_RELEASE "${CMAKE_CURRENT_SOURCE_DIR}/bin_x86/"
    )
elseif("${CMAKE_VS_PLATFORM_NAME}" STREQUAL "x64")
    set_target_properties(${PROJECT_NAME} PROPERTIES
        OUTPUT_DIRECTORY_DEBUG   "${CMAKE_CURRENT_SOURCE_DIR}/bin_x64_debug/"
        OUTPUT_DIRECTORY_RELEASE "${CMAKE_CURRENT_SOURCE_DIR}/bin_x64/"
    )
endif()
################################################################################
# Include directories
################################################################################
if("${CMAKE_VS_PLATFORM_NAME}" STREQUAL "Win32")
    target_include_directories(${PROJECT_NAME} PUBLIC
        "${CMAKE_CURRENT_SOURCE_DIR}/../../../ioq3/code/libogg-1.3.3/include"
    )
elseif("${CMAKE_VS_PLATFORM_NAME}" STREQUAL "x64")
    target_include_directories(${PROJECT_NAME} PUBLIC
        "${CMAKE_CURRENT_SOURCE_DIR}/../../../ioq3/code/libogg-1.3.3/include"
    )
endif()

################################################################################
# Compile definitions
################################################################################
if("${CMAKE_VS_PLATFORM_NAME}" STREQUAL "Win32")
    target_compile_definitions(${PROJECT_NAME} PRIVATE
        "$<$<CONFIG:Debug>:"
            "_DEBUG"
        ">"
        "$<$<CONFIG:Release>:"
            "NDEBUG"
        ">"
        "_CRT_SECURE_NO_DEPRECATE;"
        "_MBCS"
    )
elseif("${CMAKE_VS_PLATFORM_NAME}" STREQUAL "x64")
    target_compile_definitions(${PROJECT_NAME} PRIVATE
        "$<$<CONFIG:Debug>:"
            "_DEBUG"
        ">"
        "$<$<CONFIG:Release>:"
            "NDEBUG"
        ">"
        "_CRT_SECURE_NO_DEPRECATE;"
        "_WIN64;"
        "__WIN64__;"
        "_MBCS"
    )
endif()

################################################################################
# Compile and link options
################################################################################
if(MSVC)
    if("${CMAKE_VS_PLATFORM_NAME}" STREQUAL "Win32")
        target_compile_options(${PROJECT_NAME} PRIVATE
            $<$<CONFIG:Debug>:
                /Od;
                ${DEFAULT_CXX_DEBUG_RUNTIME_LIBRARY};
                /ZI
            >
            $<$<CONFIG:Release>:
                /Gm-;
                /Ox;
                /Oi;
                /GF;
                ${DEFAULT_CXX_RUNTIME_LIBRARY};
                /Gy;
                ${DEFAULT_CXX_DEBUG_INFORMATION_FORMAT}
            >
            /W3;
            ${DEFAULT_CXX_EXCEPTION_HANDLING};
            /Y-
        )
    elseif("${CMAKE_VS_PLATFORM_NAME}" STREQUAL "x64")
        target_compile_options(${PROJECT_NAME} PRIVATE
            $<$<CONFIG:Debug>:
                /Od;
                ${DEFAULT_CXX_DEBUG_RUNTIME_LIBRARY};
                /ZI
            >
            $<$<CONFIG:Release>:
                /Gm-;
                /Ox;
                /Oi;
                /GF;
                ${DEFAULT_CXX_RUNTIME_LIBRARY};
                /Gy;
                ${DEFAULT_CXX_DEBUG_INFORMATION_FORMAT}
            >
            /W3;
            ${DEFAULT_CXX_EXCEPTION_HANDLING};
            /Y-
        )
    endif()
    if("${CMAKE_VS_PLATFORM_NAME}" STREQUAL "Win32")
        target_link_options(${PROJECT_NAME} PRIVATE
            $<$<CONFIG:Release>:
                /OPT:REF;
                /OPT:ICF
            >
            /SUBSYSTEM:WINDOWS
        )
    elseif("${CMAKE_VS_PLATFORM_NAME}" STREQUAL "x64")
        target_link_options(${PROJECT_NAME} PRIVATE
            $<$<CONFIG:Release>:
                /OPT:REF;
                /OPT:ICF
            >
            /SUBSYSTEM:WINDOWS
        )
    endif()
endif()



























project(opus C)

################################################################################
# Source groups
################################################################################
set(opus-1.2.1__celt
    "../../../ioq3/code/opus-1.2.1/celt/bands.c"
    "../../../ioq3/code/opus-1.2.1/celt/celt.c"
    "../../../ioq3/code/opus-1.2.1/celt/celt_decoder.c"
    "../../../ioq3/code/opus-1.2.1/celt/celt_encoder.c"
    "../../../ioq3/code/opus-1.2.1/celt/celt_lpc.c"
    "../../../ioq3/code/opus-1.2.1/celt/cwrs.c"
    "../../../ioq3/code/opus-1.2.1/celt/entcode.c"
    "../../../ioq3/code/opus-1.2.1/celt/entdec.c"
    "../../../ioq3/code/opus-1.2.1/celt/entenc.c"
    "../../../ioq3/code/opus-1.2.1/celt/kiss_fft.c"
    "../../../ioq3/code/opus-1.2.1/celt/laplace.c"
    "../../../ioq3/code/opus-1.2.1/celt/mathops.c"
    "../../../ioq3/code/opus-1.2.1/celt/mdct.c"
    "../../../ioq3/code/opus-1.2.1/celt/modes.c"
    "../../../ioq3/code/opus-1.2.1/celt/opus_custom_demo.c"
    "../../../ioq3/code/opus-1.2.1/celt/pitch.c"
    "../../../ioq3/code/opus-1.2.1/celt/quant_bands.c"
    "../../../ioq3/code/opus-1.2.1/celt/rate.c"
    "../../../ioq3/code/opus-1.2.1/celt/vq.c"
)
source_group("opus-1.2.1\\celt" FILES ${opus-1.2.1__celt})

set(opus-1.2.1__silk
    "../../../ioq3/code/opus-1.2.1/silk/A2NLSF.c"
    "../../../ioq3/code/opus-1.2.1/silk/ana_filt_bank_1.c"
    "../../../ioq3/code/opus-1.2.1/silk/biquad_alt.c"
    "../../../ioq3/code/opus-1.2.1/silk/bwexpander.c"
    "../../../ioq3/code/opus-1.2.1/silk/bwexpander_32.c"
    "../../../ioq3/code/opus-1.2.1/silk/check_control_input.c"
    "../../../ioq3/code/opus-1.2.1/silk/CNG.c"
    "../../../ioq3/code/opus-1.2.1/silk/code_signs.c"
    "../../../ioq3/code/opus-1.2.1/silk/control_audio_bandwidth.c"
    "../../../ioq3/code/opus-1.2.1/silk/control_codec.c"
    "../../../ioq3/code/opus-1.2.1/silk/control_SNR.c"
    "../../../ioq3/code/opus-1.2.1/silk/debug.c"
    "../../../ioq3/code/opus-1.2.1/silk/dec_API.c"
    "../../../ioq3/code/opus-1.2.1/silk/decode_core.c"
    "../../../ioq3/code/opus-1.2.1/silk/decode_frame.c"
    "../../../ioq3/code/opus-1.2.1/silk/decode_indices.c"
    "../../../ioq3/code/opus-1.2.1/silk/decode_parameters.c"
    "../../../ioq3/code/opus-1.2.1/silk/decode_pitch.c"
    "../../../ioq3/code/opus-1.2.1/silk/decode_pulses.c"
    "../../../ioq3/code/opus-1.2.1/silk/decoder_set_fs.c"
    "../../../ioq3/code/opus-1.2.1/silk/enc_API.c"
    "../../../ioq3/code/opus-1.2.1/silk/encode_indices.c"
    "../../../ioq3/code/opus-1.2.1/silk/encode_pulses.c"
    "../../../ioq3/code/opus-1.2.1/silk/gain_quant.c"
    "../../../ioq3/code/opus-1.2.1/silk/HP_variable_cutoff.c"
    "../../../ioq3/code/opus-1.2.1/silk/init_decoder.c"
    "../../../ioq3/code/opus-1.2.1/silk/init_encoder.c"
    "../../../ioq3/code/opus-1.2.1/silk/inner_prod_aligned.c"
    "../../../ioq3/code/opus-1.2.1/silk/interpolate.c"
    "../../../ioq3/code/opus-1.2.1/silk/lin2log.c"
    "../../../ioq3/code/opus-1.2.1/silk/log2lin.c"
    "../../../ioq3/code/opus-1.2.1/silk/LP_variable_cutoff.c"
    "../../../ioq3/code/opus-1.2.1/silk/LPC_analysis_filter.c"
    "../../../ioq3/code/opus-1.2.1/silk/LPC_fit.c"
    "../../../ioq3/code/opus-1.2.1/silk/LPC_inv_pred_gain.c"
    "../../../ioq3/code/opus-1.2.1/silk/NLSF2A.c"
    "../../../ioq3/code/opus-1.2.1/silk/NLSF_decode.c"
    "../../../ioq3/code/opus-1.2.1/silk/NLSF_del_dec_quant.c"
    "../../../ioq3/code/opus-1.2.1/silk/NLSF_encode.c"
    "../../../ioq3/code/opus-1.2.1/silk/NLSF_stabilize.c"
    "../../../ioq3/code/opus-1.2.1/silk/NLSF_unpack.c"
    "../../../ioq3/code/opus-1.2.1/silk/NLSF_VQ.c"
    "../../../ioq3/code/opus-1.2.1/silk/NLSF_VQ_weights_laroia.c"
    "../../../ioq3/code/opus-1.2.1/silk/NSQ.c"
    "../../../ioq3/code/opus-1.2.1/silk/NSQ_del_dec.c"
    "../../../ioq3/code/opus-1.2.1/silk/pitch_est_tables.c"
    "../../../ioq3/code/opus-1.2.1/silk/PLC.c"
    "../../../ioq3/code/opus-1.2.1/silk/process_NLSFs.c"
    "../../../ioq3/code/opus-1.2.1/silk/quant_LTP_gains.c"
    "../../../ioq3/code/opus-1.2.1/silk/resampler.c"
    "../../../ioq3/code/opus-1.2.1/silk/resampler_down2.c"
    "../../../ioq3/code/opus-1.2.1/silk/resampler_down2_3.c"
    "../../../ioq3/code/opus-1.2.1/silk/resampler_private_AR2.c"
    "../../../ioq3/code/opus-1.2.1/silk/resampler_private_down_FIR.c"
    "../../../ioq3/code/opus-1.2.1/silk/resampler_private_IIR_FIR.c"
    "../../../ioq3/code/opus-1.2.1/silk/resampler_private_up2_HQ.c"
    "../../../ioq3/code/opus-1.2.1/silk/resampler_rom.c"
    "../../../ioq3/code/opus-1.2.1/silk/shell_coder.c"
    "../../../ioq3/code/opus-1.2.1/silk/sigm_Q15.c"
    "../../../ioq3/code/opus-1.2.1/silk/sort.c"
    "../../../ioq3/code/opus-1.2.1/silk/stereo_decode_pred.c"
    "../../../ioq3/code/opus-1.2.1/silk/stereo_encode_pred.c"
    "../../../ioq3/code/opus-1.2.1/silk/stereo_find_predictor.c"
    "../../../ioq3/code/opus-1.2.1/silk/stereo_LR_to_MS.c"
    "../../../ioq3/code/opus-1.2.1/silk/stereo_MS_to_LR.c"
    "../../../ioq3/code/opus-1.2.1/silk/stereo_quant_pred.c"
    "../../../ioq3/code/opus-1.2.1/silk/sum_sqr_shift.c"
    "../../../ioq3/code/opus-1.2.1/silk/table_LSF_cos.c"
    "../../../ioq3/code/opus-1.2.1/silk/tables_gain.c"
    "../../../ioq3/code/opus-1.2.1/silk/tables_LTP.c"
    "../../../ioq3/code/opus-1.2.1/silk/tables_NLSF_CB_NB_MB.c"
    "../../../ioq3/code/opus-1.2.1/silk/tables_NLSF_CB_WB.c"
    "../../../ioq3/code/opus-1.2.1/silk/tables_other.c"
    "../../../ioq3/code/opus-1.2.1/silk/tables_pitch_lag.c"
    "../../../ioq3/code/opus-1.2.1/silk/tables_pulses_per_block.c"
    "../../../ioq3/code/opus-1.2.1/silk/VAD.c"
    "../../../ioq3/code/opus-1.2.1/silk/VQ_WMat_EC.c"
)
source_group("opus-1.2.1\\silk" FILES ${opus-1.2.1__silk})

set(opus-1.2.1__silk__float
    "../../../ioq3/code/opus-1.2.1/silk/float/apply_sine_window_FLP.c"
    "../../../ioq3/code/opus-1.2.1/silk/float/autocorrelation_FLP.c"
    "../../../ioq3/code/opus-1.2.1/silk/float/burg_modified_FLP.c"
    "../../../ioq3/code/opus-1.2.1/silk/float/bwexpander_FLP.c"
    "../../../ioq3/code/opus-1.2.1/silk/float/corrMatrix_FLP.c"
    "../../../ioq3/code/opus-1.2.1/silk/float/encode_frame_FLP.c"
    "../../../ioq3/code/opus-1.2.1/silk/float/energy_FLP.c"
    "../../../ioq3/code/opus-1.2.1/silk/float/find_LPC_FLP.c"
    "../../../ioq3/code/opus-1.2.1/silk/float/find_LTP_FLP.c"
    "../../../ioq3/code/opus-1.2.1/silk/float/find_pitch_lags_FLP.c"
    "../../../ioq3/code/opus-1.2.1/silk/float/find_pred_coefs_FLP.c"
    "../../../ioq3/code/opus-1.2.1/silk/float/inner_product_FLP.c"
    "../../../ioq3/code/opus-1.2.1/silk/float/k2a_FLP.c"
    "../../../ioq3/code/opus-1.2.1/silk/float/LPC_analysis_filter_FLP.c"
    "../../../ioq3/code/opus-1.2.1/silk/float/LPC_inv_pred_gain_FLP.c"
    "../../../ioq3/code/opus-1.2.1/silk/float/LTP_analysis_filter_FLP.c"
    "../../../ioq3/code/opus-1.2.1/silk/float/LTP_scale_ctrl_FLP.c"
    "../../../ioq3/code/opus-1.2.1/silk/float/noise_shape_analysis_FLP.c"
    "../../../ioq3/code/opus-1.2.1/silk/float/pitch_analysis_core_FLP.c"
    "../../../ioq3/code/opus-1.2.1/silk/float/process_gains_FLP.c"
    "../../../ioq3/code/opus-1.2.1/silk/float/regularize_correlations_FLP.c"
    "../../../ioq3/code/opus-1.2.1/silk/float/residual_energy_FLP.c"
    "../../../ioq3/code/opus-1.2.1/silk/float/scale_copy_vector_FLP.c"
    "../../../ioq3/code/opus-1.2.1/silk/float/scale_vector_FLP.c"
    "../../../ioq3/code/opus-1.2.1/silk/float/schur_FLP.c"
    "../../../ioq3/code/opus-1.2.1/silk/float/sort_FLP.c"
    "../../../ioq3/code/opus-1.2.1/silk/float/warped_autocorrelation_FLP.c"
    "../../../ioq3/code/opus-1.2.1/silk/float/wrappers_FLP.c"
)
source_group("opus-1.2.1\\silk\\float" FILES ${opus-1.2.1__silk__float})

set(opus-1.2.1__src
    "../../../ioq3/code/opus-1.2.1/src/analysis.c"
    "../../../ioq3/code/opus-1.2.1/src/mlp.c"
    "../../../ioq3/code/opus-1.2.1/src/mlp_data.c"
    "../../../ioq3/code/opus-1.2.1/src/opus.c"
    "../../../ioq3/code/opus-1.2.1/src/opus_decoder.c"
    "../../../ioq3/code/opus-1.2.1/src/opus_encoder.c"
    "../../../ioq3/code/opus-1.2.1/src/opus_multistream.c"
    "../../../ioq3/code/opus-1.2.1/src/opus_multistream_decoder.c"
    "../../../ioq3/code/opus-1.2.1/src/opus_multistream_encoder.c"
    "../../../ioq3/code/opus-1.2.1/src/repacketizer.c"
)
source_group("opus-1.2.1\\src" FILES ${opus-1.2.1__src})

set(opusfile-0.9__src
    "../../../ioq3/code/opusfile-0.9/src/http.c"
    "../../../ioq3/code/opusfile-0.9/src/info.c"
    "../../../ioq3/code/opusfile-0.9/src/internal.c"
    "../../../ioq3/code/opusfile-0.9/src/opusfile.c"
    "../../../ioq3/code/opusfile-0.9/src/stream.c"
    "../../../ioq3/code/opusfile-0.9/src/wincerts.c"
)
source_group("opusfile-0.9\\src" FILES ${opusfile-0.9__src})

set(ALL_FILES
    ${opus-1.2.1__celt}
    ${opus-1.2.1__silk}
    ${opus-1.2.1__silk__float}
    ${opus-1.2.1__src}
    ${opusfile-0.9__src}
)

################################################################################
# Target
################################################################################
add_library(${PROJECT_NAME} STATIC ${ALL_FILES})
set_target_properties(${PROJECT_NAME} PROPERTIES FOLDER "lib")

use_props(${PROJECT_NAME} "${CMAKE_CONFIGURATION_TYPES}" "${DEFAULT_CXX_PROPS}")
set(ROOT_NAMESPACE opus)

set_target_properties(${PROJECT_NAME} PROPERTIES
    VS_GLOBAL_KEYWORD "Win32Proj"
)
################################################################################
# Target name
################################################################################
if("${CMAKE_VS_PLATFORM_NAME}" STREQUAL "Win32")
    set_target_properties(${PROJECT_NAME} PROPERTIES
        TARGET_NAME_DEBUG   "opus"
        TARGET_NAME_RELEASE "opus"
    )
elseif("${CMAKE_VS_PLATFORM_NAME}" STREQUAL "x64")
    set_target_properties(${PROJECT_NAME} PROPERTIES
        TARGET_NAME_DEBUG   "opus"
        TARGET_NAME_RELEASE "opus"
    )
endif()
################################################################################
# Output directory
################################################################################
if("${CMAKE_VS_PLATFORM_NAME}" STREQUAL "Win32")
    set_target_properties(${PROJECT_NAME} PROPERTIES
        OUTPUT_DIRECTORY_DEBUG   "${CMAKE_CURRENT_SOURCE_DIR}/bin_x86_debug/"
        OUTPUT_DIRECTORY_RELEASE "${CMAKE_CURRENT_SOURCE_DIR}/bin_x86/"
    )
elseif("${CMAKE_VS_PLATFORM_NAME}" STREQUAL "x64")
    set_target_properties(${PROJECT_NAME} PROPERTIES
        OUTPUT_DIRECTORY_DEBUG   "${CMAKE_CURRENT_SOURCE_DIR}/bin_x64_debug/"
        OUTPUT_DIRECTORY_RELEASE "${CMAKE_CURRENT_SOURCE_DIR}/bin_x64/"
    )
endif()
################################################################################
# Include directories
################################################################################
if("${CMAKE_VS_PLATFORM_NAME}" STREQUAL "Win32")
    target_include_directories(${PROJECT_NAME} PUBLIC
        "${CMAKE_CURRENT_SOURCE_DIR}/../../../ioq3/code/libogg-1.3.3/include;"
        "${CMAKE_CURRENT_SOURCE_DIR}/../../../ioq3/code/opus-1.2.1/include;"
        "${CMAKE_CURRENT_SOURCE_DIR}/../../../ioq3/code/opus-1.2.1/celt;"
        "${CMAKE_CURRENT_SOURCE_DIR}/../../../ioq3/code/opus-1.2.1/silk;"
        "${CMAKE_CURRENT_SOURCE_DIR}/../../../ioq3/code/opus-1.2.1/silk/float;"
        "${CMAKE_CURRENT_SOURCE_DIR}/../../../ioq3/code/opusfile-0.9/include"
    )
elseif("${CMAKE_VS_PLATFORM_NAME}" STREQUAL "x64")
    target_include_directories(${PROJECT_NAME} PUBLIC
        "${CMAKE_CURRENT_SOURCE_DIR}/../../../ioq3/code/libogg-1.3.3/include;"
        "${CMAKE_CURRENT_SOURCE_DIR}/../../../ioq3/code/opus-1.2.1/include;"
        "${CMAKE_CURRENT_SOURCE_DIR}/../../../ioq3/code/opus-1.2.1/celt;"
        "${CMAKE_CURRENT_SOURCE_DIR}/../../../ioq3/code/opus-1.2.1/silk;"
        "${CMAKE_CURRENT_SOURCE_DIR}/../../../ioq3/code/opus-1.2.1/silk/float;"
        "${CMAKE_CURRENT_SOURCE_DIR}/../../../ioq3/code/opusfile-0.9/include"
    )
endif()

################################################################################
# Compile definitions
################################################################################
if("${CMAKE_VS_PLATFORM_NAME}" STREQUAL "Win32")
    target_compile_definitions(${PROJECT_NAME} PRIVATE
        "$<$<CONFIG:Debug>:"
            "_DEBUG"
        ">"
        "$<$<CONFIG:Release>:"
            "NDEBUG"
        ">"
        "_CRT_SECURE_NO_DEPRECATE;"
        "OPUS_BUILD;"
        "HAVE_LRINTF;"
        "FLOATING_POINT;"
        "USE_ALLOCA;"
        "_MBCS"
    )
elseif("${CMAKE_VS_PLATFORM_NAME}" STREQUAL "x64")
    target_compile_definitions(${PROJECT_NAME} PRIVATE
        "$<$<CONFIG:Debug>:"
            "_DEBUG"
        ">"
        "$<$<CONFIG:Release>:"
            "NDEBUG"
        ">"
        "_CRT_SECURE_NO_DEPRECATE;"
        "_WIN64;"
        "__WIN64__;"
        "OPUS_BUILD;"
        "HAVE_LRINTF;"
        "FLOATING_POINT;"
        "USE_ALLOCA;"
        "_MBCS"
    )
endif()

################################################################################
# Compile and link options
################################################################################
if(MSVC)
    if("${CMAKE_VS_PLATFORM_NAME}" STREQUAL "Win32")
        target_compile_options(${PROJECT_NAME} PRIVATE
            $<$<CONFIG:Debug>:
                /Od;
                ${DEFAULT_CXX_DEBUG_RUNTIME_LIBRARY};
                /ZI
            >
            $<$<CONFIG:Release>:
                /Gm-;
                /Ox;
                /Oi;
                /GF;
                ${DEFAULT_CXX_RUNTIME_LIBRARY};
                /Gy;
                ${DEFAULT_CXX_DEBUG_INFORMATION_FORMAT}
            >
            /W3;
            /wd"4244";
            ${DEFAULT_CXX_EXCEPTION_HANDLING};
            /Y-
        )
    elseif("${CMAKE_VS_PLATFORM_NAME}" STREQUAL "x64")
        target_compile_options(${PROJECT_NAME} PRIVATE
            $<$<CONFIG:Debug>:
                /Od;
                ${DEFAULT_CXX_DEBUG_RUNTIME_LIBRARY};
                /ZI
            >
            $<$<CONFIG:Release>:
                /Gm-;
                /Ox;
                /Oi;
                /GF;
                ${DEFAULT_CXX_RUNTIME_LIBRARY};
                /Gy;
                ${DEFAULT_CXX_DEBUG_INFORMATION_FORMAT}
            >
            /W3;
            /wd"4244";
            ${DEFAULT_CXX_EXCEPTION_HANDLING};
            /Y-
        )
    endif()
    if("${CMAKE_VS_PLATFORM_NAME}" STREQUAL "Win32")
        target_link_options(${PROJECT_NAME} PRIVATE
            $<$<CONFIG:Release>:
                /OPT:REF;
                /OPT:ICF
            >
            /SUBSYSTEM:WINDOWS
        )
    elseif("${CMAKE_VS_PLATFORM_NAME}" STREQUAL "x64")
        target_link_options(${PROJECT_NAME} PRIVATE
            $<$<CONFIG:Release>:
                /OPT:REF;
                /OPT:ICF
            >
            /SUBSYSTEM:WINDOWS
        )
    endif()
endif()



























project(vorbis C)

################################################################################
# Source groups
################################################################################
set(Sources
    "../../../ioq3/code/libvorbis-1.3.6/lib/analysis.c"
    "../../../ioq3/code/libvorbis-1.3.6/lib/bitrate.c"
    "../../../ioq3/code/libvorbis-1.3.6/lib/block.c"
    "../../../ioq3/code/libvorbis-1.3.6/lib/codebook.c"
    "../../../ioq3/code/libvorbis-1.3.6/lib/envelope.c"
    "../../../ioq3/code/libvorbis-1.3.6/lib/floor0.c"
    "../../../ioq3/code/libvorbis-1.3.6/lib/floor1.c"
    "../../../ioq3/code/libvorbis-1.3.6/lib/info.c"
    "../../../ioq3/code/libvorbis-1.3.6/lib/lookup.c"
    "../../../ioq3/code/libvorbis-1.3.6/lib/lpc.c"
    "../../../ioq3/code/libvorbis-1.3.6/lib/lsp.c"
    "../../../ioq3/code/libvorbis-1.3.6/lib/mapping0.c"
    "../../../ioq3/code/libvorbis-1.3.6/lib/mdct.c"
    "../../../ioq3/code/libvorbis-1.3.6/lib/psy.c"
    "../../../ioq3/code/libvorbis-1.3.6/lib/registry.c"
    "../../../ioq3/code/libvorbis-1.3.6/lib/res0.c"
    "../../../ioq3/code/libvorbis-1.3.6/lib/sharedbook.c"
    "../../../ioq3/code/libvorbis-1.3.6/lib/smallft.c"
    "../../../ioq3/code/libvorbis-1.3.6/lib/synthesis.c"
    "../../../ioq3/code/libvorbis-1.3.6/lib/vorbisenc.c"
    "../../../ioq3/code/libvorbis-1.3.6/lib/vorbisfile.c"
    "../../../ioq3/code/libvorbis-1.3.6/lib/window.c"
)
source_group("Sources" FILES ${Sources})

set(ALL_FILES
    ${Sources}
)

################################################################################
# Target
################################################################################
add_library(${PROJECT_NAME} STATIC ${ALL_FILES})
set_target_properties(${PROJECT_NAME} PROPERTIES FOLDER "lib")

use_props(${PROJECT_NAME} "${CMAKE_CONFIGURATION_TYPES}" "${DEFAULT_CXX_PROPS}")
set(ROOT_NAMESPACE vorbis)

set_target_properties(${PROJECT_NAME} PROPERTIES
    VS_GLOBAL_KEYWORD "Win32Proj"
)
################################################################################
# Target name
################################################################################
if("${CMAKE_VS_PLATFORM_NAME}" STREQUAL "Win32")
    set_target_properties(${PROJECT_NAME} PROPERTIES
        TARGET_NAME_DEBUG   "vorbis"
        TARGET_NAME_RELEASE "vorbis"
    )
elseif("${CMAKE_VS_PLATFORM_NAME}" STREQUAL "x64")
    set_target_properties(${PROJECT_NAME} PROPERTIES
        TARGET_NAME_DEBUG   "vorbis"
        TARGET_NAME_RELEASE "vorbis"
    )
endif()
################################################################################
# Output directory
################################################################################
if("${CMAKE_VS_PLATFORM_NAME}" STREQUAL "Win32")
    set_target_properties(${PROJECT_NAME} PROPERTIES
        OUTPUT_DIRECTORY_DEBUG   "${CMAKE_CURRENT_SOURCE_DIR}/bin_x86_debug/"
        OUTPUT_DIRECTORY_RELEASE "${CMAKE_CURRENT_SOURCE_DIR}/bin_x86/"
    )
elseif("${CMAKE_VS_PLATFORM_NAME}" STREQUAL "x64")
    set_target_properties(${PROJECT_NAME} PROPERTIES
        OUTPUT_DIRECTORY_DEBUG   "${CMAKE_CURRENT_SOURCE_DIR}/bin_x64_debug/"
        OUTPUT_DIRECTORY_RELEASE "${CMAKE_CURRENT_SOURCE_DIR}/bin_x64/"
    )
endif()
################################################################################
# Include directories
################################################################################
if("${CMAKE_VS_PLATFORM_NAME}" STREQUAL "Win32")
    target_include_directories(${PROJECT_NAME} PUBLIC
        "${CMAKE_CURRENT_SOURCE_DIR}/../../../ioq3/code/libogg-1.3.3/include;"
        "${CMAKE_CURRENT_SOURCE_DIR}/../../../ioq3/code/libvorbis-1.3.6/include;"
        "${CMAKE_CURRENT_SOURCE_DIR}/../../../ioq3/code/libvorbis-1.3.6/lib"
    )
elseif("${CMAKE_VS_PLATFORM_NAME}" STREQUAL "x64")
    target_include_directories(${PROJECT_NAME} PUBLIC
        "${CMAKE_CURRENT_SOURCE_DIR}/../../../ioq3/code/libogg-1.3.3/include;"
        "${CMAKE_CURRENT_SOURCE_DIR}/../../../ioq3/code/libvorbis-1.3.6/include;"
        "${CMAKE_CURRENT_SOURCE_DIR}/../../../ioq3/code/libvorbis-1.3.6/lib"
    )
endif()

################################################################################
# Compile definitions
################################################################################
if("${CMAKE_VS_PLATFORM_NAME}" STREQUAL "Win32")
    target_compile_definitions(${PROJECT_NAME} PRIVATE
        "$<$<CONFIG:Debug>:"
            "_DEBUG"
        ">"
        "$<$<CONFIG:Release>:"
            "NDEBUG"
        ">"
        "_CRT_SECURE_NO_DEPRECATE;"
        "_MBCS"
    )
elseif("${CMAKE_VS_PLATFORM_NAME}" STREQUAL "x64")
    target_compile_definitions(${PROJECT_NAME} PRIVATE
        "$<$<CONFIG:Debug>:"
            "_DEBUG"
        ">"
        "$<$<CONFIG:Release>:"
            "NDEBUG"
        ">"
        "_CRT_SECURE_NO_DEPRECATE;"
        "_WIN64;"
        "__WIN64__;"
        "_MBCS"
    )
endif()

################################################################################
# Compile and link options
################################################################################
if(MSVC)
    if("${CMAKE_VS_PLATFORM_NAME}" STREQUAL "Win32")
        target_compile_options(${PROJECT_NAME} PRIVATE
            $<$<CONFIG:Debug>:
                /Od;
                ${DEFAULT_CXX_DEBUG_RUNTIME_LIBRARY};
                /ZI
            >
            $<$<CONFIG:Release>:
                /Gm-;
                /Ox;
                /Oi;
                /GF;
                ${DEFAULT_CXX_RUNTIME_LIBRARY};
                /Gy;
                ${DEFAULT_CXX_DEBUG_INFORMATION_FORMAT}
            >
            /W3;
            /wd"4305";
            /wd"4244";
            ${DEFAULT_CXX_EXCEPTION_HANDLING};
            /Y-
        )
    elseif("${CMAKE_VS_PLATFORM_NAME}" STREQUAL "x64")
        target_compile_options(${PROJECT_NAME} PRIVATE
            $<$<CONFIG:Debug>:
                /Od;
                ${DEFAULT_CXX_DEBUG_RUNTIME_LIBRARY};
                /ZI
            >
            $<$<CONFIG:Release>:
                /Gm-;
                /Ox;
                /Oi;
                /GF;
                ${DEFAULT_CXX_RUNTIME_LIBRARY};
                /Gy;
                ${DEFAULT_CXX_DEBUG_INFORMATION_FORMAT}
            >
            /W3;
            /wd"4305";
            /wd"4244";
            ${DEFAULT_CXX_EXCEPTION_HANDLING};
            /Y-
        )
    endif()
    if("${CMAKE_VS_PLATFORM_NAME}" STREQUAL "Win32")
        target_link_options(${PROJECT_NAME} PRIVATE
            $<$<CONFIG:Release>:
                /OPT:REF;
                /OPT:ICF
            >
            /SUBSYSTEM:WINDOWS
        )
    elseif("${CMAKE_VS_PLATFORM_NAME}" STREQUAL "x64")
        target_link_options(${PROJECT_NAME} PRIVATE
            $<$<CONFIG:Release>:
                /OPT:REF;
                /OPT:ICF
            >
            /SUBSYSTEM:WINDOWS
        )
    endif()
endif()



























project(zlib C)

################################################################################
# Source groups
################################################################################
set(Headers
    "../../../ioq3/code/zlib/crc32.h"
    "../../../ioq3/code/zlib/inffast.h"
    "../../../ioq3/code/zlib/inffixed.h"
    "../../../ioq3/code/zlib/inflate.h"
    "../../../ioq3/code/zlib/inftrees.h"
    "../../../ioq3/code/zlib/zconf.h"
    "../../../ioq3/code/zlib/zlib.h"
    "../../../ioq3/code/zlib/zutil.h"
)
source_group("Headers" FILES ${Headers})

set(Sources
    "../../../ioq3/code/zlib/adler32.c"
    "../../../ioq3/code/zlib/crc32.c"
    "../../../ioq3/code/zlib/inffast.c"
    "../../../ioq3/code/zlib/inflate.c"
    "../../../ioq3/code/zlib/inftrees.c"
    "../../../ioq3/code/zlib/zutil.c"
)
source_group("Sources" FILES ${Sources})

set(ALL_FILES
    ${Headers}
    ${Sources}
)

################################################################################
# Target
################################################################################
add_library(${PROJECT_NAME} STATIC ${ALL_FILES})
set_target_properties(${PROJECT_NAME} PROPERTIES FOLDER "lib")

use_props(${PROJECT_NAME} "${CMAKE_CONFIGURATION_TYPES}" "${DEFAULT_CXX_PROPS}")
set(ROOT_NAMESPACE zlib)

set_target_properties(${PROJECT_NAME} PROPERTIES
    VS_GLOBAL_KEYWORD "Win32Proj"
)
################################################################################
# Target name
################################################################################
if("${CMAKE_VS_PLATFORM_NAME}" STREQUAL "Win32")
    set_target_properties(${PROJECT_NAME} PROPERTIES
        TARGET_NAME_DEBUG   "zlib"
        TARGET_NAME_RELEASE "zlib"
    )
elseif("${CMAKE_VS_PLATFORM_NAME}" STREQUAL "x64")
    set_target_properties(${PROJECT_NAME} PROPERTIES
        TARGET_NAME_DEBUG   "zlib"
        TARGET_NAME_RELEASE "zlib"
    )
endif()
################################################################################
# Output directory
################################################################################
if("${CMAKE_VS_PLATFORM_NAME}" STREQUAL "Win32")
    set_target_properties(${PROJECT_NAME} PROPERTIES
        OUTPUT_DIRECTORY_DEBUG   "${CMAKE_CURRENT_SOURCE_DIR}/bin_x86_debug/"
        OUTPUT_DIRECTORY_RELEASE "${CMAKE_CURRENT_SOURCE_DIR}/bin_x86/"
    )
elseif("${CMAKE_VS_PLATFORM_NAME}" STREQUAL "x64")
    set_target_properties(${PROJECT_NAME} PROPERTIES
        OUTPUT_DIRECTORY_DEBUG   "${CMAKE_CURRENT_SOURCE_DIR}/bin_x64_debug/"
        OUTPUT_DIRECTORY_RELEASE "${CMAKE_CURRENT_SOURCE_DIR}/bin_x64/"
    )
endif()
################################################################################
# Compile definitions
################################################################################
if("${CMAKE_VS_PLATFORM_NAME}" STREQUAL "Win32")
    target_compile_definitions(${PROJECT_NAME} PRIVATE
        "$<$<CONFIG:Debug>:"
            "_DEBUG"
        ">"
        "$<$<CONFIG:Release>:"
            "NDEBUG"
        ">"
        "_CRT_SECURE_NO_DEPRECATE;"
        "_MBCS"
    )
elseif("${CMAKE_VS_PLATFORM_NAME}" STREQUAL "x64")
    target_compile_definitions(${PROJECT_NAME} PRIVATE
        "$<$<CONFIG:Debug>:"
            "_DEBUG"
        ">"
        "$<$<CONFIG:Release>:"
            "NDEBUG"
        ">"
        "_CRT_SECURE_NO_DEPRECATE;"
        "_WIN64;"
        "__WIN64__;"
        "_MBCS"
    )
endif()

################################################################################
# Compile and link options
################################################################################
if(MSVC)
    if("${CMAKE_VS_PLATFORM_NAME}" STREQUAL "Win32")
        target_compile_options(${PROJECT_NAME} PRIVATE
            $<$<CONFIG:Debug>:
                /Od;
                ${DEFAULT_CXX_DEBUG_RUNTIME_LIBRARY};
                /ZI
            >
            $<$<CONFIG:Release>:
                /Gm-;
                /Ox;
                /Oi;
                /GF;
                ${DEFAULT_CXX_RUNTIME_LIBRARY};
                /Gy;
                ${DEFAULT_CXX_DEBUG_INFORMATION_FORMAT}
            >
            /W3;
            ${DEFAULT_CXX_EXCEPTION_HANDLING};
            /Y-
        )
    elseif("${CMAKE_VS_PLATFORM_NAME}" STREQUAL "x64")
        target_compile_options(${PROJECT_NAME} PRIVATE
            $<$<CONFIG:Debug>:
                /Od;
                ${DEFAULT_CXX_DEBUG_RUNTIME_LIBRARY};
                /ZI
            >
            $<$<CONFIG:Release>:
                /Gm-;
                /Ox;
                /Oi;
                /GF;
                ${DEFAULT_CXX_RUNTIME_LIBRARY};
                /Gy;
                ${DEFAULT_CXX_DEBUG_INFORMATION_FORMAT}
            >
            /W3;
            ${DEFAULT_CXX_EXCEPTION_HANDLING};
            /Y-
        )
    endif()
    if("${CMAKE_VS_PLATFORM_NAME}" STREQUAL "Win32")
        target_link_options(${PROJECT_NAME} PRIVATE
            $<$<CONFIG:Release>:
                /OPT:REF;
                /OPT:ICF
            >
            /SUBSYSTEM:WINDOWS
        )
    elseif("${CMAKE_VS_PLATFORM_NAME}" STREQUAL "x64")
        target_link_options(${PROJECT_NAME} PRIVATE
            $<$<CONFIG:Release>:
                /OPT:REF;
                /OPT:ICF
            >
            /SUBSYSTEM:WINDOWS
        )
    endif()
endif()



























project(renderer_opengl1 C)

################################################################################
# Source groups
################################################################################
set(jpeg-8c
    "../../../ioq3/code/jpeg-8c/jaricom.c"
    "../../../ioq3/code/jpeg-8c/jcapimin.c"
    "../../../ioq3/code/jpeg-8c/jcapistd.c"
    "../../../ioq3/code/jpeg-8c/jcarith.c"
    "../../../ioq3/code/jpeg-8c/jccoefct.c"
    "../../../ioq3/code/jpeg-8c/jccolor.c"
    "../../../ioq3/code/jpeg-8c/jcdctmgr.c"
    "../../../ioq3/code/jpeg-8c/jchuff.c"
    "../../../ioq3/code/jpeg-8c/jcinit.c"
    "../../../ioq3/code/jpeg-8c/jcmainct.c"
    "../../../ioq3/code/jpeg-8c/jcmarker.c"
    "../../../ioq3/code/jpeg-8c/jcmaster.c"
    "../../../ioq3/code/jpeg-8c/jcomapi.c"
    "../../../ioq3/code/jpeg-8c/jconfig.h"
    "../../../ioq3/code/jpeg-8c/jcparam.c"
    "../../../ioq3/code/jpeg-8c/jcprepct.c"
    "../../../ioq3/code/jpeg-8c/jcsample.c"
    "../../../ioq3/code/jpeg-8c/jctrans.c"
    "../../../ioq3/code/jpeg-8c/jdapimin.c"
    "../../../ioq3/code/jpeg-8c/jdapistd.c"
    "../../../ioq3/code/jpeg-8c/jdarith.c"
    "../../../ioq3/code/jpeg-8c/jdatadst.c"
    "../../../ioq3/code/jpeg-8c/jdatasrc.c"
    "../../../ioq3/code/jpeg-8c/jdcoefct.c"
    "../../../ioq3/code/jpeg-8c/jdcolor.c"
    "../../../ioq3/code/jpeg-8c/jdct.h"
    "../../../ioq3/code/jpeg-8c/jddctmgr.c"
    "../../../ioq3/code/jpeg-8c/jdhuff.c"
    "../../../ioq3/code/jpeg-8c/jdinput.c"
    "../../../ioq3/code/jpeg-8c/jdmainct.c"
    "../../../ioq3/code/jpeg-8c/jdmarker.c"
    "../../../ioq3/code/jpeg-8c/jdmaster.c"
    "../../../ioq3/code/jpeg-8c/jdmerge.c"
    "../../../ioq3/code/jpeg-8c/jdpostct.c"
    "../../../ioq3/code/jpeg-8c/jdsample.c"
    "../../../ioq3/code/jpeg-8c/jdtrans.c"
    "../../../ioq3/code/jpeg-8c/jerror.c"
    "../../../ioq3/code/jpeg-8c/jerror.h"
    "../../../ioq3/code/jpeg-8c/jfdctflt.c"
    "../../../ioq3/code/jpeg-8c/jfdctfst.c"
    "../../../ioq3/code/jpeg-8c/jfdctint.c"
    "../../../ioq3/code/jpeg-8c/jidctflt.c"
    "../../../ioq3/code/jpeg-8c/jidctfst.c"
    "../../../ioq3/code/jpeg-8c/jidctint.c"
    "../../../ioq3/code/jpeg-8c/jinclude.h"
    "../../../ioq3/code/jpeg-8c/jmemmgr.c"
    "../../../ioq3/code/jpeg-8c/jmemnobs.c"
    "../../../ioq3/code/jpeg-8c/jmemsys.h"
    "../../../ioq3/code/jpeg-8c/jmorecfg.h"
    "../../../ioq3/code/jpeg-8c/jpegint.h"
    "../../../ioq3/code/jpeg-8c/jpeglib.h"
    "../../../ioq3/code/jpeg-8c/jquant1.c"
    "../../../ioq3/code/jpeg-8c/jquant2.c"
    "../../../ioq3/code/jpeg-8c/jutils.c"
    "../../../ioq3/code/jpeg-8c/jversion.h"
)
source_group("jpeg-8c" FILES ${jpeg-8c})

set(qcommon
    "../../../ioq3/code/qcommon/puff.c"
    "../../../ioq3/code/qcommon/puff.h"
    "../../../ioq3/code/qcommon/q_math.c"
    "../../../ioq3/code/qcommon/q_shared.c"
    "../../../ioq3/code/qcommon/q_shared.h"
    "../../../ioq3/code/qcommon/qcommon.h"
    "../../../ioq3/code/qcommon/qfiles.h"
    "../../../ioq3/code/qcommon/surfaceflags.h"
)
source_group("qcommon" FILES ${qcommon})

set(renderercommon
    "../../../ioq3/code/renderercommon/iqm.h"
    "../../../ioq3/code/renderercommon/qgl.h"
    "../../../ioq3/code/renderercommon/tr_common.h"
    "../../../ioq3/code/renderercommon/tr_font.c"
    "../../../ioq3/code/renderercommon/tr_image_bmp.c"
    "../../../ioq3/code/renderercommon/tr_image_jpg.c"
    "../../../ioq3/code/renderercommon/tr_image_pcx.c"
    "../../../ioq3/code/renderercommon/tr_image_png.c"
    "../../../ioq3/code/renderercommon/tr_image_tga.c"
    "../../../ioq3/code/renderercommon/tr_noise.c"
    "../../../ioq3/code/renderercommon/tr_public.h"
    "../../../ioq3/code/renderercommon/tr_types.h"
)
source_group("renderercommon" FILES ${renderercommon})

set(renderergl1
    "../../../ioq3/code/renderergl1/tr_altivec.c"
    "../../../ioq3/code/renderergl1/tr_animation.c"
    "../../../ioq3/code/renderergl1/tr_backend.c"
    "../../../ioq3/code/renderergl1/tr_bsp.c"
    "../../../ioq3/code/renderergl1/tr_cmds.c"
    "../../../ioq3/code/renderergl1/tr_curve.c"
    "../../../ioq3/code/renderergl1/tr_flares.c"
    "../../../ioq3/code/renderergl1/tr_image.c"
    "../../../ioq3/code/renderergl1/tr_init.c"
    "../../../ioq3/code/renderergl1/tr_light.c"
    "../../../ioq3/code/renderergl1/tr_local.h"
    "../../../ioq3/code/renderergl1/tr_main.c"
    "../../../ioq3/code/renderergl1/tr_marks.c"
    "../../../ioq3/code/renderergl1/tr_mesh.c"
    "../../../ioq3/code/renderergl1/tr_model.c"
    "../../../ioq3/code/renderergl1/tr_model_iqm.c"
    "../../../ioq3/code/renderergl1/tr_scene.c"
    "../../../ioq3/code/renderergl1/tr_shade.c"
    "../../../ioq3/code/renderergl1/tr_shade_calc.c"
    "../../../ioq3/code/renderergl1/tr_shader.c"
    "../../../ioq3/code/renderergl1/tr_shadows.c"
    "../../../ioq3/code/renderergl1/tr_sky.c"
    "../../../ioq3/code/renderergl1/tr_subs.c"
    "../../../ioq3/code/renderergl1/tr_surface.c"
    "../../../ioq3/code/renderergl1/tr_world.c"
)
source_group("renderergl1" FILES ${renderergl1})

set(sdl
    "../../../ioq3/code/sdl/sdl_gamma.c"
    "../../../ioq3/code/sdl/sdl_glimp.c"
)
source_group("sdl" FILES ${sdl})

set(ALL_FILES
    ${jpeg-8c}
    ${qcommon}
    ${renderercommon}
    ${renderergl1}
    ${sdl}
)

################################################################################
# Target
################################################################################
add_library(${PROJECT_NAME} SHARED ${ALL_FILES})
set_target_properties(${PROJECT_NAME} PROPERTIES FOLDER "renderer")

use_props(${PROJECT_NAME} "${CMAKE_CONFIGURATION_TYPES}" "${DEFAULT_CXX_PROPS}")
set(ROOT_NAMESPACE renderer_opengl1)

set_target_properties(${PROJECT_NAME} PROPERTIES
    VS_GLOBAL_KEYWORD "Win32Proj"
)
################################################################################
# Target name
################################################################################
if("${CMAKE_VS_PLATFORM_NAME}" STREQUAL "Win32")
    set_target_properties(${PROJECT_NAME} PROPERTIES
        TARGET_NAME_DEBUG   "renderer_opengl1_x86"
        TARGET_NAME_RELEASE "renderer_opengl1_x86"
    )
elseif("${CMAKE_VS_PLATFORM_NAME}" STREQUAL "x64")
    set_target_properties(${PROJECT_NAME} PROPERTIES
        TARGET_NAME_DEBUG   "renderer_opengl1_x86_64"
        TARGET_NAME_RELEASE "renderer_opengl1_x86_64"
    )
endif()
################################################################################
# Output directory
################################################################################
if("${CMAKE_VS_PLATFORM_NAME}" STREQUAL "Win32")
    set_target_properties(${PROJECT_NAME} PROPERTIES
        OUTPUT_DIRECTORY_DEBUG   "${CMAKE_CURRENT_SOURCE_DIR}/bin_x86_debug/"
        OUTPUT_DIRECTORY_RELEASE "${CMAKE_CURRENT_SOURCE_DIR}/bin_x86/"
    )
elseif("${CMAKE_VS_PLATFORM_NAME}" STREQUAL "x64")
    set_target_properties(${PROJECT_NAME} PROPERTIES
        OUTPUT_DIRECTORY_DEBUG   "${CMAKE_CURRENT_SOURCE_DIR}/bin_x64_debug/"
        OUTPUT_DIRECTORY_RELEASE "${CMAKE_CURRENT_SOURCE_DIR}/bin_x64/"
    )
endif()
if("${CMAKE_VS_PLATFORM_NAME}" STREQUAL "Win32")
    set_target_properties(${PROJECT_NAME} PROPERTIES
        ARCHIVE_OUTPUT_DIRECTORY_DEBUG   "${CMAKE_CURRENT_SOURCE_DIR}/bin_x86_debug"
        ARCHIVE_OUTPUT_DIRECTORY_RELEASE "${CMAKE_CURRENT_SOURCE_DIR}/bin_x86"
    )
elseif("${CMAKE_VS_PLATFORM_NAME}" STREQUAL "x64")
    set_target_properties(${PROJECT_NAME} PROPERTIES
        ARCHIVE_OUTPUT_DIRECTORY_DEBUG   "${CMAKE_CURRENT_SOURCE_DIR}/bin_x64_debug"
        ARCHIVE_OUTPUT_DIRECTORY_RELEASE "${CMAKE_CURRENT_SOURCE_DIR}/bin_x64"
    )
endif()
if("${CMAKE_VS_PLATFORM_NAME}" STREQUAL "Win32")
    set_target_properties(${PROJECT_NAME} PROPERTIES
        ARCHIVE_OUTPUT_NAME_DEBUG   "renderer_opengl1_x86"
        ARCHIVE_OUTPUT_NAME_RELEASE "renderer_opengl1_x86"
    )
elseif("${CMAKE_VS_PLATFORM_NAME}" STREQUAL "x64")
    set_target_properties(${PROJECT_NAME} PROPERTIES
        ARCHIVE_OUTPUT_NAME_DEBUG   "renderer_opengl1_x86_64"
        ARCHIVE_OUTPUT_NAME_RELEASE "renderer_opengl1_x86_64"
    )
endif()
################################################################################
# Include directories
################################################################################
if("${CMAKE_VS_PLATFORM_NAME}" STREQUAL "Win32")
    target_include_directories(${PROJECT_NAME} PUBLIC
        "${CMAKE_CURRENT_SOURCE_DIR}/../../../ioq3/code/AL;"
        "${CMAKE_CURRENT_SOURCE_DIR}/../../../ioq3/code/jpeg-8c;"
        "${CMAKE_CURRENT_SOURCE_DIR}/../../../ioq3/code/curl-7.54.0;"
        "${CMAKE_CURRENT_SOURCE_DIR}/../../../ioq3/code/SDL2/include;"
        "${CMAKE_CURRENT_SOURCE_DIR}/../../../ioq3/code/zlib"
    )
elseif("${CMAKE_VS_PLATFORM_NAME}" STREQUAL "x64")
    target_include_directories(${PROJECT_NAME} PUBLIC
        "${CMAKE_CURRENT_SOURCE_DIR}/../../../ioq3/code/AL;"
        "${CMAKE_CURRENT_SOURCE_DIR}/../../../ioq3/code/jpeg-8c;"
        "${CMAKE_CURRENT_SOURCE_DIR}/../../../ioq3/code/curl-7.54.0;"
        "${CMAKE_CURRENT_SOURCE_DIR}/../../../ioq3/code/SDL2/include;"
        "${CMAKE_CURRENT_SOURCE_DIR}/../../../ioq3/code/zlib"
    )
endif()

################################################################################
# Compile definitions
################################################################################
if("${CMAKE_VS_PLATFORM_NAME}" STREQUAL "Win32")
    target_compile_definitions(${PROJECT_NAME} PRIVATE
        "$<$<CONFIG:Debug>:"
            "_DEBUG"
        ">"
        "$<$<CONFIG:Release>:"
            "NDEBUG"
        ">"
        "_CRT_SECURE_NO_DEPRECATE;"
        "_WIN32;"
        "WIN32;"
        "_WINDOWS;"
        "USE_INTERNAL_JPEG;"
        "USE_RENDERER_DLOPEN;"
        "USE_LOCAL_HEADERS;"
        "_MBCS"
    )
elseif("${CMAKE_VS_PLATFORM_NAME}" STREQUAL "x64")
    target_compile_definitions(${PROJECT_NAME} PRIVATE
        "$<$<CONFIG:Debug>:"
            "_DEBUG"
        ">"
        "$<$<CONFIG:Release>:"
            "NDEBUG"
        ">"
        "_CRT_SECURE_NO_DEPRECATE;"
        "_WIN64;"
        "__WIN64__;"
        "_WIN32;"
        "WIN32;"
        "_WINDOWS;"
        "USE_INTERNAL_JPEG;"
        "USE_RENDERER_DLOPEN;"
        "USE_LOCAL_HEADERS;"
        "_MBCS"
    )
endif()

################################################################################
# Compile and link options
################################################################################
if(MSVC)
    if("${CMAKE_VS_PLATFORM_NAME}" STREQUAL "Win32")
        target_compile_options(${PROJECT_NAME} PRIVATE
            $<$<CONFIG:Debug>:
                /Od;
                ${DEFAULT_CXX_DEBUG_RUNTIME_LIBRARY};
                /ZI
            >
            $<$<CONFIG:Release>:
                /Gm-;
                /Ox;
                /Oi;
                /GF;
                ${DEFAULT_CXX_RUNTIME_LIBRARY};
                /Gy;
                ${DEFAULT_CXX_DEBUG_INFORMATION_FORMAT}
            >
            /W3;
            ${DEFAULT_CXX_EXCEPTION_HANDLING};
            /Y-
        )
    elseif("${CMAKE_VS_PLATFORM_NAME}" STREQUAL "x64")
        target_compile_options(${PROJECT_NAME} PRIVATE
            $<$<CONFIG:Debug>:
                /Od;
                ${DEFAULT_CXX_DEBUG_RUNTIME_LIBRARY};
                /ZI
            >
            $<$<CONFIG:Release>:
                /Gm-;
                /Ox;
                /Oi;
                /GF;
                ${DEFAULT_CXX_RUNTIME_LIBRARY};
                /Gy;
                ${DEFAULT_CXX_DEBUG_INFORMATION_FORMAT}
            >
            /W3;
            /wd"4267";
            ${DEFAULT_CXX_EXCEPTION_HANDLING};
            /Y-
        )
    endif()
    if("${CMAKE_VS_PLATFORM_NAME}" STREQUAL "Win32")
        target_link_options(${PROJECT_NAME} PRIVATE
            $<$<CONFIG:Debug>:
                /DEBUG;
                /INCREMENTAL
            >
            $<$<CONFIG:Release>:
                /DEBUG:FULL;
                /OPT:REF;
                /OPT:ICF;
                /INCREMENTAL:NO
            >
            /SUBSYSTEM:WINDOWS
        )
    elseif("${CMAKE_VS_PLATFORM_NAME}" STREQUAL "x64")
        target_link_options(${PROJECT_NAME} PRIVATE
            $<$<CONFIG:Debug>:
                /DEBUG;
                /INCREMENTAL
            >
            $<$<CONFIG:Release>:
                /DEBUG:FULL;
                /OPT:REF;
                /OPT:ICF;
                /INCREMENTAL:NO
            >
            /SUBSYSTEM:WINDOWS
        )
    endif()
endif()

################################################################################
# Dependencies
################################################################################
add_dependencies(${PROJECT_NAME}
    SDL2
    zlib
)

# Link with other targets.
target_link_libraries(${PROJECT_NAME} PUBLIC
    SDL2
    zlib
)

if("${CMAKE_VS_PLATFORM_NAME}" STREQUAL "Win32")
    set(ADDITIONAL_LIBRARY_DEPENDENCIES
        "OpenGL32"
    )
elseif("${CMAKE_VS_PLATFORM_NAME}" STREQUAL "x64")
    set(ADDITIONAL_LIBRARY_DEPENDENCIES
        "OpenGL32"
    )
endif()
target_link_libraries(${PROJECT_NAME} PUBLIC "${ADDITIONAL_LIBRARY_DEPENDENCIES}")



























project(renderer_opengl2 C)

################################################################################
# Source groups
################################################################################
set(dynamic
    "dynamic/renderergl2/bokeh_fp.c"
    "dynamic/renderergl2/bokeh_vp.c"
    "dynamic/renderergl2/calclevels4x_fp.c"
    "dynamic/renderergl2/calclevels4x_vp.c"
    "dynamic/renderergl2/depthblur_fp.c"
    "dynamic/renderergl2/depthblur_vp.c"
    "dynamic/renderergl2/dlight_fp.c"
    "dynamic/renderergl2/dlight_vp.c"
    "dynamic/renderergl2/down4x_fp.c"
    "dynamic/renderergl2/down4x_vp.c"
    "dynamic/renderergl2/fogpass_fp.c"
    "dynamic/renderergl2/fogpass_vp.c"
    "dynamic/renderergl2/generic_fp.c"
    "dynamic/renderergl2/generic_vp.c"
    "dynamic/renderergl2/lightall_fp.c"
    "dynamic/renderergl2/lightall_vp.c"
    "dynamic/renderergl2/pshadow_fp.c"
    "dynamic/renderergl2/pshadow_vp.c"
    "dynamic/renderergl2/shadowfill_fp.c"
    "dynamic/renderergl2/shadowfill_vp.c"
    "dynamic/renderergl2/shadowmask_fp.c"
    "dynamic/renderergl2/shadowmask_vp.c"
    "dynamic/renderergl2/ssao_fp.c"
    "dynamic/renderergl2/ssao_vp.c"
    "dynamic/renderergl2/texturecolor_fp.c"
    "dynamic/renderergl2/texturecolor_vp.c"
    "dynamic/renderergl2/tonemap_fp.c"
    "dynamic/renderergl2/tonemap_vp.c"
)
source_group("dynamic" FILES ${dynamic})

set(jpeg-8c
    "../../../ioq3/code/jpeg-8c/jaricom.c"
    "../../../ioq3/code/jpeg-8c/jcapimin.c"
    "../../../ioq3/code/jpeg-8c/jcapistd.c"
    "../../../ioq3/code/jpeg-8c/jcarith.c"
    "../../../ioq3/code/jpeg-8c/jccoefct.c"
    "../../../ioq3/code/jpeg-8c/jccolor.c"
    "../../../ioq3/code/jpeg-8c/jcdctmgr.c"
    "../../../ioq3/code/jpeg-8c/jchuff.c"
    "../../../ioq3/code/jpeg-8c/jcinit.c"
    "../../../ioq3/code/jpeg-8c/jcmainct.c"
    "../../../ioq3/code/jpeg-8c/jcmarker.c"
    "../../../ioq3/code/jpeg-8c/jcmaster.c"
    "../../../ioq3/code/jpeg-8c/jcomapi.c"
    "../../../ioq3/code/jpeg-8c/jconfig.h"
    "../../../ioq3/code/jpeg-8c/jcparam.c"
    "../../../ioq3/code/jpeg-8c/jcprepct.c"
    "../../../ioq3/code/jpeg-8c/jcsample.c"
    "../../../ioq3/code/jpeg-8c/jctrans.c"
    "../../../ioq3/code/jpeg-8c/jdapimin.c"
    "../../../ioq3/code/jpeg-8c/jdapistd.c"
    "../../../ioq3/code/jpeg-8c/jdarith.c"
    "../../../ioq3/code/jpeg-8c/jdatadst.c"
    "../../../ioq3/code/jpeg-8c/jdatasrc.c"
    "../../../ioq3/code/jpeg-8c/jdcoefct.c"
    "../../../ioq3/code/jpeg-8c/jdcolor.c"
    "../../../ioq3/code/jpeg-8c/jdct.h"
    "../../../ioq3/code/jpeg-8c/jddctmgr.c"
    "../../../ioq3/code/jpeg-8c/jdhuff.c"
    "../../../ioq3/code/jpeg-8c/jdinput.c"
    "../../../ioq3/code/jpeg-8c/jdmainct.c"
    "../../../ioq3/code/jpeg-8c/jdmarker.c"
    "../../../ioq3/code/jpeg-8c/jdmaster.c"
    "../../../ioq3/code/jpeg-8c/jdmerge.c"
    "../../../ioq3/code/jpeg-8c/jdpostct.c"
    "../../../ioq3/code/jpeg-8c/jdsample.c"
    "../../../ioq3/code/jpeg-8c/jdtrans.c"
    "../../../ioq3/code/jpeg-8c/jerror.c"
    "../../../ioq3/code/jpeg-8c/jerror.h"
    "../../../ioq3/code/jpeg-8c/jfdctflt.c"
    "../../../ioq3/code/jpeg-8c/jfdctfst.c"
    "../../../ioq3/code/jpeg-8c/jfdctint.c"
    "../../../ioq3/code/jpeg-8c/jidctflt.c"
    "../../../ioq3/code/jpeg-8c/jidctfst.c"
    "../../../ioq3/code/jpeg-8c/jidctint.c"
    "../../../ioq3/code/jpeg-8c/jinclude.h"
    "../../../ioq3/code/jpeg-8c/jmemmgr.c"
    "../../../ioq3/code/jpeg-8c/jmemnobs.c"
    "../../../ioq3/code/jpeg-8c/jmemsys.h"
    "../../../ioq3/code/jpeg-8c/jmorecfg.h"
    "../../../ioq3/code/jpeg-8c/jpegint.h"
    "../../../ioq3/code/jpeg-8c/jpeglib.h"
    "../../../ioq3/code/jpeg-8c/jquant1.c"
    "../../../ioq3/code/jpeg-8c/jquant2.c"
    "../../../ioq3/code/jpeg-8c/jutils.c"
    "../../../ioq3/code/jpeg-8c/jversion.h"
)
source_group("jpeg-8c" FILES ${jpeg-8c})

set(qcommon
    "../../../ioq3/code/qcommon/puff.c"
    "../../../ioq3/code/qcommon/puff.h"
    "../../../ioq3/code/qcommon/q_math.c"
    "../../../ioq3/code/qcommon/q_shared.c"
    "../../../ioq3/code/qcommon/q_shared.h"
    "../../../ioq3/code/qcommon/qcommon.h"
    "../../../ioq3/code/qcommon/qfiles.h"
    "../../../ioq3/code/qcommon/surfaceflags.h"
)
source_group("qcommon" FILES ${qcommon})

set(renderercommon
    "../../../ioq3/code/renderercommon/iqm.h"
    "../../../ioq3/code/renderercommon/qgl.h"
    "../../../ioq3/code/renderercommon/tr_common.h"
    "../../../ioq3/code/renderercommon/tr_font.c"
    "../../../ioq3/code/renderercommon/tr_image_bmp.c"
    "../../../ioq3/code/renderercommon/tr_image_jpg.c"
    "../../../ioq3/code/renderercommon/tr_image_pcx.c"
    "../../../ioq3/code/renderercommon/tr_image_png.c"
    "../../../ioq3/code/renderercommon/tr_image_tga.c"
    "../../../ioq3/code/renderercommon/tr_noise.c"
    "../../../ioq3/code/renderercommon/tr_public.h"
    "../../../ioq3/code/renderercommon/tr_types.h"
)
source_group("renderercommon" FILES ${renderercommon})

set(renderergl2
    "../../../ioq3/code/renderergl2/tr_animation.c"
    "../../../ioq3/code/renderergl2/tr_backend.c"
    "../../../ioq3/code/renderergl2/tr_bsp.c"
    "../../../ioq3/code/renderergl2/tr_cmds.c"
    "../../../ioq3/code/renderergl2/tr_curve.c"
    "../../../ioq3/code/renderergl2/tr_dsa.c"
    "../../../ioq3/code/renderergl2/tr_dsa.h"
    "../../../ioq3/code/renderergl2/tr_extensions.c"
    "../../../ioq3/code/renderergl2/tr_extramath.c"
    "../../../ioq3/code/renderergl2/tr_extramath.h"
    "../../../ioq3/code/renderergl2/tr_extratypes.h"
    "../../../ioq3/code/renderergl2/tr_fbo.c"
    "../../../ioq3/code/renderergl2/tr_fbo.h"
    "../../../ioq3/code/renderergl2/tr_flares.c"
    "../../../ioq3/code/renderergl2/tr_glsl.c"
    "../../../ioq3/code/renderergl2/tr_image.c"
    "../../../ioq3/code/renderergl2/tr_image_dds.c"
    "../../../ioq3/code/renderergl2/tr_init.c"
    "../../../ioq3/code/renderergl2/tr_light.c"
    "../../../ioq3/code/renderergl2/tr_local.h"
    "../../../ioq3/code/renderergl2/tr_main.c"
    "../../../ioq3/code/renderergl2/tr_marks.c"
    "../../../ioq3/code/renderergl2/tr_mesh.c"
    "../../../ioq3/code/renderergl2/tr_model.c"
    "../../../ioq3/code/renderergl2/tr_model_iqm.c"
    "../../../ioq3/code/renderergl2/tr_postprocess.c"
    "../../../ioq3/code/renderergl2/tr_postprocess.h"
    "../../../ioq3/code/renderergl2/tr_scene.c"
    "../../../ioq3/code/renderergl2/tr_shade.c"
    "../../../ioq3/code/renderergl2/tr_shade_calc.c"
    "../../../ioq3/code/renderergl2/tr_shader.c"
    "../../../ioq3/code/renderergl2/tr_shadows.c"
    "../../../ioq3/code/renderergl2/tr_sky.c"
    "../../../ioq3/code/renderergl2/tr_subs.c"
    "../../../ioq3/code/renderergl2/tr_surface.c"
    "../../../ioq3/code/renderergl2/tr_vbo.c"
    "../../../ioq3/code/renderergl2/tr_world.c"
)
source_group("renderergl2" FILES ${renderergl2})

set(sdl
    "../../../ioq3/code/sdl/sdl_gamma.c"
    "../../../ioq3/code/sdl/sdl_glimp.c"
)
source_group("sdl" FILES ${sdl})

set(ALL_FILES
    ${dynamic}
    ${jpeg-8c}
    ${qcommon}
    ${renderercommon}
    ${renderergl2}
    ${sdl}
)

################################################################################
# Target
################################################################################
add_library(${PROJECT_NAME} SHARED ${ALL_FILES})
set_target_properties(${PROJECT_NAME} PROPERTIES FOLDER "renderer")

use_props(${PROJECT_NAME} "${CMAKE_CONFIGURATION_TYPES}" "${DEFAULT_CXX_PROPS}")
set(ROOT_NAMESPACE renderer_opengl2)

set_target_properties(${PROJECT_NAME} PROPERTIES
    VS_GLOBAL_KEYWORD "Win32Proj"
)
################################################################################
# Target name
################################################################################
if("${CMAKE_VS_PLATFORM_NAME}" STREQUAL "Win32")
    set_target_properties(${PROJECT_NAME} PROPERTIES
        TARGET_NAME_DEBUG   "renderer_opengl2_x86"
        TARGET_NAME_RELEASE "renderer_opengl2_x86"
    )
elseif("${CMAKE_VS_PLATFORM_NAME}" STREQUAL "x64")
    set_target_properties(${PROJECT_NAME} PROPERTIES
        TARGET_NAME_DEBUG   "renderer_opengl2_x86_64"
        TARGET_NAME_RELEASE "renderer_opengl2_x86_64"
    )
endif()
################################################################################
# Output directory
################################################################################
if("${CMAKE_VS_PLATFORM_NAME}" STREQUAL "Win32")
    set_target_properties(${PROJECT_NAME} PROPERTIES
        OUTPUT_DIRECTORY_DEBUG   "${CMAKE_CURRENT_SOURCE_DIR}/bin_x86_debug/"
        OUTPUT_DIRECTORY_RELEASE "${CMAKE_CURRENT_SOURCE_DIR}/bin_x86/"
    )
elseif("${CMAKE_VS_PLATFORM_NAME}" STREQUAL "x64")
    set_target_properties(${PROJECT_NAME} PROPERTIES
        OUTPUT_DIRECTORY_DEBUG   "${CMAKE_CURRENT_SOURCE_DIR}/bin_x64_debug/"
        OUTPUT_DIRECTORY_RELEASE "${CMAKE_CURRENT_SOURCE_DIR}/bin_x64/"
    )
endif()
if("${CMAKE_VS_PLATFORM_NAME}" STREQUAL "Win32")
    set_target_properties(${PROJECT_NAME} PROPERTIES
        ARCHIVE_OUTPUT_DIRECTORY_DEBUG   "${CMAKE_CURRENT_SOURCE_DIR}/bin_x86_debug"
        ARCHIVE_OUTPUT_DIRECTORY_RELEASE "${CMAKE_CURRENT_SOURCE_DIR}/bin_x86"
    )
elseif("${CMAKE_VS_PLATFORM_NAME}" STREQUAL "x64")
    set_target_properties(${PROJECT_NAME} PROPERTIES
        ARCHIVE_OUTPUT_DIRECTORY_DEBUG   "${CMAKE_CURRENT_SOURCE_DIR}/bin_x64_debug"
        ARCHIVE_OUTPUT_DIRECTORY_RELEASE "${CMAKE_CURRENT_SOURCE_DIR}/bin_x64"
    )
endif()
if("${CMAKE_VS_PLATFORM_NAME}" STREQUAL "Win32")
    set_target_properties(${PROJECT_NAME} PROPERTIES
        ARCHIVE_OUTPUT_NAME_DEBUG   "renderer_opengl2_x86"
        ARCHIVE_OUTPUT_NAME_RELEASE "renderer_opengl2_x86"
    )
elseif("${CMAKE_VS_PLATFORM_NAME}" STREQUAL "x64")
    set_target_properties(${PROJECT_NAME} PROPERTIES
        ARCHIVE_OUTPUT_NAME_DEBUG   "renderer_opengl2_x86_64"
        ARCHIVE_OUTPUT_NAME_RELEASE "renderer_opengl2_x86_64"
    )
endif()
################################################################################
# Include directories
################################################################################
if("${CMAKE_VS_PLATFORM_NAME}" STREQUAL "Win32")
    target_include_directories(${PROJECT_NAME} PUBLIC
        "${CMAKE_CURRENT_SOURCE_DIR}/../../../ioq3/code/SDL2/include;"
        "${CMAKE_CURRENT_SOURCE_DIR}/../../../ioq3/code/libcurl;"
        "${CMAKE_CURRENT_SOURCE_DIR}/../../../ioq3/code/AL;"
        "${CMAKE_CURRENT_SOURCE_DIR}/../../../ioq3/code/zlib;"
        "${CMAKE_CURRENT_SOURCE_DIR}/../../../ioq3/code/jpeg-8c"
    )
elseif("${CMAKE_VS_PLATFORM_NAME}" STREQUAL "x64")
    target_include_directories(${PROJECT_NAME} PUBLIC
        "${CMAKE_CURRENT_SOURCE_DIR}/../../../ioq3/code/SDL2/include;"
        "${CMAKE_CURRENT_SOURCE_DIR}/../../../ioq3/code/libcurl;"
        "${CMAKE_CURRENT_SOURCE_DIR}/../../../ioq3/code/AL;"
        "${CMAKE_CURRENT_SOURCE_DIR}/../../../ioq3/code/zlib;"
        "${CMAKE_CURRENT_SOURCE_DIR}/../../../ioq3/code/jpeg-8c"
    )
endif()

################################################################################
# Compile definitions
################################################################################
if("${CMAKE_VS_PLATFORM_NAME}" STREQUAL "Win32")
    target_compile_definitions(${PROJECT_NAME} PRIVATE
        "$<$<CONFIG:Debug>:"
            "_DEBUG"
        ">"
        "$<$<CONFIG:Release>:"
            "NDEBUG"
        ">"
        "_CRT_SECURE_NO_DEPRECATE;"
        "_WIN32;"
        "WIN32;"
        "USE_INTERNAL_JPEG;"
        "USE_RENDERER_DLOPEN;"
        "USE_LOCAL_HEADERS;"
        "_MBCS"
    )
elseif("${CMAKE_VS_PLATFORM_NAME}" STREQUAL "x64")
    target_compile_definitions(${PROJECT_NAME} PRIVATE
        "$<$<CONFIG:Debug>:"
            "_DEBUG"
        ">"
        "$<$<CONFIG:Release>:"
            "NDEBUG"
        ">"
        "_CRT_SECURE_NO_DEPRECATE;"
        "_WIN64;"
        "__WIN64__;"
        "_WIN32;"
        "WIN32;"
        "USE_INTERNAL_JPEG;"
        "USE_RENDERER_DLOPEN;"
        "USE_LOCAL_HEADERS;"
        "_MBCS"
    )
endif()

################################################################################
# Compile and link options
################################################################################
if(MSVC)
    if("${CMAKE_VS_PLATFORM_NAME}" STREQUAL "Win32")
        target_compile_options(${PROJECT_NAME} PRIVATE
            $<$<CONFIG:Debug>:
                /Od;
                ${DEFAULT_CXX_DEBUG_RUNTIME_LIBRARY};
                /ZI
            >
            $<$<CONFIG:Release>:
                /Gm-;
                /Ox;
                /Oi;
                /GF;
                ${DEFAULT_CXX_RUNTIME_LIBRARY};
                /Gy;
                ${DEFAULT_CXX_DEBUG_INFORMATION_FORMAT}
            >
            /W3;
            ${DEFAULT_CXX_EXCEPTION_HANDLING};
            /Y-
        )
    elseif("${CMAKE_VS_PLATFORM_NAME}" STREQUAL "x64")
        target_compile_options(${PROJECT_NAME} PRIVATE
            $<$<CONFIG:Debug>:
                /Od;
                ${DEFAULT_CXX_DEBUG_RUNTIME_LIBRARY};
                /ZI
            >
            $<$<CONFIG:Release>:
                /Gm-;
                /Ox;
                /Oi;
                /GF;
                ${DEFAULT_CXX_RUNTIME_LIBRARY};
                /Gy;
                ${DEFAULT_CXX_DEBUG_INFORMATION_FORMAT}
            >
            /W3;
            /wd"4267";
            ${DEFAULT_CXX_EXCEPTION_HANDLING};
            /Y-
        )
    endif()
    if("${CMAKE_VS_PLATFORM_NAME}" STREQUAL "Win32")
        target_link_options(${PROJECT_NAME} PRIVATE
            $<$<CONFIG:Debug>:
                /DEBUG;
                /INCREMENTAL
            >
            $<$<CONFIG:Release>:
                /DEBUG:FULL;
                /OPT:REF;
                /OPT:ICF;
                /INCREMENTAL:NO
            >
            /SUBSYSTEM:WINDOWS
        )
    elseif("${CMAKE_VS_PLATFORM_NAME}" STREQUAL "x64")
        target_link_options(${PROJECT_NAME} PRIVATE
            $<$<CONFIG:Debug>:
                /DEBUG;
                /INCREMENTAL
            >
            $<$<CONFIG:Release>:
                /DEBUG:FULL;
                /OPT:REF;
                /OPT:ICF;
                /INCREMENTAL:NO
            >
            /SUBSYSTEM:WINDOWS
        )
    endif()
endif()

################################################################################
# Dependencies
################################################################################
add_dependencies(${PROJECT_NAME}
    SDL2
    zlib
)

# Link with other targets.
target_link_libraries(${PROJECT_NAME} PUBLIC
    SDL2
    zlib
)

if("${CMAKE_VS_PLATFORM_NAME}" STREQUAL "Win32")
    set(ADDITIONAL_LIBRARY_DEPENDENCIES
        "OpenGL32"
    )
elseif("${CMAKE_VS_PLATFORM_NAME}" STREQUAL "x64")
    set(ADDITIONAL_LIBRARY_DEPENDENCIES
        "OpenGL32"
    )
endif()
target_link_libraries(${PROJECT_NAME} PUBLIC "${ADDITIONAL_LIBRARY_DEPENDENCIES}")



























project(lburg C)

################################################################################
# Source groups
################################################################################
set(Headers
    "../../../ioq3/code/tools/lcc/lburg/lburg.h"
)
source_group("Headers" FILES ${Headers})

set(Sources
    "../../../ioq3/code/tools/lcc/lburg/gram.c"
    "../../../ioq3/code/tools/lcc/lburg/lburg.c"
)
source_group("Sources" FILES ${Sources})

set(ALL_FILES
    ${Headers}
    ${Sources}
)

################################################################################
# Target
################################################################################
add_executable(${PROJECT_NAME} ${ALL_FILES})
set_target_properties(${PROJECT_NAME} PROPERTIES FOLDER "tool")

use_props(${PROJECT_NAME} "${CMAKE_CONFIGURATION_TYPES}" "${DEFAULT_CXX_PROPS}")
set(ROOT_NAMESPACE lburg)

set_target_properties(${PROJECT_NAME} PROPERTIES
    VS_GLOBAL_KEYWORD "Win32Proj"
)
################################################################################
# Target name
################################################################################
if("${CMAKE_VS_PLATFORM_NAME}" STREQUAL "Win32")
    set_target_properties(${PROJECT_NAME} PROPERTIES
        TARGET_NAME_DEBUG   "lburg"
        TARGET_NAME_RELEASE "lburg"
    )
elseif("${CMAKE_VS_PLATFORM_NAME}" STREQUAL "x64")
    set_target_properties(${PROJECT_NAME} PROPERTIES
        TARGET_NAME_DEBUG   "lburg"
        TARGET_NAME_RELEASE "lburg"
    )
endif()
################################################################################
# Output directory
################################################################################
if("${CMAKE_VS_PLATFORM_NAME}" STREQUAL "Win32")
    set_target_properties(${PROJECT_NAME} PROPERTIES
        OUTPUT_DIRECTORY_DEBUG   "${CMAKE_CURRENT_SOURCE_DIR}/bin_x86_debug/"
        OUTPUT_DIRECTORY_RELEASE "${CMAKE_CURRENT_SOURCE_DIR}/bin_x86/"
    )
elseif("${CMAKE_VS_PLATFORM_NAME}" STREQUAL "x64")
    set_target_properties(${PROJECT_NAME} PROPERTIES
        OUTPUT_DIRECTORY_DEBUG   "${CMAKE_CURRENT_SOURCE_DIR}/bin_x64_debug/"
        OUTPUT_DIRECTORY_RELEASE "${CMAKE_CURRENT_SOURCE_DIR}/bin_x64/"
    )
endif()
################################################################################
# Compile definitions
################################################################################
if("${CMAKE_VS_PLATFORM_NAME}" STREQUAL "Win32")
    target_compile_definitions(${PROJECT_NAME} PRIVATE
        "$<$<CONFIG:Debug>:"
            "_DEBUG"
        ">"
        "$<$<CONFIG:Release>:"
            "NDEBUG"
        ">"
        "_CRT_SECURE_NO_DEPRECATE;"
        "WIN32;"
        "_MBCS"
    )
elseif("${CMAKE_VS_PLATFORM_NAME}" STREQUAL "x64")
    target_compile_definitions(${PROJECT_NAME} PRIVATE
        "$<$<CONFIG:Debug>:"
            "_DEBUG"
        ">"
        "$<$<CONFIG:Release>:"
            "NDEBUG"
        ">"
        "_CRT_SECURE_NO_DEPRECATE;"
        "_WIN64;"
        "__WIN64__;"
        "WIN32;"
        "_MBCS"
    )
endif()

################################################################################
# Compile and link options
################################################################################
if(MSVC)
    if("${CMAKE_VS_PLATFORM_NAME}" STREQUAL "Win32")
        target_compile_options(${PROJECT_NAME} PRIVATE
            $<$<CONFIG:Debug>:
                /Od;
                ${DEFAULT_CXX_DEBUG_RUNTIME_LIBRARY};
                /ZI
            >
            $<$<CONFIG:Release>:
                /Gm-;
                /Ox;
                /Oi;
                /GF;
                ${DEFAULT_CXX_RUNTIME_LIBRARY};
                /Gy;
                ${DEFAULT_CXX_DEBUG_INFORMATION_FORMAT}
            >
            /W3;
            ${DEFAULT_CXX_EXCEPTION_HANDLING};
            /Y-
        )
    elseif("${CMAKE_VS_PLATFORM_NAME}" STREQUAL "x64")
        target_compile_options(${PROJECT_NAME} PRIVATE
            $<$<CONFIG:Debug>:
                /Od;
                ${DEFAULT_CXX_DEBUG_RUNTIME_LIBRARY};
                /ZI
            >
            $<$<CONFIG:Release>:
                /Gm-;
                /Ox;
                /Oi;
                /GF;
                ${DEFAULT_CXX_RUNTIME_LIBRARY};
                /Gy;
                ${DEFAULT_CXX_DEBUG_INFORMATION_FORMAT}
            >
            /W3;
            ${DEFAULT_CXX_EXCEPTION_HANDLING};
            /Y-
        )
    endif()
    if("${CMAKE_VS_PLATFORM_NAME}" STREQUAL "Win32")
        target_link_options(${PROJECT_NAME} PRIVATE
            $<$<CONFIG:Debug>:
                /DEBUG;
                /INCREMENTAL
            >
            $<$<CONFIG:Release>:
                /DEBUG:FULL;
                /OPT:REF;
                /OPT:ICF;
                /INCREMENTAL:NO
            >
            /SUBSYSTEM:CONSOLE
        )
    elseif("${CMAKE_VS_PLATFORM_NAME}" STREQUAL "x64")
        target_link_options(${PROJECT_NAME} PRIVATE
            $<$<CONFIG:Debug>:
                /DEBUG;
                /INCREMENTAL
            >
            $<$<CONFIG:Release>:
                /DEBUG:FULL;
                /OPT:REF;
                /OPT:ICF;
                /INCREMENTAL:NO
            >
            /SUBSYSTEM:CONSOLE
        )
    endif()
endif()



























project(lcc C)

################################################################################
# Source groups
################################################################################
set(ioq3__code__tools__lcc__etc
    "../../../ioq3/code/tools/lcc/etc/bytecode.c"
)
source_group("ioq3\\code\\tools\\lcc\\etc" FILES ${ioq3__code__tools__lcc__etc})

set(lcc
    "../../lcc/lcc.c"
)
source_group("lcc" FILES ${lcc})

set(ALL_FILES
    ${ioq3__code__tools__lcc__etc}
    ${lcc}
)

################################################################################
# Target
################################################################################
add_executable(${PROJECT_NAME} ${ALL_FILES})
set_target_properties(${PROJECT_NAME} PROPERTIES FOLDER "tool")

use_props(${PROJECT_NAME} "${CMAKE_CONFIGURATION_TYPES}" "${DEFAULT_CXX_PROPS}")
set(ROOT_NAMESPACE lcc)

set_target_properties(${PROJECT_NAME} PROPERTIES
    VS_GLOBAL_KEYWORD "Win32Proj"
)
################################################################################
# Target name
################################################################################
if("${CMAKE_VS_PLATFORM_NAME}" STREQUAL "Win32")
    set_target_properties(${PROJECT_NAME} PROPERTIES
        TARGET_NAME_DEBUG   "lcc"
        TARGET_NAME_RELEASE "lcc"
    )
elseif("${CMAKE_VS_PLATFORM_NAME}" STREQUAL "x64")
    set_target_properties(${PROJECT_NAME} PROPERTIES
        TARGET_NAME_DEBUG   "lcc"
        TARGET_NAME_RELEASE "lcc"
    )
endif()
################################################################################
# Output directory
################################################################################
if("${CMAKE_VS_PLATFORM_NAME}" STREQUAL "Win32")
    set_target_properties(${PROJECT_NAME} PROPERTIES
        OUTPUT_DIRECTORY_DEBUG   "${CMAKE_CURRENT_SOURCE_DIR}/bin_x86_debug/"
        OUTPUT_DIRECTORY_RELEASE "${CMAKE_CURRENT_SOURCE_DIR}/bin_x86/"
    )
elseif("${CMAKE_VS_PLATFORM_NAME}" STREQUAL "x64")
    set_target_properties(${PROJECT_NAME} PROPERTIES
        OUTPUT_DIRECTORY_DEBUG   "${CMAKE_CURRENT_SOURCE_DIR}/bin_x64_debug/"
        OUTPUT_DIRECTORY_RELEASE "${CMAKE_CURRENT_SOURCE_DIR}/bin_x64/"
    )
endif()
################################################################################
# Compile definitions
################################################################################
if("${CMAKE_VS_PLATFORM_NAME}" STREQUAL "Win32")
    target_compile_definitions(${PROJECT_NAME} PRIVATE
        "$<$<CONFIG:Debug>:"
            "_DEBUG"
        ">"
        "$<$<CONFIG:Release>:"
            "NDEBUG"
        ">"
        "_CRT_SECURE_NO_DEPRECATE;"
        "WIN32;"
        "_MBCS"
    )
elseif("${CMAKE_VS_PLATFORM_NAME}" STREQUAL "x64")
    target_compile_definitions(${PROJECT_NAME} PRIVATE
        "$<$<CONFIG:Debug>:"
            "_DEBUG"
        ">"
        "$<$<CONFIG:Release>:"
            "NDEBUG"
        ">"
        "_CRT_SECURE_NO_DEPRECATE;"
        "_WIN64;"
        "__WIN64__;"
        "WIN32;"
        "_MBCS"
    )
endif()

################################################################################
# Compile and link options
################################################################################
if(MSVC)
    if("${CMAKE_VS_PLATFORM_NAME}" STREQUAL "Win32")
        target_compile_options(${PROJECT_NAME} PRIVATE
            $<$<CONFIG:Debug>:
                /Od;
                ${DEFAULT_CXX_DEBUG_RUNTIME_LIBRARY};
                /ZI
            >
            $<$<CONFIG:Release>:
                /Gm-;
                /Ox;
                /Oi;
                /GF;
                ${DEFAULT_CXX_RUNTIME_LIBRARY};
                /Gy;
                ${DEFAULT_CXX_DEBUG_INFORMATION_FORMAT}
            >
            /W3;
            /wd"4273";
            /wd"4996";
            ${DEFAULT_CXX_EXCEPTION_HANDLING};
            /Y-
        )
    elseif("${CMAKE_VS_PLATFORM_NAME}" STREQUAL "x64")
        target_compile_options(${PROJECT_NAME} PRIVATE
            $<$<CONFIG:Debug>:
                /Od;
                ${DEFAULT_CXX_DEBUG_RUNTIME_LIBRARY};
                /ZI
            >
            $<$<CONFIG:Release>:
                /Gm-;
                /Ox;
                /Oi;
                /GF;
                ${DEFAULT_CXX_RUNTIME_LIBRARY};
                /Gy;
                ${DEFAULT_CXX_DEBUG_INFORMATION_FORMAT}
            >
            /W3;
            /wd"4273";
            /wd"4996";
            ${DEFAULT_CXX_EXCEPTION_HANDLING};
            /Y-
        )
    endif()
    if("${CMAKE_VS_PLATFORM_NAME}" STREQUAL "Win32")
        target_link_options(${PROJECT_NAME} PRIVATE
            $<$<CONFIG:Debug>:
                /DEBUG;
                /INCREMENTAL
            >
            $<$<CONFIG:Release>:
                /DEBUG:FULL;
                /OPT:REF;
                /OPT:ICF;
                /INCREMENTAL:NO
            >
            /SUBSYSTEM:CONSOLE
        )
    elseif("${CMAKE_VS_PLATFORM_NAME}" STREQUAL "x64")
        target_link_options(${PROJECT_NAME} PRIVATE
            $<$<CONFIG:Debug>:
                /DEBUG;
                /INCREMENTAL
            >
            $<$<CONFIG:Release>:
                /DEBUG:FULL;
                /OPT:REF;
                /OPT:ICF;
                /INCREMENTAL:NO
            >
            /SUBSYSTEM:CONSOLE
        )
    endif()
endif()



























project(q3asm C)

################################################################################
# Source groups
################################################################################
set(Headers
    "../../../ioq3/code/tools/asm/cmdlib.h"
    "../../../ioq3/code/tools/asm/mathlib.h"
    "../../../ioq3/code/tools/asm/opstrings.h"
)
source_group("Headers" FILES ${Headers})

set(Sources
    "../../../ioq3/code/tools/asm/cmdlib.c"
    "../../../ioq3/code/tools/asm/q3asm.c"
)
source_group("Sources" FILES ${Sources})

set(ALL_FILES
    ${Headers}
    ${Sources}
)

################################################################################
# Target
################################################################################
add_executable(${PROJECT_NAME} ${ALL_FILES})
set_target_properties(${PROJECT_NAME} PROPERTIES FOLDER "tool")

use_props(${PROJECT_NAME} "${CMAKE_CONFIGURATION_TYPES}" "${DEFAULT_CXX_PROPS}")
set(ROOT_NAMESPACE q3asm)

set_target_properties(${PROJECT_NAME} PROPERTIES
    VS_GLOBAL_KEYWORD "Win32Proj"
)
################################################################################
# Target name
################################################################################
if("${CMAKE_VS_PLATFORM_NAME}" STREQUAL "Win32")
    set_target_properties(${PROJECT_NAME} PROPERTIES
        TARGET_NAME_DEBUG   "q3asm"
        TARGET_NAME_RELEASE "q3asm"
    )
elseif("${CMAKE_VS_PLATFORM_NAME}" STREQUAL "x64")
    set_target_properties(${PROJECT_NAME} PROPERTIES
        TARGET_NAME_DEBUG   "q3asm"
        TARGET_NAME_RELEASE "q3asm"
    )
endif()
################################################################################
# Output directory
################################################################################
if("${CMAKE_VS_PLATFORM_NAME}" STREQUAL "Win32")
    set_target_properties(${PROJECT_NAME} PROPERTIES
        OUTPUT_DIRECTORY_DEBUG   "${CMAKE_CURRENT_SOURCE_DIR}/bin_x86_debug/"
        OUTPUT_DIRECTORY_RELEASE "${CMAKE_CURRENT_SOURCE_DIR}/bin_x86/"
    )
elseif("${CMAKE_VS_PLATFORM_NAME}" STREQUAL "x64")
    set_target_properties(${PROJECT_NAME} PROPERTIES
        OUTPUT_DIRECTORY_DEBUG   "${CMAKE_CURRENT_SOURCE_DIR}/bin_x64_debug/"
        OUTPUT_DIRECTORY_RELEASE "${CMAKE_CURRENT_SOURCE_DIR}/bin_x64/"
    )
endif()
################################################################################
# Compile definitions
################################################################################
if("${CMAKE_VS_PLATFORM_NAME}" STREQUAL "Win32")
    target_compile_definitions(${PROJECT_NAME} PRIVATE
        "$<$<CONFIG:Debug>:"
            "_DEBUG"
        ">"
        "$<$<CONFIG:Release>:"
            "NDEBUG"
        ">"
        "_CRT_SECURE_NO_DEPRECATE;"
        "WIN32;"
        "_MBCS"
    )
elseif("${CMAKE_VS_PLATFORM_NAME}" STREQUAL "x64")
    target_compile_definitions(${PROJECT_NAME} PRIVATE
        "$<$<CONFIG:Debug>:"
            "_DEBUG"
        ">"
        "$<$<CONFIG:Release>:"
            "NDEBUG"
        ">"
        "_CRT_SECURE_NO_DEPRECATE;"
        "_WIN64;"
        "__WIN64__;"
        "WIN32;"
        "_MBCS"
    )
endif()

################################################################################
# Compile and link options
################################################################################
if(MSVC)
    if("${CMAKE_VS_PLATFORM_NAME}" STREQUAL "Win32")
        target_compile_options(${PROJECT_NAME} PRIVATE
            $<$<CONFIG:Debug>:
                /Od;
                ${DEFAULT_CXX_DEBUG_RUNTIME_LIBRARY};
                /ZI
            >
            $<$<CONFIG:Release>:
                /Gm-;
                /Ox;
                /Oi;
                /GF;
                ${DEFAULT_CXX_RUNTIME_LIBRARY};
                /Gy;
                ${DEFAULT_CXX_DEBUG_INFORMATION_FORMAT}
            >
            /W3;
            /wd"4273";
            ${DEFAULT_CXX_EXCEPTION_HANDLING};
            /Y-
        )
    elseif("${CMAKE_VS_PLATFORM_NAME}" STREQUAL "x64")
        target_compile_options(${PROJECT_NAME} PRIVATE
            $<$<CONFIG:Debug>:
                /Od;
                ${DEFAULT_CXX_DEBUG_RUNTIME_LIBRARY};
                /ZI
            >
            $<$<CONFIG:Release>:
                /Gm-;
                /Ox;
                /Oi;
                /GF;
                ${DEFAULT_CXX_RUNTIME_LIBRARY};
                /Gy;
                ${DEFAULT_CXX_DEBUG_INFORMATION_FORMAT}
            >
            /W3;
            /wd"4273";
            ${DEFAULT_CXX_EXCEPTION_HANDLING};
            /Y-
        )
    endif()
    if("${CMAKE_VS_PLATFORM_NAME}" STREQUAL "Win32")
        target_link_options(${PROJECT_NAME} PRIVATE
            $<$<CONFIG:Debug>:
                /DEBUG;
                /INCREMENTAL
            >
            $<$<CONFIG:Release>:
                /DEBUG:FULL;
                /OPT:REF;
                /OPT:ICF;
                /INCREMENTAL:NO
            >
            /SUBSYSTEM:CONSOLE
        )
    elseif("${CMAKE_VS_PLATFORM_NAME}" STREQUAL "x64")
        target_link_options(${PROJECT_NAME} PRIVATE
            $<$<CONFIG:Debug>:
                /DEBUG;
                /INCREMENTAL
            >
            $<$<CONFIG:Release>:
                /DEBUG:FULL;
                /OPT:REF;
                /OPT:ICF;
                /INCREMENTAL:NO
            >
            /SUBSYSTEM:CONSOLE
        )
    endif()
endif()



























project(q3cpp C)

################################################################################
# Source groups
################################################################################
set(Headers
    "../../../ioq3/code/tools/lcc/cpp/cpp.h"
)
source_group("Headers" FILES ${Headers})

set(Sources
    "../../../ioq3/code/tools/lcc/cpp/cpp.c"
    "../../../ioq3/code/tools/lcc/cpp/eval.c"
    "../../../ioq3/code/tools/lcc/cpp/getopt.c"
    "../../../ioq3/code/tools/lcc/cpp/hideset.c"
    "../../../ioq3/code/tools/lcc/cpp/include.c"
    "../../../ioq3/code/tools/lcc/cpp/lex.c"
    "../../../ioq3/code/tools/lcc/cpp/macro.c"
    "../../../ioq3/code/tools/lcc/cpp/nlist.c"
    "../../../ioq3/code/tools/lcc/cpp/tokens.c"
    "../../../ioq3/code/tools/lcc/cpp/unix.c"
)
source_group("Sources" FILES ${Sources})

set(ALL_FILES
    ${Headers}
    ${Sources}
)

################################################################################
# Target
################################################################################
add_executable(${PROJECT_NAME} ${ALL_FILES})
set_target_properties(${PROJECT_NAME} PROPERTIES FOLDER "tool")

use_props(${PROJECT_NAME} "${CMAKE_CONFIGURATION_TYPES}" "${DEFAULT_CXX_PROPS}")
set(ROOT_NAMESPACE q3cpp)

set_target_properties(${PROJECT_NAME} PROPERTIES
    VS_GLOBAL_KEYWORD "Win32Proj"
)
################################################################################
# Target name
################################################################################
if("${CMAKE_VS_PLATFORM_NAME}" STREQUAL "Win32")
    set_target_properties(${PROJECT_NAME} PROPERTIES
        TARGET_NAME_DEBUG   "q3cpp"
        TARGET_NAME_RELEASE "q3cpp"
    )
elseif("${CMAKE_VS_PLATFORM_NAME}" STREQUAL "x64")
    set_target_properties(${PROJECT_NAME} PROPERTIES
        TARGET_NAME_DEBUG   "q3cpp"
        TARGET_NAME_RELEASE "q3cpp"
    )
endif()
################################################################################
# Output directory
################################################################################
if("${CMAKE_VS_PLATFORM_NAME}" STREQUAL "Win32")
    set_target_properties(${PROJECT_NAME} PROPERTIES
        OUTPUT_DIRECTORY_DEBUG   "${CMAKE_CURRENT_SOURCE_DIR}/bin_x86_debug/"
        OUTPUT_DIRECTORY_RELEASE "${CMAKE_CURRENT_SOURCE_DIR}/bin_x86/"
    )
elseif("${CMAKE_VS_PLATFORM_NAME}" STREQUAL "x64")
    set_target_properties(${PROJECT_NAME} PROPERTIES
        OUTPUT_DIRECTORY_DEBUG   "${CMAKE_CURRENT_SOURCE_DIR}/bin_x64_debug/"
        OUTPUT_DIRECTORY_RELEASE "${CMAKE_CURRENT_SOURCE_DIR}/bin_x64/"
    )
endif()
################################################################################
# Compile definitions
################################################################################
if("${CMAKE_VS_PLATFORM_NAME}" STREQUAL "Win32")
    target_compile_definitions(${PROJECT_NAME} PRIVATE
        "$<$<CONFIG:Debug>:"
            "_DEBUG"
        ">"
        "$<$<CONFIG:Release>:"
            "NDEBUG"
        ">"
        "_CRT_SECURE_NO_DEPRECATE;"
        "WIN32;"
        "_MBCS"
    )
elseif("${CMAKE_VS_PLATFORM_NAME}" STREQUAL "x64")
    target_compile_definitions(${PROJECT_NAME} PRIVATE
        "$<$<CONFIG:Debug>:"
            "_DEBUG"
        ">"
        "$<$<CONFIG:Release>:"
            "NDEBUG"
        ">"
        "_CRT_SECURE_NO_DEPRECATE;"
        "_WIN64;"
        "__WIN64__;"
        "WIN32;"
        "_MBCS"
    )
endif()

################################################################################
# Compile and link options
################################################################################
if(MSVC)
    if("${CMAKE_VS_PLATFORM_NAME}" STREQUAL "Win32")
        target_compile_options(${PROJECT_NAME} PRIVATE
            $<$<CONFIG:Debug>:
                /Od;
                ${DEFAULT_CXX_DEBUG_RUNTIME_LIBRARY};
                /ZI
            >
            $<$<CONFIG:Release>:
                /Gm-;
                /Ox;
                /Oi;
                /GF;
                ${DEFAULT_CXX_RUNTIME_LIBRARY};
                /Gy;
                ${DEFAULT_CXX_DEBUG_INFORMATION_FORMAT}
            >
            /W3;
            /wd"4018";
            /wd"4996";
            ${DEFAULT_CXX_EXCEPTION_HANDLING};
            /Y-
        )
    elseif("${CMAKE_VS_PLATFORM_NAME}" STREQUAL "x64")
        target_compile_options(${PROJECT_NAME} PRIVATE
            $<$<CONFIG:Debug>:
                /Od;
                ${DEFAULT_CXX_DEBUG_RUNTIME_LIBRARY};
                /ZI
            >
            $<$<CONFIG:Release>:
                /Gm-;
                /Ox;
                /Oi;
                /GF;
                ${DEFAULT_CXX_RUNTIME_LIBRARY};
                /Gy;
                ${DEFAULT_CXX_DEBUG_INFORMATION_FORMAT}
            >
            /W3;
            /wd"4018";
            /wd"4996";
            ${DEFAULT_CXX_EXCEPTION_HANDLING};
            /Y-
        )
    endif()
    if("${CMAKE_VS_PLATFORM_NAME}" STREQUAL "Win32")
        target_link_options(${PROJECT_NAME} PRIVATE
            $<$<CONFIG:Debug>:
                /DEBUG;
                /INCREMENTAL
            >
            $<$<CONFIG:Release>:
                /DEBUG:FULL;
                /OPT:REF;
                /OPT:ICF;
                /INCREMENTAL:NO
            >
            /SUBSYSTEM:CONSOLE
        )
    elseif("${CMAKE_VS_PLATFORM_NAME}" STREQUAL "x64")
        target_link_options(${PROJECT_NAME} PRIVATE
            $<$<CONFIG:Debug>:
                /DEBUG;
                /INCREMENTAL
            >
            $<$<CONFIG:Release>:
                /DEBUG:FULL;
                /OPT:REF;
                /OPT:ICF;
                /INCREMENTAL:NO
            >
            /SUBSYSTEM:CONSOLE
        )
    endif()
endif()



























project(q3rcc C)

################################################################################
# Source groups
################################################################################
set(no_group_source_files
    "../../../ioq3/code/tools/lcc/src/alloc.c"
    "../../../ioq3/code/tools/lcc/src/bind.c"
    "../../../ioq3/code/tools/lcc/src/bytecode.c"
    "../../../ioq3/code/tools/lcc/src/c.h"
    "../../../ioq3/code/tools/lcc/src/config.h"
    "../../../ioq3/code/tools/lcc/src/dag.c"
    "../../../ioq3/code/tools/lcc/src/decl.c"
    "../../../ioq3/code/tools/lcc/src/enode.c"
    "../../../ioq3/code/tools/lcc/src/error.c"
    "../../../ioq3/code/tools/lcc/src/event.c"
    "../../../ioq3/code/tools/lcc/src/expr.c"
    "../../../ioq3/code/tools/lcc/src/gen.c"
    "../../../ioq3/code/tools/lcc/src/init.c"
    "../../../ioq3/code/tools/lcc/src/inits.c"
    "../../../ioq3/code/tools/lcc/src/input.c"
    "../../../ioq3/code/tools/lcc/src/lex.c"
    "../../../ioq3/code/tools/lcc/src/list.c"
    "../../../ioq3/code/tools/lcc/src/main.c"
    "../../../ioq3/code/tools/lcc/src/null.c"
    "../../../ioq3/code/tools/lcc/src/output.c"
    "../../../ioq3/code/tools/lcc/src/prof.c"
    "../../../ioq3/code/tools/lcc/src/profio.c"
    "../../../ioq3/code/tools/lcc/src/simp.c"
    "../../../ioq3/code/tools/lcc/src/stmt.c"
    "../../../ioq3/code/tools/lcc/src/string.c"
    "../../../ioq3/code/tools/lcc/src/sym.c"
    "../../../ioq3/code/tools/lcc/src/symbolic.c"
    "../../../ioq3/code/tools/lcc/src/token.h"
    "../../../ioq3/code/tools/lcc/src/trace.c"
    "../../../ioq3/code/tools/lcc/src/tree.c"
    "../../../ioq3/code/tools/lcc/src/types.c"
)
source_group("" FILES ${no_group_source_files})

set(dynamic
    "dynamic/dagcheck.c"
)
source_group("dynamic" FILES ${dynamic})

set(ALL_FILES
    ${no_group_source_files}
    ${dynamic}
)

################################################################################
# Target
################################################################################
add_executable(${PROJECT_NAME} ${ALL_FILES})
set_target_properties(${PROJECT_NAME} PROPERTIES FOLDER "tool")

use_props(${PROJECT_NAME} "${CMAKE_CONFIGURATION_TYPES}" "${DEFAULT_CXX_PROPS}")
set(ROOT_NAMESPACE q3rcc)

set_target_properties(${PROJECT_NAME} PROPERTIES
    VS_GLOBAL_KEYWORD "Win32Proj"
)
################################################################################
# Target name
################################################################################
if("${CMAKE_VS_PLATFORM_NAME}" STREQUAL "Win32")
    set_target_properties(${PROJECT_NAME} PROPERTIES
        TARGET_NAME_DEBUG   "q3rcc"
        TARGET_NAME_RELEASE "q3rcc"
    )
elseif("${CMAKE_VS_PLATFORM_NAME}" STREQUAL "x64")
    set_target_properties(${PROJECT_NAME} PROPERTIES
        TARGET_NAME_DEBUG   "q3rcc"
        TARGET_NAME_RELEASE "q3rcc"
    )
endif()
################################################################################
# Output directory
################################################################################
if("${CMAKE_VS_PLATFORM_NAME}" STREQUAL "Win32")
    set_target_properties(${PROJECT_NAME} PROPERTIES
        OUTPUT_DIRECTORY_DEBUG   "${CMAKE_CURRENT_SOURCE_DIR}/bin_x86_debug/"
        OUTPUT_DIRECTORY_RELEASE "${CMAKE_CURRENT_SOURCE_DIR}/bin_x86/"
    )
elseif("${CMAKE_VS_PLATFORM_NAME}" STREQUAL "x64")
    set_target_properties(${PROJECT_NAME} PROPERTIES
        OUTPUT_DIRECTORY_DEBUG   "${CMAKE_CURRENT_SOURCE_DIR}/bin_x64_debug/"
        OUTPUT_DIRECTORY_RELEASE "${CMAKE_CURRENT_SOURCE_DIR}/bin_x64/"
    )
endif()
################################################################################
# Include directories
################################################################################
if("${CMAKE_VS_PLATFORM_NAME}" STREQUAL "Win32")
    target_include_directories(${PROJECT_NAME} PUBLIC
        "${CMAKE_CURRENT_SOURCE_DIR}/../../../ioq3/code/tools/lcc/src"
    )
elseif("${CMAKE_VS_PLATFORM_NAME}" STREQUAL "x64")
    target_include_directories(${PROJECT_NAME} PUBLIC
        "${CMAKE_CURRENT_SOURCE_DIR}/../../../ioq3/code/tools/lcc/src"
    )
endif()

################################################################################
# Compile definitions
################################################################################
if("${CMAKE_VS_PLATFORM_NAME}" STREQUAL "Win32")
    target_compile_definitions(${PROJECT_NAME} PRIVATE
        "$<$<CONFIG:Debug>:"
            "_DEBUG"
        ">"
        "$<$<CONFIG:Release>:"
            "NDEBUG"
        ">"
        "_CRT_SECURE_NO_DEPRECATE;"
        "WIN32;"
        "_MBCS"
    )
elseif("${CMAKE_VS_PLATFORM_NAME}" STREQUAL "x64")
    target_compile_definitions(${PROJECT_NAME} PRIVATE
        "$<$<CONFIG:Debug>:"
            "_DEBUG"
        ">"
        "$<$<CONFIG:Release>:"
            "NDEBUG"
        ">"
        "_CRT_SECURE_NO_DEPRECATE;"
        "_WIN64;"
        "__WIN64__;"
        "WIN32;"
        "_MBCS"
    )
endif()

################################################################################
# Compile and link options
################################################################################
if(MSVC)
    if("${CMAKE_VS_PLATFORM_NAME}" STREQUAL "Win32")
        target_compile_options(${PROJECT_NAME} PRIVATE
            $<$<CONFIG:Debug>:
                /Od;
                ${DEFAULT_CXX_DEBUG_RUNTIME_LIBRARY};
                /ZI
            >
            $<$<CONFIG:Release>:
                /Gm-;
                /Ox;
                /Oi;
                /GF;
                ${DEFAULT_CXX_RUNTIME_LIBRARY};
                /Gy;
                ${DEFAULT_CXX_DEBUG_INFORMATION_FORMAT}
            >
            /W3;
            /wd"4018";
            /wd"4244";
            ${DEFAULT_CXX_EXCEPTION_HANDLING};
            /Y-
        )
    elseif("${CMAKE_VS_PLATFORM_NAME}" STREQUAL "x64")
        target_compile_options(${PROJECT_NAME} PRIVATE
            $<$<CONFIG:Debug>:
                /Od;
                ${DEFAULT_CXX_DEBUG_RUNTIME_LIBRARY};
                /ZI
            >
            $<$<CONFIG:Release>:
                /Gm-;
                /Ox;
                /Oi;
                /GF;
                ${DEFAULT_CXX_RUNTIME_LIBRARY};
                /Gy;
                ${DEFAULT_CXX_DEBUG_INFORMATION_FORMAT}
            >
            /W3;
            /wd"4018";
            /wd"4244";
            ${DEFAULT_CXX_EXCEPTION_HANDLING};
            /Y-
        )
    endif()
    if("${CMAKE_VS_PLATFORM_NAME}" STREQUAL "Win32")
        target_link_options(${PROJECT_NAME} PRIVATE
            $<$<CONFIG:Debug>:
                /DEBUG;
                /INCREMENTAL
            >
            $<$<CONFIG:Release>:
                /DEBUG:FULL;
                /OPT:REF;
                /OPT:ICF;
                /INCREMENTAL:NO
            >
            /SUBSYSTEM:CONSOLE
        )
    elseif("${CMAKE_VS_PLATFORM_NAME}" STREQUAL "x64")
        target_link_options(${PROJECT_NAME} PRIVATE
            $<$<CONFIG:Debug>:
                /DEBUG;
                /INCREMENTAL
            >
            $<$<CONFIG:Release>:
                /DEBUG:FULL;
                /OPT:REF;
                /OPT:ICF;
                /INCREMENTAL:NO
            >
            /SUBSYSTEM:CONSOLE
        )
    endif()
endif()

################################################################################
# Dependencies
################################################################################
add_dependencies(${PROJECT_NAME}
    lburg
)

# Link with other targets.
target_link_libraries(${PROJECT_NAME} PUBLIC
    lburg
)

