/*Question 1:
_Résultat affiché :
15 20
_explication : a est passé par référence, donc x devient 10 + 5 = 15.
b est passé par valeur : seule la copie change (30), y reste à 20.*/

/*Question 2:
Le passage par valeur envoie à la fonction une copie de la variable : si la copie change, l’original reste intact (ici y reste à 20).
Le passage par référence envoie la variable elle-même sous un autre nom : toute modification dans la fonction touche l’original (ici x passe à 15).*/


/*Question 3:
Fonction modifiée pour changer les deux variables:*/
void modifier(int &a, int &b) { // & sur les DEUX paramètres
    a += 5;  // x devient 15
    b += 10; // y devient 30 (avant : seule la copie changeait)
}
//Nouveau résultat : 15 30.

/*Question 4:
Rôle de l'opérateur &:

Dans la déclaration d'un paramètre, 
& indique que le paramètre est une référence : il devient un autre nom pour la variable passée en argument, sans copie.
 Ainsi, toute modification faite dans la fonction agit directement sur la variable d'origine.*/