/*
 * @lc app=leetcode id=208 lang=cpp
 *
 * [208] Implement Trie (Prefix Tree)
 */

// @lc code=start

class TrieNode {
public:
    bool isWord = false;
    TrieNode* children[26];

    TrieNode() {
        for(int i = 0; i < 26; i ++) {
            children[i] = nullptr;
        }
    }
};

class Trie {
public:
    TrieNode* root;
    /** Initialize your data structure here. */
    Trie() {
        root = new TrieNode();
    }
    
    /** Inserts a word into the trie. */
    void insert(string word) {
        TrieNode *cur = root;
        for(char c : word) {
            int child = c - 'a';
            if(cur->children[child] == nullptr)
                cur->children[child] = new TrieNode();
            cur = cur->children[child];
        }
        cur->isWord = true;
    }
    
    /** Returns if the word is in the trie. */
    bool search(string word) {
        TrieNode* node = find(word);
        if(!node)
            return false;
        return node->isWord;
    }
    
    /** Returns if there is any word in the trie that starts with the given prefix. */
    bool startsWith(string prefix) {
        return find(prefix) ? true : false;
    }

    TrieNode* find(string str) {
        TrieNode *cur = root;
        for(char c : str) {
            int child = c - 'a';
            if(!cur->children[child])
                return nullptr;
            cur = cur->children[child];
        }
        return cur;
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

