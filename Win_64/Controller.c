#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "LinkedList.h"
#include "Employee.h"
#include "defines.h"
#include "parser.h"
#include "validaciones.h"
#include "Controller.h"
#include "menu.h"



/** \brief Carga los datos de los empleados desde el archivo data.csv (modo texto).
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_loadFromText(char* path, LinkedList* pArrayListEmployee)
{
    if(pArrayListEmployee == NULL)
        return ERROR_PARAMETRO_INVALIDO;

    FILE * fp;
    fp = fopen(path, "r");
    if(fp == NULL)
        return ERROR_ABRIR_ARCHIVO;

    int ret = parser_EmployeeFromText(fp, pArrayListEmployee);
    fclose(fp);

    return ret;
}

/** \brief Carga los datos de los empleados desde el archivo data.csv (modo binario).
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_loadFromBinary(char* path , LinkedList* pArrayListEmployee)
{
    if(pArrayListEmployee == NULL)
        return ERROR_PARAMETRO_INVALIDO;

    FILE * fp;
    fp = fopen(path, "rb");
    if(fp == NULL)
        return ERROR_ABRIR_ARCHIVO;

    fclose(fp);

    return 0;

}
/** \brief Alta de empleados
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_addEmployee(LinkedList* pArrayListEmployee)
{
    if(pArrayListEmployee == NULL)
        return ERROR_PARAMETRO_INVALIDO;

    char id[8], nombre[21], horasTrabajadas[4], sueldo[8];

    if(pedirDatosEmpleado(id, nombre, horasTrabajadas, sueldo) != OK)
        return ERROR_PEDIR_DATOS_EMPLEADO;

    Employee * this = employee_newParametros(id, nombre, horasTrabajadas, sueldo);
    ll_add(pArrayListEmployee, this);


    return OK;
}

/** \brief Pide nombre empleado por pantalla
 *
 * \param nombre char*
 * \return int
 *
 */
int pedirNombreEmpleado(char * nombre)
{
    if(nombre == NULL)
        return ERROR_PARAMETRO_INVALIDO;

    printf("Ingrese nombre empleado:\n");
    fflush(stdin);
    gets(nombre);
    while(justString(nombre) == ERROR_CARACTER_INVALIDO)
    {
        printf("Reingrese nombre: \n");
        gets(nombre);
    }

    return OK;
}

/** \brief Pide horas trabajadas del empleado por pantalla
 *
 * \param horasTrabajadas char*
 * \return int
 *
 */
int pedirHorasTrabajadasEmpleado(char * horasTrabajadas)
{
    if(horasTrabajadas == NULL)
        return ERROR_PARAMETRO_INVALIDO;

    printf("Ingrese horas trabajadas empleado:\n");
    fflush(stdin);
    gets(horasTrabajadas);
    while(justNumeric(horasTrabajadas) == ERROR_DIGITO_INVALIDO)
    {
        printf("Reingrese horas trabajadas: \n");
        scanf("%s", horasTrabajadas);
    }

    return OK;
}

/** \brief Pide sueldo del empleado por pantalla
 *
 * \param sueldo char*
 * \return int
 *
 */
int pedirSueldoEmpleado(char * sueldo)
{
    if(sueldo == NULL)
        return ERROR_PARAMETRO_INVALIDO;

    printf("Ingrese sueldo empleado:\n");
    fflush(stdin);
    gets(sueldo);
    while(justNumeric(sueldo) == ERROR_DIGITO_INVALIDO)
    {
        printf("Reingrese sueldo: \n");
        scanf("%s", sueldo);
    }

    return OK;
}

/** \brief Pide id del empleado por pantalla
 *
 * \param id char*
 * \return int
 *
 */
int pedirIdEmpleado(char* id)
{
    if(id == NULL)
        return ERROR_PARAMETRO_INVALIDO;

    printf("Ingrese id empleado:\n");
    fflush(stdin);
    gets(id);
    while(justNumeric(id) == ERROR_DIGITO_INVALIDO)
    {
        printf("Reingrese id: \n");
        scanf("%s", id);
    }

    return OK;
}

/** \brief Pide todos los datos del empleado por pantalla
 *
 * \param id char*
 * \param nombre char*
 * \param horasTrabajadas char*
 * \param sueldo char*
 * \return int
 *
 */
int pedirDatosEmpleado(char* id, char* nombre, char* horasTrabajadas, char* sueldo){

    pedirIdEmpleado(id);

    pedirNombreEmpleado(nombre);

    pedirHorasTrabajadasEmpleado(horasTrabajadas);

    pedirSueldoEmpleado(sueldo);

    return OK;

}

