#include <iostream>
#include "APila.h"
#include <string>

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
        string string_expresionPostfija;
        string expresionInfija;
        int numero01 = 0;
        int numero02 = 0;
        int resultado = 0; 

    public:
        Apila objPila;

        void setExpresionInfija(string expresion){
            expresionInfija = expresion;
            objPila.inicializar();
            objPila.setPila(expresionInfija.length());
        }

        void getExpresionPostfija(){
            //string_expresionPostfija = "";
            //int tamanio = expresionInfija.length() - contadorParantesis;
            
            for (int i = 0; i < tamanioExpresionPostfija; i++){
                cout<<expresionPostfija[i]<<endl;
                //cout<<i+1;
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
            indiceExpresionPostfija = 0;
            vaciarExpresionPostfija();
            for (int i = 0; i < expresionInfija.length() ; i++){
                if (expresionInfija.at(i) >= 48 and expresionInfija.at(i) <= 57 || expresionInfija.at(i) >= 65 and expresionInfija.at(i) <= 90 || expresionInfija.at(i) >= 97 and expresionInfija.at(i) <= 122){
                    expresionPostfija[indiceExpresionPostfija] += expresionInfija.at(i);
                    //indiceExpresionPostfija++;                        
                }else{
                    if (expresionInfija.at(i) != ')'){
                        if (objPila.esVacio()){
                            objPila.Push(expresionInfija.at(i));
                            indiceExpresionPostfija++;
                        }else{
                            //indiceExpresionPostfija++;
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
                indiceExpresionPostfija++;//TENTADOR
                return;
            }else{
                indiceExpresionPostfija++;
                expresionPostfija[indiceExpresionPostfija] = objPila.Top().at(0);
                objPila.Pop();
                //indiceExpresionPostfija++;
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
                //indiceExpresionPostfija++;
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
                //indiceExpresionPostfija++;
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
            objPila.inicializar();
            for (int i = 0; i < string_expresionPostfija.length(); i++){   
                if (!identificadorOperandos(string_expresionPostfija.at(i))){
                    objPila.Push(string_expresionPostfija.at(i));
                    cout<<"Si es: "<<string_expresionPostfija.at(i)<<endl;
                }else{
                    if (!objPila.esVacio()){                      
                        numero01 = (int)objPila.Top();
                        objPila.Pop();
                        numero02 = (int)objPila.Top();
                        objPila.Pop();
                        resultado = numero01 string_expresionPostfija.at(i) numero02;
                        cout<<"No es: "<<resultado;
                    }
                }              
            }
        }*/


        bool identificadorOperandos(char caracterExpresionInfija){
            switch (caracterExpresionInfija){
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