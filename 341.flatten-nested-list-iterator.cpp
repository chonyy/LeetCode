/*
 * @lc app=leetcode id=341 lang=cpp
 *
 * [341] Flatten Nested List Iterator
 */

// @lc code=start
/**
 * // This is the interface that allows for creating nested lists.
 * // You should not implement it, or speculate about its implementation
 * class NestedInteger {
 *   public:
 *     // Return true if this NestedInteger holds a single integer, rather than a nested list.
 *     bool isInteger() const;
 *
 *     // Return the single integer that this NestedInteger holds, if it holds a single integer
 *     // The result is undefined if this NestedInteger holds a nested list
 *     int getInteger() const;
 *
 *     // Return the nested list that this NestedInteger holds, if it holds a nested list
 *     // The result is undefined if this NestedInteger holds a single integer
 *     const vector<NestedInteger> &getList() const;
 * };
 */

class NestedIterator {
private:
    stack<NestedInteger> s;

public:
    NestedIterator(vector<NestedInteger> &nestedList) {
        dfs(nestedList);
    }

    void dfs(vector<NestedInteger> &nestedList) {
        int n = nestedList.size();
        for(int i = n - 1; i >=0;i --) {
            NestedInteger cur = nestedList[i];
            if(cur.isInteger()) {
                s.push(cur.getInteger());
            }
            else {
                dfs(cur.getList());
            }
        }
    }
    
    int next() {
        auto cur = s.top();
        s.pop();
        return cur.getInteger();
    }
    
    bool hasNext() {
        return !s.empty();
    }

    // 32ms
    // NestedIterator(vector<NestedInteger> &nestedList) {
    //     int n = nestedList.size();
    //     for(int i = n - 1; i >=0;i --) {
    //         s.push(nestedList[i]);
    //     }
    // }
    
    // int next() {
    //     NestedInteger cur = s.top();
    //     s.pop();
    //     cout << cur.getInteger();
    //     return cur.getInteger();
    // }
    
    // bool hasNext() {
    //     if(s.empty()) return false;

    //     auto top = s.top();
    //     while(!top.isInteger()) {
    //         auto tempList = top.getList();
    //         int n = tempList.size();
    //         cout << n << endl;

    //         s.pop();
    //         if(n > 0) {
    //             for(int i = n - 1; i >= 0; i --) {
    //                 s.push(tempList[i]);
    //             }
    //         }

    //         if(s.empty()) return false;

    //         top = s.top();
    //     }
    //     return !s.empty();
    // }
};

/**
 * Your NestedIterator object will be instantiated and called as such:
 * NestedIterator i(nestedList);
 * while (i.hasNext()) cout << i.next();
 */
// @lc code=end

