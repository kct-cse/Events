#include<bits/stdc++.h>
using namespace std; 

int maxCities(vector<vector<char>> &a, int n, int m);


// Driver code to test above functions
int main()
{

    
    int t;
    cin >> t;
    while(t--)
    {
        int n, m;
        cin >> n >> m;

        vector<vector<char>> a(n, vector<char>(m));

        for (int i = 0; i < n; ++i)
        {
            for (int j = 0; j < m; ++j)
            {
                cin >> a[i][j];
            }
        }

        cout << maxCities(a, n, m) << "\n";

    }


    return 0; 
}// } Driver Code Ends

int maxCities(vector<vector<char>> &arr, int n, int m)
{
    // Your code goes here
    int dx[8] = {0, 0, -1, -1, -1, 1, 1, 1}; 
    int dy[8] = {-1, 1, -1, 1, 0, -1, 0, 1}; 
    
    for(int i = 0;i < n; ++i){
        for(int j = 0;j < m; ++j){
            if(arr[i][j] == '*'){
                
                for(int a = 0; a < 8; ++a){
                    if(dx[a]+i < 0 || dy[a]+j < 0 || dx[a]+i >= n || dy[a] + j >= m) continue; 
                    int newi = dx[a] + i; 
                    int newj = dy[a] + j; 
                    
                    if(arr[newi][newj] == '.'){
                        arr[newi][newj] = '+'; 
                    }
                }
            }
        }
    }
    
    vector<vector<bool>> visited(n, vector<bool>(m, false)); 
    int maxCount = 0; 
    
    for(int i = 0;i < n; ++i){
        for(int j = 0;j < m; ++j){
            if(visited[i][j]){
                continue; 
            }
            visited[i][j] = true; 
            
            if(arr[i][j] != '+'){
                continue; 
            }
            
            vector<pair<int, int>> adj;
            int counter = 0; 
            adj.push_back(make_pair(i, j));
            
            int count = 1; 
            while(counter < adj.size()){
                 
                int tempi = adj[counter].first, tempj = adj[counter].second; 
                
                for(int a = 0;a < 8; ++a){
                    int newi = dx[a]+tempi; 
                    int newj = dy[a]+tempj; 
                    
                    if(dx[a]+tempi < 0 || dy[a]+tempj < 0 || dx[a]+tempi >= n || dy[a] + tempj >= m) {
                        
                        continue; 
                    } 
                    
                    if(arr[newi][newj] == '+' && !visited[newi][newj]){
                        adj.push_back(make_pair(newi, newj)); 
                        count++; 
                    }
                    
                    visited[newi][newj] = true;  
                }
                counter++; 
            }
            
            if(maxCount < count) maxCount = count; 
        }
    }
    return maxCount; 
}
