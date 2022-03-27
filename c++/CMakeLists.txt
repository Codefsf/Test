project(test_demo)
set(PROJECT_NAME test_demo)

cmake_minimum_required(VERSION 3.9)

# remove compiler checks if you are using VS2010, it supports
#   1. auto
#   2. lambda
#   3. const iterator
# and, sadly, it doesn't support `for(item, cotainer)'
include( CheckCXXCompilerFlag )
check_cxx_compiler_flag( "-std=c++11"   COMPILER_SUPPORTS_CXX11 )
check_cxx_compiler_flag( "-std=c++0x"   COMPILER_SUPPORTS_CXX0X )
if( COMPILER_SUPPORTS_CXX11 )
    if( CMAKE_COMPILER_IS_GNUCXX )
        set( CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=gnu++11" )
    else()
        set( CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11" )
    endif()
elseif( COMPILER_SUPPORTS_CXX0X)
    set( CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++0x" )
else()
    # MSVC, On by default (if available)
endif()

#不同平台条件编译
if(WIN32)
    message("os:win32")
elseif(ANDROID)
    message("os:android")
elseif(IOS)
    message("os:ios")
endif()

#依赖包含目录
include_directories(
    ${PROJECT_SOURCE_DIR}/incoming/leveldb/include
)

#添加文件
FILE(GLOB global
    *.h
    *.cpp
)
source_group("" FILES ${global})

set(ALL_SOURCE_FILES
    ${global}
)

#生成目标文件
add_executable(${PROJECT_NAME} ${ALL_SOURCE_FILES})

#外部依赖库目录
target_link_directories(${PROJECT_NAME} PRIVATE
    # "${PROJECT_SOURCE_DIR}/incoming/leveldb/build/$<CONFIG>/"
)

#外部依赖库
target_link_libraries(${PROJECT_NAME} PRIVATE
    # leveldb
    pthread
)