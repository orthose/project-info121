//Documentation de la création d'images du projet Info121

#include"grille.hpp"

#ifndef IMAGE_H_
#define IMAGE_H_

const int taille_pix=5;

/** Permet de créer une image au format ppm
 * @param numéro du fichier
 **/
void dessinerImage(const Grille &g,int compteurFichier);

#endif
