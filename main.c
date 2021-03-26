#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#include <stdbool.h>
#include <math.h>
int a = 0;

bool helperKaprekar(int n){
	if (n == 1)
       return true;
    int karesi = n * n;
    int BasamakSayisi = 0;
    while (karesi)
    {
        BasamakSayisi++;
        karesi /= 10;
    }
    karesi = n*n;
    int BasamakDegeri,i;
	for (BasamakDegeri=1; BasamakDegeri<BasamakSayisi; BasamakDegeri++)
    {
		int Toplam = 1 ;

		for (i = 1 ; i <= BasamakDegeri ; i ++)
			Toplam *= 10 ;

         if (Toplam == n)
            continue;
         int miktar = karesi/Toplam + karesi % Toplam;
         if (miktar == n)
           return true;
    }
    return false;
}

void KaprekarKontrol(int dizi [][a] , int boyut){
	printf ("\n..Kaprekar Kontrol..\n") ;
	FILE *yaz;
	yaz = fopen("kaprekar.txt","a");
	fprintf(yaz,"\n");

    int n,x,y;
    for(x=0;x<boyut;x++){
    	for(y=0;y<boyut;y++){
    		n = dizi[x][y];
    		if(helperKaprekar(n)==true){
    			printf("Kaprekar Sayilari 'kaprekar.txt' adlý Dosyaya Gonderildi");
    			fprintf(yaz,"%d\n",n);
			}else{
				printf("Kaprekar sayisi bulunamadi..\n");
			}
		}
		printf("\n");
	}
    fclose(yaz);
}

void sirala(int** arr, int row, int col){
	int temp,t,i,j;
	for(t=1; t<(row*col); t++)
    {
        for(i=0; i<row; i++)
        {
            for(j=0; j<col-1; j++)
            {
                if (arr[i][j]>arr[i][j+1])
                {
                    temp=arr[i][j];
                    arr[i][j]=arr[i][j+1];
                    arr[i][j+1]=temp;
                }
            }
        }
        for(i=0; i<row-1; i++)
        {
            if (arr[i][col-1]>arr[i+1][0])
            {
                temp=arr[i][col-1];
                arr[i][col-1]=arr[i+1][0];
                arr[i+1][0]=temp;
            }
        }
    }
    for(i=0; i<row; i++)
    {
        printf("\n");
        for(j=0; j<col; j++)
            printf("%5d\t", arr[i][j]);
    }
	printf("\n");
}

void transpoz(int** arr,int row){
	printf("\n");
	int i,j;
	for(i=0;i<row;i++){
		for(j=0;j<row;j++){
			printf("%5d\t",arr[j][i]);
		}
		printf("\n");
	}
}

void siralaDosyaKaydet(int** arr, int row, int col){
	FILE *oku;
	oku = fopen("bubblesort.txt","a");
	fprintf(oku,"\n");
	fprintf(oku,"SIRALANMIS HALI");
	int temp,t,i,j;
	for(t=1; t<(row*col); t++)
    {
        for(i=0; i<row; i++)
        {
            for(j=0; j<col-1; j++)
            {
                if (arr[i][j]>arr[i][j+1])
                {
                    temp=arr[i][j];
                    arr[i][j]=arr[i][j+1];
                    arr[i][j+1]=temp;
                }
            }
        }
        for(i=0; i<row-1; i++)
        {
            if (arr[i][col-1]>arr[i+1][0])
            {
                temp=arr[i][col-1];
                arr[i][col-1]=arr[i+1][0];
                arr[i+1][0]=temp;
            }
        }
    }
    for(i=0; i<row; i++)
    {
        fprintf(oku,"\n");
        for(j=0; j<col; j++)
            fprintf(oku,"%5d\t", arr[i][j]);
    }
    printf("\n");
    printf("Matrisin Sirali Hali Dosyaya Kaydedildi..");
	printf("\n");
	fprintf(oku,"\n");
	fclose(oku);
}

void transpozDosyaKaydet(int** arr,int row){
	FILE *yaz;
	yaz=fopen("transpoze.txt","a");
	fprintf(yaz,"\n");
	fprintf(yaz,"TRANSPOZ HALI");
	fprintf(yaz,"\n");
	printf("\n");
	int i,j;
	for(i=0;i<row;i++){
		for(j=0;j<row;j++){
			fprintf(yaz,"%5d\t",arr[j][i]);
		}
		fprintf(yaz,"\n");
	}
	printf("Transpoze Edilmis Matris Dosyaya Kaydedildi...");
	printf("\n");
	fclose(yaz);
}

int main(){
	
	srand(time(NULL));
 	int **matris;
 	int satir;
 	int i,s1,s2;

	printf("Kare Matrisin Kaca Kac Olacagini Giriniz :\n");
    scanf("%d",&satir);

 	matris=(int **)malloc(satir*sizeof(int));
 		for(i=0;i<satir;i++)

  	matris[i]=(int *)malloc(satir*sizeof(int));

 	for(s1=0;s1<satir;s1++){
 		for(s2=0;s2<satir;s2++){
  			matris[s1][s2] = rand() % 40000-5;
   		}
 	}

 	printf("Girilen matris :\n");
 		for(s1=0;s1<satir;s1++){
  			for(s2=0;s2<satir;s2++){
  				printf("%5d\t",matris[s1][s2]);
  			}
			printf("\n");
 		}	

	 printf("\n");

	 printf("SIRALAMA ISLEMI");
 	 sirala(matris,satir,satir);
 	 siralaDosyaKaydet(matris,satir,satir);

	 printf("\n");

	 printf("TRANSPOZU ALINMIS HALI");
	 transpoz(matris,satir);
	 transpozDosyaKaydet(matris,satir);

	 a = satir ;
 	 KaprekarKontrol(matris,a);

 	for(i=0;i<satir;i++){
 		free((void *) matris[i]);
   		free((void *) matris);
 	}
  getch();	
  return 0;
}
