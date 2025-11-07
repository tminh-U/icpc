stack<int> topo;
void dfs(int u) {
	vis[u] = 2;
	for (int v : adj[u]) {
		if (vis[u] == 2) exit(0);
		
		if (vis[u] == 1) continue;
		dfs(v);
	}
	vis[u] = 1;
	topo.push(u);
}
reverse(vall(topo));