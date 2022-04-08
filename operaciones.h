#include <iostream>
#include "APila.h"
#include <string>
#include <cstdlib>

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
        string *string_expresionPostfija;
        string expresionInfija;
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
                    cout<<expresionPostfija[i]<<endl;
                }
            }
            

/*
            string_expresionPostfija = new string[cont];

            for (int j = 0; j < cont ; j++){
                if ( ){
                    /* code
                }
                
                string_expresionPostfija[j] = ;
            }*/
            
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
            auxiliar = true;
            for (int i = 0; i < expresionInfija.length() ; i++){
                if (expresionInfija.at(i) >= 48 and expresionInfija.at(i) <= 57 || expresionInfija.at(i) >= 65 and expresionInfija.at(i) <= 90 || expresionInfija.at(i) >= 97 and expresionInfija.at(i) <= 122){
                    if (auxiliar == false){
                        indiceExpresionPostfija++;
                    }
                    expresionPostfija[indiceExpresionPostfija] += expresionInfija.at(i);
                    auxiliar = true;
                    //indiceExpresionPostfija++;                        
                }else{
                    auxiliar = false;
                    if (expresionInfija.at(i) != ')'){
                        if (objPila.esVacio()){
                            objPila.Push( expresionInfija.substr(i,i));
                            //indiceExpresionPostfija++;
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
                objPila.Push( expresionInfija.substr(i,i)  /*expresionInfija.at(i)*/);
                //indiceExpresionPostfija++;//TENTADOR
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
            for (int i = 0; i < tamanioExpresionPostfija; i++){   
                if (string_expresionPostfija[i] != ""){
                    if (!identificadorOperandos(string_expresionPostfija[i])){
                        objPila.Push(string_expresionPostfija[i]);
                        cout<<"Si es: "<<string_expresionPostfija[i]<<endl;
                    }else{
                        if (!objPila.esVacio()){                      
                            //TO DO
                            //numero01 = (atof)objPila.Top().at();
                            objPila.Pop();
                            //numero02 = (atof)objPila.Top();
                            objPila.Pop();
                            //resultado = numero01 string_expresionPostfija.at(i) numero02;
                            cout<<"No es: "<<resultado;
                        }
                    }
                }           
            }
        }*/


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