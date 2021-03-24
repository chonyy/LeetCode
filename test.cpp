# include<bits/stdc++.h>

using namespace std;

void execute(vector<int>& reg, vector<int>& ram, int e, int d, int n, int &pc) {
    if(e == 0) {
        if(ram[n] == 0) {
            cout << "return" << endl;
            return;
        }
        pc = reg[d];
    }
    else if(e == 2) {
        reg[d] = n;
    }
    else if(e == 3) {
        reg[d] += n;
    }
    else if(e == 4) {
        reg[d] *= n;
    }
    else if(e == 5) {
        reg[d] = reg[n];
    }
    else if(e == 6) {
        reg[d] += reg[n];
    }
    else if(e == 7) {
        reg[d] *= reg[n];
    }
    else if(e == 8) {
        reg[d] = ram[reg[n]];
    }
    else if(e == 9) {
        ram[reg[n]] = reg[d];
    }
    reg[d] %= 1000;
    cout << "reg " << d  << ": " << reg[d] << endl;
}

void solve(vector<int>& reg, vector<int>& ram) {
    int pc = 0;
    int count = 0;
    while(true) {
        int instruction = ram[pc];
        int d = instruction % 100 / 10;
        int n = instruction % 10;
        int e = instruction / 100;

        pc ++;
        count ++;

        cout << pc << endl;

        if(e == 1)
            break;
        execute(reg, ram, e, d, n, pc);
    }
    cout << count;
}

int main() {
    int k;
    cin >> k;
    for(int i = 0; i < k; i ++) {
        string command;
        vector<int> reg(10, 0);
        vector<int> ram(1000, 0);
        int cur = 0;
        getline(cin, command);
        getline(cin, command);
        cout << command;
        while(getline(cin, command) && !command.empty()) {
            ram[cur++] = stoi(command);
        }
        solve(reg, ram);
        if(i != k - 1)
            cout << endl;
    }
    return 0; 
}
