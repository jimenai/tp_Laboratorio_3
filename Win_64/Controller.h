#include "Employee.h"
#ifndef CONTROLLER_H
    #define CONTROLLER_H

    int controller_loadFromText(char* path , LinkedList* pArrayListEmployee);
    int controller_loadFromBinary(char* path , LinkedList* pArrayListEmployee);
    int controller_addEmployee(LinkedList* pArrayListEmployee);
    int controller_editEmployee(LinkedList* pArrayListEmployee);
    int controller_removeEmployee(LinkedList* pArrayListEmployee);
    int controller_ListEmployee(LinkedList* pArrayListEmployee);
    int controller_sortEmployee(LinkedList* pArrayListEmployee);
    int controller_saveAsText(char* path , LinkedList* pArrayListEmployee);
    int controller_saveAsBinary(char* path , LinkedList* pArrayListEmployee);
    int pedirDatosEmpleado(char* id, char* nombre, char* horasTrabajadas, char* sueldo);
    int pedirNombreEmpleado(char* nombre);
    int pedirHorasTrabajadasEmpleado(char* horasTrabajadas);
    int pedirSueldoEmpleado(char* sueldo);
    int pedirSueldoEmpleado(char * sueldo);
    Employee* buscarEmpleadoPorId(LinkedList* pArrayListEmployee, int id);
    void imprimirEmpleado(Employee* empleado);
    int ordenarPorNombre(void* parametro1, void* parametro2);
    int ordenarPorSueldo(void* parametro1, void* parametro2);
    int ordenarPorHorasTrabajadas(void* parametro1, void* parametro2);
    int ordenarPorId(void* parametro1, void* parametro2);

#endif // CONTROLLER_H
