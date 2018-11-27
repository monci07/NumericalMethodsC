// Los ejercicios sacados del libro son los 21.4 y el 21.3 de la pagina 572

#include <stdio.h>
#include <math.h>


#define transs(a,b,c,d) ((c+d)/2)*(b-a)
#define U3ss(a,b,c,d,e) ((c+(4*e)+d)/6)*(b-a) 
#define TOss(a,b,c,d,e,f) ((c+(3*e)+(3*f)+d)/8)*(b-a) 

#define f1(i) 0.2+(25*i)-(200*pow(i,2))+(675*pow(i,3))-(900*pow(i,4))+(400*pow(i,5))
#define f2(i) exp(i)
#define f3(i) 1/(1+pow(i,2))
#define f4(i) log10(i)
#define f5(i) 1-i-(4*pow(i,3))+(2*pow(i,5))
#define f6(i) pow((i+(1/i)),2)

#define fh(a,b,n) (b-a)/n

void imprimir(float, float);

void simpleT();
void multipleT();

void simpleU3();
void multipleU3();

void simple3O(); 

double sum(float*, float, int);
double sum2(float*, float, int, int*);

void ts(int);
void tm(int);
double transm(float*, int);


void U3s(int);
void U3m(int);
double U3mm(float*, int);

void TOs(int);

int main(){
    int o;

    
    printf("Que metodo desea utilizar?\n");
    printf("[1]Trapecio simple.\n");
    printf("[2]Trapecio de aplicacion Multiple.\n");
    printf("[3]1/3 simple.\n");
    printf("[4]1/3 de aplicacion Multiple.\n");
    printf("[5]3/8 simple.\n");
    scanf("%d",&o);
    switch(o){
        case 1:simpleT();
               break;
        case 2:multipleT();
               break;
        case 3:simpleU3();
               break;
        case 4:multipleU3();
               break;
        case 5:simple3O();
               break;
    }
    return 0;
}

void imprimir(float xi, float r){
    printf("x(%.3f)=%.6f\n", xi, r);
}

double sum(float* lim, float h, int o){
    float i;
    double sum=0;

     switch(o){
        case 1:for(i=h;i<lim[1];i=i+h){
                                       imprimir(lim[0]+i,f1(lim[0]+i));
                                       sum+=f1(lim[0]+i);
                                      }
               imprimir(lim[0]+i,f1(lim[0]+i));
               break;

        case 2:for(i=h;i<lim[1];i=i+h){
                                       imprimir(lim[0]+i,f2(lim[0]+i));
                                       sum+=f2(lim[0]+i);
                                      }
               imprimir(lim[0]+i,f2(lim[0]+i));
               break;
        
        case 3:for(i=h;i<lim[1];i=i+h){
                                       imprimir(lim[0]+i,f3(lim[0]+i));
                                       sum+=f3(lim[0]+i);
                                      }
               imprimir(lim[0]+i,f3(lim[0]+i));
               break;

        case 4:for(i=h;i<lim[1];i=i+h){
                                       imprimir(lim[0]+i,f4(lim[0]+i));
                                       sum+=f4(lim[0]+i);
                                      }
               imprimir(lim[0]+i,f4(lim[0]+i));
               break;

        case 5:for(i=h;i<lim[1];i=i+h){
                                       imprimir(lim[0]+i,f5(lim[0]+i));
                                       sum+=f5(lim[0]+i);
                                      }
               imprimir(lim[0]+i,f5(lim[0]+i));
               break;

        case 6:for(i=h;i<lim[1];i=i+h){
                                       imprimir(lim[0]+i,f6(lim[0]+i));
                                       sum+=f6(lim[0]+i);
                                      }
               imprimir(lim[0]+i,f6(lim[0]+i));
               break;
     }

     return sum;
}

