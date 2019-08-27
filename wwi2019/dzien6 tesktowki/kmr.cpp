#include<bits/stdc++.h>
using namespace std;

const int MAXN = 1e6 + 7, LOG = 20;
int kmr[LOG][MAXN], letters[30], pairs[MAXN][3];
vector<pair<int, int>> kub_first[MAXN], kub_second[MAXN];

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int n, tail;
    string s;
    cin >> n >> s;
    //n <<= 1;
    //s += s;

    for(char &i : s) {
        letters[(int)i - 97] = 1;
    }
    for(int i = 1; i < 26; ++i) {
        letters[i] += letters[i - 1];
    }
    for(int i = 1; i <= n; ++i) {
        kmr[0][i] = letters[(int)s[i - 1] - 97];
    }

    for(int i = 1; i < LOG; ++i) {
        for(int j = 1; j <= n + 1 - (1 << i - 1); ++j) {
            kub_first[j].clear();
            kub_second[j].clear();
        }
        for(int j = 1; j <= n + 1 - (1 << i); ++j) {
            kub_second[kmr[i - 1][j + (1 << i - 1)]].push_back({kmr[i - 1][j], j});
        }
        for(int j = 1; j <= n + 1 - (1 << i - 1); ++j) {
            for(pair<int, int> &l : kub_second[j]) {
                kub_first[l.first].push_back({j, l.second});
            }
        }
        tail = 0;
        for(int j = 1; j <= n + 1 - (1 << i - 1); ++j) {
            for(pair<int, int> &l : kub_first[j]) {
                ++tail;
                pairs[tail][0] = j;
                pairs[tail][1] = l.first;
                pairs[tail][2] = l.second;
            }
        }
        tail = 0;
        for(int j = 1; j <= n + 1 - (1 << i); ++j) {
            tail += !(pairs[j][0] == pairs[j - 1][0] && pairs[j][1] == pairs[j - 1][1]);
            kmr[i][j] = tail;
        }
    }
    for (int i = 1; i <= n; i++){
        cout << kmr[3][i] << ' ';
    }
    return 0;
}

