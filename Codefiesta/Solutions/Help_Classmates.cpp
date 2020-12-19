//Initial Template for C++

#include <bits/stdc++.h> 
using namespace std; 

vector<int> help_classmate(vector<int> array, int n) 
{ 
    // code here 
    vector<int> result; 
    
    for(int i = 0;i < n; ++i){
        int ans = -1; 
        for(int j = i+1;j < n; ++j){
            if(array[i] > array[j]){
                ans = array[j]; 
                break; 
            }
        }
        result.push_back(ans); 
    }
    return result; 
} 

// { Driver Code Starts.

int main() 
{ 
    int t;
    cin>>t;
    while(t--)
    {
        int n;
        cin>>n;
        vector<int> array(n);
        for (int i = 0; i < n; ++i)
        {
            cin>>array[i];
        }
        vector<int> result = help_classmate(array,n);
        for (int i = 0; i < n; ++i)
        {
            cout<<result[i]<<" ";
        }
        cout<<"\n";
    }
    return 0; 
}  // } Driver Code Ends
