#include <iostream>
#include <vector>

using namespace std;

static int MOD = 1e9 + 7;


int main(){
    // dp[i][j] = minimum num of paths from i,j to n-1,n-1
    // dp[i][j] = dp[i+1][j] + dp[i][j+1] 
    //  if obstacle on i,j then no path => dp[i][j] = 0;
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n;
    cin>>n;
    vector<vector<char>> grid(n , vector<char> (n));
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            cin>>grid[i][j];
        }
    }
    

    // vector<vector<int>> dp(n , vector<int> (n, 0));
    vector<int> nextRow(n);
    if(grid[n-1][n-1] != '*') 
        nextRow[n-1] = 1;
    
    for(int i=n-1;i>=0;i--){
        vector<int> currRow(n);
        if(i == n-1)
            currRow[n-1] = nextRow[n-1];
        for(int j=n-1; j>=0; j--){
            if(grid[i][j] == '*') continue;
            if(i+1<n){
                currRow[j] = (currRow[j] + nextRow[j]) % MOD;
            }
            if(j+1 < n){
                currRow[j] = (currRow[j] + currRow[j+1]) % MOD;
            }
        }

        nextRow = currRow;
    }

    cout<<nextRow[0]<<"\n";

    return 0;
}