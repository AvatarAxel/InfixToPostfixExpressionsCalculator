#include <iostream>
#include <cstdlib>//Castear de int a char y de char int
#include "operaciones.h"
using namespace std;

void pause();

int main(){
    int opcion;
    int tamanio;
    int dato;
    string expresion;
    
    operaciones objOperaciones;
    do{
        system("clear");
        cout<<"1.  Ingresar el arreglo infijo"<<endl;
        cout<<"2.  Mostrar arreglo postfijo"<<endl;
        cout<<"3.  Salir"<<endl;      
        cout<<"Elija una opcion: ";
        
        cin>>opcion;
        cin.ignore();
        switch (opcion){        
        case 1:
            system("clear");            
            cout<<"Ingrese la expresion aritmetica infija: ";
            cin>>expresion;
            tamanio = expresion.length();
            objOperaciones.setExpresionInfija(expresion);
            objOperaciones.tamanioExpresionPostfija(tamanio);
            objOperaciones.calcularParentesis();
            cin.ignore();
            cout<<"Presione ENTER para continuar...";
            pause();
            break;
        case 2:
            system("clear");
            objOperaciones.calcularExpresionPostfija();
            objOperaciones.getExpresionPostfija();
            cout<<"Presione ENTER para continuar...";
            pause();
            break;
        case 3:
            system("clear");
            cout<<"Finalizado"<<endl;
            cout<<"Presione ENTER para salir...";
            pause();
            break;                   
        default:
            system("clear");
            cout<<"Valor invalido, presione ENTER para continuar...";
            pause();
            break;
        }
    }while(opcion != 3);
        
    return 0;
}

//Funcion para poder poner pause en UNIX y esperar un ENTER
void pause(){
    const char ENTER = '\n';
    char lectura = cin.get();
    while( lectura != ENTER)
    lectura = cin.get();
}