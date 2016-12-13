SRC = src
INC = include
OBJ = obj
BIN = bin
LIB = lib

CXX = g++
AR = ar
CCFLAGS = -Wall -pedantic -g -std=c++11
LDFLAGS = -L./$(LIB)
LDLIBS = -levent
IFLAGS = -I
LIBFLAGS = rvs

SOURCESMAIN = $(SRC)/pruebacronologia.cpp
SOURCESLIB= $(SRC)/chronology.cpp $(SRC)/historic_event.cpp
OBJECTS = $(SOURCESMAIN:$(SRC)/%.cpp=$(OBJ)/%.o) $(SOURCESLIB:$(SRC)/%.cpp=$(OBJ)/%.o)
EXECUTABLES = $(SOURCESMAIN:$(SRC)/%.cpp=$(BIN)/% )
LIBNAME = $(LIB)/libevent.a

all:  $(OBJECTS) $(EXECUTABLES)
# ************ Generación de documentación ******************
documentacion:
	doxygen doc/doxys/Doxyfile


# ************ Compilación de módulos ************

$(BIN)/% : $(OBJ)/%.o $(LIBNAME)
	$(CXX) $(CCFLAGS) $(IFLAGS) ./$(INC) -o $@ $^ $(LDFLAGS) $(LDLIBS)

$(LIBNAME) : $(SOURCESLIB:$(SRC)/%.cpp=$(OBJ)/%.o)  $(SOURCESLIB:$(SRC)/%.cpp=$(INC)/%.hpp)
	$(AR) $(LIBFLAGS) $(LIBNAME) $(SOURCESLIB:$(SRC)/%.cpp=$(OBJ)/%.o)

$(OBJ)/%.o : $(SRC)/%.cpp
	$(CXX) $(CCFLAGS) $(IFLAGS) $(INC) -c $^ -o $@




# ************ Limpieza ************
clean :
	-rm $(OBJ)/* $(SRC)/*~ $(INC)/*~ ./*~ $(LIB)/*

mrproper : clean
	-rm $(BIN)/* doc/html/*
