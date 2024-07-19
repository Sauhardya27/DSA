#include <iostream>
using namespace std;

double power(int a, int b){
	if(b == 0)
		return 1;

	if(b == 1)
		return a;

	double ans = power(a, b/2);
	if(b&1)
		return ans*ans*a;
	else	
		return ans*ans;
}

int main(){
	cout << "2^8 : " << power(2, 8) << endl;
	return 0;
}