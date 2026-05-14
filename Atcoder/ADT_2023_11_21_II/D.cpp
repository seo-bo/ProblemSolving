#include <bits/stdc++.h>
#include <atcoder/all>
using namespace std;
using namespace atcoder;
typedef long long ll;

int main(void)
{
	cin.tie(0)->sync_with_stdio(0);
	string A, B;
	cin >> A >> B;
	for (int i = 0; i <= 26; ++i)
	{
		string temp = A;
		for (auto &j : temp)
		{
			int a = (j - 'a' + i) % 26;
			j = char(a + 'a');
		}
		if (temp == B)
		{
			cout << "Yes";
			return 0;
		}
	}
	cout << "No";
	return 0;
}
