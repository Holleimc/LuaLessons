include_directories(${PROJECT_SOURCE_DIR}/timewheel)

set(EXECUTABLE_OUTPUT_PATH ${PROJECT_SOURCE_DIR}/bin)

aux_source_directory(./ DIR_SRCS)

add_executable(main ${DIR_SRCS})

target_link_libraries(main TimeWheel)
