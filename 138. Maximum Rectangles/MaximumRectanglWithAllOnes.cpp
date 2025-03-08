#include <bits/stdc++.h>
using namespace std;

//Using the code for largest rectangle in histogram
vector<int> nextSmallerElements(vector<int>arr, int n){
	stack<int>s;
	s.push(-1);
	vector<int> ans(n);

	for(int i=n-1; i>=0; i--){
		int curr = arr[i];
		while(s.top() != -1 && arr[s.top()] >= curr)
			s.pop();
		ans[i] = s.top();
		s.push(i);
	}
	return ans;
}

vector<int> prevSmallerElements(vector<int>arr, int n){
	stack<int>s;
	s.push(-1);
	vector<int> ans(n);

	for(int i=0; i<n; i++){
		int curr = arr[i];
		while(s.top() != -1 && arr[s.top()] >= curr)
			s.pop();
		ans[i] = s.top();
		s.push(i);
	}
	return ans;
}

int largestRectangleArea(vector<int>& heights) {
	int n = heights.size();

	vector<int> next(n);
	next = nextSmallerElements(heights, n);

	vector<int> prev(n);
	prev = prevSmallerElements(heights, n);

	int area = INT_MIN;

	for(int i=0; i<n; i++){
		int l = heights[i];

		if(next[i] == -1)
			next[i] = n;

		int b = next[i] - prev[i] - 1;
		int newArea = l*b;
		area = max(area, newArea);
	}
	return area;
}

int maximalRectangle(vector<vector<char>>& matrix) {
	vector<int> histogram(matrix[0].size(), 0);
	int maxi = INT_MIN;

	for(int i=0; i<matrix.size(); i++){
		//creating the histogram array for each row
		for(int j=0; j<matrix[0].size(); j++){
			if(matrix[i][j] == '1')
				histogram[j]++;
			else
				histogram[j] = 0;
		}
		maxi = max(maxi, largestRectangleArea(histogram));
	}
	return maxi;
}