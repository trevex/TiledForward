CPP_FILES := $(wildcard src/*.cpp)
OBJ_FILES := $(addprefix obj/,$(notdir $(CPP_FILES:.cpp=.o)))

ifneq "$(findstring win, $(MAKECMDGOALS))" ""
LD_FLAGS := -static-libstdc++ -static-libgcc -lglfw -lopengl32 -lglu32
CC_FLAGS := -g
CC := x86_64-w64-mingw32-g++
EXECUTABLE := procedural.exe
else
LD_FLAGS := -lglfw -lGLU
CC_FLAGS := -g 
CC := g++
EXECUTABLE := procedural
endif

unix: $(EXECUTABLE)

win: clean $(EXECUTABLE)

$(EXECUTABLE): $(OBJ_FILES)
	$(CC) -o $@ $^ $(LD_FLAGS) 

obj/%.o: src/%.cpp
	$(CC) $(CC_FLAGS) -c -o $@ $<

clean:
	-rm $(EXECUTABLE) $(OBJ_FILES)