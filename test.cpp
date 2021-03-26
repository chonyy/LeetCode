# include<bits/stdc++.h>

using namespace std;

void bucketSort(vector<int>& arr) {
    vector<int> bucket(11, 0);
        for(int num : arr) {
            bucket[num+5] ++;
        }

        int idx = 0;
        for(int i = -5; i <= 5; i ++) {
            while(bucket[i+5]--) {
                arr[idx ++] = i;
            }
        }

        for(int num : arr)
            cout << num << " ";
}

int main() {
    vector<int> arr = {3, 2, 5, 1, -5, 5, -2};
    bucketSort(arr);
    return 0; 
}