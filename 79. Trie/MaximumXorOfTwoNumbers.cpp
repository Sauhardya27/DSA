#include <bits/stdc++.h>
using namespace std;

struct Node {
    Node* links[2];

    //Checks if the bit is present or not
    bool containsKey(int bit){
        return (links[bit] != NULL);
    }

    Node* get(int bit){
        return links[bit];
    }

    void put(int bit, Node* node){
        links[bit] = node;
    }
};

class Trie {
    Node* root;
public:
    Trie () : root(new Node()) {}

    void insert(int num){
        Node* node = root;
        for(int i=31; i>=0; i--){
            int bit = (num >> i) & 1; //Converts into binary bits and inserts it
            if(!node->containsKey(bit)){
                node->put(bit, new Node());
                //Insert the bit and create a new reference node
            }
            node = node->get(bit); //Move to next node
        }
    }

    int getMax(int num){
        Node* node = root;
        int maxNum = 0;

        for(int i=31; i>=0; i--){
            int bit = (num >> i) & 1;

            if(node->containsKey(1 - bit)){ //Check if it contains the opposite bit
                maxNum = maxNum | (1 << i); //Then add it to maxNum
                node = node->get(1 - bit);
            }
            else{
                node = node->get(bit);
            }
        }
        return maxNum;
    }

};

class Solution {
public:
    int findMaximumXOR(vector<int>& nums) {
        Trie trie;
        int maxi = 0;

        for(auto &it: nums){
            trie.insert(it);
        }

        for(auto &it: nums){
            maxi = max(maxi, trie.getMax(it));
        }
        return maxi;
    }
};