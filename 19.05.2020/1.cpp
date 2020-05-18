#include <iostream>
#include <fstream>
//#include <cstring>
//#include <cmath>
//#include <algorithm>
using namespace std;
ifstream fin("date.in");
//ofstream fout("date.out");
//const int mxn=1e3;
//const int nax=1e5;
int a[1001][1001],coada[1001],viz[1001], g1[1001], g2[1001];
int i,n,el,j,p,u,pl,m,x,y,vf;
void citire(){
	fin>>n>>m;
	for(i=1;i<=m;++i){
		fin>>x>>y;
		g1[x]++;
		g2[y]++;
		a[x][y]=1;
	}
}
void dfs(int k){
    cout<<k;
    viz[k]=1;
    for(i=1; i<=n; ++i)
    {
        if(a[k][i]==1 && viz[i]==0)
            dfs(i);
    }
}

void circuit(int k){
	viz[k]=1;
	for(i=1;i<=n;++i){
		if(a[k][i]==1 && viz[i]==0)
			circuit(i);
	}
}
int main(){
	citire();
	cout<<"Nodurile cu grad intern = grad extern sunt: ";
	for(i=1;i<=n;++i){
		if(g1[i]==g2[i])
			cout<<i<<" ";
	}
	cout<<"\n";
	cout<<"Care este nodul de plecare: ";
	cin>>pl;
	cout<<"Parcurgerea in adancime: ";
	dfs(pl);
	cout<<"\n";
// BFS
	for(i=1;i<=n;++i)
		viz[i]=0;
	viz[pl]=1;
	coada[1]=pl;
	p=1;u=1;
	while(p<=u){
		el=coada[p];
		for(j=1;j<=n;++j)
			if((a[el][j]==1) && (viz[j]==0)){
				u++;
				coada[u]=j;
				viz[j]=1;
			}
		p++;
	}
	cout<<"Parcurgerea in latime: ";
	for(i=1;i<=u;++i)
		cout<<coada[i];
	cout<<"\nCare este varful X: ";
	cin>>vf;
	for(i=1;i<=n;++i)
		viz[i]=0;
	int nr=0;
	int l;
	for(l=1;l<=n;++l){
		//cout<<i<<"\n";
		circuit(l);
		if(viz[vf]!=0){
			nr++;
		}
		for(j=1;j<=n;++j){
			viz[j]=0;
		}
	}
	cout<<"Sunt "<<nr<<" circuite care il contin pe "<<vf;
	cout<<endl; return 0;
}
