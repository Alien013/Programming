#include <iostream>
#include <array>     //line-18
#include <vector>    //line-31
#include <deque>     //line-83
#include <list>      //line-118
#include <stack>     //line-176
#include <queue>     //line-190
#include <set>       //line-246
#include <map>       //line-286
#include <algorithm> //line-235

using namespace std;
int main()
{

    // Arrays
    // int arr1[]={1,2,3};

    // array<int,3> a={1,2,3};
    // int size=a.size();

    // for(int i=0;i<3;i++) {
    //     cout<<a[i]<<endl;
    // }

    // cout<<"Element at second index "<<a.at(2)<<endl;
    // cout<<"Array is empty or not "<<a.empty()<<endl;
    // cout<<"First element of Array "<<a.front()<<endl;
    // cout<<"Last element of Array "<<a.back()<<endl;

    // Vector
    //  vector<int> v;
    //  vector<int> v1(5,1);
    //  cout<<"\nVector v1 "<<endl;

    // for(int i:v1) {
    //     cout<<i<<" ";
    // }
    // cout<<endl;

    // cout<< "Capacity "<<v.capacity()<<endl;

    // v.push_back(1);
    // cout<< "Capacity "<<v.capacity()<<endl;

    // v.push_back(2);
    // cout<< "Capacity "<<v.capacity()<<endl;

    // v.push_back(3);
    // cout<< "Capacity "<<v.capacity()<<endl;

    // cout<<"Size "<<v.size()<<endl;

    // cout<<"Element at 2nd index "<<v.at(2)<<endl;

    // cout<<"First Element "<<v.front()<<endl;
    // cout<<"Last Element "<<v.back()<<endl;

    // cout<<"Before pop"<<endl;
    // for(int i:v) {
    //     cout<<i<<" ";
    // }
    // cout<<endl;

    // v.pop_back();

    // cout<<"After pop"<<endl;
    // for(int i:v) {
    //     cout<<i<<" ";
    // }
    // cout<<endl;

    // cout<<"Before clear size "<<v.size()<<endl;

    // cout<<"Before clear capacpty "<<v.capacity()<<endl;

    // v.clear();

    // cout<<"After clear size "<<v.size()<<endl;

    // cout<<"After clear capacpty "<<v.capacity()<<endl;

    // Deque
    //  deque<int> d;

    // d.push_back(2);
    // d.push_front(1);
    // d.push_back(3);
    // d.push_back(4);
    // d.push_back(5);

    // for(int i:d) {
    //     cout<<i<<" ";
    // }
    // cout<<endl;

    // d.pop_back();

    // for(int i:d) {
    //     cout<<i<<" ";
    // }
    // cout<<endl;

    // cout<<"First element of deque "<<d.front()<<endl;
    // cout<<"Last element of deque "<<d.back()<<endl;

    // cout<<"Empty or not: "<<d.empty()<<endl;

    // cout<<"Before erase "<<d.size()<<endl;
    // d.erase(d.begin(),d.begin()+1);
    // cout<<"After erase "<<d.size()<<endl;

    // for (int i : d)
    // {
    //     cout << i << " ";
    // }

    // Lists
    // list<int> l;
    // list<int> l1(5,100);

    // l.push_back(2);
    // l.push_front(1);
    // l.push_back(3);

    // for (int i : l)
    // {
    //     cout << i << " ";
    // }
    // cout << endl;
    // cout << endl;

    // cout<<"List l1 "<<endl;
    // for (int i : l1)
    // {
    //     cout << i << " ";
    // }
    // cout << endl;

    // cout << "before erase" << endl;
    // for (int i : l)
    // {
    //     cout << i << " ";
    // }
    // cout << endl;

    // l.erase(l.begin());

    // cout << "After erase" << endl;
    // for (int i : l)
    // {
    //     cout << i << " ";
    // }
    // cout << endl;

    // l.pop_front();
    // l.pop_back();

    // for (int i : l)
    // {
    //     cout << i << " ";
    // }
    // cout << endl;

    // l.push_back(2);
    // l.push_front(1);
    // l.push_back(3);
    // for (int i : l)
    // {
    //     cout << i << " ";
    // }
    // cout << endl;

    // cout<<"Size of list "<<l.size()<<endl;

    // Stack
    //  stack<string> s;
    //  s.push("Kushwaha");
    //  s.push("Kumar");
    //  s.push("Manoj");
    //  cout<<"size of stack "<< s.size()<<endl;

    // cout<<"Top element "<<s.top()<<endl;
    // s.pop();
    // cout<<"Top element "<<s.top()<<endl;

    // cout<<"size of stack "<< s.size()<<endl;
    // cout<<"Empty or not "<<s.empty()<<endl;

    // //Queue
    // queue<string> q;
    // q.push("Manoj");
    // q.push("Kumar");
    // q.push("Kushwaha");

    // cout<<"Size of queue "<<q.size()<<endl;
    // cout<<"First element "<<q.front()<<endl;

    // q.pop();
    // cout<<"First element "<<q.front()<<endl;
    // cout<<"Size of queue "<<q.size()<<endl;

    //  // priority_queue  min-heap max-heap
    // priority_queue<int> max; // Maxheap

    // priority_queue<int,vector<int>,greater<int>> min; //min-heap

    // // Max Heap
    // max.push(1);
    // max.push(2);
    // max.push(3);
    // max.push(4);
    // max.push(5);
    // cout<<"Empty or not "<<max.empty()<<endl;

    // cout<<endl;
    // cout<<"Max Heap"<<endl;
    // int n=max.size();
    // for(int i=0;i<n;i++) {
    //     cout<<max.top()<<" ";
    //     max.pop();
    // }
    // cout<<endl;
    // cout<<"Empty or not "<<max.empty()<<endl;

    // // Min Heap
    // min.push(5);
    // min.push(2);
    // min.push(1);
    // min.push(3);
    // min.push(4);

    // cout << endl;
    // cout << "Min Heap" << endl;
    // cout<<"Empty or not "<<min.empty()<<endl;
    // int m = min.size();
    // for (int i = 0; i < m; i++)
    // {
    //     cout << min.top() << " ";
    //     min.pop();
    // }
    // cout<<endl;
    // cout<<"Empty or not "<<min.empty()<<endl;

    // //Set
    // set<int> s;

    // s.insert(5);
    // s.insert(5);
    // s.insert(2);
    // s.insert(3);
    // s.insert(1);
    // s.insert(4);
    // s.insert(4);
    // s.insert(6);
    // s.insert(1);
    // cout << endl;
    // cout<<"Elements of set are: "<<endl;
    // cout<<"Elements before erase " << endl;
    // for (int i : s)
    // {
    //     cout << i << " ";
    // }
    // cout << endl;

    // s.erase(s.begin());
    // cout<<"Elements after erase " << endl;
    // cout<<"Elements of set are: "<<endl;
    // for (int i : s)
    // {
    //     cout << i << " ";
    // }
    // cout << endl;

    // cout<<"-5 is present or not "<<s.count(-5)<<endl;
    // cout<<"5 is present or not "<<s.count(5)<<endl;

    // s.insert(7);
    // set<int>::iterator itr=s.find(5);
    // for(auto it=itr;it!=s.end();it++) {
    //     cout<< *it <<" ";
    // }
    // cout<<endl;

    // map For ordered map-> O(log n)  unordered map-> O(1) due to use of hashtable
    cout << endl;
    // cout<<"Sorted order in ordered map"<<endl;
    // map<int,string> m;
    // m[1]="Manoj";
    // m[3]="Manish";
    // m[2]="Chandrashekar";
    // m.insert({4,"Mohit"});

    // for(auto i:m) {
    //     cout<<i.first<<" "<<i.second<<endl;
    // }
    // cout << endl;

    // cout<<"Finding 4: "<< m.count(4)<<endl;
    // cout<<"Finding -4: "<< m.count(-4)<<endl;
    // cout<<"Elements before erase using iterator: "<<endl;
    // auto it = m.find(2);
    // for (auto i = it; i != m.end(); i++)
    // {
    //     cout << (*i).first << endl;
    //     // cout << i.first << " " << i.second << endl;
    // }

    // cout<<"Before erase: "<<endl;
    // for (auto i : m)
    // {
    //     cout << i.first << " " << i.second << endl;
    // }
    // cout << endl;

    // m.erase(3); //O(log n)

    // cout<<"After erase: "<<endl;
    // for (auto i : m)
    // {
    //     cout << i.first << " " << i.second << endl;
    // }
    // cout << endl;

    // cout<<"Elements after erase using iterator: "<<endl;
    // it=m.find(2);
    // for (auto i=it;i!=m.end();i++)
    // {
    //     cout << (*i).first<< endl;
    //     // cout << i.first << " " << i.second << endl;
    // }

    // Algorithms

    vector<int> v;
    v.push_back(1);
    v.push_back(2);
    v.push_back(3);
    v.push_back(4);
    cout << "Finding 6: " << binary_search(v.begin(), v.end(), 6) << endl;
    cout << "Finding 2: " << binary_search(v.begin(), v.end(), 2) << endl;
    cout << "Lower Bound of vector: " << lower_bound(v.begin(), v.end(), 2)-v.begin() << endl;
    cout << "Upper Bound of vector: " << upper_bound(v.begin(), v.end(), 2)-v.begin()<< endl;

    int x=3;
    int y=5;
    cout<<"Max of x and y: "<<max(x,y)<<endl;
    cout<<"Min of x and y: "<<min(x,y)<<endl;
    swap(x,y);
    cout<<"x = "<<x<<endl;
    cout<<"y = "<<y<<endl;

    string s="abcd";
    reverse(s.begin(),s.end());
    cout<<s<<endl;

    rotate(v.begin(),v.begin()+1,v.end());
    cout<< "After rotate: "<<endl;
    for(int i:v) {
        cout<<i<<" ";
    }
    sort(v.begin(),v.end());
    return 0;
}