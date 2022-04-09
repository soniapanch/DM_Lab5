#include <conio.h>
#include <iostream>
#include <fstream>
#include <queue>
#include <string.h>
using namespace std;

const int N = 4;
int read_matrix1(int matr1[N][N]) {
	char line[2];
	ifstream in("l5-1.txt");
	printf("Розмiрнiсть матрицi 1: \n");
	if (in.is_open())
	{
		in.getline(line, 2);
		std::cout << line << std::endl;
		printf("Задана матриця 1: \n");
		for (int i = 0; i < 4; i++)
			for (int j = 0; j < 4; j++)
				in >> matr1[i][j];

		for (int i = 0; i < 4; i++)
		{
			for (int j = 0; j < 4; j++)
				cout << matr1[i][j] << "\t";
			cout << "\n";
		}

		in.close();
		printf("\n");
		return **matr1;
	}
	else
	{
		cout << "Файл не знайдено.";
		return 0;
	}
}
int read_matrix2(int matr2[N][N]) {
	char line[2];
	ifstream in("l5-2.txt");
	printf("Розмiрнiсть матрицi 2: \n");
	if (in.is_open())
	{
		in.getline(line, 2);
		std::cout << line << std::endl;
		printf("Задана матриця 2: \n");
		for (int i = 0; i < 4; i++)
			for (int j = 0; j < 4; j++)
				in >> matr2[i][j];

		for (int i = 0; i < 4; i++)
		{
			for (int j = 0; j < 4; j++)
				cout << matr2[i][j] << "\t";
			cout << "\n";
		}

		in.close();
		printf("\n");
		return **matr2;
	}
	else
	{
		cout << "Файл не знайдено.";
		return 0;
	}
}
int matr1[N][N];
int matr2[N][N];

int V[N] = { 0,1,2,3 };

bool isomorph() {
    for (int i = 0;i < N;i++)
        for (int j = 0;j < N;j++)
            if (matr1[i][j] != matr2[V[i]][V[j]])
                return false;
    return true;
}

int main()
{
	setlocale(LC_ALL, "Ukrainian");
	read_matrix1(matr1);
	read_matrix2(matr2);
    do {
        if (isomorph()) {
			printf("Граф iзоморфний \nЗнайденi вiдповiдностi вершин:\n");
            for (int i = 0;i < N;i++)
                printf("(%d - %d), ", i + 1, V[i] + 1);
            return 0;
        }
    } while (next_permutation(V, V + N)); 
	
}