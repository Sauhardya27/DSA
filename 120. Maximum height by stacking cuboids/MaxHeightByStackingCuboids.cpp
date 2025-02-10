#include <bits/stdc++.h>
using namespace std;

bool check(vector<int> &base, vector<int> &newBox){
	if(newBox[0] <= base[0] && newBox[1] <= base[1] && newBox[2] <= base[2])
		return true;
	else
		return false;
}

int solveTab(int n, vector<vector<int>>& arr) {
	vector<int> currRow(n + 1, 0);
	vector<int> nextRow(n + 1, 0);

	for (int curr = n - 1; curr >= 0; curr--) {
		for (int prev = curr - 1; prev >= -1; prev--) {

			int take = 0;
			if (prev == -1 || check(arr[curr], arr[prev]))
				take = arr[curr][2] + nextRow[curr + 1];

			int dontTake = 0 + nextRow[prev + 1];

			currRow[prev + 1] = max(take, dontTake);
		}
		nextRow = currRow;
	}
	return nextRow[0];
}

int maxHeight(vector<vector<int>>& cuboids) {
	// Step 1: Sort all dimensions for each cuboid
	for (auto& a : cuboids)
		sort(a.begin(), a.end());

	// Step 2: Sort all cuboids based on their length or width
	sort(cuboids.begin(), cuboids.end());

	// Step 3: Apply LIS on the heights of each cuboid
	return solveTab(cuboids.size(), cuboids);
}