double sum2(float* lim, float h, int o, int* imp){
    float i;
    int c=1;
    double sum=0;

     switch(o){
        case 1:for(i=h;i<lim[1];i=i+h){
                                       imprimir(lim[0]+i,f1(lim[0]+i));
                                       if(c%2==0)sum+=f1(lim[0]+i);
                                       else (*imp)+=f1(lim[0]+i);
                                       c++;
                                      }
               imprimir(lim[0]+i,f1(lim[0]+i));
               break;

        case 2:for(i=h;i<lim[1];i=i+h){
                                       imprimir(lim[0]+i,f2(lim[0]+i));
                                       if(c%2==0)sum+=f2(lim[0]+i);
                                       else (*imp)+=f2(lim[0]+i);
                                       c++;
                                      }
               imprimir(lim[0]+i,f2(lim[0]+i));
               break;
        
        case 3:for(i=h;i<lim[1];i=i+h){
                                       imprimir(lim[0]+i,f3(lim[0]+i));
                                       if(c%2==0)sum+=f3(lim[0]+i);
                                       else (*imp)+=f3(lim[0]+i);
                                       c++;
                                      }
               imprimir(lim[0]+i,f3(lim[0]+i));
               break;

        case 4:for(i=h;i<lim[1];i=i+h){
                                       imprimir(lim[0]+i,f4(lim[0]+i));
                                       if(c%2==0)sum+=f4(lim[0]+i);
                                       else (*imp)+=f4(lim[0]+i);
                                       c++;
                                      }
               imprimir(lim[0]+i,f4(lim[0]+i));
               break;

        case 5:for(i=h;i<lim[1];i=i+h){
                                       imprimir(lim[0]+i,f5(lim[0]+i));
                                       if(c%2==0)sum+=f5(lim[0]+i);
                                       else (*imp)+=f5(lim[0]+i);
                                       c++;
                                      }
               imprimir(lim[0]+i,f5(lim[0]+i));
               break;

        case 6:for(i=h;i<lim[1];i=i+h){
                                       imprimir(lim[0]+i,f6(lim[0]+i));
                                       if(c%2==0)sum+=f6(lim[0]+i);
                                       else (*imp)+=f6(lim[0]+i);
                                       c++;
                                      }
               imprimir(lim[0]+i,f6(lim[0]+i));
               break;
     }

     return sum;
}

//**********************************************************************************************************************************************************************
//**********************************************************************************************************************************************************************
//**********************************************************************************************************************************************************************
//**********************Metodo del trapecio*****************************************************************************************************************************
//**********************************************************************************************************************************************************************
//**********************************************************************************************************************************************************************
//**********************************************************************************************************************************************************************
//**********************************************************************************************************************************************************************


void simpleT(){
    int o;

    
    printf("Que ecuacion desea hacer?\n");
    printf("[1] 0.2+(25*i)-(200*i^2)+(675*i^3)-(900*i^4)+(400*i^5). \n");
    printf("[2] e^x.\n");
    printf("[3] 1/(1+x^2).\n");
    printf("[4] log10 x.\n");
    printf("[5] 1-x-(4x^3)+(2x^5).\n");
    printf("[6] (x+(1/x))^2.\n");
    scanf("%d",&o);
    switch(o){
        case 1:ts(1);
               break;
        case 2:ts(2);
               break;
        case 3:ts(3);
               break;
        case 4:ts(4);
               break;
        case 5:ts(5);
               break;
        case 6:ts(6);
               break;
    }
}


void ts(int o){
  int i;
  float lim[2];

  
  //alt + 97 =a
  printf("Introdusca los limites: \n");
  for(i=0;i<2;i++){
    printf("%c.- ", 97+i);
    scanf("%f",&lim[i]);
  }

  switch(o){
      case 1:printf("La respuesta es: %.9f\n",transs(lim[0],lim[1],f1(lim[0]),f1(lim[1])));
             break;
      case 2:printf("La respuesta es: %.9f\n",transs(lim[0],lim[1],f2(lim[0]),f2(lim[1])));
             break;
      case 3:printf("La respuesta es: %.9f\n",transs(lim[0],lim[1],f3(lim[0]),f3(lim[1])));
             break;
      case 4:printf("La respuesta es: %.9f\n",transs(lim[0],lim[1],f4(lim[0]),f4(lim[1])));
             break;
      case 5:printf("La respuesta es: %.9f\n",transs(lim[0],lim[1],f5(lim[0]),f5(lim[1])));
             break;
      case 6:printf("La respuesta es: %.9f\n",transs(lim[0],lim[1],f6(lim[0]),f6(lim[1])));
             break;
  }
}

