#include <iostream>
#include <fstream>
#include <string>

using namespace std;

int main() {
    string filename;
    string word;
    cout << "Enter filename: ";
    cin >> filename;
    cout << "Enter word: ";
    cin >> word;
    ifstream infile(filename);
    if (!infile) {
        cerr << "Error opening file" << endl;
        return 1;
    }
    int count = 0;
    string line;
    while (getline(infile, line)) {
        size_t pos = 0;
        while ((pos = line.find(word, pos)) != string::npos) {
            count++;
            pos += word.length();
        }
    }
    infile.close();
    cout << "The word \"" << word << "\" occurs " << count << " times in the file." << endl;
    return 0;
}
