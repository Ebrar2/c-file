#include <stdio.h>
#include <stdlib.h>
#include<string.h>
#include<ctype.h>
struct hayvan
{
    int satir;
    int sutun;
    int kalem;
    int yon;
};
void ayristir(int *komut1,int *komut2,char *komut)
{
    char *p;
    p=strtok(komut,",");
    if(p!=NULL)
   {
     *komut1=atoi(p);
     p=strtok(NULL,",");
     *komut2=atoi(p);
   }
   else
   {
      * komut1=atoi(komut);
      * komut2=0;
   }
   printf("\nkomut1:%d  komut2:%d",*komut1,*komut2);
}
void gez(struct hayvan *t,char oda[][50],int komut1,int komut2)
{
    int i,a,b;
    a=t->satir;
    b=t->sutun;
    if(komut2==0)
    {
        if(komut1==1 || komut1==2)
              t->kalem=komut1;
        else
              t->yon=komut1;
    }
    else
    {
        if(t->yon==3)
        {
            for(i=0;i<komut2 && i+t->sutun<50;i++)
            {
               if(t->kalem==1)
                  oda[t->satir][t->sutun+i]='-';
            }
            a=t->satir;
            b=t->sutun+i;
        }
        else if(t->yon==4)
        {
            for(i=0;i<komut2 && t->sutun-i>-1;i++)
            {
                 if(t->kalem==1)
                    oda[t->satir][t->sutun-i]='-';
            }
            a=t->satir;
            b=t->sutun-i;
        }
        else if(t->yon==5)
        {
            for(i=0;i<komut2 && t->satir-i>-1;i++)
            {
                if(t->kalem==1)
                  oda[t->satir-i][t->sutun]='|';
            }
            a=t->satir-i;
            b=t->sutun;
        }
        else if(t->yon==6)
        {
            for(i=0;i<komut2 && t->satir+i<20;i++)
            {
                if(t->kalem==1)
                  oda[t->satir+i][t->sutun]='|';
            }
            a=t->satir+i;
            b=t->sutun;
        }
    }
    t->satir=a;
    t->sutun=b;

}
void yaz(char oda[][50])
{
    int i,j;
    FILE *dosya;
    dosya=fopen("cizim.dat","w");
    if(dosya==NULL)
    {
        printf("\n\ncizim.dat ADLI DOSYA ACILAMADI!!!");
        exit(1);
    }
    char buf[50];
    printf("\n\n\n\nKAPLUMBAGANIN IZLEDIGI YOL\n\n\n");
    for(i=0;i<20;i++)
    {
        for(j=0;j<50;j++)
          {
            printf("%c",oda[i][j]);
            buf[j]=oda[i][j];
          }
        printf("\n");
        fprintf(dosya,"%s\n",buf);

    }
    fclose(dosya);
}
int main()
{
    int komut1,komut2;
    char oda[20][50]={' '};
    char komut[20];
    FILE *kaynak;
    struct hayvan tosbaga={0,0,1,0};
    kaynak=fopen("kaynak.dat","r");
    if(kaynak==NULL)
    {
        printf("\nkaynak.dat ADLI DOSYA ACILAMADI");
        exit(1);
    }
    while(fgets(komut,20,kaynak)!=NULL)
    {
        ayristir(&komut1,&komut2,komut);
        gez(&tosbaga,oda,komut1,komut2);
   printf("\nt->satir:%d t->sutun:%d",tosbaga.satir,tosbaga.sutun);
   printf("\nt->kalem:%d t->yon:%d",tosbaga.kalem,tosbaga.yon);
    }
    oda[tosbaga.satir][tosbaga.sutun]='*';
    yaz(oda);
    fclose(kaynak);
    return 0;

}
