/*
 * @lc app=leetcode id=208 lang=cpp
 *
 * [208] Implement Trie (Prefix Tree)
 */

// @lc code=start
class TrieNode {
    public:
        bool isWord;
        TrieNode* children[26];

        TrieNode() {
            isWord = false;

            for(int i = 0; i < 26; i ++) {
                children[i] = nullptr;
            }
        }
};


class Trie {
private:
    TrieNode* root;

public:
    /** Initialize your data structure here. */
    Trie() {
        root = new TrieNode();
    }
    
    /** Inserts a word into the trie. */
    void insert(string word) {
        int n = word.size();
        int k = 0;
        TrieNode *cur = root;

        for(int i = 0; i < n; i ++) {
            k = word[i] - 'a';
            if(cur->children[k] == nullptr) {
                cur->children[k] = new TrieNode();
            }
            cur = cur->children[k];
        }

        cur->isWord = true;
    }
    
    /** Returns if the word is in the trie. */
    bool search(string word) {
        TrieNode* res = find(word);
        if(res != nullptr && res->isWord) return true;
        return false;
    }
    
    /** Returns if there is any word in the trie that starts with the given prefix. */
    bool startsWith(string prefix) {
        if(find(prefix)) return true;
        return false;
    }

    TrieNode* find(string s) {
        TrieNode* p = root;
        int n = s.size();
        int k = 0;
        for(int i = 0; i < n; i ++) {
            k = s[i] - 'a';
            if(p->children[k] == nullptr) 
                return nullptr;
            p = p->children[k];
        }
        return p;
    }
};

/**
 * Your Trie object will be instantiated and called as such:
 * Trie* obj = new Trie();
 * obj->insert(word);
 * bool param_2 = obj->search(word);
 * bool param_3 = obj->startsWith(prefix);
 */
// @lc code=end

