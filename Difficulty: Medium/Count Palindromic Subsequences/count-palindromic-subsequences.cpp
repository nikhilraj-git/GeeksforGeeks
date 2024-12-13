//{ Driver Code Starts
// Counts Palindromic Subsequence in a given String
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:
    

    /*You are required to complete below method */
    int countPS(string &s) {
        // Your code here
 int n = s.length();
        int mod = 1000000007;
        vector<vector<long>> dp(n, vector<long>(n, 0));

        for (int len = 0; len < n; len++) {
            for (int i = 0, j = len; j < n; i++, j++) {
                if (len == 0) {
                    dp[i][j] = 1; 
                } else {
                    if (s[i] == s[j]) {
                        dp[i][j] = (dp[i + 1][j] % mod + dp[i][j - 1] % mod + 1) % mod;
                    } else {
                        dp[i][j] = (dp[i + 1][j] % mod + dp[i][j - 1] % mod - dp[i + 1][j - 1] % mod + mod) % mod;
                    }
                }
            }
        }

        return dp[0][n - 1] % mod;
    
    }
};

//{ Driver Code Starts.
//  Driver program
int main() {
    int t;
    cin >> t;
    while (t--) {
        string str;
        cin >> str;
        Solution ob;
        int ans = ob.countPS(str);
        cout << ans << endl;
    }
}
// } Driver Code Ends