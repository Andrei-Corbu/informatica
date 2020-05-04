#include <iostream>
#include <fstream>
//#include <cstring>
//#include <cmath>
//#include <algorithm>
using namespace std;
ifstream fin("graf.txt");
//ofstream fout("date.out");
const int mxn=1e3;
int nr=0;
int n,m,a[mxn][mxn];
int v[mxn];
int maxl=-1;
int poz;
void dfs(int k){
	v[k]=1;
	for(int i=1;i<=n;++i){
		if(a[k][i]==1 && v[i]==0){
			dfs(i);
		}
	}
	nr++;
}
void dfs2(int k){
	cout<<k<<" ";
	v[k]=1;
	for(int i=1;i<=n;++i){
		if(a[k][i]==1 && v[i]==0){
			dfs2(i);
		}
	}
	nr++;
}
void ComponenteConexe(){ 
	int i;
	for(i=1;i<=n;++i)
		if(v[i]==0) { 
			dfs(i);
		if(nr>=maxl){
			poz=i-1;
			nr=0;
		}
	}
}

int main(){
	int x,y;
	fin>>n>>m;
	for(int i=1;i<=m;++i){
		fin>>x>>y;
		a[x][y]=a[y][x]=1;
	}
	ComponenteConexe();
	for(int i=1;i<=n;++i)
		v[i]=0;
	dfs2(poz);
	cout<<endl; return 0;
}
