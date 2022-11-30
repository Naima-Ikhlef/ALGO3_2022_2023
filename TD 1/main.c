#include <stdio.h>
#include <stdlib.h>

void calcul (int *nb1, int *nb2, int *chr)
{
    float resu = 0;
    resu = *nb1 [0] *nb2;
    printf("nb1 %f nb2 = %e \n", *chr, resu,);
}

int main (){
    int nb1, nb2;
    char chr[0];
    printf("Entrer une valeur pour nb1 et nb2 \n");
        scanf("nb1 = %d \n nb2 = %d \n", &nb1, &nb2);
    printf("Entrer un opérateur : ");
        scanf(" %f \n", &chr);
        while (chr !== "+" || "-" || "*" || "/")
        {
             printf("Ceci n'est pas un opérateur valable \n Entrer un opérateur à nouveau");
                scanf("%d", &chr);
        }
    return 0;
}
