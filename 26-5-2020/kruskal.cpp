#include <iostream>
#include <fstream>
using namespace std;
ifstream fin("date.in");
const int mxn=1e3;
const int nax=1e5;
struct muchie{
	int x,y;
	int c;
}v[nax];
int L[nax], n, m;
int poz(int p, int u){
    //int piv,aux,k;
    int piv, k;
    muchie aux;
    piv=v[p].c;
    while(p<u){
        if(v[p].c>v[u].c){
            aux=v[p];
            v[p]=v[u];
            v[u]=aux;
        }
        if(v[p].c==piv)
            u--;
        else
            p++;
    }
    k=p;
    return k;
}
void qs(int p, int u){
    int k;
    if(p<u){
        k=poz(p,u);
        qs(p,k-1);
        qs(k+1,u);
    }
}
int main(){
	int i, j;
	int ax,ay;
	fin>>n>>m;
	for(i=1;i<=m;++i){
		fin>>v[i].x>>v[i].y>>v[i].c;
	}
	fin.close();
	qs(1,m);
	for(i=1;i<=m;++i){
		cout<<"i= "<<i<<" - "<<v[i].x<<" "<<v[i].y<<" "<<v[i].c;
		cout<<endl;
	}
	for(i=1;i<=n;++i)
		L[i]=i;
	int ct=0, k=0;
	for(i=1;i<=n && k<n; ++i){
		if(L[v[i].x] != L[v[i].y]){
			ct+=v[i].c;
			ax=L[v[i].x]; ay=L[v[i].y];
			for(j=1;j<=n;++j)
				if(L[j]==ay)
					L[j]=ax;
		}
	}
	cout<<ct<<"\n"; return 0;
}
