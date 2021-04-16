#include <bits/stdc++.h>

using namespace std;

void solve(vector<double> &nums)
{
    double sum = 0;
    for (double num : nums)
        sum += num;

    double average = (sum * 100.0) / nums.size();
    cout << average << endl;

    double highAvg = 0, lowAvg = 0;

    for (double num : nums)
    {
        if (num > average)
            highAvg += num - average;
        if (num < average)
            lowAvg += average - num;
    }

    double res = min(highAvg, lowAvg);

    printf("$%.2f\n", res / 100.0);
}

int main()
{
    int k;

    while (cin >> k && k != 0)
    {
        vector<double> nums;
        for (int i = 0; i < k; i++)
        {
            double temp;
            cin >> temp;
            nums.push_back(temp);
        }
        solve(nums);
    }

    return 0;
}