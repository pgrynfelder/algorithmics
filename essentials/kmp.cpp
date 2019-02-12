#include<bits/stdc++.h>

using namespace std;
/* wypracowanie prawo autorskie
 * prawo, tworca, dzielo, prawa osobiste, majatkowe, prawo polskie i ue
 * skupic sie na publikowaniu w internecie
 *
 * oraz
 *
 * zagrozenia wynikajace z korzystania z internetu
 * 
 * w wordie
 */


// t - tekst
// w - wzorzec
// s= $w#t

int p[1000007];

void kmp(int n){ // n-długość sklejenia tekstu i wzorca
	int j=0;
	p[0]=p[1]=0;
	for(int i=2; i<=n; i++){
		while(j && s[i]!=s[j+1]) j=p[j];
		if(s[i]==s[j+1]) j++;
		p[i]=j;
	}
}

int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	return 0;
}
