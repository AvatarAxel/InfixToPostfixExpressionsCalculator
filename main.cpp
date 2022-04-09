#include <iostream>
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
        cout<<"3.  Mostrar resultado de la expresion"<<endl;
        cout<<"4.  Salir"<<endl;              
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
            objOperaciones.calcularParentesis();
            objOperaciones.setTamanioExpresionPostfija(tamanio);
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
            pause();
            break;
        case 4:
            system("clear");
            cout<<"Finalizado"<<endl;
            cout<<"Presione ENTER para continuar...";
            pause();
            break;                               
        default:
            system("clear");
            cout<<"Valor invalido, presione ENTER para continuar...";
            pause();
            break;
        }
    }while(opcion != 4);
        
    return 0;
}

void pause(){
    const char ENTER = '\n';
    char lectura = cin.get();
    while( lectura != ENTER)
    lectura = cin.get();
}