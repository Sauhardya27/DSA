#include <iostream>
#include <vector>
using namespace std;

vector<int> reverse(vector<int>& arr){
	int s = 0, e = arr.size() - 1;
	while(s<e)
		swap(arr[s++], arr[e--]);

	return arr;
}

vector<int> findArraySum(vector<int>&a, int n, vector<int>&b, int m) {
	int i = n-1, j = m-1;
	vector<int> ans;
	int carry = 0;

	while(i>=0 && j>=0){
		int sum = a[i] + b[j] + carry;
		carry = sum/10;
		sum = sum%10;
		ans.push_back(sum);
		i--; j--;
	}

	while(i>=0){
		int sum = a[i] + carry;
		carry = sum/10;
		sum = sum%10;
		ans.push_back(sum);
		i--;
	}

	while(j>=0){
		int sum = b[j] + carry;
		carry = sum/10;
		sum = sum%10;
		ans.push_back(sum);
		j--;
	}

	while(carry > 0){
		int sum = carry;
		carry = sum/10;
		//sum = sum%10;
		ans.push_back(sum);
	}

	return reverse(ans);
}

int main(){
	vector<int> arr1 = {1, 2, 3};
	vector<int> arr2 = {9, 9};

	vector<int> result = findArraySum(arr1, 3, arr2, 2);

	cout << "Resultant array: ";
	for(int i=0; i<result.size(); i++)
		cout << result[i] << " ";
	cout << endl;
	return 0;
}