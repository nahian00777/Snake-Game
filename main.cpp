#include <bits/stdc++.h>
#include <conio.h>
#include <windows.h>
using namespace std;

HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);

class Snake
{
public:
    enum Move
    {
        STOP = 0,
        LEFT,
        RIGHT,
        UP,
        DOWN
    };
    Move SnakeMove;
    vector<int> v;
    int Score = 0;
    int SnakeCount;
    bool GameOver;
    bool flag;
    bool PassFlag;
    const int Width = 52;
    const int Height = 22;
    int SnakeHx, SnakeHy, Fruitx, Fruity;
    int SnakeX[100], SnakeY[100];
    void GameScore();
    void DMainMenu();
    void DGameOver();
    void DInstruct();
    void DCredit();
    void Controls();
    void Setup();
    void ChooseMode();
    void PrintStage();
    void PlayStage();
    void PlayGame();
    Snake();
    void StartGame();
};

Snake::Snake()
{
    SnakeCount = 0;
    GameOver = false;
    flag = false;
    SnakeHx = 0;
    SnakeHy = 0;
    Fruitx = 0;
    Fruity = 0;
    for (int i = 0; i < 100; i++)
    {
        SnakeX[i] = 0;
        SnakeY[i] = 0;
    }
}

void Snake::DMainMenu()
{
    cout << " ===========================================================================\n";
    cout << " ||                                                                       ||\n";
    cout << " ||                           *SNAKE GAME*                                ||\n";
    cout << " ||                                                                       ||\n";
    cout << " ||                      __    __    __    __                             ||\n";
    cout << " ||                     /  \\  /  \\  /  \\  /  \\                            ||\n";
    cout << " ||____________________/  __\\/  __\\/  __\\/  __\\___________________________||\n";
    cout << " ||___________________/  /__/  /__/  /__/  /______________________________||\n";
    cout << " ||                   | / \\   / \\   / \\   / \\  \\____                      ||\n";
    cout << " ||                   |/   \\_/   \\_/   \\_/   \\    o \\                     ||\n";
    cout << " ||                                           \\_____/--<                  ||\n";
    cout << " ||                                                                       ||\n";
    cout << " ||                                                                       ||\n";
    cout << " ||                              *Main Menu*                              ||\n";
    cout << " ||									  ||\n";
    cout << " ||                         -> 1. Play Game                               ||\n";
    cout << " ||                         -> 2. Instructions                            ||\n";
    cout << " ||                         -> 3. Scores                                  ||\n";
    cout << " ||                         -> 4. Credits                                 ||\n";
    cout << " ||	                    -> 5. Exit                                    ||\n";
    cout << " ||                                                                       ||\n";
    cout << " ===========================================================================\n";
}

void Snake::DGameOver()
{
    cout << "                          Your Score is " << Score << "                     \n";
    cout << " ===========================================================================\n";
    cout << " ||                                                                       ||\n";
    cout << " ||                                                                       ||\n";
    cout << " ||                                                                       ||\n";
    cout << " ||                                                                       ||\n";
    cout << " ||                                                                       ||\n";
    cout << " ||                                                                       ||\n";
    cout << " ||           ____    _    __  __ _____ _____     _______ ____            ||\n";
    cout << " ||          / ___|  / \\  |  \\/  | ____/ _ \\ \\   / / ____|  _ \\           ||\n";
    cout << " ||         | |  _  / _ \\ | |\\/| |  _|| | | \\ \\ / /|  _| | |_) |          ||\n";
    cout << " ||         | |_| |/ ___ \\| |  | | |__| |_| |\\ V / | |___|  _ <           ||\n";
    cout << " ||          \\____/_/   \\_\\_|  |_|_____\\___/  \\_/  |_____|_| \\_\\          ||\n";
    cout << " ||                                                                       ||\n";
    cout << " ||                                                                       ||\n";
    cout << " ||                                                                       ||\n";
    cout << " ||                                                                       ||\n";
    cout << " ||                  PRESS ANY KEY TO RETURN TO MENU                      ||\n";
    cout << " ||                                                                       ||\n";
    cout << " ||                                                                       ||\n";
    cout << " ||                                                                       ||\n";
    cout << " ===========================================================================\n";
}

