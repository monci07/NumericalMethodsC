#include <stdio.h>
#include <string.h>
#include <math.h>

#define f1(x,y) -1*(x*(pow(y,2)))
#define f2(x,y) x+(pow(y,2))
#define f3(x,y) 2*x*y

#define EU(y,f,h) y+(f*h)
#define EMM(y,h,f,a) y+((h*0.5)*(f+a))
#define ERK(y,k1,k2,k3,k4) y+((0.166666666666666667)*(k1+(2*k2)+(2*k3)+k4))

void euler();
void EP(int);
float evaluaE(int, float, float, float*);

void Em();
void EmP(int);
double evaluaM(int, float, float, float*);

void RK();
void RKP(int);
void kas(int, float, float, float, double*, double*, double*, double*);
double evaluaK(float*, double, double, double, double);

int main(){
    
    char o;
    printf("Que método desea utilizar?\n\n");
    printf("[1]Euler.\n[2]Euler mejorado.\n[3]Runge Kuta\n");
    scanf("%c",&o);
    switch(o){
        case '1':euler();
                 break;
        case '2':Em();
                 break;
        case '3':RK();
                 break;
    }
    system("pause");
    
    return 0;
}

/****************************************************************************************************************************************
 ****************************************************************************************************************************************
 ****************************************************************************************************************************************
 ****************************************************************************************************************************************
 ********************************************************método de Euler*****************************************************************
 ****************************************************************************************************************************************
 ****************************************************************************************************************************************
 ****************************************************************************************************************************************
 ****************************************************************************************************************************************/

void euler(){
    
    char o;
    printf("Que función desea utilizar?\n\n");
    printf("[1]-xy^2.\n[2]x+(y^2).\n[3]2xy\n");
    setbuf(stdin,0);scanf("%c",&o);
    switch(o){
        case '1':EP(1);
                 break;
        case '2':EP(2);
                 break;
        case '3':EP(3);
                 break;
    }
}

void EP(int func){
    
    float y, x0, x1, h;
    float i;
    printf("Introduzca 'y0': ");setbuf(stdin,0);scanf("%f",&y);
    printf("Introduzca 'x0': ");setbuf(stdin,0);scanf("%f",&x0);
    printf("Introduzca 'x1': ");setbuf(stdin,0);scanf("%f",&x1);
    printf("Introduzca 'h': ");setbuf(stdin,0);scanf("%f",&h);
    switch(func){
        case 1:for(i=x0;i<x1+0.1;i+=h)
               printf("y(%.1f)=%.10f\n",i,evaluaE(func,i,h,&y));
               break;
        case 2:for(i=x0;i<x1+0.1;i+=h)
               printf("y(%.1f)=%.10f\n",i,evaluaE(func,i,h,&y));
               break;
        case 3:for(i=x0;i<x1+0.1;i+=h)
               printf("y(%.1f)=%.10f\n",i,evaluaE(func,i,h,&y));
               break;
    }
}

float evaluaE(int o, float x, float h, float* y){
    switch(o){
        case 1:*(y)=EU(*y,f1(x,*y),h);
               break;
        case 2:*(y)=EU(*y,f2(x,*y),h);
               break;
        case 3:*(y)=EU(*y,f3(x,*y),h);
               break;
    }
    return *(y);
}
/****************************************************************************************************************************************
 ****************************************************************************************************************************************
 ****************************************************************************************************************************************
 ****************************************************************************************************************************************
 ****************************************************método de Euler Mejorado************************************************************
 ****************************************************************************************************************************************
 ****************************************************************************************************************************************
 ****************************************************************************************************************************************
 ****************************************************************************************************************************************/
void Em(){
    
    char o;
    printf("Que función desea utilizar?\n\n");
    printf("[1]-xy^2.\n[2]x+(y^2).\n[3]2xy\n");
    setbuf(stdin,0);scanf("%c",&o);
    switch(o){
        case '1':EmP(1);
                 break;
        case '2':EmP(2);
                 break;
        case '3':EmP(3);
                 break;
    }
}

void EmP(int func){
    
    float y, x0, x1, h;
    float i;
    printf("Introduzca 'y0': ");setbuf(stdin,0);scanf("%f",&y);
    printf("Introduzca 'x0': ");setbuf(stdin,0);scanf("%f",&x0);
    printf("Introduzca 'x1': ");setbuf(stdin,0);scanf("%f",&x1);
    printf("Introduzca 'h': ");setbuf(stdin,0);scanf("%f",&h);
    switch(func){
        case 1:for(i=x0;i<x1+0.1;i+=h)
               printf("y(%.1f)=%.10f\n",i,evaluaM(func,i,h,&y));
               break;
        case 2:for(i=x0;i<x1+0.1;i+=h)
               printf("y(%.1f)=%.10f\n",i,evaluaM(func,i,h,&y));
               break;
        case 3:for(i=x0;i<x1+0.1;i+=h)
               printf("y(%.1f)=%.10f\n",i,evaluaM(func,i,h,&y));
               break;
    }
}

