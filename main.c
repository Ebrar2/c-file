#include <stdio.h>
#include <stdlib.h>
#include<string.h>
int main()
{
    char buf[100],gec[100],ad[20],ad2[20],sesli[10]="aAeEiIoOuU";
    int say=0,i,j,a;
    FILE *dosya,*dosya2;
    printf("Dosyanin adini giriniz:");
    gets(ad);
    strcpy(ad2,ad);
    strcat(ad2,".ssz");
    dosya=fopen(ad,"r");
    dosya2=fopen(ad2,"w");
    if(dosya==NULL)
    {
        printf("\n%s ADLI DOSYA ACILAMADI!!!",ad);
        exit(1);
    }
    if(dosya2==NULL)
    {
        printf("\n%s ADLI DOSYA ACILAMADI!!!",ad2);
        exit(1);
    }
    while(fgets(buf,100,dosya)!=NULL)
    {
        a=0;
        for(j=0;buf[j]!='\0';j++)
        {
             say=0;
             for(i=0;i<10;i++)
             {
                 if(buf[j]==sesli[i])
                    say++;
             }
             if(say==0)
             {
                 gec[a]=buf[j];
                 a++;
             }
        }
        printf("\ngec:%s\n",gec);
        fprintf(dosya2,"%s",gec);
    }
    printf("\n\nISLEM BITTI!!!");
    fclose(dosya2);
    fclose(dosya);
    return 0;
}
