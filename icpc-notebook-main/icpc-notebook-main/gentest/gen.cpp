#include "bits/stdc++.h"
using namespace std;

#define ll long long
const ll mod = 1e9 + 7;
const int N = 1e6 + 5;
const ll oo = 1e18;

mt19937_64 rng(chrono::steady_clock::now().time_since_epoch().count());
int rnd(int l, int r) {
    return uniform_int_distribution<ll>(l, r)(rng);
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);

    cerr << "Time elapsed: " << 1.0 * clock() / CLOCKS_PER_SEC << 's' << endl;
    return 0;
}
