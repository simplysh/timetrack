app = timetrack

cat = $(if $(filter $(OS),Windows_NT),type,cat)
cp = $(if $(filter $(OS),Windows_NT),copy,cp)
version = $(shell $(cat) VERSION)

CXX = g++
EXTRAFLAGS = -DVERSION="\"$(version)\""
HEADERS = $(wildcard ./*.h)
OBJ = $(SRC:.cpp=.o)
SRC = $(wildcard ./*.cpp)

ifdef OS
	CXXFLAGS = -std=c++14 -static-libgcc -static-libstdc++ -pedantic-errors $(EXTRAFLAGS)
	DEST = $(shell echo %SYSTEMROOT%)
	OUT = .\$(app).exe
	RM = del /Q
else
	CXXFLAGS = -std=c++14 -pedantic-errors $(EXTRAFLAGS)
	DEST = /usr/local/bin
	OUT = ./$(app)
	RM = rm -f
endif

all: $(OUT)

# main target
$(OUT): $(OBJ)
	$(CXX) $(CXXFLAGS) -o $@ $^

# how to compile objects
./%.o: ./%.cpp ./%.h
	$(CXX) $(CXXFLAGS) -c -o $@ $<

clean:
	$(RM) $(OUT) *.o *.exe

install:
	@echo installing to $(DEST)
	$(cp) $(OUT) $(DEST)

.PHONY: clean
