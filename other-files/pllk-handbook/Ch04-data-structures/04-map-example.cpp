#include <bits/stdc++.h>
using namespace std;

int main()
{
    map<string,int> m;
    m["anurag"] = 100;
    cout << m["anurag"] << "\n";
    cout << m["tony stark"] << "\n";

    if(m.count("tony stark")) cout << "tony stark exists\n"<<"\n";
    if(m.count("peter")) cout << "peter exists\n"<<"\n";
    else cout << "peter does not exists\n"<<"\n";

    for(auto x : m) {
        cout << x.first << ": " << x.second << endl;
    }


    return 0;
}