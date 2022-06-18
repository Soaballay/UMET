'''
Utiliza las palabras leídas desde un archivo y devuelve las que son anagramas.

Entrada:
frase amarillo caro roca fresa azul meta rojo mate tema roma rosa amor mora violeta ramo

Salida:
['caro', 'roca']
['frase', 'fresa']
['meta', 'mate', 'tema']
['roma', 'amor', 'mora', 'ramo']
'''

from collections import defaultdict

def leer(documento):
    doc = open(documento, 'r')
    palabras = doc.read().split()
    doc.close()
    if len (palabras) > 1:
        (diccionario(palabras))
    else:
        print("Documento vacío")

def diccionario(palabra):
    for w in palabra:
        s_w = ''.join(sorted(w))
        dic[s_w].append(w)
    anagramas()
    
def anagramas():
    keys = dic.keys()
    for a in keys:
        valor = dic.get(a)
        if len(valor) > 1:
            print (dic[a])

dic = defaultdict(list)

leer('datos.txt')