cmake_minimum_required(VERSION 3.22.3)
project(Practical_2)

set(CMAKE_CXX_STANDARD 11)

add_executable(Practical_2 main.cpp Enemy.cpp Enemy.h SquadMember.cpp SquadMember.h Snake.cpp Snake.h Jaguar.cpp Jaguar.h Gorilla.cpp Gorilla.h Cannibal.cpp Cannibal.h EnemyFactory.cpp EnemyFactory.h SnakeFactory.cpp SnakeFactory.h JaguarFactory.cpp JaguarFactory.h GorillaFactory.cpp GorillaFactory.h CannibalFactory.cpp CannibalFactory.h Commander.cpp Commander.h Mercenary.cpp Mercenary.h Soldier.cpp Soldier.h EnemyState.cpp EnemyState.h GameMemento.cpp GameMemento.h GameStore.cpp GameStore.h SquadMemberState.cpp SquadMemberState.h GameState.cpp GameState.h)
