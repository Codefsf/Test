#include <iostream>
#include <vector>
#include <algorithm>
#include <memory>

#include "leveldb/db.h"
#include "leveldb/env.h"

int main( void )
{
    //打开数据库
    leveldb::DB* db = nullptr;
    leveldb::Options options;
    options.create_if_missing = true;
    leveldb::Status status = leveldb::DB::Open(options, "./testdb", &db);

    //读写数据库
    std::string value1 = "testvalue1";
    std::string value2 = "testvalue2";
    std::string value3 = "testvalue3";

    status = db->Put(leveldb::WriteOptions(), "key1", value1);
    status = db->Put(leveldb::WriteOptions(), "key2", value2);
    status = db->Put(leveldb::WriteOptions(), "key3", value3);


    leveldb::Iterator* it = db->NewIterator(leveldb::ReadOptions());
    for (it->SeekToFirst(); it->Valid(); it->Next()) {
        std::cout << it->key().ToString() << ": "  << it->value().ToString() << std::endl;
    }
    delete it;
    //关闭数据库
    delete db;

    return 0;
}