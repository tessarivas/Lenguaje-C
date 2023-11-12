/*
NOMBRE: Teresa Rivas Gomez
MATRICULA: 372565
FECHA: Octubre - 25 - 2023 
MATERIA: Lenguaje C
ACTIVIDAD: Taller 7: Apuntadores y Caracteres
NOMBRE DEL ARCHIVO: Taller7_ApuntadoresYCaracteres_RGT.cpp
INSTRUCCIONES: Durante este taller, vamos a resolver ejercicios relacionados con la unidad 3. Para cada
ejercicio, declaren las variables, constantes y funciones necesarias para llevar a cabo la tarea requerida.
Realicen el código a mano de los siguientes ejercicios*.
*/

// Librerias
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

// Definiciones
#define MAX_NOMBRES 3
#define MAX_LONGITUD 100

// Funciones utilizadas
int nombrecitos();
void imprimirNombres(char *nombres[], int numNombres);
void invertirCadena(char *cadena);
void ordenarPalabras(char *palabras[], int numPalabras);
char *nombres[MAX_NOMBRES] = {
    "Juan",
    "Maria",
    "Pedro"
};

// Menu para el usuario
int msges()
{
    int op;
    printf("\n MENU: Taller 7 \n");
    printf("1. Ingresar tres nombres y almacenarlos.\n");
    printf("2. Invertir una cadena.\n");
    printf("3. Ingresar lista de palabras y ordenarlas alfabeticamente.\n");
    printf("0. Salir del programa\n");
    printf("Selecciona una opcion (o|1|2|3): ");
    scanf("%d", &op);
    return op;
}

// Programa principal
int main() 
{
    int i, j;
    int op;
    int inicio = 0;
    int numPalabras = 0;
    char entrada[MAX_LONGITUD];
    char *palabras[MAX_NOMBRES];

    do {
        system("CLS");
        op = msges();
        switch(op) 
        {
            case 1:
                nombrecitos();
                system("PAUSE");
                break;

            case 2:
                /* Escribe una función llamada "invertirCadena" que tome un apuntador a "char" como argumento y 
                revierta la cadena original sin crear una nueva cadena.Luego, utiliza esta función para invertir 
                una cadena y mostrar el resultado. */
                printf("Ingresa una cadena para invertir: ");
                scanf("%s", entrada);
                invertirCadena(entrada);
                printf("Cadena invertida: %s\n", entrada);
                system("PAUSE");
                break;

            case 3:
                /* Crea un programa que permita al usuario ingresar una lista de palabras (cadenas de caracteres) 
                y luego ordene esas palabras alfabéticamente utilizando apuntadores a caracteres y arreglos de 
                apuntadores. */
                printf("Ingresa una lista de palabras separadas por espacios:\n");
                getchar();
                fgets(entrada, MAX_LONGITUD, stdin);

                numPalabras = 0;
                i = 0;

                for (j = 0; entrada[j]; j++) 
                {
                    if (entrada[j] == ' ' || entrada[j] == '\n') 
                    {
                        entrada[j] = '\0';  
                        palabras[numPalabras] = entrada + inicio; 
                        numPalabras++;
                        inicio = j + 1;
                    }
                }

                ordenarPalabras(palabras, numPalabras);

                printf("Palabras ordenadas:\n");
                for (i = 0; i < numPalabras; i++) 
                {
                    printf("%s\n", palabras[i]);
                }
                system("PAUSE");
                break;
        }
    } while (op != 0);

    return 0;
}

/* Declarar un arreglo de apuntadores a caracteres llamado nombres que
contenga tres nombres (cadenas de texto). Luego, escribe un bucle que recorra
este arreglo y, en cada iteración, imprima el nombre correspondiente. */
int nombrecitos() 
{
    int i;
    int op;
    char nombres_estaticos[MAX_NOMBRES][MAX_LONGITUD];

    printf("1. Utilizar nombres predefinidos.\n");
    printf("2. Ingresar nuevos nombres.\n");
    printf("Seleccione una opcion: ");
    scanf("%d", &op);

    if (op == 1) 
    {
        imprimirNombres(nombres, MAX_NOMBRES);
    } 
    else if (op == 2) 
    {
        /* Ingresar tres nombres y almacene estos nombres en el arreglo de apuntadores a 
        caracteres nombres. Luego, usa un bucle para imprimir los nombres almacenados. */
        printf("Ingresa tres nombres:\n");
        for (i = 0; i < MAX_NOMBRES; i++) 
        {
            scanf("%s", nombres_estaticos[i]);
            nombres[i] = nombres_estaticos[i];
        }
        imprimirNombres(nombres, MAX_NOMBRES);
    } 
    else 
    {
        printf("ERROR.\n");
    }

    return 0;
}


/* Función que sirva para ambos ejercicios donde escribas una función llamada imprimirNombres 
que tome un arreglo de apuntadores a caracteres como argumento y lo recorra para imprimir cada
nombre en una línea separada. */
void imprimirNombres(char *nombres[], int numNombres) 
{
    printf("Nombres ingresados:\n");
    int i;
    for (i = 0; i < numNombres; i++) 
    {
        printf("%s\n", nombres[i]);
    }
}

// En esa funcion invertimos la cadena para que empiece de final a inicio.
void invertirCadena(char *cadena) 
{
    int i, j;
    int longitud = strlen(cadena);
    for (i = 0, j = longitud - 1; i < j; i++, j--) 
    {
        char temp = cadena[i];
        cadena[i] = cadena[j];
        cadena[j] = temp;
    }
}

// Aqui ordenamos las palabras de manera alfabetica.
void ordenarPalabras(char *palabras[], int numPalabras) 
{
    int i, j;
    char *temp;

    for (i = 0; i < numPalabras - 1; i++) 
    {
        for (j = i + 1; j < numPalabras; j++) 
        {
            if (strcmp(palabras[i], palabras[j]) > 0) 
            {
                temp = palabras[i];
                palabras[i] = palabras[j];
                palabras[j] = temp;
            }
        }
    }
}