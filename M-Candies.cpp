#include <iostream>
#include<vector>
using namespace std;
const int M=1e9+7;
int main() {
	int n,k;
	cin>>n>>k;
	vector<int>arr(n);
	for(int i=0;i<n;i++)
	{
	    cin>>arr[i];
	}
	vector<vector<int>>dp(n,vector<int>(k+1));
	for(int i=0;i<=arr[0];i++)
	{
	    dp[0][i]=1;
	}
	for(int i=1;i<n;i++)
	{
	    vector<int>pre_sum(k+1);
	    pre_sum[0]=dp[i-1][0];
	    for(int j=1;j<k+1;j++)
	    {
	        pre_sum[j]=(pre_sum[j-1]+dp[i-1][j])%M;
	    }
	   for(int j=0;j<k+1;j++)
	   {
	       if(j>arr[i])
	       {
	           dp[i][j]=(pre_sum[j]+M-pre_sum[j-arr[i]-1])%M;
	       }
	       else
	       {
	           dp[i][j]=pre_sum[j];
	       }
	   }
	}
	cout<<dp[n-1][k];
	return 0;
}
