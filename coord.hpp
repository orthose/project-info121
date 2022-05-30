//Documention du type abstrait coordonnées du projet Info121

#ifndef COORD_H_
#define COORD_H_

//Coordonnées d'un point
struct Coord{
	int x,y;
};

//Fonctions basiques utilisant les champs de la structure

/** Permet de créer les coordonnées d'un point.
 * @param [out] coordonnées d'un point
 * @param [in] entier désignant l'abscisse
 * @param [in] entier désignant l'ordonnée
 **/
Coord creerCoord(int x,int y);

/** Permet d'obtenir l'abscisse d'un point.
 * @param [in] coordonnées d'un point
 * @return entier désignant l'abscisse
 **/
int getX(Coord c);

/** Permet d'obtenir l'ordonnée d'un point.
 * @param [in] coordonnées d'un point
 * @return entier désignant l'ordonnée
 **/
int getY(Coord c);

//Fonctions avancées n'utilisant que les fonctions basiques

/** Vérifie si deux points sont confondus.
 * @param coordonnées d'un point A
 * @param coordonnées d'un point B
 * @return true si les points sont identiques,
   false sinon
 **/
bool egalCoord(Coord A,Coord B);

/** Affiche une coordonnées.
 * @param coordonnée d'un point
 **/
void afficherCoord(Coord c);

#endif