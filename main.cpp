#include <iostream>
#include <ctime>
using namespace std;

const int rows = 10;
const int elements = 10;
int maxShips = 10;


int matrix[rows][elements];

void Clear()
{
    for(int i = 0; i < rows; i++)
    {
        for(int j = 0; j < elements; j++)
        {
            matrix[i][j] = 0;
        }
    }
}

void Show()
{
    for(int i = 0; i < rows; i++)
    {
        for(int j = 0; j < elements; j++)
        {
            cout << matrix[i][j] << " ";
        }
        cout << endl;
    }
}

int numShips()
{
    int c = 0;

    for(int i = 0; i < rows; i++)
    {
        for(int j = 0; j < elements; j++)
        {
            if(matrix[i][j] == 1)
                c++;
        }
    }

    return c;
}


void SetShips()
{
    int s = 0;
    while(s < maxShips)
    {
        int x = rand() % 10;
        int y = rand() % 10;
        if(matrix[x][y] != 1)
        {
            s++;
            matrix[x][y] = 1;
        }
    }
}

bool Attack(int x, int y)
{
    if(matrix[x][y] == 1)
    {
        matrix[x][y] = 2;
        return true;
    }
    else
    {
        return false;
    }
}

int main()
{
    srand(time(NULL));
    
    Clear();
    SetShips();
    int pos1,pos2;
    char prompt;

    while(1)
    {
        cout << "Please input location: "; cin >> pos1 >> pos2;
        if(Attack(pos1,pos2))
        {
            cout << "You got me!" << endl;
        }
        else
        {
            cout << "You missed!" << endl;
        }

        cout << "Number of Ships left: " << numShips() << endl;
        cout << "Do you want to surrender (y/n)?"; cin >> prompt;

        if(prompt == 'y')
        {
            break;
        }
    }

    cout << "Game Over!" << endl;
    Show();
    // system("pause");
    return 0;
}