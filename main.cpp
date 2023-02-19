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

struct CharAttr
{
    int row;
    int column;
    int health;
    int attack;
    int ranges;
};



/*int alienHealth = 0;
int alienAttack = 0;*/
int zombie = 2;
int zombieHealth = 250;
int zombieAttack = 5;
char A = 'A';
char EMPTY = ' ';
char test = 'T';

void arrow(vector<vector<char>> &map, int row, int col, CharAttr alien, int playerCol, int playerRow, char move, char A);
void moveup(vector<vector<char>> &map, CharAttr &alien, int &playerCol, int &playerRow, int col, int row, char move);
void movedown(vector<vector<char>> &map, CharAttr &alien, int &playerCol, int &playerRow, int col, int row, char move);
void moveright(vector<vector<char>> &map, CharAttr &alien, int &playerCol, int &playerRow, int col, int row, char move);
void moveleft(vector<vector<char>> &map, CharAttr &alien, int &playerCol, int &playerRow, int col, int row, char move);
void command(vector<vector<char>> &map, CharAttr alien, int playerCol, int playerRow, int col, int row, char move, char A);

void setItem(vector<vector<char>> &map, int &row, int &col, char character)
{
    map[row][col] = character;
    // map[2][3] = 'r';
}

void setItemrock(vector<vector<char>> map, int row, int col, char random)
{
    map[0][0] = test;
    map[row - 1][col] = test;
}

char getItem(vector<vector<char>> map, int row, int col)
{
    return map[row][col];
}

void init(vector<vector<char>> &map, int col, int row, int playerRow, int playerCol, char A)
{
    char objects[] = {' ', ' ', ' ', ' ', ' ', '^', 'v', '>', '<', 'h', 'p', 'r'};
    int noOfObjects = 12;

    map.resize(row);
    for (int i = 0; i < row; ++i)
    {
        map[i].resize(col);
    }

    for (int i = 0; i < row; ++i)
    {
        for (int j = 0; j < col; ++j)
        {
            int objNo = rand() % noOfObjects;
            map[i][j] = objects[objNo];
        }
    }
    setItem(map, playerRow, playerCol, A);

}

void initZombie() {

}

void replacetrail(vector<vector<char>> &map, int row, int col)
{
    char objects[] = {' ', ' ', ' ', ' ', ' ', '^', 'v', '>', '<', 'h', 'p', 'r'};
    int noOfObjects = 12;

    for (int i = 0; i < row; ++i)
    {
        for (int j = 0; j < col; ++j)
        {
            if (getItem(map, i, j) == '*')
            {
                int objNo = rand() % noOfObjects;
                map[i][j] = objects[objNo];
            }
        }
    }
}
void display(vector<vector<char>> &map, CharAttr alien, int col, int row)
{
    cout << " --__--__--__--__--__--__--__--_" << endl;
    cout << "         ALIEN VS ZOMBIE       =" << endl;
    cout << " __--__--__--__--__--__--__--__-" << endl;

    for (int i = 0; i < row; ++i)
    {
        // display upper border of the row
        cout << "  ";
        for (int j = 0; j < col; ++j)
        {
            cout << "+-";
        }
        cout << "+" << endl;
        // display row number
        cout << setw(2) << (i);
        // display cell content and border of each column
        for (int j = 0; j < col; ++j)
        {
            cout << "|" << map[i][j];
        }
        cout << "|" << endl;
    }
    cout << "  ";
    for (int j = 0; j < col; ++j)
    {
        cout << "+-";
    }
    cout << "+" << endl;
    // display column number
    cout << "  ";
    for (int j = 0; j < col; ++j)
    {
        int digit = (j) / 10;
        cout << " ";
        if (digit == 0)
            cout << " ";
        else
            cout << digit;
    }
    cout << endl;
    cout << "  ";
    for (int j = 0; j < col; ++j)
    {
        cout << " " << (j) % 10;
    }
    cout << endl
         << endl;

    cout << "->"
         << " Alien     :"
         << "Life  " << alien.health << "  ,"
         << " Attack  " << alien.attack << endl;
    for (int i = 0; i < zombie; i++)
    {
        cout << "   "
             << "Zombie " << i + 1 << "  :"
             << "Life  " << zombieHealth << ", "
             << "Attack  1" << endl;
    }
}

