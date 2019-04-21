cmake_minimum_required(VERSION 3.0)

add_compile_options(-fPIE -fstack-protector-all -D_FORTIFY_SOURCE=2 -Wall -Wextra -DUNICODE)
link_libraries(-static -fstack-protector)

IF (WIN32)
    add_compile_options("-Wl,dynamicbase" "-Wl,nxcompat" -DUNICODE -DWIN32 -mwindows)
    link_libraries(-mwindows)
ELSE()
    link_libraries("-Wl,-z,now" "-Wl,-z,relro")
ENDIF()

add_executable(critical_success main.c mt19937.c)