#include <bits/stdc++.h>
using namespace std;

static bool cmp(pair<int, int> a, pair<int, int> b){
	if (a.first == b.first) return a.second < b.second;
	return a.first < b.first;
}

vector<int> maxMeetings(int N,vector<int> &S,vector<int> &F){
	vector<int> result;
	vector<pair<int, int>> v;
	
	for(int i=0; i<N; i++){
		pair<int, int> p = make_pair(F[i], i+1);
		v.push_back(p);
	}
	
	sort(v.begin(), v.end(), cmp);
	
	int ansEnd = 0;
	
	for(int i=0; i<N; i++){
		if(S[v[i].second - 1] > ansEnd){
			ansEnd = v[i].first;
			result.push_back(v[i].second);
		}
	}
	sort(result.begin(), result.end());
	return result;
}