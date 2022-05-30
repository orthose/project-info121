//Fichier de test du type abstrait ensemble de coordonnées du projet Info121

#include <iostream>
#include <cstdlib>
#include "coord.hpp"
#include "enscoord.hpp"
using namespace std;

/** Infrastructure minimale de test **/
#define ASSERT(test) if (!(test)) cout << "Test failed in file " << __FILE__ \
                                       << " line " << __LINE__ << ": " #test << endl

void enscoordTest(){
	
	//Création d'un ensemble
	EnsCoord E;
	creerEC(E);
	
	ASSERT(estVide(E));
	
	//Ajout de coordonnées
	ajouterCoord(E,{5,3});
	ajouterCoord(E,{3,5});
	ajouterCoord(E,{5,5});
	ajouterCoord(E,{3,3});
	
	//Test de la réussite de l'ajout
	Coord tab[4]={{5,3},{3,5},{5,5},{3,3}};
	ASSERT(egalEC(E,rapideEC(tab,4)));
	ASSERT(nbCoord(E)==4);
	afficherEC(E);cout<<endl;
	
	//Ajout de coordonnées déjà présentes
	ajouterCoord(E,{5,5});
	ajouterCoord(E,{3,3});
	
	//Test de l'intégrité de l'ensemble
	ASSERT(egalEC(E,rapideEC(tab,4)));
	ASSERT(nbCoord(E)==4);
	afficherEC(E);cout<<endl;
	
	//Suppression de coordonnées
	enleverCoord(E,{3,3});
	enleverCoord(E,{5,5});
	
	//Test de la réussite de la suppression
	Coord tab1[2]={{5,3},{3,5}};
	ASSERT(egalEC(E,rapideEC(tab1,2)));
	ASSERT(nbCoord(E)==2);
	afficherEC(E);cout<<endl;
	
	//Suppression de coordonnées absentes de l'ensemble
	enleverCoord(E,{3,3});
	enleverCoord(E,{5,5});
	
	//Test de l'intégrité de l'ensemble
	ASSERT(egalEC(E,rapideEC(tab1,2)));
	ASSERT(nbCoord(E)==2);
	afficherEC(E);cout<<endl;
	
	//Création d'un nouvel ensemble
	creerEC(E);
	for(int i=0;i<taille;i++){
		for(int j=0;j<taille;j++){
			ajouterCoord(E,{i,j});
		}
	}
	
	Coord tab2[MaxCoord];int compteur=0;
	for(int i=0;i<taille;i++){
		for(int j=0;j<taille;j++){
			tab2[compteur]={i,j};
			compteur++;
		}
	}
	
	//Test de la réussite de la création
	ASSERT(egalEC(E,rapideEC(tab2,MaxCoord)));
	ASSERT(nbCoord(E)==MaxCoord);
	
	//Test d'ajout d'éléments en trop
	ajouterCoord(E,{20,0});
	ajouterCoord(E,{20,1});
	ajouterCoord(E,{20,2});
	
	//Test d'intégrité de l'ensemble
	ASSERT(egalEC(E,rapideEC(tab2,MaxCoord)));
	ASSERT(nbCoord(E)==MaxCoord);
	
	//Autres manipulations et tests de comportement
	EnsCoord F=rapideEC(tab2,MaxCoord);
	for(int i=0;i<100;i++){
		Coord c=elementEC(E);
		ASSERT(estDans(E,c));
		enleverCoord(E,c);
		enleverCoord(F,c);
	}
	
	ASSERT(egalEC(E,F));
	ASSERT(nbCoord(E)==MaxCoord-100 and nbCoord(F)==MaxCoord-100);

	for(int i=0;i<275;i++){
		Coord c=randomEC(E);
		ASSERT(estDans(E,c));
		enleverCoord(E,c);
		enleverCoord(F,c);
	}
	
	ASSERT(egalEC(E,F));
	ASSERT(nbCoord(E)==MaxCoord-375 and nbCoord(F)==MaxCoord-375);

	afficherEC(E);
}

//Lancement des tests
int main(){

	srand(time(NULL));
	//Pour ce test mettre taille=20
	enscoordTest();
}
