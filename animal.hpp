//Documentation du type abstrait animal du projet Info121

#include "coord.hpp"
using namespace std;

#ifndef ANIMAL_H_
#define ANIMAL_H_

//Paramètres globaux
const int FoodInit=5;
const int FoodLapin=5;
const int FoodReprod=3;
const int MaxFood=15;
const float ProbBirthRenard=0.95;
const float ProbBirthLapin=0.90;
const int MinFreeBirthLapin=4;
const int LifeRenard=25;
const int LifeLapin=2*LifeRenard;

//Genre d'un animal
enum Genre{Asexue,Male,Femelle};

//Contenu d'une case
enum Espece{Vide,Lapin,Renard};

//Modélisation d'un animal
struct Animal{
    Espece espece;
    Coord position;
    Genre sexe;
	bool grossesse;
    int age, food;
};

//Fonctions basiques utilisant les champs de la structure

/** Crée un animal d'une certaine espèce en un point.
 * @param espèce de l'animal
 * @param point auquel est l'animal
 * @param genre de l'animal
 * @return animal créé
 **/
Animal creerAnimal(Espece espece, Coord position,Genre sexe);

/** Donne l'espèce auquel appartient l'animal.
 * @param animal à analyser
 * @return espèce de l'animal
 **/
Espece especeAnimal(Animal a);

/** Vérifie si un animal existe.
 * @param animal à analyser
 * @return true ou false
 **/
bool existeAnimal(Animal a);

/** Donne la position d'un animal.
 * @param animal à analyser
 * @param coordonnée de l'animal
 **/
Coord positionAnimal(Animal a);

/** Déplace un animal en un point si cela est possible.
 * @param [in/out] animal à déplacer
 * @param coordonnée sur laquelle déplacer l'animal
 **/
void deplacerAnimal(Animal &a,Coord c);

/** Donne le sexe d'un animal.
 * @param animal à analyser
 * @return sexe de l'animal
 **/
Genre sexeAnimal(Animal a);

/** Renvoie l'état de grossesse d'un animal.
 * @param animal à analyser
 * @return true ou false
 **/
bool grossesseAnimal(Animal a);

/** Permet de féconder ou non un animal femelle
 * @param [in/out] animal à modifer
 * @param booléen désignant l'état de grossesse
 **/
void feconderAnimal(Animal &a,bool grossesse);

/** Donne le niveau de nourriture d'un animal
 * @param animal à analyser
 * @return entier >= 0
 **/
int foodAnimal(Animal a);

/** Permet à un renard de se nourrir.
 * @param animal à nourrir
 **/
void mangeRenard(Animal &a);

/** Diminue le niveau de nourriture d'un renard
 * @param [in/out] animal à modifier
 **/
void faimRenard(Animal &a);

/** Donne l'âge d'un animal
 * @param animal à analyser
 * @return entier >= 0
 **/
int ageAnimal(Animal a);

/** Fait vieillir un animal.
 * @param [in/out] animal à modifier
 **/
void vieillirAnimal(Animal &a);

//Fonctions avancées n'utilisant que les fonctions basiques

/** Donne le résultat d'un tirage aléatoire
 * @return nombre entre 0 et 1
 **/
float lancer();

/** Vérifie le résultat d'un tirage aléatoire en fonction d'une probabilité.
 * @param probabilité comprise entre 0 et 1
 * @return true ou false
 **/
bool hasard(float proba);

/** Permet de savoir si un animal survit ou non.
 * @param animal à analyser
 * @return true si l'animal meurt, false s'il survit
 **/
bool mortAnimal(Animal a);

/** Permet de savoir si un animal se reproduit ou non.
 * @param animal à analyser
 * @param entier positif désignant les cases vides autour de l'animal
 * @return true si l'animal se reproduit, false sinon
 **/
bool AnimalEngendre(Animal a, int casesVides);

/** Affiche les données d'un animal.
 * @param animal à afficher
 **/
void afficherAnimal(Animal a);

#endif
