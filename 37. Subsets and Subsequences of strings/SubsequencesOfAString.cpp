#include <iostream>
#include <vector>
using namespace std;

void solve(string str, string output, int index, vector<string> &ans) {
  if (index >= str.size()) {
	if(output.size() > 0) //Do avoid the insertion of empty string
    	ans.push_back(output);
    return;
  }

  // exclude
  solve(str, output, index + 1, ans);

  // include
  char ch = str[index];
  output.push_back(ch);
  solve(str, output, index + 1, ans);
}

vector<string> subsequences(string str) {
  vector<string> ans;
  string output;
  int index = 0;

  solve(str, output, index, ans);

  return ans;
}

int main(){
	string str = "abc";
	vector<string> ans = subsequences(str);

	cout << "Subsets:" << endl;
    for (const auto &subset : ans) {
        cout << "{ ";
        for (char num : subset) {
            cout << num << " ";
        }
        cout << "}" << endl;
    }
	return 0;
}