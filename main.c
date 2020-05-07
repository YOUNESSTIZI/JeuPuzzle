#include<stdlib.h>
#include<stdio.h>
#include<conio.h>
#include"edit.c"
#include"edit.h"

/*ce jeu consiste à jouer avec z;a;d;s; on demande à l'utilisateur d'organiser les pieces à l'aides des mvts possibles sur la case vide !! ca roule dans une tablette de 9 pièces ! 
et une case libre .. les entree sont w a s d soit miniscule ou majiscule */ 


int main()
 {
 	char M[3][3]={'1','2','3','4','5','6','7','8',' '},c ;
 	int i=0;
 	
 	int casevide[2]={0,0}; /* c'est un pointeur qui pointe sur la case vide !! la premiere case conserve la ligne la deuxieme conserve la colonne on va se sevir de ses coordonnee dans la fonction
 	traitement */
 	affichage(M);
 	printf("\n\n\tsi vous n'avez aucune idee sur le jeu !\n\t\t ecrit 'H' ....sinon tapez sur qlq chose autre !");
 	scanf("%c",&c) ;
 	getchar();
 	
 	if(c == 'H')
 	{
 		printf("\n\n Le jeu consiste a organiser les nombres de la table \ncomme affichee ci dessus :) .. \n\n ....Selon la difficulte choisit \n.. l'ordinateur va perturber l'ordre des chiffres ");
 		printf("\n\t c a vous de les organiser on utilisant ces touches\n \n w >> \t up \n s >>  \t down \n a >> \t left \n d >>  \t right  ");
 		getchar();
 		
	 }
	
	
	while(i<5) // cette boucle est pour sauter les lignes et renouveler le console en qlq sorte ;)!!
		{
			printf("\n");
			i++;
		}
 	
 	jouer(M,casevide);
 	getchar() ;

 	
 


 }
