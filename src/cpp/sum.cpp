#include <cstdio>
#include <cstdint>
#include <cstring>
#include <iostream>
#include <string>

extern "C" int64_t loop(int max)
{
    int i = max;
    int64_t result = 1;

    while (i >= 2)
    {
        result *= i--;
    }

    return result;
}

extern "C" int sum(int a, int b) { return a + b; }

extern "C" int substract(int a, int b) { return a - b; }

extern "C" double doubleSum(double a, double b) { return a + b; }

extern "C" const char *concatenateStrings(const char *str1, const char *str2)
{
    std::string result = std::string(str1) + std::string(str2);
    char *cstr = new char[result.length() + 1];
    strcpy(cstr, result.c_str());
    return cstr;
}

extern "C" void noRet() { printf("%s", "hello world"); }
extern "C" bool return_opposite(bool input) { return !input; }