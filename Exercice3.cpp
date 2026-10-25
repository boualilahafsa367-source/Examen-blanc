#include <iostream>
#include <string>
using namespace std;

// Question 1 : classe mère avec attributs protégés
// (protected = accessibles dans la classe mère ET les classes dérivées)
class Vehicle; // (pas nécessaire, juste pour la lisibilité)

class Vehicule {
protected:
    string immatriculation;
    string marque;
    double vitesseMax;

public:
    // Question 2 : constructeur paramétré
    Vehicule(string immat, string m, double vMax) {
        immatriculation = immat;
        marque = m;
        vitesseMax = vMax;
    }

    // virtual : permet le polymorphisme (le bon afficherDetails() est choisi à l'exécution)
    virtual void afficherDetails() {
        cout << "Immatriculation : " << immatriculation << endl;
        cout << "Marque : " << marque << endl;
        cout << "Vitesse max : " << vitesseMax << " km/h" << endl;
    }

    // Question 6 : destructeur virtuel
    virtual ~Vehicule() {
        cout << "Destruction d'un Vehicule" << endl;
    }
};

// Question 3 : classe dérivée Voiture
class Voiture : public Vehicule {
private:
    int nombrePortes;
    string typeCarburant;

public:
    // On appelle le constructeur de la classe mère dans la liste d'initialisation
    Voiture(string immat, string m, double vMax, int portes, string carburant)
        : Vehicule(immat, m, vMax) {
        nombrePortes = portes;
        typeCarburant = carburant;
    }

    // Question 4 : redéfinition de la méthode virtuelle
    void afficherDetails() override {
        cout << "--- Voiture ---" << endl;
        Vehicule::afficherDetails();  // on réutilise l'affichage de la classe mère
        cout << "Nombre de portes : " << nombrePortes << endl;
        cout << "Carburant : " << typeCarburant << endl;
    }

    ~Voiture() {
        cout << "Destruction d'une Voiture" << endl;
    }
};

// Question 3 : classe dérivée Camion
class Camion : public Vehicule {
private:
    double capaciteCharge;
    int nombreEssieux;

public:
    Camion(string immat, string m, double vMax, double charge, int essieux)
        : Vehicule(immat, m, vMax) {
        capaciteCharge = charge;
        nombreEssieux = essieux;
    }

    // Question 4 : redéfinition
    void afficherDetails() override {
        cout << "--- Camion ---" << endl;
        Vehicule::afficherDetails();
        cout << "Capacite de charge : " << capaciteCharge << " tonnes" << endl;
        cout << "Nombre d'essieux : " << nombreEssieux << endl;
    }

    ~Camion() {
        cout << "Destruction d'un Camion" << endl;
    }
};

// Question 5 : main avec tableau de pointeurs (polymorphisme)
int main() {
    Vehicule* tab[2];  // tableau de pointeurs vers la classe mère

    tab[0] = new Voiture("A-1234", "Toyota", 180, 5, "Diesel");
    tab[1] = new Camion("B-5678", "Volvo", 110, 20.5, 3);

    // Même appel, mais le comportement dépend du type réel de l'objet
    for (int i = 0; i < 2; i++) {
        tab[i]->afficherDetails();
        cout << endl;
    }

    // Libération de la mémoire
    for (int i = 0; i < 2; i++) {
        delete tab[i];
    }

    return 0;
}
/*
Question 6 :
Quand on supprime un objet dérivé via un pointeur Vehicule*, si le destructeur n’est pas virtual,
 C++ appelle seulement le destructeur de Vehicule.
  Le destructeur de Voiture ou Camion n’est pas exécuté, ce qui peut causer des fuites mémoire. Avec virtual, le bon destructeur (dérivé puis mère) est appelé.

Sortie du delete : Destruction d'une Voiture puis Destruction d'un Vehicule (idem pour le camion).
*/