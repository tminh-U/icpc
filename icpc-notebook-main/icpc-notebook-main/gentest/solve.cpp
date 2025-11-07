#include "bits/stdc++.h"
using namespace std;

#define task ""
#define ll long long
#define endl '\n'
#define fi first
#define se second
#define vall(a) (a).begin(), (a).end()
#define sze(a) (int)a.size()
#define pii pair<int, int>
#define pll pair<ll, ll>


#define ep emplace_back
#define pb push_back
#define pf push_front


const ll mod = 1e9 + 7;
const int N = 1e6 + 5;
const ll oo = 1e18;

bool START;


int n, m;
ll a[N], b[N], k;
vector<ll> am, duong;

bool check(ll x) {
	ll cnt = 0;
	for (int i = 1; i <= n; ++i) {
		if (a[i] == 0) {
			cnt += sze(duong) + sze(am);
			continue;
		}
		ll val = (x / a[i]);
		if (val < 0 && a[i] < 0) {
			cnt += sze(duong);
			cnt += (upper_bound(vall(am), val) - am.begin());
		}
		if (val < 0 && a[i] > 0) {
			cnt += (am.end() - lower_bound(vall(am), val));
		}
		
		if (val >= 0 && a[i] > 0) {
			cnt += sze(am);
			cnt += (upper_bound(vall(duong), val) - duong.begin());
		}
		if (val >= 0 && a[i] < 0) {
			cnt += (duong.end() - lower_bound(vall(duong), val));
		}	
	}
	return cnt >= k;
}


ll cnp() {
	ll l = -oo, r = oo, ans = -oo;
	while(l <= r) {
		ll mid = (l + r) >> 1;
		if (check(mid)) {
			ans = mid;
			r = mid - 1;
		} else {
			l = mid + 1;
		}
	}
	return ans;
}


inline void solve() {
	for (int i = 1; i <= m; ++i) {
		if (b[i] < 0) {
			am.pb(b[i]);
		} else {
			duong.pb(b[i]);
		}
	}
	cout << cnp();
	// cout << check(0);
}


inline void input() {
	cin >> k >> n;
	for (int i = 1; i <= n; ++i) cin >> a[i];
	cin >> m;
	for (int i = 1; i <= m; ++i) cin >> b[i];    
    return solve();
}
bool END;

int main() {
    if(fopen(task ".inp", "r")) {
        freopen(task ".inp", "r", stdin);
        freopen(task ".out", "w", stdout);
    }
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);

    input();
    
    
    cerr << endl << "Time elapsed: " << 1.0 * clock() / CLOCKS_PER_SEC << 's' << endl;
    cerr << "Memory: " << fabs ((&END - &START)) / 1048576.0 << "MB\n";
    return 0;
}
//444
