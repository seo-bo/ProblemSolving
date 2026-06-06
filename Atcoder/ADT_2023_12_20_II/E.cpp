#include <bits/stdc++.h>
#include <atcoder/all>
using namespace std;
using namespace atcoder;
typedef long long ll;

int main(void)
{
	cin.tie(0)->sync_with_stdio(0);
	string S, T;
	cin >> S >> T;
	int len = S.size();
	for (int i = 0; i < len; ++i)
	{
		if (S[i] != T[i])
		{
			cout << i + 1;
			return 0;
		}
	}
	cout << len + 1;
	return 0;
}
