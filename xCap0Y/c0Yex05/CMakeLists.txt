cmake_minimum_required(VERSION 3.16)

# Nome do projeto
project(c0Yex05)

# Especifica o padrão do C++
set(CMAKE_CXX_STANDARD 23)
set(CMAKE_CXX_STANDARD_REQUIRED True)

# Define compilador e biblioteca padrão C++
set(CMAKE_CXX_COMPILER "clang++")
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -stdlib=libc++")
set(CMAKE_EXE_LINKER_FLAGS "${CMAKE_EXE_LINKER_FLAGS} -stdlib=libc++")

# Adiciona os arquivos de código-fonte
add_executable(c0Yex05 src/main.cpp src/utils.cpp)

# Inclui o diretório de cabeçalhos
target_include_directories(c0Yex05 PRIVATE ${CMAKE_CURRENT_SOURCE_DIR}/src)
