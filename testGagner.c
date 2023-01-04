
/******************************************************************************
 **  Calcul de l'efficacité de stratégies de puissance4                      **
 **                                                                          **
 **  Duncan Cadoret 1E2 I, Maxime Perrot 1E1 I                               **
 **  Version 1.0                                                             **
 **  A rendre pour le 8 janvier 2023                                         **
 **  Gitlab : https://gitlabiut.iutlan.univ-rennes1.fr/maxperrot/puissance4  **
 **  Fichier : testGagner.c                                                  **
 ******************************************************************************/

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <time.h>
#include <limits.h>

// Les constantes
#define NB_LIGNES 6
#define NB_COLONNES 7
#define PION_A 'X'
#define PION_B 'O'
#define VIDE ' '
#define INCONNU ' '

// Les types
typedef int Grille[NB_LIGNES][NB_COLONNES];
typedef int Choix[NB_COLONNES];

// Prototypes des fonctions
void initGrille(Grille laGrille);
void afficher(Grille laGrille, char pion);
bool grillePleine(Grille laGrille);
void faireJouerA(Grille laGrille, char pion, int *ligne, int *colonne);
void faireJouerB(Grille laGrille, char pion, int *ligne, int *colonne);
int choisirColonne(Grille laGrille, char pion);
int chercherLigne(Grille laGrille, int col);
bool estVainqueur(Grille laGrille, int lig, int col);
void finDePartie(char vainqueur);
int choisirColonneStrategie1(Grille laGrille, char pion);
int choisirColonneStrategie2(Grille laGrille, char pion);
int choisirColonneStrategie3(Grille laGrille, char pion);
int choisirColonneStrategie4(Grille laGrille, char pion);
void partie(char *vainqueur, int *compteurPionsA, int *compteurPionsB);


// Programme principal. C'est le pion A qui commence à jouer
int main()
{
	char vainqueur;
	int i;
	int compteurPionsA, compteurPionsB;
	int nbPionsA, nbPionsB;
	int nbVictoiresA, nbVictoiresB, nbPartiesNulles, nbParties;
	
	vainqueur = INCONNU;
	compteurPionsA = 0;
	compteurPionsB = 0;
	nbPionsA = 0;
	nbPionsB = 0;
	nbVictoiresA = 0;
	nbVictoiresB = 0;
	nbPartiesNulles = 0;

	printf("┌───────────────────────────────────────────────────────────────┐\n");
	printf("│         IUT Lannion - BUT Informatique 1 - 2022-2023          │\n");
	printf("│       SAE1.02 - Comparaison d'approches algorithmiques        │\n");
	printf("│          Duncan Cadoret 1E2 I, Maxime Perrot 1E1 I            │\n");
	printf("│                                                               │\n");
	printf("│ https://gitlabiut.iutlan.univ-rennes1.fr/maxperrot/puissance4 │\n");
	printf("│                                                               │\n");
	printf("├───────────────────────────────────────────────────────────────┤\n");
	printf("│                                                               │\n");
	printf("│ Jeu de Puissance4 en C avec algorithme de décisions           │\n");
	printf("│                                                               │\n");
	printf("│ Stratégie de %c : Aléatoire                                    │\n", PION_A);
	printf("│ Stratégie de %c : Aléatoire                                    │\n", PION_B);
	printf("└───────────────────────────────────────────────────────────────┘\n");
	
	do
	{
	printf(" > Entrer le nombre de parties : ");
	scanf(" %d", &nbParties);
	} while(nbParties < 1);
	
	srand(time(NULL));
	clock_t debut;
	debut = clock();
	
	for (i = 0; i < nbParties; i++)
	{
		vainqueur = INCONNU;
		compteurPionsA = 0;
		compteurPionsB = 0;
		
		partie(&vainqueur, &compteurPionsA, &compteurPionsB);
		
		if (vainqueur == INCONNU)
		{
			nbPartiesNulles++;
		}
		else if (vainqueur == PION_A)
		{
			nbVictoiresA++;
		}
		else if (vainqueur == PION_B)
		{
			nbVictoiresB++;
		}
		
		nbPionsA += compteurPionsA;
		nbPionsB += compteurPionsB;
	}
	
	clock_t fin;
	fin = clock() - debut;
	float tempsExecution = (fin -  debut) / (CLOCKS_PER_SEC*1.0);
	
	printf("┌───────────────┬───────────────────────┬────────────────────────────┐\n");
	printf("│ Joueur        │ Victoires             │ Pions gagnants par partie  │\n");
	printf("├───────────────┼───────────────────────┼────────────────────────────┤\n");
	printf("│ Joueur %c\t│ %6d (%2.3f%)\t│ %.2f\t\t\t     │\n", PION_A, nbVictoiresA, ((nbVictoiresA*100.0)/nbParties), ((nbPionsA*1.0)/nbParties));
	printf("│ Joueur %c\t│ %6d (%2.3f%)\t│ %.2f\t\t\t     │\n", PION_B, nbVictoiresB, ((nbVictoiresB*100.0)/nbParties), ((nbPionsB*1.0)/nbParties));
	printf("│ Match nuls\t│ %6d (%2.3f%)\t│   \t\t\t     │\n", nbPartiesNulles, ((nbPartiesNulles*100.0)/nbParties));
	printf("└───────────────┴───────────────────────┴────────────────────────────┘\n");
	printf("Temps d'exécution total : %.6fs\n", tempsExecution);
	printf("Temps d'exécution moyen : %.6fµs\n", (tempsExecution/nbParties)*1000000);
    system(EXIT_SUCCESS);
}

