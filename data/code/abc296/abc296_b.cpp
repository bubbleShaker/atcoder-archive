#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main(void){
    vector<string> S(8);
    for(int i = 0; i < 8; i++) cin >> S[i];
    
    vector<char> c = {'a', 'b', 'c', 'd', 'e', 'f', 'g', 'h'};
    
    for(int i = 0; i < 8; i++){
        for(int j = 0; j < 8; j++){
            if(S[i][j] == '*'){
                cout << c[j] << 8-i << endl;
                return 0;
            }
        }
    }
}
