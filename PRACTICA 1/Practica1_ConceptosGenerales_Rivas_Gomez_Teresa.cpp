#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>

// FUNCIONES

void calculadora();
void juegoAdivinarNumero();
void calculadoraAreas();

//MENU PARA ELEGIR PROGRAMA

int main() {
	
    int opcion;
    
    do {
        printf("Elija una opcion:\n");
        printf("1. Calculadora\n");
        printf("2. Juego de adivinar el numero\n");
        printf("3. Calculadora de areas\n");
        printf("4. Salir\n");
        
        scanf("%d", &opcion);
        
        switch (opcion) {
            case 1:
                calculadora();
                break;
            case 2:
                juegoAdivinarNumero();
                break;
            case 3:
                calculadoraAreas();
                break;
            case 4:
                printf("Has salido del menu\n");
                break;
            default:
                printf("Opcion invalida. Elija nuevamente.\n");
        }
    } while (opcion != 4);
    
    return 0;
}

float suma(float a, float b) {
    return a + b;
}

float resta(float a, float b) {
    return a - b;
}

float multiplicacion(float a, float b) {
    return a * b;
}

float division(float a, float b) {
    if (b != 0) {
        return a / b;
    } else {
        printf("Error: No se puede dividir por cero.\n");
        return 0;
    }
}

void calculadora() {
  float num1, num2;
    int opcion;

//Menu de la calculadora y operadores    
    printf("Calculadora\n");
    printf("1. Suma\n");
    printf("2. Resta\n");
    printf("3. Multiplicación\n");
    printf("4. División\n");
    printf("Seleccione una opcion (1/2/3/4): ");
    scanf("%d", &opcion);

//Entrada de datos
    printf("Ingrese el primer numero: ");
    scanf("%f", &num1);

    printf("Ingrese el segundo numero: ");
    scanf("%f", &num2);

//Casos y Salida
    switch (opcion) {
        case 1:
            printf("Resultado: %.2f\n", suma(num1, num2));
            break;
        case 2:
            printf("Resultado: %.2f\n", resta(num1, num2));
            break;
        case 3:
            printf("Resultado: %.2f\n", multiplicacion(num1, num2));
            break;
        case 4:
            printf("Resultado: %.2f\n", division(num1, num2));
            break;
        default:
            printf("Opción no válida.\n");
            break;
    }

}
void juegoAdivinarNumero() {
    srand(time(0));
    int numeroAleatorio = rand() % 100 + 1;
    int intento, intentosRealizados = 0;
    
    printf("Adivina un numero del 1 al 100\n");
    //Entrada
    do {
        printf("Ingrese un numero: ");
        scanf("%d", &intento);
        
        if (intento > numeroAleatorio) {
            printf("Demasiado alto\n");
        } else if (intento < numeroAleatorio) {
            printf("Demasiado bajo\n");
        }
        
        intentosRealizados++;
    } while (intento != numeroAleatorio);
    //Salida
    printf("¡Felicidades amigo! Adivinaste el numero %d en %d intentos.\n", numeroAleatorio, intentosRealizados);
  
}

void calculadoraAreas() {
    int opcion, resultado;
//Menu de la calculadora de areas    
        printf("Elija una opcion:\n");
        printf("1. Calcular area de triangulo\n");
        printf("2. Calcular area de circulo\n");
        printf("3. Calcular area de rectangulo\n");
        printf("4. Calcular area de cubo\n");
        printf("5. Calcular area de cilindro\n");
        printf("6. Salir\n");

        scanf("%d", &opcion);

        switch (opcion) {
            case 1: {
                float base, altura;
                printf("Ingrese la base del triangulo: ");
                scanf("%f", &base);
                printf("Ingrese la altura del triangulo: ");
                scanf("%f", &altura);
                float area = 0.5 * base * altura;
                printf("El area del triangulo es: %.2f\n", area);
                break;
            }
            case 2: {
                float radio;
                printf("Ingrese el radio del circulo: ");
                scanf("%f", &radio);
                float area = M_PI * radio * radio;
                printf("El area del circulo es: %.2f\n", area);
                break;
            }
            case 3: {
                float base, altura;
                printf("Ingrese la base del rectangulo: ");
                scanf("%f", &base);
                printf("Ingrese la altura del rectangulo: ");
                scanf("%f", &altura);
                float area = base * altura;
                printf("El area del rectangulo es: %.2f\n", area);
                break;
            }
            case 4: {
                float lado;
                printf("Ingrese el lado del cubo: ");
                scanf("%f", &lado);
                float area = 6 * lado * lado;
                printf("El area del cubo es: %.2f\n", area);
                break;
            }
            case 5: {
                float radio_base, altura;
                printf("Ingrese el radio de la base del cilindro: ");
                scanf("%f", &radio_base);
                printf("Ingrese la altura del cilindro: ");
                scanf("%f", &altura);
                float area_base = M_PI * radio_base * radio_base;
                float area_lateral = 2 * M_PI * radio_base * altura;
                float area = 2 * area_base + area_lateral;
                printf("El area del cilindro es: %.2f\n", area);
                break;
            }
            case 6: {
                printf("Saliendo de la calculadora.\n");
                break;
            }
            default:
                printf("Opcion no valida. Por favor, seleccione una opcion valida.\n");
                break;
        }
}