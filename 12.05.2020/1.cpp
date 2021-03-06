#include <iostream>
#include <fstream>
//#include <cstring>
//#include <cmath>
//#include <algorithm>
using namespace std;
ifstream fin("arbore.txt");
//ofstream fout("date.out");
const int mxn=1e3;
const int nax=1e5;
int fr[nax]={0};
int niv[nax]={0};
int a[mxn][mxn], t[nax],v[nax],n;
int radacina(){
	for(int i=1;i<=n;++i)
		if(t[i]==0)
			return i;
	return 0;
}
int frunze(){
	int i,nr=0;
	for(i=1;i<=n;++i){
		if(t[i]>0)
			fr[t[i]]=1;
	}
	for(i=1;i<=n;++i){
		if(fr[i]==0)
			nr++;
	}
	return nr;
}
int inaltime(int x){
	if(t[x]==0)
		return 0;
	if(niv[x]==0)
		niv[x]=1+inaltime(t[x]);
	return niv[x];
}
int main(){
	fin>>n;
	int i;
	for(i=1;i<=n;i++){
		fin>>t[i];
	}
	cout<<"Numarul de frunze este "<<frunze()<<".\n";
	int nivmax=0;
	niv[radacina()]=0;
	for(i=1;i<=n;++i){
		niv[i]=inaltime(i);
		if(niv[i]>nivmax)
			nivmax=niv[i];
	}
	cout<<"Inaltimea arborelui este "<<nivmax<<".\n";
	return 0;
}
