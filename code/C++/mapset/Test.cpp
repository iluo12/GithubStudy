#include <iostream>
#include <set>
#include <map>
using namespace std;


void SetTest()
{
	set<int> st;
	st.insert(3);
	st.insert(2);
	st.insert(4);
	st.insert(2);
	st.insert(1);

	set<int>::iterator it = st.begin();
	while (it != st.end())
	{
		cout << *it << " ";
		it++;
	}
	cout << endl;

	for (auto e : st)
	{
		cout << e << " ";
	}
	cout << endl;
}

void multisetTest()
{
	multiset<int> st;
	st.insert(3);
	st.insert(2);
	st.insert(4);
	st.insert(2);
	st.insert(1);

	set<int>::iterator it = st.begin();
	while (it != st.end())
	{
		cout << *it << " ";
		it++;
	}
	cout << endl;

	for (auto e : st)
	{
		cout << e << " ";
	}
	cout << endl;
}

void mapTest()
{
	map<int,string> mp;
	mp.insert(make_pair(3,"Èı"));
	mp.insert(make_pair(1,"Ò»"));
	mp.insert(make_pair(5,"Îå"));
	mp.insert(make_pair(6,"Áù"));

	map<int, string>::iterator it = mp.begin();
	while (it != mp.end())
	{
		cout << (*it).first << ":" << (*it).second;
	//	cout << it->first << ":" << it->second;
		it++;
		cout << endl;
	}
	cout << endl;

	for (auto e : mp)
	{
		cout << e.first << ":" << e.second;
		cout << endl;
	}
	cout << endl;

	
}
int main()
{
	SetTest();
	multisetTest();
	mapTest();
	return 0;
}