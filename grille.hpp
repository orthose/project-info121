//Documention du type abstrait grille du projet Info121

#include "coord.hpp"
#include "enscoord.hpp"
#include "animal.hpp"
using namespace std;

#ifndef GRILLE_H_
#define GRILLE_H_

//Variables globales
const float ProbInitRenard=0.05;
const float ProbInitLapin=0.28;
const float ProbInitVide=0.68;
const float ProbGenre=0.50;
const int tempsGrossesseLapin=10;
const int tempsGrossesseRenard=13;

//Modélisation du monde
struct Grille{
	Animal tab[taille][taille];
};

//Fonctions basiques utilisant les champs de la structure

/** Initialise une grille à vide.
 * @param [out] grille à modifier
 **/
void initialiserGrilleVide(Grille &g);

/** Copie le contenu d'une grille vers une autre.
 * @param grille à copier
 * @param [out] grille à modifier
 **/
void copierGrille(Grille g1,Grille &g2);

/** Place un animal dans une grille.
 * @param [in/out] grille d'animaux
 * @param animal à placer
 **/
void placerAnimal(Grille &g,Animal a);

/** Retire un animal d'une grille si la case
    choisie est non-vide.
 * @param [in/out] grille d'animaux
 * @param point auquel enlever l'animal
 **/
void enleverAnimal(Grille &g,Coord p);

/** Lit la case d'une grille.
 * @param [in] grille d'animaux
 * @param point associé à la case choisie
 * @return animal occupant la case
 **/
Animal lireCase(const Grille &g,Coord p);

//Fonctions avancées n'utilisant ques les fonctions basiques

/** Vérifie si la case d'une grille est vide.
 * @param [in] grille d'animaux
 * @return true si la case est vide, false sinon
 **/
bool caseVide(const Grille &g,Coord p);

/** Initialise une grille aléatoirement.
 * @param [out] grille vide à modifier
 **/
void initialiserGrille(Grille &g);

/** Donne le nombre de lapins total d'une grille.
 * @param[in] grille d'animaux
 * @return entier positif ou nul
 **/
int nbLapin(const Grille &g);

/** Donne le nombre de renards total d'une grille.
 * @param[in] grille d'animaux
 * @return entier positif ou nul
 **/
int nbRenard(const Grille &g);

/** Donne le nombre d'animaux total d'une grille.
 * @param[in] grille d'animaux
 * @return entier positif ou nul
 **/
int nbAnimal(const Grille &g);

/** Donne le nombre de cases vides au total d'une grille.
 * @param[in] grille d'animaux
 * @return entier positif ou nul
 **/
int nbVide(const Grille &g);

/** Trouve les coordonnées voisines d'un point
 * @param coordonnées d'un point
 * @return ensemble de coordonnées
 **/
EnsCoord trouverVoisins(Coord p);

/** Trouve les cases libres voisines d'un point
 * @param [in] grille à analyser
 * @param coordonnées d'un point
 * @return ensemble de coordonnées
 **/
EnsCoord trouverVoisinsLibres(const Grille &g,Coord p);

/** Trouve les cases d'une certaine espèce voisines d'un point
 * @param [in] grille à analyser
 * @param espèce d'animal
 * @param coordonnées d'un point
 * @return ensemble des coordonnées
 **/
EnsCoord trouverVoisinsEspece(const Grille &g,Espece e,Coord p);

/** Vérifie qu'un animal de sexe opposé se trouve dans un ensemble
 * @param [in] grille d'animaux
 * @param ensemble de coordonnées
 * @param animal de comparaison
 * @return true ou false
 **/
bool sexeOppose(const Grille &g,EnsCoord e,Animal a);

/** Trouve l'ensemble des animaux d'une espèce.
 * @param [in] grille à analyser
 * @param espèce d'animal
 * @return ensemble de coordonnées
 **/
EnsCoord trouverEspece(const Grille &g,Espece e);

/** S'il y a un lapin dans les voisins du renard,
    le déplace sur la case du lapin.
 * @param [in/out] grille à analyser et à modifier
 * @param [in/out] renard étudié
 * @return true si le renard s'est nourri, false sinon.
 **/
bool attaqueRenard(Grille &g,Animal &r);

/** Déplace tous les lapins, en prenant en compte
    morts et naissances.
 * @param [in] ancienne grille
 * @param [in/out] nouvelle grille
 **/
void deplacerLapin(Grille g1,Grille &g2);

/** Déplace tous les renards, en prenant en compte
    morts et naissances.
 * @param [in] ancienne grille
 * @param [in/out] nouvelle grille
 **/
void deplacerRenard(Grille g1,Grille &g2);

/** Vérifie que tous les animaux sont bien placés dans une grille.
 * @param [in] grille à analyser
 * @return true ou false
 **/
bool verifierGrille(const Grille &g);

/** Vérifie que les femelles sont fécondées et les modifie.
 * @param [in/out] grille à analyser
 **/
void verifierGrossesse(Grille &g);

//Renvoie le nombre de chiffres d'un nombre.
int nbChiffre(int indice);

/** Donne l'indentation nécessaire à l'affichage.
 * @param indice de l'axe horizontal >=1
 * @return l'espace correspondant
 **/
string indentation1(int indice);

/** Donne l'indentation de l'axe vertical
 * @param indice de l'axe vertical >=1
 * @return l'espace correspondant
 **/
string indentation2(int indice);

/** Affiche une grille avec les cases numérotées.
 * @param [in] grille à afficherGrille
 **/
void afficherGrille(const Grille &g);

#endif
