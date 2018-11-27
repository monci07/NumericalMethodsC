#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define cls system("cls")

#define f1(i) pow(i,3)+(4*pow(i,2))-10
#define f1d1(i) (3*pow(i,2))+(8*i)
#define f1d2(i) (6*i)+8

#define f2(i) (2*i*cos(2*i))-pow(i,2)-(2*i)-1
#define f2d1(i) (-4*i*sin(2*i))-(2*i)+(2*cos(2*i))-2
#define f2d2(i) (-8*i*cos(2*i))-(8*sin(2*i))-2

void imprimeTabla1(float, float, double, double, double, double);
void imprimeTabla2(float, float, double, double, double, double, double);
void imprimeTabla3(float, double, double, double, double);
void imprimeTabla4(float, double, double, double, double, double);

double bisect1(float, float, float, float);
double falsa1(float, float, float, float);
double newton1(float, float, float);
double newton21(float, float, float);
double bisect2(float, float, float, float);
double falsa2(float, float, float, float);
double newton2(float, float, float);
double newton22(float, float, float);
void capturaf(int);

int main(){
    int o;
    char opc;
    do{ cls;
        printf("Que funcion desea utilizar:\n");
        printf("[1]x^3+4x^2-10\n");
        printf("[2]2x cos(2x)-(x+1)^2\n");
        scanf("%d",&o);
        capturaf(o);
        printf("Quiere hacer otro procedimiento? (s/n)\n");
        setbuf(stdin,0);
        scanf("%c",&opc);
    }while(opc=='s');
    cls;
    return 0;
}

void capturaf(int o){
    char opc;
    float a,b,ea,im;
    float xsb,xsf,xsn,xsnr;
    cls;
    setbuf(stdin,0);
    switch(o){
        case 1:printf("Que metodos desea utilizar:\n");
                 printf("[a]Bisecsion y falsa posicion\n");
                 printf("[b]Newton-Raphson 1er y 2do orden\n");
                 scanf("%c",&opc);
                 switch(opc){
                      case 'a':cls;
                               printf("Valores iniciales: ");scanf("%f,%f",&a,&b);
                               printf("Margen de error: ");scanf("%f",&ea);
                               printf("Iteraciones maximas: ");scanf("%f",&im);
                               printf("Biseccion\n");
                               xsb=bisect1(a,b,ea,im);
                               printf("La raiz es: %.4f\n",xsb);
                               printf("\n\nFalsa posicion:\n");
                               xsf=falsa1(a,b,ea,im);
                               printf("La raiz es: %.4f\n",xsf);
                               break;
                      case 'b':cls;
                               printf("Valor iniciales: ");scanf("%f",&a);
                               printf("Margen de error: ");scanf("%f",&ea);
                               printf("Iteraciones maximas: ");scanf("%f",&im);
                               printf("Newton-Raphson 1er orden\n");
                               xsn=newton1(a,ea,im);
                               printf("La raiz es: %.4f\n",xsn);
                               printf("\n\nNewton-Raphson 2do orden:\n");
                               xsnr=newton21(a,ea,im);
                               printf("La raiz es: %.4f\n",xsnr);
                               break;

                 }
                 break;
        case 2:printf("Que metodos desea utilizar:\n");
                 printf("[a]Bisecsion y falsa posicion\n");
                 printf("[b]Newton-Raphson 1er y 2do orden\n");
                 scanf("%c",&opc);
                 switch(opc){
                      case 'a':cls;
                               printf("Valores iniciales: ");scanf("%f,%f",&a,&b);
                               printf("Margen de error: ");scanf("%f",&ea);
                               printf("Iteraciones maximas: ");scanf("%f",&im);
                               printf("Biseccion\n");
                               xsb=bisect2(a,b,ea,im);
                               printf("La raiz es: %.4f\n",xsb);
                               printf("\n\nFalsa posicion:\n");
                               xsf=falsa1(a,b,ea,im);
                               printf("La raiz es: %.4f\n",xsf);
                               break;
                      case 'b':cls;
                               printf("Valor iniciales: ");scanf("%f",&a);
                               printf("Margen de error: ");scanf("%f",&ea);
                               printf("Iteraciones maximas: ");scanf("%f",&im);
                               printf("Newton-Raphson 1er orden\n");
                               xsn=newton2(a,ea,im);
                               printf("La raiz es: %.4f\n",xsn);
                               printf("\n\nNewton-Raphson 2do orden:\n");
                               xsnr=newton22(a,ea,im);
                               printf("La raiz es: %.4f\n",xsnr);
                               break;
                 }
    }

}

double bisect1(float a, float b, float es, float im){
    int i=0;
    float xs=0,fa,fxs,ea=100,xsa=0;
    printf("a\t\tb\t\txs\t\tfa\t\tfxs\t\tea\n");
    do{xs=(a+b)/2;
       fa= f1(a);
       fxs= f1(xs);
       fa*=fxs;
       i++;
       ea=((xsa-xs)/xsa)*100;
       ea=fabs(ea);
       imprimeTabla1(a,b,xs,fa,fxs,ea);
       xsa=xs;
       if(fa<0) b=xs;
       else if(fa>0) a=xs;
       else return xs;
       if(ea<=es) break;
    }while(i!=im );
    return xs;
}

