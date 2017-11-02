#include <stdio.h>
/*Ejercicio en clase
Programa que imprime los datos los varones nacidos entre dos fechas ingresadas desde
el teclado.
Fecha:31 Octubre 2017
Elaborado por: Viviana Rojas Ruiz , Jair Antonio Ramirez y Alejandro Gonzalez*/

struct fecha{
	int dia,mes,anio;
};

struct persona{
	char nombre[30],apellido[30];
	bool sexo;
	int edad;
	fecha nacimiento;
};
int personitas[100];
void datos(persona v[],int &tam,int personitas[]);
void pasar_dias(int dia,int mes,int anio,int dia_fin,int mes_fin,int anio_fin,int &numdias_inicio,int &numdias_fin);
void imprimir(persona v[],int personitas[],int tam,int numdias_inicio,int numdias_fin);

int main()
{	
	int tam=0;
	persona v[100];
	datos(v,tam,personitas);	
	return 0;
}

void datos(persona v[],int &tam,int personitas[])
{
	int numdias_inicio=0,numdias_fin=0;
	int dia,mes,anio,anio_actual;
	int dia_fin,mes_fin,anio_fin,opcion;
	
	printf("Ingrese cuantas personas va a registrar:\n");
	scanf("%d",&tam);
	printf("Ingrese Año Actual: ");
	scanf("%d",&anio_actual);
	for(int i=0;i<tam;i++)
	{
		printf("%i.Nombre: ",i+1);
		fflush(stdin);
		fgets(v[i].nombre,30,stdin);
		printf("%i.Apellido:",i+1);
		fflush(stdin);
		fgets(v[i].apellido,30,stdin);
		printf("%i.Genero,Ingrese una opcion: 1.Femenino ó 2.Masculino\n",i+1);
		scanf("%d",&opcion);
		switch(opcion)
		{
		case 1:
			v[i].sexo=false;
			break;
		case 2:
			v[i].sexo=true;
			break;
		}
		printf("%i.Fecha de Nacimiento:\ndia:",i+1);
		scanf("%d",&v[i].nacimiento.dia);
		printf("Mes:");
		scanf("%d",&v[i].nacimiento.mes);
		printf("Año:");
		scanf("%d",&v[i].nacimiento.anio);		
		v[i].edad=anio_actual-v[i].nacimiento.anio;
		personitas[i]=v[i].nacimiento.dia+(v[i].nacimiento.mes*30)+(v[i].nacimiento.anio*365);
	}
	printf("Ingrese rango de fecha a buscar:\n");
	printf("Fecha Inicial: Dia");
	scanf("%d",&dia);
	printf("Mes:");
	scanf("%d",&mes);
	printf("Año:");
	scanf("%d",&anio);
	printf("Fecha Final: Dia");
	scanf("%d",&dia_fin);
	printf("Mes:");
	scanf("%d",&mes_fin);
	printf("Año:");
	scanf("%d",&anio_fin);	
	pasar_dias(dia,mes,anio,dia_fin,mes_fin,anio_fin,numdias_inicio,numdias_fin);
	imprimir(v,personitas,tam,numdias_inicio,numdias_fin);
}

void pasar_dias(int dia,int mes,int anio,int dia_fin,int mes_fin,int anio_fin,int &numdias_inicio,int &numdias_fin)
{	 
	numdias_inicio=dia+(mes*30)+(anio*365);
	numdias_fin=dia_fin+(mes_fin*30)+(anio_fin*365);
}

void imprimir(persona v[],int personitas[],int tam,int numdias_inicio,int numdias_fin)
{
	
	
	for(int i=0;i<tam;i++)
	{
		if (numdias_inicio<=personitas[i] && numdias_fin>=personitas[i])
		{
			if(v[i].sexo==true)
			{
				printf("Nombre:%s Apellido:%s Edad:%d\n",v[i].nombre,v[i].apellido,v[i].edad);
			}			
		}		
	}
}

