#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main(void){
    int N;
    cin >> N;
    vector<int> A(100000);
    
    cin >> A[0];
    
    for(int i = 1;;){
        int tmp1;
        cin >> tmp1;
        if(cin.eof()) break;
        if(abs(tmp1 - A[i-1]) != 1){
            if(tmp1 > A[i-1]){
                int dif = tmp1 - A[i-1] + 1;
                for(int j = 1; j < dif; j++){
                    A[i] = A[i-1]+1;
                    i++;
                }
            }else{
                int dif = A[i-1] - tmp1 + 1;
                for(int j = 1; j < dif; j++){
                    A[i] = A[i-1]-1;
                    i++;
                }
            }
        }else{
            A[i] = tmp1;
            i++;
        }
    }
    
    int i = 0;
    
    while(1){
        cout << A[i];
        i++;
        if(A[i] == 0) break;
        else cout << " ";
    }
    
    return 0;
}