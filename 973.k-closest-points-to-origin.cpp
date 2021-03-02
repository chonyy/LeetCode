/*
 * @lc app=leetcode id=973 lang=cpp
 *
 * [973] K Closest Points to Origin
 */

// @lc code=start
class Solution {
public:
    double distance(vector<int>& point) {
        return point[0] * point[0] + point[1] * point[1];
    }

    void quickSelect(vector<vector<int>>& points, int low, int high, int K) {
        if(high <= low)
            return;

        int pivot = low;
        for(int i = low; i < high; i ++) {
            if(distance(points[i]) <= distance(points[high])) {
                swap(points[pivot++], points[i]);
            }
        }
        swap(points[pivot], points[high]);

        int SmallestK = pivot - low + 1;
        if(SmallestK == K)
            return;
        else if(SmallestK > K)
            quickSelect(points, low, pivot-1, K);
        else
            quickSelect(points, pivot+1, high, K-(SmallestK));            
    }

    vector<vector<int>> kClosest(vector<vector<int>>& points, int K) {
        int n = points.size();
        int start = 0;
        int end = n-1;
        vector<vector<int>> res;

        quickSelect(points, start, end, K);

        for(int i = 0; i < K; i ++) {
            res.push_back(points[i]);
        }

        return res;
    }
};
// @lc code=end

