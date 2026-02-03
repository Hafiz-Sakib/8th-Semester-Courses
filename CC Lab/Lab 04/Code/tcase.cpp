#include <iostream>
#include <regex>

using namespace std;

int main() {
    int t;
    string input;

    // Predefined regular expression
    regex pattern("^(?=.*[0-9])(?=.*[^a-zA-Z0-9]).{6,}$");

    // cout << "Enter number of test cases: ";
    cin >> t;

    while (t--) {
        cout << "Enter input string: ";
        cin >> input;

        if (regex_match(input, pattern)) {
            cout << "Match Found" << endl;
        } else {
            cout << "No Match" << endl;
        }
    }

    return 0;
}
