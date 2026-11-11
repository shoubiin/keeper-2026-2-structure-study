#include <functional>
#include <iostream>
#include <set>
#include <string>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int recordCount;
    cin >> recordCount;
    set<string, greater<string>> inOffice;
    while (recordCount--) {
        string name, action;
        cin >> name >> action;
        if (action == "enter") inOffice.insert(name);
        else inOffice.erase(name);
    }

    for (const string& name : inOffice) cout << name << '\n';
    return 0;
}
