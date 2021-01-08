#include<iostream>
#include<vector>
using namespace std; 
int main(){
    
    int n; 
    cin >> n; 
    
    vector<string> arr; 
    
    for(int i = 0;i < n; ++i){
        string input; 
        cin >> input;
        arr.push_back(input); 
    }
    
    vector<int> rowChocolatecount(n, 0); 
    vector<int> colChocolatecount(n, 0); 
    
    for(int i = 0;i < n; ++i){
        for(int j = 0; j < n; ++j){
            if(arr[i][j] == 'C'){
                rowChocolatecount[i]++; 
            }
            
            if(arr[j][i]  == 'C'){
                colChocolatecount[i] ++; 
            }
        }
    }
 
    int rowpairCount = 0, colpairCount = 0; 
    
    for(int i = 0;i < n; ++i){
        rowpairCount += (rowChocolatecount[i] * (rowChocolatecount[i]-1))/2; 
        colpairCount += (colChocolatecount[i] * (colChocolatecount[i] - 1))/2; 
    }
 
    cout << rowpairCount + colpairCount << endl; 
 
    return 0; 
}