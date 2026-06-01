#include <bits/stdc++.h>
#include <atcoder/all>
using namespace std;
using namespace atcoder;
typedef long long ll;

int main(void)
{
	cin.tie(0)->sync_with_stdio(0);
	int n = 0, m = 0;
	cin >> n >> m;
	string A, B;
	cin >> A >> B;
	int f1 = 1, f2 = 1;
	for (int i = 0; i < n; ++i)
	{
		if (A[i] != B[i])
		{
			f1 = 0;
			break;
		}
	}
	reverse(A.begin(), A.end());
	reverse(B.begin(), B.end());
	for (int i = 0; i < n; ++i)
	{
		if (A[i] != B[i])
		{
			f2 = 0;
			break;
		}
	}
	if (f1)
	{
		if (f2)
		{
			cout << 0;
		}
		else
		{
			cout << 1;
		}
		return 0;
	}
	if (f2)
	{
		cout << 2;
		return 0;
	}
	cout << 3;
	return 0;
}
