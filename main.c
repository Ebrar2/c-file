#include <stdio.h>
#include <stdlib.h>
#include<ctype.h>
int main()
{
    char ad[20],buf[100];
    FILE *dosya,*dosya2;
    int i,j,k,say=0;
    printf("Kisa mesaji iceren dosyanin adini giriniz:");
    gets(ad);
    dosya=fopen(ad,"r");
    if(dosya==NULL)
    {
        printf("\n%s ADLI DOSYA ACILAMADI!!!",ad);
        exit(1);
    }
    char d[8][5]={"ABC1","DEF1","GHI1","JKL1","MNO1","PQRS","TUV1","WXYZ"};
    while(fgets(buf,100,dosya)!=NULL)
    {
        for(i=0;buf[i]!='\0';i++)
        {
            if(buf[i]==' ' || isdigit(buf[i])==1)
               {
                  say++;
               }
            else
            {
                buf[i]=toupper(buf[i]);
                for(j=0;j<8;j++)
                {
                    for(k=0;k<4;k++)
                    {
                           if(buf[i]==d[j][k])
                              say=say+k+1;
                    }
            }

        }
        printf("\nbuf[i]:%c  say:%d",buf[i],say);
    }
    }
    dosya2=fopen("frekans.txt","w");
    if(dosya2==NULL)
    {
        printf("\n\nfrekans.txt ADLI DOSYA ACIAMADI");
        exit(1);
    }
    fprintf(dosya2,"Toplam %d kez tusa basýlacaktýr",say);
    printf("\nTus basma sayisini gosteren frekans.txt dosyasi olusturuldu");
    return 0;
}
