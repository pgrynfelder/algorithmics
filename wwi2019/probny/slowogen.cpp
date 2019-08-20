#include<bits/stdc++.h>

using namespace std;


int randrange(int a, int b){ // includes a and b
    return a + (rand() % (b - a + 1));
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    string alpha = "qwertyuiopasdfghjklzxcvbnmQWERTYUIOPASDFGHJKLZXCVBNM1234567890";
    int seed;// = 240;
    cin >> seed;
    srand(seed);
    random_shuffle(alpha.begin(), alpha.end());
    int n = randrange(1, 62);
    string word;
    for (int i = 0; i < n; i++){
        word += alpha[i];
    }
    cout << word << '\n';



    return 0;
}
