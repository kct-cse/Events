#include<iostream>
#include<algorithm>
using namespace std; 
inline bool isPossible(const int& digitCount, const int& SumOfDigits){
    return (SumOfDigits >= 0 && SumOfDigits <= 9 * digitCount); 
}
int main(){
    int digitCount, SumOfDigits; 

    cin >> digitCount >> SumOfDigits; 

    string min = ""; 
    int s = SumOfDigits; 

    if(digitCount == 1 && SumOfDigits == 0){
        cout << "0 0" << endl; 
        return 0; 
    } 

    for(int i = 1; i <= digitCount; ++i){
        for(int d = 0; d <= 9; ++d){
            if(i == 1 && d == 0) continue; 

            if(isPossible(digitCount-i, SumOfDigits-d)){
                min += to_string(d); 
                SumOfDigits -= d; 
                break;  
            }
        }

        if(min == ""){
            cout << "-1 -1" << endl; 
            return 0; 
        }
    }

    string max = ""; 
    SumOfDigits = s; 
    int digitsLeft = digitCount; 

    while(SumOfDigits > 9){
        digitsLeft--; 
        SumOfDigits -= 9; 
        max += "9"; 
    }

    max += to_string(SumOfDigits); 
    digitsLeft--; 

    while(digitsLeft > 0){
        max += "0"; 
        digitsLeft--; 
    }

    cout << min << " " << max << endl; 

    return 0; 
}