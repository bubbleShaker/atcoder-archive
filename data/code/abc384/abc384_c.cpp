#include <bits/stdc++.h>
using namespace std;
using P=pair<int,string>;

bool f(P p1,P p2){
  if(p1.first==p2.first){
    return p1.second<p2.second;
  }else{
    return p1.first>p2.first;
  }
}

int main(){
  vector<int> tok(5);
  for(int i=0;i<5;i++) cin>>tok[i];
  string bas="ABCDE";
  vector<P> vec;
  for(int bit=1;bit<(1<<5);bit++){
    bitset<5> bts(bit);
    int sum=0;
    string str;
    for(int i=0;i<5;i++){
      if(bts[i]){
        sum+=tok[i];
        str+=bas[i];
      }
    }
    vec.push_back(make_pair(sum,str));
  }
  sort(vec.begin(),vec.end(),f);
  int n=vec.size();
  for(int i=0;i<n;i++){
    cout<<vec[i].second<<endl;
  }
  return 0;
}