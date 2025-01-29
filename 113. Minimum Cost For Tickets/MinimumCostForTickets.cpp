#include <bits/stdc++.h>
using namespace std;

//exponential time complexity
int solve(int n, vector<int> &days, vector<int> &cost, int index){
    if(index >= n)
        return 0;

    //1-day cost
    int option1 = cost[0] + solve(n, days, cost, index+1);

    int i;
    //7-days cost
    for(i=index; i<n && days[i] < days[index] + 7; i++);

    int option2 = cost[1] + solve(n, days, cost, i);

    //30-days cost
    for(i=index; i<n && days[i] < days[index] + 30; i++);

    int option3 = cost[2] + solve(n, days, cost, i);

    return min(option1, min(option2, option3));
}

int solveMem(int n, vector<int> &days, vector<int> &cost, int index, vector<int> &dp){
    if(index >= n)
        return 0;

    if(dp[index] != -1)
        return dp[index];

    //1-day cost
    int option1 = cost[0] + solveMem(n, days, cost, index+1, dp);

    int i;
    //7-days cost
    for(i=index; i<n && days[i] < days[index] + 7; i++);

    int option2 = cost[1] + solveMem(n, days, cost, i, dp);

    //30-days cost
    for(i=index; i<n && days[i] < days[index] + 30; i++);

    int option3 = cost[2] + solveMem(n, days, cost, i, dp);

    dp[index] = min(option1, min(option2, option3));
    return dp[index];
}

int solveTab(int n, vector<int> &days, vector<int> &cost){
    vector<int> dp(n+1, INT_MAX);
    dp[n] = 0;

    //In bottom-up approach we will follow the reverse as done in top-down approach
    for(int k=n-1; k>=0; k--){
        //1-day cost
        int option1 = cost[0] + dp[k+1];

        int i;
        //7-days cost
        for(i=k; i<n && days[i] < days[k] + 7; i++);

        int option2 = cost[1] + dp[i];

        //30-days cost
        for(i=k; i<n && days[i] < days[k] + 30; i++);

        int option3 = cost[2] + dp[i];

        dp[k] = min(option1, min(option2, option3));
    }
    return dp[0];
}

int minimumCoins(int n, vector<int> days, vector<int> cost){
    // return solve(n, days, cost, 0);
    // vector<int> dp(n+1, -1);
    // return solveMem(n, days, cost, 0, dp);
    // return solveTab(n, days, cost);
    
    int ans = 0;
    //For storing day, cost for the month and for week
    queue<pair<int, int>> month; //30-days hence O(30)
    queue<pair<int, int>> week; //7-days hene O(&7)

    for(auto &day: days){
        //Step-1: Remove expired days
        while(!month.empty() && month.front().first + 30 <= day)
            month.pop();

        while(!week.empty() && week.front().first + 7 <= day)
            week.pop();

        //Step-2: Add current days;
        week.push({day, ans + cost[1]});
        month.push({day, ans + cost[2]});

        //Step-3: Calculate min cost
        ans = min(ans +cost[0], min(week.front().second, month.front().second));
    }
    return ans;
}