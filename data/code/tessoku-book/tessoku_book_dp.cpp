#include <bits/stdc++.h>
using namespace std;
int main(){
  int n,m;
  cin>>n>>m;
  vector<int> wAns(n+1);
  for(int i=0;i<m;i++){
    int a;
    cin>>a;
    wAns[a]++;
  }
  for(int i=1;i<=n;i++){
    cout<<m-wAns[i]<<endl;
  }
  return 0;
}