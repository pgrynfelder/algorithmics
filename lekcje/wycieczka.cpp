#include<bits/stdc++.h>

using namespace std;

int distances[(int)10e5+7];
int n;
int k;

bool sol(long long x){
        long long i = 0;
        long long days = 1;
	long long current = 0;
        while (i <= n){
		current += distances[i];
		if (current > x){
			current = distances[i];
			if (current > x){
				return false;
			}
			days++;
		}
		i++;
	}
	return days <= k;
}

void bs(long long l, long long r){
        while (l < r){
		long long mid = (l+r)/2;
                if (sol(mid)){
                        r = mid;
                }
                else {
                        l = mid+1;
                }
        }
	cout << l << '\n';
}

int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin >> n >> k;
	n-=1;
	long long suma = 0;
	for (int i = 1; i <= n; i++){
		cin >> distances[i];
		suma += distances[i];
	}
	bs(0, suma);
	return 0;
}
