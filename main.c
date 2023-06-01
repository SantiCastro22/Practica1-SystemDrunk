#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAXLIB 200

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
int contLibros = 0;

void agregarLibro(Libro registroLibros[MAXLIB]);
void eliminarLibro(Libro registroLibros[MAXLIB]);
void mostrarLibro(Libro registroLibros[MAXLIB]);

int main()
{
	int opcion;

	do
	{
		printf("------ MENU DE OPCIONES ------\n");
		printf("1. Agregar Libro\n");
		printf("2. Modificar Libro\n");
		printf("3. Eliminar Libro\n");
		printf("4. Mostrar Libros cargados\n");
		printf("5. Salir\n");
		printf("Ingrese una opcion: ");
		scanf("%d", &opcion);

		switch (opcion)
		{
		case 1:
			agregarLibro(registroLibros);
			break;
		case 2:
			modificarLibro(registroLibros);
			break;
		case 3:
			eliminarLibro(registroLibros);
			break;
		case 4:
			mostrarLibro(registroLibros);
			break;
		case 5:
			printf("Saliendo del sistema...\n");
			break;

		default:
			printf("Por favor, ingrese una opcion valida.\n");
			break;
		}
		printf("\n");
	} while (opcion != 5);
	
	return 0;
}

void agregarLibro(Libro registroLibros[MAXLIB])
{
	printf("\n------ AGREGAR NUEVO LIBRO ------\n");

	for (int i = 0; i < MAXLIB; i++)
	{
		fflush(stdin);
		printf("- Libro [%d]\n", i + 1);
		printf("- Autor del libro: ");
		gets(registroLibros[i].autor);
		printf("- Titulo del libro: ");
		gets(registroLibros[i].titulo);
		printf("- Editorial del libro: ");
		gets(registroLibros[i].editorial);
		printf("- A%co de publicacion del libro: ", 164);
		scanf("%d", &registroLibros[i].anio);
		printf("- Precio del libro: ");
		scanf("%f", &registroLibros[i].precio);
		contLibros++;
	}
	printf("\n");
}

void mostrarLibro(Libro registroLibros[MAXLIB])
{
	printf("\nREGISTRO DE LIBROS EXISTENTES\n");

	for (int i = 0; i < MAXLIB; i++)
	{
		printf("Libro [%d]\n", i + 1);
		printf("Titulo: %s\n", registroLibros[i].titulo);
		printf("Autor: %s\n", registroLibros[i].autor);
		printf("Editorial: %s\n", registroLibros[i].editorial);
		printf("A%co: %d\n", 164, registroLibros[i].anio);
		printf("Precio: %.2f\n", registroLibros[i].precio);
		printf("----------------------\n");
	}
}

void eliminarLibro(Libro registroLibros[MAXLIB])
{
	char indexTituloLibro[30];
	int encontrado = 0;
	fflush(stdin);
	printf("\nELIMINAR LIBROS\n");
	printf("Ingrese el titulo del libro a eliminar: ");
	gets(indexTituloLibro);

	for (int i = 0; i < MAXLIB; i++)
	{
		if (strcmp(indexTituloLibro, registroLibros[i].titulo) == 0)
		{
			for (int j = i; j < MAXLIB; j++)
				registroLibros[j] = registroLibros[j + 1];

			encontrado = 1;
			printf("\nEl libro se elimino correctamente del sistema\n");
		}
	}

	if (!encontrado)
	{
		printf("\nEl libro que desea eliminar no se encuentra\n");
	}
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
        printf("Nuevo Autor: ");
        gets(registroLibros[editLibro].autor);
        printf("Nuevo Titulo: ");
        gets(registroLibros[editLibro].titulo);
        printf("Nuevo Editorial: ");
        gets(registroLibros[editLibro].editorial);
        printf("Nuevo A%co de publicacion: ",164);
        scanf("%d",&registroLibros[editLibro].anio);
        printf("Nuevo Precio: ");
        scanf("%f",&registroLibros[editLibro].precio);
        printf("\nEl libro se modifico con exito\n");
    }
    else 
        printf("\nEl libro que desea modicar no se encuentra\n");
    
}
