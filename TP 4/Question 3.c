void afficherClientFichier(FILE *f, Client c)
{
    f=fopen("test.txt","a+");
    fseek(f, 0, SEEK_SET);
    int id =0;
    char nom[12];
    do
    {
        fscanf(f,"%d %s", &id, &nom);
        printf("id: %d  nom : %s \n", id, nom);
    } while (!feof(f));

}
