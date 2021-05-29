#include <bits/stdc++.h>
using namespace std;

<<<<<<< HEAD
// L: 8, a = {4, 1, 2, 5}
// 8 + 4 + 3 + 4
=======
bool cmp(vector<int> a, vector<int> b) {
    if(a[1] == b[1]) {
        if(a[2] == b[2])
            return a[0] > b[0];
        return a[2] > b[2]; 
    }
    return a[1] < b[1];
}

void solve(vector<string> lines) {
    // entry: <contestant, <problem, <solved, penalty>>>
    unordered_map<int, unordered_map<int, pair<bool, int>>> contest;
    for(string line : lines) {
        // Process the input
        string temp;
        istringstream ss(line);
        ss >> temp;
        int contestant = stoi(temp);
        ss >> temp;
        int problem = stoi(temp);
        ss >> temp;
        int time = stoi(temp);
        ss >> temp;
        char L = temp[0];

        // Start counting
        auto& problemEntry = contest[contestant][problem];
<<<<<<< HEAD
=======
        if(problemEntry.first)
            continue;
>>>>>>> b8ae7f068a866f309bbc4f48dffd01824050c0a7
        if(L == 'C') {
            problemEntry.first = true;
            problemEntry.second += time;
        }
        else if(L== 'I') {
            problemEntry.second += 20;
        }
    }
>>>>>>> e35af07fbfbc221f6cfcd9410a51dd07d64a6e70

int getTotalCost(int L, vector<int> a) {
    // observation: coord
}

int main() {

}
<<<<<<< HEAD
=======

<<<<<<< HEAD
// 2

// 1 2 10 I
// 3 1 11 C
// 1 2 19 R
// 1 2 21 C
// 1 1 25 C

// 1 2 10 I
// 3 1 11 C
=======
>>>>>>> b8ae7f068a866f309bbc4f48dffd01824050c0a7
>>>>>>> e35af07fbfbc221f6cfcd9410a51dd07d64a6e70
