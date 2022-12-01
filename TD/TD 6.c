#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Client
{
    int id;
    char nom[15];
    char tel[10];
} Client;

void ajouteClientFichier(Client c, char *nomFichier)
{
    FILE *f = fopen(nomFichier, "a");
    if (f == NULL)
    {printf("Erreur de l'ouverture du fichier %s en mode a (ajout)\n", nomFichier);
        exit(1);
    }
    fprintf(f, "%d %s %s ", c.id, c.nom, c.tel);
    fclose(f);
}

void afficheClientsFichier(char *nomFichier)
{
    FILE *f = fopen(nomFichier, "r");
    if (f == NULL)
    {
        printf("Erreur de l'ouverture du fichier %s en mode r (lecture)\n", nomFichier);
        exit(1);
    }
    Client c;
    while (fscanf(f, "%d %s %s ", &c.id, c.nom, c.tel) != EOF)
    {
        printf("%d %s %s ", c.id, c.nom, c.tel);
    }
    fclose(f);
}

int nombreClientsFichier(char *nomFichier)
{
    FILE *f = fopen(nomFichier, "r");
    if (f == NULL)
    {
        printf("Erreur de l'ouverture du fichier %s en mode r (lecture)\n", nomFichier);
        exit(1);
    }
    int nb = 0;
    Client c;
    while (fscanf(f, "%d %s %s ", &c.id, c.nom, c.tel) != EOF)
    {
        nb++;
    }
    fclose(f);
    return nb;
}

void triClientsFichier(char *nomFichier)
{
    FILE *f = fopen(nomFichier, "r");
    if (f == NULL)
    {
        printf("Erreur de l'ouverture du fichier %s en mode r (lecture)\n", nomFichier);
        exit(1);
    }
    Client *clients = malloc(nombreClientsFichier(nomFichier) * sizeof(Client));
    int i = 0;
    Client c;
    while (fscanf(f, "%d %s %s ", &c.id, c.nom, c.tel) != EOF)
    {
        clients[i] = c;
        i++;
    }
    fclose(f);
    for (int i = 0; i < nombreClientsFichier(nomFichier); i++)
    {
        for (int j = i + 1; j < nombreClientsFichier(nomFichier); j++)
        {
            if (strcmp(clients[i].nom, clients[j].nom) > 0)
            {
                Client tmp = clients[i];
                clients[i] = clients[j];
                clients[j] = tmp;
            }
        }
    }
    f = fopen(nomFichier, "w");
    if (f == NULL)
    {
        printf("Erreur de l'ouverture du fichier %s en mode w (écriture)\n", nomFichier);
        exit(1);
    }
    for (int i = 0; i < nombreClientsFichier(nomFichier); i++)
    {
        fprintf(f, "%d %s %s ", clients[i].id, clients[i].nom, clients[i].tel);
    }
    fclose(f);
}

void appartientClientFichier(char *nomFichier, char *nomClient)
{
    FILE *f = fopen(nomFichier, "r");
    if (f == NULL)
    {
        printf("Erreur de l'ouverture du fichier %s en mode r (lecture)\n", nomFichier);
        exit(1);
    }
    Client c;
    while (fscanf(f, "%d %s %s ", &c.id, c.nom, c.tel) != EOF)
    {
        if (strcmp(c.nom, nomClient) == 0)
        {
            printf("%d %s %s ", c.id, c.nom, c.tel);
            fclose(f);
            return;
        }
    }
    printf("Client non répertorié ");
    fclose(f);
}

int main()
{
    char nomFichier[20];
    printf("Nom du fichier : ");
    scanf("%s", nomFichier);
    Client c;
    printf("Id : ");
    scanf("%d", &c.id);
    printf("Nom : ");
    scanf("%s", c.nom);
    printf("Tel : ");
    scanf("%s", c.tel);
    ajouteClientFichier(c, nomFichier);
    afficheClientsFichier(nomFichier);
    printf(" %d ", nombreClientsFichier(nomFichier));
    triClientsFichier(nomFichier);
    afficheClientsFichier(nomFichier);
    char nomClient[15];
    printf("Nom du client : ");
    scanf("%s", nomClient);
    appartientClientFichier(nomFichier, nomClient);
    return 0;
}
