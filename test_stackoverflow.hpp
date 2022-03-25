#include <iostream>

void TestStackoverflow()
{
    char c[1024 * 1024 * 8 + 111] = {2};
}