// Teresa Rivas Gomez / Matricula: 372565
// Oct - 04 - 2023
// Primer Examen

/*

Escribe un programa en C que encuentre y muestre todos los números perfectos en un rango dado por el usuario. 
Un número perfecto es un número entero positivo que es igual a la suma de sus divisores propios positivos (excluyendo a sí mismo).

Requisitos del programa:
+ Solicita al usuario que ingrese un número entero positivo "n" que representa el rango.
+ El programa buscará números perfectos en el rango de 1 a "n".  
+ Valida que "n" sea un número entero positivo.
+ Si encuentras un número perfecto, muestra ese número y sus divisores propios positivos.  
+ Después de encontrar todos los números perfectos en el rango, pregunta al usuario si desea buscar números perfectos en otro rango. 
  Si la respuesta es afirmativa, el programa debe repetirse; de lo contrario, debe finalizar.

*/

// Librerias
#include <stdio.h>
#include <stdlib.h>

// Funciones
int suma(int n);

// Menu principal
int main()
{
  // Declarar Variables
  int n, opcion;
  do
  {
    // Etiqueta para marcar desde donde empezaria de nuevo
    otra_vez:
    // Entrada
    printf("Ingrese un numero entero positvo para delimitar su rango: \n");
    scanf("%d", &n);
    // Condicion para que sea positivo
    if (n > 0)
    {
      // Manda llamar a la funcion con el procedimiento
      suma(n);
    }
    else
    {
        // Volver a pedir el numero
        printf("El numero tiene que ser mayor a 0.\n");
        // Etiqueta
        goto otra_vez;
    }
    // Preguntar de nuevo
    printf("Intentar de nuevo: \n");
    printf("1. Si\n");
    printf("0. No\n");
    scanf("%d", &opcion);
    // Hacer este proceso hasta que el usuario indique que ya no lo quiere intentar (0)
  } while (opcion != 0);
  // Salida
  getchar();
  // Retorno a 0
  return 0;
}
// Funcion para las operaciones
int suma(int n)
{
    // Declarar variables
    int i, suma;
    // Ciclo 
    // Inicializar en 0
    suma = 0;
    for (i = 1; i < n; i++)
    {
      // Condicion para revisar si es divisible
      if (n % i == 0)
      {
        // Si se cumple:
        suma += i;
      }
    }
    // Condicion para cuando es perfecto
    if (suma == n)
    {
      // Segundo ciclo
      for (i = 1; i < n; i++)
      {
        // Condicion
        if (n % i == 0)
        {
          //Mensaje al usuario de que se cumplio
          printf("Es perfecto!\n");
          printf("Divisores positivos: %d\n", i);
        }
      }
    }
    // Si no se cumple, muestra mensaje al usuario
    else
    {
        printf("No es perfecto n_n \n");
    }
    // Retornar a la suma
    return suma;
}