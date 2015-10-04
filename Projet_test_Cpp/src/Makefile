SRC= $(wildcard *.cpp)
# SRC= main.cpp 
HDR= $(INCLUDE_DIR)/$(wildcard *.hpp)
OBJ= $(SRC:.cpp=.o)

LOCAL_NAME=appli_test

# appli_test have all the depedencies in order to be testable here
# 
appli_test: $(OBJ) 
	$(CC) -o $@ $^ $(LDFLAGS)

# shopping_list only makes the executable for the shopping list file
shopping_list: shopping_list.o
	$(CC) -o $@ $< $(LDFLAGS)

shopping_list.o: shopping_list.cpp
	$(CC) $(CFLAGS) $(LIBS_FLAG) -o $@ -c $<

main.o: main.cpp
	$(CC) $(CFLAGS) $(LIBS_FLAG) -o $@ -c $<

clean:
	rm -rf *.o

mp: clean
	rm -rf $(LOCAL_NAME)
