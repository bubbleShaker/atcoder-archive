#include <bits/stdc++.h>
using namespace std;
using ll=long long;

ll N,A,B;
ll P,Q,R,S;

bool jok_1(ll k){
  if(max(1-A,1-B)<=k&&k<=min(N-A,N-B)){
    return true;
  }else{
    return false;
  }
}

bool jok_2(ll k){
  if(max(1-A,B-N)<=k&&k<=min(N-A,B-1)){
    return true;
  }else{
    return false;
  }
}

int main(){
  cin>>N>>A>>B;
  cin>>P>>Q>>R>>S;
  bool x_ok=false;
  bool y_ok=false;
  for(ll i=P;i<=Q;i++){
    for(ll j=R;j<=S;j++){
      //(i,j)が黒く塗られているか考える
      bool is_b=false;
      if(jok_1(i-A)&&jok_1(j-B)&&i-A==j-B) is_b=true;
      if(jok_2(i-A)&&jok_2(B-j)&&i-A==B-j) is_b=true;
      if(is_b){
        cout<<"#";
      }else{
        cout<<".";
      }
    }
    cout<<endl;
  }
  return 0;
}