# UTNAlgoritmosCPP
Trabajos Practicos de la UTN 

______________________Contexto del proyecto:__________________________

Una empresa de viajes aéreos solicita el desarrollo de un programa que le permita procesar la información de reservas semanales, para ello cuenta con un archivo RESERVAS.DAT que posee la siguiente estructura:

cod_ciudad (0..99) cod_dia(0..6) DNI (integer)

Por razones de optimización en el uso de recursos solo se permite una lectura secuencial del archivo, para proceder a volcar los datos en un array de 2 dimensiones de forma que cod_ciudad quede dispuesto en el indice de filas y cod_dia quede dispuesto en el indice de columnas.



__________________________Requerimientos:_______________________________

Se debe desarrollar una aplicación en lenguaje C/C++ que despliega un menú con las
siguientes opciones:
● Cargar archivo
● Procesar archivo
● Emitir reporte
● Salir


Par cumplir con el objetivo se deben desarrollar las siguientes funciones:


1) La función cargar_archivo: debe recibir a través de sus parámetros el archivo abierto RESERVAS.DAT, y solicitarle al usuario que ingrese los datos para grabar en el mismo.
2) La función procesar_archivo: que tiene dos parámetros, de entrada el archivo que se generó en el punto anterior, y de salida la matriz donde se cargarán los punteros.
3) La función emitir_reporte: que recibe la matriz creada en el punto anterior e imprime por pantalla un listado ordenado por cod_ciudad ascendente, con la cantidad total de reservas efectuadas para cada ciudad.