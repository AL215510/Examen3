/**Arturo Pérez González - 215510
 * Código que, utilizando la recursividad, genera el factorial de un numero ingresado**/
#include <iostream>
#include <stdlib.h>
#include <stdio.h>
#include <math.h>
using namespace std;

/**Función factorial**/
float factorial(int x){
    if(x <= 1){
        return 1;
    }
    return x * factorial(x - 1);
}

/**Estructura de nodo para los procesos del banco**/
struct nodo{
	string proceso;
	int saldo;
	nodo * siguiente;
};
typedef struct nodo * C;

/**Funcion para insertar el historial**/
void InsertarSaldo(C &lista, int s){
	C aux1 = new nodo;
	C aux2 = new nodo;
	
	aux1->saldo = s;
	aux1->siguiente = NULL;
	
	if(lista == NULL){
		lista = aux1;
	}else{
		aux2 = lista;
		while(aux2->siguiente != NULL){
			aux2 = aux2->siguiente;
		}
		aux2->siguiente = aux1;
	}
}

/**Código principal**/
int main(){
    int opc, cont, cont1;
    C lista = NULL;
    int opc1, sald = 20000;
    int ret, depo;

    do{
        cout << "Elija el codigo que quiere utilizar: " << endl;
        cout << "1.Numero Factorial" << endl;
        cout << "2.Cajero automatico" << endl;
        cin >> opc;
        
        switch (opc)
        {
        case 1:
            do 
            {
                /**Inserción del número a factorar**/
                int num;
                cout << endl << "Ingrese el numero al que desea calcular la factorial: ";
                cin >> num;

                /**Impresión del resultado**/
                float NumFact = factorial(num);
                cout << "El factorial del numero " << num << " es: " << NumFact << endl;
                cout << "Desea seguir usando el codigo factorial? (1.Si / 2.No): ";
                cin >> cont1;
                cout << endl;
            }while (cont1 == 1);
            break;
        case 2:            
            do{
                cout << endl << "****Cuenta de banco****" << endl
                << "1.Consulta de saldo" << endl
                << "2.Retiro" << endl
                << "3.Deposito" << endl
                << "0.Salir" << endl
                << "Ingresar opcion: ";
                cin >> opc1;
                cout << endl;
                
                switch(opc1){
                    case 1:
                        cout << endl << "Su saldo en su cuenta es: " << sald << endl << endl;
                        InsertarSaldo(lista, sald);
                        break;
                    case 2:
                        cout << "Ingrese la cantidad que desea retirar: ";
                        cin >> ret;
                        cout << endl;
                        sald -= ret;
                        cout << "Se ha retirado exitosamente el dinero" << endl << endl;
                        InsertarSaldo(lista, sald);
                        break;
                    case 3:
                        cout << "Ingrese la cantidad que desea depositar a su cuenta" << endl;
                        cin >> depo;
                        sald += depo;
                        cout << endl;
                        cout << "Se ha depositado exitosamente el dinero" << endl << endl;
                        InsertarSaldo(lista, sald);
                        break;
                    case 0:
                        cout << "Saliendo..." << endl << endl;
                        break;
                    default:
                        break;
                }
            }while(opc1 != 0);
            break;
        default:
            cout << "Elija una opcion valida!!!" << endl << endl;
            break;
        }
        cout << endl << "Desea seguir usando el programa? (1.Si / 2.No): ";
        cin >> cont;
        cout << endl;
    }while(cont == 1);
    cout << "Ha salido del programa!!";
}