double falsa1(float a, float b, float es, float im){
   int i=0;
 float xs=0,fa, fb, fxs,ea=100,xsa=0;
    printf("a\t\tb\t\tfa\t\tfb\t\txs\t\tfxs\t\tea\n");
    do{fa= f1(a);
       fb= f1(b);
       xs=(fb*(a-b));
       xs/=(fa-fb);
       xs=b-xs;
       fxs= f1(xs);
       fa*=fxs;
       i++;
       ea=fabs((1-(xs/xsa))*100);
       xsa=xs;
       imprimeTabla2(a,b,fa,fb,xs,fxs,ea);
       if(fa<0) b=xs;
       else if(fa>0) a=xs;
       else return xs;
       if(ea<=es) break;
    }while(i!=im );
    return xs;
}

double newton1(float a, float es, float im){
    int i=0;
    double xs=0,fa,faa,ea=100,xsa=0;
    printf("   a\t\tf(a)\t\tf'(a)\t\txs\t\tea\n");
    do{fa=f1(a);
       faa=f1d1(a);
       xs=a-(fa/faa);
       ea=((xsa-xs)/xsa)*100;
       ea=fabs(ea);
       xsa=xs;
       imprimeTabla3(a,fa,faa,xs,ea);
       i++;
       a=xs;
       if(ea<=es) return xs;
    }while(i!=im);
    return xs;
}

double newton21(float a, float es, float im){
    int i=0;
    double xs=0,fa,faa,faaa,ea=100,xsa=0;
    printf("   a\t\t f(a)\t\t f'(a)\t\t f''(a)\t\t xs\t\t ea\n");
    do{fa=f1(a);
       faa=f1d1(a);
       faaa=f1d2(a);
       xs=a-((fa*faa)/(pow(faa,2)-(fa*faa)));
       ea=fabs(((xsa-xs)/xsa)*100);
       xsa=xs;
       imprimeTabla4(a,fa,faa,faaa,xs,ea);
       i++;
       a=xs;
       if(ea<=es) return xs;
    }while(i!=im);
    return xs;
}

double bisect2(float a, float b, float es, float im){
     int i=0;
    float xs=0,fa,fxs,ea=100,xsa=0;
    printf("a\t\tb\t\txs\t\tfa\t\tfxs\t\tea\n");
    do{xs=(a+b)/2;
       fa= f2(a);
       fxs= f2(xs);
       fa*=fxs;
       i++;
       ea=((xsa-xs)/xsa)*100;
       ea=fabs(ea);
       imprimeTabla1(a,b,xs,fa,fxs,ea);
       xsa=xs;
       if(fa<0) b=xs;
       else if(fa>0) a=xs;
       else return xs;
       if(ea<=es) break;
    }while(i!=im );
    return xs;
}

double falsa2(float a, float b, float es, float im){
 int i=0;
 float xs=0,fa, fb, fxs,ea=100,xsa=0;
    printf("a\t\tb\t\tfa\t\tfb\t\txs\t\tfxs\t\tea\n");
    do{fa= f2(a);
       fb= f2(b);
       xs=(fb*(a-b));
       xs/=(fa-fb);
       xs=b-xs;
       fxs= f1(xs);
       fa*=fxs;
       i++;
       ea=fabs((1-(xs/xsa))*100);
       xsa=xs;
       imprimeTabla2(a,b,fa,fb,xs,fxs,ea);
       if(fa<0) b=xs;
       else if(fa>0) a=xs;
       else return xs;
       if(ea<=es) break;
    }while(i!=im );
    return xs;
}

double newton2(float a, float es, float im){
     int i=0;
    double xs=0,fa,faa,ea=100,xsa=0;
    printf("   a\t\tf(a)\t\tf'(a)\t\txs\t\tea\n");
    do{fa=f2(a);
       faa=f2d1(a);
       xs=a-(fa/faa);
       ea=((xsa-xs)/xsa)*100;
       ea=fabs(ea);
       xsa=xs;
       imprimeTabla3(a,fa,faa,xs,ea);
       i++;
       a=xs;
       if(ea<=es) return xs;
    }while(i!=im);
    return xs;
}

double newton22(float a, float es, float im){
    int i=0;
    double xs=0,fa,faa,faaa,ea=100,xsa=0;
    printf("   a\t\t f(a)\t\t f'(a)\t\t f''(a)\t\t xs\t\t ea\n");
    do{fa=f2(a);
       faa=f2d1(a);
       faaa=f2d2(a);
       xs=a-((fa*faa)/(pow(faa,2)-(fa*faa)));
       ea=fabs(((xsa-xs)/xsa)*100);
       xsa=xs;
       imprimeTabla4(a,fa,faa,faaa,xs,ea);
       i++;
       a=xs;
       if(ea<=es) return xs;
    }while(i!=im);
    return xs;
}

void imprimeTabla1(float a, float b, double xs, double fa, double fxs, double ea){
 printf("%.3f\t\t%.3f\t\t%.3f\t\t%.3f\t\t%.3f\t\t%.3f\n",a,b,xs,fa,fxs,ea);
}

void imprimeTabla2(float a, float b, double fa, double fb, double xs, double fxs, double ea){
 printf("%.3f\t\t%.3f\t\t%.3f\t\t%.3f\t\t%.3f\t\t%.3f\t\t%.3f\n",a,b,fa,fb,xs,fxs,ea);
}

void imprimeTabla3(float a, double fa, double faa, double xs, double ea){
 printf("%.3f\t\t%.3f\t\t%.3f\t\t%.3f\t\t%.3f\n",a,fa,faa,xs,ea);
}

void imprimeTabla4(float a, double fa, double faa, double faaa, double xs, double ea){
  printf("%.3f\t\t%.3f\t\t%.3f\t\t%.3f\t\t%.3f\t\t%.3f\n",a,fa,faa,faaa,xs,ea);
}