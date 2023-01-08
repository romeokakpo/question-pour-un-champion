CFLAGS = `wx-config --cxxflags`
EXE_NAME = ../QPUC
INCLUDES = -include wx/wx.h
LIBS = `wx-config --libs std,richtext`
SOURCE_FILES= $(wildcard *.cpp)
EXE_OBJ_FILES = $(SOURCE_FILES:.cpp=.o)

all : $(EXE_NAME)

clean :
	rm $(EXE_NAME) $(EXE_OBJ_FILES);

$(EXE_NAME) : $(EXE_OBJ_FILES)
	g++ -o $(EXE_NAME) $(EXE_OBJ_FILES) $(LIBS)

%.o: %.cpp
	g++ $(CFLAGS) $(INCLUDES) -o $@ -c $<