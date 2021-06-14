#include <stdio.h>
#include <stdlib.h>
#include<string.h>
#define dosyaA "giris.txt"
int main()
{
    FILE *dosya,*dosya2;
    char buf[50],kartno[50][50];
    int a=0,i=0,j=0;
    dosya=fopen(dosyaA,"r");
    if(dosya==NULL)
    {
        printf("DOSYA ACILAMADI!!!");
        exit(1);
    }
    dosya2=fopen("casus.txt","w");
    if(dosya2==NULL)
    {
        printf("DOSYA ACILAMADI!!!");
        exit(1);
    }
    while(fgets(buf,50,dosya)!=NULL)
    {
        strcpy(kartno[a],buf);
        printf("i:%d kartno:%s\n",a,kartno[a]);
        a++;
    }
    for(i=0;i<a;i++)
    {
        printf("\nk[i]:%s",kartno[i]);
        for(j=i+1;j<a;j++)
        {
            if(strcmp(kartno[i],kartno[j])==0)
              {
                  printf("\nAYNI:%s",kartno[j]);
                  fprintf(dosya2,"%s\n",kartno[j]);
              }
            }
    }
    printf("\nISLEM BITTI!!!");
    fclose(dosya2);
    fclose(dosya);
    return 0;
}
