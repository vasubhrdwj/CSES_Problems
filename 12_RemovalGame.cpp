#include <iostream>
#include <vector>
#include <algorithm>
#include <climits>

#define ll long long

using namespace std;

// ll helper(int i, int j, int ch, vector<int>& arr,vector<vector<vector<ll>>>& dp){
//     if(i == j){
//         if(ch == 1) return 0;
//         return arr[i];
//     }

//     if(dp[i][j][ch] != INT_MIN)
//         return dp[i][j][ch];

//     if(ch == 0){ // A
//         ll op1 = arr[i] + helper(i+1, j, 1, arr, dp);
//         ll op2 = arr[j] + helper(i, j-1, 1, arr, dp);
//         return dp[i][j][ch] = max(op1, op2);
//     }
//     // If B it is
//     return dp[i][j][ch] = min(helper(i+1,j, 0, arr, dp), helper(i,j-1, 0 , arr, dp));
    
// }
int main(){
    
    int n;
    cin>>n;
    vector<int> arr(n);

    for(int i=0; i<n; i++)
        cin>>arr[i];

    // dp[i][j] = max Score for arr[i...j] for whoever's turn it is

    // dp[i][j] = max(a[i] + sum[i+1][j] - dp[i+1][j], 
    //                a[j] + sum[i][j-1] - dp[i][j-1])
    // dp[i][j][1] = min(dp[i+1][j][0], dp[i][j-1][0])

    // Base: dp[i][i] = arr[i]
    // Final : dp[0][n-1]

    vector<vector<ll>> dp(n, vector<ll> (n, 0));

    for(int i=0; i<n; i++){
        dp[i][i] = arr[i];
    }
    vector<vector<ll>> sum(n, vector<ll> (n, 0));

    for(int i=0; i<n; i++){
        sum[i][i] = arr[i];
        for(int j=i+1; j<n; j++){
            sum[i][j]  = sum[i][j-1] + arr[j];
            // cout<<"Sum from " << i << " to " << j << " is " << sum[i][j] << '\n';

        }
    }

    for(int i=n-1; i>=0; i--){
        for(int j=i; j<n; j++){
            if(i == j)
                dp[i][j] = arr[i];
            else{
                dp[i][j] = max(arr[i] + sum[i+1][j] - dp[i+1][j],
                arr[j] + sum[i][j-1] - dp[i][j-1]); 
            }
        }
    }

    cout << dp[0][n-1] << '\n';


    return 0;
}