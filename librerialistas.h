#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef char* elemento; // Cambio el tipo de dato de int a char*

struct nodo
{
    elemento dato; // Cambio el tipo de dato de int a char*
    struct nodo * siguiente;
};

typedef struct nodo Nodo;

Nodo* crearNodo(elemento x, Nodo* enlace)
{
    Nodo *p;
    p = (Nodo*)malloc(sizeof(Nodo));
    p->dato = strdup(x); // Utilizo strdup para copiar la cadena x
    p->siguiente = enlace;
    return p;
}

void imprimir(Nodo *inicio)
{
    Nodo *actual = inicio;
    while (actual != NULL)
    {
        printf("%s ", actual->dato); // Cambio %d por %s para imprimir cadenas
        actual = actual->siguiente;
    }
    printf("\n");
}

void insertarInicio(Nodo **inicio, elemento x)
{
    Nodo *nuevo = crearNodo(x, *inicio);
    *inicio = nuevo;
}

void insertarFinal(Nodo **inicio, elemento x)
{
    Nodo *nuevo = crearNodo(x, NULL);
    if (*inicio == NULL)
    {
        *inicio = nuevo;
        return;
    }

    Nodo *actual = *inicio;
    while (actual->siguiente != NULL)
    {
        actual = actual->siguiente;
    }
    actual->siguiente = nuevo;
}

void insertarOrdenado(Nodo **inicio, elemento x)
{
    Nodo *nuevo = crearNodo(x, NULL);
    if (*inicio == NULL || strcmp(x, (*inicio)->dato) <= 0) // Comparo cadenas usando strcmp
    {
        nuevo->siguiente = *inicio;
        *inicio = nuevo;
        return;
    }

    Nodo *actual = *inicio;
    while (actual->siguiente != NULL && strcmp(actual->siguiente->dato, x) < 0) // Comparo cadenas usando strcmp
    {
        actual = actual->siguiente;
    }
    nuevo->siguiente = actual->siguiente;
    actual->siguiente = nuevo;
}

Nodo* buscarElemento(Nodo *inicio, elemento x)
{
    Nodo *actual = inicio;
    while (actual != NULL)
    {
        if (strcmp(actual->dato, x) == 0) // Comparo cadenas usando strcmp
        {
            return actual;
        }
        actual = actual->siguiente;
    }
    return NULL;
}

void eliminarElemento(Nodo **inicio, elemento x)
{
    Nodo *actual = *inicio;
    Nodo *anterior = NULL;

    while (actual != NULL)
    {
        if (strcmp(actual->dato, x) == 0) // Comparo cadenas usando strcmp
        {
            if (anterior == NULL)
            {
                *inicio = actual->siguiente;
            }
            else
            {
                anterior->siguiente = actual->siguiente;
            }
            free(actual->dato); // Libero la memoria de la cadena
            free(actual);
            return;
        }
        anterior = actual;
        actual = actual->siguiente;
    }
}

void modificarElemento(Nodo *inicio, elemento x, elemento nuevo)
{
    Nodo *actual = inicio;
    while (actual != NULL)
    {
        if (strcmp(actual->dato, x) == 0) // Comparo cadenas usando strcmp
        {
            free(actual->dato); // Libero la memoria de la cadena antigua
            actual->dato = strdup(nuevo); // Actualizo la cadena con la nueva
            return;
        }
        actual = actual->siguiente;
    }
}