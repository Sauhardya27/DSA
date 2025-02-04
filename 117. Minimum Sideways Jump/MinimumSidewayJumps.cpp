#include <bits/stdc++.h>
using namespace std;

int solve(vector<int> &obs, int currLane, int currPos){
	int n = obs.size() - 1;

	if (currPos == n)
		return 0;

	if (obs[currPos + 1] != currLane)
		return solve(obs, currLane, currPos + 1);

	else{
		// Sideways jump
		int ans = INT_MAX;
		for (int i = 1; i <= 3; i++){
			if (i != obs[currPos + 1] && obs[currPos] != i) // If the lane where you want to jump is not the currLane and in that lane obstacle is not present
				ans = min(ans, 1 + solve(obs, i, currPos));
		}
		return ans;
	}
}

int solveMem(vector<int> &obs, int currLane, int currPos, vector<vector<int>> &dp){
	int n = obs.size() - 1;

	if (currPos == n)
		return 0;

	if (dp[currLane][currPos] != -1)
		return dp[currLane][currPos];

	if (obs[currPos + 1] != currLane)
		return solveMem(obs, currLane, currPos + 1, dp);

	else{
		// Sideways jump
		int ans = INT_MAX;
		for (int i = 1; i <= 3; i++)
		{
			if (i != obs[currPos + 1] && obs[currPos] != i) // If the lane where you want to jump is not the currLane and in that lane obstacle is not present
				ans = min(ans, 1 + solveMem(obs, i, currPos, dp));
		}
		dp[currLane][currPos] = ans;
		return dp[currLane][currPos];
	}
}

int minSideJumps(vector<int> &obstacles){
	// return solve(obstacles, 2, 0);

	vector<vector<int>> dp(4, vector<int>(obstacles.size(), -1)); // Taking 4 rows (0) when no obstacles is present in any lane
	return solveMem(obstacles, 2, 0, dp);
}