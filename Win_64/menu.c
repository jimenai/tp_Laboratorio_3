#include <stdio.h>
#include "defines.h"

/** \brief Muestra el menu de opciones a elegir
 *
 *
 */
void showMenu(){
    printf("ABM Empleados\nElija opcion:\n%d-Cargar los datos de los empleados desde el archivo data.csv (modo texto)\n%d-Cargar los datos de los empleados desde el archivo data.csv (modo binario)\n%d-Alta\n%d-Modificar\n%d-Baja\n%d-Listar\n%d-Ordenar\n%d-Guardar los datos de los empleados en el archivo data.csv (modo texto)\n%d-Guardar los datos de los empleados en el archivo data.csv (modo binario)\n%d-Salir\n", CARGARTXT, CARGARBIN, ALTA, MODIFICACION, BAJA, LISTAR, ORDENAR, GUARDARTXT, GUARDARBIN, SALIR);
}

/** \brief Muestra el menu de opciones a elegir para modificar alguna dato del empleado
 *
 *
 */
void showMenuEmpleadoModificar()
{
    printf("Que datos del empleado desea modificar?\n1-Nombre\n2-Horas Trabajadas\n3-Sueldo\n4-Salir\n", MODIFICAR_NOMBRE, MODIFICAR_HORAS_TRABAJADAS, MODIFICAR_SALARIO, MODIFICAR_SALIR);
}

/** \brief Muestra el menu de los datos que desea ordenar
 *
 *
 */
void showMenuOrdenamiento()
{
    printf("Por que quiere ordenar?\n1-Nombre\n2-Sueldo\n3-Horas Trabajadas\n4-ID\n5-Salir\n", ORDENAR_POR_NOMBRE, ORDENAR_POR_SUELDO, ORDENAR_POR_HORAS_TRABAJADAS,ORDENAR_POR_ID, SALIR_DE_ORDENAR);
}

/** \brief Muestra el menu de los tipos de ordenamiento a elegir
 *
 *
 */
int showMenuTipoDeOrdenamiento()
{
    //int ordenar;
    printf("De que manera desea ordenar? Elija opcion:\n1-Ascendente\n2-Descendente\n", ORDENAMIENTO_ASCENDENTE, ORDENAMIENTO_DESCENDENTE);
    if(ORDENAMIENTO_ASCENDENTE)
        return ORDENAMIENTO_ASCENDENTE;
    else if(ORDENAMIENTO_DESCENDENTE)
        return ORDENAMIENTO_DESCENDENTE;
    else
        printf("Tipo de ordenamiento no valido");
        return ERROR_TIPO_ORDENAMIENTO_INVALIDO;
    //return ordenar;
}
