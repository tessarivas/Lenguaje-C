/*
NOMBRE DEL ARCHIVO: Practica8_Estructuras_RGT.cpp
AUTOR: Teresa Rivas Gomez
FECHA DE CREACION: Nov - 21 - 2023
DESCRIPCION: El objetivo de esta práctica es simular un sistema de gestión de inventario en C
utilizando estructuras (structs) donde los usuarios pueden agregar y retirar elementos
del inventario. También incorporaremos una instrucción de la Práctica 2 para mejorar
la funcionalidad del sistema de gestión de inventario.
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define REGISTROS 500

/* ESTRUCTURA PRINCIPAL DEL INVENTARIO */
typedef struct _producto {
    int status;
    int codigo;
    char nombre[30];
    int cantidad;
    double precio;
} Tproducto;

/* DECLARACION DE FUNCIONES */
int mensajes();
void menu();

Tproducto agregar_manual(void);
int mostrar_inventario(Tproducto inventario[], int i);
void retirar_producto(Tproducto inventario[], int i);
void calcular_total(Tproducto inventario[], int i);

int ValidarCadena(char mensj[], int ri, int rf);
int ValidarCadenaTexto(const char cadena[]);
int ValidacionPrecio(char mensj[], double *precio);
int Mayusculas(char cadena[]);

/* MENU PRINCIPAL */
int main()
{
    menu();
    return 0;
}

/* MENSAJES AL USUARIO */
int mensajes()
{
    int opcion;
    system("CLS");
    printf("-------------------------\n");
    printf("        INVENTARIO       \n");
    printf("-------------------------\n");
    printf("1.- AGREGAR ELEMENTO\n");
    printf("2.- RETIRAR ELEMENTO\n");
    printf("3.- MOSTRAR INVENTARIO\n");
    printf("4.- CALCULAR VALOR TOTAL\n");
    printf("-------------------------\n");
    printf("0.- SALIR\n");
    printf("-------------------------\n");
    opcion = ValidarCadena("SELECCIONA UNA OPCION ENTRE 0|1|2|3|4: ", 0, 4);
    return opcion;
}

void menu()
{
    int i = 0;
    int opcion;
    Tproducto inventario[REGISTROS];
    do {
        opcion = mensajes();
        system("CLS");
        switch(opcion)
        {
            case 1:
                printf("AGREGAR ELEMENTO\n");
                if(i < REGISTROS)
                {
                    inventario[i] = agregar_manual();
                    i++;
                    printf("PRODUCTO AGREGADO CORRECTAMENTE.\n");
                }
                else
                {
                    printf("NO SE AGREGAR OTRO PRODUCTO, INVENTARIO LLENO.\n");
                }
                system("PAUSE");
                break;
            case 2:
                printf("RETIRAR ELEMENTO\n");
                retirar_producto(inventario, i);
                system("PAUSE");
                break;
            case 3:
                printf("MOSTRAR INVENTARIO\n");
                mostrar_inventario(inventario, i);
                system("PAUSE");
                break;
            case 4:
                printf("CALCULAR VALOR TOTAL\n");
                calcular_total(inventario, i);
                system("PAUSE");
                break;
            case 0:
                printf("SALISTE DEL PROGRAMA\n");
                break;
        }
    } while(opcion != 0);
} 

/* AGREGAR PRODUCTO MANUAL: Solicita manualmente al usuario la información de un producto, 
como código, nombre, cantidad y precio, validando cada entrada y devolviendo un objeto Tproducto 
con los datos ingresados */
Tproducto agregar_manual(void)
{
    Tproducto producto;

    // VARIABLES
    int op;
    char nombre_producto[30];
    double precio_producto;

    // STATUS
    producto.status = 1;

    // TITULO
    printf("INGRESE LOS SIGUIENTES DATOS:\n");
    printf("-----------------------------\n");

    // CODIGO
    producto.codigo = ValidarCadena("0.- CODIGO DEL PRODUCTO:\n", 1, 501);

    // NOMBRE
    do {
        printf("1.- NOMBRE DEL PRODUCTO:\n");
        fflush(stdin);
        gets(nombre_producto);
        Mayusculas(nombre_producto);
        op = ValidarCadenaTexto(nombre_producto);
        if(op != 1)
        {
            printf("NOMBRE NO VALIDO.\n");
        }
    } while(op != 1);
    strcpy(producto.nombre, nombre_producto);

    // CANTIDAD
    producto.cantidad = ValidarCadena("2.- CANTIDAD DEL PRODUCTO:\n", 1, 10000);

    // PRECIO
    while (!ValidacionPrecio("3.- PRECIO DEL PRODUCTO:\n", &precio_producto));
    producto.precio = precio_producto;

    // IMPRIMIR
    printf("-----------------------------\n");
    printf("PRODUCTO PREVIAMENTE AGREGADO:\n");
    printf("-----------------------------\n");
    printf("CODIGO: %d\n", producto.codigo);
    printf("NOMBRE: %s\n", producto.nombre);
    printf("CANTIDAD: %d\n", producto.cantidad);
    printf("PRECIO: $%.2f\n", producto.precio);

    return producto;
}

/* RETIRAR PRODUCTO: Elimina una cantidad especificada de un producto del inventario, solicitando
 al usuario el código del producto y la cantidad a eliminar. Si el producto se encuentra, ajusta 
 la cantidad en el inventario y, si es necesario, marca el producto como eliminado. */
