#include<stdio.h>
#include<stdlib.h>
#include<string.h>

char *multichar(char *s,int n) {
    int l = strlen(s);
    char *new_string = (char*)malloc(n*l*sizeof(char));
    int i,j,k=0;
    for (i = l-1; i>=0;i--)
    { 
        for (j = 0; j < n; j++,k++)
        {
            *(new_string + k) = *(s+i);
        }
    }
    *(new_string + n*l) = '\0';
    printf("success"); 
    return new_string;
}

int main() {
    char *s = (char*)malloc(sizeof(char));
    int n;

    printf("Entrer une chaine de caractere : \n");
    gets(s);
    printf("Nombre de Repetition: ");
    scanf("%d",&n);
    printf("\nle nouveau mot est:  \n%s",multichar(s,n));
    
    free(s);
    return 0;
}