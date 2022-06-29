gcc:
	g++ -O2 -Wall -Werror -Wextra -o main.o src/*.cpp

borland:
	bcc32 src/main.cpp src/utils.cpp src/venta.cpp src/vendedor.cpp
