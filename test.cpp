# include<bits/stdc++.h>

using namespace std;

void solve(vector<int>& nums) {
	for(int i : nums) {
    	cout << i << endl;
    }
}

int main() {
    int n;
    cin >> n;
    vector<int> nums;
    int temp;

    while(n--) {
        cin >> temp;
        nums.push_back(temp);
    }

    solve(nums);

    return 0; 
}