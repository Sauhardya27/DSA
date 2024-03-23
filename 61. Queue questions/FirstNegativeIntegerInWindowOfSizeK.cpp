#include <iostream>
#include <vector>
#include <queue>
using namespace std;

vector<long long> printFirstNegativeInteger(long long int A[], long long int N, long long int K) {
    deque<int> dq;
    vector<long long> ans;
    
    for(long long int i=0; i<K; i++){
        if(A[i] < 0)
            dq.push_back(i);
    }
    
    if(dq.size() > 0)
        ans.push_back(A[dq.front()]);
    else
        ans.push_back(0);
        
    for(long long int i=K; i<N; i++){
        if(!dq.empty() && i-dq.front() >= K)
            dq.pop_front();
            
        if(A[i] < 0)
            dq.push_back(i);
            
        if(dq.size() > 0)
            ans.push_back(A[dq.front()]);
        else
            ans.push_back(0);
    }
    return ans;
}

int main(){
	long long int A[] = {-8, 2, 3, -6, 10};
	vector<long long> ans = printFirstNegativeInteger(A, 5, 2);

	cout << "Output: ";
	for(int i=0; i<4; i++){
		cout << ans[i] << " ";
	}
	cout << endl;
	return 0;
}