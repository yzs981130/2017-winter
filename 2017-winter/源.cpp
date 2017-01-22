#include <iostream>
#include <string>
#include <cstring>
#include <algorithm>
using namespace std;
struct Node
{
	int cnt;
	Node *ch[26];
	Node() { memset(ch, 0, sizeof(ch)); cnt = 0; }
}*root;
void Insert(const string &str)
{
	Node *current, *newnode;
	int len = str.length();
	current = root;
	for (int i = 0; i < len; i++)
		if (current->ch[str[i] - 'a'] != NULL)
		{
			current = current->ch[str[i] - 'a'];
			current->cnt++;
		}
		else
		{
			newnode = new Node();
			current->ch[str[i] - 'a'] = newnode;
			current = current->ch[str[i] - 'a'];
			current->cnt = 1;
		}
}
int Find(const string &str)
{
	Node *current;
	int len = str.length();
	if (len == 0)
		return 0;
	current = root;
	for (int i = 0; i < len; i++)
		if (current->ch[str[i] - 'a'] != NULL)
			current = current->ch[str[i] - 'a'];
		else
			return 0;
	return current->cnt;
}
int main()
{
	int cntd = 0, cntq = 0;
	cin >> cntd;
	string s;
	root = new Node();
	for(int i = 0; i < cntd; i++)
	{
		cin >> s;
		Insert(s);
	}
	cin >> cntq;
	for(int i = 0; i < cntq; i++)
	{
		cin >> s;
		cout << Find(s) << endl;
	}
	system("pause");
	return 0;
}