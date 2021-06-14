#include <stdio.h>
#include <stdlib.h>
#include<string.h>
#include<ctype.h>
#define dosyaA "istek.txt"
#define dosyaA2 "depo.txt"
struct siparis
{
    char ad[20];
    int miktar;
};
void ayir(char *buf,struct siparis *s)
{
    char *p;
    p=strtok(buf," ");
    strcpy(s->ad,p);
    p=strtok(NULL," ");
    s->miktar=atoi(p);

}
int main()
{
    FILE *dosya,*dosya2,*yeni;
    char buf[100];
    int a=0,b=0,i=0,j,fark;
    dosya=fopen(dosyaA,"r");
    if(dosya==NULL)
    {
        printf("%s ADLI DOSYA ACILAMADI",dosyaA);
        exit(1);
    }
    dosya2=fopen(dosyaA2,"r");
    if(dosya2==NULL)
    {
        printf("%s ADLI DOSYA ACILAMADI",dosyaA2);
        exit(1);
    }
    while(fgets(buf,100,dosya)!=NULL)
        a++;
    fseek(dosya,0,SEEK_SET);
    struct siparis s[a];
    while(fgets(buf,100,dosya)!=NULL)
    {
        ayir(buf,s+i);
        i++;
    }
     while(fgets(buf,100,dosya2)!=NULL)
        b++;
    fseek(dosya2,0,SEEK_SET);
    struct siparis depo[b];
    i=0;
    while(fgets(buf,100,dosya2)!=NULL)
    {
        ayir(buf,depo+i);
       // printf("\ni:%d DEPO:%s   %d",i,depo[i].ad,depo[i].miktar);
        i++;
    }
    for(i=0;i<a;i++)
    {
        for(j=i+1;j<a;j++)
        {
            if(strcmp(s[i].ad,s[j].ad)==0)
            {
                strcpy(s[j].ad,"TEKRAR");
                s[i].miktar=s[i].miktar+s[j].miktar;
                s[j].miktar=0;
            }
        }
    }
    yeni=fopen("nekaldi.txt","w");
    if(yeni==NULL)
    {
        printf("\n\nnekaldi.txt ADLI DOSYA ACILAMADI");
        exit(1);
    }
    for(i=0;i<b;i++)
    {
            for(j=0;j<a;j++)
            {
                if(strcmp(depo[i].ad,s[j].ad)==0)
                    {
                       // printf("\nDEPO:%s   %d",depo[i].ad,depo[i].miktar);
                        //printf("\nISTEK:%s   %d",s[j].ad,s[j].miktar);
                        fark=depo[i].miktar-s[j].miktar;
                        if(fark<0)
                           fprintf(yeni,"%s karsilanamaz\n",depo[i].ad);
                        else
                            fprintf(yeni,"%s %d\n",depo[i].ad,fark);
                        break;
                    }
            }
    }
    printf("\nISLEM BITTI");
    fclose(yeni);
    fclose(dosya2);
    fclose(dosya);
    return 0;
}
