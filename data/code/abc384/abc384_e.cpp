#include<bits/stdc++.h>
using namespace std;
//#include<atcoder/all>
//using namespace atcoder;
using ll = long long;
using ull = unsigned long long;

int di[] = {1,0,-1,0};
int dj[] = {0,1,0,-1};
int main(){
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int h,w;
	ll x;
	cin >> h >> w >> x;
	int p,q;
	cin >> p >> q;
	--p,--q;
	vector grid(h,vector<ll>(w));
	for(int i=0;i<h;++i)for(int j=0;j<w;++j){
		cin >> grid[i][j];
	}
	
	using P = pair<ll,pair<int,int>>; //変更箇所
	priority_queue<P,vector<P>,greater<P>> pq;
	vector seen(h,vector<bool>(w));
	vector add(h,vector<bool>(w)); //変更箇所
	seen[p][q] = true;
	for(int v=0;v<4;++v){
		int ni = p + di[v];
		int nj = q + dj[v];
		if(ni<0 || nj<0 || ni>=h || nj>=w)continue;
		pq.emplace(grid[ni][nj],make_pair(ni,nj)); //変更箇所
    add[ni][nj]=true; //変更箇所
	}
	
	ll now = grid[p][q];
	while(!pq.empty()){
		auto [score,index] = pq.top();
    auto [i,j]=index; //変更箇所
		pq.pop();
		if((now+x-1)/x > score){ //変更箇所
      now += score;
      seen[i][j] = true; //変更箇所
      for(int v=0;v<4;++v){
        int ni = i + di[v];
        int nj = j + dj[v];
        if(ni<0 || nj<0 || ni>=h || nj>=w)continue;
        if(seen[ni][nj])continue;
        if(add[ni][nj])continue; //変更箇所
        pq.emplace(grid[ni][nj],make_pair(ni,nj)); //変更箇所
        add[ni][nj]=true;//変更箇所 
      }
		}
	}

	cout << now << endl;
}