#include <iostream>
#include <vector>

using namespace std;

static int MOD = 1e9 + 7;


int main(){
    // State: 
    // dp[i][w] = maxm val we can get for prefix length i with capacity w

    // Transition: 
    // dp[i][w] = max(dp[i-1][w](not pick) + dp[i-1][w-pr[i]] + pg[i])
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n, x;
    cin>>n>>x;

    vector<int> wt(n), val(n); 

    for(int i=0; i<n; i++){
        cin>>wt[i];
    }
    for(int i=0; i<n; i++){
        cin>>val[i];
    }
    vector<vector<int>> dp(n+1, vector<int> (x+1));
    // dp[0][anything] = 0 => Base Case
    for(int i=1; i<n+1; i++){
        for(int j=0; j<=x; j++){
            int pick = 0;
            if(wt[i-1] <= j)
                pick = dp[i-1][j - wt[i-1]] + val[i-1];
            int notPick = dp[i-1][j];
            dp[i][j] = max(pick, notPick);
        }
    }

    cout<<dp[n][x]<<'\n';
    

    return 0;
}