void Snake::DInstruct()
{

    cout << " ===========================================================================\n";
    cout << " ||                                                                       ||\n";
    cout << " ||                           *Instructions*                              ||\n";
    cout << " ||                                                                       ||\n";
    cout << " ||                                                                       ||\n";
    cout << " ||                                           ____                        ||\n";
    cout << " ||                  ________________________/ O  \\___/                   ||\n";
    cout << " ||                 <_____________________________/   \\                   ||\n";
    cout << " ||                                                                       ||\n";
    cout << " ||                                                                       ||\n";
    cout << " ||             1. W,A,S,D to change direction of the Snake.              ||\n";
    cout << " ||             2. Eat the Fruit to Make the Snake Grow. With             ||\n";
    cout << " ||                each fruit 10 Points will be Added to the              ||\n";
    cout << " ||                score.                                                 ||\n";
    cout << " ||             3. If Snake eats itself, game will be over.               ||\n";
    cout << " ||                                                                       ||\n";
    cout << " ||                                                                       ||\n";
    cout << " ||                  PRESS ANY KEY TO RETURN TO MENU                      ||\n";
    cout << " ||                                                                       ||\n";
    cout << " ||                                                                       ||\n";
    cout << " ===========================================================================\n";
}

void Snake::DCredit()
{

    cout << " ===========================================================================\n";
    cout << " ||                                                                       ||\n";
    cout << " ||                               *Credits*                               ||\n";
    cout << " ||                                                                       ||\n";
    cout << " ||                           Game Developed by                           ||\n";
    cout << " ||                                                                       ||\n";
    cout << " ||                                                                       ||\n";
    cout << " || ***    **       ***       **       **  **       ***       ***     **  ||\n";
    cout << " || ** *   **      ** **      **       **  **      ** **      ** *    **  ||\n";
    cout << " || **  *  **     **   **     ** * * * **  **     **   **     **  *   **  ||\n";
    cout << " || **   * **    ** * * **    ** * * * **  **    ** * * **    **   *  **  ||\n";
    cout << " || **    ***   ** * * * **   **       **  **   ** * * * **   **    * **  ||\n";
    cout << " || **     **  **         **  **       **  **  **         **  **     ***  ||\n";
    cout << " ||                                                                       ||\n";
    cout << " ||                                                                       ||\n";
    cout << " ||                                                                       ||\n";
    cout << " ||                                                                       ||\n";
    cout << " ||                                                                       ||\n";
    cout << " ||                    PRESS ANY KEY TO RETURN TO MENU                    ||\n";
    cout << " ||                                                                       ||\n";
    cout << " ===========================================================================\n";
}

void Snake::Setup()
{
    for (int i = 0; i < 100; i++)
    {
        SnakeX[i] = 0;
        SnakeY[i] = 0;
    }
    SnakeCount = 0;
    GameOver = false;
    SnakeMove = STOP;
    SnakeHx = Width / 2;
    SnakeHy = Height / 2;
    Fruitx = rand() % Width;
    Fruity = rand() % Height;
    Score = 0;
}

void Snake::PrintStage()
{
    system("cls");
    for (int i = 0; i < Width + 2; i++)
    {
        cout << "#";
    }
    cout << endl;
    for (int i = 0; i < Height; i++)
    {
        for (int j = 0; j < Width; j++)
        {
            if (j == 0)
            {
                cout << "#";
            }
            if (i == SnakeHy && j == SnakeHx)
            {
                cout << "O";
            }
            else if (i == Fruity && j == Fruitx)
            {
                cout << "*";
            }
            else
            {
                flag = false;
                for (int k = 0; k < SnakeCount; k++)
                {
                    if (SnakeX[k] == j && SnakeY[k] == i)
                    {
                        cout << "o";
                        flag = true;
                    }
                }
                if (!flag)
                {
                    cout << " ";
                }
            }
            if (j == Width - 1)
            {
                cout << "#";
            }
        }
        cout << "\n";
    }
    for (int i = 0; i < Width + 2; i++)
    {
        cout << "#";
    }
}

void Snake::Controls()
{
    if (_kbhit())
    {
        char c = _getch();
        if (c == 'a')
        {
            SnakeMove = LEFT;
        }
        else if (c == 'd')
        {
            SnakeMove = RIGHT;
        }
        else if (c == 'w')
        {
            SnakeMove = UP;
        }
        else if (c == 's')
        {
            SnakeMove = DOWN;
        }
        else if (c == 'D')
        {
            SnakeMove = RIGHT;
        }
        else if (c == 'W')
        {
            SnakeMove = UP;
        }
        else if (c == 'S')
        {
            SnakeMove = DOWN;
        }
        else if (c == 'A')
        {
            SnakeMove = LEFT;
        }
    }
}

