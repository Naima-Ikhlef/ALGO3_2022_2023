void ajouterClientFichier(FILE *f, Client c)
{
    f=fopen("fich.txt","r+");
    fseek(f, 0, SEEK_SET);
    int id = 0 ;
    char nom[12];
    bool trouver  = false;
    printf("entrez l'id\n");
    scanf("%d", &c.id);

    printf("entrez le nom\n");
    scanf("%s", &c.nom);

    do
    {
        fscanf(f,"%d %s", &id, &nom);
        printf("%s", c.nom);
        printf("%s", nom);
        if(c.nom == nom)
        {
            printf("le client existe déjà ! ");
            trouver = true;
        }
    }while (!feof(f));

    if(trouver == false)
    {
        fseek(f,0, SEEK_END);
        fprintf(f,"\n");
        fprintf(f, "%d ", c.id);
        fprintf(f, "%s ", c.nom);
    }
}
