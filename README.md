# Trabajo Práctico N°1

## Ejercicio N°2

**a)** Investigar el archivo `.gitignore`  
- ¿Por qué es conveniente incluirlo?  
- ¿Cuándo se debe hacer?  
- ¿Cómo configuraría el archivo `.gitignore`?  
- Incluya en su repositorio una regla de cómo ignorar un archivo `ignorado.txt`  

---

### ¿Por qué es conveniente incluirlo?

Es conveniente incluir el archivo `.gitignore` porque permite excluir archivos y carpetas que no se desean subir al repositorio. Esto ayuda a mantener el repositorio limpio, organizado y evita subir archivos innecesarios como archivos temporales, compilados o configuraciones locales.

---

### ¿Cuándo se debe hacer?

Se debe crear al inicio del proyecto o en cualquier momento en que se identifique que hay archivos que no deberían ser versionados, como por ejemplo:

- Archivos compilados (ej: `.exe`, `.o`)
- Archivos temporales  
- Configuraciones locales del entorno  
- Archivos generados durante la ejecución  

---

### ¿Cómo configuraría el archivo `.gitignore`?

Para configurarlo:

1. Crear un archivo de texto con el nombre `.gitignore`  
2. Editarlo agregando las reglas necesarias según el tipo de proyecto  
3. Organizar el archivo utilizando comentarios para separar las distintas categorías de archivos  

**Ejemplo:**

```gitignore
# Archivos compilados
*.exe
*.o

# Archivos temporales
*.tmp

# Configuración de VS Code
.vscode/
```
> [!NOTE] 
> El archivo .gitignore no elimina archivos que ya están siendo seguidos por Git, por lo que debe configurarse antes de hacer git add o eliminar manualmente los archivos del seguimiento.

---

## Ejercicio N°3: Debugging y Análisis de Memoria

1. **Analisis del codigo_misterio y modificacion**

Tras realizar la depuracion paso a paso con el debugger (F10/F11), el programa procesa un número entero a través de tres transformaciones matemáticas sucesivas, operando directamente sobre la memoria original mediante punteros.

**Cuadro de descripcion de funciones del codigo_misterio y renombrado**

A continuación, se detallan los cambios de nombres propuestos basados en el comportamiento logico deducido:

|  Nombre Orginal  | Nuevo nombre descriptivo |                                                  Justificacion Logica                                                  |
|:----------------:|:------------------------:|:----------------------------------------------------------------------------------------------------------------------:|
| f_alpha          | invertir_numero          | Utiliza un bucle para extraer digitos con % 10 y reconstruir el numero en orden inverso (ej: 452 se convierte en 254). |
| f_beta           | calcular_mitad           | Realiza una division entera por 2 sobre el valor actual almacenado en la direccion de memoria.                         |
| f_gamma          | sumar_digitos_al_total   | Calcula la suma de los digitos del numero actual y el resultado se lo suma al valor original.                          |
| valor_referencia | p_dato                   | Se renombra para indicar que es un puntero (p) que referencia a la variable numérica procesada.                           |

2. **Identificacion de errores del codigo_sin_funcionar y correcciones**

El archivo presentaba fallos en tres niveles: compilación, ejecución y lógica de punteros.

**A. Error de sintaxis (compilacion)**
- **Falta de delimitadores:** En la linea de la declaracion de `suma` y en instrucion `return 0`, falta el punto y coma `;`, lo que impedia la generacion del ejecutable.
- **Directiva de cabecera:** Se detecto la falta de la libreria `stdio.h`, necesaria para las funciones estándar de entrada y salida.

**B. Error de ejecucion (segmentation fault)**
- **Fallo en `scanf`:** Se intentaba cargar el `valor1` pasando la variable por valor. Al no recibir una direccion de memoria valida mediante el operador `&`, el programa intentaba escribir en una direccion de memoria invalida.

**C. Error logico (paso por valor)**
- **Funcion `duplicar_numero`:** Originalmente, la funcion recibia una copia del valor. Al duplicar la copia local, el valor original en el main permanecia inalterado.

- **Solucion aplicada:** Se modifico el parametro a un puntero (`int *numero`) y se actualizo la llamada en el main enviando la dirección con el operador `&` (`duplicar_numero(&valor1)`).