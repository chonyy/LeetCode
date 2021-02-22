/*
 * @lc app=leetcode id=690 lang=cpp
 *
 * [690] Employee Importance
 */

// @lc code=start
/*
// Definition for Employee.
class Employee {
public:
    int id;
    int importance;
    vector<int> subordinates;
};
*/

class Solution {
    unordered_map<int, Employee*> m;
public:
    int getImportance(vector<Employee*> employees, int id) {
        for(auto emp : employees) 
            m[emp->id] = emp;

        return dfs(id);
    }

    int dfs(int id) {
        int sum = m[id]->importance;

        for(int sub : m[id]->subordinates) {
            sum += dfs(sub);
        }

        return sum;
    }
};
// @lc code=end

