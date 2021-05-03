enable_language(ASM_NASM)
set(CMAKE_ASM_NASM_COMPILE_OBJECT "<CMAKE_ASM_NASM_COMPILER> <INCLUDES> <FLAGS> -o <OBJECT> <SOURCE>")
set(CMAKE_ASM_NASM_LINK_EXECUTABLE "ld <CMAKE_ASM_NASM_LINK_FLAGS> <LINK_FLAGS> <OBJECTS>  -o <TARGET> <LINK_LIBRARIES>")
# set(CMAKE_ASM_NASM_SOURCE_FILE_EXTENSIONS ${CMAKE_ASM_NASM_SOURCE_FILE_EXTENSIONS} s S)
set(CMAKE_ASM_NASM_OBJECT_FORMAT macho64)



file(GLOB_RECURSE HEADER_LIST "${PROJECT_SOURCE_DIR}/include/${CMAKE_PROJECT_NAME}/*.hpp")
file(GLOB SOURCE_LIST ${PROJECT_SOURCE_DIR}/src/*.cpp)
file(GLOB ASSEMBLY_FILES ${PROJECT_SOURCE_DIR}/src/*.s ${PROJECT_SOURCE_DIR}/src/*.asm)




set (self ${PROJECT_NAME})

add_library (${self} STATIC 
${ASSEMBLY_FILES} ${SOURCE_LIST}  ${HEADER_LIST} 
)

foreach (file ${ASSEMBLY_FILES})
    set_source_files_properties(${file} PROPERTIES COMPILE_FLAGS "-x assembler-with-cpp")
    source_group(TREE ${CMAKE_CURRENT_LIST_DIR}
            PREFIX "sources"               
            FILES  ${file}
    )
endforeach ()

ph_IDE ()

ph_precompile (TARGET ${self} PUBLIC PCH ${std_pch})

add_library (ph::assembly ALIAS ${self})
# target_link_libraries (${self} PUBLIC ${Boost_LIBRARIES})
target_include_directories (${self} PUBLIC ${PROJECT_SOURCE_DIR}/include)
# target_include_directories (${self} PUBLIC ph::coroutines)
target_compile_features (${self} PUBLIC cxx_std_20)


target_include_directories(${self} PRIVATE
    $<BUILD_INTERFACE:${PROJECT_SOURCE_DIR}/include/${self}>
    $<INSTALL_INTERFACE:include/${self}>
)

target_include_directories(${self} PUBLIC
    $<BUILD_INTERFACE:${PROJECT_SOURCE_DIR}/include>
    $<INSTALL_INTERFACE:include>
)

if (CMAKE_PROJECT_NAME STREQUAL PROJECT_NAME)

else()
    set_target_properties(${PROJECT_NAME}          PROPERTIES FOLDER "dependencies/${PROJECT_NAME}")
endif()