#include <bits/stdc++.h>

using namespace std;



void solve(){

    int n;

    cin>>n;

    string s;

    cin>>s;

    vector<int>dp(n+1);

    vector<vector<bool>>mp(n+5, vector<bool>(n+5, false));

    for(int i=1; i<=n; i++){

        mp[i][i]=true;

        dp[i]=i;

    }

    s = ' '+s;

    for(int j=2; j<=n; j++){

        for(int i=j; i>0; i--){

            if(s[i]==s[j] && (mp[i+1][j-1] || i>=j-1)){

                mp[i][j]=true;

                dp[j]=min(dp[i-1]+1, dp[j]);

            }

        }

        // cout<<dp[j]<<' ';

    }

    cout<<dp[n]<<endl;

}



int main() {

    int t; 

    cin>>t;

    while(t--){

        solve();

    }

	// your code goes here

	return 0;

}

