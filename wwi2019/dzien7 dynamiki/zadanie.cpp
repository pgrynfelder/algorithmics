#include <bits/stdc++.h>
using namespace std;
const int n=2000+15;
int tab[n][n],m;
int tabq[n];
int tabm[n];
vector<int>wyn;
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin>>m;
    int q=m;
    for (int i=1; i<=m; i++)
    {
        int a;
        cin >> a;
        if (a <= 0){
            m--;
            i--;
            continue;
        }
        tabm[i]=a;
 
    }
 
    for (int i=1; i<=q ;i++)
    {
        int a;
        cin >> a;
        if (a <= 0){
            q--;
            i--;
            continue;
        }
        tabq[i]=a;
    }
    for (int i=1; i<=m; i++)
    {
        for (int j=1; j<=q; j++)
        {
            if (tabq[j]==tabm[i])
            {
                tab[i][j]=(max(tab[i-1][j],tab[i][j-1]))+tabq[j];
            }
            else
            {
                tab[i][j]=(max(tab[i-1][j],tab[i][j-1]));
            }
        }
    }
 
    int indm=m;
    int indq=q;
    while (indq!=0 && indm!=0)
    {
        if (max(tab[indm-1][indq],tab[indm][indq-1])==tab[indm-1][indq])
        {
            if (tab[indm][indq]-tab[indm-1][indq]!=0)
                wyn.push_back(tab[indm][indq]-tab[indm-1][indq]);
 
            indm--;
        }
        else
        {
            if (tab[indm][indq]-tab[indm][indq-1]!=0)
                wyn.push_back(tab[indm][indq]-tab[indm][indq-1]);
 
            indq--;
        }
 
    }
    cout<<wyn.size()<<'\n';
    for (int i=wyn.size()-1; i>=0;i --)
    {
        if (wyn[i]!=0)
            cout<<wyn[i]<<' ';
    }
}