#include<bits/stdc++.h>

using namespace std;

int n,m,a,b;
long long p=1;
const long long P = 997;
const long long MOD=(long long)1e9 +9;
long long d,e;
char slowo[1000020];
long long pom[1000020];
long long pom2[1000020];
int main()
{
//---------wczytywanie-----------------
ios_base::sync_with_stdio(0);
cin.tie(0);
cout.tie(0);
cin>>n;
cin>>slowo[0];
pom[0] = slowo[0];
pom2[0] = p;
//---------ustawianie tablicy sum------
for(int i =1;i<n;i++)
{
    cin>>slowo[i];
    pom[i] = (pom[i-1]*P + (long long)slowo[i]);
    p=p*P;
    if(p>=MOD)
    {
        p = p%MOD;
    }
    pom2[i]=p;
    if(pom[i]>=MOD){
        pom[i] = pom[i]%MOD;
    }
    //cout<<pom[i]<<" "<<pom2[i]<<endl;
}
cin>>m;
//--------testy---------
for(int i =0;i<m;i++)
{
cin>>a>>b;
int c = (b+a-1)/2; //srodek pomiedzy a i b
// a i b zmniejszam aby nie musiec pisać -1
a--;
b--;
//--------wartosci podsłow-----
//cout<<c-a<<" "<<pom2[c-a]<<endl;
d = (pom[c-1]-(pom[a-1]*pom2[c-a]));
e = (pom[b] - (pom[c-1]*pom2[b-c+1]));
if(d>=MOD or d<=-MOD)
{
d=d%MOD;
}
if(e>=MOD or e<=-MOD)
{
e=e%MOD;
}
if(d<0)
{
d+=MOD;
}
if(e<0)
{
e+=MOD;
}
//cout<<e<<" "<<d<<endl;
if(e == d)
{
cout<<"TAK"<<endl;
}
else
{
cout<<"NIE"<<endl;
}
}
}