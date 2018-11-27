#include <stdio.h>
#include <math.h>

#define func(i) pow(i,2)-(4*i)-8.95

float bisect(float, float, float, float);
void imprimeTabla(float, float, float, float, float, float);

void imprimeTabla(float a, float b, float xs, float fa, float fxs, float ea)
{
    printf("%.2f\t\t%.2f\t\t%.2f\t\t%.2f\t\t%.2f\t\t%.2f\n",a,b,xs,fa,fxs,ea);
}

float bisect(float a, float b, float es, float im)
{int i=0;
 float xs=0,fa,fxs,ea=100,xsa=0;
    printf("a\t\tb\t\txs\t\tfa\t\tfxs\t\tea\t\t\n");
    do{xs=(a+b)/2;
       fa= func(a);
       fxs= func(xs);
       fa*=fxs;
       i++;
       imprimeTabla(a,b,xs,fa,fxs,ea);
       ea=((xsa-xs)/xsa)*100;
       ea=fabs(ea);
       xsa=xs;
       if(fa<0) b=xs;
       else if(fa>0) a=xs;
       else return xs;
       if(ea<es) break;
    }while(i!=im );
    return xs;
}

int main()
{float i,j,k,l;
 float resp;
 char c;
    do{ system("CLS");
        printf("Introduce los parametros que desea evaluar(poner coma entre los parametros: \n");
        scanf("%f,%f",&i, &j);
        printf("\nCual es tu margen de error?");
        scanf("%f",&k);
        printf("\nCuantas interaciones deseas que pasen?");
        scanf("%f",&l);
        resp=bisect(i,j,k,l);
        printf("\nLa raiz es: %.4f",resp);
        printf("\nOtro calculo? (s/n)");
        setbuf(stdin,0);
        scanf("%c",&c);
    }while(c=='s');
    return 0;
}
