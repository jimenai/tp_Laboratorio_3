#include <stdio.h>
#include <stdlib.h>
#include <windows.h>
#include "Employee.h"
#include "defines.h"
#include "validaciones.h"

Employee* employee_new(){
    return (Employee *)malloc(sizeof(Employee));
}


Employee* employee_newParametros(char* idStr, char* nombreStr, char* horasTrabajadasStr, char* salaryStr){
    if(idStr == NULL || nombreStr == NULL || horasTrabajadasStr == NULL || salaryStr == NULL)
        return ERROR_PARAMETRO_INVALIDO;

    Employee * this = employee_new();
    if(this == NULL)
        return ERROR_MEMORIA_NO_DISPONIBLE;

    employee_setId(this, atoi(idStr));
    employee_setNombre(this, nombreStr);
    employee_setHorasTrabajadas(this, atoi(horasTrabajadasStr));
    employee_setSueldo(this, atoi(salaryStr));

    return this;
}


int employee_setId(Employee* this, int id){

    if(this == NULL)
        return ERROR_PARAMETRO_INVALIDO;

    if(id <= 0)
        return ERROR_ID_INVALIDO;

    this->id = id;
    return OK;
}

int employee_getId(Employee* this, int * id){
    int state = 0;
    if(this != NULL)
    {
        *id = this->id;
        state = 1;
    }
    return state;
}

int employee_setNombre(Employee* this, char* nombre){
    if(this == NULL)
        return ERROR_PARAMETRO_INVALIDO;

    if(nombre == NULL || justString(nombre) != OK)
        return ERROR_NOMBRE_INVALIDO;

    strcpy(this->nombre, nombre);
    return OK;
}

int employee_getNombre(Employee* this, char* nombre){
    if(this == NULL)
        return ERROR_PARAMETRO_INVALIDO;

    strcpy(nombre, this->nombre);
    return OK;
}

int employee_setHorasTrabajadas(Employee* this, int horasTrabajadas){
   if(this == NULL)
        return ERROR_PARAMETRO_INVALIDO;

   if(horasTrabajadas <= 0 || horasTrabajadas >= 360)
        return ERROR_HORAS_TRABAJADAS_INVALIDA;

   this->horasTrabajadas = horasTrabajadas;
   return OK;
}

int employee_getHorasTrabajadas(Employee* this, int* horasTrabajadas){
    if(this == NULL || horasTrabajadas == NULL)
        return ERROR_PARAMETRO_INVALIDO;

    *horasTrabajadas = this->horasTrabajadas;
    return OK;
}

int employee_setSueldo(Employee* this, int sueldo){
    if(this == NULL)
        return ERROR_PARAMETRO_INVALIDO;

    if(sueldo <= 0)
        return ERROR_SUELDO_INVALIDO;
    this->sueldo = sueldo;
    return OK;
}

int employee_getSueldo(Employee* this,int* sueldo){
    if(this == NULL || sueldo == NULL)
        return ERROR_PARAMETRO_INVALIDO;

    *sueldo = this->sueldo;
    return OK;
}

void employee_delete(Employee * this){
    if(this != NULL){
        free(this);
        this = NULL;
    }
}

