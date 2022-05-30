//Définition des fonctions associées au type animal du projet Info121

#include <iostream>
#include <cstdlib>
#include "coord.hpp"
#include "animal.hpp"
using namespace std;

/* Fonctions basiques utilisant les champs des structures */

//Crée un animal initialisé
Animal creerAnimal(Espece espece, Coord position,Genre sexe){
	Animal a;
	if(espece==Lapin) a={espece,position,sexe,false,LifeLapin,FoodInit};
	else if(espece==Renard) a={espece,position,sexe,false,LifeRenard,FoodInit};
	else if(espece==Vide) a={espece,position,sexe,false,0,0};
	return a;
}

//Renvoie l'espèce d'un animal
Espece especeAnimal(Animal a){
	return a.espece;
}

//Vérifie si un animal existe
bool existeAnimal(Animal a){
	return especeAnimal(a)!=Vide;
}

//Renvoie la position d'un animal
Coord positionAnimal(Animal a){
	return a.position;
}

//Déplace un animal sans vérification
void deplacerAnimal(Animal &a,Coord c){
	a.position=c;
}

//Renvoie le sexe d'un animal
Genre sexeAnimal(Animal a){
	return a.sexe;
}

//Renvoie l'état de grossesse d'un animal
bool grossesseAnimal(Animal a){
	return a.grossesse;
}

//Permet de féconder un animal femelle
void feconderAnimal(Animal &a,bool grossesse){
	if(sexeAnimal(a)==Femelle){
		a.grossesse=grossesse;
	}
}

//Renvoie le niveau de nourriture d'un animal
int foodAnimal(Animal a){
	return a.food;
}

//Permet à un renard de manger un lapin
void mangeRenard(Animal &a){
	if(especeAnimal(a)==Renard){
		a.food+=FoodLapin;
		if(foodAnimal(a)>MaxFood) a.food=MaxFood;
	}
}

//Fait diminuer le niveau de nourriture d'un renard
void faimRenard(Animal &a){
	if(especeAnimal(a)==Renard){
		a.food--;
	}
}

//Renvoie l'âge d'un animal
int ageAnimal(Animal a){
	return a.age;
}

//Fait vieillir un animal
void vieillirAnimal(Animal &a){
	a.age--;
}

/* Fonctions avancées n'utilisant que les fonctions basiques */

//Renvoie un nombre entre 0 et 1
float lancer(){
	return float(rand())/float(RAND_MAX);
}

//Tirage aléatoire en fonction d'une probabilité
bool hasard(float proba){
	return lancer()<=proba;
}

//Vérifie si un animal survit
bool mortAnimal(Animal a){
	return not(ageAnimal(a)>0 and foodAnimal(a)>0);
}

//Vérifie si un animal est reproductible
bool AnimalEngendre(Animal a,int casesVides){
	if (especeAnimal(a)==Lapin) return (casesVides>=MinFreeBirthLapin and hasard(ProbBirthLapin) and sexeAnimal(a)==Femelle and grossesseAnimal(a));
	else if(especeAnimal(a)==Renard) return (foodAnimal(a)>=FoodReprod and hasard(ProbBirthRenard) and sexeAnimal(a)==Femelle and grossesseAnimal(a));
	return false;
}

//Affiches les données d'un animal
void afficherAnimal(Animal a){
	if(especeAnimal(a)!=Vide){
		if(especeAnimal(a)==Renard) cout<<"Espèce: Renard"<<endl;
		else cout<<"Espèce: Lapin"<<endl;
		afficherCoord(positionAnimal(a));
		if(sexeAnimal(a)==Male) cout<<"Sexe: Mâle"<<endl;
		else cout<<"Sexe: Femelle"<<endl;
		cout<<"Âge: "<<ageAnimal(a)<<endl;
		cout<<"Nourriture: "<<foodAnimal(a)<<endl;
	}
}


