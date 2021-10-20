#include <iostream>
#include<vector>
using namespace std;
const int N=402;
long long INF=1e18;
long long dp[N][N],sum[N][N];
int main() {
	int n;
	cin>>n;
	vector<int>arr(n);
	for(int i=0;i<n;i++)
	{
	    cin>>arr[i];
	}
	for(int i=0;i<n;i++)
	{
	    sum[i][i]=arr[i];
	    dp[i][i]=0;
	}
	for(int width=2;width<=n;width++)
	{
	    for(int l=0,r=width-1;r<n;l++,r++)
	    {
	       sum[l][r]=arr[l]+sum[l+1][r];
	       dp[l][r]=INF;
	       for(int x=l;x<r;x++)
	       {
	          dp[l][r]=min(dp[l][r],dp[l][x]+dp[x+1][r]+sum[l][r]); 
	       }
	    }
	}
	cout<<dp[0][n-1];
	return 0;
}
