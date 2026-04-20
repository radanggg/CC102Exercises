#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

int main() {

    ofstream outFile("original.txt");
    if (!outFile) {
        cerr << "Error: Could not create original.txt" << endl;
        return 1;
    }

    outFile << "One\n";
    outFile << "Two\n";
    outFile << "Three\n";
    outFile << "Four\n";
    outFile << "Five\n";
    outFile << "Six\n";
    outFile.close();

    ifstream inFile("original.txt");
    if (!inFile) {
        cerr << "Error: Could not open original.txt" << endl;
        return 1;
    }

    vector<string> words;
    string line;
    while (getline(inFile, line)) {
        words.push_back(line);
    }
    inFile.close();

    sort(words.begin(), words.end());

    ofstream sortedFile("sorted.txt");
    if (!sortedFile) {
        cerr << "Error: Could not create sorted.txt" << endl;
        return 1;
    }

    for (const string& word : words) {
        sortedFile << word << "\n";
    }
    sortedFile.close();

    cout << "Done! original.txt written and sorted into sorted.txt" << endl;
    return 0;
}
