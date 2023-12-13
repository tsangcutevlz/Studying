cmake_minimum_required(VERSION 3.27.9)

project(SFMLProject)

# Thêm đường dẫn include của SFML
include_directories("/opt/homebrew/Cellar/sfml/2.6.1/include")

# Tìm và load các thành phần của SFML
find_package(SFML 2.6.1 COMPONENTS graphics audio REQUIRED)

# Thêm thư viện SFML vào dự án
add_executable(${PROJECT_NAME} math.cpp player.cpp skeleton.cpp main.cpp )

# Liên kết các thư viện SFML
target_link_libraries(${PROJECT_NAME} sfml-graphics sfml-audio)


# In ra đường dẫn include của SFML để kiểm tra
message(STATUS "SFML_INCLUDE_DIR: ${SFML_INCLUDE_DIR}")

set(CMAKE_OSX_ARCHITECTURES "arm64")

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -Wno-c++11-extensions")


# In ra các thư viện được liên kết để kiểm tra
message(STATUS "SFML_LIBRARIES: ${SFML_LIBRARIES}")

# In ra các biến cmake của SFML để kiểm tra
message(STATUS "SFML_FOUND: ${SFML_FOUND}")
message(STATUS "SFML_VERSION: ${SFML_VERSION}")
