#include <iostream>
//#include <fstream>
//#include <cstring>
//#include <cmath>
//#include <algorithm>
using namespace std;
ifstream fin("date.in");
//ofstream fout("date.out");
#define ll long long;
const int mxn=1e3;
const int nax=1e5;

int n,m,a[mxn][mxn],viz[nax],k;

void DFS(int x)
{ int i;
  viz[x]=1;
  for(i=1;i<=n;i++)
    if (a[x][i]==1 && viz[i]==0) DFS(i);  
}

int Conex()
{ int i;
  DFS(1);
  for(i=1;i<=n;i++)
      if (viz[i]==0) return 0;
  return 1;
}

int main(){
	int x,y;
	fin>>n>>m>>k;
	while(fin>>x>>y){
		a[x][y]=a[y][x]=1;
	}
	cout<<endl; return 0;
}
