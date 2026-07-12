#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main(void){
    string s;
    cin >> s;
    int diff = 'A' - 'a';
    for(int i = 0; i < s.size(); i++){
        s[i] += diff;
    }
    cout << s << endl;
    return 0;
}
