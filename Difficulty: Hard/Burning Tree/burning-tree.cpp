//{ Driver Code Starts
//Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

struct Node {
    int data;
    Node *left;
    Node *right;

    Node(int val) {
        data = val;
        left = right = NULL;
    }
};


Node *buildTree(string str) {
    // Corner Case
    if (str.length() == 0 || str[0] == 'N')
        return NULL;

    // Creating vector of strings from input
    // string after spliting by space
    vector<string> ip;

    istringstream iss(str);
    for (string str; iss >> str;)
        ip.push_back(str);

    // Create the root of the tree
    Node *root = new Node(stoi(ip[0]));

    // Push the root to the queue
    queue<Node *> queue;
    queue.push(root);

    // Starting from the second element
    int i = 1;
    while (!queue.empty() && i < ip.size()) {

        // Get and remove the front of the queue
        Node *currNode = queue.front();
        queue.pop();

        // Get the current Node's value from the string
        string currVal = ip[i];

        // If the left child is not null
        if (currVal != "N") {

            // Create the left child for the current Node
            currNode->left = new Node(stoi(currVal));

            // Push it to the queue
            queue.push(currNode->left);
        }

        // For the right child
        i++;
        if (i >= ip.size())
            break;
        currVal = ip[i];

        // If the right child is not null
        if (currVal != "N") {

            // Create the right child for the current Node
            currNode->right = new Node(stoi(currVal));

            // Push it to the queue
            queue.push(currNode->right);
        }
        i++;
    }

    return root;
}


// } Driver Code Ends
//User function Template for C++

/*
struct Node {
    int data;
    Node *left;
    Node *right;

    Node(int val) {
        data = val;
        left = right = NULL;
    }
};
*/
class Solution {
  public:
      void getParent(Node* root, unordered_map<Node*,Node*>&parTrack, int target,Node* &tarNode){
        if(!root)return;
        
        if(root->data==target)tarNode=root;
        
        if(root->left){
            parTrack[root->left]=root;
            getParent(root->left,parTrack,target,tarNode);
        }
        
        if(root->right){
            parTrack[root->right]=root;
            getParent(root->right,parTrack,target,tarNode);
        }
    }
    int minTime(Node* root, int target) 
    {
        // Your code goes here
          int ans=0;
        
        if(!root)return ans;
        
        unordered_map<Node*,Node*>parTrack;
        Node* tarNode;
        
        getParent(root, parTrack,target,tarNode);
        
        // traverse from the given target node;
        unordered_map<Node*,bool>vis;
        queue<Node*>q;
        q.push(tarNode);
        vis[tarNode]=true;
        
        while(!q.empty()){
            int s=q.size();
            
            for(int i=0;i<s;i++){
                Node* node=q.front();
                q.pop();
                
                if(!vis[node->left]&&node->left){
                    vis[node->left]=true;
                    q.push(node->left);
                }
                
                if(!vis[node->right]&&node->right){
                    vis[node->right]=true;
                    q.push(node->right);
                }
                
                if(!vis[parTrack[node]]&&parTrack[node]){
                    vis[parTrack[node]]=true;
                    q.push(parTrack[node]);
                }
            }
            
            ans++;
        }
        return ans-1;
    
    }
};

//{ Driver Code Starts.

int main() 
{
    int tc;
    scanf("%d ", &tc);
    while (tc--) 
    {    
        string treeString;
        getline(cin, treeString);
        // cout<<treeString<<"\n";
        int target;
        cin>>target;
        // cout<<target<<"\n";

        Node *root = buildTree(treeString);
        Solution obj;
        cout<<obj.minTime(root, target)<<"\n"; 

        cin.ignore();

    }


    return 0;
}

// } Driver Code Ends