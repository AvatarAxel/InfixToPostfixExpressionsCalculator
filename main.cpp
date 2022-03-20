#include <iostream>
#include <string.h>
#include "APila.h"
using namespace std;

void pause();

int main(){
    int opcion;
    int tamanio;
    int dato;
    string expresion;
    
    Apila objPila;
    objPila.inicializar();
    do{
        system("clear");
        cout<<"1.  Ingresar el arreglo infijo"<<endl;
        cout<<"2.  Mostrar arreglo postfijo"<<endl;
        cout<<"3.  Eliminar dato"<<endl;
        cout<<"4.  Mostrar pares"<<endl;
        cout<<"5.  Mostrar impares"<<endl;
        cout<<"6.  Vaciar"<<endl;
        cout<<"7.  Salir"<<endl;      
        cout<<"Elija una opcion: ";
        
        cin>>opcion;
        cin.ignore();
        switch (opcion){        
        case 1:
            system("clear");            
            cout<<"Ingrese la expresion aritmetica infija: ";
            cin>>expresion;
            tamanio = expresion.length();
            cout<<tamanio<<endl;
            objPila.setPila(tamanio);
            objPila.setExpresionInfija(expresion);
            objPila.setExpresionPostfija(tamanio,expresion);
            cin.ignore();
            cout<<"Presione ENTER para continuar...";
            pause();
            break;
        case 2:
            system("clear");
            objPila.calcularExpresionPostfija();
            cout<<"Presione ENTER para continuar...";
            pause();
            break;
        case 3:
            system("clear");
            if (objPila.Pop()==-1){
                cout<<"La pila ya se encuentra vacia"<<endl;
            }
            cout<<"Presione ENTER para continuar...";
            pause();          
            break;
        case 4:
            system("clear");
            objPila.calcularExpresionPostfija();
            cout<<"Presione ENTER para continuar...";
            pause();            
            break;
        case 5:
            system("clear");
            objPila.mostraInpares(0);
            cout<<"Presione ENTER para continuar...";
            pause();            
            break;
        case 6:
            system("clear");
            objPila.Clear();
            cout<<"Pila vaciada"<<endl;
            cout<<"Presione ENTER para continuar...";
            pause();            
            break;
        case 7:
            system("clear");
            cout<<"Finalizado"<<endl;
            cout<<"Presione ENTER para continuar...";
            pause();
            break;           
        default:
            system("clear");
            cout<<"Valor invalido, pulse enter para continuar...";
            cout<<"Presione ENTER para continuar...";
            pause();
            break;
        }
    }while(opcion != 7);
        
    return 0;
}

//Funcion para poder poner pause en UNIX y esperar un ENTER
void pause(){
    const char ENTER = '\n';
    char lectura = cin.get();
    while( lectura != ENTER)
    lectura = cin.get();
}