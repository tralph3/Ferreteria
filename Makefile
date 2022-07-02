SRCS:=$(wildcard src/*.cpp)

gcc:
	g++ -O2 -Wall -Werror -Wextra -o main.o $(SRCS)

borland:
	bcc32 src/main.cpp src/utils.cpp src/venta.cpp src/vendedor.cpp src/fecha.cpp
