#include <bits/stdc++.h>
using namespace std;

int main(){
  int n;
  cin>>n;
  vector<int> p(n+1),q(n+1);
  map<int,int> ze_pe,pe_ze;
  for(int i=1;i<=n;i++)cin>>p[i];
  for(int i=1;i<=n;i++)cin>>q[i],ze_pe[q[i]]=i,pe_ze[i]=q[i];
  for(int i=1;i<=n;i++){
    int pe=ze_pe[i];
    cout<<pe_ze[p[pe]]<<" ";
  }cout<<endl;
  return 0;
}