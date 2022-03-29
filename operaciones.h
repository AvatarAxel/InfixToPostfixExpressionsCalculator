#include <iostream>
#include "APila.h"
#include <string>

//#include <> agregar libreria matematica
using namespace std;
class operaciones
{
    private:
        int valorPriodadFueraPila;
        int valorPrioridadDentroPila;
        int contadorParantesis = 0;
        char *expresionPostfija;
        int indiceExpresionPostfija = 0;
        string string_expresionPostfija;
        string expresionInfija; 

    public:
        Apila objPila;

        void setExpresionInfija(string expresion){
            expresionInfija = expresion;
            objPila.inicializar();
            objPila.setPila(expresionInfija.length());
        }

        string getExpresionPostfija(){
            string_expresionPostfija = "";
            int tamanio = expresionInfija.length() - contadorParantesis;
            for (int i = 0; i < tamanio; i++){
                string_expresionPostfija+=expresionPostfija[i];
            }
            return string_expresionPostfija;
        }



        void calcularParentesis(){
            contadorParantesis = 0;
            for (int i = 0; i < expresionInfija.length(); i++){
                if (expresionInfija.at(i) == ')' || expresionInfija.at(i) == '('){
                    contadorParantesis++;
                }
            }
        }

        void tamanioExpresionPostfija(int tamanio){
            expresionPostfija = new char[tamanio];
        }      

        void calcularExpresionPostfija(){
            indiceExpresionPostfija = 0;
            for (int i = 0; i < expresionInfija.length() ; i++){
                if (expresionInfija.at(i) >= 48 and expresionInfija.at(i) <= 57 || expresionInfija.at(i) >= 65 and expresionInfija.at(i) <= 90 || expresionInfija.at(i) >= 97 and expresionInfija.at(i) <= 122){
                    expresionPostfija[indiceExpresionPostfija] = expresionInfija.at(i);
                    indiceExpresionPostfija++;
                }else{
                    if (expresionInfija.at(i) != ')'){
                        if (objPila.esVacio()){
                            objPila.Push(expresionInfija.at(i));
                        }else{
                            compararPrioridades(i);
                        }                        
                    }else{
                        pilaAPostfija();                     
                    }
                }
            }
            pasarTodoContenidoDePilaAPost();
        }   

        void compararPrioridades(int i){
            if(prioridadFueraDeLaPila(expresionInfija.at(i)) > prioridadDentroDeLaPila(objPila.Top().at(0))){
                objPila.Push(expresionInfija.at(i));
                return;
            }else{
                expresionPostfija[indiceExpresionPostfija] = objPila.Top().at(0);
                objPila.Pop();
                indiceExpresionPostfija++;
                compararPrioridades(i);
            }   
        }          

        void pilaAPostfija(){
            if (objPila.Top().at(0) == '('){
                objPila.Pop();
                return;
            }else{
                if (objPila.esVacio() == true){
                    return;
                }
                expresionPostfija[indiceExpresionPostfija] = objPila.Top().at(0);
                indiceExpresionPostfija++;
                objPila.Pop();
                pilaAPostfija();
            }      
        }    

        void pasarTodoContenidoDePilaAPost(){
            if (objPila.esVacio()){
                return;
            }else{
                expresionPostfija[indiceExpresionPostfija] = objPila.Top().at(0);
                indiceExpresionPostfija++;
                objPila.Pop();
                pasarTodoContenidoDePilaAPost();
            }
        }   

        int prioridadFueraDeLaPila(char caracterExpresionInfija){
            switch (caracterExpresionInfija){
                case '^':
                    valorPriodadFueraPila = 4;
                    return valorPriodadFueraPila;
                    break;
                case '*':
                    valorPriodadFueraPila = 2;
                    return valorPriodadFueraPila;
                    break;
                case '/':
                    valorPriodadFueraPila = 2;
                    return valorPriodadFueraPila;
                    break;
                case '+':
                    valorPriodadFueraPila = 1;
                    return valorPriodadFueraPila;
                    break;
                case '-':
                    valorPriodadFueraPila = 1;
                    return valorPriodadFueraPila;
                    break;
                case '(':
                    valorPriodadFueraPila = 5;
                    return valorPriodadFueraPila;
                    break;
                default:
                    return -1;
                    break;
            }
        }    

        int prioridadDentroDeLaPila(char caracterExpresionInfija){
            switch (caracterExpresionInfija){
                case '^':
                    valorPrioridadDentroPila = 3;
                    return valorPrioridadDentroPila;
                    break;
                case '*':
                    valorPrioridadDentroPila = 2;
                    return valorPrioridadDentroPila;
                    break;
                case '/':
                    valorPrioridadDentroPila = 2;
                    return valorPrioridadDentroPila;
                    break;
                case '+':
                    valorPrioridadDentroPila = 1;
                    return valorPrioridadDentroPila;
                    break;
                case '-':
                    valorPrioridadDentroPila = 1;
                    return valorPrioridadDentroPila;
                    break;
                case '(':
                    valorPrioridadDentroPila = 0;
                    return valorPrioridadDentroPila;
                    break;
                default:
                    return -1;
                    break;
            }
        }

        //Encontrar el resultado  

        /*void evaluarExpresion(){
            if (){
                
            }
            
        }*/                                                       

};