/** \brief Modificar datos de empleado
 *
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_editEmployee(LinkedList* pArrayListEmployee)
{
    char nombre[MAX_SIZE_NAME];
    char id[MAX_SIZE_ID];
    char sueldo[MAX_SIZE_SALARY];
    char horasTrabajadas[MAX_SIZE_WORKED_HOURS];

    if(pedirIdEmpleado(id) != OK)
        return ERROR_ID_INGRESADO_INCORRECTO;

    Employee* empleado = buscarEmpleadoPorId(pArrayListEmployee, atoi(id));
    if(empleado == NULL)
        return ERROR_EMPLEADO_NO_ENCONTRADO;

    int option;

    do
    {
        showMenuEmpleadoModificar();
        scanf("%d", &option);
        switch(option)
        {
            case MODIFICAR_NOMBRE:
                if(pedirNombreEmpleado(nombre) != OK)
                    break;
                employee_setNombre(empleado, nombre);
                break;

            case MODIFICAR_HORAS_TRABAJADAS:
                if(pedirHorasTrabajadasEmpleado(horasTrabajadas) != OK)
                   break;
                employee_setHorasTrabajadas(empleado, atoi(horasTrabajadas));
                break;

            case MODIFICAR_SALARIO:
                if(pedirSueldoEmpleado(sueldo) != OK)
                    break;
                employee_setSueldo(empleado, atoi(sueldo));
                break;

            case MODIFICAR_SALIR:
                printf("Programa finalizado\n");
                break;
            default:
                printf("Opcion ingresada no valida\n");
                break;
        }

    }while(option != MODIFICAR_SALIR);
    // imprimir todos los valores del empleado encontrado
    // preguntar al usuario que quiere modificar
    // 1-nombre, 2-horastrabajadas, 3-sueldo, 4-salir

    // char nombre[32];
    //si elige 1 entonces llamar a pedirNombreEmpleado(nombre);

    return OK;
}

/** \brief Busca al empleado por el id
 *
 * \param pArrayListEmployee LinkedList*
 * \param id int
 * \return int
 *
 */
Employee* buscarEmpleadoPorId(LinkedList* pArrayListEmployee, int id)
{
    if(pArrayListEmployee == NULL)
        return NULL;

    if(id <= 0 || id > TAMANIO_MAXIMO_ID)
        return NULL;

    Employee* empleado = NULL;
    for(int index = 0; index < pArrayListEmployee->size; index++)
    {
        empleado = (Employee*)ll_get(pArrayListEmployee, index);
        if(empleado == NULL)
            continue;
        if(empleado->id == id)
            break;
    }

    return empleado;
}

/** \brief Busca al empleado por salario
 *
 * \param pArrayListEmployee LinkedList*
 * \param sueldo int
 * \return int
 *
 */
LinkedList* buscarEmpleadosPorSalario(LinkedList* pArrayListEmployee, int sueldo)
{
    LinkedList* linkedList = ll_newLinkedList();
    Employee* empleado = NULL;
    for(int index = 0; index < pArrayListEmployee->size; index++)
    {
        empleado = (Employee*)ll_get(pArrayListEmployee, index);
        if(empleado == NULL)
            continue;
        if(empleado->sueldo == sueldo)
           ll_add(linkedList, empleado);
    }

    return linkedList;
}

/** \brief Baja de empleado
 *
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_removeEmployee(LinkedList* pArrayListEmployee)
{
    char id[MAX_SIZE_ID];
    pedirIdEmpleado(id);
    Employee* empleado = buscarEmpleadoPorId(pArrayListEmployee, atoi(id));
    if(empleado == NULL)
        return ERROR_EMPLEADO_NO_ENCONTRADO;

    int index = ll_indexOf(pArrayListEmployee, empleado);
    ll_remove(pArrayListEmployee, index);

    return OK;
}

/** \brief Listar empleados
 *
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */

int controller_ListEmployee(LinkedList* pArrayListEmployee)
{
    if(pArrayListEmployee == NULL)
        return ERROR_PARAMETRO_INVALIDO;

    Employee* emp;
    for(int i = 0; i < ll_len(pArrayListEmployee); i++){
        emp = (Employee*)ll_get(pArrayListEmployee, i);
        imprimirEmpleado(emp);
    }
    return OK;
}

/** \brief Imprime un solo empleado
 *
 * \param empleado Empleado*
 * \return int
 *
 */
void imprimirEmpleado(Employee* empleado)
{
    if(empleado == NULL)
        return;

    printf("%d-%s-%d-%d\n", empleado->id, empleado->nombre, empleado->horasTrabajadas, empleado->sueldo);
}

