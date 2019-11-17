#include<bits/stdc++.h>
using namespace std;

constexpr int M=1e6+7;
vector<int>g[M];
bool odw[M];
int odl[M];

void dfs(int v){
	odw[v]=1;
	for(auto w:g[v]) if(!odw[w]) dfs(w);
}

void dfs2(int v, int p){
	for(auto w:g[v]){
		if(w==p) continue;
		odl[w]=odl[v]+1;
		dfs2(w,v);
	}
}

int main(){
	ios_base::sync_with_stdio(0);
	cout.tie(0);
	cout.tie(0);
	
	string s;
	int n,m,k,a,b,c,d;
	cin>>n>>m>>k;

	cin>>s;
	if(s=="NIE"){
		cout<<"OK";
		return 0;
	}
	
	for(int i=1; i<n*m; i++){
		cin>>a>>b>>c>>d;
		g[((a-1)*m)+b].push_back(((c-1)*m)+d);
		g[((c-1)*m)+d].push_back(((a-1)*m)+b);
	}	

	dfs(1);
	
	for(int i=1; i<=n*m; i++){
		if(!odw[i]){
			cout<<"KURR1";
			return 0;
		}
	}
	
	a=1;
	odl[a]=0;
	dfs2(1,0);
	for(int i=1; i<=n*m; i++) if(odl[i]>odl[a]) a=i;
		
	odl[a]=0;
	dfs2(a,0);
	for(int i=1; i<=n*m; i++) if(odl[i]>odl[a]) a=i;

	if(odl[a]!=k) cout<<"KURR2";
	else cout<<"OK";
	
	return 0;
}
