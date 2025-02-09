#include <bits/stdc++.h>
using namespace std;

int solveOptimal(int n, vector<int> &arr){
	if(n == 0)
		return 0;
		
	vector<int> ans;
	ans.push_back(arr[0]);
	
	for(int i=1; i<n; i++){
		if(arr[i] > ans.back())
			ans.push_back(arr[i]);
		else {
			int index = lower_bound(ans.begin(), ans.end(), arr[i]) - ans.begin();
			//Using binary search to find out the index to replace
			ans[index] = arr[i];
		}
	}
	return ans.size();
}

int maxEnvelopes(vector<vector<int>>& envelopes) {
	sort(envelopes.begin(), envelopes.end(), [](const vector<int>& a, const vector<int>& b) {
			if (a[0] == b[0])
				return a[1] > b[1]; 
				// If widths are equal, sort by height in decreasing order
			return a[0] < b[0]; // Otherwise, sort by width in increasing order
	});

	vector<int> heights;
	for (const auto& env : envelopes) {
		heights.push_back(env[1]);
	}

	return solveOptimal(heights.size(), heights);
}