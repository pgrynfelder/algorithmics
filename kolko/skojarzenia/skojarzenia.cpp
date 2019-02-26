/* 
 * mamy se graf dwudzielny (nie ma cykli nieparzystych)
 * 
 * skojarzenie - dobieranie w pary
 * 
 * szukanie maksymalnego skojarzenia
 * 
 * A: D, F
 * B: D
 * C: E, F
 * 
 * zachlan robi A~D, B~*, C~E
 * no ale to sa 2 skojarzenia a mozna 3
 * wiec do dupy
 * 
 * 
 * solv n^2
 * 
 *      (~ skojarzone, - nieskojarzone)
 *      wiec idziemy droga B-D~A-F (F to pierwszy (tu tez ostatni) wolny jak se po tej sciezce idziemy)
 *      w sciezce sie nie moga powtarzac
 *      jak zamienimy B-D~A-F na B~D-A~F to mamy fajen skojarzenia
 * 
 * 
 * 
 * solv n*sqrt
 * 
 * 		AYY LMAO KROTSZE SCIEZKI
 * 		ayy lmao bfs ale trzeba troche zmienic
 * 		wrzucamy na kolejke wszystkie punkty z jednej strony, dajemy im odleglosc 0
 * 		robimy bfsa z wieloma startpointami
 * 		
 * 		i jak dfs trafi na wierzcholek nieskojarzony
 * 		to aaa kojarz
 * 
 * 		bfs niech ma dwa ograniczenia - idziemy tylko na wieksze numerki
 * 		
 * 		 
 * /
