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
#include "ProduitA.h"
#include "ProduitB.h"
#include "ProduitC.h"
#include "ProduitD.h"
#include "ProduitE.h"
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
void testProduits();
void testCommandes();
void testInventaire();

int main()
{
	//testComposants();
	//testProduits();
	//testCommandes();
	testInventaire();
	//commerce();
	afficherInformation();
	return 0;
}

void afficherInformation()
{
	cout << endl << endl;
	cout << endl << "-------------------------------" << endl
		<< " NB constructeurs       : " << Compteur::getNbConstructeurs() << endl
		<< " NB constructeurs copie : " << Compteur::getNbConstructeursCopie() << endl
		<< " NB destructeurs        : " << Compteur::getNbDestructeurs() << endl;
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

void testProduits()
{
	Composant1* c1 = new Composant1(98, 45); // Appel du constructeur
	Composant2* c2 = new Composant2(96, 33); // Appel du constructeur
	Composant3* c3 = new Composant3(22); // Appel du constructeur
	Composant4* c4 = new Composant4(100); // Appel du constructeur
	Composant5* c5 = new Composant5(2, 77, 100); // Appel du constructeur
	ProduitA produitA; // Appel du constructeur
	produitA.ajouterComposant(c1);
	produitA.ajouterComposant(c2);
	produitA.ajouterComposant(c3);
	ProduitB produitB; // Appel du constructeur
	produitB.ajouterComposant(c4);
	produitB.ajouterComposant(c5);
	ProduitC produitC; // Appel du constructeur
	produitC.ajouterComposant(new Composant(*c1));
	ProduitD produitD; // Appel du constructeur
	produitD.ajouterComposant(new Composant(*c2));
	ProduitE produitE; // Appel du constructeur
	produitE.ajouterComposant(new Composant(*c3));
	ProduitA* produitACC = new ProduitA(produitA); // Appel du constructeur par copie
	ProduitB produitBCC(produitB); // Appel du constructeur par copie
	list<Produit*> mesProduits;
	mesProduits.push_back((Produit*)&produitA);
	mesProduits.push_back((Produit*)&produitB);
	mesProduits.push_back((Produit*)&produitC);
	mesProduits.push_back((Produit*)&produitD);
	mesProduits.push_back((Produit*)&produitE);
	mesProduits.push_back((Produit*)produitACC);
	mesProduits.push_back((Produit*)&produitBCC);
	for (Produit* produit : mesProduits)
		cout << *produit << endl; // Validation de la méthode virtuelle
	delete produitACC;
}

void testCommandes()
{
	int quantites[5] = { 2, 4, 6, 8, 10 };
	Commande* c1 = new Commande(12345, quantites);
	Commande cc(*c1);
	int quantites2[5] = { -2, 0, 6, 18, 10093498 };
	Commande c2(67890, quantites2);
	cout << *c1 << endl;
	cout << cc << endl;
	cout << c2 << endl;
	cout << c2.getNoCommande() << "/" << c2.getQuantiteProduit(3) << endl;
	delete c1;
}

void testInventaire()
{
	Inventaire inventaire;
	inventaire.ajouterProduit(new ProduitA());
	inventaire.ajouterProduit(new ProduitA());
	inventaire.ajouterProduit(new ProduitA());
	inventaire.ajouterProduit(new ProduitB());
	inventaire.ajouterProduit(new ProduitB());
	inventaire.ajouterProduit(new ProduitC());
	inventaire.ajouterProduit(new ProduitD());
	inventaire.ajouterProduit(new ProduitE());
	Inventaire* inventaireCC = new Inventaire(inventaire);
	Produit* produits[6];
	produits[0] = inventaire.recupererProduit(0); // un produitA
	produits[1] = inventaire.recupererProduit(0); // un produitA
	produits[2] = inventaire.recupererProduit(1); // un produitB
	produits[3] = inventaire.recupererProduit(2); // un produitC
	produits[4] = inventaire.recupererProduit(3); // un produitD
	produits[5] = inventaire.recupererProduit(4); // un produitE
	Produit* produit = inventaire.recupererProduit(0);
	ProduitA* produitCopie = new ProduitA(*((ProduitA*)produit));
	produit->ajouterComposant(new Composant1(100, 20));
	produit->ajouterComposant(new Composant2(90, 50));
	produit->ajouterComposant(new Composant5(10, 85, 30));
	cout << "ORIGINAL --> " << *produit << endl;
	cout << "COPIE    --> " << *produitCopie << endl;
	delete produit;
	delete produitCopie;
	for (Produit* produit : produits)
		cout << *produit << endl;
	for (int x = 0; x < 6; x++)
		delete produits[x];
	delete inventaireCC;
}

void commerce()
{
	// VOTRE CODE DE PROJET SERA ICI
}