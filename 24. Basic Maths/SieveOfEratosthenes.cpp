#include <iostream>
#include <vector>
using namespace std;

int countPrimes(int n){
	// Sieve of Eratosthenes
	int count = 0;
	vector<bool> prime(n + 1, true);

	prime[0] = prime[1] = false;

	for (int i = 2; i < n; i++){ //2 to i*i <=n
		if (prime[i]){
			count++;

			for (int j = 2 * i; j < n; j += i) //i*i to <=n
				prime[j] = false;
		}
	}
	return count;
}

int main(){
	cout << "No. of prime numbers between 0-100: " << countPrimes(100) << endl;
	return 0;
}