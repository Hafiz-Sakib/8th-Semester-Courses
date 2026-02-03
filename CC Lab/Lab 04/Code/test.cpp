#include <iostream>
#include <regex>

using namespace std;

int main() {
    string input;

    // Predefined regular expression
    regex pattern("^(?=.*[0-9])(?=.*[^a-zA-Z0-9]).{6,}$");

    /*
    Condition:
    - Minimum length 6
    - At least one digit
    - At least one special character
    */

    cout << "Enter input string: ";
    cin >> input;

    if (regex_match(input, pattern))
    {
        cout << "Match Found" << endl;
    } else
    {
        cout << "No Match" << endl;
    }

    return 0;
}
