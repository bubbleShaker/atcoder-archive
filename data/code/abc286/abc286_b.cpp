#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main(void){
    int n;
    cin >> n;
    string s;
    cin >> s;
    string ans = "";
    for(int i = 0; i < s.size() ; i++) {
        if(s[i] == 'n' && s[i+1] == 'a') {
            ans += "nya";
            i++;
        }else{
            ans += s[i];
        }
    }
    cout << ans << endl;
    return 0;
}
