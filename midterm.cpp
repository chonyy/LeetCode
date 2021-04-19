#include <bits/stdc++.h>

using namespace std;

int countt = 0;

// might need long long
long long dfs(vector<int> &parent, int i)
{
    if (parent[i] == i)
        return 0;

    return abs(i - parent[i]) + dfs(parent, parent[i]);
}

void ask(vector<int> &parent, int i)
{
    long long dist = dfs(parent, i);
    if (countt)
        cout << endl;
    cout << dist;
}

void link(vector<int> &parent, int i, int j)
{
    parent[i] = j;
}

// might need to swap
int main()
{
    int k;
    cin >> k;
    char cmd;
    int a, b;
    int n;

    for (int i = 0; i < k; i++)
    {
        cin >> n;
        vector<int> parent(n + 1);
        for (int i = 0; i <= n; i++)
        {
            parent[i] = i;
        }

        while (cin >> cmd && cmd != 'O')
        {
            if (cmd == 'E')
            {
                cin >> a;
                ask(parent, a);
                countt++;
            }
            if (cmd == 'I')
            {
                cin >> a >> b;
                link(parent, a, b);
            }
        }
    }
}