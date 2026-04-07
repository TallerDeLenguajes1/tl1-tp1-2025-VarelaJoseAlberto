#include <stdio.h>
int main(int argc, char const *argv[])
{
    // inciso 4a
    printf("hola mundo");

    int variable = 10;
    int *p_variable = &variable;

    // 1) El contenido del puntero (la dirección a la que apunta) 
    printf("1) Contenido del puntero: %p\n", (void*)p_variable);
    
    // 2) La direccion de memoria almacenada por el puntero 
    // Nota: Debería ser igual al punto anterior.
    printf("2) Direccion almacenada por el puntero: %p\n", (void*)p_variable);

    // 3) La direccion de memoria de la variable original 
    printf("3) Direccion de memoria de la variable: %p\n", (void*)&variable);

    // 4) La direccion de memoria del propio puntero 
    // ¡Ojo! Esta es la ubicación del puntero, no a donde apunta.
    printf("4) Direccion de memoria del puntero: %p\n", (void*)&p_variable);

    // 5) El tamaño de memoria utilizado por la variable 
    printf("5) Tamaño de memoria de la variable: %zu bytes\n", sizeof(variable));
    return 0;
}
