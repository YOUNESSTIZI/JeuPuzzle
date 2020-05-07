#include<stdlib.h>
#include<stdio.h>
#include<ctype.h>
#include<time.h>



void affichage(char M[3][3]) // cette procedure sert à afficher a chaque fois le tableau !
{
	int i=0;
	printf("--------- --------\n") ;
	for(i=0;i<3;i++)
	{
		
		printf("| %c     %c     %c |\n",M[i][0],M[i][1],M[i][2]) ;
	}
	
} 



int vide(char M[3][3],int casevide[2])  // cette fonction retourne la case vide de la table !! il retourne le num de la case de 1 a 9
{
	int i,j ;
	for(i=0;i<3;i++)
	{
		for(j=0;j<3;j++)
		{
			if(M[i][j] ==' ')
			{
				casevide[0] = i ; // on conserve les coordonnee de la case vide dans un pointeur !!
				casevide[1] = j ;
				
				return(1+j+(3*i));
			}
				
				
		}
	}
	
}


char mvt() // cette fonction retourne le mouvement demandé par l'utilisateur // soit left>a / right>d/up>w /down>s 
{
	char mvt ;
	
	fflush(stdin);
	scanf("%c",&mvt);
	getchar();
	mvt=toupper(mvt); // le mvt est en majiscule 
	
	return mvt ; 
	
	
}




char hasard() // cette fonction return un mvt au hasard !! 
{
	int has ; // le nombre au hasard .. il faut aue ca sera compris entre 1 et 4 chaque nombre correspond a un mvt !
	srand(time(NULL));
	has = (rand()%4) + 1 ;
	
	switch(has)
	{
		case(1):
			{
				return 'W';
				break;
			}
			
		case(2):
			{
				return 'A';
				break;
			}			
		case(3):
			{
				return 'S';
				break;
			}
		case(4):
			{
				return 'D';
				break;
			}				
	}
	
	
}





char limit(char M[3][3],int casevide[2],int automatic)  //cette fonction verifie la possibilité du mvt selon la case vide actuel et le mvt demandee .. on utilise qwerty 
{
	
	/* cette fonction s'occupe de demander le mvt et verifier la case vide et ensuite rejeter ou accepter le mvt */
	
	char mvt_choisit ; // d'abord on demande le mvt 
	switch(automatic)
	{
		case(0):
			{
				mvt_choisit = mvt() ;
				break;
			}
		case(1):
			{
				mvt_choisit = hasard() ;
				
				
				break;				
			}
			
		
	}
	
	
	switch(mvt_choisit) // maintenant on trait la demande selon la case vide // si le mvt est possible on reseve sur le mvt sinon on le transforme en rejet / 
	{
		case('W'): // on travail avec un clavier 'qwerty' pas 'azerty'  
			{
				if(vide(M,casevide)==7 || vide(M,casevide)==8 || vide(M,casevide)==9 ) // si les cases vides sont qu dessous de tablette on ne peut pas faire monter une piece alors on rejette le mvt 
					{
						mvt_choisit = 'r' ;
					}
				break;	
			}
		
		case('A'):
			{
				if(vide(M,casevide)==3 || vide(M,casevide)==6 || vide(M,casevide)==9 )  
					{
						mvt_choisit = 'r' ;
					}	
				break;
				
			}
			
		case('S'):
			{
				if(vide(M,casevide)==1 || vide(M,casevide)==2|| vide(M,casevide)==3 )  
					{
						mvt_choisit = 'r' ;
					}	
				break;
				
			}
			
		case('D'):
			{
				if(vide(M,casevide)== 1 ||vide(M,casevide)==4 || vide(M,casevide)==7  )  
					{
						mvt_choisit = 'r' ;
					}	
				break;
			}
		default :
			{
				mvt_choisit = 'r' ;
				
			}
			
	
	}
	
	printf("%c",mvt_choisit) ;
	return mvt_choisit ;
	

}




void trait(char M[3][3] , int casevide[2],int automatic) // cette fonction s'occupe de tout ! commencant par l'affichage passant par la verification du mvt si il est valalable .. l'executer puis reafficher la table !
{
	char c=limit(M,casevide,automatic);
	int i=0 ;
	
	if(automatic == 0 )
		{
		
				while(c=='r') // ici on repete la boucle pour que on ira un mvt valable  
				{
					printf("\n peut etre la case entree n'est pas valable reessayee ..!!\n..");
					c=limit(M,casevide,automatic);
				}
				
		}
	if(automatic == 1)	// on est pas besoin d'afficher la table si les tache sont faites automatiauement
		{
			while(c=='r') // ici on repete la boucle pour que on ira un mvt valable  
				{
					c=limit(M,casevide,automatic);
				}
			}	
		
	
	
	
	
	switch(c) // c bon maintenant au'on a verifie aue le mvt peut etre effectuer on l'execute :) 
	{	//c ici ou on va servir du pointeur d case vide 
		case('W') :
			{
				M[*(casevide)][*(casevide+1)] = M[*(casevide)+1][*(casevide+1)] ;
				M[*(casevide)+1][*(casevide+1)] = ' ' ;
				break;
			}
		case('S'):
			{
				M[*(casevide)][*(casevide+1)] = M[*(casevide)-1][*(casevide+1)] ;
				M[*(casevide)-1][*(casevide+1)] = ' ' ;
				break;
			}
		case('D'):
			{
				M[*(casevide)][*(casevide+1)] = M[*(casevide)][*(casevide+1)-1] ;
				M[*(casevide)][*(casevide+1)-1] = ' ' ;
				break;
			}
		case('A'):
			{
				M[*(casevide)][*(casevide+1)] = M[*(casevide)][*(casevide+1)+1] ;
				M[*(casevide)][*(casevide+1)+1] = ' ' ;
				break;
			}					
	}
	
	if(automatic != 1 )
			{
				while(i<5) // cette boucle est pour sauter les lignes et renouveler le console en qlq sorte ;)!!
				{
					printf("\n");
					i++;
				}
				affichage(M);
		}
		
	
	

}




void mvt_hasard(char M[3][3] , int casevide[2],int automatic,int diff) // cette fonction assure que le mvt au hasard est valable on l'execute ..sinon on redemande au pc de choisir un autre mvt !! on execute diff fois !!
{
	int i=0;
	
	
	while(i<diff)
	{
		trait(M,casevide,automatic);
		i++;
	}
	
	
	affichage(M);
	
	
}

int ver_trii(char M[3][3]) // cette fonction verifie si on a bien trier la tablette ou nn !
{
	int c=0;
	
	if(M[2][0]=='7' && M[2][1]=='8' && M[2][2]==' ')
		c++;
		
	if(c== 1 && M[1][0]=='4' && M[1][1]=='5' && M[1][2]=='6')
		c++;
	
	if(c==2 && M[0][0]=='1' && M[0][1]=='2' && M[0][2]=='3')
		return 1;
	
		
	return 0;	
			
}


void jouer(char M[3][3] , int casevide[2])
{
	int diff ;
//	affichage(M);
	printf("\n\n la difficulte est citee en 20 vous pouvez la changer :) .... ");
	scanf("%d",&diff);
	
	printf("\n\n\n c est partiii .. att qlq secondes stp :)\n\n\t\t");
	
	mvt_hasard(M,casevide,1,diff) ;
	printf("\n\n\t\t -- bonne chance.... ");

	
	
	
	do
	{
		trait(M,casevide,0);
	}while(ver_trii(M)==0);
	
	printf("\n\n -------------BIEN JOUER------------ ");

	
	
	
}










