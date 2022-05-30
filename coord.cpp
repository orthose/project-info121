//Définition des fonctions associées au type coordonnées du projet Info121

#include <iostream>
#include "coord.hpp"
using namespace std;

/* Fonctions basiques utilisant les champs de la structure */

//Crée une coordonnée initialisée
Coord creerCoord(int x, int y){
    Coord c={x,y};
    return c;
}

//Retourne la valeur en abscisse d'une coordonnée
int getX(Coord c){
    return c.x;
}

//Retourne la valeur en ordonnée d'une coordonnée
int getY(Coord c){
    return c.y;
}

/* Fonctions avancées n'utilisant que les fonctions basiques */

//Vérifie l'egalité entre deux coordonées
bool egalCoord(Coord A, Coord B){
    return (getX(A)==getX(B) && getY(A)==getY(B));
}

//Affiche une coordonnée
void afficherCoord(Coord c){
	cout<<"Coord("<<getX(c)<<","<<getY(c)<<")"<<endl;
}