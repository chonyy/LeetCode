/*
 * @lc app=leetcode id=658 lang=cpp
 *
 * [658] Find K Closest Elements
 */

// @lc code=start
class Solution {
public:
    vector<int> findClosestElements(vector<int>& arr, int k, int x) {
        vector<int> res;
        int n = arr.size();
        // Find the closest element
        int closest = findClosest(arr, x);

        // Expand from the closest
        int l = closest, r = closest;
        k --;
        while(k --) {
            if(l <= 0) {
                r ++;
            }
            else if(r >= n-1) {
                l --;
            }
            else if(abs(arr[l-1] - x) <= abs(arr[r+1] - x)){
                l --;
            }
            else {
                r ++;
            }
        }

        for(int i = l; i <= r; i ++) {
            res.push_back(arr[i]);
        }

        return res;
    }

    int findClosest(vector<int>& arr, int x) {
        int l = 0, r = arr.size()-1;
        int closestDist = INT_MAX, closest = -1;
        while(l <= r) {
            int mid = l + (r-l) / 2;
            int cand = arr[mid];

            if(abs(cand - x) < closestDist) {
                closestDist = abs(cand - x);
                closest = mid;
            }

            if(cand == x)
                return mid;
            else if(cand < x) {
                l = mid + 1;
            }
            else {
                r = mid - 1;
            }
        }

        return closest;
    }
};
// @lc code=end

