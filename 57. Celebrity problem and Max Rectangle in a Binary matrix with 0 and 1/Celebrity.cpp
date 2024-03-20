#include <iostream>
#include <stack>
#include <vector>
using namespace std;
class Solution 
{   private:
    bool knows(vector<vector<int> >& M, int a, int b){
        if(M[a][b] == 1)
            return 1;
        else
            return 0;
    }
    public:
    //Function to find if there is a celebrity in the party or not.
    int celebrity(vector<vector<int> >& M, int n) 
    {
        stack<int>s;
        for(int i=0; i<n; i++)
            s.push(i);
            
        while(s.size() > 1){
            int a = s.top();
            s.pop();
            
            int b = s.top();
            s.pop();
            
            if(knows(M, a, b))
                s.push(b);
            else
                s.push(a);
        }
        int ans = s.top();
        int zeroCount = 0;
        int oneCount = 0;
        
        for(int i=0; i<n; i++){
            if(M[ans][i] == 0)
                zeroCount++;
        }
        
        if(zeroCount != n)
            return -1;
            
        for(int i=0; i<n; i++){
            if(M[i][ans] == 1)
                oneCount++;
        }
        
        if(oneCount != n-1)
            return -1;
            
        return ans;
    }
};

int main(){
	Solution solution;
	vector<vector<int>> a = {{0, 1, 0}, {0, 0, 0}, {0, 1, 0}};
	cout << "Celebrity is: " << solution.celebrity(a, 3);
	return 0;
}