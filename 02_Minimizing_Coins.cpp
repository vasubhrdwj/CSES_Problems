#include <iostream>
#include <vector>

using namespace std;



int main(){
    int n, sum;
    cin>>n>>sum;
    vector<int> c(n);

    for(int i=0;i<n;i++){
        cin>>c[i];
    }

    // dp[i] -> minimum num of coins to get sum of i

    vector<int> dp(sum + 1, 1e9);
    dp[0] = 0;

    for(int i=1; i<=sum; i++){
        for(int j=0;j<n;j++){
            if(c[j] <= i){
                dp[i] = min(dp[i], dp[i - c[j]] + 1);
            }
        }
    }
    

    cout<< (dp[sum] < 1e9? dp[sum] : -1);

    return 0;
}