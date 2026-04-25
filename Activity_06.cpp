#include <iostream>
#include <fstream>
using namespace std;

bool isPrime(int n) {
    if (n < 2) return false;
    if (n == 2) return true;
    if (n % 2 == 0) return false;
    for (int i = 3; i * i <= n; i += 2)
        if (n % i == 0) return false;
    return true;
}

int main() {
    int num;
    int primeCount = 0;

    ifstream numbers("NUMS.txt");
    if (!numbers) {
        cerr << "File could not open!" << endl;
        return 1;
    }
    if (numbers.is_open()) {
        cout << "NOTICE: FILE WAS SUCCESSFULLY OPEN!" << endl;
    }

    while (numbers >> num) {
        if (isPrime(num))
            primeCount++;
    }

    numbers.close();
    cout << "Prime count: " << primeCount << endl;
    return 0;
}
