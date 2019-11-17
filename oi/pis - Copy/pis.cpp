#include<iostream>
#define isalpha(c) (('A' <= c and c <= 'Z') or ('A' <= c and c <= 'Z'))
#define isupper(c) ('A' <= c and c <= 'Z')
#define isdigit(c) ('0' <= c and c <= '9')
#define lower(c) (('A' <= c and c <= 'Z') ? c + ('a' - 'A') : c)

using namespace std;

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    return 0;
}
