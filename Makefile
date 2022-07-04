BIN_DIR=./bin
SRCS:=$(wildcard src/*.cpp)

gcc:
	if [ ! -d "$(BIN_DIR)" ]; then \
		mkdir -p $(BIN_DIR); \
	fi
	g++ -O2 -Wall -Werror -Wextra -o $(BIN_DIR)/main.o $(SRCS)

borland:
	bcc32 src/main.cpp src/utils.cpp src/sale.cpp src/seller.cpp src/date.cpp src/listings.cpp src/listing1.cpp src/listing2.cpp src/listing3.cpp