/** \brief Ordenar empleados
 *
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_sortEmployee(LinkedList* pArrayListEmployee)
{
    //TODO: mostrar menu para pedir que ordenamiento quiere
    int opcion;
    int tipoDeOrdenamiento;

    showMenuOrdenamiento();
    scanf("%d", &opcion);
    if(opcion == SALIR_DE_ORDENAR)
        return SALIR_DE_ORDENAR;
    showMenuTipoDeOrdenamiento();
    scanf("%d", &tipoDeOrdenamiento);
    switch(opcion)
        {
        case ORDENAR_POR_NOMBRE:
            if(tipoDeOrdenamiento == ERROR_TIPO_ORDENAMIENTO_INVALIDO)
                break;
            else
                ll_sort(pArrayListEmployee, &ordenarPorNombre, 0);
            break;
        case ORDENAR_POR_SUELDO:
            if(tipoDeOrdenamiento == -1)
                break;
            else
                ll_sort(pArrayListEmployee, &ordenarPorSueldo, 0);
            break;
        case ORDENAR_POR_HORAS_TRABAJADAS:
            if(tipoDeOrdenamiento == SALIR_DE_ORDENAR)
                break;
            else
                ll_sort(pArrayListEmployee, &ordenarPorHorasTrabajadas, tipoDeOrdenamiento);
            break;
        case ORDENAR_POR_ID:
            if(tipoDeOrdenamiento == SALIR_DE_ORDENAR)
                break;
            else
                ll_sort(pArrayListEmployee, &ordenarPorId, tipoDeOrdenamiento);
            break;
        case SALIR_DE_ORDENAR:
            return OK;
        default:
            printf("No eligio una opcion valida");
        }
    return OK;
}

/** \brief Ordenar empleados por nombre
 *
 * \param parametro1 void*
 * \param parametro2 void*
 * \return int
 *
 */
int ordenarPorNombre(void* parametro1, void* parametro2)
{
    Employee* empleado1 = (Employee*)parametro1;
    Employee* empleado2 = (Employee*)parametro2;

    return strcmp(empleado1->nombre, empleado2->nombre);
}

/** \brief Ordenar empleados por sueldo
 *
 * \param parametro1 void*
 * \param parametro2 void*
 * \return int
 *
 */
int ordenarPorSueldo(void* parametro1, void* parametro2)
{
    Employee* empleado1 = (Employee*)parametro1;
    Employee* empleado2 = (Employee*)parametro2;

    if(empleado1->sueldo > empleado2->sueldo)
        return 1;
    else if(empleado1->sueldo < empleado2->sueldo)
        return -1;
    else
        return 0;
}

/** \brief Ordenar empleados por horas trabajadas
 *
 * \param parametro1 void*
 * \param parametro2 void*
 * \return int
 *
 */
int ordenarPorHorasTrabajadas(void* parametro1, void* parametro2)
{
    Employee* empleado1 = (Employee*)parametro1;
    Employee* empleado2 = (Employee*)parametro2;

    if(empleado1->horasTrabajadas > empleado2->horasTrabajadas)
        return 1;
    else if(empleado1->horasTrabajadas < empleado2->horasTrabajadas)
        return -1;
    else
        return 0;
}

/** \brief Ordenar empleados por id
 * \param parametro1 void*
 * \param parametro2 void*
 * \return int
 *
 */
int ordenarPorId(void* parametro1, void* parametro2)
{
    Employee* empleado1 = (Employee*)parametro1;
    Employee* empleado2 = (Employee*)parametro2;

    if(empleado1->id > empleado2->id)
        return 1;
    else if(empleado1->id < empleado2->id)
        return -1;
    else
        return 0;
}

/** \brief Guarda los datos de los empleados en el archivo data.csv (modo texto).
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_saveAsText(char* path , LinkedList* pArrayListEmployee)
{
    char nombre[32];
    int id;
    int horasTrabajadas;
    int sueldo;
    int cantidadEscrita;
    Employee* empleado;
    FILE* pFile = NULL;
    pFile = fopen(path, "w");
    if(pFile == NULL)
        return ERROR_ABRIR_ARCHIVO;

    fprintf(pFile, "id,nombre,horas,sueldo\n");
    for(int i = 0; i < ll_len(pArrayListEmployee); i++)
    {
        empleado = ll_get(pArrayListEmployee, i);
        employee_getId(empleado, i);
        employee_getNombre(empleado, nombre);
        employee_getHorasTrabajadas(empleado, horasTrabajadas);
        employee_getSueldo(empleado, sueldo);
        cantidadEscrita = fscanf(pFile, "%d,%s,%d,%d", id, nombre, horasTrabajadas, sueldo);
    }

    if(cantidadEscrita != 1)
        fclose(pFile);
        return ERROR_AL_GUARDAR_ARCHIVO_TEXTO;

    fclose(pFile);

    return OK;
}

/** \brief Guarda los datos de los empleados en el archivo data.csv (modo binario).
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_saveAsBinary(char* path , LinkedList* pArrayListEmployee)
{
    int cantidadGuardada;
    Employee* empleado;
    FILE* pFile = NULL;
    pFile = fopen(path, "wb");
    if(pFile == NULL)
        return ERROR_ABRIR_ARCHIVO;

    for(int i = 0; i < ll_len(pArrayListEmployee); i++)
    {
        empleado = ll_get(pArrayListEmployee, i);
        cantidadGuardada = fwrite(empleado, sizeof(Employee), 1, pFile);
    }
    if(cantidadGuardada != 1)
        fclose(pFile);
        return ERROR_AL_GUARDAR_ARCHIVO_BINARIO;

    fclose(pFile);

    return 1;
}
