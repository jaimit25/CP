#include <bits/stdc++.h>
#include <string>
using namespace std;

// Code for Graph visualization with Flood Fill ALgorithm( $4 directions - top,right,bottom,left )

string getPx(int dt, int flag) {
  if (flag == 1) {
    return to_string(dt);
  }
  if (dt == 0)
    return ".";
  else if (dt == 2)
    return "#";
  else
    return " ";
}

void printImage(vector<vector<int>> img, int flag) {
  cout << endl;
  for (auto list : img) {
    for (auto px : list) {

      cout << getPx(px, flag) << " ";
    }
    cout << endl;
  }

  for (int i = 0; i < img[0].size(); i++)
    cout << "_ ";
  cout << endl;
}

void color(int row, int col, vector<vector<int>> &updated_image,
           vector<vector<int>> image, int newColor, int delRow[], int delCol[],
           int iniC) {

  updated_image[row][col] = newColor;

  int n = image.size();    // height
  int m = image[0].size(); // width

  for (int i = 0; i < 4; i++) {
    int new_row = row + delRow[i];
    int new_col = col + delCol[i];
    if (new_row >= 0 && new_row < n && new_col >= 0 && new_col < m &&
        image[new_row][new_col] == iniC && // if new point color is same as
                                           // initial color then Re-Paint it
        updated_image[new_row][new_col] !=
            newColor // if new point is not updated by any node
    ) {
      color(new_row, new_col, updated_image, image, newColor, delRow, delCol,
            iniC);
    }
  }
}

vector<vector<int>> floodFill(vector<vector<int>> image, int start_row,
                              int start_col, int newColor) {

  int initial_color = image[start_row][start_col];
  vector<vector<int>> updated_image = image;
  int delRow[] = {-1, 0, +1, 0};
  int delCol[] = {0, +1, 0, -1};

  color(start_row, start_col, updated_image, image, newColor, delRow, delCol,
        initial_color);

  return updated_image;
}

vector<vector<int>> processWithOne(vector<vector<int>> image, int newColor) {
  printImage(image, 0);

  vector<vector<int>> updated_Image = floodFill(image, 0, 0, newColor);

  for (int i = 0; i < image.size(); i++) {
    for (int j = 0; j < image[0].size(); j++) {
      if (image[i][j] == 1) {
        updated_Image = floodFill(updated_Image, i, j, newColor);
      }
    }
  }
  // updated_Image = floodFill(updated_Image, 0, 9, 2);

  return updated_Image;
}

int main() {

  vector<vector<int>> image = {
      // x : 9 , y : 10
      {1, 1, 0, 1, 1, 1, 0, 1, 1, 1}, {1, 0, 1, 0, 1, 0, 1, 0, 1, 1},
      {0, 1, 1, 1, 0, 1, 1, 1, 0, 1}, {0, 1, 1, 1, 1, 1, 1, 1, 0, 1},
      {0, 1, 1, 1, 1, 1, 1, 1, 0, 1}, {0, 1, 1, 1, 1, 1, 1, 1, 0, 1},
      {1, 0, 1, 1, 1, 1, 1, 0, 1, 1}, {1, 1, 0, 1, 1, 1, 0, 1, 1, 1},
      {1, 1, 1, 0, 1, 0, 1, 1, 1, 1}, {1, 1, 1, 1, 0, 1, 1, 1, 1, 1}};
  int newColor = 3;
  vector<vector<int>> updated_Image = processWithOne(image, newColor);
  printImage(updated_Image, 0);
  printImage(updated_Image, 1);

  return 0;
}