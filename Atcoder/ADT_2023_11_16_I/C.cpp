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
	int alen = A.size(), blen = B.size();
	for (int i = 0; i + blen <= alen; ++i)
	{
		string temp;
		for (int j = i; j < i + blen; ++j)
		{
			temp += A[j];
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
