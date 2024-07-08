#include <iostream>
#include <vector>
using namespace std;

int firstOcc(vector<int>& arr, int n, int k){
    int s = 0, e = n-1;
    int ans = -1;

    while(s<=e){
        int mid = (s+e)/2;
        if(arr[mid] == k){
            ans = mid;
            e = mid - 1;
        }
        else if(arr[mid] > k)
            e = mid - 1;
        else
            s = mid + 1;
    }
    return ans;
}

int lastOcc(vector<int>& arr, int n, int k){
    int s = 0, e = n-1;
    int ans = -1;
    
    while(s<=e){
        int mid = (s+e)/2;
        if(arr[mid] == k){
            ans = mid;
            s = mid + 1;
        }
        else if(arr[mid] > k)
            e = mid - 1;
        else
            s = mid + 1;
    }
    return ans;
}

pair<int, int> firstAndLastPosition(vector<int>& arr, int n, int k)
{
    pair<int, int> pos;
    pos.first = firstOcc(arr, n, k);
    pos.second = lastOcc(arr, n, k);

    return pos;
}

int main(){
	//Note to find no. of occurence of an element in O(log n) time, occurence = last occurence - first occurence + 1
	vector<int> arr1 = {0, 1, 1, 5};
	pair<int, int> pos = firstAndLastPosition(arr1, 4, 1);
	cout << "First occurence -> " << pos.first << " Second occurence -> " << pos.second << endl;
	
	return 0;
}
