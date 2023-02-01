// ********************************************************* 
// Course: TCP1101 PROGRAMMING FUNDAMENTALS 
// Year: Trimester 1, 2022/23 (T2215) 
// Lab: TT3L 
// Names: KHAIREL_HAFIZ_BIN_KHAIRIL_ANWAR | AHAMD_TAJUDDIN_BIN_FAUZAN 
// IDs: 1221303651 | 1221303628 
// Emails: 1221303651@STUDENT.MMU.EDU.MY | 1221303628@STUDENT.MMU.EDU.MY 
// Phones: 0177050683 | 0126290244 
// ********************************************************* 

// TODO: Fill in the missing information above and delete this line.

#include <iostream>
#include <ctime>
#include <iomanip>
#include <vector>
using namespace std;

vector< vector<char> > map;

void init(int colx, int rowy,int playerRow,int playerCol,char A)
{
    char objects[] = {' ',' ',' ',' ', ' ', ' ', ' ', ' ', ' ', '^', 'v', '>', '<','h','p','r'};
    int noOfObjects = 16;

    map.resize(rowy);
    for (int i = 0;i < rowy; ++i)
    {
        map[i].resize(colx);
    }

    for (int i = 0; i < rowy; ++i)
    {
        for (int j = 0; j < colx; ++j)
        {
            int objNo = rand() % noOfObjects;
            map[i][j] = objects[objNo];
        }
    }
    map[playerRow][playerCol] = A;
}

void display(int colx, int rowy)
{
    cout << " --__--__--__--__--__--__--__--_" << endl;
    cout << "         ALIEN VS ZOMBIE       =" << endl;
    cout << " __--__--__--__--__--__--__--__-" << endl;

    for (int i = 0; i < rowy; ++i)
    {
        // display upper border of the row
        cout << "  ";
        for (int j = 0; j < colx; ++j)
        {
            cout << "+-";
        }
        cout << "+" << endl;
        // display row number
        cout << setw(2) << (i + 1);
        // display cell content and border of each column
        for (int j = 0; j < colx; ++j)
        {
            cout << "|" << map[i][j];
        }
        cout << "|" << endl;
    }
    cout << "  ";
    for (int j = 0; j < colx; ++j)
    {
        cout << "+-";
    }
    cout << "+" << endl;
    // display column number
    cout << "  ";
    for (int j = 0; j < colx; ++j)
    {
        int digit = (j + 1) / 10;
        cout << " ";
        if (digit == 0)
            cout << " ";
        else
            cout << digit;
    }
    cout << endl;
    cout << "  ";
    for (int j = 0; j < colx; ++j)
    {
        cout << " " << (j + 1) % 10;
    }
    cout << endl
         << endl;
}

void askrowcol(int& colx,int& rowy)
{
    cout << "Enter number of column : ";
    cin >> colx;

    cout << "Enter number of row : ";
    cin >> rowy;
}

void menu()
{
    int choice;
    do
    {

        cout << "0. Play\n1. Settings\n2. Credits\n3. Exit" << endl;
        cout << "Select number: ";
        cin >> choice;
        switch (choice)
        {

        case 0:
            cout << endl;
            cout << "Welcome to Alien vs Zombie" <<endl << endl;
            break;
        case 1:
            cout << "Your in settings now" << endl;
            break;
        case 2:
            cout << "By Khairel and Tajuddin" << endl;
            break;
        case 3:
            cout << "Thank you for playing" << endl;
            break;
        }

    } while (choice != 0);
}

int main()
{
    int colx, rowy;

    menu();
    askrowcol(colx, rowy);

    int playerRow = rowy / 2;
    int playerCol = colx / 2;

    char move, A = 'A';
    int x = 0, k = 2, y = 7;
    srand(time(NULL));
    init(colx, rowy, playerRow, playerCol, A);
    display(colx, rowy);

    while (x == 0)
    {
        cout << "Enter a move (w = up, s = down, a = left, d = right, q = quit): " << endl;
        cout << "Alien movement: ";
        cin >> move;
        if (move == 'w')
        {
            map[playerRow][playerCol] = '*';
            playerRow = playerRow - 1;
            map[playerRow][playerCol] = A;
            display(colx, rowy);
        }

        if (move == 's')
        {
            map[playerRow][playerCol] = '*';
            playerRow = playerRow + 1;
            map[playerRow][playerCol] = A;
            display(colx, rowy);
        }

        if (move == 'd')
        {
            map[playerRow][playerCol] = '*';
            playerCol = playerCol + 1;
            map[playerRow][playerCol] = A;
            display(colx, rowy);
        }

        if (move == 'a')
        {
            map[playerRow][playerCol] = '*';
            playerCol = playerCol - 1;
            map[playerRow][playerCol] = A;
            display(colx, rowy);
            // map[k][y + 1] = ' ';
        }

        if (move == 'q')
        {
            break;
        }
    }
}
