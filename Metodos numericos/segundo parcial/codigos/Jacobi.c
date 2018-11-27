#include <stdio.h>

#define cls system("cls")

void capt(int);
void ini(float*, int);
void jacobi(int o, float m[][o+1], float*, float*, int);
void asignacion(float*, float*, int);

int main(){
 int o;
 printf("Cuantas ecuaciones seran?");scanf("%d",&o);
 capt(o);
 return 0;
}

void capt(int o){
 float m[o][o+1];
 float rf[o], ra[o];
 int in, i, j,k;

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

 printf("Cuantas interaciones quiere que pase? ");scanf("%d",&in);

 ini(rf,o);
 ini(ra,o);

 for(i=0;i<o;i++)
 for(j=0;j<=o;j++)
 {
  printf("%.1f\t",m[i][j]);
  if(j==o)printf("\n");
 }


 for(i=1;i<=in;i++){
    for(j=0;j<o;j++)jacobi(o,m, ra,rf , j);
  asignacion(ra,rf,o);
 }
 for(k=0;k<o;k++)printf("x%d = %.4f\n",k+1,rf[k]);
}

void ini(float r[0], int o){
 int i;
 for(i=0;i<=o;i++)r[i]=0;
}

void jacobi(int o, float m[][o+1], float ra[],float rf[], int j){
 int i;
 float l;
 ra[j]=m[j][o];
 for(i=0;i<o;i++){
        if(i==j)continue;
        ra[j]=ra[j]+(-(m[j][i])*ra[i]);
    }
 ra[j]=ra[j]/m[j][j];
}

void asignacion(float ra[0], float rf[0], int o){
 int i;
 for(i=0;i<o;i++)rf[i]=ra[i];
}
