[![Puissance4](https://gitlabiut.iutlan.univ-rennes1.fr/maxperrot/puissance4/-/raw/main/images/logo_transparent.png)](https://gitlabiut.iutlan.univ-rennes1.fr/maxperrot/puissance4)

Jeu de Puissance4 en C réalisé dans le cadre de la SAÉ1.02 : Comparaison d'approches algorithmiques

# Stratégie 1 : Le complément à trois

par Duncan Cadoret

L'ordinateur joue les pions rouges.

- [Début de partie](#début-de-partie)
- [Milieu de partie (Priorité n°2)](#milieu-de-partie-priorité-n2)
- [Milieu de partie (Priorité n°3)](#milieu-de-partie-priorité-n3)
- [Milieu de partie (Priorité n°4)](#milieu-de-partie-priorité-n4)
- [Gagner la partie (Priorité n°1)](#gagner-la-partie-priorité-n1)

## Ordre de priorité des actions : 

1. Si on peut gagner on gagne !
2. Empêcher l'adversaire d'aligner 3 ou 4 pions (Bien sûr, on préférera empêcher l'adversaire d'aligner 4 pions dans le cas) où les deux conditions seraient remplies). 
3. Si on peut aligner 3 pions on le fait !
4. Sinon on joue au hasard dans le tableau.

## Début de partie

![Partie 1](https://gitlabiut.iutlan.univ-rennes1.fr/maxperrot/puissance4/-/raw/main/images/parties/partie1.png)

La seule action que peut exécuter l'IA correspond à la n°4 dans l'ordre de priorité soit "jouer au hasard" ainsi l'IA a choisi une colonne au hasard entre 0 et 6.

## Milieu de partie (Priorité n°2)

![Partie 2.1](https://gitlabiut.iutlan.univ-rennes1.fr/maxperrot/puissance4/-/raw/main/images/parties/partie2-1.png)
![Partie 2.2](https://gitlabiut.iutlan.univ-rennes1.fr/maxperrot/puissance4/-/raw/main/images/parties/partie2-2.png)

Dans l'ordre de priorité, la première action qui vient est la n°2 soit : empêcher l'adversaire d'aligner 3 ou 4 pions.

## Milieu de partie (Priorité n°3)

![Partie 2.3](https://gitlabiut.iutlan.univ-rennes1.fr/maxperrot/puissance4/-/raw/main/images/parties/partie2-3.png)
![Partie 2.4](https://gitlabiut.iutlan.univ-rennes1.fr/maxperrot/puissance4/-/raw/main/images/parties/partie2-4.png)

Dans l'ordre de priorité, la première action qui vient est la n°3 soit : aligner 3 pions puisque c'est possible, ce n'est cependant pas le meilleur coup possible.

## Milieu de partie (Priorité n°4)

![Partie 2.5](https://gitlabiut.iutlan.univ-rennes1.fr/maxperrot/puissance4/-/raw/main/images/parties/partie2-5.png)
![Partie 2.6](https://gitlabiut.iutlan.univ-rennes1.fr/maxperrot/puissance4/-/raw/main/images/parties/partie2-6.png)

Dans le cas de figure à gauche aucune des premières conditions n'est possible donc l'IA pose un pion dans une colonne aléatoire ce qui peut comme dans le cas de droite parfois être un coup plutôt bon puisqu'il crée de multiples occasions futures.

## Gagner la partie (Priorité n°1)

![Partie 2.7](https://gitlabiut.iutlan.univ-rennes1.fr/maxperrot/puissance4/-/raw/main/images/parties/partie2-7.png)
![Partie 2.8](https://gitlabiut.iutlan.univ-rennes1.fr/maxperrot/puissance4/-/raw/main/images/parties/partie2-8.png)

Ici l'ordinateur a la possibilité de gagner en alignant ses 4 pions donc elle applique la priorité n°1 : GAGNER !

# Stratégie 2 : MAD Algorithm

par Maxime Perrot

L'algorithme Milieu Attaque Défense (MAD) possède plusieurs fonctionnalités :
- Evaluer si une case permet à l'adversaire de gagner
- Evaluer si une case lui permet de gagner
- Evaluer si une ligne de 2 pions peut être améliorée en ligne de 3 ou 4 pions

## Actions possibles :

- Milieu
  1. Placer le pion le plus proche du milieu
- Attaque
  1. Aligner 4 pions qui mèneront à une ligne de 4
  2. Aligner 3 pions qui mèneront à une ligne de 4
  3. Aligner 2 pions qui mèneront à une ligne de 4
- Défense
  1. Empêcher l'adversaire d'aligner 4 pions qui mèneront à une ligne de 4
  2. Empêcher l'adversaire d'aligner 3 pions qui mèneront à une ligne de 4
  3. Empêcher l'adversaire d'aligner 2 pions qui mèneront à une ligne de 4
  4. Placer le pion au dessus du dernier pion ennemi

## Ordre des priorités :

Du plus important au moins important :

1. Aligner 4 pions qui mèneront à une ligne de 4
2. Empêcher l'adversaire d'aligner 4 pions qui mèneront à une ligne de 4
3. Empêcher l'adversaire d'aligner 3 pions qui mèneront à une ligne de 4
4. Aligner 3 pions qui mèneront à une ligne de 4
5. Aligner 2 pions qui mèneront à une ligne de 4
6. Placer le pion au dessus du dernier pion ennemi
7. Empêcher l'adversaire d'aligner 2 pions qui mèneront à une ligne de 4
8. Placer le pion au plus proche du milieu

Si plusieurs actions d'une même priorités sont possibles, l'une d'entre elle sera choisie aléatoirement

Si l'action à une priorité inférieur à 2 et la case au dessus du pion potentiellement posé mène à une victoire de l'adversaire, il passe à l'action suivante et banni cette case des possibilités (sauf au cas où c'est la seule action possible)

## Algorithme

L'algorithme exécute la première action possible dans l'ordre d'importance.

## Exemple contre un algorithme imbattable :

Notre algorithme commence avec les rouges.



![Partie 3.1](https://gitlabiut.iutlan.univ-rennes1.fr/maxperrot/puissance4/-/raw/main/images/parties/partie3-1.png)

![Partie 3.2](https://gitlabiut.iutlan.univ-rennes1.fr/maxperrot/puissance4/-/raw/main/images/parties/partie3-2.png)

On passe quelques étapes

![Partie 3.3](https://gitlabiut.iutlan.univ-rennes1.fr/maxperrot/puissance4/-/raw/main/images/parties/partie3-3.png)

On passe quelques étapes

![Partie 3.4](https://gitlabiut.iutlan.univ-rennes1.fr/maxperrot/puissance4/-/raw/main/images/parties/partie3-4.png)

![Partie 3.5](https://gitlabiut.iutlan.univ-rennes1.fr/maxperrot/puissance4/-/raw/main/images/parties/partie3-5.png)

![Partie 3.6](https://gitlabiut.iutlan.univ-rennes1.fr/maxperrot/puissance4/-/raw/main/images/parties/partie3-6.png)

![Partie 3.7](https://gitlabiut.iutlan.univ-rennes1.fr/maxperrot/puissance4/-/raw/main/images/parties/partie3-7.png)

![Partie 3.8](https://gitlabiut.iutlan.univ-rennes1.fr/maxperrot/puissance4/-/raw/main/images/parties/partie3-8.png)

![Partie 3.9](https://gitlabiut.iutlan.univ-rennes1.fr/maxperrot/puissance4/-/raw/main/images/parties/partie3-9.png)

![Partie 3.10](https://gitlabiut.iutlan.univ-rennes1.fr/maxperrot/puissance4/-/raw/main/images/parties/partie3-10.png)

![Partie 3.11](https://gitlabiut.iutlan.univ-rennes1.fr/maxperrot/puissance4/-/raw/main/images/parties/partie3-11.png)

![Partie 3.12](https://gitlabiut.iutlan.univ-rennes1.fr/maxperrot/puissance4/-/raw/main/images/parties/partie3-12.png)

![Partie 3.13](https://gitlabiut.iutlan.univ-rennes1.fr/maxperrot/puissance4/-/raw/main/images/parties/partie3-13.png)

![Partie 3.14](https://gitlabiut.iutlan.univ-rennes1.fr/maxperrot/puissance4/-/raw/main/images/parties/partie3-14.png)

![Partie 3.15](https://gitlabiut.iutlan.univ-rennes1.fr/maxperrot/puissance4/-/raw/main/images/parties/partie3-15.png)

![Partie 3.16](https://gitlabiut.iutlan.univ-rennes1.fr/maxperrot/puissance4/-/raw/main/images/parties/partie3-16.png)


# Contacts

Duncan Cadoret

> Email : duncan.cadoret@etudiant.univ-rennes1.fr
>
> Discord : CADORET Duncan#5071
>
> Gitlab : @dcadoret

Maxime Perrot

> Email : maxime.perrot@etudiant.univ-rennes1.fr
>
> Discord : Maxime#7805
> 
> Gitlab : @maxperrot
>
> Keybase : https://keybase.io/maxperrot
