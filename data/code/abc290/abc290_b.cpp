#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main(void){
    int n, k;
    cin >> n >> k;
    string s;
    cin >> s;
    set<int> set;
    for(int i = 0; i < n; i++){
        if(set.size() == k) break;
        if(s[i] == 'o') set.insert(i);
    }
    string t;
    for(int i = 0; i < n; i++){
        if(set.count(i)){
            t.push_back('o');
            set.erase(i);
        }else{
            t.push_back('x');
        }
    }
    cout << t << endl;
    return 0;
}