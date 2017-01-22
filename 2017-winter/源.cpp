#include <iostream>
#include <string>
#include <cstring>
#include <algorithm>
using namespace std;
#define MAXN 1000100
int Next[MAXN];
void makeNext(const string &s)
{
	int i = 0, j = -1, len = s.length();
	while(i < len)
	{
		if (j == -1 || s[i] == s[j])
		{
			Next[i] = j;
			i++, j++;
		}
		else
			j = Next[j];
	}
}
int KMP(const string &p, const string &q)
{
	int cnt = 0, lenp = p.length(), lenq = q.length();
	makeNext(q);
	for(int i = 0, j = 0; i < lenp; i++)
	{
		while(i < lenp && j < lenq)
		{
			if (p[i] == q[j])
				i++, j++;
			else if (j == 0)
				i++;
			else
				j = Next[j - 1] + 1;
		}
		if(j == lenq)
		{
			cnt++;
			j = Next[j - 1] + 1;
			i += j - lenq;
		}
	}
	return cnt;
}
int main()
{
	int n;
	cin >> n;
	string s1, s2;
	while(n--)
	{
		memset(Next, 0, sizeof(Next));
		cin >> s1 >> s2;
		cout << KMP(s2, s1) << endl;
	}
	system("pause");
	return 0;
}