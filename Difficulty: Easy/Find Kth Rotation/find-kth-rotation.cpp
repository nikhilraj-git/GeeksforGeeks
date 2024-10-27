//{ Driver Code Starts
#include <bits/stdc++.h>

using namespace std;


// } Driver Code Ends
// User function template for C++
class Solution {
  public:
    int findKRotation(vector<int> &arr) {
        // Code Here
        int n = arr.size();
        int ans=INT_MAX;
        int ind = -1;
        if(arr[0]<arr[n-1])
            return 0;
        
        
        
        int s=0,e=arr.size()-1;
        while(s<=e)
        {
            int mid = s+(e-s)/2;
            
            if(arr[s]<=arr[e])
            {
                if(ans>arr[s])
                {
                    ans=arr[s];
                    ind = s;
                }
                break;
            }
            if(arr[mid]>=arr[s])
            {
                if(ans>arr[s])
                {
                    ans=arr[s];
                    ind = s;
                }
                s=mid+1;
            }           
            else 
            {
                if(arr[mid]<ans)
                {
                    ans=arr[mid];
                    ind=mid;
            }
            e= mid-1;
        
            }
        }
        return ind;
    }
    
};


//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    cin.ignore();
    while (t--) {
        vector<int> arr;
        string input1;
        getline(cin, input1);
        stringstream ss1(input1);
        int number1;
        while (ss1 >> number1) {
            arr.push_back(number1);
        }
        Solution ob;
        int res = ob.findKRotation(arr);
        cout << res << endl;
        cout << "~" << endl;
    }
}

// } Driver Code Ends