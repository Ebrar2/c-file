#include <stdio.h>
#include <stdlib.h>
#include<string.h>
#include<ctype.h>
struct kalori
{
    char yiyecek[20];
    float kalori;
};
struct siparis
{
    char yiyecek[20];
    float adet;
};
int main()
{
    FILE *dosya,*dosya2;
    float toplamKalr=0.0;
    char buf[100],*p;
    int a=0,b=0,i,j=0;
    dosya=fopen("kalori.txt","r");
    dosya2=fopen("siparis.txt","r");
    if(dosya==NULL)
    {
        printf("\nkalori.txt ADLI DOSYA ACILAMADI!!!");
        exit(1);
    }
    if(dosya2==NULL)
    {
        printf("\nsiparis.txt ADLI DOSYA ACILAMADI!!!");
        exit(1);
    }
    while(fgets(buf,100,dosya)!=NULL)
        a++;
    fseek(dosya,0,SEEK_SET);
    struct kalori k[a];
    while(fgets(buf,100,dosya2)!=NULL)
        b++;
    fseek(dosya2,0,SEEK_SET);
    struct siparis s[b];
    while(fgets(buf,100,dosya)!=NULL)
    {
        p=strtok(buf," ");
        strcpy(k[j].yiyecek,p);
        p=strtok(NULL," ");
        k[j].kalori=atof(p);
       // printf("\nk[j].yiyecek:%s    k[j].kalori:%.2f",k[j].yiyecek,k[j].kalori);
        j++;
    }
    j=0;
    printf("\n");
    while(fgets(buf,100,dosya2)!=NULL)
    {
        p=strtok(buf," ");
        strcpy(s[j].yiyecek,p);
        p=strtok(NULL," ");
        s[j].adet=atof(p);
       // printf("\ns[j].yiyecek:%s s[j]:%.2f",s[j].yiyecek,s[j].adet);
        for(i=0;i<a;i++)
        {
            if(strcmp(s[j].yiyecek,k[i].yiyecek)==0)
            {
                toplamKalr=k[i].kalori*s[j].adet+toplamKalr;
                break;
            }
        }
        j++;
    }
    printf("\n\n\nTOPLAM KALORI:%.2f",toplamKalr);
    fclose(dosya2);
    fclose(dosya);
    return 0;
}
