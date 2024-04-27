#include <bits/stdc++.h>
#define ll long long

using namespace std;
const ll MOD = 1e9 + 7;

void solve1(int n)
{
    vector<int> dp(n + 1);
    // dp[k] =>Num of ways to get a sum k
    dp[0] = 1; // Base(for 0 we have only 1 way)
    // dp[1] = dp[0]
    // dp[2] = dp[1] + dp[0]
    // dp[k] = dp[k-1]+......+dp[k-6]
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= 6; j++)
        {
            if (j <= i) // transition
                dp[i] = (dp[i] + dp[i - j]) % MOD;
        }
    }
    // final state
    cout << dp[n] << endl;
}

// Another Method
void solve2(int n)
{
    vector<int> dp(n + 1);
    // dp[i] = num of ways to get sum of n from
    // current state i
    dp[n] = 1;
    // for ex : dp[2] = dp[2 + 1] => ways to reach 3 from 2
    for (int i = n - 1; i >= 0; i--)
    {
        for (int j = 1; j <= 6; j++)
        {
            if (j <= n - i)
            {
                dp[i] = (dp[i] + dp[i + j]) % MOD;
            }
        }
    }

    cout << dp[0] << endl;
}

int main()
{
    int n;
    cin >> n;
    solve1(n);

    return 0;
}