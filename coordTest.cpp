//Fichier de test du type abstrait coordonnées du projet Info121

#include <iostream>
#include "coord.hpp"
using namespace std;

/** Infrastructure minimale de test **/
#define ASSERT(test) if (!(test)) cout << "Test failed in file " << __FILE__ \
                                       << " line " << __LINE__ << ": " #test << endl

void CoordTest(){
	
	//Tests automatiques
	Coord A=creerCoord(12,9);
	Coord B=creerCoord(12,8);
	Coord C=creerCoord(13,9);
	Coord D=creerCoord(12,9);
	ASSERT(getX(A)==12 and getY(A)==9);
	ASSERT(getX(B)==12 and getY(B)==8);
	ASSERT(getX(C)==13 and getY(C)==9);
	ASSERT(getX(D)==12 and getY(D)==9);
	ASSERT(not egalCoord(A,B));
	ASSERT(not egalCoord(A,C));
	ASSERT(egalCoord(A,D));
	
	//Tests d'affichage
	afficherCoord(A);
	afficherCoord(B);
	afficherCoord(C);
	afficherCoord(D);

}

//Lancement des tests
int main(){
	CoordTest();
}