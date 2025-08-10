#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

int main(void)
{
	cin.tie(0)->sync_with_stdio(0);
	int T = 0;
	cin >> T;
	while (T--)
	{
		int n = 0;
		cin >> n;
		vector<ll>A(n + 1), B(n + 1);
		for (int i = 1; i <= n; ++i)
		{
			cin >> A[i];
		}
		for (int i = 1; i <= n; ++i)
		{
			cin >> B[i];
		}
		auto sv = [&]
			{
				if (A[n] != B[n])
				{
					return false;
				}
				for (int i = n - 1; i >= 1; --i)
				{
					if (A[i] == B[i])
					{
						continue;
					}
					ll a = A[i + 1] ^ A[i];
					ll b = B[i + 1] ^ A[i];
					if (!(a == B[i]) && !(b == B[i]))
					{
						return false;
					}
				}
				return true;
			};
		cout << ((sv()) ? "YES\n" : "NO\n");
	}
	return 0;
}
