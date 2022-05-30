//Définition des fonctions associées au type grille du projet Info121

#include <iostream>
#include "coord.hpp"
#include "enscoord.hpp"
#include "animal.hpp"
#include "grille.hpp"
using namespace std;

/* Fonctions basiques utilisant les champs de la structure */

//Initialise une grille à vide
void initialiserGrilleVide(Grille &g){
	for(int i=0;i<taille;i++){
		for(int j=0;j<taille;j++){
			Animal a=creerAnimal(Vide,{i,j},Asexue);
			g.tab[i][j]=a;
		}
	}
}

//Copie le contenu d'une grille dans une autre
void copierGrille(Grille g1,Grille &g2){
	for(int i=0;i<taille;i++){
		for(int j=0;j<taille;j++){
			g2.tab[i][j]=g1.tab[i][j];
		}
	}
}

//Place un animal dans une grille
void placerAnimal(Grille &g,Animal a){
	if(existeAnimal(a)){
		g.tab[getX(positionAnimal(a))][getY(positionAnimal(a))]=a;
	}
}

//Enlève un animal d'une grille
void enleverAnimal(Grille &g,Coord p){
	if(existeAnimal(lireCase(g,p))){
		Animal a=creerAnimal(Vide,p,Asexue);
		g.tab[getX(p)][getY(p)]=a;
	}
}

//Lit une case d'une grille
Animal lireCase(const Grille &g,Coord p){
	return g.tab[getX(p)][getY(p)];
}

/* Fonctions avancées n'utilisant ques les fonctions basiques */

//Vérifie si une case est vide
bool caseVide(const Grille &g,Coord p){
	return especeAnimal(lireCase(g,p))==Vide;
}	

//Initialise une grille aléatoirement
void initialiserGrille(Grille &g){
	
	initialiserGrilleVide(g);
	for(int i=0;i<taille;i++){
		for(int j=0;j<taille;j++){
			
			Espece espece;
			Genre sexe=Asexue;
			float tirage=lancer();
			
			//Initialisation de l'espèce
			if(tirage<=ProbInitRenard) espece=Renard;
			else if(tirage<=ProbInitRenard+ProbInitLapin) espece=Lapin;
			else espece=Vide;
			
			//Initialisation du sexe
			if(espece!=Vide){
			    if(hasard(ProbGenre)) sexe=Male;
			    else sexe=Femelle;
			}
			
			Coord position=creerCoord(i,j);
			Animal a=creerAnimal(espece,position,sexe);
			placerAnimal(g,a);
		}
	}
}

//Renvoie le nombre de lapins d'une grille
int nbLapin(const Grille &g){
	int compteur=0;
	for(int i=0;i<taille;i++){
		for(int j=0;j<taille;j++){
			Coord p=creerCoord(i,j);
			if(especeAnimal(lireCase(g,p))==Lapin) compteur++;
		}
	}
	return compteur;
}

//Renvoie le nombre de renards d'une grille
int nbRenard(const Grille &g){
	int compteur=0;
	for(int i=0;i<taille;i++){
		for(int j=0;j<taille;j++){
			Coord p=creerCoord(i,j);
			if(especeAnimal(lireCase(g,p))==Renard) compteur++;
		}
	}
	return compteur;
}

//Renvoie le nombre d'animaux d'une grille
int nbAnimal(const Grille &g){
	return nbLapin(g)+nbRenard(g);
}

//Renvoie le nombre de cases vides d'une grille
int nbVide(const Grille &g){
	return (taille*taille)-nbAnimal(g);
}

//Renvoie les coordonnées voisines d'un point
EnsCoord trouverVoisins(Coord p){
	
	EnsCoord res;
	creerEC(res);
    int minX,maxX,Xc,Yc;
    Xc=getX(p);
    Yc=getY(p);

	//Recherche des bornes minX et maxX
	//et enregistrement des cases à côté
    if(Xc==0) minX=0;
    else{
        minX=Xc-1;
        ajouterCoord(res, creerCoord(minX, Yc));
    }

    if(Xc==taille-1) maxX=taille-1;
    else{
        maxX=Xc+1;
        ajouterCoord(res, creerCoord(maxX, Yc));
    }
	
	//Enregistrement des cases au-dessus et en-dessous
    for(int i=minX;i<=maxX;i++){
        if(Yc!=0) ajouterCoord(res, creerCoord(i, Yc-1));
        if(Yc!=taille-1) ajouterCoord(res, creerCoord(i, Yc+1));
    }
    return res;
}

