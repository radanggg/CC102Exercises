    #include <iostream>
    #include <cstdlib>
    using namespace std;

    struct book{
        int barcode;
        string title;
        int year;
        int rating;

        //For rates
        string rates(){
            if (rating == 5) return "Excellent";
            else if (rating == 4) return "Very Good";
            else if (rating == 3) return "Good";
            else if (rating == 2) return "Fair";
            else if (rating == 1) return "Poor";
            else if (rating == 0) return "No Rating";
            else return "Invalid";
            }

        //For input
        void input(book books[], int i){
            int found = 0;
            do {
                cout << "Input Book Barcode: ";
                cin >> barcode;

                found = 0;
                    for (int j=0; j < i; j++){
                        if (books[j].barcode == barcode){
                            found = 1;
                            cout << "Barcode is already exist, Enter another barcode." << endl;
                            }
                        }
                    }while (found == 1);
            cin.ignore();

            cout << "Input Book Title: ";
            getline(cin, title);

            cout << "Input Book Year: ";
            cin >> year;

            do{
            cout << "Input Book Rating (1-5): ";
                cin >> rating;
            cout << rates();
                if(rating < 1 || rating > 5){
                    cout << "No such rating exist" << endl;
                }
            }while(rating < 1 || rating > 5);
        }

        //For output
        void display(){
            cout << "\t" << barcode;
            cout << "\t" << title;
            cout << "\t" << year;
            cout << "\t" << rates();
        }

    };

    int main(){
        char again;

        //For loop
        do{
            int numBook;
            cout << "Enter number of books: ";
            cin >> numBook;
            book books[numBook];
            cin.ignore();

            //Book Input
            for(int i=0; i < numBook; i++){
                cout << "Book #" << i+1 << endl;
                books[i].input(books, i);
                cout << endl;
            }

            //BOok Display Table
            cout << "------- BOOK TABLE ------ " << endl;
            cout << "\tBarcode\tTitle\tYear\tRatings" << endl;
            for (int i=0; i < numBook; i++){
                    cout << "Book " << i+1 << " ";
                    books[i].display();
                    cout << endl;
                }
            cout << "\nDo you want to repeat? ";
            cin >> again;
            cin.ignore();
            cout << endl;
            system("cls");

        }while (again == 'y' || again =='Y');

    return 0;
    }
