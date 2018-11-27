#include <stdio.h>
#include <math.h>

#define func1(i) (0.5*pow(i,3))-(4*pow(i,2))+(6*i)-2
#define func2(i) (1.5*pow(i,2))-(8*i)+6

double newton(float, float, float);
void imprimeTabla(float, float, float, float, double);

void imprimeTabla(float a, float fa, float faa, float ea, double xs)
{
    printf("%.5f\t\t%.5f\t\t%.5f\t\t%.5f\t\t%.5f\n",a,fa,faa,ea,xs);
}

double newton(float a, float es, float im)
{int i=0;
 double xs=0,fa,faa,ea=100,xsa=0;
    printf("   a\t\t\tf(a)\t\t\tf'(a)\t\t\tea\n");
    do{fa=func1(a);
       faa=func2(a);
       xs=a-(fa/faa);
       ea=((xsa-xs)/xsa)*100;
       ea=fabs(ea);
       xsa=xs;
       imprimeTabla(a,fa,faa,ea,xs);
       i++;
       a=xs;
       if(ea<es) return xs;
    }while(i!=im);

    imprimeTabla(a,fa,faa,ea,xs);
    return xs;
}

int main()
{float i,j,k,l;
 double resp;
 char c;
    do{ system("CLS");
        printf("Introduce el parametro en el que quiere que empieze: \n");
        scanf("%f",&i);
        printf("\nCual es tu margen de error?");
        scanf("%f",&j);
        printf("\nCuantas interaciones deseas que pasen?");
        scanf("%f",&k);
        resp=newton(i,j,k);
        printf("\nLa raiz es: %.5f",resp);
        printf("\nOtro calculo? (s/n)");
        setbuf(stdin,0);
        scanf("%c",&c);
    }while(c=='s');
    return 0;
}
