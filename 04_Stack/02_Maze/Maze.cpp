#include <iostream>
#include "../../shared/Stack.h"

using namespace std;

constexpr int kNumRows = 10;
constexpr int kNumCols = 9;

char maze[kNumRows][kNumCols] =
{
	{'1', '1', '1', '1', '1', '1', '1', '1', '1'},
	{'1', 'S', '0', '0', '0', '0', '0', '0', '1'},
	{'1', '1', '1', '1', '0', '1', '0', '1', '1'},
	{'1', '0', '0', '0', '0', '0', '0', '0', '1'},
	{'1', '0', '1', '1', '1', '1', '1', '1', '1'},
	{'1', '0', '0', '0', '0', '0', '0', '0', '1'},
	{'1', '1', '1', '1', '1', '0', '1', '1', '1'},
	{'1', '1', '1', '0', '0', '0', '1', '0', '1'},
	{'1', '0', '0', '0', '0', '0', '0', 'G', '1'}, // <- 'G'를 만나면 종료
	{'1', '1', '1', '1', '1', '1', '1', '1', '1'},
};

void PrintMaze()
{
	for (int j = 0; j < kNumRows; j++)
	{
		for (int i = 0; i < kNumCols; i++)
			cout << maze[j][i] << " ";
		cout << endl;
	}
}

struct Pos
{
    int row;
    int col;

    friend ostream& operator<<(ostream& os, const Pos& pos)
    {
		cout << "(" << pos.row << ", " << pos.col << ")" << flush;
		return os;
    }
};


int posX[4] = {0, 1, 0, -1};
int posY[4] = {1, 0, -1, 0};

void RecurMaze(Pos p)
{
    const char mark = maze[p.row][p.col];

    if (mark == 'G')
    {
        cout << "Found!" << endl;
        return ;
    }

    if (mark != '1' && mark != 'X')
    {
        maze[p.row][p.col] = 'X';
        for (int i = 0; i < 4; ++i)
        {
            RecurMaze({p.row + posX[i], p.col + posY[i]});
        }
    }
}

// 조기 종료 가능한 버전
// int RecurMaze(Pos p)
// {
//     const char mark = maze[p.row][p.col];

//     if (mark == 'G')
//     {
//         cout << "Found!" << endl;
//         return 1;
//     }

//     if (mark != '1' && mark != 'X')
//     {
//         maze[p.row][p.col] = 'X';
//         for (int i = 0; i < 4; ++i)
//         {
//             if (RecurMaze({p.row + posX[i], p.col + posY[i]})) return 1;
//         }
//     }
//     return 0;
// }

void StackMaze()
{
    Stack<Pos> s;

    // Pos start = {1, 1};
    // s.Push(start);
    s.Push({1,1});// 시작 위치

    while (!s.IsEmpty())
    {
        Pos p = s.Top();
        s.Pop();

        cout << p << " ";

        const char mark = maze[p.row][p.col];

        if (mark == 'G')
        {
            cout << "Found!" << endl;
            break;
        }

        if (mark != '1' && mark != 'X')
        {
            maze[p.row][p.col] = 'X';
            for(int i = 0; i < 4; ++i)
                s.Push({p.row + posX[i], p.col + posY[i]});
        }
    }
}

int main()
{
    PrintMaze();

    RecurMaze({1, 1});

    // StackMaze();

    PrintMaze();

    return 0;
}