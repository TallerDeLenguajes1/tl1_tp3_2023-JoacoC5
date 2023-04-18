#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

struct Producto
{
    int productoID; //Numerado en ciclo iterativo
    int cantidad; //Entre 1 y 10
    char *tipoProducto; //Algun valor del arreglo TiposProductos
    float precioUnitario; //Entre 10-100

} typedef producto;

struct Cliente
{
    int clienteID; //Numerado en ciclo iterativo
    char *nombreCliente; //Ingresado por usuario
    int cantProdAPedir; //Aleatorio entre 1 y 5
    producto *productos; //El tamaño de esta variable dependera del tamaño de la variable "cantProdAPedir"

}typedef cliente;

float costoTotalProducto(producto *a);
void mostrar (int cant, cliente a, float total[]);

int main () {
     
    srand(time(NULL));
    
    char *TiposProductos[] = {"Galletas", "Snack", "Cigarrillo", "Caramelos", "Bebida"};
    int cant, aux;
    cliente *clientes;
    char buff[30];

    printf("Ingrese la cantidad de clientes: ");
    scanf("%d", &cant);
    fflush(stdin);
    float total[cant];

    clientes = malloc(sizeof(cliente)*cant);

    for (int i = 0; i < cant; i++)
    {
        clientes[i].clienteID = (i+1);
        fflush(stdin);
        printf("Ingresar nombre del cliente: ");
        gets(buff);
        fflush(stdin);
        clientes[i].nombreCliente = malloc((strlen(buff)+1) * sizeof(char));
        strcpy(clientes[i].nombreCliente, buff);
        fflush(stdin);
        clientes[i].cantProdAPedir = 1+rand()%5;
        fflush(stdin);
        clientes[i].productos = malloc(sizeof(producto) * clientes[i].cantProdAPedir);
        fflush(stdin);
        

        printf("\n\n------DATOS DEL PREVENTISTA------\n");
        printf("--Cliente de ID N %d--\n", clientes[i].clienteID);
        printf("Nombre cliente: %s\n", clientes[i].nombreCliente);
        printf("Cantidad de productos del cliente: %d\n", clientes[i].cantProdAPedir);
        fflush(stdin);

        for (int j = 0; j < clientes[i].cantProdAPedir; j++)
        {
            clientes[i].productos->productoID = (j+1);
            clientes[i].productos->cantidad = 1 + rand()%9;
            fflush(stdin);
            aux = rand()%5;
            fflush(stdin);
            clientes[i].productos->tipoProducto = &TiposProductos[aux][0];
            clientes[i].productos->precioUnitario = 10 + rand()%90;
            fflush(stdin);

            total[i] = total[i] + costoTotalProducto(clientes[i].productos);

            puts("-\nINFORMACION PRODUCTOS\n-");
            printf("ID producto: %d\n", clientes[i].productos->productoID);
            printf("Cantidad del producto: %d\n", clientes[i].productos->cantidad);
            printf("Tipo de Producto: %s\n", clientes[i].productos->tipoProducto);
            printf("Precio del producto: %.2f\n", clientes[i].productos->precioUnitario);
        }

        printf("\n-Costo total del cliente: %.2f-\n\n\n", total[i]);       
        
    }



   //mostrar(cant, *clientes, total);


    return 0;
}


float costoTotalProducto(producto *a)
{
    float precio;

    precio = a->cantidad * a->precioUnitario;

    return precio;
}

void mostrar (int cant, cliente a, float total[])
{
    printf("\n\n------DATOS DEL PREVENTISTA------\n");

    for (int i = 0; i < cant; i++)
    {
        printf("--Cliente de ID N %d--\n", a.clienteID);
        printf("Nombre cliente: %s", a.nombreCliente);
        printf("Cantidad de productos del cliente: %d", a.cantProdAPedir);

        puts("-INFORMACION PRODUCTOS-");
        for (int j = 0; j < a.productos->cantidad; i++)
        {
            printf("ID producto: %d", a.productos->productoID);
            printf("Cantidad del producto: %d", a.productos->cantidad);
            printf("Tipo de Producto: %s", a.productos->tipoProducto);
            printf("Precio del producto: %.2f", a.productos->precioUnitario);
        }
        printf("Costo total del cliente: %.2f", total[i]);
        
    }
    
}