#include <iostream>
#include <regex.h>

using namespace std;

int main() {
    regex_t regex;
    char S[100];   // Input string
    int result;

    // Predefined regular expression
    char R[] = "^(?=.*[0-9])(?=.*[^a-zA-Z0-9]).{6,}$";
    /*
    Regex Condition Explanation:

    ^                  -> Start of the string
    (?=.*[0-9])        -> Must contain at least one digit
    (?=.*[^a-zA-Z0-9]) -> Must contain at least one special character
    .{6,}              -> Minimum length of the string should be 6 characters
    $                  -> End of the string

    Overall Condition:
    The input string must be at least 6 characters long,
    contain at least one digit,
    and contain at least one special symbol.
    */

    // Read input string
    cout << "Enter input string: ";
    cin >> S;

    // Compile the regular expression
    result = regcomp(&regex, R, REG_EXTENDED);
    if (result != 0) {
        cout << "Regex compilation failed" << endl;
        return 1;
    }

    // Match input string with predefined regex
    result = regexec(&regex, S, 0, NULL, 0);

    if (result == 0) {
        cout << "Match Found" << endl;
    } else {
        cout << "No Match" << endl;
    }

    // Free allocated memory
    regfree(&regex);

    return 0;
}
