cmake_minimum_required(VERSION 3.15)
project(CLIONPROYECT)

set(CMAKE_CXX_STANDARD 14)
find_package(SFML 2.5 COMPONENTS system window graphics)

add_executable(CLIONPROYECT main.cpp Particle.h Particle.cpp CollisionSystem.h CollisionSystem.cpp Event.h Event.cpp)
target_link_libraries(CLIONPROYECT sfml-system sfml-window sfml-graphics)