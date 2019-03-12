#include<bits/stdc++.h>

using namespace std;

/* siec przeplywowa = graf
 ~* s - zrodlo
 ~* t - ujscie
 ~* c - ile wody moze przeplynac przez rure (maks. natezenie, przepustowosc)
 ~* 
 ~* przeplyw - przpompowanie wody z e zrodla do ujscia
 ~* maksymalny - ile maksymalnie
 ~* 
 ~* formalne definicje
 ~* 
 ~* E - krawedzie
 ~* f: E -> R - przeplyw
 ~* All (u,v) in E: f(u,v) <= c(u,v)
 ~* All (u,v) in E: f(u,v) = -f(v,u)
 ~* All v in V\{s,t}: sum(w in V, f(v, w) = 0)
 ~* 
 ~* ALGOS
 ~* 
 ~* 
 ~* jakis chamski zachlan
 ~* 1. f na poczatku 0
 ~* 2. dopoki instnieje sciezka powiekszajaca p
 ~* 	powiekszam f na p o min(cf) na sciezce
 ~* 
 ~* 
 ~* 
 ~* SIEC REZYDUALNA
 ~* (G, s, t, c)
 ~* z G(V, E) bedziemy tworzyc Gf(V, Ef)  (f - po przeplywie)
 ~* 
 ~* (u, v) is in Ef iff ((u, v) in E and f(u, v) < c(u, v)) or ((v,u) in E and  f(v, u) > 0)
 ~* czyli bedziemy robic nowe, odwrocone krawedzie
 ~* 
 ~* All (u,v): cf(u, v) = c(u,v) - f(u,v)
 ~*/
 
int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	return 0;
}
