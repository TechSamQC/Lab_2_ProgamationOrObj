//Partie en-tête
//Nom : Samuel Brassard
//Programme : Labo 2 - Commerce
//Date de création : 03/10/2024
//Date de dernière modification : 10/10/2024

//Clauses d'inclusion
#include <iostream>
#include <list>
#include "BonCommande.h"
#include "Reception.h"
#include "RapportAssuranceQualite.h"
#include "Produit.h"
#include "Inventaire.h"
#include "Fournisseur.h"
#include "Entreprise.h"
#include "Entrepot.h"
#include "Compteur.h"
#include "Composant.h"
#include "Composant1.h"
#include "Composant2.h"
#include "Composant3.h"
#include "Composant4.h"
#include "Composant5.h"
#include "Commande.h"
#include "Client.h"
#include "hasard.h"

using namespace std;

int Compteur::constructeur = 0;
int Compteur::constructeurCopie = 0;
int Compteur::destructeur = 0;

void afficherInformation();
void commerce();
void testComposants();

int main()
{
	testComposants();
	//commerce();
	afficherInformation();
	return 0;
}

void afficherInformation()
{
	cout << endl << endl;
	cout << endl << "-------------------------------" << endl
		<< " NB constructeurs : " << Compteur::getNbConstructeurs() << endl
		<< " NB constructeurs copie : " << Compteur::getNbConstructeursCopie() << endl
		<< " NB destructeurs : " << Compteur::getNbDestructeurs() << endl;
	cin.get();
}

void testComposants()
{
	Composant1* c1 = new Composant1(98, 45); // Appel du constructeur
	Composant2* c2 = new Composant2(96, 33); // Appel du constructeur
	Composant3* c3 = new Composant3(22); // Appel du constructeur
	Composant4* c4 = new Composant4(100); // Appel du constructeur
	Composant5* c5 = new Composant5(2, 77, 100); // Appel du constructeur
	Composant1 cc(*c1); // Appel du constructeur par copie
	cout << "cc : " << cc.getNom() << "/" << cc.getPoids() << "/" << cc.getPrix() << "/" << cc.getQualite() << endl;
	list<Composant*> composants; // Création d'une liste de Composant*
	composants.push_back(c1); // Ajout dans la liste
	composants.push_back(c2); // Ajout dans la liste
	composants.push_back(c3); // Ajout dans la liste
	composants.push_back(c4); // Ajout dans la liste
	composants.push_back(c5); // Ajout dans la liste
	// Affichage de chaque composant
	for (Composant* composant : composants) // Pour chaque composant de la liste
		cout << composant->getNom() << "/" << composant->getPoids() << "/" << composant->getPrix() << "/" << composant->getQualite() << endl;
	// Suppression de chaque composant
	while (!composants.empty())
	{
		Composant* composant = composants.front(); // Récupération du dernier composant*
		composants.pop_front();
		// Il est retiré de la liste
		delete composant; // Maintenant on le supprime pour libérer la mémoire
	}
	// à la fin de la fonction, la liste (qui n'est pas un pointeur se supprime automatiquement car elle est sur la pile
}

void commerce()
{
	// VOTRE CODE DE PROJET SERA ICI
}