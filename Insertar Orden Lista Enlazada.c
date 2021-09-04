#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

typedef struct Nodo Nodo;
typedef  Nodo *ptrNodo;



struct Nodo
{
    int numero;
    
     Nodo *next;
    
};
bool validar(char respuesta);
void insertar (ptrNodo*lista,int numero);
void imprimir(ptrNodo lista);
int main(){
    char respuesta;
    ptrNodo lista=NULL;
    int numero;
    do{
        printf("Ingrese dia\n");
        scanf("%d",&numero);
        fflush(stdin);
        printf("Continuar?\n");
        scanf("%c",&respuesta);
        fflush(stdin);
        insertar(&lista,numero);
        
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
void insertar (ptrNodo*lista,int numero){
    ptrNodo nuevo;
    ptrNodo anterior;
    ptrNodo auxiliar;
    nuevo=(Nodo*)malloc(sizeof(Nodo));
    nuevo->numero=numero;
    nuevo->next=NULL;
    anterior=NULL;
    auxiliar=*lista;
    while (auxiliar!=NULL&&numero>auxiliar->numero)
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


void imprimir(ptrNodo lista){
    
    while(lista  != NULL){
        printf("%d\n",lista->numero);

        lista= lista->next;
    }
}