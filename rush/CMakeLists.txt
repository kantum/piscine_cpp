cmake_minimum_required(VERSION 3.14)
project(cppr00)

set(CMAKE_CXX_STANDARD 98)

add_executable(cppr00 main.cpp Game.cpp Game.hpp Character.cpp Character.hpp Player.cpp Player.hpp Enemy.cpp Enemy.hpp Projectile.cpp Projectile.hpp Menu.cpp Menu.hpp)