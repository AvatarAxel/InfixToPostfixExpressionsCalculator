#include <iostream>
using namespace std;
class Apila
{
    private:
        char *pila;
        int tope;
        int _pilaSize;
        int valorPriodadFueraPila;
        int valorPrioridadDentroPila;
        char *auxiliarExpresion;
        char *expresionPostfija;
        int indiceExpresionPostfija = 0;
        string expresionInfija;           
        
        bool esLleno(){
            if (tope==(_pilaSize)){
                return true;
            }else{
                return false;
            }
        }

        bool esVacio(){
            if (tope==-1){
                return true;
            }else{
                return false;
            }    
        }

    public:

        void inicializar(){
            tope = -1;
        }
        
        void setPila(int tamanio){
            pila = new char[tamanio];
            _pilaSize = tamanio-1;
        }

        void setExpresionInfija(string expresion){
            expresionInfija = expresion;
        }

        int getTope(){
            return tope;
        }

        void getExpresionPostfija(){
            cout<<"expresionPostfija: ";
            for (int i = 0; i < expresionInfija.length(); i++){
                cout<<expresionPostfija[i];
            }
            cout<<endl;
        }

        void tamanioExpresionPostfija(int tamanio){
            expresionPostfija = new char[tamanio];
        }

        void calcularExpresionInfija(){
            indiceExpresionPostfija = 0;
            for (int i = 0; i < expresionInfija.length() ; i++){
                if (expresionInfija.at(i) >= 48 and expresionInfija.at(i) <= 57 || expresionInfija.at(i) >= 65 and expresionInfija.at(i) <= 90 || expresionInfija.at(i) >= 97 and expresionInfija.at(i) <= 122){
                    expresionPostfija[indiceExpresionPostfija] = expresionInfija.at(i);
                    indiceExpresionPostfija++;
                }else{
                    if (expresionInfija.at(i) != ')'){
                        if (esVacio()){
                            Push(expresionInfija.at(i));
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
            if(prioridadFueraDeLaPila(expresionInfija.at(i)) > prioridadDentroDeLaPila(pila[tope])){
                Push(expresionInfija.at(i));
                return;
            }else{
                expresionPostfija[indiceExpresionPostfija] = pila[tope];
                Pop();
                indiceExpresionPostfija++;
                compararPrioridades(i);
            }   
        }

        void pilaAPostfija(){
            if (Top() == '('){
                Pop();
                return;
            }else{
                expresionPostfija[indiceExpresionPostfija] = pila[tope];
                indiceExpresionPostfija++;
                Pop();
                pilaAPostfija();
            }      
        }

        void pasarTodoContenidoDePilaAPost(){
            if (esVacio()){
                return;
            }else{
                expresionPostfija[indiceExpresionPostfija] = pila[tope];
                indiceExpresionPostfija++;
                Pop();
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

        int Push(char dato){
            if (!esLleno()){
                tope++;          
                pila[tope] = dato;
            }else{
                return -1;
            }    
        }

        int Pop(){
            if (!esVacio()){
                char caracter;
                caracter = pila[tope];
                pila[tope] = -1;
                tope--;
                return 1;//Para saber que si saco el elemento
            }else{
                return -1;
            }
        }

        int Top(){
            if (!esVacio()){
                return pila[tope];
            }else{
                return -1;
            }
        }

        int Clear(){
            if (esVacio()){
                return 0;
            }else{
                Pop();
                Clear();
            }
        }

        void showAll(int cont){
            if (cont == -1){
                return;
            }else{
                cout<<pila[cont]<<endl;
                showAll(cont-1);
            }
        }      
};