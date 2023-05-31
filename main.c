#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LIBROS 500

typedef struct {
	char titulo[100];
	char autor[50];
	char genero[50];
	int anio_publicacion;
} Libro;

void agregarLibro(Libro libros[], int* contador);
void eliminarLibro(Libro registroLibros[]);
void mostrarLibro(Libro registroLibros[MAXLIB]);

int main()
{
    
    return 0;
}

void agregarLibro(Libro libros[], int* contador) {
	if (*contador < MAX_LIBROS) {
		Libro nuevoLibro;
		
		printf("Ingrese el título del libro: ");
		gets(nuevoLibro.titulo);
		nuevoLibro.titulo[strcspn(nuevoLibro.titulo, "\n")];
		
		printf("Ingrese el autor del libro: ");
		gets(nuevoLibro.autor);
		nuevoLibro.autor[strcspn(nuevoLibro.autor, "\n")];
		
		printf("Ingrese el genero del libro: ");
		gets(nuevoLibro.genero);
		nuevoLibro.genero[strcspn(nuevoLibro.genero, "\n")];
		
		printf("Ingrese el año de publicación del libro: ");
		scanf("%d", &nuevoLibro.anio_publicacion);
		getchar();
		
		libros[*contador] = nuevoLibro;
		(*contador)++;
		
		printf("Libro agregado con éxito.\n");
	} else {
		printf("La biblioteca está llena. No es posible agregar más libros.\n");
	}
}
void mostrarLibro(Libro registroLibros[MAXLIB])
{
    printf("\nREGISTRO DE LIBROS EXISTENTES\n");

    for (int i = 0; i < MAXLIB; i++) {
        printf("Libro [%d]\n",i+1);
        printf("Titulo: %s\n", registroLibros[i].titulo);
        printf("Autor: %s\n", registroLibros[i].autor);
        printf("Editorial: %s\n", registroLibros[i].editorial);
        printf("A%co: %d\n", 164,registroLibros[i].anio);
        printf("Autor: %.2f\n", registroLibros[i].precio);
        printf("----------------------\n");
    }
}

void eliminarLibro(Libro registroLibros[])
{
    char indexTituloLibro[30];
    int encontrado = 0;
    fflush(stdin);
    printf("\nELIMINAR LIBROS\n");
    printf("Ingrese el titulo del libro a eliminar: ");
    gets(indexTituloLibro);

    for (int i = 0; i < MAX_LIBROS; i++)
    {
        if (strcmp(indexTituloLibro, registroLibros[i].titulo) == 0)
        {
            for (int j = i; j < MAX_LIBROS; j++)
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
