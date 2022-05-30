//Documention du type abstrait ensemble de coordonnées du projet Info121

#include "coord.hpp"
using namespace std;

#ifndef ENSCOORD_H_
#define ENSCOORD_H_

//Nombre maximum d'éléments dans un ensemble
const int taille = 20;
const int MaxCoord=taille*taille;

//Ensemble de coordonnées
struct EnsCoord{
    Coord tab[MaxCoord];
	int nbCoord;
};

//Fonctions basiques utilisant les champs de la structure

/** Initialise un ensemble de coordonnées vide.
 * @param [out] ensemble de coordonnées
 **/
void creerEC(EnsCoord &e);

/** Permet d'obtenir le nombre d'éléments
    d'un ensemble de points.
 * @param [in] ensemble de coordonnées
 * @return nombre de points dans l'ensemble de points
 **/
int nbCoord(const EnsCoord &e);

/** Renvoie un élément d'un ensemble de coordonnées
 * @param [in] ensemble de coordonnées
 * @return une coordonnée
 **/
Coord elementEC(const EnsCoord &e);

/** Renvoie un élément au hasard d'un ensemble de coordonnées
 * @param [in] ensemble de coordonnées
 * @return une coordonnée
 **/
Coord randomEC(const EnsCoord &e);

/** Vérifie si un point est dans un ensemble de points.
 * @param [in] ensemble de points
 * @param coordonnées d'un point
 * @return true si le point est dans l'ensemble, false sinon
 **/
bool estDans(const EnsCoord &e,Coord c);

/** Ajoute un point à un ensemble de coordonnées.
 * @param [in/out] ensemble de coordonnées
 * @param coordonnées d'un point
 **/
void ajouterCoord(EnsCoord &e,Coord c);

/** Retire un point à un ensemble de coordonnées.
 * @param [in/out] ensemble de coordonnées
 * @param coordonnées d'un point
 **/
void enleverCoord(EnsCoord &e,Coord c);

//Fonctions avancées n'utilisant que les fonctions basiques

/** Vérifie si un ensemble de coordonnées est vide.
 * @param [in] ensemble de coordonnées
 * @return true si l'ensemble est vide, false sinon.
 **/
bool estVide(const EnsCoord &e);

/** Vérifie si deux ensembles de coordonnées sont égaux.
 * @param ensemble de coordonnées P
 * @param ensemble de coordonnées Q
 * @return true ou false
 **/
bool egalEC(EnsCoord P,EnsCoord Q);

/** Permet de créer un ensemble de coordonnées rapidement.
 * @param tableau de coordonnées
 * @param nombre d'éléments du tableau
 **/
EnsCoord rapideEC(Coord tab[],int nbElt);

/** Affiche les éléments d'un ensemble de coordonnées.
 * @param [in] ensemble de coordonnées
 **/
void afficherEC(EnsCoord e);

#endif
