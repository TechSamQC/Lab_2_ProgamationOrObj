//Partie en-tête
//Nom : Samuel Brassard
//Programme : Labo 2 - Commerce
//Date de création : 03/10/2024
//Date de dernière modification : 03/10/2024

//Clauses d'inclusion
#include <iostream>
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
#include "Commande.h"
#include "Client.h"
#include "hasard.h"

using namespace std;

int Compteur::constructeur = 0;
int Compteur::constructeurCopie = 0;
int Compteur::destructeur = 0;

void afficherInformation();
void commerce();

int main()
{
	commerce();
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

void commerce()
{
	// VOTRE CODE DE PROJET SERA ICI
}