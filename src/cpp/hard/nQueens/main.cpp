#include <iostream>
#include <string>
#include <vector>
#define bv2D std::vector<std::vector<bool>>
bool inCol(int N, bv2D &board, int col)
{
    for (int i = 0; i < N; i++)
        if (board[i][col]) return true;
    return false;
}
bool inRow(int N, bv2D &board, int row)
{
    for (int i = 0; i < N; i++)
        if (board[row][i]) return true;
    return false;
}
int numQueens(int N, bv2D &board)
{
    int q = 0;
    for (int i = 0; i < N; i++)
        for (int j = 0; j < N; j++)
            if (board[i][j]) q++;
    return q;
}
bool inDiag(int N, bv2D &board, int row, int col)
{
    for (int i = 0; i < N; i++)
    {
        if (row + i < N && col + i < N && board[row + i][col + i]) return true;
        if (row - i > -1 && col - i > -1 && board[row - i][col - i]) return true;
        if (row + i < N && col - i > 0 && board[row + i][col - i]) return true;
        if (row - i > -1 && col + i < N && board[row - i][col + i]) return true;
    }
    return false;
}
void printBoard(bv2D &board, int N)
{
    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < N; j++) std::cout << std::to_string(board[i][j]) << ' ';
        std::cout << '\n';
    }
}
bool checkQueens(int N, bv2D &board, int row)
{
    if (N < 2)
        return false;
    for (int i = 0; i < N; i++)
    {
        if (inRow(N, board, row) || inCol(N, board, i) || inDiag(N, board, row, i))
            continue;
        board[row][i] = true;
        if (row + 1 == N) return true;

        bool res = checkQueens(N, board, row + 1);
        if (res && numQueens(N, board) == N) return true;
        
        board[row][i] = false;
    }
    return false;
}
bv2D createBoard(int N)
{
    bv2D vec;
    for (int i = 0; i < N; i++)
    {
        std::vector<bool> v;
        for (int j = 0; j < N; j++) v.push_back(false);
        vec.push_back(v);
    }
    return vec;
}
int main(int argc, char **argv)
{
    if (argc < 2) return EXIT_FAILURE;
    int N = std::stoi(argv[1]);
    bv2D board = createBoard(N);
    bool res = checkQueens(N, board, 0);
    if (res) printBoard(board, N);
    else std::cout << "Error, could not find queen count.\n";
    return EXIT_SUCCESS;
}