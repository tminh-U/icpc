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



int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);

	system("g++ -std=c++20 -Wall -O2 gen.cpp -o gen.exe");
	system("g++ -std=c++20 -Wall -O2 brute.cpp -o brute.exe");
	system("g++ -std=c++20 -Wall -O2 solve.cpp -o solve.exe");
    while(true) {
		system("gen.exe > test.txt");
    	system("brute.exe < test.txt > o1.out");
    	system("solve.exe < test.txt > o2.out");
    	
    	if (system("FC o1.out o2.out")) {
    		cout << "SAI";
    		return 0;
    	}
    }
    cerr << "Time elapsed: " << 1.0 * clock() / CLOCKS_PER_SEC << 's' << endl;
    return 0;
}
