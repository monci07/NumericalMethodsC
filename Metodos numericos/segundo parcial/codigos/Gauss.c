#include <stdio.h>
#include <windows.h>

#define MAX 1000
#define cls system("cls")

void gaussjordan(int o, float m[][o+1]);
void captura(int );

int main(){
    int i, j, o;
    cls;
    printf("Cuantas ecuaciones seran?");scanf("%d",&o);

    captura(o);

    return 0;
}

void captura(int o){
    int i,j;
    float m[o][o+1];

    printf("Introduce las ecuaciones sin resultados:\n");
    for(i=0;i<o;i++)
    for(j=0;j<o;j++)
    {
     printf("Captura el d[%d][%d]",i,j);scanf("%f", &m[i][j]);
    }
    printf("Introduce los resultados:\n");
    for(i=0;i<o;i++)
    {
     printf("Captura el r[%d][%d]",i,o);scanf("%f", &m[i][o]);
    }

    for(i=0;i<o;i++)
    for(j=0;j<o+1;j++){
        printf("%.2f\t",m[i][j]);
        if(j==o)printf("\n");
    }
    printf("\n\nMatriz con resultados:\n");
   gaussjordan(o,m);

    for(i=0;i<o;i++)
    for(j=0;j<o+1;j++){
        printf("%.2f",m[i][j]);
        if(j!=o) printf("\t");
        else printf("=x%d\n",i+1);
    }
}

void gaussjordan(int o, float m[][o+1]){
	int i, j, k;
    double xa;
    for(j=0; j<o; j++){
        for(i=0; i<o; i++){
            if(i!=j){
                xa=m[i][j]/m[j][j];
                for(k=0; k<o+1; k++){
                    m[i][k]=m[i][k]-xa*m[j][k];
                }
            }
        }
    }
    for (i=0;i<o;i++) {
     xa=m[i][i];
     for (j=0;j<o+1;j++)if(m[i][j]!=0)m[i][j]=m[i][j]/xa;
    }
}
