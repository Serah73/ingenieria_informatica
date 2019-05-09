import math

class ft_t:
	def __init__(self):
		self.N = 0
		self.v = 0
		self.a = 0
		self.e = 0
		self.s = 0

	def AskStart(self):
		print("Introduzca el valor 'p':")
		p = int(input())
		
		print("Introduzca el valor 'q':")
		q = int(input())

		print("Introduzca el valor 's':")
		self.s = int(input())

		self.N = p*q
		self.v = math.floor(math.fmod(math.pow(self.s, 2), self.N))

		print(f"Identificacion publica de A: {self.v}\n")

	def AskSecret(self):
		print(f"Introduce el valor de 'x':")
		return int(input())

	def Prime(self, a, b):
		if b > a:
			return False
		elif math.fmod(a, b) == 0:
			return False
		else:
			return True

	def Algorithm(self):
		x = self.AskSecret()
		self.a = math.floor(math.fmod( math.pow(x, 2), self.N))

		print("Escoge el valor de e: ")
		self.e = int(input())

		y = 0

		if self.e == 1:
			y = math.floor(math.fmod( (self.s*x), self.N))
		else:
			y = math.floor(math.fmod(x, self.N))

		return y

	def CheckPrime(self, primo):
		divisor = 1
		divisores = 0

		while True:
			if math.fmod( primo, divisor ) == 0:
				divisores += 1
			divisor += 1

			if divisores > 2:
				return False
			if not divisor <= primo:
				break

		if divisores == 2:
			return True

		else:
			return False

	def Check(self, y):
		dummy = 0

		if self.e == 0:
			dummy = math.floor(math.fmod(self.a, self.N))
		else:
			dummy = math.floor(math.fmod( (self.a*self.v), self.N))

		checkY = math.floor(math.fmod( math.pow(y, 2), self.N))

		if dummy == checkY:
			return True
		else:
			return False

	def Run(self):
		self.AskStart()

		print("Introduzca el numero de iteraciones:\n")
		maxIter = int(input())
		check = True
		i = 1

		while (i <= maxIter) and check:
			y = self.Algorithm()
			check = self.Check(y)

			print(f"{i}º iteracion:\n")
			print(f"\ta = {self.a}\n\ty = {y}\n")
			print(f"\tComprobando:\n")
			print(f"\t\t{y}² = {self.a} (mod {self.N})\n")

			if check:
				print("Se ha completado la iteracion correctamente\n\n")
			else:
				print("Ha sido erronea la comprobacion. Anulando el procedimiento\n")

			i += 1





def main():
	a = ft_t()
	a.Run()


if __name__ == '__main__':
	main()