[![Puissance4](https://gitlabiut.iutlan.univ-rennes1.fr/maxperrot/puissance4/-/raw/main/images/logo_transparent.png)](https://gitlabiut.iutlan.univ-rennes1.fr/maxperrot/puissance4)

Jeu de Puissance4 en C réalisé dans le cadre de la SAÉ1.02 : Comparaison d'approches algorithmiques

# Stratégie 1 : Le complément à trois

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

Ici l'IA a la possibilité de gagner en alignant ses 4 pions donc elle applique la priorité n°1 : GAGNER !

# Contacts

Duncan Cadoret
> Discord : CADORET Duncan#5071
> Gitlab : dcadoret

Maxime Perrot
> Discord : Maxime#7805
> Gitlab : maxperrot
