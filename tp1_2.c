#include <stdio.h>

// a) funcion que devuelve el cuadrado (paso por valor)
int cuadrado(int n) {
    return n * n;
}

// b) funcion cuadrado tipo void (paso por referencia)
void cuadradoVoid(int *n) {
    *n = (*n) * (*n);
}

// c) mostrar direccion y contenido
void mostrarDatos(int *var) {
    printf("Contenido: %d\n", *var);
    printf("Direccion: %p\n", (void*)var);
}

// d) invertir valores
void invertir(int *a, int *b) {
    int aux = *a;
    *a = *b;
    *b = aux;
}

// e) ordenar de menor a mayor
void ordenar(int *a, int *b) {
    if (*a > *b) {
        invertir(a, b); // Reutilizamos la función invertir
    }
}

int main() {
    int num1, num2;

    // f) Leer pares de valores e imprimirlos
    printf("ingrese el primer numero: ");
    scanf("%d", &num1);
    printf("ingrese el segundo numero: ");
    scanf("%d", &num2);

    printf("\n--- resultados ---\n");
    
    printf("el cuadrado de %d es: %d\n", num1, cuadrado(num1));
    
    printf("datos de num1:\n");
    mostrarDatos(&num1);

    printf("\nordenando los valores...\n");
    ordenar(&num1, &num2);
    printf("menor: %d | mayor: %d\n", num1, num2);

    printf("\ninvirtiendo los valores...\n");
    invertir(&num1, &num2);
    printf("ahora num1 es: %d y num2 es: %d\n", num1, num2);

    return 0;
}