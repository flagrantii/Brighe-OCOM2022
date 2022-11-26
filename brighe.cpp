#include<bits/stdc++.h>
using namespace std;
vector<int> a;
vector<int> b;

int solve(int n)
{
	int dp[n+1][n+1];
    for(int i=0;i<=n;i++){
        for(int j=0;j<=n;j++){
            if(i==0 or j==0){
                dp[i][j]=0;
            }else if(i>=1 and j>=1){
                if(a[i-1]==b[j-1]){
                    dp[i][j]=dp[i-1][j-1]+1;
                }else if(a[i-1]!=b[j-1]){
                    dp[i][j]=max(dp[i-1][j],dp[i][j-1]);
                }
            }
        }
    }
    return dp[n][n];
}
int main ()
{
    int n;
    cin>>n;
    int x;
    for(int i=0;i<n;i++){
        cin>>x;
        a.push_back(x);
    }
    for(int i=0;i<n;i++){
        cin>>x;
        b.push_back(x);
    }
    cout<<solve(n);
    return 0;
}
