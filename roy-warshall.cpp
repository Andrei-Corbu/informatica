#include <iostream>
#include <fstream>
#include <cstdlib>
//#include <cstring>
//#include <cmath>
//#include <algorithm>
using namespace std;
ifstream fin("date.in");
//ofstream fout("date.out");
const int INF=1e9;
const int mxn=1e3;
const int nax=1e5;
int n,m,a[mxn][mxn],c,i,j;
void roys() {
    int k;
    for (k=1; k<=n; k++)
        for (i=1; i<=n; i++)
            for (j=1; j<=n; j++)
                if(a[i][j] > a[i][k] + a[k][j])
                    a[i][j] = a[i][k] + a[k][j];
}
int main() {
    int x,y;
    fin>>n>>m;
    for(i=1; i<=n; ++i)
        for(j=1; j<=n; ++j)
            if(i==j)
                a[i][j]=0;
            else
                a[i][j]=INF;
    for(i=1; i<=m; ++i) {
        fin>>x>>y>>c;
        a[x][y]=c;
    }
    for(i=1; i<=n; ++i) {
        for(j=1; j<=n; ++j) {
            if(i==j) {
                cout<<0<<" ";
            }
            else {
                if(a[i][j] == INF) {
                    cout<<INF<<" ";
                }
                else cout<<a[i][j]<<" ";
            }
        }
        cout<<endl;
    }
    cout<<endl; return 0;
}
