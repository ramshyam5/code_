#include <iostream>
#include <fstream>
#include <cctype>

using namespace std;

int main() {
    string filename;
    ifstream infile(filename);
    if (!infile) {
        cerr << "Error opening file" << endl;
        return 1;
    }
    int digit_count = 0, alphabet_count = 0, space_count = 0;
    char c;
    while (infile.get(c)) {
        if (isdigit(c)) {
            digit_count++;
        } else if (isalpha(c)) {
            alphabet_count++;
        } else if (isspace(c)) {
            space_count++;
        }
    }
    infile.close();
    cout << "Digits: " << digit_count << endl;
    cout << "Alphabets: " << alphabet_count << endl;
    cout << "Spaces: " << space_count << endl;
    return 0;
}
