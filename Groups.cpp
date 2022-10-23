// CPP program to find n-th term of a recursive
// function using matrix exponentiation.
#include <bits/stdc++.h>
using namespace std;
#define MOD 1000000009

#define ll long long int

ll power(ll n)
{
	if (n <= 1)
		return 1;

	// This power function returns first row of
	// {Transformation Matrix}^n-1*Initial Vector
	n--;

	// This is an identity matrix.
	ll res[2][2] = { 1, 0, 0, 1 };

	// this is Transformation matrix.
	ll tMat[2][2] = { 2, 3, 1, 0 };

	// Matrix exponentiation to calculate power of {tMat}^n-1
	// store res in "res" matrix.
	while (n) {

		if (n & 1) {
			ll tmp[2][2];
			tmp[0][0] = (res[0][0] * tMat[0][0] + res[0][1] * tMat[1][0]) % MOD;
			tmp[0][1] = (res[0][0] * tMat[0][1] + res[0][1] * tMat[1][1]) % MOD;
			tmp[1][0] = (res[1][0] * tMat[0][0] + res[1][1] * tMat[1][0]) % MOD;
			tmp[1][1] = (res[1][0] * tMat[0][1] + res[1][1] * tMat[1][1]) % MOD;
			res[0][0] = tmp[0][0];
			res[0][1] = tmp[0][1];
			res[1][0] = tmp[1][0];
			res[1][1] = tmp[1][1];
		}
		n = n / 2;
		ll tmp[2][2];
		tmp[0][0] = (tMat[0][0] * tMat[0][0] + tMat[0][1] * tMat[1][0]) % MOD;
		tmp[0][1] = (tMat[0][0] * tMat[0][1] + tMat[0][1] * tMat[1][1]) % MOD;
		tmp[1][0] = (tMat[1][0] * tMat[0][0] + tMat[1][1] * tMat[1][0]) % MOD;
		tmp[1][1] = (tMat[1][0] * tMat[0][1] + tMat[1][1] * tMat[1][1]) % MOD;
		tMat[0][0] = tmp[0][0];
		tMat[0][1] = tmp[0][1];
		tMat[1][0] = tmp[1][0];
		tMat[1][1] = tmp[1][1];
	}

	// res store {Transformation matrix}^n-1
	// hence will be first row of res*Initial Vector.
	return (res[0][0] * 1 + res[0][1] * 1) % MOD;
}

// Driver code
int main()
{
	ll n = 3;
	cout << power(n);
	return 0;
}

