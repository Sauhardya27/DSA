#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

//For +ve, -ve and 0
int getLongestSubarray(vector<int>& nums, int k){
    unordered_map<long long, int> preMap;
    long long sum = 0;
    int maxLen = 0;

    for(int i=0; i<nums.size(); i++){
        sum += nums[i];
        if(sum == k)
            maxLen = max(maxLen, i+1);

        long long remSum = sum - k;
        if(preMap.find(remSum) != preMap.end()){
            int len = i - preMap[remSum];
            maxLen = max(maxLen, len);
        }
        if(preMap.find(sum) == preMap.end())
            preMap[sum] = i;
    }
    return maxLen;
}

//For +ve only
int longestSubarrayWithSumK(vector<int> a, long long k) {
    int left = 0, right = 0, maxLen = 0;
    long long sum = a[0];
    int n = a.size();

    while(right < n){
        while(left <= right && sum > k){
            sum -= a[left];
            left++;
        }

        if(sum == k)
            maxLen = max(maxLen, right-left+1);

        right++;
        if(right < n)
            sum += a[right];
    }
    return maxLen;
}

