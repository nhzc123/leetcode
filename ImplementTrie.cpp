/**
 * @file ImplementTrie.cpp
 * @brief
 * @author nhzc   charles.nhzc@gmail.com
 * @version 1.0.0
 * @date 2015-05-11
 */
class TrieNode {

public:
    map<char, TrieNode*> m;
    char val;
    bool isWord;
    // Initialize your data structure here.
    TrieNode() {
        m.clear();
        isWord = false;
    }
    TrieNode(char v){
        m.clear();
        isWord = false;
        val = v;
    }
};

class Trie {
private:
void insert(TrieNode *root, string s){
        if (s.length() == 0){
            root->isWord = true;
            return ;
        }
        if (root->m.find(s[0]) == root->m.end()){
            root->m[s[0]] = new TrieNode(s[0]);
        }
        insert(root->m[s[0]] , s.substr(1));
        return ;
    }

    bool search(TrieNode *root, string key){
        if (key.length() == 0){
            return root->isWord;
        }
        if (root->m.find(key[0]) == root->m.end()){
            return false;
        }
        else{
            return search(root->m[key[0]], key.substr(1));
        }
    }

    bool startsWith(TrieNode *root, string prefix){
        if (prefix.length() == 0){
            return true;
        }
         if (root->m.find(prefix[0]) == root->m.end()){
            return false;
        }
        else{
            return startsWith(root->m[prefix[0]], prefix.substr(1));
        }
    }

public:
    Trie() {
        root = new TrieNode();
    }

    // Inserts a word into the trie.
    void insert(string s) {
        insert(root, s);

    }

    // Returns if the word is in the trie.
    bool search(string key) {
        return search(root, key);
    }

    // Returns if there is any word in the trie
    // that starts with the given prefix.
    bool startsWith(string prefix) {
        return startsWith(root, prefix);
    }



private:
    TrieNode* root;
};

// Your Trie object will be instantiated and called as such:
// Trie trie;
// trie.insert("somestring");
// trie.search("key");
