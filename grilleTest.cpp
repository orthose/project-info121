//Fichier de test du type abstrait grille du projet Info121

#include <iostream>
#include "coord.hpp"
#include "enscoord.hpp"
#include "animal.hpp"
#include "grille.hpp"
using namespace std;

/** Infrastructure minimale de test **/
#define ASSERT(test) if (!(test)) cout << "Test failed in file " << __FILE__ \
                                       << " line " << __LINE__ << ": " #test << endl

void fonctionsBasiquesTest(){
	
	//Initialisation de la grille
	Grille g;
	initialiserGrilleVide(g);
	ASSERT(nbVide(g)==taille*taille);
	
	//Création d'animaux
	Animal a=creerAnimal(Renard,{0,0},Male);
	Animal b=creerAnimal(Lapin,{2,1},Femelle);
	Animal c=creerAnimal(Renard,{3,2},Male);
	Animal d=creerAnimal(Lapin,{5,6},Male);
	Animal e=creerAnimal(Renard,{taille-1,taille-1},Femelle);
	Animal f=creerAnimal(Vide,{10,8},Asexue);
	
	//Enregistrement dans la grille
	placerAnimal(g,a);
	placerAnimal(g,b);
	placerAnimal(g,c);
	placerAnimal(g,d);
	placerAnimal(g,e);
	placerAnimal(g,f);
	
	//Test de la réussite de l'opération
	Animal alpha=lireCase(g,{0,0});
	ASSERT(nbAnimal(g)==5);
	ASSERT(especeAnimal(alpha)==especeAnimal(a));
	ASSERT(egalCoord(positionAnimal(alpha),positionAnimal(a)));
	ASSERT(sexeAnimal(alpha)==sexeAnimal(a));
	
    alpha=lireCase(g,{2,1});
	ASSERT(especeAnimal(alpha)==especeAnimal(b));
	ASSERT(egalCoord(positionAnimal(alpha),positionAnimal(b)));
	ASSERT(sexeAnimal(alpha)==sexeAnimal(b));
	
	alpha=lireCase(g,{3,2});
	ASSERT(especeAnimal(alpha)==especeAnimal(c));
	ASSERT(egalCoord(positionAnimal(alpha),positionAnimal(c)));
	ASSERT(sexeAnimal(alpha)==sexeAnimal(c));
	
	alpha=lireCase(g,{5,6});
	ASSERT(especeAnimal(alpha)==especeAnimal(d));
	ASSERT(egalCoord(positionAnimal(alpha),positionAnimal(d)));
	ASSERT(sexeAnimal(alpha)==sexeAnimal(d));
	
	alpha=lireCase(g,{taille-1,taille-1});
	ASSERT(especeAnimal(alpha)==especeAnimal(e));
	ASSERT(egalCoord(positionAnimal(alpha),positionAnimal(e)));
	ASSERT(sexeAnimal(alpha)==sexeAnimal(e));
	
	alpha=lireCase(g,{10,8});
	ASSERT(especeAnimal(alpha)==especeAnimal(f));
	ASSERT(egalCoord(positionAnimal(alpha),positionAnimal(f)));
	ASSERT(sexeAnimal(alpha)==sexeAnimal(f));
	
	ASSERT(verifierGrille(g));
	
	//Test que toutes les autres cases sont bien vides
	EnsCoord ec;creerEC(ec);
	Coord tab[6]={{0,0},{2,1},{3,2},{5,6},{taille-1,taille-1},{10,8}};
	ec=rapideEC(tab,6);
	for(int i=0;i<taille;i++){
		for(int j=0;j<taille;j++){
			Coord c=creerCoord(i,j);
			if(not estDans(ec,c)){
				Animal a=lireCase(g,c);
				ASSERT(especeAnimal(a)==Vide);
				ASSERT(egalCoord(positionAnimal(a),c));
				ASSERT(sexeAnimal(a)==Asexue);
				ASSERT(ageAnimal(a)==0);
				ASSERT(foodAnimal(a)==0);
			}
		}
	}
	
	afficherGrille(g);
	cout<<endl;
	
	//Copie dans une nouvelle grille
	Grille h;
	initialiserGrilleVide(h);
	copierGrille(g,h);
	
	//Test de la réussite de l'opération
	alpha=lireCase(h,{0,0});
	ASSERT(nbAnimal(h)==5);
	ASSERT(especeAnimal(alpha)==especeAnimal(a));
	ASSERT(egalCoord(positionAnimal(alpha),positionAnimal(a)));
	ASSERT(sexeAnimal(alpha)==sexeAnimal(a));
	
    alpha=lireCase(h,{2,1});
	ASSERT(especeAnimal(alpha)==especeAnimal(b));
	ASSERT(egalCoord(positionAnimal(alpha),positionAnimal(b)));
	ASSERT(sexeAnimal(alpha)==sexeAnimal(b));
	
	alpha=lireCase(h,{3,2});
	ASSERT(especeAnimal(alpha)==especeAnimal(c));
	ASSERT(egalCoord(positionAnimal(alpha),positionAnimal(c)));
	ASSERT(sexeAnimal(alpha)==sexeAnimal(c));
	
	alpha=lireCase(h,{5,6});
	ASSERT(especeAnimal(alpha)==especeAnimal(d));
	ASSERT(egalCoord(positionAnimal(alpha),positionAnimal(d)));
	ASSERT(sexeAnimal(alpha)==sexeAnimal(d));
	
	alpha=lireCase(h,{taille-1,taille-1});
	ASSERT(especeAnimal(alpha)==especeAnimal(e));
	ASSERT(egalCoord(positionAnimal(alpha),positionAnimal(e)));
	ASSERT(sexeAnimal(alpha)==sexeAnimal(e));
	
	alpha=lireCase(h,{10,8});
	ASSERT(especeAnimal(alpha)==especeAnimal(f));
	ASSERT(egalCoord(positionAnimal(alpha),positionAnimal(f)));
	ASSERT(sexeAnimal(alpha)==sexeAnimal(f));
	
	ASSERT(verifierGrille(h));
	
	//Test que toutes les autres cases sont bien vides
	for(int i=0;i<taille;i++){
		for(int j=0;j<taille;j++){
			Coord c=creerCoord(i,j);
			if(not estDans(ec,c)){
				Animal a=lireCase(h,c);
				ASSERT(especeAnimal(a)==Vide);
				ASSERT(egalCoord(positionAnimal(a),c));
				ASSERT(sexeAnimal(a)==Asexue);
				ASSERT(ageAnimal(a)==0);
				ASSERT(foodAnimal(a)==0);
			}
		}
	}
	
	//Suppression d'animaux
	enleverAnimal(g,{0,0});
	enleverAnimal(g,{2,1});
	enleverAnimal(g,{10,8});
	
	//Test de la réussite de l'opération
	ASSERT(nbAnimal(g)==3);
	ASSERT(nbAnimal(h)==5);
	ASSERT(caseVide(g,{0,0}));
	ASSERT(caseVide(g,{2,1}));
	ASSERT(caseVide(g,{10,8}));
	ASSERT(not caseVide(h,{0,0}));
	ASSERT(not caseVide(h,{2,1}));
	ASSERT(caseVide(h,{10,8}));
	verifierGrille(g);
	verifierGrille(h);
	
	afficherGrille(g);
	
}

