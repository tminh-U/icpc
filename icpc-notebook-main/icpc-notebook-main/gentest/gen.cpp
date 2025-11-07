#include "bits/stdc++.h"
using namespace std;

#define task ""
#define ll long long
#define endl '\n'
#define fi first
#define se second
#define vall(a) (a).begin(), (a).end()
#define sze(a) (int)a.size()

#define ep emplace_back
#define pb push_back
#define pf push_front

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

    
    cerr << "Generated n=" << n << '\n';
    cerr << "Time elapsed: " << 1.0 * clock() / CLOCKS_PER_SEC << 's' << endl;
    return 0;
}
