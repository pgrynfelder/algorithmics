#include<bits/stdc++.h>
#define lower(c) (isupper(c) ? (c + 32) : c)

using namespace std;
typedef unsigned long long ull;

double t[59];
double w1[];
double t1[20];
double w2[];
double t2[20];
double w3[];
double t3[3];

constexpr int P = 1e6 + 7, MOD = 1e9 + 7;

double avg(vector<int> &v){
    double r = 0;
    for (int y : v){
        r += y;
    }
    return r / v.size();
}

double sqd(vector<int> &v, double &x){
    double r = 0;
    for (int y : v){
        r += pow((y-x), 2);
    }
    return sqrt(r / v.size());
}

void pcs(const string &s){
    fill(t, t+58, 0);
    t[55] = s.size() - 3;
    unordered_map<int, int> whs;
    t[56] = 0;
    t[57] = 0;
    int uc = 0, uw = 0, wl = 0, sc = 0, sw = 0, wh = 0;
    vector<int> ucs, uws, scs, sws, wls;
    for (int i = 0; i < t[55] + 1; i++){
        char c = s[i];
        cout << c;
        bool pw = 1; 
        bool ps = 0;
        if (isalpha(c)){
            t[0]++;
            t[lower(c) - 'a' + 29]++;
            pw = 0;
            wl++;
            wh = ((ull)P * wh + lower(c)) % MOD;
            if (isupper(c)){
                t[1]++;
                ucs.push_back(uc);
                uws.push_back(uw);
                uc = uw = 0;
            }
            if (lower(c) == 'u'){
                if (lower(s[i+1]) == 's') t[58]++;
            }
        }
        else if (isdigit(c)) t[2]++;
        else if (c==' ') t[3]++;
        else if (c=='.'){
            ps = 1;
            t[4]++;
            if (s[i+1] == '.' and s[i+2] == '.') t[5]++;
        }
        else if (c==',') t[6]++;
        else if (c == ';') t[7]++;
        else if (c == ':') t[8]++;
        else if (c == '"') t[9]++;
        else if (c == '-') t[10]++;
        else if (c == '?'){
            t[11]++;
            ps=1;
        } else if (c == '!'){
            t[12]++;
            ps=1;
        } else if (c=='^') ps=1;
        sc++; uc++;

        if (pw and wl){
            t[56]++;
            if (wh == 325955471)
                t[13]++;
            else if (wh == 105)
                t[14]++;
            else if (wh == 992934780)
                t[15]++;
            else if (wh == 97)
                t[16]++;
            uw++; sw++;
            wls.push_back(wl);
            whs[wh]++;
            wl = wh = 0;
        }
        if (ps and sw){
            t[57]++;
            scs.push_back(sc);
            sws.push_back(sw);
            sc = sw = 0;
        }
    }
    t[17] = whs.size();
    for (auto &xd : whs)
        t[18] += (xd.second == 1 ? 1 : 0);
    t[19] = avg(wls);
    t[20] = sqd(wls, t[19]);
    t[21] = avg(scs);
    t[22] = sqd(scs, t[21]);
    t[23] = avg(sws);
    t[24] = sqd(sws, t[23]);
    if (ucs.size()){
        t[25] = avg(ucs);
        t[26] = sqd(ucs, t[25]);
    } else {
        t[25] = t[26] = 0;
    }
    if (uws.size()){
        t[27] = avg(uws);
        t[28] = sqd(uws, t[27]);
    } else {
        t[27] = t[28] = 0;
    }
    for (int i = 0; i < 13; i++) t[i] /= t[55];
    for (int i = 29; i < 55; i++) t[i] /= t[55];
    for (int i = 13; i < 19; i++) t[i] /= t[56];
    t[58] /= t[56];
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int q;
    cin >> q;
    string s;
    cin.ignore();
    while (q--){
        getline(cin, s);
        s = s + "^^^";
        pcs(s);
        for (int i = 0; i < 59; i++){
            cout << t[i] << "\n";
        }
    }
    cout << "FINISHED";
    return 0;
}
