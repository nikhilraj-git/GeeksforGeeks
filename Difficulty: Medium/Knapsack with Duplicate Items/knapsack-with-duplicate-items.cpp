//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++
#include<bits/stdc++.h>
class Solution{
public:
    int knapSack(int N, int W, int val[], int wt[])
    {
        // code here
         vector<int> dp(W + 1, 0);
        
        for (int i = 0; i < N; i++) {
            for (int j = wt[i]; j <= W; j++) {
                dp[j] = max(dp[j], val[i] + dp[j - wt[i]]);
            }
        }
        
        return dp[W];
    
    }
};

//{ Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        int N, W;
        cin>>N>>W;
        int val[N], wt[N];
        for(int i = 0;i < N;i++)
            cin>>val[i];
        for(int i = 0;i < N;i++)
            cin>>wt[i];
        
        Solution ob;
        cout<<ob.knapSack(N, W, val, wt)<<endl;
    }
    return 0;
}
// } Driver Code Ends