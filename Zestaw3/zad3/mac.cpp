#include <fstream>
#include <iostream>

using namespace std;

const int MAX_SIZE = 100;

void read_matrix(const string &filename, double matrix[MAX_SIZE][MAX_SIZE], int &rows, int &cols) {
  ifstream file(filename);
  if (!file.is_open()) {
    cerr << "Nie udalo sie otworzyc pliku: " << filename << endl;
    exit(1);
  }

  rows = 0;
  string line;
  while (getline(file, line)) {
    int cols_count = 0;
    double value = 0.0;
    int i = 0;
    for (char c : line) {
      if (c == ' ') {
        matrix[rows][cols_count++] = value;
        value = 0.0;
      } else {
        value = value * 10.0 + (c - '0');
      }
    }
    matrix[rows][cols_count++] = value;
    cols = max(cols, cols_count);
    rows++;
  }

  file.close();
}

void write_matrix(const string &filename, double matrix[MAX_SIZE][MAX_SIZE], int rows, int cols) {
  ofstream file(filename);
  if (!file.is_open()) {
    cerr << "Nie udalo sie otworzyc pliku: " << filename << endl;
    exit(1);
  }

  for (int i = 0; i < rows; ++i) {
    for (int j = 0; j < cols; ++j) {
      file << matrix[i][j] << " ";
    }
    file << endl;
  }

  file.close();
}

void multiply_matrices(double matrix1[MAX_SIZE][MAX_SIZE], int rows1, int cols1, double matrix2[MAX_SIZE][MAX_SIZE], int rows2, int cols2, double result[MAX_SIZE][MAX_SIZE]) {
  for (int i = 0; i < rows1; ++i) {
    for (int j = 0; j < cols2; ++j) {
      double sum = 0.0;
      for (int k = 0; k < cols1; ++k) {
        sum += matrix1[i][k] * matrix2[k][j];
      }
      result[i][j] = sum;
    }
  }
}

int main() {
  int rows1, cols1;
  double matrix1[MAX_SIZE][MAX_SIZE];
  read_matrix("matrix1.txt", matrix1, rows1, cols1);

  int rows2, cols2;
  double matrix2[MAX_SIZE][MAX_SIZE];
  read_matrix("matrix2.txt", matrix2, rows2, cols2);

  double result[MAX_SIZE][MAX_SIZE];
  multiply_matrices(matrix1, rows1, cols1, matrix2, rows2, cols2, result);

  write_matrix("result.txt", result, rows1, cols2);

  printf("Program zakonczony, mozna sprawdzic wynik :)\n");
  
}
