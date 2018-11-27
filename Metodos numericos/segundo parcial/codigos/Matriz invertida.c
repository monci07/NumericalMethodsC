#include <stdio.h>

#define MAX 1000
#define cls system("cls")

void captura(int );
void inve(int o, float m[][o*2]);
float r(int o, int, float m[][o*2], float res[o]);
void compro(int c, float n[][c], float b[c], float a[c]);

int main(){
    int o;
    printf("De cuanto sera la matriz: ");scanf("%d",&o);
    captura(o);
    return 0;
}

void captura(int o){
    float m[o][o*2];
    float resul[o], rc[o], d[o*o];
    int i,j, k=0;

    for(i=0;i<o;i++)
    for(j=0;j<o;j++)
    {
     printf("Captura el d[%d][%d]",i,j);scanf("%f", &m[i][j]);
     if(i==j)m[i][j+o]=1;
     else m[i][j+o]=0;
     d[k]=m[i][j];
     k++;
    }
    printf("Introduce los resultados:\n");
    for(i=0;i<o;i++)
    {
     printf("Captura el r[%d][%d]",i,o);scanf("%f", &resul[i]);
    }
    printf("\nMatriz generada: \n");
    for(i=0;i<o;i++)
    for(j=0;j<o*2;j++)
    {
     printf("%.1f\t",m[i][j]);
     if(j==(o*2)-1)printf("\n");
    }

    inve(o,m);
    printf("\nMatriz Inversa:\n");
    for(i=0;i<o;i++)
    for(j=o;j<o*2;j++)
    {
     printf("%.4f\t",m[i][j]);
     if(j==(o*2)-1)printf("\n");
    }

    for(i=0;i<o;i++){
        rc[i]=r(o,i,m,resul);
        printf("x%d= %.2f\n",i+1,r(o,i,m,resul));
    }
}

void inve(int o, float m[][o*2]){
	int i, j, k;
	float xa;
    for(j=0; j<o; j++){
        for(i=0; i<o; i++){
            if(i!=j){
                xa=m[i][j]/m[j][j];
                for(k=0; k<o*2; k++){
                    m[i][k]=m[i][k]-xa*m[j][k];
                }
            }
        }
    }
    for (i=0;i<o;i++) {
     xa=m[i][i];
     for (j=0;j<o*2;j++)if(m[i][j]!=0)m[i][j]=m[i][j]/xa;
    }
}

float r(int o, int j, float m[][o*2], float res[o]){
 int i;
 float re=0;
 for(i=o;i<o*2;i++){
        re=re+(m[j][i]*res[i-o]);
 }
 return re;
}
