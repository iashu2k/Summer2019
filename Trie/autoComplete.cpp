#include <iostream>
#include <string>
using namespace std;
#include <vector>
#include <vector>
class TrieNode {
	public :
	char data;
	TrieNode **children;
	bool isTerminal;

	TrieNode(char data) {
		this -> data = data;
		children = new TrieNode*[26];
		for(int i = 0; i < 26; i++) {
			children[i] = NULL;
		}
		isTerminal = false;
	}
};

class Trie {
	TrieNode *root;

	public :
	int count;

	Trie() {
		this->count = 0;
		root = new TrieNode('\0');
	}

	bool insertWord(TrieNode *root, string word) {
		// Base case
		if(word.size() == 0) {
			if (!root->isTerminal) {
				root -> isTerminal = true;
				return true;
			} else {
				return false;
			}
		}

		// Small Calculation
		int index = word[0] - 'a';
		TrieNode *child;
		if(root -> children[index] != NULL) {
			child = root -> children[index];
		}
		else {
			child = new TrieNode(word[0]);
			root -> children[index] = child;
		}

		// Recursive call
		return insertWord(child, word.substr(1));
	}

	// For user
	void insertWord(string word) {
		if (insertWord(root, word)) {
			this->count++;
		}
	}

    TrieNode* search(TrieNode *root, string word){
        if(word.size()==0){
            return root;
        }

        int index = word[0] - 'a';
        TrieNode *child;
        if(root->children[index]!=NULL){
            child = root->children[index];
        }
        else
            return root;

        return search(child , word.substr(1));
    }

    TrieNode* search(string word) {
        // Write your code here
        return search(root, word);

    }

    void printauto(TrieNode *root, string pattern){
        if(root->isTerminal){
            cout<<pattern<<root->data<<endl;
        }

        for(int i = 0; i < 26; i++){
            if(root->children[i]!=NULL){

                printauto(root->children[i],pattern+root->data);
            }
        }

    }

    void print(TrieNode *root, string pattern){

        for(int i = 0; i < 26; i++){
            if(root->children[i]!=NULL){

                printauto(root->children[i],pattern);
            }
        }
    }

    void autoComplete(vector<string> input, string pattern) {
        // Complete this function
        // Print the output as specified in question
        for(int i = 0; i < input.size(); i++){
            insertWord(input[i]);
        }

        TrieNode* t = search(pattern);
        if(t->isTerminal)
            cout<<pattern<<endl;
        print(t, pattern);
    }




};


int main() {
	Trie t;
    int N;
    cin >> N;
    string pattern;
    vector<string> vect;
    for (int i=0; i < N; i++) {
        string word;
        cin >> word;
        vect.push_back(word);
    }
    cin >> pattern;
    t.autoComplete(vect, pattern);
}
