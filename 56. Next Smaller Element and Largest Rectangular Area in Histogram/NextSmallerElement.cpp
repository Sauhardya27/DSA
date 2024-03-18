#include <iostream>
#include <stack>
#include <vector>
using namespace std;
vector<int> nextSmallerElement(vector<int> &arr, int n)
{
    stack<int>s;
    s.push(-1);
    vector<int> ans(n);

    for(int i=n-1; i>=0; i--){
        int curr = arr[i];
        while(s.top() >= curr)
            s.pop();

        ans[i] = s.top();
        s.push(curr);
    }
    return ans;
}

int main(){
	vector<int> arr;
	arr.push_back(2);
	arr.push_back(1);
	arr.push_back(4);
	arr.push_back(3);

	vector<int> ans;
	ans = nextSmallerElement(arr, 4);

	cout << "Original Array: ";
	for(int i=0; i<4; i++)
		cout << arr[i] << " ";

	cout << endl;

	cout << "Solution Array: ";
	for(int i=0; i<4; i++)
		cout << ans[i] << " ";

	cout << endl;
	return 0;
}

