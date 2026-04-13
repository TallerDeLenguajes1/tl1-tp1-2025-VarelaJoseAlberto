# Trabajo Práctico N°1

## Ejercicio N°2

**a) Investigación del archivo `.gitignore`**

* **¿Por qué es conveniente incluirlo?** Es conveniente porque permite excluir archivos y carpetas que no se desean subir al repositorio. Esto ayuda a mantener el proyecto limpio y evita versionar archivos innecesarios como ejecutables, archivos temporales o configuraciones locales del editor.

* **¿Cuándo se debe hacer?** Se debe crear idealmente al inicio del proyecto, antes de realizar el primer `git add`, o en cuanto se identifiquen archivos que no deben ser seguidos por Git (como los `.exe` generados al compilar).

* **¿Cómo configuraría el archivo `.gitignore`?** 
    1. Crear un archivo llamado `.gitignore` en la raíz del proyecto.
    2. Agregar reglas por línea (ej: `*.exe` para ignorar todos los ejecutables).
    3. Usar comentarios con `#` para organizar las reglas.

* **Ejemplo:**

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

* **Regla para ignorar `ignorado.txt`:** Basta con agregar una línea en el archivo con el nombre exacto: `ignorado.txt`.

---

## Ejercicio N°3: Debugging y Análisis de Memoria

### 1. Análisis de `codigo_misterio.c`

Tras realizar la depuración paso a paso con el debugger (**F10/F11**), se determinó que el programa procesa un número entero a través de tres transformaciones matemáticas sucesivas, operando directamente sobre la memoria original mediante punteros.

**Cuadro de descripcion de funciones del codigo_misterio y renombrado**

A continuación, se detallan los cambios de nombres propuestos basados en el comportamiento logico deducido:

| Nombre Original | Nuevo Nombre Descriptivo | Justificacion L0gica |

| :--- | :--- | :--- |
| `f_alpha` | `invertir_numero` | Extrae los dígitos con `% 10` y los reconstruye en orden inverso (ej: 452 a 254). |
| `f_beta` | `calcular_mitad` | Realiza una división entera por 2 sobre el valor en la dirección de memoria. |
| `f_gamma` | `sumar_digitos_al_total` | Suma los dígitos del número actual y añade el resultado al valor almacenado. |
| `valor_referencia` | `p_dato` | Indica que es un puntero (p) que referencia a la variable del main. |                         |

### 2. Identificacion de errores del codigo_sin_funcionar y correcciones

El archivo presentaba fallos en tres niveles: compilación, ejecución y lógica de punteros.

**A. Error de sintaxis (compilacion)**
- **Falta de delimitadores:** En la linea de la declaracion de `suma` y en instrucion `return 0`, falta el punto y coma `;`, lo que impedia la generacion del ejecutable.
- **Directiva de cabecera:** Se detecto la falta de la libreria `stdio.h`, necesaria para las funciones estándar de entrada y salida.

**B. Error de ejecucion (segmentation fault)**
- **Fallo en `scanf`:** Se intentaba cargar el `valor1` pasando la variable por valor. Al no recibir una direccion de memoria valida mediante el operador `&`, el programa intentaba escribir en una direccion de memoria invalida.

**C. Error logico (paso por valor)**
- **Funcion `duplicar_numero`:** Originalmente, la funcion recibia una copia del valor. Al duplicar la copia local, el valor original en el main permanecia inalterado.

- **Solucion aplicada:** Se modifico el parametro a un puntero (`int *numero`) y se actualizo la llamada en el main enviando la dirección con el operador `&` (`duplicar_numero(&valor1)`).

---

### 4.g. Analisis de resultados de `tp1_1.c`

Al ejecutar el programa, se obtuvieron las siguientes conclusiones sobre las direcciones de memoria:

1.  **Igualdad de los puntos 1, 2 y 3:** El resultado es el mismo porque un puntero almacena la **dirección de memoria** de otra variable. Por lo tanto, el contenido del puntero, la dirección almacenada en él y la dirección de la variable original apuntan al mismo lugar físico en la RAM.

2.  **Punto 4: Dirección del propio puntero:** Se obtiene una dirección distinta a las anteriores. Esto se debe a que el puntero es una variable independiente que necesita su propio espacio en la memoria para almacenar la dirección a la que apunta. Es un objeto distinto en el *stack*.

3.  **Tamaño de la variable (Punto 5):** El resultado de `sizeof(variable)` fue de **4 bytes**, que es el tamaño estándar reservado para un tipo de dato entero (`int`) en la arquitectura utilizada.