//**********************************************************************************************************************************************************************
//**********************************************************************************************************************************************************************
//**********************************************************************************************************************************************************************
//**********************************************************************************************************************************************************************

void multipleT(){
    int o;

    
    printf("Que ecuacion desea hacer?\n");
    printf("[1] 0.2+(25*i)-(200*i^2)+(675*i^3)-(900*i^4)+(400*i^5). \n");
    printf("[2] e^x.\n");
    printf("[3] 1/(1+x^2).\n");
    printf("[4] log10 x.\n");
    printf("[5] 1-x-(4x^3)+(2x^5).\n");
    printf("[6] (x+(1/x))^2.\n");

    scanf("%d",&o);
    switch(o){
        case 1:tm(1);
               break;
        case 2:tm(2);
               break;
        case 3:tm(3);
               break;
        case 4:tm(4);
               break;
        case 5:tm(5);
               break;
        case 6:tm(6);
               break;
    }
}

void tm(int o){
  int i;
  float lim[2];

  
  //alt + 97 =a
  printf("Introdusca los limites: \n");
  for(i=0;i<2;i++){
    printf("%c.- ", 97+i);
    scanf("%f",&lim[i]);
  }

  switch(o){
      case 1:printf("La respuesta es: %.9f\n",transm(lim, 1));
             break;
      case 2:printf("La respuesta es: %.9f\n",transm(lim, 2));
             break;
      case 3:printf("La respuesta es: %.9f\n",transm(lim, 3));
             break;
      case 4:printf("La respuesta es: %.9f\n",transm(lim, 4));
             break;
      case 5:printf("La respuesta es: %.9f\n",transm(lim, 5));
             break;
      case 6:printf("La respuesta es: %.9f\n",transm(lim, 6));
             break;
  }
}

double transm(float* lim, int o){
    int n;
    double y;
    
    printf("Introdusca entre cuantas partes desea dividirlo: ");scanf("%d",&n);
    switch(o){
        case 1: y=(((f1(lim[0])+(2*sum(lim,fh(lim[0],lim[1],n),1))+f1(lim[1])))/(2*n))*(lim[1]-lim[0]);
                break;
        case 2: y=(((f2(lim[0])+(2*sum(lim,fh(lim[0],lim[1],n),2))+f2(lim[1])))/(2*n))*(lim[1]-lim[0]);
                break;
        case 3: y=(((f3(lim[0])+(2*sum(lim,fh(lim[0],lim[1],n),3))+f3(lim[1])))/(2*n))*(lim[1]-lim[0]);
                break;
        case 4: y=(((f4(lim[0])+(2*sum(lim,fh(lim[0],lim[1],n),4))+f4(lim[1])))/(2*n))*(lim[1]-lim[0]);
                break;
        case 5: y=(((f5(lim[0])+(2*sum(lim,fh(lim[0],lim[1],n),5))+f5(lim[1])))/(2*n))*(lim[1]-lim[0]);
                break;
        case 6: y=(((f6(lim[0])+(2*sum(lim,fh(lim[0],lim[1],n),6))+f6(lim[1])))/(2*n))*(lim[1]-lim[0]);
                break;
    }
    
    return y;
}



//**********************************************************************************************************************************************************************
//**********************************************************************************************************************************************************************
//**********************************************************************************************************************************************************************
//**********************Metodo 1/3 simple y multiple********************************************************************************************************************
//**********************************************************************************************************************************************************************
//**********************************************************************************************************************************************************************
//**********************************************************************************************************************************************************************
//**********************************************************************************************************************************************************************

