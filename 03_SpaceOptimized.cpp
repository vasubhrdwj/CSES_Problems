#include <iostream>
#include <vector>

using namespace std;

static int MOD = 1e9 + 7;


int main(){
    int n, x;
    cin>>n>>x;
    vector<int> c(n);

    for(int i=0;i<n;i++){
        cin>>c[i];
    }

    vector<vector<int>> dp(n+1, vector<int> (x+1));
    vector<int> nextState(x + 1,0);
    nextState[0] = 1;

    // dp[idx][sum] = dp[idx][k - c[idx]] + dp[idx+1][k]

    for(int i=0;i<n;i++){
        dp[i][0] = 1;
    }

    for(int i=n-1; i>=0; i--){
        vector<int> currState(x+1, 0);
        currState[0] = 1;
        for(int sum=1; sum<=x; sum++){
            int skip = nextState[sum];
            int pick = 0;
            if(c[i] <= sum){
                pick = currState[sum - c[i]];
            }

            currState[sum] = (skip + pick) % MOD;
        }
        nextState = currState;
    }
    
    cout<<nextState[x];
    return 0;
}