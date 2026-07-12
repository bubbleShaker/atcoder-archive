#include <bits/stdc++.h>
using namespace std;

int main(){
  int n;
  cin>>n;
  vector<int> p(n+1);
  vector<int> q(n+1);
  for(int i=1;i<=n;i++){
    cin>>p[i];
    q[p[i]]=i;
  }
  for(int i=1;i<=n;i++){
    cout<<q[i]<<" ";
  }cout<<endl;
  return 0;
}