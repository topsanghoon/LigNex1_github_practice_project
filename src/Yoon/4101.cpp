#include <iostream>
using namespace std;

int main() {
    int a, b;
    while (cin >> a >> b) {
        if (a == 0 && b == 0) break;
        cout << (a > b ? "Yes" : "No") << "\n";
    }
    return 0;
}

