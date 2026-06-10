#include <bits/stdc++.h>
#include <atcoder/all>
using namespace std;
using namespace atcoder;
typedef long long ll;

int main(void)
{
	cin.tie(0)->sync_with_stdio(0);
	string str;
	cin >> str;
	vector<int> B, K, R;
	for (int i = 0; i < 8; ++i)
	{
		if (str[i] == 'B')
		{
			B.push_back(i);
		}
		else if (str[i] == 'K')
		{
			K.push_back(i);
		}
		else if (str[i] == 'R')
		{
			R.push_back(i);
		}
	}
	int flag = (((B[0] + B[1]) % 2) & (R[0] <= K[0] && K[0] <= R[1]));
	cout << ((flag) ? "Yes" : "No");
	return 0;
}
