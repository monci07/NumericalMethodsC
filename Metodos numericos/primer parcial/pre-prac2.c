#include <stdio.h>
#include <math.h>

#define func(i) pow(2.718281828459045235360,i)-(3*pow(i,2))

float bisect(float, float, float, float);
void imprimeTabla(float, float, float, float, float, float);

void imprimeTabla(float a, float b, float xs, float fa, float fxs, float ea)
{
    printf("%.4f\t\t%.4f\t\t%.4f\t\t%.4f\t\t%.4f\t\t%.4f\n",a,b,xs,fa,fxs,ea);
}

float bisect(float a, float b, float es, float im)
{int i=0;
 float xs=0,fa, fb, fxs,ea=100,xsa=0;
    printf("a\t\tb\t\txs\t\tfa\t\tfxs\t\tea\t\t\n");
    do{fa= func(a);
       fb= func(b);
       xs=(fb*(a-b));
       xs/=(fa-fb);
       xs=b-xs;
       fxs= func(xs);
       fa*=fxs;
       i++;
       ea=fabs((1-(xs/xsa))*100);
       xsa=xs;
       imprimeTabla(a,b,xs,fa,fxs,ea);
       if(fa<0) b=xs;
       else if(fa>0) a=xs;
       else return xs;
    }while(ea>es||i!=im );
    return xs;
}

int main()
{float i,j=0,k,l;
 float resp;
 char c;
    do{ system("CLS");
        printf("Introduce los parametros que desea evaluar(poner coma entre los parametros: \n");
        setbuf(stdin,0);
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

        //resp=bisect(i,j,k,l);
    return 0;
}
