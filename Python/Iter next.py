'''
ITERADOR QUE DEVUELVE LAS POSICIONES PARES DE UNA LISTA
El mensaje __iter__ devuelve un iterador, que debe ser un objeto que sepa responder el mensaje__next__. 
El mensaje __next__ devuelve el próximo elemento de lasecuencia.
'''

class Iterator:
	def __init__(self, data):
		self.data = data
		self.indice = 0

	def __iter__(self):
		return self

	def __next__(self):
		if self.indice >= len(self.data):
			raise StopIteration
		elem = self.data[self.indice]
		self.indice += 2
		return elem

it = Iterator([1,2,3,4,5])
for e in it:
	print(e)