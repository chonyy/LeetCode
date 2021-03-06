/*
 * @lc app=leetcode id=1570 lang=cpp
 *
 * [1570] Dot Product of Two Sparse Vectors
 */

// @lc code=start
class SparseVector {
public:
    unordered_map<int, int> m;
    
    SparseVector(vector<int> &nums) {
        int n = nums.size();

        for(int i = 0; i < n; i ++) {
            if(nums[i] != 0) {
                m[i] = nums[i];
            }
        }
    }
    
    // Return the dotProduct of two sparse vectors
    int dotProduct(SparseVector& vec) {
        int product = 0;

        for(auto it = m.begin(); it != m.end(); it ++) {
            if(vec.m.count(it->first) != 0) {
                product += vec.m[it->first] * it->second;
            }
        }

        return product;
    }
};

// Your SparseVector object will be instantiated and called as such:
// SparseVector v1(nums1);
// SparseVector v2(nums2);
// int ans = v1.dotProduct(v2);
// @lc code=end

