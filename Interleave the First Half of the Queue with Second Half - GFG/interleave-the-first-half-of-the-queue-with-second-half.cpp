//{ Driver Code Starts
//Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function Template for C++

class Solution{
public:
    vector<int> rearrangeQueue(queue<int> &q){
        queue<int>second;
        // push first half of first queue into second q
        int sizeOne = q.size();
        int halfOne = sizeOne/2;
        for(int i=0;i<halfOne;i++){
            int temp=q.front();
            q.pop();
            second.push(temp);
        }
        vector<int> result;
        // merge both the halves
        // into the original queue -> q
        for(int i=0;i<halfOne;i++){
            int temp=second.front();
            second.pop();
            q.push(temp);
            
            temp=q.front();
            q.pop();
            q.push(temp);
        }
      // Convert the final queue to a vector
        while (!q.empty()) {
            result.push_back(q.front());
            q.pop();
        }
        return result;
    
    }
};

//{ Driver Code Starts.

int main(){
    
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        
        queue<int> q;
        for(int i=0;i<n;i++){
            int a;
            cin>>a;
            q.push(a);
        }
        Solution ob;
        vector<int> ans=ob.rearrangeQueue(q);
        for(int i=0;i<ans.size();i++){
            cout<<ans[i]<<" ";
        }
        cout<<endl;
    }
    
    return 0;
}
// } Driver Code Ends