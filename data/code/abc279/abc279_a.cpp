#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ull = unsigned long long;
#define rep(i,n) for(int i = 0; i < (n); i++)
using P = pair<int,int>;

int main(void){
  string s;
  cin >> s;
  int ans = 0;
  for(char c : s) {
    if(c == 'v') ans++;
    else ans += 2;
  }
  cout << ans << endl;
  return 0;
}