/*******************************
 **  Fonctions et procédures  **
 *******************************/

void initGrille(Grille laGrille)
{
    int l, c;
    for (l = 0; l < NB_LIGNES; l++)
    {
        for (c = 0; c < NB_COLONNES; c++)
        {
            laGrille[l][c] = VIDE;
        }
    }
}

bool grillePleine(Grille laGrille)
{
    bool pleine = true;
    int c = 0;
    while (pleine && c < NB_COLONNES)
    {
        if (laGrille[0][c] == VIDE)
        {
            pleine = false;
        }
        c++;
    }
    return pleine;
}

void faireJouerA(Grille laGrille, char pion, int *ligne, int *colonne)
{
    *ligne = -1;
    do
    {
        *colonne = choisirColonneStrategie4(laGrille, pion);
        *ligne = chercherLigne(laGrille, *colonne);
    } while (*ligne == -1);
    laGrille[*ligne][*colonne] = pion;
}

void faireJouerB(Grille laGrille, char pion, int *ligne, int *colonne)
{
    *ligne = -1;
    do
    {
        *colonne = choisirColonneStrategie4(laGrille, pion);
        *ligne = chercherLigne(laGrille, *colonne);
    } while (*ligne == -1);
    laGrille[*ligne][*colonne] = pion;
}

int choisirColonne(Grille laGrille, char pion)
{
    int col;

    do
    {
        printf("Numero de colonne ? ");
        scanf("%d", &col);
    } while (col < 0 || col > 6);
    return col;
}

int chercherLigne(Grille laGrille, int col)
{
    int ligne = -1;

    while (ligne < NB_LIGNES - 1 && laGrille[ligne + 1][col] == VIDE)
    {
        ligne++;
    }

    return ligne;
}

bool estVainqueur(Grille laGrille, int lig, int col)
{
    // consiste à regarder si une ligne de 4 pions s'est formÃ©e autour du pion qui vient de tomber en (lig, col)
    char lePion = laGrille[lig][col];
    int cpt, i, j;

    // regarder la verticale, en comptant le nombre de pions au Sud (inutile de regarder au Nord du pion qui vient de tomber)
    i = lig;
    cpt = 0;
    while (i < NB_LIGNES && laGrille[i][col] == lePion)
    {
        cpt++;
        i++;
    }
    if (cpt >= 4)
    {
        return true;
    }
    
    // regarder l'horizontale, en comptant le nombre de pions à l'Est et à l'Ouest
    j = col;
    cpt = 0;
    
    // on regarde à l'est
    while (j >= 0 && laGrille[lig][j] == lePion)
    {
        cpt++;
        j--;
    }
    j = col + 1;
    
    // on regarde à l'ouest
    while (j < NB_COLONNES && laGrille[lig][j] == lePion)
    {
        cpt++;
        j++;
    }
    if (cpt >= 4)
    {
        return true;
    }
    
    // regarder la diagonale descendante, en comptant le nombre de pions au Nord Ouest et au Sud Est
    i = lig;
    j = col;
    cpt = 0;
    
    // on regarde au Nord Ouest
    while (j >= 0 && i >= 0 && laGrille[i][j] == lePion)
    {
        cpt++;
        i--;
        j--;
    }
    i = lig + 1;
    j = col + 1;
    
    // on regarde au Sud Est
    while (i < NB_LIGNES && j < NB_COLONNES && laGrille[i][j] == lePion)
    {
        cpt++;
        i++;
        j++;
    }
    if (cpt >= 4)
    {
        return true;
    }
    
    // regarder la diagonale descendante, en comptant le nombre de pions au Nord Est et au Sud Ouest
    i = lig;
    j = col;
    cpt = 0;
    
    // on regarde au Nord Est
    while (j < NB_COLONNES && i >= 0 && laGrille[i][j] == lePion)
    {
        cpt++;
        i--;
        j++;
    }
    i = lig + 1;
    j = col - 1;
    
    // on regarde au Sud Ouest
    while (i < NB_LIGNES && j >= 0 && laGrille[i][j] == lePion)
    {
        cpt++;
        i++;
        j--;
    }
    if (cpt >= 4)
    {
        return true;
    }
    
    return false;
}

