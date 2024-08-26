#include <iostream>
#include <vector>

using namespace std;

static int MOD = 1e9 + 7;

bool isValid(int i,int m){
    return i>=1 && i<=m;
} 

int main(){
    // State: 
    // dp[i][k] = no of prefixes of length i such last element of this prefix = k

    // Transition: 
    // dp[i][k] = dp[i-1][k-1] + dp[i-1][k] + dp[i-1][k+1]

    // Base Case
    // dp[1][k] = 1 if a[0] = 0 || a[0] = k

    // Final case: sum(range_i(1,m)){dp[n][i]}
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n, m;
    cin>>n>>m;
    vector<int> a(n);
    for(int i=0;i<n;i++)
        cin>>a[i];
    vector<vector<int>> dp(n+1, vector<int> (m+1, 0));
    for(int k=1; k<=m; k++)
        dp[1][k] = ((a[0]==0 || a[0]==k)? 1 : 0);
    

    for(int i=2; i<=n; i++){
        for(int k=1; k<=m; k++){
            if(a[i-1] != 0 && a[i-1] != k){
                // dp[i][k] = 0;
                continue;
            }

            for(int p=k-1; p<=k+1; p++){
                if(isValid(p,m)){
                    dp[i][k] = (dp[i][k] + dp[i-1][p]) % MOD;
                }
            }
        }
    }
    int ans = 0;
    for(int k=1; k<=m; k++){
        ans = (ans + dp[n][k]) % MOD;
    }
    cout<< ans;

    return 0;
}