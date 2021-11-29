#include <iostream>
#include <vector>
#include <algorithm>
#include <memory>

#include "leveldb/db.h"
#include "leveldb/env.h"

int main( void )
{
    leveldb::DB* db = nullptr;
    leveldb::Options options;
    options.create_if_missing = true;
    leveldb::Status status = leveldb::DB::Open(options, "/tmp/testdb", &db);

    return 0;
}