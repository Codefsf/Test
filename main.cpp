#include <iostream>

#include "test_memory.hpp"
#include "test_mutex.hpp"
#include "test_leveldb.hpp"

using namespace std;

int main( void )
{
    //TestMemory();
    
    TestMutex();

    return 0;
}