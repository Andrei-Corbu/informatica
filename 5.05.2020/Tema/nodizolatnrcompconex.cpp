#include <iostream>
#include <fstream>
//#include <cstring>
//#include <cmath>
//#include <algorithm>
using namespace std;
ifstream fin("graf.txt");
//ofstream fout("date.out");
const int mxn=1e3;
int n,m,a[mxn][mxn];
int v[mxn];
int nrcomp;
void dfs(int k){
	v[k]=1;
	for(int i=1;i<=n;++i){
		if(a[k][i]==1 && v[i]==0){
			dfs(i);
		}
	}
}
void ComponenteConexe(){ 
	int i;
	for(i=1;i<=n;++i)
		if(v[i]==0) { 
			nrcomp++; 
			dfs(i);
		}
}
int main(){
	bool ok=true;
	int x,y;
	fin>>n>>m;
	for(int i=1;i<=m;++i){
		fin>>x>>y;
		a[x][y]=a[y][x]=1;
	}
	ComponenteConexe();
	for(int i=1;i<=n;++i){
		if(v[i]==0){
			cout<<i<<", ";
			ok=false;
		}
	}
	cout<<"\n";
	if(ok==true)
		cout<<"Graful nu contine noduri izolate.\n";
	cout<<"Sunt "<<nrcomp<<" componente conexe.\n";
	return 0;
}
