#pragma once

#include <string>

#ifdef FUNC_EXPORTS
#define FUNC_API __declspec(dllexport)
#else
#define FUNC_API __declspec(dllimport)
#endif

#ifdef __cplusplus
extern "C" {
#endif

    int FUNC_API implementation(std::string str, char c);

#ifdef __cplusplus
}
#endif