// Teresa Rvas Gomez / Matricula: 372565
// Fecha de creacion: Sep - 30 - 2023
// Materia: Lenguaje C / Actividad: Practica 5 "Clases de Almacenamiento"

// Librerias
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

// Menu
int msges();
void menu();

// Ejercicio
int numero_random();
int copa_piston();

// Menu principal
int main()
{
    menu();
    return 0;
}

// Mensaje al usuario para seleccionar ejercicio en el menu
int msges()
{
    int op;
    system ("CLS");
    // Mensajes
    printf("\n Practica 5 \n");
    printf(" MENU: Elige el tipo de variable. \n");
    printf("1. Loteria. \n");
    printf("2. Copa Piston. \n");
    printf("0. Salir del programa. \n");
    scanf("%d", &op);
    return op;
}

// Seleccion de ejercicios segun sea el caso
void menu()
{
    // Variable para el menu
    int op;
    // Variables para el ejercicio 1
    int numero;
    static int ganador;
    do {
        op = msges();
        switch (op)
        {
            case 1:
                // Asignar valores
                ganador = numero_random();
                // Entrda de datos
                printf ("\n La Loteria! \n");
                printf ("Ingresa un numero del 1 al 100: \n");
                scanf ("%d", &numero );
                // Condicion para comprobar que sea valido
                if ( numero < 0 && numero > 100)
                {
                    printf ("Numero invalido, recuerda solo elegir un numero del 1 al 100.\n");
                    system ("PAUSE");
                }
                else 
                {
                    // Comprobar si es el mismo numero del ganador
                    if ( numero == ganador )
                    {
                        // Mensaje si el numero si fue el ganador
                        printf ("Has ganado!\n");
                        system ("PAUSE");
                    }
                    else
                    {
                        // Mensaje si el numero no fue el ganador
                        printf ("Intentalo de nuevo.\n");
                        printf ("El numero ganador era: %d\n", ganador );
                        system ("PAUSE");
                    }
                }
                break;
            case 2:
                copa_piston();
                break;
            case 0:
                printf("Saliste del programa.\n");
                break;
            default:
                printf("Opcion invalida, intentalo de nuevo y lee bien porfa.\n");
                break;
        }
    } while(op != 0);
}

// Funcion para generar el numero random
int numero_random()
{
    srand(time(NULL));
    return rand() %100 + 1;
}

// Ejercicio 2:
// La Carrera de Coches: Variables de registro (register) en C para simular una carrera de coches.
int copa_piston()
{
    // Declarar variables
    int distancia = 1000;
    //Generar numero
    srand(time(NULL));
    // Registros para la velocidad de cada carro:
    register int RayoMcQueen = rand() %101 + 100;
    register int Francesco = rand() %101 + 100;
    register int JacksonStorm = rand() %101 + 100;
    //PARA MEDIR EL TIEMPO QUE HIZO CADA UNO, CONVERTI LA DISTANCIA A FLOAT Y LO DIVIDE POR LA VELOCIDAD DEL COCHE.
    float timec1 = (float)distancia / RayoMcQueen;
    float timec2 = (float)distancia / Francesco;
    float timec3 = (float)distancia / JacksonStorm;
    // Imprimir resultados
    printf("Resultados de la Copa Pistón: \n");
    printf("Rayo McQueen - VELOCIDAD: %d KM/H - TIEMPO: %.2f SEGUNDOS\n", RayoMcQueen, timec1);
    printf("Francesco - VELOCIDAD: %d KM/H - TIEMPO: %.2f SEGUNDOS\n", Francesco, timec2);
    printf("Jackson Storm - VELOCIDAD: %d KM/H - TIEMPO: %.2f SEGUNDOS\n", JacksonStorm, timec3);
    // Variables para determinar el ganador
    float timeg = timec1;
    // Usar un puntero constante para el nombre del ganador
    const char *ganador = "Rayo McQueen"; 
    if (timec2 < timeg) {
        timeg = timec2;
        ganador = "Francesco";
    }
    if (timec3 < timeg) {
        timeg = timec3;
        ganador = "Jackson Storm";
    }
    // Imprimir el carro ganador
    printf("\n");
    printf("El carro ganador con el menor tiempo: %.2f SEGUNDOS es de %s\n", timeg, ganador);
    system ("PAUSE");
    return 0;
}