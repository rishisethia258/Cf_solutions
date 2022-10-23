// C++ program for the above approach

#include <bits/stdc++.h>
using namespace std;

// Recursive function to find Nth term
int nthTerm(int N)
{
	// Base Case
	if (N == 1) {
		return 2;
	}

	// Recursive Call according to
	// Nth term of the series
	return ((N - 1) * 13)
		+ nthTerm(N - 1);
}

// Driver Code
int main()
{
	// Input Nth term
	int N = 17;

	// Function call
	cout << nthTerm(N) << endl;
	return 0;
}

