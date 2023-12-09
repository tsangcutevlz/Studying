cmake_minimum_required(VERSION 3.5)

project(SFMLProject)

# Thêm đường dẫn include của SFML
include_directories("/opt/homebrew/Cellar/sfml/2.6.1/include")

# Tìm và load các thành phần của SFML
find_package(SFML 2.6.1 COMPONENTS graphics audio REQUIRED)

# Thêm thư viện SFML vào dự án
add_executable(${PROJECT_NAME} main.cpp)

# Liên kết các thư viện SFML
target_link_libraries(${PROJECT_NAME} sfml-graphics sfml-audio)

message(STATUS "SFML_INCLUDE_DIR: ${SFML_INCLUDE_DIR}")
