#include <iostream>
#include <fstream>
//#include <cstring>
//#include <cmath>
//#include <algorithm>
using namespace std;
ifstream fin("date.in");
ofstream fout("date.out");
const int mxn=1e3;
const int INF=1e9;
int main(){
	int n,m;
	int x,y;
	int k;
	int c[mxn][mxn];
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
	for(int i=1;i<=n;++i){
		for(int j=1;j<=n;++j)
			fout<<c[i][j]<<" ";
		fout<<"\n";
	}
	cout<<endl; return 0;
}
