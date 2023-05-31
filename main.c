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