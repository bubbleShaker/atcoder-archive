#include <bits/stdc++.h>
using namespace std;
using P=pair<int,int>;

int main(){
  int n,k;
  cin>>n>>k;
  vector<P> a(n);
  vector<int> b(k);
  set<int> st;
  for(int i=0;i<n;i++)cin>>a[i].first,a[i].second=i;;
  for(int i=0;i<k;i++)cin>>b[i],st.insert(--b[i]);
  sort(a.rbegin(),a.rend());
  for(int i=0;i<n;i++){
    auto [del,ind]=a[i];
    if(st.count(ind)&&del==a[0].first){
      cout<<"Yes"<<endl;
      return 0;
    }
  }
  cout<<"No"<<endl;
  return 0;
}