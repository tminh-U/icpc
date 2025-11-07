struct mat {
	int d[N][N], n, m;
	mat(int n_ = 0, int m_ = 0) {
		memset(d, 0, sizeof(d));
		n = n_; m = m_;
	}
	mat operator*(const mat &other) const {
		mat res(n, other.m);
		for (int i = 0; i < n; ++i) {
			for (int k = 0; k < other.m; ++k) {
				for (int j = 0; j < m; ++j) {
					res.d[i][k] = (res.d[i][k] + 1ll * d[i][j] * other.d[j][k]) % mod;
				}
			}
		}
		return res;
	}
	mat operator^(ll k) const {
		mat res(n, n);
		mat mul = *this;
		for (int i = 0; i < n; ++i) res.d[i][i] = 1;
		while(k) {
			if (k & 1) res = res * mul;
			mul = mul * mul;
			k >>= 1;
		}
		return res;
	}
};

