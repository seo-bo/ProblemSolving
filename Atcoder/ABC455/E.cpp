#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef tuple<ll, ll, ll>tp;

int main(void)
{
	cin.tie(0)->sync_with_stdio(0);
	ll n = 0;
	cin >> n;
	string str;
	cin >> str;
	ll ans = n * (n + 1) / 2;
	ll a = 0, b = 0, c = 0;
	map<ll, ll>A, B, C;
	map<tp, ll>D;
	A[0] = B[0] = C[0] = D[make_tuple(0, 0, 0)] = 1;
	for (auto& i : str) // al - ar == bl - br -> al - bl == ar - br, 
	{
		a += (i == 'A'), b += (i == 'B'), c += (i == 'C');
		ll pa = a - b, pb = b - c, pc = c - a;
		tp temp = make_tuple(pa, pb, pc); // A == B & B == C & C == A
		ans -= A[pa]++ + B[pb]++ + C[pc]++ - D[temp]++ * 2; // A == B == C ?
	}
	cout << ans;
	return 0;
}
