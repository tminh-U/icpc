struct ST2D {
	int st[N * 3][N * 3];
	void updatey(int idx, int lx, int rx, int idy, int ly, int ry, int y, int val) {
		if (ly == ry) {
			if (lx == rx) {
				st[idx][idy] = val;
			} else {
				st[idx][idy] = f(st[idx << 1][idy], st[idx << 1 | 1][idy]);
			}
			return;
		}
		int midy = (ly + ry) >> 1;
		if (y <= midy) {
			updatey(idx, lx, rx, idy << 1, ly, midy, y, val);
		} else {
			updatey(idx, lx, rx, idy << 1 | 1, midy + 1, ry, y, val);
		}
		st[idx][idy] = f(st[idx][idy << 1], st[idx][idy << 1 | 1]);
	}
	
	void updatex(int idx, int lx, int rx, int x, int y, int val) {
		if (lx != rx) {
			int midx = (lx + rx) >> 1;
			if (x <= midx) {
				updatex(idx << 1, lx, midx, x, y, val);
			} else {
				updatex(idx << 1 | 1, midx + 1, rx, x, y, val);
			}
		}
		updatey(idx, lx, rx, 1, 2, m + n, y, val);
	}
	
	int gety(int idx, int idy, int ly, int ry, int l, int r) {
		if (l > ry || r < ly) return 0;
		if (l <= ly && ry <= r) return st[idx][idy];
		
		int midy = (ly + ry) >> 1;
		return f(gety(idx, idy << 1, ly, midy, l, r), gety(idx, idy << 1 | 1, midy + 1, ry, l, r)); 
	}
	
	int getx(int idx, int lx, int rx, int x, int y, int u, int v) {
		if (lx > u || rx < x) return 0;
		if (x <= lx && rx <= u) return gety(idx, 1, 2, m + n, y, v);
		
		int midx = (lx + rx) >> 1;
		return f(getx(idx << 1, lx, midx, x, y, u, v), getx(idx << 1 | 1, midx + 1, rx, x, y, u, v));
	}
	
	inline int get(int x, int y, int u, int v) {
		x = max(x, 1 - m);
		u = min(u, n - 1);
		
		y = max(y, 2);
		v = min(v, n + m);
		
		return getx(1, 0, n + m - 2, x + base, y, u + base, v);
	}
	
	inline void update(const int x, const int y, const int val) {
		updatex(1, 0, n + m - 2, x + base, y, val);
	}
	
} st;