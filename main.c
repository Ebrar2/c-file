#include <stdio.h>
#include <stdlib.h>
#include<ctype.h>
int main()
{
    char ad[20],buf[100];
    int i,cumleS=0,kelimeS=0,karakterS=0;
    printf("Hangi dosya hakkinda bilgi verilecek:");
    gets(ad);
    FILE *dosya;
    dosya=fopen(ad,"r");
    if(dosya==NULL)
    {
        printf("\nDOSYA ACILAMADI!!!");
        exit(1);
    }
    while((fgets(buf,100,dosya))!=NULL)
    {
        for(i=0;buf[i]!='\0';i++)
        {
            if(buf[i]=='.')
                cumleS++;
            else if(buf[i]==' ')
                kelimeS++;
            karakterS++;
        }
    }
    printf("\n\nCumle sayisi:%d\n",cumleS);
    printf("Kelime sayisi:%d\n",kelimeS+cumleS);
    printf("Karakter sayisi:%d\n",karakterS);
    fclose(dosya);
    return 0;
}
