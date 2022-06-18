'''
Elimina duplicados de una matriz y devuelve la cantidad de elementos.
Se ejecuta en tiempo medio O(N log N) y no se hace uso de API.
'''

def quicksort(q_matriz):                
    menores = []
    iguales = []
    mayores = []
    if len(q_matriz) > 1:
        pivote = q_matriz[0]
        for i in q_matriz:
            if i < pivote:
                menores.append(i)
            elif i == pivote:
                iguales.append(i)
            elif i > pivote:
                mayores.append(i)
        return quicksort(menores)+iguales+quicksort(mayores)
    else:
      return q_matriz
 
def clean(c_matriz):                
    if len(c_matriz) == 1:
        matriz.append(c_matriz[0])
        return matriz
    if c_matriz[0] == c_matriz[1]:
        return clean(c_matriz[1:])
    else:
        matriz.append(c_matriz[0])
        clean(c_matriz[1:])
        return matriz
 
matriz = []
A = [1,4,1,2,3,1,3] 

if len(A) > 1:
    print(len(clean(quicksort(A))))     
else:
    print ("Matriz vacía")