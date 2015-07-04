/**
 * @file WordSearch2.cpp
 * @brief
 * @author nhzc   charles.nhzc@gmail.com
 * @version 1.0.0
 * @date 2015-06-01
 */
//notice that we should initialize the TrieNode child leaf as 26 TrieNode , not as the map structure
//It will be running out of time
class Solution {
public:
    class TrieNode{
          public:
         TrieNode *ch[26];
        bool isWord;
        TrieNode() : isWord(false) {
            for (auto &a : ch) a = NULL;
        }
};

    class Trie{
       private:


public:
    Trie() {
        root = new TrieNode();
    }

    // Inserts a word into the trie.
    void insert(string word) {
       TrieNode *p = root;
        for (auto &a : word) {
            int i = a - 'a';
            if (p->ch[i] == NULL) p->ch[i] = new TrieNode();
            p = p->ch[i];
        }
        p->isWord = true;

    }

    // Returns if the word is in the trie.
    bool search(string word) {
        TrieNode *p = root;
        for (auto &a : word) {
            int i = a - 'a';
            if (p->ch[i] == NULL) return false;
            p = p->ch[i];
        }
        return p->isWord;
    }

    // Returns if there is any word in the trie
    // that starts with the given prefix.
    bool startsWith(string word) {
         TrieNode *p = root;
        for (auto &a : word) {
            int i = a - 'a';
            if (p->ch[i] == NULL) return false;
            p = p->ch[i];
        }
        return true;
    }



private:
    TrieNode* root;

    };
    void dfs(vector<vector<char>> &board, Trie *tireTree, set<string> &result, int x, int y, string str){
        if (x >= board[0].size() || x < 0 || y >= board.size() || y < 0 || board[y][x] == '*' ){
            return;
        }
        str += board[y][x];

        if (!tireTree->startsWith(str)){
            return ;
        }
        if (tireTree->search(str)){
            result.insert(str);
        }
        char tem = board[y][x];
        board[y][x] = '*';
        dfs(board, tireTree, result, x + 1, y, str);
        dfs(board, tireTree, result, x - 1, y, str);
        dfs(board, tireTree, result, x , y + 1, str);
        dfs(board, tireTree, result, x , y - 1, str);
        board[y][x] = tem;

    }
    vector<string> findWords(vector<vector<char>>& board, vector<string>& words) {
        Trie *tireTree = new Trie();
        for (int i = 0; i < words.size(); i ++){
            tireTree->insert(words[i]);
        }
        set<string> result;
         vector<string> res;
        if (board.size() == 0 || words.size() == 0){
            return res;
        }
        string str = "";
        for (int y = 0 ; y < board.size(); y ++){
            for (int x = 0; x < board[0].size(); x ++){
                 dfs(board, tireTree, result, x, y, str);
            }
        }

        for (set<string>::iterator iter = result.begin(); iter != result.end(); iter ++){
            res.push_back(*iter);
        }
        return res;
    }
};
