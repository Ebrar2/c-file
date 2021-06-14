#include <stdio.h>
#include <stdlib.h>
#include<string.h>
#define dosyaA "akademik.txt"
int main()
{
    FILE *dosya,*dosya2;
    int a=0,i=0,j=0,say=0;
    char gec[12][50],buf[50];
    dosya=fopen(dosyaA,"r");
    if(dosya==NULL)
    {
        printf("%s ADLI DOSYA ACILAMADI!!!\n",dosyaA);
        exit(1);
    }
    dosya2=fopen("eposta.txt","w");
    if(dosya2==NULL)
    {
        printf("'eposta.txt' ADLI DOSYA ACILAMADI!!!\n");
        exit(1);
    }
    while(fgets(buf,50,dosya)!=NULL)
    {
        strcpy(gec[a],buf);
        a++;
    }
    for(i=0;i<12;i++)
    {
        for(j=i+1;j<12;j++)
       {
           if(strcmp(gec[i],gec[j])==0)
           {
               strcpy(gec[j],"TEKRAR");
           }

       }
    }
    char x[6]="TEKRAR";
    for(i=0;i<12;i++)
    {
        say=0;
        printf("\ngec[i]:%s",gec[i]);
        for(j=0;j<6;j++)
        {
            if(gec[i][j]==x[j])
                say++;
        }
        if(say==0)
        {
             printf("\ngec[i]:%s",gec[i]);
             fprintf(dosya2,"%s",gec[i]);
        }
    }
    printf("\n\nISLEM BITTI!!!");
    fclose(dosya);
    fclose(dosya2);
    return 0;
}
