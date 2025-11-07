struct DSU {
	int par[N], sz[N];
	stack<pair<int*, int>> s;
	void init() {
		for (int i = 1; i <= n; ++i) {
			par[i] = i;
			sz[i] = 1;
		}
	}
	int find(int v) {
		while(v != par[v]) v = par[v];
		return v;
	}
	void merge(int a, int b) {
		a = find(a);
		b = find(b);
		
		if (a != b) {
			if (sz[a] < sz[b]) swap(a, b);
			s.push(make_pair(&sz[a], sz[a]));
			s.push(make_pair(&par[b], par[b]));
			sz[a] += sz[b];
			par[b] = a;
		}
	}
	void rollback(int snap) {
		while(sze(s) > snap) {
			auto[it, val] = s.top();
			s.pop();
			*it = val;
		}
	}
} dsu;
struct node {
	int u, v, l, r;
	node(int u_, int v_, int l_, int r_) : u(u_), v(v_), l(l_), r(r_) {}
};
void dnc(int l, int r, vector<node> &Q) {
	int mid = (l + r) >> 1;
	int snap = sze(dsu.s);
	
	vector<node> ql, qr;
	for (auto[u, v, L, R] : Q) {
		if (L <= l && r <= R) {
			dsu.merge(u, v);
		} else {
			if (L <= mid) ql.pb(node(u, v, L, R));
			if (mid < R) qr.pb(node(u, v, L, R)); 
		}
	}
	
	if (l == r) {
		//stuff
	} else {
		dnc(l, mid, ql);
		dnc(mid + 1, r, qr);
	}
	dsu.rollback(snap);
}
