#include <bits/stdc++.h>
using namespace std;

bool solve(string &s, string &p, int i, int j){
	if(i<0 && j<0)
		return true;

	if(i>=0 && j<0)
		return false;

	if(i<0 && j>=0){
		for(int k=0; k<=j; k++){
			if(p[k] != '*')
				return false;
		}
		return true;
	}

	//match
	if(s[i] == p[j] || p[j] == '?')
		return solve(s, p, i-1, j-1);
	else if(p[j] == '*')
		return solve(s, p, i-1, j) || solve(s, p, i, j-1);
	else
		return false;
}

bool solveMem(string &s, string &p, int i, int j, vector<vector<int>> &dp){
	if(i<0 && j<0)
		return true;

	if(i>=0 && j<0)
		return false;

	if(i<0 && j>=0){
		for(int k=0; k<=j; k++){
			if(p[k] != '*')
				return false;
		}
		return true;
	}

	if(dp[i][j] != -1)
		return dp[i][j];

	//match
	if(s[i] == p[j] || p[j] == '?')
		return dp[i][j] = solveMem(s, p, i-1, j-1, dp);
	else if(p[j] == '*')
		return dp[i][j] = solveMem(s, p, i-1, j, dp) || solveMem(s, p, i, j-1, dp);
	else
		return false;
}

//For Bottom-Up approach convert 0-based indexing to 1-based indexing, 
//by increasing the size of the array by 1;
//(< 0 gets changed == 0), (<= and >= gets changed to < and >)
bool solveTab(string &s, string &p){
	vector<vector<bool>> dp(s.size()+1, vector<bool>(p.size()+1, 0));
	dp[0][0] = true;

	//other case is already handled

	for(int j=1; j<=p.size(); j++){
		bool flag = true;
		for(int k=1; k<=j; k++){
			if(p[k-1] != '*'){
				flag = false;
				break;
			}
		}
		dp[0][j] = flag;
	}

	for(int i=1; i<=s.size(); i++){
		for(int j=1; j<=p.size(); j++){
			if(s[i-1] == p[j-1] || p[j-1] == '?')
				dp[i][j] = dp[i-1][j-1];
			else if(p[j-1] == '*')
				dp[i][j] = dp[i-1][j] || dp[i][j-1];
			else
				dp[i][j] = false;
		}
	}
	return dp[s.size()][p.size()];
}

bool solveOpt(string &s, string &p){
	vector<bool> prev(p.size()+1, false);
	vector<bool> curr(p.size()+1, false);

	prev[0] = true;

	//other case is already handled

	for(int j=1; j<=p.size(); j++){
		bool flag = true;
		for(int k=1; k<=j; k++){
			if(p[k-1] != '*'){
				flag = false;
				break;
			}
		}
		prev[j] = flag;
	}

	for(int i=1; i<=s.size(); i++){
		for(int j=1; j<=p.size(); j++){
			if(s[i-1] == p[j-1] || p[j-1] == '?')
				curr[j] = prev[j-1];
			else if(p[j-1] == '*')
				curr[j] = prev[j] || curr[j-1];
			else
				curr[j] = false;
		}
		prev = curr;
	}
	return prev[p.size()];
}

bool isMatch(string s, string p) {
	// return solve(s, p, s.size()-1, p.size()-1);  
	// vector<vector<int>> dp(s.size(), vector<int>(p.size(), -1));
	// return solveMem(s, p, s.size()-1, p.size()-1, dp); 
	// return solveTab(s, p);
	return solveOpt(s, p); 
}