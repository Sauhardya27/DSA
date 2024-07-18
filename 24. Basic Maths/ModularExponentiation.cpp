#include <iostream>
#include <vector>
using namespace std;

int modularExponentiation(int x, int n, int m){
	int res = 1;
	while (n > 0){
		if (n & 1){
			// If exponent is odd
			res = (1LL * res * (x) % m) % m; // 1LL is the suffix of long long
		}
		x = (1LL * (x) % m * (x) % m) % m;
		n = n >> 1;
	}
	return res;
}

int main(){
	cout << modularExponentiation(4, 3, 10) << endl;
	return 0;
}