void affichage(char* M); // cette procedure sert à afficher a chaque fois le tableau ! ]

char mvt(); // cette fonction retourne le mouvement demandé par l'utilisateur // soit left>a / right>d/up>w /down>s]

int vide(char M[3][3]) ; // cette fonction retourne la case vide de la table !! il retourne le num de la case de 1 a 9]

int limit(char* M) ; //cette fonction verifie la possibilité du mvt et retourn 0 ou 1 ]

void trait(char* M) ; // cettte procedure sert à executer le nouveau mvt ! ]

char hasard(); // cette fonction retourne un mvt par hasard fait par l'ordinateur !! selon la case libre et la limite

void mvt_hasard();//cette procedure assure que le mvt et valable sinon on redemande un autre mvt au processeur ;

bool verif(char *M) ; // il verifie si les pieces sont triee ou nn /
