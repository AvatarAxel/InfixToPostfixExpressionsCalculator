#include <iostream>
using namespace std;
class Apila
{
    private:
        int *pila;
        int tope;
        int _pilaSize;
        int valor;
        char *auxiliarExpresion;
        char *expresionPostfija;
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
            pila = new int[tamanio];
            _pilaSize = tamanio-1;
        }

        void setExpresionInfija(string expresion){
            expresionInfija = expresion;
        }

        void setExpresionPostfija(int tamanio, string expresion){
            expresionPostfija = new char[tamanio];
        }

        void getExpresionPostfija(){
            cout<<"Arreglo postfijo: "<<endl;
        }

        void calcularExpresionPostfija(){
            auxiliarExpresion = new char[expresionInfija.length()];

            for (int i = 0; i < expresionInfija.length() ; i++){
                if (expresionInfija.at(i) >= 48 and expresionInfija.at(i) <= 57){
                    cout<<"Es un numero: "<<expresionInfija.at(i)<<endl;
                }else{
                    cout<<"Simbolo: "<<expresionInfija.at(i)<<endl;
                    cout<<"valor del simbolo: "<<prioridadFueraDeLaPila(expresionInfija.at(i))<<endl;
                }
            }
        }

        int prioridadFueraDeLaPila(char caracterExpresionInfija){
            switch (caracterExpresionInfija){
                case '^':
                    valor = 4;
                    return valor;
                    break;
                case '*':
                    valor = 2;
                    return valor;
                    break;
                case '/':
                    valor = 2;
                    return valor;
                    break;
                case '+':
                    valor = 1;
                    return valor;
                    break;
                case '-':
                    valor = 1;
                    return valor;
                    break;
                case '(':
                    valor = 5;
                    return valor;
                    break;
                default:
                    return -1;
                    break;
            }
        }

int prioridadDentroDeLaPila(char caracterExpresionInfija){
            switch (caracterExpresionInfija){
                case '^':
                    valor = 3;
                    return valor;
                    break;
                case '*':
                    valor = 2;
                    return valor;
                    break;
                case '/':
                    valor = 2;
                    return valor;
                    break;
                case '+':
                    valor = 1;
                    return valor;
                    break;
                case '-':
                    valor = 1;
                    return valor;
                    break;
                case '(':
                    valor = 0;
                    return valor;
                    break;
                default:
                    return -1;
                    break;
            }
        }        

        
        int Push(int dato){
            if (!esLleno()){
                tope++;          
                pila[tope] = dato;
            }else{
                return -1;
            }    
        }

        int Pop(){
            if (!esVacio()){
                int num;
                num = pila[tope];
                pila[tope] = -1;
                tope--;
                cout<<"Dato eliminado: "<<num<<endl;
                return num;//Para saber que si saco el elemento
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
            if (cont > tope){
                return;
            }else{
                cout<<pila[cont]<<endl;
                showAll(cont+1);
            }
        }

        void mostraPares(int cont){
            if (cont > tope){
                return;
            }else{
                if (pila[cont]%2==0){
                    cout<<pila[cont]<<endl;
                }
                mostraPares(cont+1);
            }
        }
        
        void mostraInpares(int cont){
            if (cont > tope){
                return;
            }else{
                if (pila[cont]%2!=0){
                    cout<<pila[cont]<<endl;
                }
                mostraInpares(cont+1);
            }
        }        
};