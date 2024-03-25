#include <bits/stdc++.h> 
#include <queue>
#include <vector>
using namespace std;
long long int sumOfMaxAndMin(vector<int> &arr, int n, int k) {
	long long int ans = 0;
	deque<int>maxi(k);
	deque<int>mini(k);

	for(int i=0; i<k; i++){
		while(!maxi.empty() && arr[maxi.back()] <= arr[i])
			maxi.pop_back();

		while(!mini.empty() && arr[mini.back()] >= arr[i])
			mini.pop_back();

		maxi.push_back(i);
		mini.push_back(i);
	}

	ans += arr[maxi.front()] + arr[mini.front()];

	for(int i=k; i<n; i++){
		//removal of element
		while(!maxi.empty() && i-maxi.front() >= k)
			maxi.pop_front();

		while(!mini.empty() && i-mini.front() >= k)
			mini.pop_front();

		//addition of element
		while(!maxi.empty() && arr[maxi.back()] <= arr[i])
			maxi.pop_back();

		while(!mini.empty() && arr[mini.back()] >= arr[i])
			mini.pop_back();

		maxi.push_back(i);
		mini.push_back(i);

		ans += arr[maxi.front()] + arr[mini.front()];
	}
	return ans;
}

int main(){
	vector<int> arr1 = {1, 2, 3, 4, 5};
	vector<int> arr2 = {2, 4, 7, 3, 8, 1};

	cout << "Sum of max and min for 1st array is: " << sumOfMaxAndMin(arr1, 5, 3) << endl;
	cout << "Sum of max and min for 2nd array is: " << sumOfMaxAndMin(arr2, 6, 4) << endl;
	return 0;
}
