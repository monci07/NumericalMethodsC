#include <stdio.h>
#include <math.h>

//#define M_PI 3.14159265358979323846
#define func1(i) cos(i*(M_PI/180))-(3*i)+5
#define func2(i) (-1*sin(i*(M_PI/180)))-3
#define func3(i) (-1*cos(i*(M_PI/180)))

double newton2(float, float, float);
void imprimeTabla(float, double, double, double, double, double);

void imprimeTabla(float a, double fa, double faa, double faaa, double ea, double xs)
{
    printf("%.4f\t\t%.4f\t\t%.4f\t\t%.4f\t\t%.4f\t\t%.4f\n",a,fa,faa,faaa,xs,ea);
}

double newton2(float a, float es, float im)
{int i=0;
 double xs=0,fa,faa,faaa,ea=100,xsa=0;
    printf("   a\t\t f(a)\t\t f'(a)\t\t f''(a)\t\t xs\t\t ea\n");
    do{fa=func1(a);
       faa=func2(a);
       faaa=func3(a);
       xs=a-((fa*faa)/(pow(faa,2)-(fa*faa)));
       ea=((xs-xsa)/xs)*100;
       xsa=xs;
       imprimeTabla(a,fa,faa,faaa,ea,xs);
       i++;
       a=xs;
       if(ea<es) return xs;
    }while(i!=im);

    imprimeTabla(a,fa,faa,faaa,ea,xs);
    return xs;
}

int main()
{float i,j,k;
 double resp;
 char c;
    do{ system("CLS");
        printf("Introduce el parametro en el que quiere que empieze: \n");
        scanf("%f",&i);
        printf("\nCual es tu margen de error?");
        scanf("%f",&j);
        printf("\nCuantas interaciones deseas que pasen?");
        scanf("%f",&k);
        resp=newton2(i,j,k);
        printf("\nLa raiz es: %.5f",resp);
        printf("\nOtro calculo? (s/n)");
        setbuf(stdin,0);
        scanf("%c",&c);
    }while(c=='s');
    return 0;
}