//Renvoie les cases libres voisines d'un point
EnsCoord trouverVoisinsLibres(const Grille &g,Coord p){
	
	EnsCoord voisins=trouverVoisins(p),res;
	creerEC(res);
	
	//On retire tous les voisins occupés
	//et on stocke tous ceux libres
	while(not estVide(voisins)){
		Coord p=elementEC(voisins);
		if(especeAnimal(lireCase(g,p))==Vide){
			ajouterCoord(res,p);
		}
		enleverCoord(voisins,p);
	}
	return res;
}

//Renvoie les cases d'une certaine espèce autour d'un point
EnsCoord trouverVoisinsEspece(const Grille &g,Espece e,Coord p){
	
	EnsCoord voisins=trouverVoisins(p),res;
	creerEC(res);
	while(not estVide(voisins)){
		Coord p=elementEC(voisins);
		if(especeAnimal(lireCase(g,p))==e){
			ajouterCoord(res,p);
		}
		enleverCoord(voisins,p);
	}
	return res;
}

//Vérifie qu'un animal de sexe opposé se trouve dans l'ensemble
bool sexeOppose(const Grille &g,EnsCoord e,Animal a){
	if(existeAnimal(a)){
		while(not estVide(e)){
			Coord p=elementEC(e);
			Animal b=lireCase(g,p);
			if(sexeAnimal(a)!=sexeAnimal(b) and especeAnimal(a)==especeAnimal(b)){
				return true;
			}
			enleverCoord(e,p);
		}
	}
	return false;
}

//Renvoie l'ensemble des positions des animaux d'une espèce
EnsCoord trouverEspece(const Grille &g,Espece e){
	
	EnsCoord res;
	creerEC(res);
	
	for(int i=0;i<taille;i++){
		for(int j=0;j<taille;j++){
			Coord p=creerCoord(i,j);
			if(especeAnimal(lireCase(g,p))==e){
				ajouterCoord(res,p);
			}
		}
	}
	return res;
}

//Déplace un renard sur un lapin si cela est possible
bool attaqueRenard(Grille &g,Animal &r){
	
	bool res=false;
	
	if(especeAnimal(r)==Renard){
	
		//Recherche des lapins au voisinage du renard
		EnsCoord lapins=trouverVoisinsEspece(g,Lapin,positionAnimal(r));
		
		res=not estVide(lapins);
		
		if(res){
			
			//Choix aléatoire d'une case occupée par un lapin
			Coord p=randomEC(lapins);
			//Sauvegarde de la place du renard
			Coord o=positionAnimal(r);
			//Change la coordonnée du renard
			deplacerAnimal(r,p);
			//Le renard se nourrit
			mangeRenard(r);
			//Sauvegarde dans la grille de la nouvelle place
			placerAnimal(g,r);
			//Suppression de son ancienne place
			enleverAnimal(g,o);
		}
	}
	return res;
}

//Déplace tous les lapins avec morts et naissances
void deplacerLapin(Grille g1,Grille &g2){
	
	//Tous les lapins de la grille
	EnsCoord e=trouverEspece(g1,Lapin);
	
	//Parcours de tous les lapins
	while(not estVide(e)){
		Coord c1=randomEC(e);
		Animal l=lireCase(g1,c1);
		
		//Diminution de l'état du lapin
		vieillirAnimal(l);
		
		//Survie de l'animal
		if(not mortAnimal(l)){
			
			//Cases libres autour du lapin
			EnsCoord voisinsLibres=trouverVoisinsLibres(g1,c1);
			int nbCasesLibres=nbCoord(voisinsLibres);
			
			if(not estVide(voisinsLibres)){
				
				//Choix aléatoire d'une case libre
				Coord c2=randomEC(voisinsLibres);
				//Change la coordonnée du lapin
				deplacerAnimal(l,c2);
				//Sauvegarde dans la grille de la nouvelle place
				placerAnimal(g2,l);
				
				
				//Lapins au voisinage 
				EnsCoord lapins=trouverVoisinsEspece(g1,Lapin,c1);
				//Parmi ceux-là vérification du sexe opposé
				if(sexeOppose(g1,lapins,l)){
					feconderAnimal(l,true);
					placerAnimal(g2,l);
				}
				
				//Test de reproduction du lapin
				if(AnimalEngendre(l,nbCasesLibres)){
							
					//Initialisation du sexe
					Genre sexe=Asexue;
					if(hasard(ProbGenre)) sexe=Male;
					else sexe=Femelle;
					//Création d'un nouvel animal
					Animal nouveau=creerAnimal(Lapin,c1,sexe);
					//Placement de cet animal
					placerAnimal(g2,nouveau);
				}
			}
		}
		enleverCoord(e,c1);
	}
}		

