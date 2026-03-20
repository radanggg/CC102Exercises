#include <iostream>
#include <cstdlib>
using namespace std;

struct book {
    int barcode;
    string title;
    int year;
    int rating;
};

    // Ratings
    string rates(int rating) {
        if (rating == 5) return "Excellent";
        else if (rating == 4) return "Very Good";
        else if (rating == 3) return "Good";
        else if (rating == 2) return "Fair";
        else if (rating == 1) return "Poor";
        else if (rating == 0) return "No Rating";
        else return "Invalid";
    }

    // Input
    void input(book books[], int i) {
        int found = 0;
        do {
            cout << "Input Book Barcode: ";
            cin >> books[i].barcode;

            found = 0;
            for (int j = 0; j < i; j++) {
                if (books[j].barcode == books[i].barcode) {
                    found = 1;
                    cout << "Barcode already exists. Enter another barcode." << endl;
                }
            }
        } while (found == 1);
        cin.ignore();

        cout << "Input Book Title: ";
        getline(cin, books[i].title);

        cout << "Input Book Year: ";
        cin >> books[i].year;

        do {
            cout << "Input Book Rating (1-5): ";
            cin >> books[i].rating;
            cout << rates(books[i].rating) << endl;
            if (books[i].rating < 1 || books[i].rating > 5) {
                cout << "No such rating exists." << endl;
            }
        } while (books[i].rating < 1 || books[i].rating > 5);
    }

    // Display
    void display(book books[], int numBook) {
        cout << "------- BOOK TABLE -------" << endl;
        cout << "\tBarcode\tTitle\tYear\tRatings" << endl;
        for (int i = 0; i < numBook; i++) {
            cout << "Book " << i + 1 << " ";
            cout << "\t" << books[i].barcode;
            cout << "\t" << books[i].title;
            cout << "\t" << books[i].year;
            cout << "\t" << rates(books[i].rating);
            cout << endl;
        }
    }

int main() {
    char again;

    do {
        int numBook;
        cout << "Enter number of books: ";
        cin >> numBook;

        book books[numBook];
        cin.ignore();

        // Input
        for (int i = 0; i < numBook; i++) {
            cout << "Book #" << i + 1 << endl;
            input(books, i);
            cout << endl;
        }

        // Display
        display(books, numBook);

        cout << "\nDo you want to repeat? ";
        cin >> again;
        cin.ignore();
        cout << endl;
        system("cls");

    } while (again == 'y' || again == 'Y');

    return 0;
}
