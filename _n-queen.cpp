#include <iostream>
using namespace std;

| Metric               | Complexity        | Explanation                                                                                        |
| -------------------- | ----------------- | -------------------------------------------------------------------------------------------------- |
| **Time Complexity**  | O(N!)             | Each queen has up to N choices; backtracking reduces many cases, but worst case remains factorial. |
| **Space Complexity** | O(N²)** or O(N)** | O(N²) if using board matrix; can be optimized to O(N) using arrays for column/diagonal checks.     |



#define N 8 // You can change this value to test for different board sizes

// Function to print the chessboard
void printBoard(int board[N][N])
{
  for (int i = 0; i < N; i++)
  {
    for (int j = 0; j < N; j++)
      cout << (board[i][j] ? "Q " : ". ");
    cout << endl;
  }
  cout << endl;
}

// Check if placing a queen at board[row][col] is safe
bool isSafe(int board[N][N], int row, int col)
{
  int i, j;

  // Check this row on left side
  for (i = 0; i < col; i++)
    if (board[row][i])
      return false;

  // Check upper diagonal on left side
  for (i = row, j = col; i >= 0 && j >= 0; i--, j--)
    if (board[i][j])
      return false;

  // Check lower diagonal on left side
  for (i = row, j = col; j >= 0 && i < N; i++, j--)
    if (board[i][j])
      return false;

  return true;
}

// Recursive utility function to solve N-Queens
bool solveNQueens(int board[N][N], int col)
{
  // Base case: All queens placed
  if (col >= N)
    return true;

  // Try placing this queen in all rows
  for (int i = 0; i < N; i++)
  {
    if (isSafe(board, i, col))
    {
      board[i][col] = 1; // Place queen

      // Recur to place rest of the queens
      if (solveNQueens(board, col + 1))
        return true;

      // Backtrack if placing queen here doesn't lead to a solution
      board[i][col] = 0;
    }
  }

  return false; // No place is safe in this column
}

// Driver function
int main()
{
  int board[N][N] = {0};

  if (!solveNQueens(board, 0))
    cout << "No solution exists.";
  else
    printBoard(board);

  return 0;
}