void fonctionsAvanceesTest(){
	Grille g;
	initialiserGrilleVide(g);
	initialiserGrille(g);
	//afficherGrille(g);
	cout<<"Nombre de lapins: "<<nbLapin(g)<<endl;
	cout<<"Pourcentage de lapins: "<<float(nbLapin(g)*100)/float(taille*taille)<<endl;
	cout<<"Nombre de renards: "<<nbRenard(g)<<endl;
	cout<<"Pourcentage de renards: "<<float(nbRenard(g)*100)/float(taille*taille)<<endl;
	cout<<"Nombre d'animaux: "<<nbAnimal(g)<<endl;
	cout<<"Nombre de cases vides: "<<nbVide(g)<<endl;
	cout<<"Pourcentage de cases vides: "<<float(nbVide(g)*100)/float(taille*taille)<<endl;

}

void afficherGrilleTest(){
	
	ASSERT(nbChiffre(0)==1);
	ASSERT(nbChiffre(1)==1);
	ASSERT(nbChiffre(5)==1);
	ASSERT(nbChiffre(9)==1);
	ASSERT(nbChiffre(10)==2);
	ASSERT(nbChiffre(taille)==2);

    ASSERT(indentation1(1)==" ");
    ASSERT(indentation1(5)==" ");
    ASSERT(indentation1(9)==" ");
    ASSERT(indentation1(10)=="  ");
    ASSERT(indentation1(49)=="  ");
    ASSERT(indentation1(72)=="  ");
    ASSERT(indentation1(99)=="  ");
    ASSERT(indentation1(100)=="   ");
    ASSERT(indentation1(125)=="   ");
}

//Lancement des tests
int main(){
	
	srand(time(NULL));
	
	fonctionsBasiquesTest();
	fonctionsAvanceesTest();
	afficherGrilleTest();
}
