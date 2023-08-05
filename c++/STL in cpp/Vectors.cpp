#include <bits/stdc++.h>
using namespace std;

// void PrintVector(vector<int> v)   {
//     cout<< "size: "<<v.size()<< endl;
//     for(int i=0;i<v.size();i++)
//     cout<< v[i] <<" ";
// cout << endl;

// void PrintVector(vector<string> v)   {
//     cout<< "size: "<<v.size()<< endl;
//     for(int i=0;i<v.size();i++)
//     cout<< v[i] <<" ";
// cout << endl;

void PrintVector(vector<pair<int, int>> v)
{
	cout << "size: " << v.size() << endl;
	for (int i = 0; i < v.size(); i++)
		cout << v[i].first << " " << v[i].second << endl;
	cout << endl;
}
int main()
{
	// vector<int> v;
	// int n;
	// cin>> n;
	// for(int i=0;i<n;i++) {
	//     int x;
	//     cin >> x;
	//     PrintVector(v);
	//     v.push_back(x);
	// }

	// vector<string> v;
	// int n;
	// cin>>n;
	// for( int i=0;i<n;i++) {
	// 	string s;
	// 	cin>>s;
	// 	v.push_back(s);
	// }


	// vector<pair<int, int>> v = {{1, 2}, {2, 3}, {3, 4}};
	vector<pair<int, int>> v;
	PrintVector(v);

	int n;
	cin >> n;
	for (int i = 0; i < n; i++)
	{
		int x, y;
		cin >> x >> y;
		v.push_back({x, y});
	}
	PrintVector(v);
	return 0;
}