void retirar_producto(Tproducto inventario[], int i)
{
    int j;
    int cod;
    int cant;
    int encontrado = 0;
    printf("RETIRAR PRODUCTO DEL INVENTARIO:\n");
    printf("--------------------------------\n");
    cod = ValidarCadena("CODIGO DEL PRODUCTO: \n", 1, 501);
    
    for(j = 0; j < i; j++)
    {
        if(inventario[j].codigo == cod)
        {
            cant = ValidarCadena("INGRESA LA CANTIDAD DE PRODUCTO A ELIMINAR: \n", 1, inventario[j].cantidad);
            inventario[j].cantidad = inventario[j].cantidad - cant;
            if(inventario[j].cantidad == 0)
            {
                inventario[j].status = 0;
            }
            printf("SE ELIMINARON %d DEL INVENTARIO.\n", cant);
            encontrado = 1;
            break;
        }
    }
    if (encontrado == 0)
    {
        printf("NO SE ENCONTRO EL PRODUCTO.\n");
    }
}

/* MOSTRAR INVENTARIO: Imprime en formato tabular la información de los productos activos en el 
inventario, incluyendo número, código, nombre, cantidad y precio. Utiliza un bucle para recorrer el 
inventario, verifica el estado activo del producto y muestra la información correspondiente de manera 
organizada. */
int mostrar_inventario(Tproducto inventario[], int i)
{
    int j, k;

    printf("                PRODUCTOS EN INVENTARIO               \n");
    printf("+------+------+----------------+----------+----------+\n");
    printf("| NUM. | COD. |     NOMBRE     | CANTIDAD |  PRECIO  |\n");
    printf("+------+------+----------------+----------+----------+\n");

    for(j = 0, k = 0; j < i; j++)
    {
        if(inventario[j].status == 1)
        {
            printf("| %-4d | %-4d | %-14s | %-8d | $%-7.2f |",
            j + 1,
            inventario[j].codigo,
            inventario[j].nombre,
            inventario[j].cantidad,
            inventario[j].precio
            );
            printf("\n");
            k++;
        }
    }
    return 0;
}

/* CALCULAR VALOR TOTAL: Calcula y muestra el valor total del inventario sumando el producto de la 
cantidad y el precio de cada elemento activo en el arreglo de productos. Utiliza un bucle para recorrer 
el inventario y acumula el valor total en la variable total, que luego se imprime en formato monetario.*/
void calcular_total(Tproducto inventario[], int i)
{
    Tproducto producto;

    int j;
    double total = 0;

    for (j = 0; j < i; j++)
    {
        producto = inventario[j];
        total = total + (producto.cantidad * producto.precio);
    }
    printf("TOTAL EN EL INVENTARIO: $%.2f\n", total);
}

/* VALIDACION */
int ValidarCadena(char mensj[], int ri, int rf) 
{
    int num;
    char cadena[200]; 

    do
    {
        printf("%s", mensj);
        fflush(stdin); 
        gets(cadena);
        num = atoi(cadena);
    } while (num < ri || num > rf);

    return num;
}

int ValidarCadenaTexto(const char cadena[]) 
{
    int longitud = strlen(cadena);
    // CADENA VACIA
    if (longitud == 0) 
    {
        return 0;
    }
    // ESPACIO AL INICIO O FIN
    if (cadena[0] == ' ' || cadena[longitud - 1] == ' ') 
    {
        return 0; 
    }
    // SOLO MAYUSCULAS Y ESPACIOS
    for (int i = 0; cadena[i] != '\0'; i++) 
    {
        if (cadena[i] == ' ') 
        {
            // DOBLES ESPACIOS
            if(cadena[i + 1] == ' ')
            {
                return 0;
            }
        }
        else
        {
            // CARACTERES NO VALIDOS
            if(cadena[i] < 'A' || cadena[i] > 'Z')
            {
                return 0;
            }
        }
    }
    // TODO AL 100
    return 1;
}

/* VALIDACION DE PRECIO: Solicita al usuario un precio mediante el mensaje mensj, validando que la entrada 
sea un valor numérico positivo. Utiliza un bucle do-while para repetir la solicitud hasta que se ingrese un 
precio válido. Verifica la cantidad de puntos decimales permitidos y que todos los caracteres sean dígitos 
o el carácter de punto decimal. Convierte la cadena ingresada a un valor de tipo double usando atof y lo 
asigna a la variable precio. Retorna 1 si se ingresa un precio válido, y 0 en caso contrario.*/
int ValidacionPrecio(char mensj[], double *precio) 
{
    char cadena[200];
    int longitud;

    do
    {
        printf("%s", mensj);
        fflush(stdin);
        gets(cadena);

        longitud = strlen(cadena);

        int puntoCount = 0;
        for (int i = 0; i < longitud; i++) 
        {
            if (cadena[i] == '.') 
            {
                puntoCount++;
                if (puntoCount > 1) 
                {
                    return 0;
                }
            }
            else if (cadena[i] < '0' || cadena[i] > '9') 
            {
                return 0;
            }
        }
        *precio = atof(cadena);
    } while (*precio <= 0);

    return 1;
}

/* EXTRAS */
int Mayusculas(char cadena[]) 
{
    int i = 0;
    while ( cadena[i] != '\0' ) 
    {
        if ( cadena[i] >= 'a' )
        {
            if ( cadena [i] <= 'z' )
            {
                cadena[i] = cadena[i] - ( 'a' - 'A');
            }
        }
        i++;
    }
    return 0;
}