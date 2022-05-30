//Programme principal du projet Info121

#include <iostream>
#include <cstdlib>
#include "grille.hpp"
#include "image.hpp"
using namespace std;

//Programme principal
int main(){
	
	//Initialisation de l'al�atoire
	srand(time(NULL));
	
	//On travaille avec deux grilles
	Grille g1,g2;
	initialiserGrille(g2);
	
	//Variables de la boucle
	bool boucle=true;
	int tour=0;
	
	//Boucle de la simulation
	do{
		//V�rification que le cycle continue
		boucle=not(nbLapin(g2)==0 or nbRenard(g2)==0);
		
		//Op�rations r�p�t�es
		afficherGrille(g2);
		cout<<endl<<"Nombre de tours: "<<tour<<endl;
		cout<<"Nombre de lapins: "<<nbLapin(g2)<<endl;
		cout<<"Nombre de renards: "<<nbRenard(g2)<<endl;
		cout<<"Nombre d'animaux: "<<nbAnimal(g2)<<endl;
		cout<<"Nombre de cases vides: "<<nbVide(g2)<<endl;
		copierGrille(g2,g1);
		initialiserGrilleVide(g2);
		deplacerLapin(g1,g2);
		deplacerRenard(g1,g2);
		verifierGrossesse(g2);
		
		//V�rification du succ�s des d�placements
		if(not verifierGrille(g2)) cout<<"Erreur: Coordonn�es incorrectes."<<endl;
		
		//Interaction avec utilisateur
		cout<<"Appuyez sur entr�e pour continuer..."<<endl;
		char saisie=getchar();
		boucle=(saisie=='\n') and boucle;
		boucle=tour<=999 and boucle;
		system("clear");
		
		//Enregistrement de l'image
		dessinerImage(g2,tour);
		
		tour++;
		
	}while(boucle);
	
}
