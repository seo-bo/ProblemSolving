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
	int len = str.size();
	string maxi(len, 'a'), mini(len, 'z');
	for (int i = 0; i < len; ++i)
	{
		string temp;
		for (int j = 0; j < len; ++j)
		{
			temp += str[(i + j) % len];
		}
		maxi = max(maxi, temp);
		mini = min(mini, temp);
	}
	cout << mini << '\n' << maxi;
	return 0;
}
