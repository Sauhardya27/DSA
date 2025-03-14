#include <bits/stdc++.h>
using namespace std;

struct Item{
    int value;
    int weight;
};

static bool cmp(pair<double, Item> a, pair<double, Item> b){
	return a.first > b.first;
}

double fractionalKnapsack(vector<int>& val, vector<int>& wt, int capacity) {
	int W = capacity;
	int n = val.size();
	vector<pair<double, Item>> v(n);
	vector<Item> items(n);
	
	for(int i=0; i<n; i++){
		items[i].value = val[i];
		items[i].weight = wt[i];
	}
	
	for(int i=0; i<n; i++){
		double value = (1.0*val[i])/wt[i];
		pair<double, Item> p = make_pair(value, items[i]);
		v[i] = p;
	}
	
	sort(v.begin(), v.end(), cmp);
	
	double totalValue = 0;
	for(int i=0; i<n; i++){
		if(v[i].second.weight < W){
			totalValue += v[i].second.value;
			W -= v[i].second.weight;
		} else {
			totalValue += W*v[i].first;
			W = 0;
		}
	}
	return totalValue;
}