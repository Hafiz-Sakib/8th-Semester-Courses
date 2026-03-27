#include <bits/stdc++.h>
using namespace std;

bool isKeyword(const string &word)
{
    static const vector<string> keywords = {
        "auto", "break", "case", "char", "const", "continue", "default", "do", "double",
        "else", "enum", "extern", "float", "for", "goto", "if", "int", "long", "register",
        "return", "short", "signed", "sizeof", "static", "struct", "switch", "typedef",
        "union", "unsigned", "void", "volatile", "while"};

    for (const auto &k : keywords)
        if (word == k)
            return true;

    return false;
}

bool isIgnored(const string &word)
{
    static const vector<string> ignored = {
        "include", "stdio", "iostream", "printf", "scanf",
        "cin", "cout", "endl"};

    for (const auto &w : ignored)
        if (word == w)
            return true;

    return false;
}

bool isValidIdentifier(const string &word)
{
    if (word.empty() || !(isalpha(word[0]) || word[0] == '_'))
        return false;

    for (char c : word)
        if (!(isalnum(c) || c == '_'))
            return false;

    return true;
}

string cleanToken(string word)
{
    while (!word.empty() && !(isalpha(word[0]) || word[0] == '_'))
        word.erase(word.begin());

    string cleaned;

    for (char c : word)
    {
        if (isalnum(c) || c == '_')
            cleaned += c;
        else
            break;
    }

    return cleaned;
}

int main()
{
    ifstream file("input.c");

    if (!file)
    {
        cout << "Error: Cannot open input.c\n";
        return 1;
    }

    map<string, int> frequency;
    string word;

    while (file >> word)
    {
        word = cleanToken(word);

        if (isValidIdentifier(word) &&
            !isKeyword(word) &&
            !isIgnored(word))
        {
            frequency[word]++;
        }
    }

    cout << "\nTotal Unique Identifiers : "
         << frequency.size() << "\n\n";

    cout << left << setw(20) << "Identifier"
         << "Frequency\n";
    cout << "-------------------------------------\n";

    for (const auto &entry : frequency)
    {
        cout << left << setw(20)
             << entry.first
             << entry.second << "\n";
    }

    return 0;
}
