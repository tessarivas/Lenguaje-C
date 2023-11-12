#include <stdio.h>
#include <stdlib.h>

int msges();
void menu();
void e1 (void);
void e2 (void);
void e3 (void);
void e4 (void);
void e5 (void);
void e6 (void);
void e7 (void);
void e8 (void);

int main ()
{
    menu ();

    return 0;
}
int msges()
{
    int op;
    printf("\n MENU \n");
    printf("1.- EJERCICIO 1 \n");
    printf("2.- EJERCICIO 2 \n");
    printf("3.- EJERCICIO 3 \n");
    printf("4.- EJERCICIO 4 \n");
    printf("5.- EJERCICIO 5 \n");
    printf("6.- EJERCICIO 6 \n");
    printf("7.- EJERCICIO 7 \n");
    printf("8.- EJERCICIO 8 \n");
    printf("0.- SALIR  \n");
    printf("ESCOGE UNA OPCION: ");
    scanf("%d", &op);
    return op;
}
void menu()
{
    int op;
    do
    {
        op = msges();
        switch (op)
        {
        case 1:
            e1();
            break;
        case 2:
            e2();
            break;
        case 3:
            e3();
            break;
        case 4:
            e4();
            break;
        case 5:
            e5();
            break;
        case 6:
            e6();
            break;
        case 7:
            e7();
            break;
        case 8:
            e8();
            break;
        }

    } while (op != 0);
}
//Determinar si un número es positivo, negativo o cero*.
void e1 (void)
{
    system ("CLS");
    int n;

    printf("Ingrese un numero: \n");
    scanf("%d", &n);

    if (n > 0)
    {
        printf("El numero es positivo");
    }
    else
    {
        if (n < 0)
        {
            printf("El numero es negativo\n");
        }
        else
        {
            printf("El numero es igual a cero\n");
        }
    }
    system ("PAUSE");
}
// El ejercicio debe permitir ingresar grados Celsius y debe convertirlos a grados Fahrenheit *.
void e2 (void)
{
    system ("CLS");
    int grados_c;

    printf("Programa para convertir grados CELSIUS a FAHRENHEIT\n");
    printf("Ingrese el numero de grados que desea convertir: \n");
    scanf("%d", &grados_c);

    float grados_f = grados_c * 1.8 + 32;

    printf("Los grados convertidos a Farhenheit son: %.0f\n", grados_f);
    system ("PAUSE");
}
// Determinar si un número es par y positivo al mismo tiempo*.
void e3 (void)
{
    system ("CLS");
    int n;

    printf("Determinar si un numero es POSITIVO y es PAR\n");
    printf("Ingrese un numero: \n");
    scanf("%d", &n);

    if (n > 0 && n % 2 == 0)
    {
        printf("El numero es positivo y es par\n");
    }
    else
    {
        printf("El numero no cumple con 1 o 2 de las condiciones.\n");
    }
    system ("PAUSE");
}
// Cuanto daría la siguiente expresión aritmética resultado = (a * b + c) / (b - a), si
// a=5 , b =3 y c=7. (Realiza el procedimiento realizado)
void e4 (void)
{
    system ("CLS");
    int a = 5, b = 3, c = 7;
    float resultado;

    printf("Cuanto daría la siguiente expresiun aritmetica (a * b + c) / (b - a), si a = 5 , b =  y c = 7");
    resultado = (a * b + c) / (b - a);

    printf("El resultado del ejercicio es: %.2f\n", resultado);
    system ("PAUSE");
}
// El ejercicio debe permitir ingresar un año y determine si ese año es bisiesto o no*.
void e5 (void)
{
    system ("CLS");
    int a;

    printf("Ingrese un año: ");
    scanf("%d", &a);

    if ( (a % 4 == 0 && a % 100 != 0) || (a % 400 == 0) ) 
    {
        printf( "ES BISIESTO\n" );
    }
    else
    {
        printf( "NO ES BISIESTO\n" );
    }
    system ("PAUSE");
}
// Convierte los números decimales a binarios y calcula cual seria el resultado de los siguientes ejercicios:
// num = 37;
// complemento = ~num;
void e6 (void)
{
    system ("CLS");
    int num = 37;
    int complemento = ~num;
    printf("Complemento de %d en binario: %d\n", num, complemento);
    system ("PAUSE");
}
// Convierte los números decimales a binarios y calcula cual seria el resultado de los siguientes ejercicios:
// num = 5;
// desplazado = num << 2;
void e7 (void)
{
    system ("CLS");
    int num = 5;
    int desplazado = num << 2;
    printf("Desplazamiento de %d a la izquierda 2 bits: %d\n", num, desplazado);
    system ("PAUSE");

}
// Convierte los números decimales a binarios y calcula cual seria el resultado de los siguientes ejercicios:
// Una tienda ofrece descuentos basados en el monto de compra y la membresía del cliente. 
// Si el monto de compra es mayor o igual a 1000 y el cliente tiene una membresía premium, 
// se aplica un descuento del 15%. Si el cliente no tiene membresía premium pero el monto de 
// compra es mayor o igual a 1000, se aplica un descuento del 10%. Si el monto de compra es 
// menor a 1000, no se aplica ningún descuento*. (Usar operadores ternarios)
void e8 (void)
{
    system ("CLS");
    float montoCompra = 1200.0;
    int tieneMembresia = 1; // 1 para "tiene membresía premium", 0 para "no tiene membresía premium"
    float descuento = (montoCompra >= 1000) ? ((tieneMembresia == 1) ? 0.15 : 0.10) : 0.0;
    float montoFinal = montoCompra - (montoCompra * descuento);
    printf("Monto de compra: %.2f\n", montoCompra);
    printf("Descuento aplicado: %.0f%%\n", descuento * 100);
    printf("Monto final: %.2f\n", montoFinal);
    system ("PAUSE");
}