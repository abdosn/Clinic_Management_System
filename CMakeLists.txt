cmake_minimum_required(VERSION 3.18)

set(MYPROJECT Clinic_Management_System)

set(SRC_FILES
    main.c
)

project(${MYPROJECT})

add_subdirectory(${CMAKE_SOURCE_DIR}/PatientRecords)

add_executable(${MYPROJECT} ${SRC_FILES})

target_link_libraries(${MYPROJECT} PUBLIC PatientRecords)