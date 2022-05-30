# Introduction

* Étudiant : Maxime Vincent
* Formation : L1 S2 MPI
* UE : [Info 121](https://www.lri.fr/~hivert/COURS/Info121/INFO121.html) 
* Établissement : Université Paris-Sud
* Année : 2018-2019

Projet de programmation impérative simulant l'évolution de populations de renards
et de lapins interagissant entre elles sur une grille en 2D.

# Compilation
```shell
make
```

# Exécution
Le programme principal crée des fichiers images ppm.
```shell
./simulation
```

Les programmes de test écrivent des informations sur la sortie standard 
et réalisent des tests unitaires.
```shell
./coordTest
./coordTest
./enscoordTest
./animalTest
./grilleTest
```

# Nettoyage
```shell
make clean
```
