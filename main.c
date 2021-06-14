#include <stdio.h>
#include <stdlib.h>
#include<ctype.h>
#define dosyaA "sinif.txt"
int main()
{
    FILE *file;
    int i,say=0,numaralar[10],n1,n2,n3,n4,n5,n0,num;
    float top,top1=0.0,top2=0.0,top3=0.0,top4=0.0,top5=0.0,top6=0.0,notO[10];
    if((file=fopen(dosyaA,"r"))==NULL)
    {
        printf("Dosya acilamadi!!!");
        exit(1);
    }
    while(say!=10)
    {
        fscanf(file,"%d%d%d%d%d%d%d",&num,&n0,&n1,&n2,&n3,&n4,&n5);
        numaralar[say]=num;
        notO[say]=(float)(n0+n1+n2+n3+n4+n5)/6;
        top1=top1+n0;  top2=top2+n1;  top3=top3+n2;
        top4=top4+n3;  top5=top5+n4;  top6=top6+n5;
        say++;
    }
    top1=top1/10,top2=top2/10,top3=top3/10;
    top4=top4/10,top5=top5/10,top6=top6/10;
    fclose(file);
    if((file=fopen("sonuclar.txt","w"))==NULL)
    {
        printf("2.Dosya acilamadi!!!");
        exit(1);
    }
    say=0;
    while(say!=10)
    {
        fprintf(file,"%d  %.2f\n",numaralar[say],notO[say]);
        say++;
    }
    fprintf(file,"1.dersin ort:%.2f\n",top1);
    fprintf(file,"2.dersin ort:%.2f\n",top2);
    fprintf(file,"3.dersin ort:%.2f\n",top3);
    fprintf(file,"4.dersin ort:%.2f\n",top4);
    fprintf(file,"5.dersin ort:%.2f\n",top5);
    fprintf(file,"6.dersin ort:%.2f\n",top6);
    fprintf(file,"Sinif ort:%.2f\n",(top1+top2+top3+top4+top5+top6)/6);
    fclose(file);
    return 0;
}
