#include <bits/stdc++.h>
using namespace std;
using ll=long long;

ll powll(ll a,int b){
  ll ret=1;
  for(int i=0;i<b;i++){
    ret*=a;
  }
  return ret;
}

ll to_dec(string s,ll n){
  ll ret=0;
  ll mul=1;
  reverse(s.begin(),s.end());
  ll sn=s.size();
  for(ll i=0;i<sn;i++){
    ret+=(ll)(s[i]-'0')*mul;
    mul*=n;
  }
  return ret;
}

ll calc_sum(ll n,ll k){
  return powll(n,k-1);
}

ll calc_ind(string s){
  ll n=(s[0]-'0');
  string sub_s=s.substr(1);
  return to_dec(sub_s,n)+1;//n進数のsub_sを10進数に変換
}

bool is_hebi(string s){
  ll n=(s[0]-'0');
  for(int i=1;i<s.size();i++){
    if((ll)(s[i]-'0')>=n){
      return false;
    }
  }
  return true;
}

string min_hebi(string s){
  ll n=(s[0]-'0');
  bool change=false;
  for(int i=1;i<s.size();i++){
    if(change){
      s[i]=(n-1)+'0';
      continue;
    }
    if((ll)(s[i]-'0')>=n){
      s[i]=(n-1)+'0';
      change=true;
    }
  }
  return s;
}

int main(){
  ll l,r;
  cin>>l>>r;
  string s_l,s_r;
  s_l=to_string(l);
  s_r=to_string(r);
  ll ans=0;
  bool is_count=false;
  bool is_break=false;
  if(s_l.size()==s_r.size()&&s_l[0]==s_r[0]){//サイズが同じならば
    s_r=min_hebi(s_r);
    ans=calc_ind(s_r);
    if(!is_hebi(s_l)){
      s_l=min_hebi(s_l);
      ans-=calc_ind(s_l);
    }else{
      ans-=calc_ind(s_l);
      ans++;
    }
    cout<<ans<<endl;
    return 0;
  }
  for(ll k=2;k<=19;k++){//k桁
    for(ll n=1;n<=9;n++){//先頭の数字がn
      if((s_l[0]-'0')==n&&k==s_l.size()){//lと先頭の数字が同じで桁が同じ
        if(!is_hebi(s_l)){//lがヘビ数でないならば
          s_l=min_hebi(s_l);//lより小さい最大のヘビ数に変換
          ans+=calc_sum(n,k)-calc_ind(s_l);
          is_count=true;//数え中にする
        }else{
          ans+=calc_sum(n,k)-calc_ind(s_l)+1;
          is_count=true;
        }
      }else if((s_r[0]-'0')==n&&k==s_r.size()){//rと先頭の数字が同じで桁が同じ
        if(!is_hebi(s_r)){//rがヘビ数でないならば
          s_r=min_hebi(s_r);//rより小さい最大のヘビ数に変換
        }
        ans+=calc_ind(s_r);
        is_break=true;
        break;
      }else if(is_count){
        ans+=calc_sum(n,k);
      }
    }
    if(is_break)break;
  }
  cout<<ans<<endl;
  return 0;
}