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
	string str, A, B;
	cin >> str;
	for (int i = 0; i < n; ++i)
	{
		A += str[i];
		B += str[n + i];
	}
	string ra = A, rb = B;
	reverse(ra.begin(), ra.end()), reverse(rb.begin(), rb.end());
	A += rb, B = ra + B;
	vector<int>va = z_algorithm(A);
	vector<int>vb = z_algorithm(B);
	va.push_back(0), vb.push_back(0);
	int len = 2 * n;
	/*
	어쩌피 문자열은 str = [A + rev(B)][rev(A) + B]인데
	이때 |A| = i / |B| = n-i이라고 할때
	C#1 - [A + rev(B)] [rev(B) + A] 일때 Z 알고리즘으로 i 구하고
	C#2 - [B + rev(A)] [rev(A) + B] 일때 i를 구했으니 Z알고리즘으로 n - i 추적
	*/
	for (int i = 0; i <= n; ++i)
	{
		if (va[len - i] < i || vb[n + i] < n - i)
		{
			continue;
		}
		for (int j = 0; j < i; ++j)
		{
			cout << str[j];
		}
		for (int j = n + i; j < 2 * n; ++j)
		{
			cout << str[j];
		}
		cout << '\n' << i;
		return 0;
	}
	cout << -1;
	return 0;
}
