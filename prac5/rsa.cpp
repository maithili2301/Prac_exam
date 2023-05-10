

#include <bits/stdc++.h>
using namespace std;

// Returns gcd of a and b
int gcd(int a, int h)
{
	int temp;
	while (1) {
		temp = a % h;
		if (temp == 0)
			return h;
		a = h;
		h = temp;
	}
}

// Code to demonstrate RSA algorithm
int main()
{
	// Two random prime numbers
	double p;
	cout<<"Enter the first prime number p : ";
	cin>>p;
	
	double q;
    cout<<"Enter the second prime number q: ";
    cin>>q;
	// First part of public key:
	double n = p * q;
    cout<<"The value of n is : "<<n<<endl;
	// Finding other part of public key.
	// e stands for encrypt
	double e;
	cout<<"Enter the encryption key e: ";
	cin>>e;
	double phi = (p - 1) * (q - 1);
	cout<<"The value of phi is : "<<phi<<endl;
	while (e < phi) {
		// e must be co-prime to phi and
		// smaller than phi.
		if (gcd(e, phi) == 1)
			break;
		else
			e++;
	}

	// Private key (d stands for decrypt)
	// choosing d such that it satisfies
	// d*e = 1 + k * totient
	int k; // A constant value
	cout<<"Enter the constant value k : ";
	cin>>k;
	double d = (1 + (k * phi)) / e;

	// Message to be encrypted
	double msg;
	cout<<"Enter the message to be encrypted : ";
	cin>>msg;

	printf("Message data = %lf", msg);

	// Encryption c = (msg ^ e) % n
	double c = pow(msg, e);
	c = fmod(c, n);
	printf("\nEncrypted data = %lf", c);

	// Decryption m = (c ^ d) % n
	double m = pow(c, d);
	m = fmod(m, n);
	printf("\nOriginal Message Sent = %lf", m);

	return 0;
}