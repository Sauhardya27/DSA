#include <iostream>
#include <stack>
#include <vector>
#include <limits.h>
using namespace std;

class Solution {
private:
    vector<int> nextSmallerElements(vector<int> arr, int n){   
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

    vector<int> prevSmallerElements(vector<int> arr, int n){
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
        
    int largestRectangleArea(vector<int> heights, int n) {
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
public:
    int maximalRectangle(vector<vector<char>>& matrix) {
        vector<vector<int>>v;
        int n = matrix.size();
        int m = matrix[0].size();

        for(int i=0; i<n; i++){
            vector<int>t;
            for(int j=0; j<m; j++)
                t.push_back(matrix[i][j] - '0');

            v.push_back(t);
        }

        int area = largestRectangleArea(v[0], m);
            
        for(int i=1; i<n; i++){
            for(int j=0; j<m; j++){
                if(v[i][j] != 0)
                    v[i][j] += v[i-1][j];
                else
                    v[i][j] = 0;
            }
                
            area = max(area, largestRectangleArea(v[i], m));
        }
        return area;
    }
};

int main(){
	Solution solution;
	vector<vector<char>> mat = {{'1','0','1','0','0'}, {'1','0','1','1','1'},{'1','1','1','1','1'},{'1','0','0','1','0'}};

	cout << "Maximum area of rectangle possible in the given matrix = " << solution.maximalRectangle(mat) << " sq units" << endl;
	return 0;
}