//Déplace tous les renards avec morts et naissances
void deplacerRenard(Grille g1,Grille &g2){
	
	//Tous les renards de la grille
	EnsCoord e=trouverEspece(g1,Renard);
	
	//Parcours de tous les renards
	while(not estVide(e)){
		Coord c1=randomEC(e);
		Animal r=lireCase(g1,c1);
		
		//Diminution de l'état du renard
		faimRenard(r);
		vieillirAnimal(r);
		
		//Survie de l'animal
		if(not mortAnimal(r)){
			
			//Parmi les lapins déjà déplacés 
			//le renard essaye de se nourrir
			if(not attaqueRenard(g2,r)){
				
				//Déplacement sur case libre
				EnsCoord voisinsLibres=trouverVoisinsLibres(g2,c1);
				if(not estVide(voisinsLibres)){
					
					//choix aléatoire d'une case libre
					Coord c2=randomEC(voisinsLibres);
					//Change la coordonnée du renard
					deplacerAnimal(r,c2);
					//Sauvegarde dans la grille de la nouvelle place
					placerAnimal(g2,r);
					
					//Renards au voisinage 
					EnsCoord renards=trouverVoisinsEspece(g1,Renard,c1);
					//Parmi ceux-là vérification du sexe opposé
					if(sexeOppose(g1,renards,r)){
						feconderAnimal(r,true);
						placerAnimal(g2,r);
					}
					
					//Test de reproduction du renard
					if(AnimalEngendre(r,nbCoord(voisinsLibres))){
							
						//Initialisation du sexe
						Genre sexe=Asexue;
						if(hasard(ProbGenre)) sexe=Male;
						else sexe=Femelle;
						//Création d'un nouvel animal
						Animal nouveau=creerAnimal(Renard,c1,sexe);
						//Placement de cet animal
						placerAnimal(g2,nouveau);
					}
				}
			}
		}
		enleverCoord(e,c1);
	}
}

//Vérifie que tous les animaux sont à leur place
bool verifierGrille(const Grille &g){
    for(int i=0;i<taille;i++){
        for(int j=0;j<taille;j++){
            Coord p=creerCoord(i,j);
            Animal a=lireCase(g,p);
            if(not egalCoord(positionAnimal(a),p)) return false;
        }
    }
    return true;
}

// Vérifie que les femelles sont fécondées et les modifie.
void verifierGrossesse(Grille &g){
	for(int i=0;i<taille;i++){
		for(int j=0;j<taille;j++){
			Coord p=creerCoord(i,j);
			Animal a=lireCase(g,p);
			if(existeAnimal(a) and especeAnimal(a)==Lapin and ageAnimal(a)%tempsGrossesseLapin==0){
				feconderAnimal(a,false);
				placerAnimal(g,a);
			}
			if(existeAnimal(a) and especeAnimal(a)==Renard and ageAnimal(a)%tempsGrossesseRenard==0){
				feconderAnimal(a,false);
				placerAnimal(g,a);
			}
		}
	}
}
				

//Renvoie le nombre de chiffres d'un nombre
int nbChiffre(int indice){
	int compteur=0;
	for(int i=10;i<=taille*10;i*=10){
		compteur++;
		if(indice<i) return compteur;
	}
	return compteur;
}

//Renvoie l'indentation nécessaire à l'affichage des lignes
string indentation1(int indice){
	string res=" ";
	int compteur=0;
	while(indice>=10){
	    indice/=10;
	    compteur++;
	}
	for(int i=0;i<compteur;i++){
		res+=" ";
	}
	return res;
}

//Renvoie l'indentation de l'axe vertical
string indentation2(int indice){
	string res="";
	int compteur=nbChiffre(taille)-nbChiffre(indice);
	for(int i=0;i<compteur;i++){
	    res+=" ";
	}    
	return res;
}	

//Affiche une grille sur le terminal
void afficherGrille(const Grille &g){
	
	//Initialisation de l'espace pour l'axe vertical
	string espace=indentation2(1)+"  ";
	cout<<espace;
	
	//Affichage de l'axe horizontal
	for(int i=1;i<=taille;i++){
		cout<<i<<" ";
	}
	cout<<endl;
	
	//Affichage de la grille et de l'axe vertical
	for(int j=1;j<=taille;j++){
		//Affichage de l'axe vertical
		cout<<indentation2(j)<<j;
		for(int i=1;i<=taille;i++){
			
			//Lecture de la case
			Coord p=creerCoord(i-1,j-1);
			Animal a=lireCase(g,p);
			
			//Afichage de la case
			if(especeAnimal(a)==Lapin){
				cout<<indentation1(i)<<"L";
			}
			else if(especeAnimal(a)==Renard){
				cout<<indentation1(i)<<"R";
			}
			else cout<<indentation1(i)<<" ";
		}
		cout<<endl;
	}
}
				
	
	

	
	
