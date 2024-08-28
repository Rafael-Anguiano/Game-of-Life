#include <iostream>
#include <stdlib.h>
#include <vector>

using namespace std;

void printMatrix (vector<vector<bool>> matrix, int size) {
  system("clear");
  for (int i=0; i<size; i++) {
    for (int j=0; j<size; j++) {
      if (matrix[i][j]) {
        cout << "\x1b[47m" << "\x1b[37m";
      } else {
        cout << "\x1b[44m" << "\x1b[34m";
      }
      cout << matrix[i][j] << " ";
    }
    cout <<  "\x1b[0m";
    cout << endl;
  }
}

void askCoordinates (vector<vector<bool>>& matrix) {
  int option = 0;
  do {
    int i, j;
    cout << "Enter an X and Y coordinate: ";
    cin >> j;
    cin >> i;
    matrix[i][j] = true;
    
    cout << endl;

    printMatrix(matrix, matrix.size());

    cout << endl;

    cout << "If you want to exit type 1" << endl;
    cout << "If you want to change other position type 0" << endl;
    cin >> option;
  } while (option != 1);
}

int validateNeighbours (vector<vector<bool>> matrix, int n, int i, int j) {
  int num = 0;
  if (i-1 >= 0) {
    if (j-1 >= 0 && matrix[i-1][j-1] == true) num++;
    if (matrix[i-1][j]) num++;
    if (j+1 < n && matrix[i-1][j+1]) num++;
  }
  if (i+1 < n) {
    if (j-1 >= 0 && matrix[i+1][j-1]) num++;
    if (matrix[i+1][j]) num++;
    if (j+1 < n && matrix[i+1][j+1]) num++;
  }
  if (j-1 >= 0 && matrix[i][j-1]) num++;
  if (j+1 < n && matrix[i][j+1]) num++;
  return num;
}

int main () {
  cout <<  "\x1b[0m";
  int n = 0;
  cout << "Please enter size of board: ";
  cin >> n;
  vector<bool>arr(n, false);
  vector<vector<bool>>matrix;
  vector<vector<bool>> next;
  for (int i=0; i<n; i++) {
    matrix.push_back(arr);
    next.push_back(arr);
  }

  askCoordinates(matrix);

  while (getchar() != 'e') {
    for (int i=0; i<n; i++) {
      for (int j=0; j<n; j++) {
        int num = validateNeighbours(matrix, n, i, j);
        if (matrix[i][j] && (num == 2 || num == 3)) {
          next[i][j] = true;
        } else if (matrix[i][j] == 0 && num == 3) {
          next[i][j] = true;
        } else {
          next[i][j] = false;
        }
      }
    }
    matrix = next;
    printMatrix(matrix, n);
    cout << endl;
    cout << "Enter to continue or type 'e' to exit: ";
  }


  return 0;
}
