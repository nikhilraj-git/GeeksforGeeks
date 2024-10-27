//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution{
	public:
	int solve(int n,int m,int mid)
	{
	    long long ans=1;
	    for(int i=1;i<=n;i++)
	    {
	        ans=ans*mid;
	        if(ans>m)return 2;
	    }
	    if(ans==m)return 1;
	    else return 0;
	}
	int NthRoot(int n, int m)
	{
	    // Code here.
	    if(m==1)return 1;
	    int s=0,e=m;
	    while(s<=e)
	    {
	        int mid=s+(e-s)/2;
	        int ans=solve(n,m,mid);
	        if(ans == 1)return mid;
	        else if(ans==2)
	        {
	            e=mid-1;
	           
	        }
	        else 
	        {
	            s=mid+1;
	        }
	    }
	    return -1;
	}  
};

//{ Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		int n, m;
		cin >> n >> m;
		Solution ob;
		int ans = ob.NthRoot(n, m);
		cout << ans << "\n";
	
cout << "~" << "\n";
}  
	return 0;
}
// } Driver Code Ends