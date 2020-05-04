#include <iostream>
#include <fstream>
//#include <cstring>
//#include <cmath>
//#include <algorithm>
using namespace std;
ifstream fin("date.in");
//ofstream fout("datemdfs.out");
const int mxn=1e3;
const int INF=1e9;
int n,m,v[mxn],c[mxn][mxn];
void dfs(int k){
	cout<<k<<" ";
	v[k]=1;
	for(int i=1;i<=n;++i){
		if(c[k][i]!=0 && c[k][i]!=INF && v[i]==0){
			dfs(i);
		}
	}
}
int main(){
	int x,y;
	int k;
	int pl;
	fin>>n>>m;
	for(int i=1;i<=n;++i)
		for(int j=1;j<=n;++j){
			c[i][j]=0;
		}
	for(int i=1;i<=m;++i){
		fin>>x>>y>>k;
		c[x][y]=c[y][x]=k;
	}
	for(int i=1;i<=n;++i)
		for(int j=1;j<=n;++j){
			if(c[i][j]==0 && i!=j)
				c[i][j]=INF;
		}
	cin>>pl;
	dfs(pl);
	cout<<endl; return 0;
}
