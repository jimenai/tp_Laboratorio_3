#include <stdio.h>
#include <stdlib.h>
#include "LinkedList.h"
#include "Controller.h"
#include "Employee.h"
#include "defines.h"
#include "menu.h"

/****************************************************
    Menu:
     1. Cargar los datos de los empleados desde el archivo data.csv (modo texto).
     2. Cargar los datos de los empleados desde el archivo data.csv (modo binario).
     3. Alta de empleado
     4. Modificar datos de empleado
     5. Baja de empleado
     6. Listar empleados
     7. Ordenar empleados
     8. Guardar los datos de los empleados en el archivo data.csv (modo texto).
     9. Guardar los datos de los empleados en el archivo data.csv (modo binario).
    10. Salir
*****************************************************/

void printResultado(int resultado);
int main()
{
    int option = 0;
    int resultado;

    //Creo una lista de empleados
    LinkedList* listaEmpleados = ll_newLinkedList();
    do{
        //Muestra menu de opciones para el ABM
        showMenu();
        scanf("%d", &option);
        switch(option)
        {//Si elegimos la opcion 1, cargamos los datos del empleado en un archivo de TEXTO
            case CARGARTXT:
                // Path absoluto: comienza desde el raiz, por ejemplo C:
                // Path relativo comienza desde donde esta el .exe
                //asignamos el resultado de la carga a la variable resultado
                resultado = controller_loadFromText("Data/Employees3.csv", listaEmpleados);
                //imprimimos el resultado de la carga en el archivo.
                printResultado(resultado);
                break;
            //Si elegimos la opcion 2, cargamos los datos del empleado en un archivo binario.
            case CARGARBIN:
                //asignamos el resultado de la carga a la variable resultado
                resultado = controller_loadFromBinary("files/sdata.csv", listaEmpleados);
                //imprimimos el resultado de la carga en el archivo.
                printResultado(resultado);
                break;
            case ALTA:
                //Si elegimos la opcion 3 damos de alta un empleado en la lista de empleados
                resultado = controller_addEmployee(listaEmpleados);
                //imprimimos el resultado de la carga en el archivo
                printResultado(resultado);
                break;
            case BAJA:
                //Si elegimos la opcion 4, queremos eliminar un empleado
                resultado = controller_removeEmployee(listaEmpleados);
                //imprimimos el resultado de la carga en el archivo.
                printResultado(resultado);
                break;
            case MODIFICACION:
                //Si elegimos la opcion 5, modificamos algun/os empleado
                resultado = controller_editEmployee(listaEmpleados);
                //Imprimimos el resultado de la carga del archivo
                printResultado(resultado);
                break;
            case LISTAR:
                //Si elegimos la opcion 6, listamos a los empleados
                resultado = controller_ListEmployee(listaEmpleados);
                //Imprimimos el resultado del listar
                printResultado(resultado);
                break;
            case ORDENAR:
                //Si elegimos la opcion 7, ordenamos los empleados de la manera que lo deseemos
                resultado = controller_sortEmployee(listaEmpleados);
                //Imprimimos el resulado del ordenamiento del empleado
                printResultado(resultado);
                break;
            case GUARDARTXT:
                //Si elegimos la opcion 8, se guardan los datos en un archivo de texto
                resultado = controller_loadFromText("dataTXT.csv", listaEmpleados);
                break;
            case GUARDARBIN:
                //Si elegimos la opcion 8, se guardan los datos en un archivo de texto
                controller_loadFromBinary("dataBIN.csv", listaEmpleados);
                //Imprimimos el resulado del ordenamiento del empleado
                printResultado(resultado);
                break;
            case SALIR:
                printf("Programa Finalizado");
                break;
            default:
                printf("No ha ingresado un numero valido");
                break;
        }
    }while(option != SALIR);

    return 0;
}

void printResultado(int resultado)
{
    switch(resultado){
        case OK:
            puts("Resultado del proceso: exitoso");
            break;
        case ERROR_ABRIR_ARCHIVO:
            puts("No se pudo abrir archivo");
            break;
        case ERROR_LEER_ARCHIVO:
            puts("No se pudo leer archivo");
            break;
        case ERROR_GUARDAR_ARCHIVO:
            puts("No se pudo guardar archivo");
            break;
        case ERROR_PARAMETRO_INVALIDO:
            puts("Parametro Invalido");
            break;
        case ERROR_MEMORIA_NO_DISPONIBLE:
            puts("Memoria no disponible");
            break;
        case ERROR_ID_INVALIDO:
            puts("ID no valido");
            break;
        case ERROR_CARACTER_INVALIDO:
            puts("Caracter invalido");
            break;
        case ERROR_NOMBRE_INVALIDO:
            puts("Nombre invalido");
            break;
        case ERROR_HORAS_TRABAJADAS_INVALIDA:
            puts("Horas trabajadas invalidas");
            break;
        case ERROR_SUELDO_INVALIDO:
            puts("Sueldo invalido");
            break;
        case ERROR_DIGITO_INVALIDO:
            puts("No ha ingresado digitos");
            break;
        case ERROR_PEDIR_DATOS_EMPLEADO:
            puts("Error al padir los datos");
            break;
        case ERROR_EMPLEADO_NO_ENCONTRADO:
            puts("Empleado no encontrado");
            break;
        case ERROR_ID_INGRESADO_INCORRECTO:
            puts("ID ingresado incorrecto");
            break;
        default:
            puts("Error no indentificado");
            break;
    }

}
