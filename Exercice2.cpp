#include <iostream>
#include <string>
using namespace std;

// Question 1 : classe avec encapsulation
class CompteBancaire {
private:                    // attributs privés : inaccessibles depuis l'extérieur
    int numero;
    string titulaire;
    double solde;

public:
    // Question 2 : constructeur paramétré
    CompteBancaire(int num, string nom, double soldeInitial) {
        numero = num;
        titulaire = nom;
        solde = soldeInitial;
    }

    // Question 3 : méthodes

    // Dépôt : seulement si le montant est positif
    void deposer(double montant) {
        if (montant > 0) {
            solde += montant;
        } else {
            cout << "Montant invalide." << endl;
        }
    }

    // Retrait : montant positif ET solde suffisant
    void retirer(double montant) {
        if (montant > 0 && montant <= solde) {
            solde -= montant;
        } else {
            cout << "Retrait impossible." << endl;
        }
    }

    // Affiche les informations du compte
    void afficher() {
        cout << "Compte numero " << numero << endl;
        cout << "Titulaire : " << titulaire << endl;
        cout << "Solde : " << solde << " DH" << endl;
    }
};

// Question 4 : programme principal
int main() {
    // Création de deux comptes
    CompteBancaire c1(101, "Amina", 1000);
    CompteBancaire c2(102, "Youssef", 500);

    c1.deposer(300);   // dépôt sur le compte 1 : 1000 + 300 = 1300
    c2.retirer(200);   // retrait sur le compte 2 : 500 - 200 = 300

    // Affichage des deux comptes
    c1.afficher();
    c2.afficher();

    return 0;
}