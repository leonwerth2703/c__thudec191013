#include <bits/stdc++.h>
using namespace std;

string addBigNumbers(const string& num1, const string& num2) {
    const string n1(num1.rbegin(), num1.rend());
    const string n2(num2.rbegin(), num2.rend());

    int carry = 0;
    string result;

    for (int i = 0; i < max(n1.size(), n2.size()); i++) {
        const int digit1 = (i < n1.size()) ? (n1[i] - '0') : 0;
        const int digit2 = (i < n2.size()) ? (n2[i] - '0') : 0;

        const int sum = digit1 + digit2 + carry;
        carry = sum / 10;
        result.push_back((sum % 10) + '0');
    }

    if (carry != 0) {
        result.push_back(carry + '0');
    }

    reverse(result.begin(), result.end());
    return result;
}

int main() {
    const string num1 = "55";
    const string num2 = "30";
    cout << addBigNumbers(num1, num2) << endl;
    return 0;
}
