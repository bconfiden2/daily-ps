#include <iostream>
#include <cstdlib>
using namespace std;

int* makeArray1D(int* size);
//void printArray1D(int* size);
void destroyArray1D(int* arr, int* size);

int** makeArray2D(int* size);
void destroyArray2D(int** arr, int* size);

int main(int argc, char* argv[])
{
    if(argc < 2)
    {
        cout << "!" << endl;
        return -1;
    }

    int dim = argc - 1;
    int* size = new int[dim];

    for(int i = 0 ; i < dim ; i++)
    {
        size[i] = atoi(argv[i + 1]);
    }

    int* arr1d = nullptr;
    arr1d = makeArray1D(size);
    for(int i = 0 ; i < size[0] ; i++)
    {
        arr1d[i] = i;
        cout << arr1d[i] << " ";
    }
    cout << endl;

    int** arr2d = nullptr;
    arr2d = makeArray2D(size);
    for(int i = 0 ; i < size[0] ; i++)
    {
        for(int j = 0 ; j < size[1] ; j++)
        {
            arr2d[i][j] = i + j;
            cout << arr2d[i][j] << " ";
        }
        cout << endl;
    }

    destroyArray1D(arr1d, size);
    destroyArray2D(arr2d, size);
    return 0;
}

int* makeArray1D(int* size)
{
    int* temp = new int[size[0]];
    return temp;
}

void destroyArray1D(int* arr, int* size)
{
    delete[] arr;
}

int** makeArray2D(int* size)
{
    int** temp = new int*[size[0]];
    for(int i = 0 ; i < size[0] ; i++)
    {
        temp[i] = new int[size[1]];
    }

    return temp;
}

void destroyArray2D(int** arr, int* size)
{
    for(int i = 0 ; i < size[0] ; i++)
    {
        delete[] arr[i];
    }
    delete[] arr;
}