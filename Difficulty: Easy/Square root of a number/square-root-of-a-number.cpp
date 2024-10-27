//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// Function to find square root
// x: element to find square root
typedef long long int ll;
class Solution {
  public:
    ll floorSqrt(ll n) {
        // Your code goes here
        ll ans=0;
        if(n==1)return 1;
        ll s=1,e=n/2;
        while(s<=e)
        {
            ll mid =s+(e-s)/2;
            if(mid*mid==n)return mid;
            else if(mid*mid<n)
            {
                ans=mid;
                s=mid+1;
            }
            else 
            {
                e=mid-1;
            }
        }
        return ans;
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        long long n;
        cin >> n;
        Solution obj;
        cout << obj.floorSqrt(n) << endl;

        cout << "~"
             << "\n";
    }
    return 0;
}

// } Driver Code Ends