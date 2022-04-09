#include <iostream>
#include "APila.h"
#include <string>
#include <math.h>

using namespace std;
class operaciones
{
    private:
        int valorPriodadFueraPila;
        int valorPrioridadDentroPila;
        int contadorParantesis = 0;
        int tamanioExpresionPostfija = 0;
        string *expresionPostfija;
        int indiceExpresionPostfija = 0;
        string expresionInfija;
        string string_aux;
        bool auxiliar = true;
        double numero01 = 0;
        double numero02 = 0;
        double resultado = 0; 

    public:
        Apila objPila;

        void setExpresionInfija(string expresion){
            expresionInfija = expresion;
            objPila.inicializar();
            objPila.setPila(expresionInfija.length());
        }

        void getExpresionPostfija(){
            for (int i = 0; i < tamanioExpresionPostfija; i++){
                if (expresionPostfija[i] != ""){
                    cout<<expresionPostfija[i];
                }
            }
            cout<<endl;
        }

        void calcularParentesis(){
            contadorParantesis = 0;
            for (int i = 0; i < expresionInfija.length(); i++){
                if (expresionInfija.at(i) == ')' || expresionInfija.at(i) == '('){
                    contadorParantesis++;
                }
            }
        }

        void setTamanioExpresionPostfija(int tamanio){
            tamanioExpresionPostfija = tamanio - contadorParantesis;
            expresionPostfija = new string[tamanioExpresionPostfija];
        }      

        void vaciarExpresionPostfija(){
            for (int i = 0; i < tamanioExpresionPostfija; i++){
                expresionPostfija[i] = "";
            }
        }

        void calcularExpresionPostfija(){
            string_aux = "";
            indiceExpresionPostfija = 0;
            vaciarExpresionPostfija();
            auxiliar = true;
            for (int i = 0; i < expresionInfija.length() ; i++){
                if (expresionInfija.at(i) >= 48 and expresionInfija.at(i) <= 57 || expresionInfija.at(i) >= 65 and expresionInfija.at(i) <= 90 || expresionInfija.at(i) >= 97 and expresionInfija.at(i) <= 122){
                    if (auxiliar == false){
                        indiceExpresionPostfija++;
                    }
                    expresionPostfija[indiceExpresionPostfija] += expresionInfija.at(i);
                    auxiliar = true;                      
                }else{
                    auxiliar = false;
                    if (expresionInfija.at(i) != ')'){
                        if (objPila.esVacio()){
                            string_aux = "";
                            string_aux.append(1, expresionInfija.at(i));
                            objPila.Push(string_aux);
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
                string_aux = "";
                string_aux.append(1, expresionInfija.at(i));
                objPila.Push(string_aux);
                return;
            }else{
                indiceExpresionPostfija++;
                expresionPostfija[indiceExpresionPostfija] = objPila.Top().at(0);
                objPila.Pop();
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
                indiceExpresionPostfija++;
                expresionPostfija[indiceExpresionPostfija] = objPila.Top().at(0);
                objPila.Pop();
                pilaAPostfija();
            }      
        }    

        void pasarTodoContenidoDePilaAPost(){
            if (objPila.esVacio()){
                return;
            }else{
                indiceExpresionPostfija++;
                expresionPostfija[indiceExpresionPostfija] = objPila.Top().at(0);
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

        void evaluarExpresion(){
            objPila.inicializar();
            resultado = 0;
            for (int i = 0; i < tamanioExpresionPostfija; i++){   
                if (expresionPostfija[i] != ""){
                    if (!identificadorOperandos(expresionPostfija[i])){
                        objPila.Push(expresionPostfija[i]);
                    }else{
                        if (!objPila.esVacio()){                      
                            numero02 = stof(objPila.Top());
                            objPila.Pop();
                            numero01 = stof(objPila.Top());
                            objPila.Pop();
                            realizarOperacion(expresionPostfija[i]);
                            numero01 = 0;
                            numero02 = 0;
                            objPila.Push(to_string(resultado));
                        }
                    }
                }           
            }
            cout<<"Resultado: "<<objPila.Top()<<endl;
        }

        void realizarOperacion(string caracterExpresionPostfija){
            switch (caracterExpresionPostfija.at(0)){
                case '^':
                    resultado = pow(numero01,numero02);
                    break;
                case '*':
                    resultado = numero01*numero02;
                    break;
                case '/':
                    resultado = numero01/numero02;
                    break;
                case '+':
                    resultado = numero01+numero02;
                    break;
                case '-':
                    resultado = numero01-numero02;
                    break;
                default:
                    break;
            }
        }                             

        bool identificadorOperandos(string caracterExpresionInfija){
            switch (caracterExpresionInfija.at(0)){
                case '^':
                    return true;
                    break;
                case '*':
                    return true;
                    break;
                case '/':
                    return true;
                    break;
                case '+':
                    return true;
                    break;
                case '-':
                    return true;
                    break;
                default:
                    return false;
                    break;
            }
        }                                                    

};