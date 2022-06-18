'''
Programa que simule la tirada de dados. 
Cada vez que ejecutamos el programa, éste elegirá dos números aleatorios entre el 1 y el 6.
El programa deberá imprimirlos en pantalla, imprimir su suma y preguntarle al usuario si quiere tirar los dados otra vez.
'''

import random

def tirar_dado():
    num1 = random.randint(1,6)
    num2 = random.randint(1,6)
    print ("Los números que salieron fueron:", num1, "y", num2)
    print ("La suma de los mismos es:", num1+num2)

def confirmacion():
    cont = True
    while cont:
        print("¿Desea tirar los dados nuevamente? Introduzca si o no")
        respuesta = input()
        if respuesta in ('si', 'sí', 'Si', 'Sí', 'SI', 'SÍ'):
            tirar_dado()
            cont = True
        elif respuesta in ('no', 'No', 'NO'):
            print("¡Gracias por participar!")
            cont = False
        else:
            print ("Respuesta incorrecta.")
            cont = True
    return cont    
    
tirar_dado()
confirmacion()