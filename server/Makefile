CXX = g++ 
# "-I" để chỉ đường dẫn đến thư viện 
CXXFLAGS = -Wall -std=c++11 -I/model -I/controller  -I../client/model

# Danh sách file nguồn
SRC_DIR = .
MODEL_DIR = model
CONTROLLER_DIR = controller


SRC = $(SRC_DIR)/main.cpp \
      $(MODEL_DIR)/ConnectionService.cpp \
      $(MODEL_DIR)/MessageService.cpp \
      $(MODEL_DIR)/GroupChat.cpp \
      $(MODEL_DIR)/Client.cpp \
      $(CONTROLLER_DIR)/ServiceManager.cpp \
      $(CONTROLLER_DIR)/ClientManager.cpp \
      $(CONTROLLER_DIR)/GroupManager.cpp

OBJ = $(SRC:.cpp=.o)


TARGET = main

all: $(TARGET)

$(TARGET): $(OBJ)
	$(CXX) $(OBJ) -o $(TARGET)

%.o: %.cpp
	$(CXX) $(CXXFLAGS) -c $< -o $@

clean:
	rm -f $(OBJ) $(TARGET)
