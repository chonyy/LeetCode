# include<bits/stdc++.h>

using namespace std;

void solve(long long num) {
    vector<pair<long long, string>> units = {{10000000, "kuti"}, {100000, "lakh"}, {1000, "hajar"}, {100, "shata"}};
    for(auto unit : units) {
        if(num >= unit.first) {
            solve(num / unit.first);
            cout << " " << unit.second;
            num = num % unit.first;
        }
    }
    if(num)
        cout << " " << num;
}

int main() {
    long long num;
    int k = 1;
    while(cin >> num) {
        cout << setw(4) << k << ".";
        if(num)
            solve(num);
        else
            cout << " 0";
        cout << endl;
        k ++;
    }
    return 0; 
}