cmake_minimum_required(VERSION 3.24)
project(OrganismSimulator)

set(CMAKE_CXX_STANDARD 17)

add_executable(OrganismSimulator OrganismSimulator.cpp Swiat.h Swiat.cpp Organizm.h Organizm.cpp
               Reporter.h Reporter.cpp Zwierze.h Zwierze.cpp Roslina.h Roslina.cpp
               Animals/Leniwiec.h Animals/Leniwiec.cpp Animals/Lis.h Animals/Lis.cpp
               Animals/Owca.h Animals/Owca.cpp Animals/Tygrys.h Animals/Tygrys.cpp
               Animals/Wilk.h Animals/Wilk.cpp Plants/Guarana.h Plants/Guarana.cpp
               Plants/Mlecz.h Plants/Mlecz.cpp Plants/Trawa.h Plants/Trawa.cpp)

