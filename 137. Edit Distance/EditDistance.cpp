#include <bits/stdc++.h>
using namespace std;

int solve(string &a, string &b, int i, int j){
	if(i == a.length())
		return b.length() - j;

	if(j == b.length())
		return a.length() - i;

	int ans = 0;
	if(a[i] == b[j]){
		//Call for the remaining portions
		return solve(a, b, i+1, j+1);
	}
	else {
		//insert
		int insertAns = 1 + solve(a, b, i, j+1);
		//delete
		int deleteAns = 1 + solve(a, b, i+1, j);
		//replace
		int replaceAns = 1 + solve(a, b, i+1, j+1);

		ans = min({insertAns, deleteAns, replaceAns});
	}
	return ans;
}

int solveMem(string &a, string &b, int i, int j, vector<vector<int>> &dp){
	if(i == a.length())
		return b.length() - j;

	if(j == b.length())
		return a.length() - i;

	if(dp[i][j] != -1)
		return dp[i][j];

	int ans = 0;
	if(a[i] == b[j]){
		//Call for the remaining portions
		return solveMem(a, b, i+1, j+1, dp);
	}
	else {
		//insert
		int insertAns = 1 + solveMem(a, b, i, j+1, dp);
		//delete
		int deleteAns = 1 + solveMem(a, b, i+1, j, dp);
		//replace
		int replaceAns = 1 + solveMem(a, b, i+1, j+1, dp);

		ans = min({insertAns, deleteAns, replaceAns});
	}
	return dp[i][j] = ans;
}

int solveTab(string &a, string &b){
	int n1 = a.length();
	int n2 = b.length();

	vector<vector<int>> dp(n1+1, vector<int>(n2+1, 0));

	//base case
	for(int j=0; j<n2; j++)
		dp[n1][j] = n2 - j;

	for(int i=0; i<n1; i++)
		dp[i][n2] = n1 - i;

	for(int i=n1-1; i>=0; i--){
		for(int j=n2-1; j>=0; j--){
			int ans = 0;
			if(a[i] == b[j]){
				//Call for the remaining portions
				ans = dp[i+1][j+1];
			}
			else {
				//insert
				int insertAns = 1 + dp[i][j+1];
				//delete
				int deleteAns = 1 + dp[i+1][j];
				//replace
				int replaceAns = 1 + dp[i+1][j+1];

				ans = min({insertAns, deleteAns, replaceAns});
			}
			dp[i][j] = ans;
		}
	}
	return dp[0][0];
}

int solveOpt(string &a, string &b){
	int n1 = a.length();
	int n2 = b.length();

	vector<int> curr(n2+1, 0);
	vector<int> next(n2+1, 0);

	//base case
	for(int j=0; j<n2; j++)
		next[j] = n2 - j; //last index is denoted by next vector

	// for(int i=0; i<n1; i++)
	//     dp[i][n2] = n1 - i;

	for(int i=n1-1; i>=0; i--){
		for(int j=n2-1; j>=0; j--){
			//Catch for 2nd base case
			curr[n2] = n1 - i;

			int ans = 0;
			if(a[i] == b[j]){
				//Call for the remaining portions
				ans = next[j+1];
			}
			else {
				//insert
				int insertAns = 1 + curr[j+1];
				//delete
				int deleteAns = 1 + next[j];
				//replace
				int replaceAns = 1 + next[j+1];

				ans = min({insertAns, deleteAns, replaceAns});
			}
			curr[j] = ans;
		}
		next = curr;
	}
	return next[0];
}


int minDistance(string word1, string word2) {
	// return solve(word1, word2, 0, 0);
	// vector<vector<int>> dp(word1.size(), vector<int>(word2.size(), -1));
	// return solveMem(word1, word2, 0, 0, dp);
	// return solveTab(word1, word2);
	if(word1.empty())
		return word2.length();
	
	if(word2.empty())
		return word1.length();

	return solveOpt(word1, word2);
}