//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution{

	public:
	int mod=1e9+7;
int countSum(int arr[],int n,int i,int target,
vector<vector<int>>&dp){
 
    if(i<0)
    return target==0?1:0;
    
    if(dp[i][target]!=-1)
    return dp[i][target];
    
    int notPick=countSum(arr,n,i-1,target,dp)%mod;
    int pick=0;
    if((target-arr[i])>=0)
    pick=countSum(arr,n,i-1,target-arr[i],dp)%mod;
    
    return dp[i][target]=(pick+notPick)%mod;
}
 
int perfectSum(int arr[], int n, int sum)
{
        // Your code goes here
        vector<vector<int>>dp(n,vector<int>(sum+1,-1));
        return countSum(arr,n,n-1,sum,dp);
        
}
	  
};

//{ Driver Code Starts.
int main() 
{
   	
   
   	int t;
    cin >> t;
    while (t--)
    {
        int n, sum;

        cin >> n >> sum;

        int a[n];
        for(int i = 0; i < n; i++)
        	cin >> a[i];

       

	    Solution ob;
	    cout << ob.perfectSum(a, n, sum) << "\n";
	     
    }
    return 0;
}

// } Driver Code Ends