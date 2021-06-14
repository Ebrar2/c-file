#include <stdio.h>
#include <stdlib.h>
#include<string.h>
#include<ctype.h>
struct telefon
{
    char ad[20];
    char ad2[20];
    float fiyat;
};
void ayir(struct telefon *t,char *buf)
{
    char *p;
    p=strtok(buf," ");
    strcpy(t->ad,p);
    p=strtok(NULL," ");
    strcpy(t->ad2,p);
    p=strtok(NULL," ");
    t->fiyat=atof(p);
}
void ucuzPahali(struct telefon t[],int n)
{
    FILE *ucuz,*pahali;
    int i;
    float top=0.0,ort;
    ucuz=fopen("ucuz.txt","w");
    if(ucuz==NULL)
    {
        printf("\n\nucuz.txt ADLI DOSYA ACILAMADI");
        exit(1);
    }
    pahali=fopen("pahali.txt","w");
    if(pahali==NULL)
    {
        printf("\n\npahali.txt ADLI DOSYA ACILAMADI");
        exit(1);
    }
    for(i=0;i<n;i++)
        top=top+t[i].fiyat;
    ort=top/n;
    printf("\nort:%.2f",ort);
    for(i=0;i<n;i++)
    {
        if(t[i].fiyat<=ort)
            fprintf(ucuz,"%s %s %.2f\n",t[i].ad,t[i].ad2,t[i].fiyat);
        else
            fprintf(pahali,"%s %s %.2f\n",t[i].ad,t[i].ad2,t[i].fiyat);

    }
    fclose(ucuz);
    fclose(pahali);
}
int main()
{
    FILE *fiyat;
    char buf[100];
    int a=0,i=0;
    fiyat=fopen("fiyat.txt","r");
    if(fiyat==NULL)
    {
        printf("fiyat.txt ADLI DOSYA ACILAMADI");
        exit(1);
    }
    while(fgets(buf,100,fiyat)!=NULL)
        a++;
    struct telefon t[a];
    fseek(fiyat,0,SEEK_SET);
    while(fgets(buf,100,fiyat)!=NULL)
    {
        ayir(t+i,buf);
        i++;
    }
    ucuzPahali(t,a);
    fclose(fiyat);
    printf("\n\nISLEM BITTT");
    return 0;
}
