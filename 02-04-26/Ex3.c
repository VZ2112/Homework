/******************
 * Incipiunt Data
 ******************/

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

int cmp_str(char *str1, char *str2) {
  int i;
  for(i = 0; str1[i] && str2[i] && str1[i] == str2[i]; i++);
  return str1[i] - str2[i];
}

int cpy_mem(unsigned size, void *dest, void *src) {
  unsigned i;
  // Copies a Memory Area Byte by Byte
  for(i = 0; i < size; i++) ((char *)dest)[i] = ((char *)src)[i];
  return;
}

void sort(unsigned n, char std[][NAME_LEN], int grd[][M]) {
  // Sorts using the Quicksort Algorithm
  char tmpstr[NAME_LEN];
  int tmpgrd[M];
  int i, j, k;
  if(n < 2) return;
  k = n - 1; // Last Element is Pivot
  j = -1; // Partitioning
  for(i = 0; i < n; i++)
    if(cmp_str(std[i], std[k]) <= 0) {
      cpy_mem(NAME_LEN, tmpstr, std[++j]); // Swap the two Entries
      cpy_mem(NAME_LEN, std[j], std[i]);
      cpy_mem(NAME_LEN, std[i], tmpstr);
      cpy_mem(M * sizeof(int), tmpgrd, grd[j]);
      cpy_mem(M * sizeof(int), grd[j], grd[i]);
      cpy_mem(M * sizeof(int), grd[i], tmpgrd);
    }
  sort(j, std, grd); // Sort the two Partitions
  sort(n - j - 1, std + j + 1, grd + j + 1);
}

/***********************
 * Incipit Boilerplate
 * Not honed for Users
 ***********************/

#include <stdio.h>

int main(int argc, char const *argv[]) {
  int i;
  printf("\nPlain:\t%-50sGrades:\n\n", "Name:");
  for(i = 0; i < N; i++) printf("\t%-50s%d %d %d %d\n", students[i],
    grades[i][0], grades[i][1], grades[i][2], grades[i][3]);
  sort(N, students, grades);
  printf("\nSorted:\t%-50sGrades:\n\n", "Name:");
  for(i = 0; i < N; i++) printf("\t%-50s%d %d %d %d\n", students[i],
    grades[i][0], grades[i][1], grades[i][2], grades[i][3]);
  return 0;
}
