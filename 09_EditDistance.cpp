#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;


int main(){
    
    // ios::sync_with_stdio(0);
    // cin.tie(0);

        string s1, s2;
        cin >>s1;
        cin>>s2; 
        int m, n;
        m = s1.size(), n=s2.size();

        // dp[i][j] = Minim edit distance b/w first i character of first string
        //  and first j characters of second string

        // Transition:
        // dp[i][j] = dp[i-1][j-1] if(s1[i] == s2[j])
        // else dp[i][j] = minm(dp[i-1][j-1], dp[i-1][j], dp[i][j-1]) + 1;
        //                      replace      rem from 1   rem from 2
        // Base : if i chars in s1 and no chars in s2 => remove i items from s2
        // dp[i][0] = i, dp[0][i] = i, dp[0][0] = 0;
        vector<vector<int>> dp(m+1, vector<int> (n+1, 0));
        for(int i=0; i<=m; i++){
            dp[i][0] = i;
        } 
        for(int i=0; i<=n; i++){
            dp[0][i] = i;
        }

        for(int i=1; i<=m; i++){
            for(int j=1; j<=n; j++){
                if(s1[i-1] == s2[j-1]){
                    dp[i][j] = dp[i-1][j-1]; // Just continue
                }
                else{
                    dp[i][j] = min(
                        {dp[i-1][j-1] + 1, // Replace any one
                        dp[i-1][j] + 1, // Remove from s1
                        dp[i][j-1] + 1 // Remove from s2
                        });
                }
            }
        }

        cout << dp[m][n] << '\n';

    return 0;
}