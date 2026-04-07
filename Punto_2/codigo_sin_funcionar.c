#include <stdio.h>
// codigo_roto.c
// Ahora recibe un PUNTERO para poder modificar el original
void duplicar_numero(int *numero) {
    *numero = (*numero) * 2;
}

int main() {
    int valor1;
    int valor2;

    printf("Ingrese el primer valor: ");
    // ERROR CORREGIDO: Se agrego & para dar la direccion de memoria
    scanf("%d", &valor1);

    printf("Ingrese el segundo valor: ");
    scanf("%d", &valor2);

    // ERROR CORREGIDO: Se agrego ; al final
    int suma = valor1 + valor2;
    printf("La suma es: %d\n", suma);

    // ERROR CORREGIDO: Se envía la direccion con &
    duplicar_numero(&valor1);
    printf("El primer valor duplicado es: %d\n", valor1);

    // ERROR CORREGIDO: Se agrego ; al final
    return 0;
}