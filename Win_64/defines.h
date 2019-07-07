#ifndef DEFINES_H
#define DEFINES_H

    #define CARGARTXT 1
    #define CARGARBIN 2
    #define ALTA 3
    #define MODIFICACION 4
    #define BAJA 5
    #define LISTAR 6
    #define ORDENAR 7
    #define GUARDARTXT 8
    #define GUARDARBIN 9
    #define SALIR 10

    #define PATHFILES files/
    #define FILENAME data.csv


    #define OK 1

    // defino los errores
    #define ERROR_ABRIR_ARCHIVO                 -1
    #define ERROR_LEER_ARCHIVO                  -2
    #define ERROR_GUARDAR_ARCHIVO               -3
    #define ERROR_PARAMETRO_INVALIDO            -4
    #define ERROR_MEMORIA_NO_DISPONIBLE         -5
    #define ERROR_ID_INVALIDO                   -6
    #define ERROR_CARACTER_INVALIDO             -7
    #define ERROR_NOMBRE_INVALIDO               -8
    #define ERROR_HORAS_TRABAJADAS_INVALIDA     -9
    #define ERROR_SUELDO_INVALIDO               -10
    #define ERROR_DIGITO_INVALIDO               -11
    #define ERROR_PEDIR_DATOS_EMPLEADO          -12
    #define ERROR_EMPLEADO_NO_ENCONTRADO        -13
    #define ERROR_ID_INGRESADO_INCORRECTO       -14
    #define ERROR_TIPO_ORDENAMIENTO_INVALIDO    -15
    #define ERROR_AL_GUARDAR_ARCHIVO_BINARIO    -16
    #define ERROR_AL_GUARDAR_ARCHIVO_TEXTO      -17

    #define TAMANIO_MAXIMO_ID                   9000
    #define TAMANIO_MAXIMO_HORAS_TRABAJADAS     360

    #define MODIFICAR_NOMBRE                1
    #define MODIFICAR_HORAS_TRABAJADAS      2
    #define MODIFICAR_SALARIO               3
    #define MODIFICAR_SALIR                 4

    #define MAX_SIZE_NAME           32
    #define MAX_SIZE_ID             8
    #define MAX_SIZE_SALARY         10
    #define MAX_SIZE_WORKED_HOURS   3

    #define ORDENAMIENTO_DESCENDENTE    0
    #define ORDENAMIENTO_ASCENDENTE     1

    #define ORDENAR_POR_NOMBRE              1
    #define ORDENAR_POR_SUELDO              2
    #define ORDENAR_POR_HORAS_TRABAJADAS    3
    #define ORDENAR_POR_ID                  4
    #define SALIR_DE_ORDENAR                5
#endif
