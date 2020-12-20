// CPP implementation for recursive 
// approach to find the number of set 
// bits using Brian Kernighan’s Algorithm 
#include <bits/stdc++.h> 
using namespace std; 

// recursive function to count set bits 
int countSetBits(int n) 
{ 
	// base case 
	if (n == 0) 
		return 0; 
	else
		return 1 + countSetBits(n & (n - 1)); 
} 

// driver code 
int main() 
{ 
	// get value from user 
	int n = 9; 
	int x =  countSetBits(n);

	// function calling 
	cout << x*2;

	return 0; 
} 

// This code is contributed by Raj. 
