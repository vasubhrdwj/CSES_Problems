#include <iostream>
#include <vector>

using namespace std;

static int MOD = 1e9 + 7;


int main(){
    int n;
    cin>>n;

    vector<int> dp(n+1, 1e9);
    dp[0] = 0;
    

    for(int i=1; i<=n; i++){
        string dig = to_string(i);
        for(int j=0; j<dig.size(); j++){
            dp[i] = min(dp[i] , dp[i - (dig[j] - '0')] + 1);
        }
    }
    cout<<dp[n]<<endl;



    return 0;
}