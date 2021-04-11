class Solution {
public:
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        // Create a set for constant access time
        unordered_set<string> wordSet (wordList.begin(), wordList.end());
        
        deque<string> startQ;
        deque<string> endQ;
        startQ.push_back(beginWord);
        endQ.push_back(endWord);
        
        // Return 0 if the endWord is not in the set
        if(wordSet.find(endWord) == wordSet.end()) {
            return 0;
        }
        
        int step = 1;
        
        while(!startQ.empty()) {
            int size = startQ.size();
            for(int i = 0; i < size; i ++) {
                string curWord = startQ.front();
                startQ.pop_front();
                // Loop through all possible words within one distance
                for(int j = 0; j < curWord.size(); j ++) {
                    // Try all character at each index
                    string candidate = curWord;
                    for(char c = 'a'; c <= 'z'; c ++) {
                        if(c == curWord[j])
                            continue;
                        candidate[j] = c;
                        
                        // If it's the target, return step + 1
                        if(find(endQ.begin(), endQ.end(), candidate) != endQ.end())
                            return step + 1;
                        
                        // If the candidate is in the word set, push_back it int the deque, and remove from the set
                        if(wordSet.find(candidate) != wordSet.end()) {
                            startQ.push_back(candidate);
                            wordSet.erase(candidate);
                        }
                    }
                }
            }
            swap(startQ, endQ);
            step ++;
        }
        
        return 0;
    }
};