double evaluaM(int o, float x, float h, float* y){
        switch(o){
        case 1:*(y)=EMM(*y,h,f1(x,*y),f1(x+h,EU(*y,f1(x,*y),h)));
               break;
        case 2:*(y)=EMM(*y,h,f2(x,*y),f2(x+h,EU(*y,f2(x,*y),h)));
               break;
        case 3:*(y)=EMM(*y,h,f3(x,*y),f3(x+h,EU(*y,f3(x,*y),h)));
               break;
    }
    return *(y);
}
/****************************************************************************************************************************************
 ****************************************************************************************************************************************
 ****************************************************************************************************************************************
 ****************************************************************************************************************************************
 ******************************************************método de runge katta*************************************************************
 ****************************************************************************************************************************************
 ****************************************************************************************************************************************
 ****************************************************************************************************************************************
 ****************************************************************************************************************************************/
void RK(){
    
    char o;
    printf("Que función desea utilizar?\n\n");
    printf("[1]-xy^2.\n[2]x+(y^2).\n[3]2xy\n");
    setbuf(stdin,0);scanf("%c",&o);
    switch(o){
        case '1':RKP(1);
                 break;
        case '2':RKP(2);
                 break;
        case '3':RKP(3);
                 break;
    }
}

void RKP(int func){
    
    float y, x0, x1, h;
    double k1, k2, k3, k4;
    float i;
    printf("Introduzca 'y0': ");setbuf(stdin,0);scanf("%f",&y);
    printf("Introduzca 'x0': ");setbuf(stdin,0);scanf("%f",&x0);
    printf("Introduzca 'x1': ");setbuf(stdin,0);scanf("%f",&x1);
    printf("Introduzca 'h': ");setbuf(stdin,0);scanf("%f",&h);
    switch(func){
        case 1:for(i=x0;i<x1+0.1;i+=h){
               kas(func, i, h,y,&k1,&k2,&k3,&k4);
               printf("k1=%.10f\n",k1);
               printf("k2=%.10f\n",k2);
               printf("k3=%.10f\n",k3);
               printf("k4=%.10f\n",k4);
               printf("y(%.1f)=%.10f\n\n",i,evaluaK(&y,k1,k2,k3,k4));
        }break;
        
        case 2:for(i=x0;i<x1+0.1;i+=h){
               kas(func, i, h,y,&k1,&k2,&k3,&k4);
               printf("k1=%.10f\n",k1);
               printf("k2=%.10f\n",k2);
               printf("k3=%.10f\n",k3);
               printf("k4=%.10f\n",k4);
               printf("y(%.1f)=%.10f\n\n",i,evaluaK(&y,k1,k2,k3,k4));
        }break;
        
        case 3:for(i=x0;i<x1+0.1;i=i+h){
               kas(func, i, h,y,&k1,&k2,&k3,&k4);
               printf("k1=%.10f\n",k1);
               printf("k2=%.10f\n",k2);
               printf("k3=%.10f\n",k3);
               printf("k4=%.10f\n",k4);
               printf("y(%.1f)=%.10f\n\n",i,evaluaK(&y,k1,k2,k3,k4));
        }break;
    }
}

void kas(int func, float x, float h, float y, double* k1, double* k2, double* k3, double* k4){
    double vf, vx, vy;
    switch(func){
        case 1:vf=f1(x,y);
               *k1=EU(0,vf,h);
               vx=x+(h/2);
               vy=y+((*k1)*0.5);
               vf=f1(vx,vy);
               *k2=EU(0,vf,h);
               vy=y+((*k2)*0.5);
               vf=f1(vx,vy);
               *k3=EU(0,vf,h);
               vx=x+h;
               vy=*k3+y;
               vf=f1(vx,vy);
               *k4=EU(0,vf,h);
               break;
        case 2:vf=f2(x,y);
               *k1=EU(0,vf,h);
               vx=x+(h/2);
               vy=y+((*k1)*0.5);
               vf=f2(vx,vy);
               *k2=EU(0,vf,h);
               vy=y+((*k2)*0.5);
               vf=f2(vx,vy);
               *k3=EU(0,vf,h);
               vx=x+h;
               vy=*k3+y;
               vf=f2(vx,vy);
               *k4=EU(0,vf,h);
               break;
        case 3:vf=f3(x,y);
               *k1=EU(0,vf,h);
               vx=x+(h/2);
               vy=y+((*k1)*0.5);
               vf=f3(vx,vy);
               *k2=EU(0,vf,h);
               vy=y+((*k2)*0.5);
               vf=f3(vx,vy);
               *k3=EU(0,vf,h);
               vx=x+h;
               vy=*k3+y;
               vf=f3(vx,vy);
               *k4=EU(0,vf,h);
               break;
    }

}

double evaluaK(float* y, double k1, double k2, double k3, double k4){
    *y=ERK(*y,k1,k2,k3,k4);
    return *y;
}
