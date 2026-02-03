#include <iostream>
#include <regex>
using namespace std;

int main() {
    int t;
    string pattern, str;

    // Read number of test cases
    cout << "Enter number of test cases: ";
    cin >> t;

    while (t--) {
        // Read regex pattern
        cout << "Enter regular expression: ";
        cin >> pattern;

        // Read input string
        cout << "Enter string to match: ";
        cin >> str;

        // Create regex object
        regex r(pattern);

        // Match string with regex
        if (regex_match(str, r)) {
            cout << "Match Found" << endl;
        } else {
            cout << "No Match" << endl;
        }
    }

    return 0;
}
