/*
NOMBRE DEL ARCHIVO: EXAMEN 2
AUTOR: Teresa Rivas Gomez
FECHA DE CREACION: Nov - 22 - 2023
DESCRIPCION: Registro de mascotas, historisl medico(actualizar y mostrar), consulta de registros, 
y almacenamiento de datos(almacenar y cargar datos.)
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/* TAMAÑO DEL REGISTRO */
#define REGISTROS 50

/* ESTRUCTURA PRINCIPAL */
typedef struct _registro
{
    int status;
    char nombre[20];
    char tipo[20];
    char raza[20];
    int edad;
    int vacunas;
} Tregistro;

/* DECLARACION DE FUNCIONES UTILIZADAS */
int mensajes();
void menu();

Tregistro agregar_mascota(void);
Tregistro historial_mascota(int i);
int consultar_mascotas(Tregistro datos[], int i);
void almacenar_mascotas(Tregistro datos[], int i);

int ValidarCadena(char mensj[], int ri, int rf);
int ValidarCadenaTexto(const char cadena[]);
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
    printf("          MASCOTAS         \n");
    printf("---------------------------\n");
    printf("1.- REGISTRO\n");
    printf("2.- HISTORIAL MEDICO\n");
    printf("3.- CONSULTA DE REGISTROS\n");
    printf("4.- ALMACENAMIENTO DE DATOS\n");
    printf("0.- SALIR\n");
    printf("---------------------------\n");
    opcion = ValidarCadena("SELECCIONA UNA OPCION(0|1|2|3|4): ", 0, 4);
    return opcion;
}

/* CASOS PARA CADA OPCION */
void menu()
{
    int i = 0;
    int opcion;
    Tregistro datos[REGISTROS];

    do {
        opcion = mensajes();
        system("CLS");
        switch(opcion)
        {
            case 1:
                printf("REGISTRO DE MASCOTAS\n");
                if(i < REGISTROS)
                {
                    datos[i] = agregar_mascota();
                    i++;
                    printf("-----------------------------\n");
                    printf("MASCOTA AGREGADA CORRECTAMENTE\n");
                }
                else
                {
                    printf("NO SE PUDO AGREGAR MASCOTA, ALCANZO EL LIMITE");
                }
                system("PAUSE");
                break;
            case 2:
                printf("HISTORIAL MEDICO\n");
                historial_mascota(i);
                system("PAUSE");
                break;
            case 3:
                printf("CONSULTA DE REGISTROS\n");
                consultar_mascotas(datos, i);
                system("PAUSE");
                break;
            case 4:
                printf("ALMACENAMIENTO DE DATOS\n");
                almacenar_mascotas(datos, i);
                system("PAUSE");
                break;
            case 0:
                printf("SALISTE DEL PROGRAMA.\n");
                break;
        }
    } while(opcion != 0);
}

/* AGREGAR MASCOTA AL REGISTRO */
Tregistro agregar_mascota(void)
{
    Tregistro reg;

    int op;
    char nom[20];
    char tip[20];
    char raz[20];

    // STATUS
    reg.status = 1;

    // DATOS
    printf("INGRESA LOS SIGUIENTES DATOS:\n");
    printf("-----------------------------\n");

    // NOMBRE
    do {
        printf("1.- NOMBRE DE LA MASCOTA:\n");
        fflush(stdin);
        gets(nom);
        Mayusculas(nom);
        op = ValidarCadenaTexto(nom);
        if(op != 0)
        {
            printf("PALABRA NO VALIDA.\n");
        }
    } while(op != 0);
    strcpy(reg.nombre, nom);

    // TIPO
    do {
        printf("2.- ESPECIE/TIPO DE LA MASCOTA:\n");
        fflush(stdin);
        gets(tip);
        Mayusculas(tip);
        op = ValidarCadenaTexto(tip);
        if(op != 0)
        {
            printf("PALABRA NO VALIDA.\n");
        }
    } while(op != 0);
    strcpy(reg.tipo, tip);

    // RAZA
    do {
        printf("3.- RAZA DE LA MASCOTA:\n");
        fflush(stdin);
        gets(raz);
        Mayusculas(raz);
        op = ValidarCadenaTexto(raz);
        if(op != 0)
        {
            printf("PALABRA NO VALIDA.\n");
        }
    } while(op != 0);
    strcpy(reg.raza, raz);

    // EDAD
    reg.edad = ValidarCadena("4.- EDAD DE LA MASCOTA:\n", 0, 20);

    // CANTIDAD DE VACUNAS
    reg.vacunas = ValidarCadena("5.- CANTIDAD DE VACUNAS DE LA MASCOTA:\n", 0, 100);

    // IMPRIMIR
    printf("-----------------------------\n");
    printf("MASCOTA PREVIAMENTE AGREGADA:\n");
    printf("-----------------------------\n");
    printf("NOMBRE: %s\n", reg.nombre);
    printf("TIPO/ESPECIE: %s\n", reg.tipo);
    printf("RAZA: %s\n", reg.raza);
    printf("EDAD: %d\n", reg.edad);
    printf("VACUNAS: %d\n", reg.vacunas);

    return reg;
}

