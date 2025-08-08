#include <iostream>
#include <stack>
using namespace std;

int main() {
    string s;
    cout << "Enter brackets: ";
    cin >> s;

    stack<char> st;

    for (char c : s) {
        if (c == '(' || c == '{' || c == '[')
            st.push(c);
        else {
            if (st.empty()) { cout << "Not Balanced"; return 0; }
            if ((c == ')' && st.top() == '(') ||
                (c == '}' && st.top() == '{') ||
                (c == ']' && st.top() == '['))
                st.pop();
            else { cout << "Not Balanced"; return 0; }
        }
    }

    cout << (st.empty() ? "Balanced" : "Not Balanced");
}