void simpleU3(){
    int o;

    
    printf("Que ecuacion desea hacer?\n");
    printf("[1] 0.2+(25*i)-(200*i^2)+(675*i^3)-(900*i^4)+(400*i^5). \n");
    printf("[2] e^x.\n");
    printf("[3] 1/(1+x^2).\n");
    printf("[4] log10 x.\n");
    printf("[5] 1-x-(4x^3)+(2x^5).\n");
    printf("[6] (x+(1/x))^2.\n");
    scanf("%d",&o);
    switch(o){ 
        case 1:U3s(1);
               break;
        case 2:U3s(2);
               break;
        case 3:U3s(3);
               break;
        case 4:U3s(4);
               break;
        case 5:U3s(5);
               break;
        case 6:U3s(6);
               break;
    }
}

void U3s(int o){
  int i;
  float lim[2];
  float h;
  
  //alt + 97 =a
  printf("Introdusca los limites: \n");
  for(i=0;i<2;i++){
    printf("%c.- ", 97+i);
    scanf("%f",&lim[i]);
  }
  h=fh(lim[0],lim[1],2);

  switch(o){
      case 1:printf("La respuesta es: %.9f\n",U3ss(lim[0],lim[1],f1(lim[0]),f1(lim[1]),lim[0]+h));
             break;
      case 2:printf("La respuesta es: %.9f\n",U3ss(lim[0],lim[1],f2(lim[0]),f2(lim[1]),lim[0]+h));
             break;
      case 3:printf("La respuesta es: %.9f\n",U3ss(lim[0],lim[1],f3(lim[0]),f3(lim[1]),lim[0]+h));
             break;
      case 4:printf("La respuesta es: %.9f\n",U3ss(lim[0],lim[1],f4(lim[0]),f4(lim[1]),lim[0]+h));
             break;
      case 5:printf("La respuesta es: %.9f\n",U3ss(lim[0],lim[1],f5(lim[0]),f5(lim[1]),lim[0]+h));
             break;
      case 6:printf("La respuesta es: %.9f\n",U3ss(lim[0],lim[1],f6(lim[0]),f6(lim[1]),lim[0]+h));
             break;
  }
}

//**********************************************************************************************************************************************************************
//**********************************************************************************************************************************************************************
//**********************************************************************************************************************************************************************
//**********************************************************************************************************************************************************************

void multipleU3(){
    int o;

    
    printf("Que ecuacion desea hacer?\n");
    printf("[1] 0.2+(25*i)-(200*i^2)+(675*i^3)-(900*i^4)+(400*i^5). \n");
    printf("[2] e^x.\n");
    printf("[3] 1/(1+x^2).\n");
    printf("[4] log10 x.\n");
    printf("[5] 1-x-(4x^3)+(2x^5).\n");
    printf("[6] (x+(1/x))^2.\n");

    scanf("%d",&o);
    switch(o){
        case 1:U3m(1);
               break;
        case 2:U3m(2);
               break;
        case 3:U3m(3);
               break;
        case 4:U3m(4);
               break;
        case 5:U3m(5);
               break;
        case 6:U3m(6);
               break;
    }
}

void U3m(int o){
  int i;
  float lim[2];

  
  //alt + 97 =a
  printf("Introdusca los limites: \n");
  for(i=0;i<2;i++){
    printf("%c.- ", 97+i);
    scanf("%f",&lim[i]);
  }

  switch(o){
      case 1:printf("La respuesta es: %.9f\n",U3mm(lim, 1));
             break;
      case 2:printf("La respuesta es: %.9f\n",U3mm(lim, 2));
             break;
      case 3:printf("La respuesta es: %.9f\n",U3mm(lim, 3));
             break;
      case 4:printf("La respuesta es: %.9f\n",U3mm(lim, 4));
             break;
      case 5:printf("La respuesta es: %.9f\n",U3mm(lim, 5));
             break;
      case 6:printf("La respuesta es: %.9f\n",U3mm(lim, 6));
             break;
  }
}

