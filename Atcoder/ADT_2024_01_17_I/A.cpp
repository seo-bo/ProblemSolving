#include <bits/stdc++.h>
#include <atcoder/all>
using namespace std;
using namespace atcoder;
typedef long long ll;

int main(void)
{
	cin.tie(0)->sync_with_stdio(0);
	vector<int> v = {3858, 3679, 3658, 3648, 3638, 3630, 3613, 3555, 3516, 3481};
	string base = "tkBUaSemns";
	string str;
	cin >> str;
	for (int i = 0;; ++i)
	{
		if (str.front() == base[i])
		{
			cout << v[i];
			return 0;
		}
	}
	return 0;
}
