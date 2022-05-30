#include<iostream>
#include"image.hpp"
#include"grille.hpp"
#include"animal.hpp"
#include"enscoord.hpp"
#include<iomanip>
#include<sstream>
#include<fstream>
#include<string>
using namespace std;

void dessinerImage(const Grille &g,int compteurFichier){
    
    int r,v,b;
    ostringstream filename;
    
    //Création d'un nouveau nom de fichier
    filename<<"img"<<setfill('0')<<setw(3)<<compteurFichier<<".ppm";
    
    //Ouverture du fichier et création
    ofstream fic(filename.str());
    
    //Ecriture de l'entete
    fic<<"P3"<<endl
       <<taille*taille_pix<<" "<<taille*taille_pix<<endl
       <<255<<endl;
	   
	//Ecriture des pixels en parcourant la grille
	for(int i=0;i<taille;i++){
		
		//Tracé sur la hauteur
		for(int h=0;h<taille_pix;h++){
			
			for(int j=0;j<taille;j++){
			
				//Tracé d'une ligne
				for(int k=0;k<taille_pix;k++){
				
					//Calcul de la couleur
					Coord p=creerCoord(i,j);
					Animal a=lireCase(g,p);
					if(especeAnimal(a)==Lapin){
						r=0;v=0;b=255;
					}
					else if(especeAnimal(a)==Renard){
						r=255;v=0;b=0;
					}
					else{
						r=0;v=255;b=0;
					}
			
				//Ecriture de la couleur dans le fichier
				fic<<r<<" "<<v<<" "<<b<<endl;
				}
			}
		}
	}
    
    //Fermeture du fichier
    fic.close();
    
}
       
    
