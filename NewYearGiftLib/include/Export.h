#pragma once

#ifdef _WIN32
    #ifdef NEWYEARGIFTLIB_EXPORTS
        #define NEWYEAR_GIFT_API __declspec(dllexport)
    #else
        #define NEWYEAR_GIFT_API __declspec(dllimport)
    #endif
#else
    #define NEWYEAR_GIFT_API
#endif