double U3mm(float* lim, int o){
    int n, sumi=0;
    double y;
    printf("Introdusca entre cuantas partes desea dividirlo: ");scanf("%d",&n);
    switch(o){
        case 1: y=((f1(lim[0])+(2*sum2(lim,n,1,&sumi))+(4*sumi)+f1(lim[1]))/(3*n))*(lim[1]-lim[0]);
                break;
        case 2: y=((f2(lim[0])+(2*sum2(lim,n,2,&sumi))+(4*sumi)+f2(lim[1]))/(3*n))*(lim[1]-lim[0]);
                break;
        case 3: y=((f3(lim[0])+(2*sum2(lim,n,3,&sumi))+(4*sumi)+f3(lim[1]))/(3*n))*(lim[1]-lim[0]);
                break;
        case 4: y=((f4(lim[0])+(2*sum2(lim,n,4,&sumi))+(4*sumi)+f4(lim[1]))/(3*n))*(lim[1]-lim[0]);
                break;
        case 5: y=((f5(lim[0])+(2*sum2(lim,n,5,&sumi))+(4*sumi)+f5(lim[1]))/(3*n))*(lim[1]-lim[0]);
                break;
        case 6: y=((f6(lim[0])+(2*sum2(lim,n,6,&sumi))+(4*sumi)+f6(lim[1]))/(3*n))*(lim[1]-lim[0]);
                break;
    }
    return y;
}

//**********************************************************************************************************************************************************************
//**********************************************************************************************************************************************************************
//**********************************************************************************************************************************************************************
//**********************Metodo 3/8 simple*******************************************************************************************************************************
//**********************************************************************************************************************************************************************
//**********************************************************************************************************************************************************************
//**********************************************************************************************************************************************************************
//**********************************************************************************************************************************************************************

void simple3O(){
    int o;

    
    printf("Que ecuacion desea hacer?\n");
    printf("[1] 0.2+(25*i)-(200*i^2)+(675*i^3)-(900*i^4)+(400*i^5). \n");
    printf("[2] e^x.\n");
    printf("[3] 1/(1+x^2).\n");
    printf("[4] log10 x.\n");
    printf("[5] 1-x-(4x^3)+(2x^5).\n");
    printf("[6] (x+(1/x))^2.\n");
    scanf("%d",&o);
    switch(o){ 
        case 1:TOs(1);
               break;
        case 2:TOs(2);
               break;
        case 3:TOs(3);
               break;
        case 4:TOs(4);
               break;
        case 5:TOs(5);
               break;
        case 6:TOs(6);
               break;
    }
}

void TOs(int o){
      int i;
  float lim[2];
  float h;
  //alt + 97 =a
  printf("Introdusca los limites: \n");
  for(i=0;i<2;i++){
    printf("%c.- ", 97+i);
    scanf("%f",&lim[i]);
  }
  h=fh(lim[0],lim[1],3);

  switch(o){
      case 1:printf("La respuesta es: %.9f\n",TOss(lim[0],lim[1],f1(lim[0]),f1(lim[1]),lim[0]+h,lim[0]+2*h));
             break;
      case 2:printf("La respuesta es: %.9f\n",TOss(lim[0],lim[1],f2(lim[0]),f2(lim[1]),lim[0]+h,lim[0]+2*h));
             break;
      case 3:printf("La respuesta es: %.9f\n",TOss(lim[0],lim[1],f3(lim[0]),f3(lim[1]),lim[0]+h,lim[0]+2*h));
             break;
      case 4:printf("La respuesta es: %.9f\n",TOss(lim[0],lim[1],f4(lim[0]),f4(lim[1]),lim[0]+h,lim[0]+2*h));
             break;
      case 5:printf("La respuesta es: %.9f\n",TOss(lim[0],lim[1],f5(lim[0]),f5(lim[1]),lim[0]+h,lim[0]+2*h));
             break;
      case 6:printf("La respuesta es: %.9f\n",TOss(lim[0],lim[1],f6(lim[0]),f6(lim[1]),lim[0]+h,lim[0]+2*h));
             break;
  }
}