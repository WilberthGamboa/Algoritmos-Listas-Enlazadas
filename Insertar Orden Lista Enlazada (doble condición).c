#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Nodo Nodo;
typedef  Nodo *ptrNodo;



struct Nodo
{
    int numero;
    int hora;
    
     Nodo *next;
    
};
bool validar(char respuesta);
void insertar (ptrNodo*lista,int numero,int hora);
void imprimir(ptrNodo lista);
int main(){
    char respuesta;
    ptrNodo lista=NULL;
    int numero;
    int hora;
    do{
        printf("Ingrese dia\n");
        scanf("%d",&numero);
        fflush(stdin);
         printf("Ingrese hora\n");
        scanf("%d",&hora);
        fflush(stdin);
        printf("Continuar?\n");
        scanf("%c",&respuesta);
        fflush(stdin);
        insertar(&lista,numero,hora);
        
    }while(validar(respuesta));
    imprimir(lista);
    return 0;
}

bool validar(char respuesta){
    if(respuesta=='s'){
        return true;
    }
    return false;
}
void insertar (ptrNodo*lista,int numero,int hora){
    ptrNodo nuevo;
    ptrNodo anterior;
    ptrNodo auxiliar;
    nuevo=(Nodo*)malloc(sizeof(Nodo));
    nuevo->numero=numero;
    nuevo->hora=hora;
    nuevo->next=NULL;
    anterior=NULL;
    auxiliar=*lista;


    while ((auxiliar!=NULL&&numero>auxiliar->numero)||(auxiliar!=NULL&&numero==auxiliar->numero&&hora>auxiliar->hora))
    {
        anterior=auxiliar;
        auxiliar=auxiliar->next;
        /* code */
    }
    if(anterior==NULL){
        nuevo->next=*lista;
        *lista=nuevo;
    }else{
        anterior->next=nuevo;
        nuevo->next=auxiliar;
    }
    

   
}

    /*if(anterior==NULL){
        nuevo->next=*lista;
        *lista=nuevo;
    }else{
        while (auxiliar!=NULL){
            if((numero==auxiliar->numero)&&(hora>auxiliar->hora)){
            anterior=auxiliar;
            auxiliar=auxiliar->next;

        }else if(numero>auxiliar->numero){
            anterior=auxiliar;
            auxiliar=auxiliar->next;

        }
        anterior->next=nuevo;
        nuevo->next=auxiliar;

        }
        
        
    } 
    */
    
    
    
    
    
    /*
    while (auxiliar!=NULL)
    {
        if((numero==auxiliar->numero)&&(hora>auxiliar->hora)){
            anterior=auxiliar;
            auxiliar=auxiliar->next;

        }else if(numero>auxiliar->numero){
            anterior=auxiliar;
            auxiliar=auxiliar->next;

        }
        
        
    }
    if(anterior==NULL){
        nuevo->next=*lista;
        *lista=nuevo;
    }else{
        anterior->next=nuevo;
        nuevo->next=auxiliar;
    }
    */

   



void imprimir(ptrNodo lista){
    
    while(lista  != NULL){
        printf("numero: %d\n",lista->numero);
        printf("hora: %d\n",lista->hora);

        lista= lista->next;
    }
}