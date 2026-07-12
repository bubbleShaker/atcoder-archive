#include <bits/stdc++.h>
using namespace std;
void init(map<char,int>& mp,char c){
  while(mp[c]>=4){
    int q=mp[c]/4;
    mp[c]-=q*4;
    mp[c]+=q;
  }
}
int main(){
  int n;
  char c;
  cin>>n>>c;
  string s;
  cin>>s;
  map<char,int> mp;
  for(int i=0;i<n;i++){
    mp[s[i]]++;
  }
  init(mp,'B');
  init(mp,'R');
  int co=min(mp['B'],mp['R']);
  mp['B']-=co;
  mp['R']-=co;
  char remC;
  if(mp['B']==3){
    remC='W';
  }else if(mp['B']==2){
    remC='R';
  }else if(mp['B']==1){
    remC='B';
  }else if(mp['R']==3){
    remC='W';
  }else if(mp['R']==2){
    remC='B';
  }else if(mp['R']==1){
    remC='R';
  }else if(mp['B']==0&&mp['R']==0){
    remC='W';
  }
  if(remC==c){
    cout<<"Yes"<<endl;
  }else{
    cout<<"No"<<endl;
  }
  return 0;
}