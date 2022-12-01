int main(int argc, char const *argv[])
{
    FILE *f=NULL;
    f=fopen("test.txt","r+");
    Client c;
    int num=0;
    char _nom[15];
    afficherClientFichier(f,c);
    num = nombreClientsFichier(f);
    printf("il y a : %d", num);
    appartientClientFichier(f, _nom);
    return 0;
}
