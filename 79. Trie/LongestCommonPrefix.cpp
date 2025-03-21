#include <bits/stdc++.h>
using namespace std;

//Using trie (Not optimized) S.C. = O(m*n)
class TrieNode{
    public:
        char data;
        TrieNode* children[26];
        int countChild;
        bool isTerminal;

    
        TrieNode(char ch){
            data = ch;
            for(int i=0; i<26; i++)
                children[i] = NULL;

            countChild = 0;
            isTerminal = false;
        }
};

class Trie{
    public:
        TrieNode* root;
        
        Trie(char ch){
            root = new TrieNode(ch);
        }

        void insertUtil(TrieNode* root, string word){
			//If word is empty(reached the end of the word)
			if(word.length() == 0){
				root->isTerminal = true;
				return;	
			}

			TrieNode* child;
			//Assuming all the characters are in CAPS
			int index = word[0] - 'a';

			//If the char is present
			if(root->children[index] != NULL){
				child = root->children[index];
			}
			else{
				child = new TrieNode(word[0]);
                root->countChild += 1;
				root->children[index] = child;
			}

			insertUtil(child, word.substr(1));
		}

		void insertWord(string word){
			insertUtil(root, word);
		}

        void lcp(string str, string &ans){
            for(int i=0; i<str.length(); i++){
                char ch = str[i];

                if(root->countChild == 1){
                    ans.push_back(ch);
                    int index = ch - 'a';
                    root = root->children[index];
                }
                else
                    break;

                if(root->isTerminal)
                    break;
            }
        }
};

string longestCommonPrefix(vector<string> &arr, int n)
{
    Trie* t = new Trie('\0');
    string ans = "";

    for(int i=0; i<n; i++)
        t->insertWord(arr[i]);

    string first = arr[0];
    t->lcp(first, ans);

    return ans;
    
}

//Optimized solution: S.C. = O(1)
/*string longestCommonPrefix(vector<string> &arr, int n)
{
    string ans;
    for(int i=0; i<arr[0].length(); i++){
        char ch = arr[0][i];
        bool match = true;
        for(int j=1; j<n; j++){
            if(arr[j].size() < i || ch != arr[j][i]){
                match = false;
                break;
            }
        }
        if(!match)
            break;
        else
            ans.push_back(ch);
    }
    return ans;
}*/