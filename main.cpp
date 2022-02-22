#include <iostream>
#include <vector>
#include <algorithm>
#include <memory>
#include <chrono>
#include <fstream>
#include <time.h>
#include <io.h>

#include "leveldb/db.h"
#include "leveldb/env.h"

int main( void )
{
    //打开数据库
    // leveldb::DB* db = nullptr;
    // leveldb::Options options;
    // options.create_if_missing = true;
    // leveldb::Status status = leveldb::DB::Open(options, "./testdb", &db);

    // int i = 0;

    // int64_t start_time = time(0);
    // std::cout << "start:" << start_time << std::endl;

    // std::string image_dir = "./thumbimage/*.png";
    // long handle = 0;
    // _finddata_t file_info;
    // handle = _findfirst(image_dir.c_str(), &file_info);
    // if (handle == -1)
    // {
    //     return -1;
    // }

    // do
    // {
    //     std::string image_data;
    //     std::ifstream read_file;

    //     std::string file_path = std::string("./thumbimage/").append(file_info.name);
    //     read_file.open(file_path, std::ios_base::binary);

    //     image_data.reserve(file_info.size);
    //     read_file.read(const_cast<char*>(image_data.c_str()), file_info.size);
    //     read_file.close();

    //     std::cout << "file_info: " << std::to_string(i) << " " << file_info.name << file_info.size << " " << std::to_string(image_data.size()) 
    //     << " pa" << file_path << std::endl;

    //     db->Put(leveldb::WriteOptions(), std::to_string(i++), image_data);
    // } while(!_findnext(handle, &file_info));
    
    // _findclose(handle);
    
    // int64_t end_time = time(0);
    // std::cout << "end:" << end_time << std::endl;
    // std::cout << "use time:" << end_time - start_time << std::endl;
    // //关闭数据库
    // delete db;

    return 0;
}