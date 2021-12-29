cmake_minimum_required(VERSION 3.0) 

aux_source_directory(. DIR_LIB_SRCS)

set(LIBRARY_OUTPUT_PATH ${PROJECT_SOURCE_DIR}/lib)

add_library(TimeWheel STATIC ${DIR_LIB_SRCS})
