#define N 20
#define NAME_LEN 32
#define M 4

char students[N][NAME_LEN] = {
  "Aram Petrosyan",
  "Nare Mkrtchyan",
  "Vahan Grigoryan",
  "Lusine Harutyunyan",
  "Sona Khachatryan",
  "Tigran Manukyan",
  "Ani Karapetyan",
  "David Hovhannisyan",
  "Mariam Ghazaryan",
  "Arsen Babayan",
  "Elena Sargsyan",
  "Levon Vardanyan",
  "Hasmik Stepanyan",
  "Karen Harutyunyan",
  "Suren Avetisyan",
  "Lilit Khachatryan",
  "Vahagn Margaryan",
  "Narine Melikyan",
  "Gor Movsesyan",
  "Astghik Danielyan"
};

int grades[N][M] = {
  // Math, Physics, Chemistry, English
  {78, 85, 92, 88}, // Aram Petrosyan
  {65, 70, 58, 62}, // Nareh Mkrtchyan
  {90, 95, 88, 93}, // Vahan Grigoryan
  {45, 52, 49, 55}, // Lusine Harutyunyan
  {82, 77, 80, 85}, // Sona Khachatryan
  {70, 68, 72, 75}, // Tigran Manukyan
  {88, 91, 85, 90}, // Ani Karapetyan
  {55, 60, 58, 62}, // David Hovhannisyan
  {77, 79, 81, 78}, // Mariam Ghazaryan
  {92, 95, 90, 94}, // Arsen Babayan
  {60, 62, 65, 68}, // Elena Sargsyan
  {85, 80, 87, 82}, // Levon Vardanyan
  {50, 55, 52, 48}, // Hasmik Stepanyan
  {73, 75, 70, 72}, // Karen Harutyunyan
  {66, 68, 64, 65}, // Suren Avetisyan
  {89, 92, 90, 88}, // Lilit Khachatryan
  {58, 60, 55, 57}, // Vahagn Margaryan
  {80, 85, 83, 82}, // Narine Melikyan
  {47, 50, 45, 48}, // Gor Movsesyan
  {91, 95, 93, 94}  // Astghik Danielyan
};

int cmp_avg_grd(int i, int j) {
  return grades[i][0] + grades[i][1] + grades[i][2] + grades[i][3]
    - grades[j][0] - grades[j][1] - grades[j][2] - grades[j][3];
}

int cmp_math_grade(int i, int j) {
  return grades[i][0] - grades[j][0];
}

int cpy_mem(unsigned size, void *dest, void *src) {
  unsigned i;
  // Copies a Memory Area Byte by Byte
  for(i = 0; i < size; i++) ((char *)dest)[i] = ((char *)src)[i];
  return;
}

void sort(unsigned n, char std[][NAME_LEN], int grd[][M],
  int cmp(int, int)) {
  // Sorts using the Quicksort Algorithm
  char tmpstr[NAME_LEN];
  int tmpgrd[M];
  int i, j, k;
  if(n < 2) return;
  k = n - 1; // Last Element is Pivot
  j = -1; // Partitioning
  for(i = 0; i < n; i++)
    if(cmp(i, k) <= 0) {
      cpy_mem(NAME_LEN, tmpstr, std[++j]); // Swap the two Entries
      cpy_mem(NAME_LEN, std[j], std[i]);
      cpy_mem(NAME_LEN, std[i], tmpstr);
      cpy_mem(M * sizeof(int), tmpgrd, grd[j]);
      cpy_mem(M * sizeof(int), grd[j], grd[i]);
      cpy_mem(M * sizeof(int), grd[i], tmpgrd);
    }
  sort(j, std, grd, cmp); // Sort the two Partitions
  sort(n - j - 1, std + j + 1, grd + j + 1, cmp);
}

int avg_gt_80(int i) {
  return grades[i][0] + grades[i][1] + grades[i][2] + grades[i][3] > 320;
}

int avg_lt_60(int i) {
  return grades[i][0] + grades[i][1] + grades[i][2] + grades[i][3] < 240;
}

int count(unsigned n, char std[][NAME_LEN], int grd[][M], int crit(int)) {
  int count = 0, i;
  for(i = 0; i < n; i++) if(crit(i)) count++;
  return count;
}

/***********************
 * Incipit Boilerplate
 * Not honed for Users
 ***********************/

#include <stdio.h>

int main(int argc, char const *argv[]) {
  int i;
  printf("1: Highest and lowest average Grade.\n");
  printf("2: 5 highest Grades from Math.\n");
  printf("3: Average higher than 80.\n");
  printf("4: Average lower than 60.\n");
  printf("5: Subject with highest average Grade.\n");
  printf("Which one?");
  scanf("%d", &i);
  switch(i) {
  case 1:
    sort(N, students, grades, cmp_avg_grd);
    printf("Highest Average: %s\n", students[N - 1]);
    printf("Lowest Average: %s\n", students[0]);
    break;
  case 2:
    sort(N, students, grades, cmp_math_grade);
    printf("Student with highest Math Grade: %s\n", students[N - 1]);
    break;
  case 3:
    printf("Students with average Grade greater than 80: %d",
      count(N, students, grades, avg_gt_80));
    break;
  case 4:
    printf("Students with average Grade less than 60: %d",
      count(N, students, grades, avg_lt_60));
    break;
  }
  return 0;
}
