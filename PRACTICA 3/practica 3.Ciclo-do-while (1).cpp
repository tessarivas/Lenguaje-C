#include <stdio.h>
main()
{
	int m=1,s=0,a=0;
	float v,pv;
	do
	{
		printf ("Ingresa la venta mensual: ");
		scanf("%f",&v);
		m++;
		s=(s+v);
		if (v>2500)
		{
		a=a+1;	
		}
	} while(m<=10);
	
	pv=s/10;
	printf("El total de las ventas fue:%d ",s);
	printf("El promedio de ventas es de:%f ",pv);
	printf("Personas han vendido mas de 2500 pesos en el mes%d:",a);
}