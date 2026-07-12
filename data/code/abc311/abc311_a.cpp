#include <bits/stdc++.h>
using namespace std;

int main(void){
    int N;
    cin >> N;
    string s;
    cin >> s;
    int ca = 0, cb = 0, cc = 0;
    int ans = 0;
    for(int i = 0; i < N; i++){
        int t = i;
        if(s[i] == 'A') ca++;
        else if(s[i] == 'B') cb++;
        else if(s[i] == 'C') cc++;
        if((ca >= 1) && (cb >= 1) && (cc >= 1)){
            ans = t+1;
            break;
        }
    }
    
    cout << ans << endl;
    return 0;
}