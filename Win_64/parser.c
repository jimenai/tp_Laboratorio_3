#include <stdio.h>
#include <stdlib.h>
#include "LinkedList.h"
#include "Employee.h"
#include "defines.h"

/** \brief Parsea los datos los datos de los empleados desde el archivo data.csv (modo texto).
 *
 * \param pFile puntero al archivo abierto
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int parser_EmployeeFromText(FILE* pFile, LinkedList* pArrayListEmployee)
{
    if(pFile == NULL || pArrayListEmployee == NULL)
        return ERROR_PARAMETRO_INVALIDO;

    Employee * this = NULL;
    char idStr[6], nombreStr[50], horasTrabajadasStr[10], salarioStr[10];
    int cantidadLeida;

    while(!feof(pFile)){
        cantidadLeida = fscanf(pFile,"%[^,],%[^,],%[^,],%[^\n]\n", idStr, nombreStr, horasTrabajadasStr, salarioStr);
        if(cantidadLeida != 4){
            ll_deleteLinkedList(pArrayListEmployee);
            //fclose(pFile);
            return ERROR_LEER_ARCHIVO;
        }
        this = employee_newParametros(idStr, nombreStr, horasTrabajadasStr, salarioStr);
        ll_add(pArrayListEmployee, this);
    }

    fclose(pFile);

    return OK;
}

/** \brief Parsea los datos los datos de los empleados desde el archivo data.csv (modo binario).
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int parser_EmployeeFromBinary(FILE* pFile , LinkedList* pArrayListEmployee)
{
   if(pFile == NULL || pArrayListEmployee == NULL)
        return ERROR_PARAMETRO_INVALIDO;

    Employee * this = NULL;

    while(!feof(pFile))
    {
        this = employee_new();
        fread(this, sizeof(Employee), 1, pFile);
        ll_add(pArrayListEmployee, this);
    }


}
