##proto3dcube
##Copyright (C) 2024 Steven Philley

#OBJS defines files to compile as part of the project
OBJS = proto3dcube.cpp Video.cpp Input.cpp Cube.cpp Model.cpp \
       Transform.cpp Timer.cpp Renderable.cpp Clock.cpp ./src/ProgressBar.cpp\
	   ./src/Vec3.cpp
		

#OBJ_NAME name of executable
OBJ_NAME = proto3dcube 

#
all : $(OBJS)
	g++ $(OBJS) -w -lSDL2 -o $(OBJ_NAME)
