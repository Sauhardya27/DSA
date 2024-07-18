#include <iostream>
#include <vector>
using namespace std;

double myPow(double x, int n){
	double res = 1.0;
	long long num = n;

	if (n < 0){
		x = 1 / x;
		num = -num;
	}

	while (num > 0){
		if (num & 1){
			// n is odd
			res = res * x;
		}
		x = x * x;
		num = num >> 1;
	}
	return res;
}

int main(){
	cout << "2^10 : " << myPow(2.10000, 3) << endl;
	return 0;
}