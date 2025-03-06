#include <bits/stdc++.h>
using namespace std;

int solveOpt(string& a, string& b) {
	int n1 = a.size();
	int n2 = b.size();

	vector<int> curr(n2 + 1, 0);
	vector<int> next(n2 + 1, 0);

	for (int i = n1 - 1; i >= 0; i--) {
		for (int j = n2 - 1; j >= 0; j--) {
			int ans = 0;

			if (a[i] == b[j])
				ans = 1 + next[j + 1];
			else
				ans = max(curr[j + 1], next[j]);

			curr[j] = ans;
		}
		next = curr;
	}
	return next[0];
}

int longestPalindromeSubseq(string s) {
	string revStr = s;
	reverse(s.begin(), s.end());
	return solveOpt(s, revStr);
}