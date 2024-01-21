#include <bits/stdc++.h>
using namespace std;

long long power(long long a, long long b, long long c)
{
	return (long long)pow(a, b) % c;
}

int main()
{
	long long g, n, x, y, A, B, k1, k2;
	
	g = 23;
	n = 47;
	cout << "The public keys g and n are: " << g << " and " << n << " respectively" << endl;

	cout << "Alice private key: "; cin >> x; 
	cout << x << endl;

	A = power(g, x, n);
	cout << A << " is sent to Bob" << endl;

	cout << "Bob private key: "; cin >> y; 
	cout << y << endl;

	B = power(g, y, n);
	cout << B << " is sent to Alice" << endl;

	k1 = power(B, x, n);
	k2 = power(A, y, n);
	
	cout << "Secret key for Alice is: " << k1 << endl;
	cout << "Secret key for Bob is: " << k2 << endl;

	return 0;
}
