#pragma once

#define LOG_NOTHING     0x0000000000000000
#define LOG_ALL         0xFFFFFFFFFFFFFFFF
#define LOG_DEBUG       0x0000000000000001
#define LOG_CELLS       0x0000000000000002
#define LOG_CLUSTERS    0x0000000000000004

#define LOG_LEVEL       LOG_ALL


#define LOG_HELPER(fmt, ...)    printf(fmt "\n%s", __VA_ARGS__)
#define LOG_ALWAYS(...)         LOG_HELPER(__VA_ARGS__, "")

#ifdef DEBUG
    #define LOG(lvl, ...)       (lvl & LOG_LEVEL) && LOG_HELPER(__VA_ARGS__, "")
#else
    #define LOG(lvl, ...)
#endif