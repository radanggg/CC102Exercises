#include <iostream>
#include <iomanip>
#include <cstdlib>

using namespace std;
int main (){

    int NumStud, NumQuiz, score;
    double sum, average;
    char ch;

do{
    system("cls");
    cout << "Enter number of student: ";
    cin >> NumStud;
    cout << "Enter number of quizzes per student: ";
    cin >> NumQuiz;

    //Input Scores
    int score[NumStud][NumQuiz];
    for (int i = 0; i < NumStud; i++){
        cout << "\nStudent " << i + 1 << " scores: ";
    for (int j = 0; j < NumQuiz; j++){
        cin >> score[i][j];
        }
    }

    cout <<"\nStudent ";

    //Table Header
    for (int j = 0; j < NumQuiz; j++){
        cout << "Q" << j + 1 << "   ";
    }
    cout << "Average\n";
    cout << "---------------------------------------\n";

    //Table Display and Computation of Average
    for (int i = 0; i < NumStud; i++){
        double sum = 0;

        cout << i + 1 << "       ";

    for (int j = 0; j < NumQuiz; j++){
        cout << score[i][j] << "   ";
        sum += score[i][j];
     }

    double average = sum / NumQuiz;
    cout << fixed << setprecision(2) << average << endl;
    cout << "---------------------------------------\n";
    }

    cout << "Repeat? [Y/N]";
    cin >> ch;
    }
while (ch == 'Y' || ch == 'y');

return 0;
}
