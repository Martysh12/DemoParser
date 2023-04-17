set(SOURCES
    main.cpp
)

add_executable(demoparse ${SOURCES})

target_include_directories(demoparse PRIVATE "${DemoParser_SOURCE_DIR}/include")
