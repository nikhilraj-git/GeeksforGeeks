//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

class Matrix {
  public:
    template <class T>
    static void input(vector<vector<T>> &A, int n, int m) {
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                scanf("%d ", &A[i][j]);
            }
        }
    }

    template <class T>
    static void print(vector<vector<T>> &A) {
        for (int i = 0; i < A.size(); i++) {
            for (int j = 0; j < A[i].size(); j++) {
                cout << A[i][j] << " ";
            }
            cout << endl;
        }
    }
};


// } Driver Code Ends

class Solution {
  public:
    int MinimumEffort(int rows, int columns, vector<vector<int>> &heights) {
        // code here
        vector<vector<int>> dist(rows,vector<int>(columns,1e9));
        priority_queue<pair<int,pair<int,int>>,vector<pair<int,pair<int,int>>>,greater<pair<int,pair<int,int>>>> pq;
        dist[0][0] =0;
        pq.push({0,{0,0}});
        
        int dx[]={-1,1,0,0};
        int dy[]={0,0,-1,1};
        while(!pq.empty())
        {
            auto it = pq.top();
            pq.pop();
            int diff= it.first;
            int row = it.second.first;
            int col = it.second.second;
            
            if(row == rows-1 && col == columns-1)
                return diff;
            
            for(int i=0;i<4;i++)
            {
                int nx = row+dx[i];
                int ny = col+dy[i];
                if(nx>=0 && ny>=0 && nx<rows && ny<columns)
                {
                    int newEffort = max(abs(heights[row][col]-heights[nx][ny]),diff);
                    if(newEffort<dist[nx][ny])
                    {
                        dist[nx][ny]=newEffort;
                        pq.push({newEffort,{nx,ny}});
                    }
                }
            }
        }
        
    }
};


//{ Driver Code Starts.

int main() {
    int t;
    scanf("%d ", &t);
    while (t--) {

        int rows;
        scanf("%d", &rows);

        int columns;
        scanf("%d", &columns);

        vector<vector<int>> heights(rows, vector<int>(columns));
        Matrix::input(heights, rows, columns);

        Solution obj;
        int res = obj.MinimumEffort(rows, columns, heights);

        cout << res << endl;
    }
}

// } Driver Code Ends