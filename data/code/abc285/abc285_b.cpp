#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i,n) for(int i = 0; i < (n); i++)

int main(void){
    int n;
    cin >> n;
    string s;
    cin >> s;
    for(int i = 1; i <= n-1; i++) {
        int l = 0;
        while(i+l <= n-1) {
            if(s[l] == s[l+i]) break;
            l++;
        }
        cout << l << endl;
    }
    return 0;
}
