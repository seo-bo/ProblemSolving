#include <bits/stdc++.h>
#include <atcoder/all>
using namespace std;
using namespace atcoder;
typedef long long ll;

int main(void)
{
	cin.tie(0)->sync_with_stdio(0);
	int n = 0;
	cin >> n;
	string A, B;
	cin >> A >> B;
	for (int i = 0; i < n; ++i)
	{
		char a = A[i], b = B[i];
		if (a == b)
		{
			continue;
		}
		if (b == '0' || b == '1')
		{
			swap(a, b);
		}
		if (a == '0' && b == 'o')
		{
			continue;
		}
		if (a == '1' && b == 'l')
		{
			continue;
		}
		cout << "No";
		return 0;
	}
	cout << "Yes";
	return 0;
}
