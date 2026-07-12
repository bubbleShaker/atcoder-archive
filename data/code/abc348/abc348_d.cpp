#include <bits/stdc++.h>
using namespace std;
int h,w;
vector<string> grid;
int n;
vector<tuple<int,int,int>> potions;
set<pair<int,int>> st;
map<pair<int,int>,int> mp;
pair<int,int> start,goal;
vector<int> dx={-1,0,1,0};
vector<int> dy={0,1,0,-1};
void input(){
    cin>>h>>w;
    grid.resize(h);
    for(int i=0;i<h;i++){
        cin>>grid[i];
    }
    cin>>n;
    potions.resize(n);
    for(int i=0;i<n;i++){
        int r,c,e;
        cin>>r>>c>>e;
        r--;
        c--;
        potions[i]={r,c,e};
        st.insert({r,c});
        mp[{r,c}]=i;
    }
}
void checkStartAndGoal(){
    for(int i=0;i<h;i++){
        for(int j=0;j<w;j++){
            if(grid[i][j]=='S'){
                start={i,j};
            }
            if(grid[i][j]=='T'){
                goal={i,j};
            }
        }
    }
    return;
}
vector<vector<bool>> BFS(int ind){
    vector visited(h,vector<bool>(w));
    vector costGrid(h,vector<int>(w));
    auto [sx,sy,se]=potions[ind];
    queue<pair<int,int>> que;
    que.push({sx,sy});
    costGrid[sx][sy]=se;
    while(!que.empty()){
        auto [x,y]=que.front();
        que.pop();
        if(visited[x][y])continue;
        visited[x][y]=true;
        if(costGrid[x][y]==0)continue;
        for(int i=0;i<4;i++){
            int nx=x+dx[i];
            int ny=y+dy[i];
            if(nx<0||nx>=h||ny<0||ny>=w)continue;
            if(visited[nx][ny])continue;
            if(grid[nx][ny]=='#')continue;
            que.push({nx,ny});
            costGrid[nx][ny]=costGrid[x][y]-1;
        }
    }
    return visited;
}
vector<vector<int>> makeNewGraph(){
    vector<vector<int>> g(n);
    for(int i=0;i<n;i++){
        vector<vector<bool>> visited=BFS(i);
        for(int j=0;j<n;j++){
            if(i==j)continue;
            auto [nx,ny,ne]=potions[j];
            if(visited[nx][ny]){
                g[i].push_back(j);
            }
        }
    }
    return g;
}
void solve(){
    input();
    checkStartAndGoal();
    auto [sx,sy]=start;
    auto [gx,gy]=goal;
    if(st.count({sx,sy})==false){
        cout<<"No"<<endl;
        return;
    }
    if(st.count({gx,gy})==false){
        potions.push_back({gx,gy,0});
        mp[{gx,gy}]=n;
    }
    n=potions.size();
    vector<vector<int>> graph=makeNewGraph();
    vector<bool> visited(n);
    queue<int> que;
    que.push(mp[{sx,sy}]);
    while(!que.empty()){
        auto u=que.front();
        que.pop();
        if(visited[u])continue;
        visited[u]=true;
        for(int v:graph[u]){
            if(visited[v])continue;
            que.push(v);
        }
    }
    if(visited[mp[{gx,gy}]]){
        cout<<"Yes"<<endl;
    }else{
        cout<<"No"<<endl;
    }
}
int main(){
    solve();
    return 0;
}