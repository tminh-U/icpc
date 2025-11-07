void dfs(int u) {
	low[u] = num[u] = ++t;
	s.push(u);
	for (int v : adj[u]) {
		if (num[v] == n + 1) continue;
		if (!num[v]) {
			dfs(v);
			low[u] = min(low[u], low[v]);
		} else low[u] = min(low[u], num[v]);
	}
	if (low[u] == num[u]) {
		++cc;
		int v = 0;
		while(v != u) {
			v = s.top();
			
			scc[v] = cc;
			num[v] = n + 1;
			++cc_sz[cc];
			
			s.pop();
		}
	}
}