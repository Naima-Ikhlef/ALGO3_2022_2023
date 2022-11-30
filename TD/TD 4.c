#include <stdio.h>
#include <stdlib.h>
#define N 10
typedef int Tab[N];

//exo 1

void f(Tab t, int n){
    int b=1, j=n, i;
    while(b==1)
    {
        b=0;
        i=0;
        while(i<j)
        {
          if(t[i]>t[i+1]) 
          {
            permute(t,i,i+1);
                    b=1;
          }
            i++;
         }
            j--;
     }
}

int rechDicho(Tab t, int c, int g, int d){
    int res = -1;
    if (g < c)
    {
        if (t[g] == d)
        {
            res = g;
        }
        else
        {
            res = rechDicho(t, c, g+1, d);
        }
    }
    return res;
};

//exo 2

int indiceMin(int tableau[], int tailleTab){
    int i,j=0;
    for (i = 0;i<tailleTab;i++){ //
        if (tableau[j] > tableau[i+1]) {
            j = i+1;
        }
    }
    return j;
}

void permute(int tableau[],int i, int j){
    int temporaire;
    temporaire = tableau[i];
    tableau[i] = tableau[j];
    tableau[j] = temporaire;
}

int affiche_tab(int tableau[], int tailleTab)
{
    int i;
    for(i=0;i<tailleTab;i++)
    {
        printf("%d\n",tableau[i]);
    }
}

int main()
{
    int t[] = {3,17,9,15,2,7,10,9,8,12};
    printf("L'indice de la valeur 15 est %d\n", rechDicho(t1, N, 0, 15));
    printf("%d\n", indiceMin(t,10));
    permute(t,4,0);
    printf("%d\n", indiceMin(t,10));
    affiche_tab(t,13);
    return 0;
}
