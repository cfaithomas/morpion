#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

/**************************************variables globales************************************************************/
int cptcoup=0;
char jeu[3][3];
bool gagne=false;
bool tab[2]={false,false};


void affichejeu(); //affiche la grille
void initjeu(); //remplissage a blanc
bool verificationcoup(int l,int c);
void jouer();
char determinesymbole();
bool verifgagneligne();
bool verifgagnecolonne();
bool verifgagnediagonale();
bool checktabbool();

void affichejeu() {


    printf("      0         1         2\n");
    printf("0     %c    |   %c    |   %c\n", jeu[0][0], jeu[0][1], jeu[0][2]);
    printf("   --------|--------|--------\n");
    printf("1     %c    |   %c    |   %c  \n", jeu[1][0], jeu[1][1], jeu[1][2]);
    printf("   --------|--------|--------\n");
    printf("2     %c    |   %c    |   %c\n", jeu[2][0], jeu[2][1], jeu[2][2]);


}

void initjeu() {

    for(int i=0;i<3;i++)
    {
        for(int j=0;j<3;j++)
        {
            jeu[i][j] =' ';
        }
    }

}

void jouer() {
    printf("Nouveau tour\n");
    int ligne=0;
    int colonne=0;
    printf("Veuillez entrez le numéro de ligne");
    scanf("%d",&ligne);
    printf("veuillez entrer une numéro de colonne");
    scanf("%d",&colonne);
    if(verificationcoup(ligne,colonne))
    {
        printf("Coup valide!\n");
        jeu[ligne][colonne]=determinesymbole();
    }
    else {
        printf("Coup invalide!\n");
        jouer();
    }

    cptcoup++;


}

bool verificationcoup(int l, int c) {
    return l>=0&&l<3&&c>=0&&c<3&&jeu[l][c]==' ';

}

char determinesymbole() {
    if(cptcoup%2==0)
        return 'X';
    else
        return 'O';
}

bool verifgagneligne() {
bool test;
    for(int i=0;i<3;i++) {
        test = true;
        for (int j = 0; j < 2; j++) {
            if ((jeu[i][j] != jeu[i][j + 1])||jeu[i][j]==' ') {
                test = false;
            }

            if(test&&j==1)
            {
                return true;
            }


        }
    }
    return false;
}

bool verifgagnediagonale() {


    if((jeu[0][0]==jeu[1][1]&&jeu[1][1]==jeu[2][2]&&jeu[0][0]!=' ')||(jeu[0][2]==jeu[1][1]&&jeu[1][1]==jeu[2][0]&&jeu[0][2]!=' '))
    {

        return true;
    }

    return false;
}

bool verifgagnecolonne() {
    bool test;
    for (int i = 0; i < 3; i++) {
        test = true;
        for (int j = 0; j < 2; j++) {
            if ((jeu[j][i] != jeu[j+1][i]) || jeu[j][i] == ' ') {
                test = false;
            }

            if (test && j == 1) {
                return true;
            }


        }
    }
    return false;

}


int main() {
    initjeu();
    while(true) {

        affichejeu();
        if(verifgagneligne()||verifgagnecolonne()) {
            gagne = true;
            break;
        }
        if(cptcoup==10) {
            break;
        }
        jouer();

    }
    if(gagne) {
        cptcoup--;
        printf("%c a gagné", determinesymbole());
    }
    else{
        printf("Egalité");
    }
    return 0;
}