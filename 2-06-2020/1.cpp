/*Harta unui oras este impartita in n intersectii si m strazi cu sens unic intre intersectii, fiecare strada avand o lungime.
Pentru doua intersectii i si j poate exista atat strada de la i la j, cat si de la j la i. Intr-o intersectie x se gaseste Julieta
si intr-o intersectie y se gaseste Romeo. Cei doi se pot deplasa pe strazi in sensurile de parcurgere ale acestora. Determinati
intersectia in care trebuie sa se intalneasca cei doi astfel incat sa parcurga in total o distanta minima. Pentru solutia obtinuta
afisati intersectia, distanta parcursa de Julieta, distanta parcursa de Romeo si traseul parcurs de fiecate dintre ei.
Datele de intrare asigura ca cei doi se pot intalni.
*/
#include <iostream>
#include <fstream>
//#include <cmath>
//#include <algorithm>
using namespace std;
ifstream f("date.in");
const int mxn=1e3;
const int nax=1e5;
const int inf=1e9;
int a[mxn][mxn],dr[nax],dj[nax],g[nax],v1[nax],n,m,x,y,v2[nax], tj[nax], tr[nax];
void citire() {
    int i,j,k,cost;
    f>>n>>m;
    for(i=1; i<=n; i++)
        for(j=1; j<=n; j++)
            if(i==j) a[i][j]=0;
            else a[i][j]=inf;
    for(k=1; k<=m; k++) {
        f>>i>>j>>cost;
        a[i][j]=cost;
    }
    f.close();
    cin>>x>>y;
}

void dijkstra(int s) {
    int i,j,k,minn;
    for(i=1; i<=n; i++) {
        g[i]=a[s][i];
        if(i!=s && g[i]!=inf)
			v2[i]=s;
        else 
			v2[i]=0;
        v1[i]=0;
    }
    v1[s]=1;
    for(k=1; k<n; k++) {
        minn=inf;
        for(i=1; i<=n; i++)
            if(!v1[i] && g[i]<minn) {
                minn=g[i];
                j=i;
            }
        for(i=1; i<=n; i++)
            if(!v1[i] && g[i]>g[j]+a[j][i]) {
                g[i]=g[j]+a[j][i];
                v2[i]=j;
            }
        v1[j]=1;
    }
}

void drum(int i, int t[200]) {
    if(v2[i]) drum(v2[i],t);
    cout<<i<<" ";
}

int main() {
    int i,minn=100000,imin;
    citire();
    dijkstra(x);
    for(i=1; i<=n; i++) {
        dj[i]=g[i];
        tj[i]=v2[i];
    }
    dijkstra(y);
    for(i=1; i<=n; i++) {
        dr[i]=g[i];
        tr[i]=v2[i];
    }
    for(i=1; i<=n; i++)
        if(dj[i]+dr[i]<minn) {
            minn=dj[i]+dr[i];
            imin=i;
        }
    cout<<"Intersectia in care se intalnesc: "<<imin<<endl;
    cout<<"Lungimea drumului pe care il parcurge Julieta: "<<dj[imin]<<endl;
    cout<<"Lungimea drumului pe care il parcurge Romeo: "<<dr[imin]<<endl;
    cout<<"Drumul pe care il parcurge Julieta: ";
    drum(imin,tj);
    cout<<"\nDrumul pe care il parcurge Romeo:: ";
    drum(imin,tr);
    cout<<"\n";
    return 0;
}


