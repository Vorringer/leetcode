#include<iostream>
#include<vector>
#include<map>
using namespace std;
class TrieNode {
public:
	// Initialize your data structure here.
	char val;
	map<char ,TrieNode*>*child;
	TrieNode(const char& ch) :val(ch)
	{
		child = new map < char, TrieNode* > ;
	}
	TrieNode() :val(' ')
	{
		child = new map < char, TrieNode* > ;

	}
};

class Trie {
public:
	Trie() {
		root = new TrieNode();
	}
	~Trie(){ destroy(root); }
	// Inserts a word into the trie.
	void insert(string s) {
		TrieNode* temp = root;
		s.append("$");
		for (int i = 0; i<s.size(); i++)
		{
			if ((*(temp->child)).find(s[i]) == (*(temp->child)).end())
			{
				(*(temp->child))[s[i]] = new TrieNode(s[i]);
				temp = (*(temp->child))[s[i]];
			}
			else
			{
				temp = (*(temp->child))[s[i]];
			}
		}
	}

	// Returns if the word is in the trie.
	bool search(string key) {
		TrieNode* temp = root;
		key.append("$");
		for (int i = 0; i<key.size(); i++)
		{
			if ((*(temp->child)).find(key[i]) == (*(temp->child)).end())
			{
				return false;
			}
			else
			{
				temp = (*(temp->child))[key[i]];
			}
		}
		return true;
	}

	// Returns if there is any word in the trie
	// that starts with the given prefix.
	bool startsWith(string prefix) {
		TrieNode* temp = root;
		for (int i = 0; i<prefix.size(); i++)
		{
			if ((*(temp->child)).find(prefix[i]) == (*(temp->child)).end())
			{
				return false;
			}
			else
			{
				temp = (*(temp->child))[prefix[i]];
			}
		}
		return true;
	}

private:
	TrieNode* root;
	void destroy(TrieNode* root) {
		for (map<char, TrieNode*>::iterator p = (root->child)->begin(); p != root->child->end(); p++)
		{
			destroy(p->second);
		}
		delete root;
	}
};
int main()
{
	Trie t;
	/*t.insert("p");
	t.startsWith("pr");
	t.search("p");
	t.insert("pr");
	t.startsWith("pre");
	t.search("pr");
	t.insert("pre");
	//startsWith("pre"), search("pre"), insert("pref"), startsWith("pref"), search("pref"), insert("prefi"), startsWith("pref"), search("prefi"), insert("prefix"), startsWith("prefi"),
	t.search("prefix");*/
	t.insert("ab");
	t.search("a");
	system("pause");
}