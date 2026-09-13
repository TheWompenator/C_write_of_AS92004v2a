#include <stdio.h>
#include <stdlib.h>
#include <stdarg.h>
#include <string.h>
#include <cJSON/cJSON.h>
#include <validation/validation.h>
#include <lua/lua.h>
#include <lua/lauxlib.h>
#include <lua/lualib.h>

char OPENING_LUA_FILE[] = PROJECT_DIR "/data/core/defaults/main.lua";

int call_injectable (lua_State* L, char function[128]) {
    lua_getglobal (L, function);

    if (!lua_isfunction (L, -1)) {

        return 1;
    }

    if (lua_pcall(L, 0, 1, 0) != LUA_OK) {
        fprintf(stderr, "Lua error: %s\n", lua_tostring(L, -1));
        lua_pop(L, 1);
        return 1;
    }
    return 0;
}

int main(void) {
    lua_State *L = luaL_newstate();
    luaL_openlibs(L);

    int error = luaL_dofile(L, OPENING_LUA_FILE);

    if (error) {
        fprintf(stderr, "%s", lua_tostring(L, -1));
        lua_pop(L, 1);  /* pop error message from the stack */
    }

    call_injectable(L, "ASINJECT_begin_quiz");

    lua_close(L);

    return 0;
}

void error (lua_State *L, const char *fmt, ...) {
    va_list argp;
    va_start(argp, fmt);
    vfprintf(stderr, fmt, argp);
    va_end(argp);
    lua_close(L);
    exit(EXIT_FAILURE);
}
