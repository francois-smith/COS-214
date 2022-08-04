cmake_minimum_required(VERSION 3.22.3)
project(Practical_2)

set(CMAKE_CXX_STANDARD 11)

add_executable(Practical_2 main.cpp Enemy.cpp Enemy.h SquadMember.cpp SquadMember.h Snake.cpp Snake.h Jaguar.cpp Jaguar.h Gorilla.cpp Gorilla.h Cannibal.cpp Cannibal.h EnemyFactory.cpp EnemyFactory.h)
