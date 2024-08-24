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

    // dp[k] -> Number of ways to get a sum k
    // dp[k] = sum(dp[k - c[j]]) for all j -> 0 to n-1

    vector<int> dp(x + 1);
    dp[0] = 1;

    for(int i=1; i<=x; i++){
        for(int j=0;j<n;j++){
            if(c[j] <= i){
                dp[i] = (dp[i]  + dp[i - c[j]]) % MOD;
            }
        }
    }
    

    cout<< dp[x];

    return 0;
}