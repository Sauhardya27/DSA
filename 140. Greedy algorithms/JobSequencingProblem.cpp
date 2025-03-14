#include <bits/stdc++.h>
using namespace std;

struct Job{
    int id;
    int dead;
    int profit;
};

static bool cmp(Job a, Job b){
	return a.profit > b.profit;
}

vector<int> JobSequencing(vector<int> &id, vector<int> &deadline, vector<int> &profit) {
	int n = id.size();
	vector<Job> job(n);
	int maxDeadline = 0;
	
	for(int i=0; i<n; i++){
		job[i].id = id[i];
		job[i].dead = deadline[i];
		job[i].profit = profit[i];
		
		maxDeadline = max(maxDeadline, deadline[i]);
	}
	
	sort(job.begin(), job.end(), cmp);
	
	vector<int> schedule(maxDeadline+1, -1);
	
	int count = 0;
	int maxProfit = 0;
	for(int i=0; i<n; i++){
		int currId = job[i].id;
		int currDead = job[i].dead;
		int currProfit = job[i].profit;
		
		for(int j=currDead; j>0; j--){
			if(schedule[j] == -1){
				schedule[j] = currId;
				count++;
				maxProfit += currProfit;
				break;
			}
		}
	}
	return {count, maxProfit};
}