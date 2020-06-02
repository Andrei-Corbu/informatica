#include <iostream>
#include <fstream>
using namespace std;
const int p_inf=1e9;
ifstream f("date.in");
const int nmax=1e5;
const int mxn=1e4;
int a[mxn][mxn],n,i,j,c,d[nmax],s[nmax],p[nmax],x,y,mind;
void init()
{   f>>n;
    for(i=1; i<=n; i++)
        for(j=1; j<=n; j++)if(i==j) a[i][j]=0;
            else a[i][j]=p_inf;
}
void citire()
{   while(f>>i>>j>>c) a[i][j]=c;
    f.close();
}
void generare_drum(int x)
{
    s[x]=1;
    for(i=1; i<=n; i++)
    {   d[i]=a[x][i];
        if(i!=x &&d[i]<p_inf) p[i]=x;
    }
    mind=p_inf;
    for(i=1; i<=n; i++)
    {   for(j=1; j<=n; j++)
            if(s[j]==0&&d[j]<mind)
            {   mind=d[j];
                y=j;
            }
        s[y]=1;
        for(j=1; j<=n; j++)
            if(s[i]==0&&d[j]>d[y]+a[y][j])
            {   d[j]=d[y]+a[y][j];
                p[j]=y;
            }
    }
}
void drum(int i)
{   if (p[i]!=0) drum (p[i]);
    cout<<i<<" ";
}
void afisare(int x)
{   for(i=1; i<=n; i++)
        if(i!=x)
            if(p[i]!=0)
            {   cout<<"drumul cu costul minim de la nodul "<<x;
                cout<<" la nodul "<<i<<" are costul "<<d[i]<<endl;
                drum(i);
                cout<<endl;
            }
            else cout<<" nu exista drum de la "<<x<<" la "<<i<<endl;
}
int main()
{   cout<<"x=";
    cin>>x;
    init();
    citire();
    generare_drum(x);
    afisare(x);
    return 0;
}
