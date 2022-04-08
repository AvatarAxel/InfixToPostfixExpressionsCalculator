#include <iostream>
using namespace std;
class Apila
{

    private:
        string *pila;
        int tope;
        int _pilaSize;          

    public:    
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

        void inicializar(){
            tope = -1;
        }
        
        void setPila(int tamanio){
            pila = new string[tamanio];
            _pilaSize = tamanio-1;
        }

        int getTope(){
            return tope;
        }

        int Push(string dato){
            if (!esLleno()){
                tope++;          
                pila[tope] = dato;
                return 0;
            }else{
                return -1;
            }    
        }

        int Pop(){
            if (!esVacio()){
                string caracter;
                caracter = pila[tope];
                pila[tope] = -1;
                tope--;
                return 1;
            }else{
                return -1;
            }
        }

        string Top(){
            if (!esVacio()){
                return pila[tope];
            }else{
                return "1";
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