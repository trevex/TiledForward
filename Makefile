CPP_FILES := $(wildcard src/*.cpp)
OBJ_FILES := $(addprefix obj/,$(notdir $(CPP_FILES:.cpp=.o)))

ifneq "$(findstring win, $(MAKECMDGOALS))" ""
LD_FLAGS := -static-libstdc++ -static-libgcc -static -lglew32 -lglfw -lopengl32 -lglu32
CC_FLAGS := -DGLEW_STATIC -std=c++0x
CC := x86_64-w64-mingw32-g++
EXECUTABLE := tiledforward.exe
else
LD_FLAGS := -lglfw -lGLU -lGLEW
CC_FLAGS := -g -std=c++11
CC := g++
EXECUTABLE := tiledforward
endif

unix: $(EXECUTABLE)

win: $(EXECUTABLE)

$(EXECUTABLE): $(OBJ_FILES)
	$(CC) -o $@ $^ $(LD_FLAGS) 

obj/%.o: src/%.cpp
	$(CC) $(CC_FLAGS) -c -o $@ $<

clean:
	-rm $(EXECUTABLE) $(EXECUTABLE).exe $(OBJ_FILES)