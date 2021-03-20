/*
 * @lc app=leetcode id=244 lang=cpp
 *
 * [244] Shortest Word Distance II
 */

// @lc code=start
class WordDistance {
    unordered_map<string, vector<int>> m;
public:
    WordDistance(vector<string>& wordsDict) {
        for(int i = 0; i < wordsDict.size(); i ++) {
            m[wordsDict[i]].push_back(i);
        }
    }
    
    int shortest(string word1, string word2) {
        auto& idx1 = m[word1];
        auto& idx2 = m[word2];

        int i = 0, j = 0;
        int dist = INT_MAX;
        while(i < idx1.size() && j < idx2.size()) {
            dist = min(dist, abs(idx1[i] - idx2[j]));
            if(idx1[i] < idx2[j]) {
                i ++;
            }
            else 
                j ++;
        }

        return dist;
    }
};

/**
 * Your WordDistance object will be instantiated and called as such:
 * WordDistance* obj = new WordDistance(wordsDict);
 * int param_1 = obj->shortest(word1,word2);
 */
// @lc code=end

