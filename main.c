#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAXLIB 200 // CANTIDAD MAXIMA DE LIBROS

typedef struct
{
	char autor[30];
	char titulo[30];
	char editorial[20];
	int anio;
	float precio;
} Libro;

// VARIABLES GLOBALES
Libro registroLibros[MAXLIB]; // ARRAY DE TIPO LIBRO
int contLibros = 0;			  // CONTADOR DE LIBROS CARGADOS

void agregarLibro(Libro registroLibros[MAXLIB]);
void eliminarLibro(Libro registroLibros[MAXLIB]);
void mostrarLibro(Libro registroLibros[MAXLIB]);
void modificarLibro(Libro registroLibros[MAXLIB]);

void mergeSort(Libro registro[], int left, int right);
void merge(Libro registro[], int left, int middle, int right);
void quickSort(Libro arr[], int low, int high);

void selectionSort(Libro registro[], int n);

int main()
{
	int opcion;

	printf("*********************************\n");
    printf("*  Sistema de Gestion de Libros *\n");
    printf("*********************************\n");

	do
	{
		printf("------ MENU DE OPCIONES ------\n");
		printf("1. Agregar Libro\n");
		printf("2. Modificar Libro\n");
		printf("3. Eliminar Libro\n");
		printf("4. Mostrar Libros cargados\n");
		printf("5. Ordenar por a%co de publicacion(MergeSort)\n", 164);
		printf("6. Salir\n");
		printf("Ingrese una opcion: ");
		scanf("%d", &opcion);

		switch (opcion)
		{
		case 1:
			agregarLibro(registroLibros);
			break;
		case 2:
			if (contLibros>0)
				modificarLibro(registroLibros);
			else
				printf("\nNo existen libros cargados para modificar\n");
			break;
		case 3:
			if (contLibros>0)
				eliminarLibro(registroLibros);
			else
				printf("\nNo existen libros cargados para eliminar\n");
			break;
		case 4:
			if (contLibros>0)
				mostrarLibro(registroLibros);
			else
				printf("\nNo existen libros cargados para mostrar\n");
			break;
		case 5:
			if (contLibros > 0)
			{
				mergeSort(registroLibros, 0, contLibros - 1);
				mostrarLibro(registroLibros);
			}
			else
				printf("\nNo existen libros cargados para mostrar\n");
			break;
		case 6:
			printf("\n Saliendo del sistema...\n");
			break;
		default:
			printf("\n Por favor, ingrese una opcion valida.\n");
			break;
		}
		printf("\n");
	} while (opcion != 6);

	return 0;
}

void agregarLibro(Libro registroLibros[MAXLIB])
{
	printf("\n------ AGREGAR NUEVO LIBRO ------\n");

	int opcion;

	do
	{
		fflush(stdin);
		printf("Libro Nro: #%d\n", contLibros + 1);
		printf("- Autor del libro: ");
		gets(registroLibros[contLibros].autor);
		printf("- Titulo del libro: ");
		gets(registroLibros[contLibros].titulo);
		printf("- Editorial del libro: ");
		gets(registroLibros[contLibros].editorial);
		printf("- A%co de publicacion del libro: ", 164);
		scanf("%d", &registroLibros[contLibros].anio);
		printf("- Precio del libro: ");
		scanf("%f", &registroLibros[contLibros].precio);

		contLibros++; // Incrementar la cantidad de libros

		printf("Desea agregar otro libro? (1: SI / 0: NO): ");
		scanf("%d", &opcion);
		printf("\n");
	} while (opcion == 1);

}

void mostrarLibro(Libro registroLibros[MAXLIB])
{
	printf("\nREGISTRO DE LIBROS EXISTENTES\n");

	for (int i = 0; i < contLibros; i++)
	{
		printf("Libro #%d\n", i + 1);
		printf("Titulo: %s\n", registroLibros[i].titulo);
		printf("Autor: %s\n", registroLibros[i].autor);
		printf("Editorial: %s\n", registroLibros[i].editorial);
		printf("A%co: %d\n", 164, registroLibros[i].anio);
		printf("Precio: $ %.2f\n", registroLibros[i].precio);
		printf("----------------------\n");
	}
	system("pause");
}