void Snake::PlayStage()
{
    int prevx = SnakeX[0];
    int prevy = SnakeY[0];
    int prev2x, prev2y;
    SnakeX[0] = SnakeHx;
    SnakeY[0] = SnakeHy;
    for (int i = 1; i < SnakeCount; i++)
    {
        prev2x = SnakeX[i];
        prev2y = SnakeY[i];
        SnakeX[i] = prevx;
        SnakeY[i] = prevy;
        prevx = prev2x;
        prevy = prev2y;
    }
    if (SnakeMove == LEFT)
    {
        SnakeHx--;
    }
    else if (SnakeMove == RIGHT)
    {
        SnakeHx++;
    }
    else if (SnakeMove == UP)
    {
        SnakeHy--;
    }
    else if (SnakeMove == DOWN)
    {
        SnakeHy++;
    }
    if (PassFlag)
    {
        if (SnakeHx >= Width)
        {
            SnakeHx = 0;
        }
        else if (SnakeHx < 0)
        {
            SnakeHx = Width - 1;
        }
        if (SnakeHy >= Height)
        {
            SnakeHy = 0;
        }
        else if (SnakeHy < 0)
        {
            SnakeHy = Height - 1;
        }
    }
    else
    {
        if (SnakeHx >= Width || SnakeHx < 0 || SnakeHy >= Height || SnakeHy < 0)
        {
            v.push_back(Score);
            GameOver = true;
        }
    }
    for (int i = 0; i < SnakeCount; i++)
    {
        if (SnakeX[i] == SnakeHx && SnakeY[i] == SnakeHy)
        {
            v.push_back(Score);
            GameOver = true;
            break;
        }
    }
    if (SnakeHx == Fruitx && SnakeHy == Fruity)
    {
        Fruitx = rand() % Width;
        Fruity = rand() % Height;
        SnakeCount++;
        Score += 10;
    }
}

void Snake::PlayGame()
{
    Setup();
    while (!GameOver)
    {
        PrintStage();
        Controls();
        PlayStage();
        Sleep(100);
    }
}

void Snake::ChooseMode()
{
    system("cls");
    cout << " ===========================================================================\n";
    cout << " ||                                                                       ||\n";
    cout << " ||                           *SNAKE GAME*                                ||\n";
    cout << " ||                                                                       ||\n";
    cout << " ||                      __    __    __    __                             ||\n";
    cout << " ||                     /  \\  /  \\  /  \\  /  \\                            ||\n";
    cout << " ||____________________/  __\\/  __\\/  __\\/  __\\___________________________||\n";
    cout << " ||___________________/  /__/  /__/  /__/  /______________________________||\n";
    cout << " ||                   | / \\   / \\   / \\   / \\  \\____                      ||\n";
    cout << " ||                   |/   \\_/   \\_/   \\_/   \\    o \\                     ||\n";
    cout << " ||                                           \\_____/--<                  ||\n";
    cout << " ||                                                                       ||\n";
    cout << " ||                                                                       ||\n";
    cout << " ||                         *Selection Menu*                              ||\n";
    cout << " ||						                          ||\n";
    cout << " ||              -> 1. Snake Can Get Pass Through The Wall.               ||\n";
    cout << " ||              -> 2. Snake Can Not Get Pass Through The Wall.           ||\n";
    cout << " ||                                                                       ||\n";
    cout << " ||                                                                       ||\n";
    cout << " ||                                                                       ||\n";
    cout << " ||                                                                       ||\n";
    cout << " ===========================================================================\n";
    char c;
    c = _getch();
    if (c == '1')
    {
        PassFlag = true;
    }
    else if (c == '2')
    {
        PassFlag = false;
    }
}

void Snake::GameScore()
{
    system("cls");
    sort(v.rbegin(), v.rend());
    cout << "Rank"
         << "             "
         << "Score" << endl;
    for (int i = 0; i < v.size(); i++)
    {
        cout << i + 1 << ".                " << v[i] << endl;
    }
    cout << endl
         << endl;
    cout << "PRESS ANY KEY TO RETURN TO MENU                      \n";
}

void StartGame(Snake Sn)
{
    while (true)
    {
        char c;
        system("cls");
        Sn.DMainMenu();
        c = _getch();
        system("cls");
        if (c == '1')
        {
            Sn.ChooseMode();
            Sn.PlayGame();
            system("cls");
            Sn.DGameOver();
            _getch();
        }
        else if (c == '2')
        {
            Sn.DInstruct();
            _getch();
        }
        else if (c == '3')
        {
            Sn.GameScore();
            _getch();
        }
        else if (c == '4')
        {
            Sn.DCredit();
            _getch();
                }
        else if (c == '5')
        {
            cout << "Closing The Game..." << endl;
            Sleep(1000);
            return;
        }
    }
}

int main()
{
    SetConsoleTextAttribute(hConsole, 120);
    Snake s1;
    StartGame(s1);
    return 0;
}