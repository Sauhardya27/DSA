#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

bool isPossible(vector<int>& arr, int n, int k, int mid){
    int cowCount = 1, lastPos = arr[0];

    for(int i=0; i<n; i++){
        if(arr[i] - lastPos >= mid){
            cowCount++;
            if(cowCount == k)
                return true;
            lastPos = arr[i];
        }
    }
    return false;
}

int aggressiveCows(vector<int> &stalls, int k){
    int n = stalls.size();
    int s = 0;
    int ans = -1;
    int maxi = -1;

    sort(stalls.begin(), stalls.end());

    for(int i=0; i<n; i++){
        maxi = max(maxi, stalls[i]);
    }

    int e = maxi;

    while(s<=e){
        int mid = (s+e)/2;
        if(isPossible(stalls, n, k, mid)){
            ans = mid;
            s = mid + 1;
        }
        else    
            e = mid - 1;
    }
    return ans;
}

int main(){
	vector<int>arr = {0, 3, 4, 7, 10, 9};
	int k = 4;
	cout << "The maximum possible minimum distance -> " << aggressiveCows(arr, k) << endl;
	return 0;
}