void eliminarLibro(Libro registroLibros[MAXLIB])
{
	char indexTituloLibro[30];
	int encontrado = 0;
	fflush(stdin);
	printf("\nELIMINAR LIBROS\n");
	printf("Libros Existentes: %d \n", contLibros);
	printf("Ingrese el titulo del libro a eliminar: ");
	gets(indexTituloLibro);

	for (int i = 0; i < contLibros; i++)
	{
		if (strcmp(indexTituloLibro, registroLibros[i].titulo) == 0)
		{
			for (int j = i; j < contLibros; j++)
				registroLibros[j] = registroLibros[j + 1];

			encontrado = 1;
			printf("\nEl libro se elimino correctamente del sistema\n");
		}
	}

	if (!encontrado)
	{
		printf("\nEl libro que desea eliminar no se encuentra\n");
	}

	system("pause");
}

void modificarLibro(Libro registroLibros[MAXLIB])
{
	int editLibro;
	printf("\nMODIFICAR LIBROS\n");
	printf("Ingrese el numero de libro a editar: ");
	scanf("%d", &editLibro);

	editLibro--;
	fflush(stdin);

	if (editLibro <= contLibros)
	{
		printf("Modificando Libro: #%d\n",editLibro+1);

		printf("Autor Actual: %s\n", registroLibros[editLibro].autor);
		printf("- Nuevo Autor: ");
		gets(registroLibros[editLibro].autor);

		printf("Titulo Actual: %s\n", registroLibros[editLibro].titulo);
		printf("- Nuevo Titulo: ");
		gets(registroLibros[editLibro].titulo);

		printf("Editorial Actual: %s\n", registroLibros[editLibro].editorial);
		printf("- Nuevo Editorial: ");
		gets(registroLibros[editLibro].editorial);

		printf("A%co de publicacion actual: %d\n", 164, registroLibros[editLibro].anio);
		printf("- Nuevo A%co de publicacion: ", 164);
		scanf("%d", &registroLibros[editLibro].anio);

		printf("Precio Actual: %.2f\n", registroLibros[editLibro].precio);
		printf("- Nuevo Precio: ");
		scanf("%f", &registroLibros[editLibro].precio);

		printf("\nEl libro se modifico con exito\n");
	}
	else
	{
		printf("\nEl libro que desea modicar no se encuentra\n");
	}

	system("pause");
}

void mergeSort(Libro registro[], int left, int right)
{
	if (left < right)
	{
		int middle = left + (right - left) / 2;

		mergeSort(registro, left, middle);
		mergeSort(registro, middle + 1, right);

		merge(registro, left, middle, right);
	}
}

void merge(Libro registro[], int left, int middle, int right)
{
	int i, j, k;
	int n1 = middle - left + 1;
	int n2 = right - middle;

	Libro L[n1], R[n2];

	for (i = 0; i < n1; i++)
		L[i] = registro[left + i];
	for (j = 0; j < n2; j++)
		R[j] = registro[middle + 1 + j];

	i = 0;
	j = 0;
	k = left;

	while (i < n1 && j < n2)
	{
		if (L[i].anio <= R[j].anio)
		{
			registro[k] = L[i];
			i++;
		}
		else
		{
			registro[k] = R[j];
			j++;
		}
		k++;
	}

	while (i < n1)
	{
		registro[k] = L[i];
		i++;
		k++;
	}

	while (j < n2)
	{
		registro[k] = R[j];
		j++;
		k++;
	}
}

void quickSort(Libro registro[], int low, int high)
{
	if (low < high)
	{
		int indexPivot = partition(registro, low, high);

		quickSort(registro, low, indexPivot - 1);
		quickSort(registro, indexPivot + 1, high);
	}
}

void selectionSort(Libro registro[], int n)
{
    for (int i = 0; i < n - 1; i++)
    {
        int minIndex = i;

        for (int j = i + 1; j < n; j++)
        {
            if (registro[j].anio < registro[minIndex].anio)
            {
                minIndex = j;
            }
        }

        if (minIndex != i)
        {
            swap(&registro[i], &registro[minIndex]);
        }
    }
}
