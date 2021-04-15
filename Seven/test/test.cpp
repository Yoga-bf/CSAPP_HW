#include <iostream>
#include <string>
#include <vector>
using namespace std;
void f(void);

int y = 100;
int x = 200;

int main()
{
    vector<string> v;
    v.push_back("Hello, ");
    string &x = v[0];
    v.push_back(" world!");
    cout << x << endl;
}