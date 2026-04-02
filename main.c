#define N 20
#define NAME_LEN 50
#define M 4

int str_cpy(char dest[], char src[]) {
	int i;
	for(i = 0; src[i]; i++) dest[i] = src[i];
	dest[i] = src[i];
	return i;
}

int cmp(char a[], char b[]) {
	int i;
	for(i = 0; a[i] && b[i] && a[i] == b[i]; i++);
	return a[i] - b[i];
}

void sort(int n, char arr[][NAME_LEN]) {
	char tmp[NAME_LEN];
	int i, j, k;
	if(n < 2) return;
	k = n - 1;
	j = -1;
	for(i = 0; i < k; i++)
		if(cmp(arr[i], arr[k]) < 0) {
			str_cpy(tmp, arr[++j]);
			str_cpy(arr[j], arr[i]);
			str_cpy(arr[i], tmp);
		}
	str_cpy(tmp, arr[++j]);
	str_cpy(arr[j], arr[i]);
	str_cpy(arr[i], tmp);
	sort(j, arr);
	sort(n - j - 1, arr + j + 1);
	return;
}

#include <stdio.h>

int main()
{
	int i;
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
		"Gor Movsisyan",
		"Astghik Danielyan"
	};
	sort(N, students);
	for(i = 0; i < N; i++) puts(students[i]);
	return 0;
}