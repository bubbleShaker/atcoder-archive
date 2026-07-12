#include <bits/stdc++.h>
using namespace std;
using ll=long long;
using P=pair<int,ll>;

int main(){
  int N;
  cin>>N;
  vector<ll> A(N);
  for(int i=0;i<N;i++) cin>>A[i];
  int Q;
  cin>>Q;
  P bp=make_pair(0,0);
  vector<queue<P>> vque(N);
  for(int i=0;i<Q;i++){
    int t;
    cin>>t;
    if(t==1){
      ll x;
      cin>>x;
      bp=make_pair(i,x);
    }
    if(t==2){
      int ti;
      ll x;
      cin>>ti>>x;
      ti--;
      vque[ti].push({i,x});
    }
    if(t==3){
      int ti;
      cin>>ti;
      ti--;
      while(!vque[ti].empty()){
        P p=vque[ti].front();
        if(p.first<bp.first){
          vque[ti].pop();
        }else{
          break;
        }
      }
      queue<P> que=vque[ti];
      ll add=0;
      while(!que.empty()){
        add+=que.front().second;
        que.pop();
      }
      if(bp.second==0) cout<<A[ti]+add<<endl;
      else cout<<bp.second+add<<endl;
    }
  }
}