#include <iostream>
using namespace std;
class Apila
{

    private:
        char *pila;//Cambiarla al tipo string
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
            pila = new char[tamanio];
            _pilaSize = tamanio-1;
        }

        int getTope(){
            return tope;
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
                return 1;
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