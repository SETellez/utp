#include <stdio.h>
#include <stdlib.h>

typedef int elemento;
struct nodo
{
    elemento dato;
    struct nodo * siguiente;
};

typedef struct nodo Nodo;

Nodo* crearNodo(elemento x, Nodo* enlace)
{
    Nodo *p;
    p = (Nodo*)malloc(sizeof(Nodo));
    p->dato = x;
    p->siguiente = enlace;
    return p;
}

void imprimir(Nodo *inicio)
{
    Nodo *actual = inicio;
    while (actual != NULL)
    {
        printf("%d ", actual->dato);
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
    if (*inicio == NULL || x <= (*inicio)->dato)
    {
        nuevo->siguiente = *inicio;
        *inicio = nuevo;
        return;
    }

    Nodo *actual = *inicio;
    while (actual->siguiente != NULL && actual->siguiente->dato < x)
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
        if (actual->dato == x)
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
        if (actual->dato == x)
        {
            if (anterior == NULL)
            {
                *inicio = actual->siguiente;
            }
            else
            {
                anterior->siguiente = actual->siguiente;
            }
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
        if (actual->dato == x)
        {
            actual->dato = nuevo;
            return;
        }
        actual = actual->siguiente;
    }
}

void guardarEnArchivo(Nodo *inicio)
{
    FILE *archivo;
    archivo = fopen("listaguardada.txt", "w");

    if (archivo == NULL)
    {
        printf("Error al abrir el archivo.\n");
        return;
    }

    Nodo *actual = inicio;
    while (actual != NULL)
    {
        fprintf(archivo, "%d ", actual->dato);
        actual = actual->siguiente;
    }

    fclose(archivo);
    printf("Lista guardada en el archivo 'listaguardada.txt'.\n");
}

void leerDesdeArchivo(Nodo **inicio)
{
    FILE *archivo;
    archivo = fopen("listaguardada.txt", "r");

    if (archivo == NULL)
    {
        printf("No hay o no existe el archivo.\n");
        return;
    }

    elemento x;
    while (fscanf(archivo, "%d", &x) == 1)
    {
        insertarFinal(inicio, x);
    }

    fclose(archivo);
    printf("Lista cargada desde el archivo 'listaguardada.txt'.\n");
}

int main()
{
    Nodo *lista = NULL;
    elemento opcion, x, nuevo;
    Nodo *elementoBuscado;
    leerDesdeArchivo(&lista);

    do
    {
        printf("\n--------------MENU--------------\n");
        printf("1. Insertar elemento al inicio\n");
        printf("2. Insertar elemento al final\n");
        printf("3. Insertar elemento ordenado\n");
        printf("4. Buscar elemento\n");
        printf("5. Eliminar elemento\n");
        printf("6. Modificar elemento\n");
        printf("7. Imprimir lista\n");
        printf("8. Guardar lista en el archivo\n");
        printf("0. Salir\n--------------------------------\n");
        printf("Ingrese opcion: ");
        scanf("%d", &opcion);

        switch (opcion)
        {
        case 1:
            printf("Ingrese elemento a insertar al inicio: ");
            scanf("%d", &x);
            insertarInicio(&lista, x);
            break;   
        case 2:
            printf("Ingrese elemento a insertar al final: ");
            scanf("%d", &x);
            insertarFinal(&lista, x);
            break;
        case 3:
            printf("Ingrese elemento a insertar de forma ordenada: ");
            scanf("%d", &x);
            insertarOrdenado(&lista, x);
            break;
        case 4:
            printf("Ingrese elemento a buscar: ");
            scanf("%d", &x);
            elementoBuscado = buscarElemento(lista, x);
            if (elementoBuscado != NULL)
            {
                printf("Elemento encontrado: %d\n", elementoBuscado->dato);
            }
            else
            {
                printf("Elemento no encontrado\n");
            }
            break;
        case 5:
            printf("Ingrese elemento a eliminar: ");
            scanf("%d", &x);
            eliminarElemento(&lista, x);
            break;
        case 6:
            printf("Ingrese elemento a modificar: ");
            scanf("%d", &x);
            printf("Ingrese nuevo valor: ");
            scanf("%d", &nuevo);
            modificarElemento(lista, x, nuevo);
            break;
        case 7:
            printf("Elementos de la lista: ");
            imprimir(lista);
            break;
        case 8:
            guardarEnArchivo(lista);
            break;
        case 0:
            printf("Finalizado. Exito. :3 \n");
            break;
        default:
            printf("Opcion no valida.\n");
            break;
        }
    } while (opcion != 0);

    return 0;
}   

