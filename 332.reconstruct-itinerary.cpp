/*
 * @lc app=leetcode id=332 lang=cpp
 *
 * [332] Reconstruct Itinerary
 */

// @lc code=start
class Solution {
    vector<string> res;
    unordered_map<string, priority_queue<string, vector<string>, greater<>>> g;
public:
    vector<string> findItinerary(vector<vector<string>>& tickets) {

        for(auto ticket : tickets) {
            g[ticket[0]].push(ticket[1]);
        }

        travel("JFK");

        return vector<string>(res.rbegin(), res.rend());
    }

    void travel(string begin) {
        auto& neighbors = g[begin];
        while(!neighbors.empty()) {
            string destination = neighbors.top();
            neighbors.pop();
            travel(destination);
        }
        cout << begin << endl;
        res.push_back(begin);
    }
    
};
// @lc code=end

