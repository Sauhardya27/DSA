#include <bits/stdc++.h>
using namespace std;

class TrieNode{
public:
	char data;
	TrieNode *children[26];
	bool isTerminal;
	TrieNode(char ch){
		data = ch;
		for (int i = 0; i < 26; i++){
			children[i] = NULL;
		}
		isTerminal = false;
	}
};

class Trie{
public:
	TrieNode *root;

	Trie(){
		root = new TrieNode('\0');
	}

	// Other way to insert word (efficient)
	void insertUtil(TrieNode *root, const string &word, int index)
	{
		// If we've reached the end of the word
		if (index == word.length()){
			root->isTerminal = true;
			return;
		}

		// Calculate the index for the current character
		int charIndex = word[index] - 'A';

		// If the character is not present, create a new TrieNode
		if (root->children[charIndex] == nullptr){
			root->children[charIndex] = new TrieNode(word[index]);
		}

		// Recur for the next character
		insertUtil(root->children[charIndex], word, index + 1);
	}

	void insertWord(const string &word){
		insertUtil(root, word, 0);
	}

	bool searchUtil(TrieNode *root, const string &word, int index){
		// Base case: If the entire word has been processed
		if (index == word.length()){
			return root->isTerminal;
		}

		// Get the current character's index (assuming all uppercase)
		int charIndex = word[index] - 'A';

		// Check if the current character exists in the Trie
		if (root->children[charIndex] == NULL){
			return false;
		}

		// Recurse to the next character
		return searchUtil(root->children[charIndex], word, index + 1);
	}

	bool searchWord(const string &word){
		return searchUtil(root, word, 0);
	}

	void removeWord(string word){
		if (searchWord(word)){
			while (word.length() != 0){
				int index = word[0] - 'A';
				root = root->children[index];
				word = word.substr(1);
			}
			root->isTerminal = false;
		}
		return;
	}
};

int main()
{
	Trie *t = new Trie();

	t->insertWord("ABCD");
	if (t->searchWord("ABCD"))
		cout << "Word is present" << endl;
	else
		cout << "Word is absent" << endl;

	t->removeWord("ABCD");
	if (t->searchWord("ABCD"))
		cout << "Word is present" << endl;
	else
		cout << "Word is absent" << endl;

	return 0;
}