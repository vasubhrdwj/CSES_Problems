#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;


int main(){
    
    ios::sync_with_stdio(0);
    cin.tie(0);
    int a, b;
    cin>>a>>b;

    vector<vector<int>> dp (a+1, vector<int> (b+1, 1e9));


    for(int i=1; i<=a; i++){
        for(int j=1; j<=b; j++){
            if(i == j){
                dp[i][j] = 0;
                continue;
            }
            // vertical cut
            for(int v=1; v<i ;v++){
                dp[i][j] = min(dp[i][j], dp[i-v][j] + dp[v][j] + 1);
            }
            for(int h=1; h<j; h++){
                dp[i][j] = min(dp[i][j], dp[i][j-h] + dp[i][h] + 1);
            }
            
        }
    }

    cout<< dp[a][b] << '\n';

        

    return 0;
}