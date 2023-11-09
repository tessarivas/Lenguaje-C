/*
NOMBRE: Teresa Rivas Gomez
MATRICULA: 372565
FECHA: Noviembre - 08 - 2023 
MATERIA: Lenguaje C
ACTIVIDAD: Taller 8. Experimentación con Punteros y Arrays
NOMBRE DEL ARCHIVO: Taller8_ExpConPunterosYArrays_RGT
INSTRUCCIONES: Durante este taller, vamos a resolver ejercicios relacionados con la unidad 5. Para cada
ejercicio, declaren las variables, constantes y funciones necesarias para llevar a cabo la tarea requerida.
Realicen el código a mano de los siguientes ejercicios*.
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
// DEFINIR TAMAÑOM DE LA MATRIZ
#define M 100
#define N 15
// FUNCIONES EXTRA
char pedir();
void llenar(char **q, int m, int n);
// GENERAR UNA MATRIZ EN DIFERENTES METODOS
// m = metodo
void m1(char *p, int m, int n);
void m2(char vector[], int m, int n);
void m3(char A[][3], int m, int n);
void m4(char *p[], int m, int n);
void m5(char **q, int m, int n);
// BUSCAR PARA CADA TIPO DE METODO
// b = busqueda
void b1(char *p, int m, int n, char letra);
void b2(char vector[], int m, int n, char letra);
void b3(char A[][3], int m, int n, char letra);
void b4(char *p[], int m, int n, char letra);
void b5(char **q, int m, int n, char letra);
// MENU PRINCIPAL
int main()
{
    srand(time(NULL));
    clock_t inicio, fin;
    // VARIABLES
    int i, k, n;
    char b[M][N];
    char *q[M];
    char **r = q;
    // t = tiempos
    double t1 = 0, t2 = 0, t3 = 0, t4 = 0, t5 = 0;
    // RECORRER MATRIZ Y LLENARLA
    for (i = 0; i < M; i++)
    {
        q[i] = &b[i][0];
    }
    llenar(r, M, N);
    printf("CANTIDAD DE VECES PARA ITERAR LA BUSQUEDA: ");
    scanf("%d", &n);
    // l = letra
    char l[n];
    for (i = 0; i < n; i++)
    {
        l[i] = 'A' + rand() % 26; 
    }

    for (k = 0; k < n; k++)
    {
        char letra = l[k];
        // 1
        printf("METODO 1\n");
        inicio = clock();
        m1(&b[0][0], M, N);
        b1(&b[0][0], M, N, letra);
        fin = clock();
        t1 += (double)(fin - inicio) / CLOCKS_PER_SEC;
        // 2
        printf("METODO 2\n");
        inicio = clock();
        m2(&b[0][0], M, N);
        b2(&b[0][0], M, N, letra);
        fin = clock();
        t2 += (double)(fin - inicio) / CLOCKS_PER_SEC;
        // 3
        printf("METODO 3\n");
        inicio = clock();
        m3(b, M, N);
        b3(b, M, N, letra);
        fin = clock();
        t3 += (double)(fin - inicio) / CLOCKS_PER_SEC;
        // 4
        printf("METODO 4\n");
        inicio = clock();
        m4(q, M, N);
        b4(q, M, N, letra);
        fin = clock();
        t4 += (double)(fin - inicio) / CLOCKS_PER_SEC;
        // 5    
        printf("METODO 5\n");
        inicio = clock();
        m5(r, M, N);
        b5(r, M, N, letra);
        fin = clock();
        t5 += (double)(fin - inicio) / CLOCKS_PER_SEC;
    }
    //IMPRESION DEL TIEMPO PARA LA EJECUCION DE CADA METODO
    printf("\nTIEMPO PARA CADA METODO:\n");
    printf("METODO 1: %f segundos\n", t1);
    printf("METODO 2: %f segundos\n", t2);
    printf("METODO 3: %f segundos\n", t3);
    printf("METODO 4: %f segundos\n", t4);
    printf("METODO 5: %f segundos\n", t5);
    // RETRONO
    return 0;
}
//FUNCIONES EXTRA PARA LETRAS
char pedir()
{
    char letra;
    printf("ESCRIBE LA LETRA QUE BUSCAS: ");
    scanf(" %c", &letra);
    // RETORNO
    return letra;
}
void llenar(char **q, int m, int n)
{
    int i, j;
    // COLUMNAS
    for (i = 0; i < m; i++)
    {
        // FILAS
        for (j = 0; j < n; j++)
        {
            // LETRAS ALEATORIAS DEL ABECEDARIO
            q[i][j] = 'A' + rand() % 26;
        }
    }
}
// MATRIZ GENERADA CON LA DIRECCION DEL PRIMER ELEMENTO
void m1(char *p, int m, int n)
{
    int i, j;
    printf("MATRIZ GENERADA: \n");
    // COLUMNAS
    for (i = 0; i < m; i++)
    {
        // LINEAS
        for (j = 0; j < n; j++)
        {
            printf("%d\t", *(p + i * n + j));
        }
        printf("\n");
    }
}
void b1(char *p, int m, int n, char letra)
{
    int i, j;
    for (i = 0; i < m; i++)
    {
        for (j = 0; j < n; j++)
        {
            if (*(p + i * n + j) == letra)
            {
                printf("LETRA %d EN POSICION: [%d][%d]\n", letra, i, j);
                return;
            }
        }
    }
    printf("LA LETRA %d NO ESTA EN LA MATRIZ\n", letra);
}
// MATRIZ GENERADA CONSIDERANDO LOS ARRAYS COMO UN VECTOR 
void m2(char vector[], int m, int n)
{
    int i, j;
    printf("MATRIZ GENERADA: \n");
    // COLUMNAS
    for (i = 0; i < m; i++)
    {
        // LINEAS
        for (j = 0; j < n; j++)
        {
            printf("%d\t", vector[i * n + j]);
        }
        printf("\n");
    }
}
void b2(char vector[], int m, int n, char letra)
{
    int i, j;
    for (i = 0; i < m; i++)
    {
        for (j = 0; j < n; j++)
        {
            if (vector[i * n + j] == letra)
            {
                printf("LETRA %d EN POSICION: [%d][%d]\n", letra, i, j);
                return;
            }
        }
    }
    printf("LA LETRA %d NO ESTA EN LA MATRIZ\n", letra);
}
// MATRIZ GENRADA CON UN VALOR ENTERO CONSTANTE PARA EL TAMAÑO DE LAS COLUMNAS
void m3(char A[][3], int m, int n)
{
    int i, j;
    printf("MATRIZ GENERADA: \n");
    // COLUMNAS
    for (i = 0; i < m; i++)
    {
        // LINEAS
        for (j = 0; j < n; j++)
        {
            printf("%d\t", A[i][j]);
        }
        printf("\n");
    }
}
void b3(char A[][3], int m, int n, char letra)
{
    int i, j;
    for (i = 0; i < m; i++)
    {
        for (j = 0; j < n; j++)
        {
            if (A[i][j] == letra)
            {
                printf("LETRA %d EN POSICION: [%d][%d]\n", letra, i, j);
                return;
            }
        }
    }
    printf("LA LETRA %d NO ESTA EN LA MATRIZ\n", letra);
}
// MATRIZ GENERADA PARA MAYOR FLEXIBILIDAD
void m4(char *p[], int m, int n)
{
    int i, j;
    printf("MATRIZ GENERADA: \n");
    // COLUMNAS
    for (i = 0; i < m; i++)
    {
        // FILAS
        for (j = 0; j < n; j++)
        {
            printf("%d\t", p[i][j]);
        }
        printf("\n");
    }
}
void b4(char *p[], int m, int n, char letra)
{
    int i, j;
    for (i = 0; i < m; i++)
    {
        for (j = 0; j < n; j++)
        {
            if (p[i][j] == letra)
            {
                printf("LETRA %d EN POSICION: [%d][%d]\n", letra, i, j);
                return;
            }
        }
    }
    printf("LA LETRA %d NO ESTA EN LA MATRIZ\n", letra);
}
// MATRIZ GENERADA
void m5(char **q, int m, int n)
{
    int i, j;
    printf("MATRIZ GENERADA: \n");
    // COLUMNAS
    for (i = 0; i < m; i++)
    {
        // LINEAS
        for (j = 0; j < n; j++)
        {
            printf("%d\t", q[i][j]);
        }
        printf("\n");
    }
}
void b5(char **q, int m, int n, char letra)
{
    int i, j;
    for (i = 0; i < m; i++)
    {
        for (j = 0; j < n; j++)
        {
            if (q[i][j] == letra)
            {
                printf("LETRA %d EN POSICION: [%d][%d]\n", letra, i, j);
                return;
            }
        }
    }
    printf("LA LETRA %d NO ESTA EN LA MATRIZ\n", letra);
}