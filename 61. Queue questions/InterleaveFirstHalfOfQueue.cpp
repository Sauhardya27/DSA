//{ Driver Code Starts
//Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function Template for C++
#include <stack>
class Solution{
public:
    vector<int> rearrangeQueue(queue<int> &q){
        int n = q.size();
        stack<int> s;
        vector<int> ans;
        
        for(int i=0; i<n/2; i++){
            s.push(q.front());
            q.pop();
        }
        
        while(!s.empty()){
            q.push(s.top());
            s.pop();
        }
        
        for(int i=0; i<n/2; i++){
            q.push(q.front());
            q.pop();
        }
        
        for(int i=0; i<n/2; i++){
            s.push(q.front());
            q.pop();
        }
        
        while(!s.empty()){
            int val = s.top();
            s.pop();
            ans.push_back(val);
            
            val = q.front();
            q.pop();
            ans.push_back(val);
        }
        return ans;
    }
};

//{ Driver Code Starts.

int main(){
    
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        
        queue<int> q;
        for(int i=0;i<n;i++){
            int a;
            cin>>a;
            q.push(a);
        }
        Solution ob;
        vector<int> ans=ob.rearrangeQueue(q);
        for(int i=0;i<ans.size();i++){
            cout<<ans[i]<<" ";
        }
        cout<<endl;
    }
    
    return 0;
}