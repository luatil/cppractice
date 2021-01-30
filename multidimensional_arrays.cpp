#include <iostream>

void ex1()
{
	int* array = new int[50];
}

void ex2()
{
	int** a2d = new int*[50];
	for(int i = 0; i < 50; i++)
		a2d[i] = new int[50];

	for(int i = 0; i < 50; i++)
		delete[] a2d[i];
	delete[] a2d;
}

void ex3()
{
	int*** a3d = new int**[50];
	for(int i = 0; i < 50; i++) 
	{
		a3d[i] = new int*[50];
		for(int j = 0; j < 50; j++)
			a3d[i][j] = new int[50];
	}

}

// this is much faster due to cache miss
void ex4()
{
	int* array = new int[5 * 5];
	for (int y = 0; y < 5; y++)
	{
		for (int x = 0; x < 5; x++)
		{
			array[x + y * 5] = 2;
		}
	}
	delete[] array;
}

int main()
{
	ex4();
}