void partie(char *vainqueur, int *compteurPionsA, int *compteurPionsB)
{
    Grille laGrille;
    int ligne, colonne;
    initGrille(laGrille);
    
    while (*vainqueur == INCONNU && !grillePleine(laGrille))
    {
        faireJouerA(laGrille, PION_A, &ligne, &colonne);
        (*compteurPionsA)++;
        if (estVainqueur(laGrille, ligne, colonne))
        {
            *vainqueur = PION_A;
        }
        else if (!grillePleine(laGrille))
        {
            faireJouerB(laGrille, PION_B, &ligne, &colonne);
            (*compteurPionsB)++;
            if (estVainqueur(laGrille, ligne, colonne))
            {
                *vainqueur = PION_B;
            }
        }
    }	
}

/******************
 **  Stratégies  **
 ******************/

// Stratégie Gauche
int choisirColonneStrategie1(Grille laGrille, char pion)
{
    int lig, col;
    bool caseTrouvee;
    col = 0;
    caseTrouvee = false;

    // On parcourt les colonnes du tableau de gauche a droite
    while (!caseTrouvee) // Tant la case n'est pas trouvée
    {
        lig = chercherLigne(laGrille, col);
        if (lig >= 0) // Si la colonne n'est pas pleine
        {
            caseTrouvee = true; // On renvoit la colonne
        }
        else
        {
            col++;
        }
    }

    return col;
}

// Stratégie MoinsRemplieGaucheDroite
int choisirColonneStrategie2(Grille laGrille, char pion)
{
    int lig, col, ligMaximum, colMinimum;
    ligMaximum = -1;
    colMinimum = NB_LIGNES;

    for (col = 0; col < NB_COLONNES; col++)
    {
        lig = chercherLigne(laGrille, col);
        printf("\n---lig = %d\tligMaximum = %d---\n",lig,ligMaximum);
        if (lig > ligMaximum)
        {
            printf("\n---lig > ligMaximum---\n");
            ligMaximum = lig;
            colMinimum = col;
        }
    }
    printf("\n---colMinimum : %d---\n",colMinimum);
    return colMinimum;
}

// Stratégie MilieuAlterneGaucheDroite
int choisirColonneStrategie3(Grille laGrille, char pion)
{
	Choix tab = {3,2,4,1,5,0,6};
	int res;
	int i;
	i = 0;
	while (laGrille[0][tab[i]]!= VIDE)
	{
    	i = i+1;
	}
	if (laGrille[0][tab[i]] == VIDE)
	{
    	res = tab[i];
	}
	return res;
}

// Stratégie Aleatoire
int choisirColonneStrategie4(Grille laGrille, char pion)
{
	int colonne;
	do
	{
    	colonne = rand() % NB_COLONNES;
	} while (laGrille[0][colonne] != VIDE);
	return colonne;
}

// Stratégie du MAD Algorithm
int MAD_Algorithm(Grille laGrille, char pion)
{
    int poubelle[NB_COLONNES];
    int i;
    int colonne, ligne;
    char pionEnnemi;
    
    colonne = -1; // TEMPORAIRE
    
    // --- Poubelle ---
    
	// Calcul du pion ennemi
    if (pion == PION_A)
    {
		pionEnnemi = PION_B;
	}
    else
    {
		pionEnnemi == PION_A;
	}
    
    for (i = 0; i < NB_COLONNES; i++)
    {
        ligne = chercherLigne(laGrille, i) -1;
        poubelle[i] = danger(laGrille, ligne, i, pionEnnemi);
    }
    
	/*
    if (gagner() != -1)
    {
    }
    else if (stop4() != -1)
    {
    }
    else if (stop3() != -1)
    {
    }
    else if (align3() != -1)
    {
    }
    else if (align2() != -1)
    {
    }
    else if (audessus() != -1)
    {
    }
    else if (stop2() != -1)
    {
    }
    else
    {
    }
    */
    
    return colonne;
}

bool danger(Grille laGrille, int lig, int col, char pionEnnemi)
{
    // Envoie une grille dans laquelle le pion (lig ; col) est un pion ennemi dans la fonction estVainqueur()
	Grille grilleTemp;
	
	copieGrille(laGrille, grilleTemp);
	grilleTemp[lig][col] = pionEnnemi;
	
	return estVainqueur(grilleTemp, lig, col);
}

void copieGrille(Grille g1, Grille g2)
{
	int x, y;
	
	for (y = 0; y < NB_LIGNES; y++)
	{
		for (x = 0; x < NB_COLONNES; x++)
		{
			g2[y][x] = g1[y][x];
		}
	}
}


int gagner(Grille laGrille, int ligne, int colonne, char monPion){
    int res = -1;
    Grille grilleTemp;
    copieGrille(laGrille, grilleTemp);
    grilleTemp[ligne][colonne] = monPion;
    if (estVainqueur(grilleTemp, ligne, colonne))
    {
        res = colonne;
    }
    return res;
}
