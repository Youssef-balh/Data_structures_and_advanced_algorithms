#include<stdio.h>
#include<stdlib.h>


int main() {
    struct auteur
    {
        char *nom;
        char *nationalite;
        int an;
    };
    
    struct livre
    {
        char *titre;
        int nbrPages;
        float prix;
        struct auteur author; /* Nested structure */
    };
    struct livre livre1 = {"The murder",541,10.52,{"youssef balo","morocco",2002}};
    struct livre livre2 = {"Rich dad poor dad",150,50.52,{"youssef balo","America",1889}};

    void livreInfo(struct livre livre) {
        printf("Auteur est:  %s\n",livre.author.nom);
        printf("Nationalité:  %s\n",livre.author.nationalite);
        printf("Année:  %d\n",livre.author.an);
        printf("Titre :  %s\n",livre.titre);
        printf("Nbre de pages :  %d\n",livre.nbrPages);        
        printf("Prix :  %.2f euros \n",livre.prix);
        printf("----------------------------------");
    }
    livreInfo(livre1);
    printf("\n");
    livreInfo(livre2);



    return 0;
}