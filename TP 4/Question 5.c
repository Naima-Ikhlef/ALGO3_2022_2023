bool appartientClientFichier(FILE *f, char _nom[15])
{
    f=fopen("test.txt","r+");
    fseek(f, 0, SEEK_SET);
    int id =0;
    char nom[15];
    while (!feof(f))
    {
        fscanf(f,"%d %s", &id, &nom);
        if (_nom == nom)
        {
            printf(" client: %s id: %d", nom, id);
            return true;
        }
        else
        return false;
    }
}
