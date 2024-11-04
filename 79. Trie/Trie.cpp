#include <bits/stdc++.h>
using namespace std;

class TrieNode{
	public:
	char data;
	TrieNode* children[26];
	bool isTerminal;
	TrieNode(char ch){
		data = ch;
		for(int i=0;i<26;i++){
			children[i] = NULL;
		}
		isTerminal = false;
	}
};

class Trie{
	public:
		TrieNode* root;

		Trie(){
			root = new TrieNode('\0');
		}

		void insertUtil(TrieNode* root, string word){
			//If word is empty(reached the end of the word)
			if(word.length() == 0){
				root->isTerminal = true;
				return;	
			}

			TrieNode* child;
			//Assuming all the characters are in CAPS
			int index = word[0] - 'A';

			//If the char is present
			if(root->children[index] != NULL){
				child = root->children[index];
			}
			else{
				child = new TrieNode(word[0]);
				root->children[index] = child;
			}

			insertUtil(child, word.substr(1));
		}

		void insertWord(string word){
			insertUtil(root, word);
		}

		bool searchUtil(TrieNode* root, string word){
			if(word.length() == 0)
				return root->isTerminal;

			TrieNode* child;
			int index = word[0] - 'A';

			if(root->children[index] != NULL){
				child = root->children[index];
			}
			else{
				return false;
			}

			return searchUtil(child, word.substr(1));
		}

		bool searchWord(string word){
			return searchUtil(root, word);
		}

		void removeWord(string word){
			if(searchWord(word)){
				while(word.length() != 0){
					int index = word[0] - 'A';
					root = root->children[index];
					word = word.substr(1);
				}
				root->isTerminal = false;
			}
			return;
		}
};

int main(){
	Trie* t = new Trie();

	t->insertWord("ABCD");
	if(t->searchWord("ABCD"))
		cout << "Word is present" << endl;
	else
		cout << "Word is absent" << endl;

	t->removeWord("ABCD");
	if(t->searchWord("ABCD"))
		cout << "Word is present" << endl;
	else
		cout << "Word is absent" << endl;

	return 0;
}