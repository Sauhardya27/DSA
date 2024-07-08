#include <iostream>
using namespace std;

int mySqrt(int x){
	int s = 0, e = x;
	long long int ans;

	while (s <= e){
		long long int mid = s + (e - s) / 2;
		long long int sq = mid * mid;
		if (sq == x)
			return mid;
		else if (sq < x){
			ans = mid;
			s = mid + 1;
		}
		else
			e = mid - 1;
	}
	return ans;
}

double morePrecision(int x, int precision, int sq){
	double factor = 1, ans = sq;
	for(int i=0; i<precision; i++){
		factor /= 10;
		for(double j=sq; j*j<x; j+= factor){
			ans = j;
		}
	}
	return ans;
}

int main(){
	int x = 3;
	cout << "Sq root of -> " << morePrecision(x, 3, mySqrt(3)) << endl;
	return 0;
}