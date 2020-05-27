#include <iostream>
#include <fstream>
using namespace std;
ifstream fin("date.in");
const int inf=1e9;
const int mxn=1e3;
const int nax=1e5;
int n,m,a[mxn][mxn],p[nax];
void citire(){
	int i,j,k,c;
    fin>>n>>m;
    for(i=1; i<n; i++)
        for(j=i+1; j<=n; j++)
            a[i][j]=a[j][i]=inf;
    for(k=1; k<=m; k++){
        fin>>i>>j>>c;
        a[i][j]=a[j][i]=c;
    }
}

int main(){
    int ct=0;
    int i,k,minn,x;
    citire();
    fin.close();
    for(i=2; i<=n; i++) p[i]=1;
    for(k=1; k<n; k++){
        minn=inf;
        for(i=1; i<=n; i++)
            if(p[i] && a[p[i]][i]<minn){
                minn=a[p[i]][i];
                x=i;
            }
        ct+=a[p[x]][x];
        for(i=1; i<=n; i++)
            if(p[i] && a[p[i]][i]>a[i][x])
                p[i]=x;
        p[x]=0;
    }
    cout<<ct<<"\n"; return 0;
}
