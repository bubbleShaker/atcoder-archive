#include <iostream>
#include <string>
#include <map>
#include <utility>
int main(){
  long long A,B,k;
  std::cin>>A>>B>>k;
  std::string ans;
  auto fact=[&](long long n){
    long long ret=1;
    while(n>0){
      ret*=n--;
    }
    return ret;
  };
  std::map<std::pair<long long,long long>,long long> nCm_map; //メモ化用
  auto nCm=[&](auto nCm,long long n,long long m)->long long{ //オーバーフローを防ぐためパスカルの三角形?を用いる
    if(nCm_map.count({n,m})){
      return nCm_map[{n,m}];
    }
    if(n==m||m==0){
      return nCm_map[{n,m}]=1;
    }else if(n<m){
      return nCm_map[{n,m}]=0;
    }else{
      return nCm_map[{n,m}]=nCm(nCm,n-1,m)+nCm(nCm,n-1,m-1);
    }
  };
  
  while(A!=1&&B!=1){
    long long len=A+B; //文字列の長さ
    long long border=nCm(nCm,len-1,A-1);
    if(k<=border){
      ans+='a';
      A--;
    }else if(k>border){
      ans+='b';
      B--;
      k-=border;
    }
  }
  int len=A+B;
  if(A==1){
    std::string temp_str(len,'b');
    temp_str[k-1]='a'; //左からk-1番目がaのものがk番目に小さい
    ans+=temp_str;
  }else if(B==1){
    std::string temp_str(len,'a');
    temp_str[len-k]='b'; //右からk番目がbのものがk番目に小さい
    ans+=temp_str;
  }
  std::cout<<ans<<'\n';
  return 0;
}