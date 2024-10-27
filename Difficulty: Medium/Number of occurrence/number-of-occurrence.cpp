//{ Driver Code Starts
// Initial function template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:
    int count(vector<int>& arr, int target) {
        // code here
        int left=0,right =0;
        left = BS(arr,target,true);
        right=BS(arr,target,false);
        if(left==-1 && right==-1)return 0;
        else return right-left+1;
    }
    int BS(vector<int> &arr,int target,bool isLeft)
    {
        int ans =-1;
        int s =0,e=arr.size()-1;
        while(s<=e)
        {
            int mid = s+(e-s)/2;
            if(target>arr[mid])
            {
                s=mid+1;
            }
            else if(target<arr[mid])
            {
                e=mid-1;
            }
            else 
            {
                ans=mid;
                if(isLeft)
                {
                    e=mid-1;
                }
                else 
                {
                    s=mid+1;
                }
            }
        }
        return ans;
    }
    
};


//{ Driver Code Starts.

int main() {
    int test_case;
    cin >> test_case;
    cin.ignore();
    while (test_case--) {

        int d;
        vector<int> arr, brr, crr;
        string input;
        getline(cin, input);
        stringstream ss(input);
        int number;
        while (ss >> number) {
            arr.push_back(number);
        }
        getline(cin, input);
        ss.clear();
        ss.str(input);
        while (ss >> number) {
            crr.push_back(number);
        }
        d = crr[0];
        int n = arr.size();
        Solution ob;
        int ans = ob.count(arr, d);
        cout << ans << endl;
    }
    return 0;
}
// } Driver Code Ends