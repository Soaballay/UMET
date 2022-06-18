# Imprime todas las permutaciones de los caracteres

def permutar(lista, fin=[]):
    if len(lista) == 0:
        print(fin)
    else:
        for i in range(len(lista)):
            permutar(lista[:i] + lista[i+1:], fin + lista[i:i+1])
 
permutar(['a','b','c'])