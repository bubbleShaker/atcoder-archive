#include <bits/stdc++.h>
using namespace std;

int main(void){
    int A, B;
    cin >> A >> B;
    
    if((B-A) == 1 && ( B != 4 ) && ( B != 7)){
        cout << "Yes" << endl;
    }else{
        cout << "No" << endl;
    } 
    
    return 0;
}
