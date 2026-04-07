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
[!NOTE] 
El archivo .gitignore no elimina archivos que ya están siendo seguidos por Git, por lo que debe configurarse antes de hacer git add o eliminar manualmente los archivos del seguimiento.