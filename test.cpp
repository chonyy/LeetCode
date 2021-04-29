#include<bits/stdc++.h>

using namespace std;

bool cmp(vector<int>& a, vector<int>& b) {
    if(a[0] == b[0])
        return a[1] < b[1];
    return a[0] < b[0];
}

int main()
{
    // auto cmp = [](vector<int>& a, vector<int> &b) {
    //     if(a[0] == b[0])
    //         return a[1] < b[1];
    //     return a[0] < b[0];
    // }

    priority_queue<vector<int>, vector<vector<int>>, decltype(&cmp)> pq(cmp);
    vector<vector<int>> arr{{4, 5, 6}, {1, 2, 3}, {7, 8, 9}, {1, 3, 3}};
    
    cout << arr.size() << endl;
    for(auto element : arr) {
        // cout << "push" << endl;
        // for(int num : element)
        //     cout << num << " ";
        // cout << endl;
        pq.push(element);
    }

    while(!pq.empty()) {
        auto cur = pq.top();
        for(int num : cur)
            cout << num << " ";
        cout << endl;

        pq.pop();
    }
}