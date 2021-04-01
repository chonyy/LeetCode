# include<bits/stdc++.h>

using namespace std;

void solve(vector<int>& nums, int k) {
    stack<pair<int, int>> stk;
    vector<int> res;

    for(int num : nums) {
        if(!stk.empty() && num == stk.top().first) {
            stk.top().second ++;
            if(stk.top().second == k)
                stk.pop();
        }
        else {
            stk.push({num, 1});
        }
    }

    // We will have a cleaned stack now
    while(!stk.empty()) {
        res.insert(res.end(), stk.top().second, stk.top().first);
        stk.pop();
    }

    reverse(res.begin(), res.end());
    for(int r : res)
        cout << r << " ";
}

int main() {
    // 5 5 4 3
    // vector<int> arr = {5, 2, 3, 3, 3, 2, 1, 1, 1, 2, 5, 5, 4, 3};
    // int k = 3;
    // solve(arr, k);
    vector<int> res;

    for(int i = 0; i < n; i ++0 {
        sum += nums[i];
    })
    unordered_map<int, int> m;

    return 0; 
}