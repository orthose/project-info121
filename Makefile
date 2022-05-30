# Le compilateur à utiliser
CXX = g++
# Les options du compilateur
CXXFLAGS = -Wall -std=c++11 -g

all: simulation coordTest coordTest enscoordTest animalTest grilleTest
# Les programmes principaux à ne compiler que un par un
# On donne le fichier cpp et la liste des fichiers .o qu'ils utilisent
simulation: simulation.cpp coord.o enscoord.o animal.o grille.o image.o
coordTest: coordTest.cpp coord.o
enscoordTest: enscoordTest.cpp coord.o enscoord.o
animalTest: animalTest.cpp coord.o animal.o
grilleTest: grilleTest.cpp coord.o enscoord.o animal.o grille.o

# Les différents composants
# on donne le fichier cpp ainsi que la liste des fichiers .hpp dont ils dépendent
coord.o: coord.cpp coord.hpp
animal.o: animal.cpp animal.hpp coord.hpp 
enscoord.o: enscoord.cpp enscoord.hpp coord.hpp
grille.o: grille.cpp grille.hpp animal.hpp enscoord.hpp coord.hpp
image.o: image.cpp image.hpp grille.hpp enscoord.hpp

# Pour faire le ménage
clean:
	rm -f simulation *Test *.o