/* HISTORIAL MEDICO DE MASCOTA */
Tregistro historial_mascota(int i)
{
    Tregistro reg;

    int op;
    int j;
    char nom[20];
    
    printf("      HISTORIAL MEDICO       \n");
    printf("INGRESA LOS SIGUIENTES DATOS:\n");
    printf("-----------------------------\n");

    do {
        printf("1.- NOMBRE DE LA MASCOTA:\n");
        fflush(stdin);
        gets(nom);
        Mayusculas(nom);
        op = ValidarCadenaTexto(nom);
        if(op != 0)
        {
            printf("PALABRA NO VALIDA.\n");
        }
    } while(op != 0);

    for(j = 0; j < i; j++)
    {
        if(strcmp(reg.nombre, nom) == 0)
        {
            printf("-----------------------------\n");
            printf("   HISTORIAL DE LA MASCOTA:  \n");
            printf("-----------------------------\n");
            printf("NOMBRE: %s\n", reg.nombre);
            printf("TIPO/ESPECIE: %s\n", reg.tipo);
            printf("RAZA: %s\n", reg.raza);
            printf("EDAD: %d\n", reg.edad);
            printf("VACUNAS: %d\n", reg.vacunas);
        }
        else
        {
            printf("MASCOTA NO ENCONTRADA. REVISE DE NUEVO.\n");
        }
    }
}

/* CONSULTA DE TODOS LOS REGISTROS */
int consultar_mascotas(Tregistro datos[], int i)
{
    int j, k;

    printf("REGISTRO DE MASCOTAS\n");
    printf("+------+----------------+---------------+--------------+--------+-----------+\n");
    printf("| NUM. |     NOMBRE     |  TIPO/ESPECIE |     RAZA     |  EDAD  |  VACUNAS  |\n");
    printf("+------+----------------+---------------+--------------+--------+-----------+\n");

    for(j = 0, k = 0; j < i; j++)
    {
        if(datos[j].status == 1)
        {
            printf("| %-4d | %-14s | %-13s | %-12s | %-6d | %-9d |",
            j + 1,
            datos[j].nombre,
            datos[j].tipo,
            datos[j].raza,
            datos[j].edad,
            datos[j].vacunas
            );
            printf("\n");
            k++;
        }
    }
    return 0;
}

/* ALMACENAMIENTO DE LOS DATOS */
void almacenar_mascotas(Tregistro datos[], int i)
{
    int j, k;

    // CREAR ARCHIVO
    FILE *archivo;
    archivo = fopen("C:\\Users\\52616\\OneDrive\\Documentos\\U A B C\\3er Semestre\\Lenguaje C\\Examen 2\\output\\registros.txt", "w");

    // ERROR
    if (archivo == NULL) 
    {
        printf("ERROR AL ABRIR EL ARCHIVO.\n");
        return;
    }

    // IMPRIMIR
    fprintf(archivo, "REGISTRO DE MASCOTAS\n");
    fprintf(archivo, "+------+----------------+---------------+--------------+--------+-----------+\n");
    fprintf(archivo, "| NUM. |     NOMBRE     |  TIPO/ESPECIE |     RAZA     |  EDAD  |  VACUNAS  |\n");
    fprintf(archivo, "+------+----------------+---------------+--------------+--------+-----------+\n");

    for(j = 0, k = 0; j < i; j++)
    {
        if(datos[j].status == 1)
        {
            fprintf(archivo, "| %-4d | %-14s | %-13s | %-12s | %-6d | %-9d |",
            j + 1,
            datos[j].nombre,
            datos[j].tipo,
            datos[j].raza,
            datos[j].edad,
            datos[j].vacunas
            );
            fprintf(archivo, "\n");
            k++;
        }
    }

    // CERRAR
    fclose(archivo);
    printf("LOS REGISTROS SE HAN COPIADO EN 'registros.txt'.\n");
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
    // SOLO LETRAS Y ESPACIOS
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
            if(cadena[i] < 'A' || cadena[i] > 'Z' || cadena[i] < 'a' || cadena[i] > 'z')
            {
                return 0;
            }
        }
    }
    // TODO AL 100
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