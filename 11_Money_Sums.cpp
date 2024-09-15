#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;


int main(){
    
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n;
    cin>>n;
    vector<int> coins(n);
    for(int i=0;i<n;i++)
        cin>>coins[i];

    vector<int> possible(1e5+1, false);
    possible[0] = 1;

    for(int i=0; i<n; i++){
        vector<int> temp(1e5+1, false);
        int curr = coins[i];

        for(int j=0; j<=1e5; j++){
            if(possible[j]){
                temp[j + curr] = true;
                temp[j] = true;
            }
        }

        possible = temp;
    }
    vector<int> ans;
    for(int i=1 ; i<=1e5;i++){
        if(possible[i]){
            ans.push_back(i);
        }
    }
    cout<<ans.size()<<'\n';
    for(auto val : ans){
        cout<<val<<' ';
    } 

    return 0;
}