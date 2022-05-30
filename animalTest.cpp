//Fichier de test du type abstrait animal du projet Info121

#include <iostream>
#include <cstdlib>
#include "coord.hpp"
#include "animal.hpp"
using namespace std;

/** Infrastructure minimale de test **/
#define ASSERT(test) if (!(test)) cout << "Test failed in file " << __FILE__ \
                                       << " line " << __LINE__ << ": " #test << endl

void animalTest(){

	//Création d'animaux
	Animal L=creerAnimal(Lapin,{5,10},Femelle);
	Animal R=creerAnimal(Renard,{4,8},Femelle);
	Animal V=creerAnimal(Vide,{12,9},Male);
	
	//Test de la réussite de l'opération
	ASSERT(existeAnimal(L));
	ASSERT(existeAnimal(R));
	ASSERT(not existeAnimal(V));
	ASSERT(especeAnimal(L)==Lapin);
	ASSERT(especeAnimal(R)==Renard);
	ASSERT(egalCoord(positionAnimal(L),{5,10}));
	ASSERT(egalCoord(positionAnimal(R),{4,8}));
	ASSERT(sexeAnimal(L)==Femelle);
	ASSERT(sexeAnimal(R)==Femelle);
	ASSERT(ageAnimal(L)==LifeLapin);
	ASSERT(ageAnimal(R)==LifeRenard);
	ASSERT(foodAnimal(L)==FoodInit);
	ASSERT(foodAnimal(R)==FoodInit);
	
	afficherAnimal(L);cout<<endl;
	afficherAnimal(R);cout<<endl;
	
	//Fonctions de nourriture pour renard
	mangeRenard(R);
	ASSERT(foodAnimal(R)==FoodInit+FoodLapin);
	faimRenard(R);
	ASSERT(foodAnimal(R)==FoodInit+FoodLapin-1);
	
	//Fonctions de nourriture pour renard testées sur lapin
	mangeRenard(L);
	ASSERT(foodAnimal(L)==FoodInit);
	faimRenard(L);
	ASSERT(foodAnimal(L)==FoodInit);
	
	//Fonction de déplacement
	deplacerAnimal(L,{5,11});
	deplacerAnimal(R,{5,8});
	ASSERT(egalCoord(positionAnimal(L),{5,11}));
	ASSERT(egalCoord(positionAnimal(R),{5,8}));
	
	//Fonction de reproduction
	L.grossesse=true;
	R.grossesse=true;
	for(int i=0;i<10;i++){
		if(AnimalEngendre(L,8)) cout<<"Le lapin se reproduit."<<endl;
		else cout<<"Le lapin ne s'est pas reproduit."<<endl;
		if(AnimalEngendre(R,8)) cout<<"Le renard se reproduit."<<endl;
		else cout<<"Le renard ne s'est pas reproduit."<<endl;
	}
	cout<<endl;
	
	//Fonctions de vieillesse et de mort
	for(int i=0;i<FoodInit+FoodLapin-1;i++){
		faimRenard(R);
	}
	ASSERT(mortAnimal(R));
	for(int i=0;i<LifeLapin;i++){
		vieillirAnimal(L);
	}
	ASSERT(mortAnimal(L));
	
	afficherAnimal(L);cout<<endl;
	afficherAnimal(R);cout<<endl;	

}

//Lancement des tests	
int main(){
	srand(time(NULL));
	animalTest();
}
