#include <iostream>
#include <fstream>
#include <string>
using namespace std;

int main() {
    // --- Write color.txt ---
    ofstream outFile("color.txt");
    if (!outFile) {
        cerr << "Error: Could not create color.txt" << endl;
        return 1;
    }

    outFile << "Red\n";
    outFile << "Blue\n";
    outFile << "Green\n";
    outFile << "Yellow\n";
    outFile << "Purple\n";
    outFile.close();

    // --- Read color.txt and copy to color_copy.txt ---
    ifstream inFile("color.txt");
    if (!inFile) {
        cerr << "Error: Could not open color.txt for reading" << endl;
        return 1;
    }

    ofstream copyFile("color_copy.txt");
    if (!copyFile) {
        cerr << "Error: Could not create color_copy.txt" << endl;
        return 1;
    }

    string line;
    while (getline(inFile, line)) {
        copyFile << line << "\n";
    }

    inFile.close();
    copyFile.close();

    cout << "Done! color.txt written and copied to color_copy.txt." << endl;
    return 0;
}
