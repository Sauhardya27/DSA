#include <iostream>
#include <vector>
using namespace std;

int findPivot(vector<int>& arr, int n){
	int s=0, e=n-1;
	while(s<e){
		int mid = (s+e)/2;
		if(arr[mid] >= arr[0])
			s = mid+1;
		else	
			e = mid;
	}
	return s;
}

int main(){
	vector<int>arr = {3, 8, 10, 17, 1};
	cout << "Pivot Index -> " << findPivot(arr, 5) << endl;
	return 0;
}