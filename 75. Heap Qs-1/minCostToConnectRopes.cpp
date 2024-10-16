#include <bits/stdc++.h>
using namespace std;

class Solution {
  public:
    long long minCost(vector<long long>& arr) {
        priority_queue<long long, vector<long long>, greater<long long>> pq;
        long long cost = 0;
        
        for(int i=0; i<arr.size(); i++)
            pq.push(arr[i]);
            
        while(pq.size() > 1){
            long long a = pq.top();
            pq.pop();
            
            long long b = pq.top();
            pq.pop();
            
            long long sum = a + b;
            cost += sum;
            pq.push(sum);
        }
        return cost;
    }
};

int main() {
    long long t;
    cin >> t;
    cin.ignore();
    while (t--) {
        string input;
        long long num;
        vector<long long> a;

        getline(cin, input);
        stringstream s2(input);
        while (s2 >> num) {
            a.push_back(num);
        }
        Solution ob;
        cout << ob.minCost(a) << endl;
    }
    return 0;
}