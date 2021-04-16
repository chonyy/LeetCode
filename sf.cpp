#include <bits/stdc++.h>

using namespace std;

unordered_map<int, int> m;

int f(int n)
{
    if (m[n])
        return m[n];

    if (n == 0)
        return 0;

    if (n % 10)
        return n % 10;

    int ans = f(n / 10);
    m[n] = ans;
    return ans;
}

void solve(int p, int q)
{
    int sum = 0;

    for (int i = p; i <= q; i++)
    {
        sum += f(i);
    }
    cout << sum << endl;
}

// might need to swap
int main()
{
    int p, q;
    string line;
    while (cin >> p >> q)
    {
        if (p == -1 && q == -1)
            break;

        if (p > q)
            swap(p, q);
        solve(p, q);
    }

    return 0;
}