#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

constexpr ll N = 1e14 + 7, sqrtN = 1e7 + 7;
ll n, k, c;

// returns prime factorisation of n, for n in task it's guaranteed it has no
// more than 13 prime divisors
vector<ll> factor(ll n) {  // O(sqrt(n) + 13)
    vector<ll> factors;
    for (int i = 2; i * i <= n; i++) {
        if (n % i == 0) {
            factors.emplace_back(i);
            while (n % i == 0) n /= i;
        }
    }
    if (n > 1) factors.emplace_back(n);

    return factors;  // at most 13
}

// numbers divisible by any p in primes on [1..n]
ll divisible(const vector<ll> &primes, ll n) {
    ll cnt = 0;
    size_t maxmask = 1 << primes.size();
    for (size_t mask = 0; mask < maxmask; mask++) {
        ll product = 1;
        for (size_t i = 0; (1 << i) <= mask; i++)
            if ((1 << i) & mask) product *= primes[i];
        // sign = (-1)^(|primes|+|subset|)
        bool odd = (__builtin_popcount(mask) + primes.size()) & 1;
        if (odd)
            cnt -= n / product;
        else
            cnt += n / product;
    }
    return cnt;
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    cin >> n >> k >> c;

    auto factors = factor(n);

    for (auto c : factors) cout << c << " ";
    cout << "\n";



    return 0;
}