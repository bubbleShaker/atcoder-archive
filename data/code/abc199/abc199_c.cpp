#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main(void){
    int N;
    cin >> N;
    string S;
    cin >> S;
    int Q;
    cin >> Q;
    
    bool fl = false;
    int N2 = N * 2;
    for(int i = 0; i < Q; i++){
        int T, A, B;
        cin >> T >> A >> B;
        A--; B--;
        if(T == 1){
            if(!fl){
                swap(S[A], S[B]);
            }else{
                swap(S[(A+N)%N2], S[(B+N)%N2]);
            }
        }else{
            fl = !fl;
        }
    }
    
    string s1 = S.substr(0, N);
    string s2 = S.substr(N);
    
    if(fl){
        cout << s2 << s1 << endl;
        return 0;
    }
    cout << S << endl;
    return 0;
}