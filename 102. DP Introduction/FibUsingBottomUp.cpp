#include <bits/stdc++.h>
using namespace std;

int main(){
	int n;
	cin >> n;

	vector<int> dp(n + 1);
	dp[0] = 0;
	dp[1] = 1;

	for (int i = 2; i <= n; i++)
		dp[i] = dp[i - 1] + dp[i - 2];

	cout << dp[n] << endl;

	return 0;
}

int main(){
	int n;
	cin >> n;

	int prev1 = 0;
	int prev2 = 1;
	int curr;

	for (int i = 2; i <= n; i++){
		curr = prev1 + prev2;
		prev2 = prev1;
		prev1 = curr;
	}

	cout << prev1 << endl;

	return 0;
}