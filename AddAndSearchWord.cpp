/**
 * @file AddAndSearchWord.cpp
 * @brief
 * @author nhzc   charles.nhzc@gmail.com
 * @version 1.0.0
 * @date 2015-05-16
 */
class WordDictionary {
public:
    struct TrieNode{
        public:
            char value;
            map<char, TrieNode *> m;
            bool isWord;
            TrieNode(){
                isWord = false;
                m.clear();
            }
            TrieNode(char c){
                value = c;
                isWord = false;
                m.clear();
            }
    };

    WordDictionary(){
        root = new TrieNode();
    }

    void addWord(TrieNode *root, string word){
        if (word.length() == 0){
            root->isWord = true;
            return ;
        }
        if (root->m.find(word[0]) == root->m.end()){
            TrieNode *tem = new TrieNode(word[0]);
            root->m[word[0]] = tem;
        }
        addWord(root->m[word[0]], word.substr(1));
        return ;
    }

    bool search(TrieNode *root, string word){
        if (word.length() == 0){
            return root->isWord;
        }
        if (word[0] == '.'){
          /*  for (auto & a : root->m){
                if (search(a, word.substr(1))){
                    return true;
                }
            }
            */
            for (map<char, TrieNode *>::iterator iter = root->m.begin(); iter != root->m.end(); iter ++){
                if (search(iter->second, word.substr(1))){
                    return true;
                }
            }
            return false;
        }
        else{
            if (root->m.find(word[0]) == root->m.end()){
                return false;
            }
            else{
                return search(root->m[word[0]], word.substr(1));
            }
        }
    }

    // Adds a word into the data structure.
    void addWord(string word) {
        addWord(root, word);
    }

    // Returns if the word is in the data structure. A word could
    // contain the dot character '.' to represent any one letter.
    bool search(string word) {
        return search(root, word);
    }
private:
    TrieNode *root;
};

// Your WordDictionary object will be instantiated and called as such:
// WordDictionary wordDictionary;
// wordDictionary.addWord("word");
// wordDictionary.search("pattern");
