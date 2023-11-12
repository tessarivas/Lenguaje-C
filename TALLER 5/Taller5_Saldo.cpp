// Teresa Rvas Gómez / Matricula: 372565
// Fecha de creación: Sep - 30 - 2023
// Materia: Lenguaje C / Actividad: Taller 5 "Clases de Almacenamiento"

// EJERCICIO 2:
// Declara una variable externa llamada saldo en un archivo fuente (archivo.c) y
// accede a ella desde otro archivo fuente (otroarchivo.c). Modifica su valor en
// ambos archivos y muestra el valor final. ¿Cómo afecta la visibilidad y el tiempo
// de vida de la variable externa?

// Librerias
#include <stdio.h>
#include <stdlib.h>

// Variable
int saldo = 1000;

// Funcion
void externa(int cantidad)
{
    saldo += cantidad;
    printf ("Saldo: %d\n ", saldo);
    system ("PAUSE");
}