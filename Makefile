CXX = g++
CXXFLAGS = -ggdb -Wall -MMD
EXEC = ss5k
OBJECTS = main.o square.o level1.o level2.o basicsquare.o lateralsquare.o uprightsquare.o unstablesquare.o psychedelicsquare.o board.o level.o level0.o  match.o matchaxis.o matchl.o window.o
DEPENDS = ${OBJECTS:.o=.d}

${EXEC}: ${OBJECTS}
	${CXX} ${CXXFLAGS} ${OBJECTS} -o ${EXEC} -lX11

-include ${DEPENDS}

.PHONY: clean

clean:
	rm ${OBJECTS} ${EXEC} ${DEPENDS}
