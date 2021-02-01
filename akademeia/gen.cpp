#include <bits/stdc++.h>
using namespace std;

int random(int a, int b) { return rand() % (b - a + 1) + a; }

int main(int argc, char **argv) { srand(atoi(argv[1])); }