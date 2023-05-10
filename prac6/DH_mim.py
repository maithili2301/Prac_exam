import random
from math import gcd
# public keys are taken
# p is a prime number
# g is a primitive root of p
from math import sqrt
def isPrime( n):
	# Corner cases
	if (n <= 1):
		return False
	if (n <= 3):
		return True

	if (n % 2 == 0 or n % 3 == 0):
		return False
	i = 5
	while(i * i <= n):
		if (n % i == 0 or n % (i + 2) == 0) :
			return False
		i = i + 6

	return True
""" Iterative Function to calculate (x^n)%p
	in O(logy) */"""
def power( x, y, p):
	res = 1 # Initialize result
	x = x % p # Update x if it is more
			# than or equal to p
	while (y > 0):
		if (y & 1):
			res = (res * x) % p
		y = y >> 1 # y = y/2
		x = (x * x) % p

	return res

def findPrimefactors(s, n) :

	while (n % 2 == 0) :
		s.add(2)
		n = n // 2
	for i in range(3, int(sqrt(n)), 2):
		while (n % i == 0) :
			s.add(i)
			n = n // i
	if (n > 2) :
		s.add(n)

lt = []
def findPrimitive( n) :
	s = set()

	if (isPrime(n) == False):
		return -1

	phi = n - 1

	findPrimefactors(s, phi)

	for r in range(2, phi + 1):

		flag = False
		for it in s:

			if (power(r, phi // it, n) == 1):

				flag = True
				break
		
		if (flag == False):
		    #print(r)
			lt.append(r)
			#return lt
		    #7 lt.append(r)

	return lt
p = int(input('Enter a prime number : '))
print('The primitive roots of prime number ',p,' are : ',findPrimitive(p)) 

g = int(input('Enter a primitive number from above list : '))
class A:
	def __init__(self):
		# Generating a random private number selected by alice
		self.n = random.randint(1, p)	
	def publish(self):
		# generating public values
		return (g**self.n)%p

	def compute_secret(self, gb):
		# computing secret key
		return (gb**self.n)%p

class B:
	def __init__(self):
		# Generating a random private number selected for alice
		self.a = random.randint(1, p)
		# Generating a random private number selected for bob
		self.b = random.randint(1, p)
		self.arr = [self.a,self.b]

	def publish(self, i):
		# generating public values
		return (g**self.arr[i])%p

	def compute_secret(self, ga, i):
		# computing secret key
		return (ga**self.arr[i])%p

alice = A()
bob = A()
eve = B()

# Printing out the private selected number by Alice and Bob
print(f'Alice selected (a) : {alice.n}')
print(f'Bob selected (b) : {bob.n}')
print(f'Eve selected private number for Alice (c) : {eve.a}')
print(f'Eve selected private number for Bob (d) : {eve.b}')

# Generating public values
ga = alice.publish()
gb = bob.publish()
gea = eve.publish(0)
geb = eve.publish(1)
print(f'Alice published (ga): {ga}')
print(f'Bob published (gb): {gb}')
print(f'Eve published value for Alice (gc): {gea}')
print(f'Eve published value for Bob (gd): {geb}')

# Computing the secret key
sa = alice.compute_secret(gea)
sea = eve.compute_secret(ga,0)
sb = bob.compute_secret(geb)
seb = eve.compute_secret(gb,1)
print(f'Alice computed (S1) : {sa}')
print(f'Eve computed key for Alice (S1) : {sea}')
print(f'Bob computed (S2) : {sb}')
print(f'Eve computed key for Bob (S2) : {seb}')