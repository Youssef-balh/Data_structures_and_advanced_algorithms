#include<stdio.h>
#include<stdlib.h>


// remplissage matrice

void m_remplissage(int** tab,int ligne,int colonne) {
    for (int i = 0; i < ligne; i++)
    {
        for (int j = 0; j < colonne; j++)
        {
            *(*(tab+i)+j) = rand()%80;
        }
    }
}

// affichage de la matrice

void m_affichage(int** tab,int ligne,int colonne) {
    for (int i = 0; i < ligne; i++)
    {
        for (int j = 0; j < colonne; j++)
        {
            printf("%d\t",*(*(tab+i)+j));
        }
        printf("\n");
    }
}

// additionner 
int **m_additionner(int** tab1,int** tab2,int l,int c) {
    int** tab3;
    tab3 = (int**)malloc(l*sizeof(int*));
    for (int i = 0; i < l; i++)
    {
        tab3[i] = malloc(c*sizeof(int));        
    }
    for (int i = 0; i < l; i++)
    {
        for(int j=0; j<c; j++) {
            tab3[i][j] = tab1[i][j] + tab2[i][j];
        }
    }
    return tab3;
}

int **m_multiplication(int** tab1,int** tab2,int l,int c, int p) {
    int **tab_multi;
    tab_multi = (int**)malloc(l*sizeof(int*));
    for (int i = 0; i < l; i++)
    {
        tab_multi[i] = malloc(p*sizeof(int));        
    }
    for (int i = 0; i < l; i++)
    {
        for (int j = 0; j < p; j++)
        {
            tab_multi[i][j] = 0;
            for (int k = 0; k < c; k++)
            {
                tab_multi[i][j] += tab_multi[i][k] * tab_multi[k][j];
            }
            
        }
        
    }
    return tab_multi;
}

int main() {
    int ligne,ligne2,colonne,colonne2;
    int i,j;
    int** tab1;
    int** tab2;
    int** tab3;
    int** tab4;
    //tab1 
    printf("Veuillez saisir la taille des lignes:\t");
	scanf("%d",&ligne);
	printf("Veuillez saisir la taille des colonnes:\t");
	scanf("%d",&colonne);
    //allouer l espace
    tab1 = (int**)malloc(ligne*sizeof(int*));
    for (int i = 0; i < ligne; i++)
    {
        tab1[i] = malloc(colonne*sizeof(int));        
    }
    //remplissage
    m_remplissage(tab1,ligne,colonne);
    //affichage
    m_affichage(tab1,ligne,colonne);

    //tab2
    printf("Veuillez saisir la taille des lignes:\t");
	scanf("%d",&ligne2);
	printf("Veuillez saisir la taille des colonnes:\t");
	scanf("%d",&colonne2);
    //allouer l espace
    tab2 = (int**)malloc(ligne*sizeof(int*));
    for (int i = 0; i < ligne; i++)
    {
        tab2[i] = malloc(colonne*sizeof(int));        
    }
    //remplissage
    m_remplissage(tab2,ligne,colonne);
    //affichage
    m_affichage(tab2,ligne,colonne);

    
    //ADDDITION OF THE TWO
    tab3 = m_additionner(tab1,tab2,ligne,colonne);
    printf("\nl addition est : \n");
    m_affichage(tab3,ligne,colonne);

    // MULTIPLICATION
    tab4 = m_multiplication(tab1,tab2,ligne,colonne,ligne2);
    m_affichage(tab4,ligne,colonne2);

}
