#include<iostream>
#include<vector>
using namespace std; 
int g_c_d(int a, int b){
    if(a % b == 0) return b; 
    return g_c_d(b, a%b); 
}
int main(){

    int n, m; 
    cin >> n >> m; 

    vector<bool> boys(n), girls(m); 

    int a, b; 
    cin >> a; 

    while(a--){
        int k; 
        cin >> k; 
        boys[k] = true; 
    }

    cin >> b; 

    while(b--){
        int k; 
        cin >> k; 
        girls[k] = true; 
    }

    int big = max(m, n); 
    int small = min(m, n); 

    int gcd = g_c_d(big, small);     

    vector<bool> arr(gcd, false); 
    
    for(int i = 0; i < n; ++i){
        if(boys[i]){
            arr[i%gcd] = true; 
        }
    }

    for(int j = 0; j < m; ++j){
        if(girls[j]){
            arr[j%gcd] = true; 
        }
    }

    for(int i = 0;i < gcd; ++i){
        if(!arr[i]) {
            cout << "no" << endl; 
            return 0; 
        }
    }

    cout << "yes" << endl; 

    return 0; 
}