void askrowcol(int &col, int &row)
{
    do
    {
        cout << "Enter number of column : ";
        cin >> col;
        if (col % 2 == 0)
        {
            cout << "The column must be in odd number" << endl;
            continue;
        }

        else
        {
            break;
        }
    } while (true);

    do
    {
        cout << "Enter number of row : ";
        cin >> row;

        if (row % 2 == 0)
        {
            cout << "The row must be in odd number" << endl;
            continue;
        }

        else
        {
            break;
        }
    } while (true);
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
            cout << "Welcome to Alien vs Zombie" << endl
                 << endl;
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

void alienhitborder()
{
    cout << "Alien hit border" << endl;
}

/*int healthindicator(CharAttr& alien)
{
    return (100 - alien.health );
}*/

void healthpod(CharAttr &alien)
{
    if (alien.health <= 80)
    {
        cout << "Alien finds a health pack." << endl;
        cout << "Alien's life is increased by 20 ." << endl;
        alien.health += 20; // healthindicator(alien);
        cout << "Your alien health is " << alien.health << endl;
    }
    else if (alien.health > 80)
    {
        int z = 100 - alien.health;
        for (int i = 1; alien.health < 100; ++i)
        {
            alien.health += 1;
        }
        cout << "Alien finds a health pack." << endl;
        cout << "Alien's life is increased by " << z << endl;
        cout << "Alien's life is maxed." << endl;
    }
}

void hitrock()
{

    cout << "Alien hit the rock" << endl;
}

void moveup(vector<vector<char>> &map, CharAttr &alien, int &playerCol, int &playerRow, int col, int row, char move)
{
    do
    {
        if (playerRow == 0)
        {
            map[playerRow][playerCol] = 'A';
            alienhitborder();
            display(map, alien, col, row);
            break;
        }

        if (getItem(map, playerRow - 1, playerCol) == 'r')
        {
            hitrock();
            setItemrock(map, playerRow - 1, playerCol, test);
            break;
        }

        if (getItem(map, playerRow - 1, playerCol) == 'h')
        {
            healthpod(alien);
        }

        if (getItem(map, playerRow - 1, playerCol) == '^')
        {
            map[playerRow][playerCol] = '*';
            playerRow = playerRow - 1;
            moveup(map, alien, playerCol, playerRow, col, row, move);
            break;
        }

        if (getItem(map, playerRow - 1, playerCol) == 'v')
        {
            map[playerRow][playerCol] = '*';
            playerRow = playerRow - 1;
            movedown(map, alien, playerCol, playerRow, col, row, move);
            break;
        }

        if (getItem(map, playerRow - 1, playerCol) == '>')
        {
            map[playerRow][playerCol] = '*';
            playerRow = playerRow - 1;
            moveright(map, alien, playerCol, playerRow, col, row, move);
            break;
        }

        if (getItem(map, playerRow - 1, playerCol) == '<')
        {
            map[playerRow][playerCol] = '*';
            playerRow = playerRow - 1;
            moveleft(map, alien, playerCol, playerRow, col, row, move);
            break;
        }

        if (playerRow > 0)
        {
            map[playerRow][playerCol] = '*';
            playerRow = playerRow - 1;
            map[playerRow][playerCol] = A;
            display(map, alien, col, row);
        }
        system("pause");

    } while (true);
    replacetrail(map, row, col);
    display(map, alien, col, row);
    command(map, alien, playerCol, playerRow, col, row, move, A);
}

void movedown(vector<vector<char>> &map, CharAttr &alien, int &playerCol, int &playerRow, int col, int row, char move)
{
    do
    {
        if (playerRow == (row - 1))
        {
            map[playerRow][playerCol] = 'A';
            alienhitborder();
            display(map, alien, col, row);
            break;
        }

        if (getItem(map, playerRow + 1, playerCol) == 'r')
        {
            hitrock();
            break;
        }

        if (getItem(map, playerRow + 1, playerCol) == 'h')
        {
            healthpod(alien);
        }

        if (getItem(map, playerRow + 1, playerCol) == '^')
        {
            map[playerRow][playerCol] = '*';
            playerRow = playerRow + 1;
            moveup(map, alien, playerCol, playerRow, col, row, move);
            break;
        }

        if (getItem(map, playerRow + 1, playerCol) == 'v')
        {
            map[playerRow][playerCol] = '*';
            playerRow = playerRow + 1;
            movedown(map, alien, playerCol, playerRow, col, row, move);
            break;
        }

        if (getItem(map, playerRow + 1, playerCol) == '>')
        {
            map[playerRow][playerCol] = '*';
            playerRow = playerRow + 1;
            moveright(map, alien, playerCol, playerRow, col, row, move);
            break;
        }

        if (getItem(map, playerRow + 1, playerCol) == '<')
        {
            map[playerRow][playerCol] = '*';
            playerRow = playerRow + 1;
            moveleft(map, alien, playerCol, playerRow, col, row, move);
            break;
        }

        if (playerRow < (row - 1))
        {
            map[playerRow][playerCol] = '*';
            playerRow = playerRow + 1;
            map[playerRow][playerCol] = A;
            display(map, alien, col, row);
        }
        system("pause");

    } while (true);
    replacetrail(map, row, col);
    display(map, alien, col, row);
    command(map, alien, playerCol, playerRow, col, row, move, A);
}

void moveright(vector<vector<char>> &map, CharAttr &alien, int &playerCol, int &playerRow, int col, int row, char move)
{
    do
    {

        if (playerCol == (col - 1))
        {
            map[playerRow][playerCol] = 'A';
            alienhitborder();
            display(map, alien, col, row);
            break;
        }

        if (getItem(map, playerRow, playerCol + 1) == 'r')
        {
            hitrock();
            break;
        }

        if (getItem(map, playerRow, playerCol + 1) == 'h')
        {
            healthpod(alien);
        }

        if (getItem(map, playerRow, playerCol + 1) == '^')
        {
            map[playerRow][playerCol] = '*';
            playerCol = playerCol + 1;
            moveup(map, alien, playerCol, playerRow, col, row, move);
            break;
        }

        if (getItem(map, playerRow, playerCol + 1) == 'v')
        {
            map[playerRow][playerCol] = '*';
            playerCol = playerCol + 1;
            movedown(map, alien, playerCol, playerRow, col, row, move);
            break;
        }

        if (getItem(map, playerRow, playerCol + 1) == '>')
        {
            map[playerRow][playerCol] = '*';
            playerCol = playerCol + 1;
            moveright(map, alien, playerCol, playerRow, col, row, move);
            break;
        }

        if (getItem(map, playerRow, playerCol + 1) == '<')
        {
            map[playerRow][playerCol] = '*';
            playerCol = playerCol + 1;
            ;
            moveleft(map, alien, playerCol, playerRow, col, row, move);
            break;
        }

        if (playerCol < (col - 1))
        {
            map[playerRow][playerCol] = '*';
            playerCol = playerCol + 1;
            map[playerRow][playerCol] = A;
            display(map, alien, col, row);
        }
        system("pause");

    } while (true);
    replacetrail(map, row, col);
    display(map, alien, col, row);
    command(map, alien, playerCol, playerRow, col, row, move, A);
}

void moveleft(vector<vector<char>> &map, CharAttr &alien, int &playerCol, int &playerRow, int col, int row, char move)
{
    do
    {

        if (playerCol == 0)
        {
            map[playerRow][playerCol] = 'A';
            alienhitborder();
            display(map, alien, col, row);
            break;
        }

        if (getItem(map, playerRow, playerCol - 1) == 'r')
        {
            hitrock();
            break;
        }

        if (getItem(map, playerRow, playerCol - 1) == 'h')
        {
            healthpod(alien);
        }

        if (getItem(map, playerRow, playerCol - 1) == '^')
        {
            map[playerRow][playerCol] = '*';
            playerCol = playerCol - 1;
            moveup(map, alien, playerCol, playerRow, col, row, move);
            break;
        }

        if (getItem(map, playerRow, playerCol - 1) == 'v')
        {
            map[playerRow][playerCol] = '*';
            playerCol = playerCol - 1;
            movedown(map, alien, playerCol, playerRow, col, row, move);
            break;
        }

        if (getItem(map, playerRow, playerCol - 1) == '>')
        {
            map[playerRow][playerCol] = '*';
            playerCol = playerCol - 1;
            moveright(map, alien, playerCol, playerRow, col, row, move);
            break;
        }

        if (getItem(map, playerRow, playerCol - 1) == '<')
        {
            map[playerRow][playerCol] = '*';
            playerCol = playerCol - 1;
            moveleft(map, alien, playerCol, playerRow, col, row, move);
            break;
        }

        if (playerCol > 0)
        {
            map[playerRow][playerCol] = '*';
            playerCol = playerCol - 1;
            map[playerRow][playerCol] = A;
            display(map, alien, col, row);
        }
        system("pause");
    } while (true);
    replacetrail(map, row, col);
    display(map, alien, col, row);
    command(map, alien, playerCol, playerRow, col, row, move, A);

    // map[k][y + 1] = ' ';
}

void zombiemove(vector<vector<char>> &map, int zombierow, int zombiecol)
{
    int nextrow = zombierow;
    int nextcol = zombiecol; 
    int zombie_pos = rand() % 3;
    if (zombie_pos == 0)
    {
        zombierow--;
        map[zombierow][zombiecol] = 'z';
    }
    else if (zombie_pos == 1)
    {
        zombierow++;
                map[zombierow][zombiecol] = 'z';

    }
    else if(zombie_pos == 2)
    {
        zombiecol++;
                map[zombierow][zombiecol] = 'z';

    }
    else if(zombie_pos == 3)
    {
        zombiecol--;
                map[zombierow][zombiecol] = 'z';

    }
}

void alienmove(vector<vector<char>> &map, CharAttr alien, int playerCol, int playerRow, int col, int row, char move, char A)
{

    cout << "Enter a move (w = up, s = down, a = left, d = right, q = quit): " << endl;
    cout << "Alien movement: ";
    cin >> move;

    if (move == 'w')
    {
        moveup(map, alien, playerCol, playerRow, col, row, move);
    }

    if (move == 's')
    {
        movedown(map, alien, playerCol, playerRow, col, row, move);
    }

    if (move == 'd')
    {
        moveright(map, alien, playerCol, playerRow, col, row, move);
    }

    if (move == 'a')
    {
        moveleft(map, alien, playerCol, playerRow, col, row, move);
    }

    if (move == 'q')
    {
        system("exit");
    }
    else
    {
        display(map, alien, col, row);
        command(map, alien, playerCol, playerRow, col, row, move, A);

    }
}

void command(vector<vector<char>> &map, CharAttr alien, int playerCol, int playerRow, int col, int row, char move, char A)
{
    string comand;
    cout << "command > ";
    cin >> comand;
    if (comand == "move")
    {

        alienmove(map, alien, playerCol, playerRow, col, row, move, A);
    }
    else if (comand == "arrow")
    {
        arrow(map, row, col, alien, playerCol, playerRow, move, A);
    }
    else if (comand == "help")
    {
        cout << "Command:" << endl;
        cout << endl;
        cout << "Move up - w" << endl;
        cout << "Move down - s" << endl;
        cout << "Move left - a" << endl;
        cout << "Move right - d" << endl;
        system("pause");
        display(map, alien, col, row);
        command(map, alien, playerCol, playerRow, col, row, move, A);
    }
    else if (comand == "quit")
    {
        system("exit");
    }
    else
    {
        display(map, alien, col, row);
        command(map, alien, playerCol, playerRow, col, row, move, A);
    }

}

void arrow(vector<vector<char>> &map, int row, int col, CharAttr alien, int playerCol, int playerRow, char move, char A)
{
    int arrow_row;
    int arrow_col;

    cout << "Choose arrow you want to change " << endl;

    cout << "Row : ";
    cin >> arrow_row;
    cout << "Column : ";
    cin >> arrow_col;
    cout << endl;

    if (getItem(map, arrow_row, arrow_col) == '^' || getItem(map, arrow_row, arrow_col) == 'v' || getItem(map, arrow_row, arrow_col) == '<' || getItem(map, arrow_row, arrow_col) == '>')
    {
        string command;
        cout << "Enter a command (alien movement = move, change arrow = arrow , manual book = help ,exit = quit): " << endl;
        cout << "Which direction : ";
        cin >> command;
        if (command == "up")
        {
            setItem(map, arrow_row, arrow_col, '^');
        }
        else if (command == "down")
        {
            setItem(map, arrow_row, arrow_col, 'v');
        }
        else if (command == "left")
        {
            setItem(map, arrow_row, arrow_col, '<');
        }
        else if (command == "right")
        {
            setItem(map, arrow_row, arrow_col, '>');
        }
    }
    else
    {
        cout << "Change arrow only" << endl;
    }
    display(map, alien, col, row);
    command(map, alien, playerCol, playerRow, col, row, move, A);
}

int main()
{
    vector<vector<char>> map;
    CharAttr alien;
    int col, row, zombie;
    askrowcol(col, row);
    int zombieRow = rand() % row;
    int zombieCol = rand() % col;
    int zombieRow2 = rand() % row;
    int zombieCol2 = rand() % col;
    int playerRow = row / 2;
    int playerCol = col / 2;
    alien.health = 100;
    alien.attack = rand() % 50 + 20; // if rand dpt 0, at least ad 20 attack

   // setItem(map, zombieRow, zombieCol, '1');

    char move, A = 'A';

    srand(time(NULL));
    init(map, col, row, playerRow, playerCol, A);
    setItem(map, zombieRow, zombieCol, '1');
    setItem(map, zombieRow2, zombieCol2, '2');
    display(map, alien, col, row);
    command(map, alien, playerCol, playerRow, col, row, move, A);
}
