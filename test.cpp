#include<bits/stdc++.h>

using namespace std;

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
        if(L == 'C') {
            problemEntry.first = true;
            problemEntry.second += time;
        }
        else if(L== 'I') {
            problemEntry.second += 20;
        }
    }

    // Sort the result
    priority_queue<vector<int>, vector<vector<int>>, decltype(&cmp)> pq(cmp);
    for(auto contestant : contest) {
        int problemSolved = 0;
        int penaltyTime = 0;
        for(auto prob : contestant.second) {
            auto problemEntry = prob.second;
            // cout << "Prob: " << prob.first << " " << problemEntry.first << " " << problemEntry.second << endl;
            if(problemEntry.first) {
                problemSolved ++;
                penaltyTime += problemEntry.second;
            }
        }
        pq.push({contestant.first, problemSolved, penaltyTime});
    }

    // Ouput result
    while(!pq.empty()) {
        auto entry = pq.top();
        pq.pop();
        cout << entry[0] << " " << entry[1] << " " << entry[2] << endl;
    }
}

int main()
{
    int cases;
    cin >> cases;
    cin.ignore();
    cin.ignore();

    for(int i = 0; i < cases; i ++) {
        if(i)
            cout << endl;
        
        string line;
        vector<string> lines;
        while(getline(cin, line)) {
            if(line == "")
                break;
            lines.push_back(line);
        }

        solve(lines);
    }
}

// 2

// 1 2 10 I
// 3 1 11 C
// 1 2 19 R
// 1 2 21 C
// 1 1 25 C

// 1 2 10 I
// 3 1 11 C