int nombreClientsFichier(FILE *f)
{
    f=fopen("test.txt","r+");
    fseek(f, 0, SEEK_SET);
    int id =0;
    char nom[12];
    int compte=0;
    while (!feof(f))
    {
        fscanf(f,"%d %s", &id, &nom);
        compte +=1;
    }
    return compte;
}
