#include <bits/stdc++.h>
#include <atcoder/all>
using namespace std;
using namespace atcoder;
typedef long long ll;

int main(void)
{
	cin.tie(0)->sync_with_stdio(0);
	ll n = 0, k = 0, q = 0;
	cin >> n >> k >> q;
	vector<ll> v(n + 1, -1);
	multiset<ll> A, B;
	ll sum = 0;
	while (q--)
	{
		ll a = 0, b = 0;
		cin >> a >> b;
		if (v[a] == -1)
		{
			A.insert(b);
			sum += b;
		}
		else
		{
			auto it = A.find(v[a]);
			if(it != A.end())
			{
				sum -= v[a];
				A.erase(it);
			}
			else
			{
				B.erase(B.find(v[a]));
			}
			A.insert(b);
			sum += b;
		}
		v[a] = b;
		while (A.size() > k)
		{
			auto it = A.begin();
			sum -= *it;
			B.insert(*it);
			A.erase(it);
		}
		while (!B.empty() && *prev(B.end()) > *A.begin())
		{
			auto it = prev(B.end());
			auto jt = A.begin();
			ll pa = *it, pb = *jt;
			sum += pa - pb;
			B.erase(it), A.erase(jt);
			A.insert(pa), B.insert(pb);
		}
		cout << sum << '\n';
	}
	return 0;
}
