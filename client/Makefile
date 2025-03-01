CXX = g++
# "-I" để chỉ đường dẫn đến thư viện 
CXXFLAGS = -Wall -std=c++11 -I/model -I/controller

# Danh sách file nguồn
SRC = main.cpp model/User.cpp model/Connection.cpp controller/ConnectionController.cpp  controller/MessageController.cpp model/Messenger.cpp
OBJ = $(SRC:.cpp=.o)

TARGET = main

all: $(TARGET)

$(TARGET): $(OBJ)
	$(CXX) $(OBJ) -o $(TARGET)

%.o: %.cpp
	$(CXX) $(CXXFLAGS) -c $< -o $@

clean:
	rm -f $(OBJ) $(TARGET)
