#include <iostream>
#include <vector>
int main(){
  int n,t,m;
  std::cin>>n>>t>>m;
  std::vector ng(n+1,std::vector<bool>(n+1));
  for(int i=0;i<m;i++){
    int a,b;
    std::cin>>a>>b;
    ng[a][b]=true;
    ng[b][a]=true;
  }
  long long ans=0;
  auto dfs=[&](auto dfs,int per,std::vector<std::vector<int>> teams)->void{
    // std::cout<<"per is "<<per<<'\n';
    if(per>n){
      if(teams.size()==t){
        // for(auto team:teams){
        //   for(int i=0;i<team.size();i++){
        //     std::cout<<team[i]<<((i!=team.size()-1)?' ':'\n');
        //   }
        // }
        // std::cout<<'\n';
        ans++;
      }
      return;
    }
    for(auto &team:teams){ //既にあるteamにperを入れた遷移を考える
      bool is_ok=true;
      for(int mem:team){
        if(ng[per][mem]){ //相性が悪い組み合わせがあるか調べる
          is_ok=false;
        }
      }
      if(is_ok){
        team.push_back(per);
        dfs(dfs,per+1,teams);
        team.pop_back();
      }
    }
    if(teams.size()<t){ //既存のチーム数がt未満ならば、新しいチームを作った遷移を考える
      std::vector<int> new_team;
      new_team.push_back(per);
      teams.push_back(new_team);
      dfs(dfs,per+1,teams);
    }
  };
  std::vector<std::vector<int>> base_teams;
  dfs(dfs,1,base_teams);
  std::cout<<ans<<'\n';
  return 0;
}