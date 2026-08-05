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
	int len = A.size();
	int pivot = -1;
	for (int i = 0; i < len; ++i)
	{
		int temp = -1;
		int a = A[i] - 'a' + 1, b = B[i] - 'a' + 1;
		if (a < b)
		{
			temp = b - a;
		}
		else
		{
			temp = 26 - a + b;
		}
		if (pivot == -1)
		{
			pivot = temp;
			continue;
		}
		if (pivot != temp)
		{
			cout << "No";
			return 0;
		}
	}
	cout << "Yes";
	return 0;
}
