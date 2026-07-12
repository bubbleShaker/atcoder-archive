#include <bits/stdc++.h>
using namespace std;

bool is_ok(int h,int m){
  string h_s=to_string(h);
  string m_s=to_string(m);
  if(h_s.size()==1){
    h_s+='0';
    reverse(h_s.begin(),h_s.end());
  }
  if(m_s.size()==1){
    m_s+='0';
    reverse(m_s.begin(),m_s.end());
  }
  char tmp=h_s[1];
  h_s[1]=m_s[0];
  m_s[0]=tmp;
  int nh=stoi(h_s);
  int nm=stoi(m_s);
  if(0<=nh&&nh<=23&&0<=nm&&nm<=59){
    return true;
  }else{
    return false;
  }
}

int main(){
  int h,m;
  cin>>h>>m;
  while(1){
    if(is_ok(h,m)){
      cout<<h<<" "<<m<<endl;
      return 0;
    }
    m++;
    if(m==60){
      m=0;
      h++;
      if(h==24){
        h=0;
      }
    }
  }
  return 0;
}