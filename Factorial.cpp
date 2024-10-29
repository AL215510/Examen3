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

/**Código principal**/
int main(){
    /**Inserción del número a factorar**/
    int num;
    cout << "Ingrese el numero al que desea calcular la factorial: ";
    cin >> num;

    /**Impresión del resultado**/
    float NumFact = factorial(num);
    cout << "El factorial del numero " << num << " es: " << NumFact;
}