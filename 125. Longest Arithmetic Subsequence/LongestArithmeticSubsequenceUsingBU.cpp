#include <bits/stdc++.h>
using namespace std;

int lengthOfLongestAP(vector<int>& arr) {
	int n = arr.size();
	if(n <= 2)
		return n;
	
	unordered_map<int, int> dp[n+1];
	int ans = 0;
	
	//Here dp[j][diff] represents the cnt of AP with difference = diff till i
	//exclusive of i. Then we update dp[i][diff] by considering the curr diff
	for(int i=1; i<n; i++){
		for(int j=0; j<i; j++){
			int diff = arr[i] - arr[j];
			int cnt = 1;
			
			if(dp[j].count(diff))
				cnt = dp[j][diff];
				
			dp[i][diff] = 1 + cnt;
			ans = max(ans, dp[i][diff]);
		}
	}
	return ans;
}

//Write the code for space optimized solution in O(n) using the formula (a+c)/2 = b