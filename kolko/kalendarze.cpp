#include<bits/stdc++.h>

using namespace std;

uint32_t a[1000000+8];
uint32_t b[1000000+8];

uint32_t suma[1000000+8];
uint32_t sumb[1000000+8];

uint32_t a2b(uint32_t day, uint32_t month, uint32_t m)
{
    uint32_t days = suma[month-1] + day;

    uint32_t begin = 1;
    uint32_t end = m;

    while(begin<end){
        int current = (begin + end)/2;
        if(sumb[current] < days){
            begin = current + 1;
        }
        else {
            end = current;
        }

    }
    cout << days - sumb[begin-1] << " " << begin << "\n";
}

uint32_t b2a(uint32_t day, uint32_t month, uint32_t n)
{
    uint32_t days = sumb[month-1] + day;

    uint32_t begin = 1;
    uint32_t end = n;

    while(begin<end){
        uint32_t current = (begin + end)/2;
        if(suma[current] < days){
            begin = current + 1;
        }
        else {
            end = current;
        }

    }
    cout << days - suma[begin-1] << " " << begin << "\n";
}


int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    
    uint32_t n, m, z;
    cin >> n >> m;

    for(uint32_t i = 1; i <= n; i++)
    {
        cin >> a[i];
        suma[i] = suma[i-1]+a[i];
    }

    for(uint32_t i = 1; i <= m; i++)
    {
        cin >> b[i];
        sumb[i] = sumb[i-1]+b[i];
    }

    cin >> z;
    
    for(uint32_t i = 0; i < z; i++)
    {
        uint32_t day, month;
        char c;

        cin >> day >> month >> c;

        if(c=='A'){
            a2b(day, month, m);
        }
        else {
            b2a(day, month, n);
        }
    }
    
    
}