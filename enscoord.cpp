//Définition des fonctions associées au type ensemble de coordonnées du projet Info121

#include <iostream>
#include <cstdlib>
#include "coord.hpp"
#include "enscoord.hpp"
using namespace std;

/* Fonctions basiques utilisant les champs de la structure */

//Crée un ensemble de Coordonnées
void creerEC(EnsCoord &e){
    e.nbCoord=0;
}

//Renvoie le nombre de coordonées d'un ensemble
int nbCoord(const EnsCoord &e){
    return e.nbCoord;
}

//Renvoie un élement d'un ensemble de coordonnées
Coord elementEC(const EnsCoord &e){
    return e.tab[0];
}

//Renvoie un élément au hasard d'un ensemble de coordonnées
Coord randomEC(const EnsCoord &e){
	int i=rand()%(nbCoord(e));
	return e.tab[i];
}

//Renvoie  si une coordonée est dans un ensemble
bool estDans(const EnsCoord &e,Coord c){
    for(int i=0;i<nbCoord(e);i++){
        if(egalCoord(e.tab[i],c)) return true;
    }
    return false;
}

//Ajoute une Coordonée à un ensemble
void ajouterCoord(EnsCoord &e, Coord c){
    if(estDans(e,c)){
        cerr<<"Erreur: coordonnée déja dans l'ensemble."<<endl;
        return;
    } else if(nbCoord(e)>=MaxCoord){
        cerr<<"Erreur: taille maximale du tableau atteinte."<<endl;
        return;
    }
    e.tab[nbCoord(e)]=c;
    e.nbCoord++;
}

//Enlève une coordonée à un ensemble
void enleverCoord(EnsCoord &e,Coord c){
    for(int i=0;i<nbCoord(e);i++){
        if(egalCoord(e.tab[i],c)){
            Coord temp=e.tab[nbCoord(e)-1];
            e.tab[nbCoord(e)-1]=c;
            e.tab[i]=temp;
            e.nbCoord--;
            break;
        }
    }
}

/* Fonctions avancées n'utilisant que les fonctions basiques */

//Vérifie si un ensemble est vide
bool estVide(const EnsCoord &e){
	return nbCoord(e)==0;
}

//Vérifie si deux ensembles de coordonnées contiennent les memes éléments
bool egalEC(EnsCoord P,EnsCoord Q){ 
    if(nbCoord(P)==nbCoord(Q)){
        while(not estVide(P)){
            Coord c=elementEC(P);
            if(not estDans(Q,c)) return false;
            enleverCoord(P,c);
			enleverCoord(Q,c);
        }
        if(estVide(Q)) return true;
    }
    return false;
}

//Pemet de récupérer un ensemble de coordonnées à partir d'un tableau
EnsCoord rapideEC(Coord tab[],int nbElt){
    
	EnsCoord res;
	creerEC(res);
	
	//Enregistre les valeurs dans l'ensemble
    for(int i=0;i<nbElt;i++){
        ajouterCoord(res,tab[i]);
    }
    return res;
}

//Affiche un ensemble de coordonnées
void afficherEC(EnsCoord e){
	while(not estVide(e)){
		Coord c=elementEC(e);
		afficherCoord(c);
		enleverCoord(e,c);
	}
}