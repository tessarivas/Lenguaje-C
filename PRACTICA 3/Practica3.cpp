#include <stdio.h>

main()
{
	int personas=1, total=0, destacados=0;
	float ventas, promedio;

	do
	{
		printf ("Ingresa la venta mensual de cada persona: \n");
		scanf("%f",&ventas);
		personas++;
	
		total=(total+ventas);
		
		if (ventas > 2500) {
		destacados = destacados + 1;	
		}
		
	} while (personas <= 10);
	
	promedio = total / 10;
	
	printf("Total de ventas: $%.2d\n ", total);
	printf("Promedio de ventas: $%.2f\n ", promedio);
	printf("Cantidad de personas que vendieron mas de $2,500: %d\n", destacados);
	
	return 0;
}
