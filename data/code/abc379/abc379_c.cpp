#include <bits/stdc++.h>
using namespace std;
using ll=long long;

int main(){
  ll n,m;
  cin>>n>>m;
  vector<pair<ll,ll>> xa(m);
  for(int i=0;i<m;i++){
    cin>>xa[i].first;
  }
  for(int i=0;i<m;i++){
    cin>>xa[i].second;
  }
  sort(xa.begin(),xa.end());
  xa.push_back(make_pair(n,0));
  m++;
  bool ok=true;
  ll ans=0;
  for(int i=0;i<m-1;i++){
    ll dif=xa[i+1].first-xa[i].first-1;
    if(dif<xa[i].second){
      xa[i].second-=dif;
      xa[i+1].second+=xa[i].second-1;
      ans+=(dif*(dif+1))/2;
      if(xa[i].second>1){
        ans+=(dif+1)*(xa[i].second-1);
      }
    }else{
      ok=false;
    }
  }
  if(xa[m-1].second!=1) ok=false;
  if(ok){
    cout<<ans<<endl;
  }else{
    cout<<-1<<endl;
  }
  return 0;
}