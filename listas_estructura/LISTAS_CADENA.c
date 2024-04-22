#include "librerialistas.h"

int main()
{
    Nodo *lista = NULL;
    elemento opcion, x, nuevo;
    Nodo *elementoBuscado;

    do
    {
        printf("\nMENU:\n");
        printf("1. Insertar elemento al inicio\n");
        printf("2. Insertar elemento al final\n");
        printf("3. Eliminar elemento\n");
        printf("4. Buscar elemento\n");
        printf("5. Imprimir lista\n");
        printf("0. Salir\n");
        printf("Ingrese opcion: ");
        scanf("%s", opcion); 

        switch (opcion[0]) 
        {
        case '1':
            printf("Ingrese elemento a insertar al inicio: ");
            scanf("%s", x); 
            insertarInicio(&lista, x);
            break;
        case '2':
            printf("Ingrese elemento a insertar al final: ");
            scanf("%s", x); 
            insertarFinal(&lista, x);
            break;
        case '3':
            printf("Ingrese elemento a eliminar: ");
            scanf("%s", x); 
            eliminarElemento(&lista, x);
            break;
         case '4':
            printf("Ingrese elemento a buscar: ");
            scanf("%s", x); 
            elementoBuscado = buscarElemento(lista, x);
            if (elementoBuscado != NULL)
            {
                printf("Elemento encontrado: %s\n", elementoBuscado->dato); 
            }
            else
            {
                printf("Elemento no encontrado\n");
            }
            break;
        case '5':
            printf("Elementos de la lista: ");
            imprimir(lista);
            break;
        case '0':
            printf("Saliendo del programa.\n");
            break;
        default:
            printf("Opcion no valida.\n");
            break;
        }
    } while (opcion[0] != '0');

    return 0;
}