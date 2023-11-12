// Taller 4. Funciones con retorno y sin retorno
// Teresa Rivas Gomez 372565
// Sep - 16 - 2023

/*

1. Calcular el factorial de un número entero utilizando una función sin retorno.
- calcularFactorial: Esta función debe tomar un número entero como entrada y calcular su factorial. El resultado debe mostrarse en 
pantalla. No debe devolver ningún valor, solo mostrar el resultado.
- En la función main, solicita al usuario que ingrese un número entero no negativo para calcular su factorial.
- Utiliza la función calcularFactorial para calcular el factorial del número ingresado y mostrar el resultado.
- Pregunta al usuario si desea calcular el factorial de otro número. Si es así, permite al usuario ingresar otro número y calcular 
su factorial. Si no, muestra un mensaje de despedida y termina el programa.

2. Calcular el factorial de un número entero utilizando una función recursiva. La
función de calcularFactorial, esta función debe tomar un número entero como
entrada y calcular su factorial de manera recursiva. Debe devolver el resultado del
cálculo del factorial.

*/

#include <stdio.h>

int FactorialRecursivo(int numero);
void FactorialSinRetorno(int numero);

int main() 
{
    int numero;
    char respuesta;

    do {
        printf("\nIngresa un numero para calcular su factorial: ");
        scanf("%d", &numero);

        if (numero < 0) 
        {
            printf("Por favor, ingresa un numero no negativo.\n");
        } else 
        {
            printf("Opcion 1: Calcular factorial con recursion\n");
            printf("Opcion 2: Calcular factorial sin retorno\n");
            int opcion;
            scanf("%d", &opcion);

            switch (opcion) 
            {
                case 1:
                    FactorialSinRetorno(numero);
                    break;
                case 2:
                    {
                        int resultado = FactorialRecursivo(numero);
                        printf("El factorial de %d es: %d\n", numero, resultado);
                    }
                    break;
                default:
                    printf("Opcion no valida.\n");
                    break;
            }
        }

        printf("Deseas calcular el factorial de otro numero? (S/N): ");
        scanf(" %c", &respuesta);
    } while (respuesta == 'S' || respuesta == 's');

    printf("Hasta luego!\n");

    return 0;
}

void FactorialSinRetorno(int numero) 
{
    int factorial = 1;

    for (int i = 1; i <= numero; i++) 
    {
        factorial *= i;
    }
    printf("El factorial de %d es: %d\n", numero, factorial);
}

int FactorialRecursivo(int numero) 
{
    if (numero == 0) 
    {
        return 1;
    } 
    else 
    {
        return numero * FactorialRecursivo(numero - 1);
    }
}