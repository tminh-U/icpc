struct HLD {
	int depth[N], nxt[N], par[N], sz[N];
	void build(int u, int p) {
		sz[u] = 1;
		int best_child = 0;
		for (int v : adj[u]) {
			if (v == p) continue;
			depth[v] = depth[u] + 1;
			par[v] = u;
			
			build(v, u);
			sz[u] += sz[v];
			if (sz[v] > sz[best_child]) best_child = v;
		}
		nxt[u] = best_child;
	}
	
	int idx = 1;
	void assign_chain(int u, int cur) {
		chain[u] = cur; id[u] = idx++;
		if (nxt[u]) assign_chain(nxt[u], cur);
		for (int v : adj[u]) if (v != par[u] && v != nxt[u]) assign_chain(v, v);
	}
	
	int queries(int u, int v) {
		int res = 0;
		for (; chain[u] != chain[v]; v = par[chain[v]]) {
			if (depth[chain[u]] > depth[chain[v]]) swap(u, v);
			res = f(res, f(1, 1, n, id[chain[v]], id[v]));
		}
		if (depth[u] > depth[v]) swap(u, v);
		return f(res, f(1, 1, n, id[u], id[v]));
	}
} hld;