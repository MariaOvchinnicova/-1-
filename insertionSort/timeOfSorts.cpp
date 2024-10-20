
#include <iostream>
#include <cstdlib>
#include <ctime>
#include <chrono>
#include <iomanip>

using namespace std;
void sort(int arr[], int n)
{
    for (int i = 0; i < n - 1; ++i) {
        for (int j = 0; j < n - i - 1; ++j) {
            if (arr[j] > arr[j + 1]) {
                swap(arr[j], arr[j + 1]);
            }
        }
    }
}

void reverseSort(int arr[],int n) 
{
    for (int i = 0; i < n - 1; ++i) {
        for (int j = 0; j < n - i - 1; ++j) {
            if (arr[j] < arr[j + 1]) {
                swap(arr[j], arr[j + 1]);
            }
        }
    }
}

void insertionSort(int arr[], int n)
{
    int  key,j;
    for (int i = 1; i < n; i++)
    {
        key = arr[i];
        for (j = i - 1; j >= 0; j--)
        {
            if (arr[j] > key)
                arr[j + 1] = arr[j];
            else
                break;
        }
        arr[j + 1] = key;
    }
}

void print(int arr[], int n) 
{
    cout << '[';
    for (int i = 0; i < n;i++) 
    {
        cout << arr[i] ;
        if (i != (n - 1))
            cout << ", ";
    }
    cout << ']';
    cout << endl;
}
void printd(double arr[], int n)
{
    cout << '[';
    for (int i = 0; i < n;i++)
    {
        cout << arr[i];
        if (i != (n - 1))
            cout << ", ";
    }
    cout << ']';
    cout << endl;
}
int main()
{
    setlocale(LC_ALL, "Russian");
    srand(static_cast<unsigned int>(std::time(0)));

    double s = 0;
    int t;
    int n = 15000;
    cout << setw(10) << "n" <<
        setw(20) << "Отсортированный" <<
        setw(30) << "Обратно отсортированный" <<
        setw(30) << "Почти отсортированный" <<
        
        setw(20) << "Случайный" << '\n';
    const int r = 5;
    int col[r];
    double timeS[r];
    double timeRS[r];
    double timeAS[r];
    double timeR[r];
    for (int k = 0; k < 5; k++)
    {
        int* arrSort = new int[n];
        int* arrRevSort = new int[n];
        int* arrRand = new int[n];
        int* arrAlmSort = new int[n];
        for (int i = 0; i < n;i++)
        {
            t = 1 + rand() % n;
            arrSort[i] = t;
            arrRevSort[i] = t;
            arrRand[i] = t;
            arrAlmSort[i] = t;
        }


        sort(arrSort, n);
        sort(arrAlmSort, int(n * (0.9)));
        reverseSort(arrRevSort, n);

        col[k] = n;
        cout << setw(10) << n;
         auto begin = std::chrono::steady_clock::now();
         insertionSort(arrSort, n);
         auto end = std::chrono::steady_clock::now();
         auto elapsed_ms = std::chrono::duration_cast<std::chrono::milliseconds>(end - begin);
         s = elapsed_ms.count() / (double)1000;
         timeS[k] = s;
         cout << setw(20) << s;
         begin = std::chrono::steady_clock::now();
         insertionSort(arrRevSort, n);
          end = std::chrono::steady_clock::now();
          elapsed_ms = std::chrono::duration_cast<std::chrono::milliseconds>(end - begin);
         s = elapsed_ms.count() / (double)1000;
         timeRS[k] = s;
         cout << setw(30) << s;
          begin = std::chrono::steady_clock::now();
         insertionSort(arrAlmSort, n);
          end = std::chrono::steady_clock::now();
          elapsed_ms = std::chrono::duration_cast<std::chrono::milliseconds>(end - begin);
         s = elapsed_ms.count() / (double)1000;
         timeAS[k] = s;
         cout << setw(30) << s;
          begin = std::chrono::steady_clock::now();
         insertionSort(arrRand, n);
         end = std::chrono::steady_clock::now();
          elapsed_ms = std::chrono::duration_cast<std::chrono::milliseconds>(end - begin);
         s = elapsed_ms.count() / (double)1000;
         timeR[k] = s;
         cout << setw(20) << s;
         cout << '\n';
        delete[]arrSort;
        delete[]arrRevSort;
        delete[]arrRand;
        delete[]arrAlmSort;
        n += 1000;
    }
    cout << "Количество элементов"<<'\n';
    print(col, r);
    cout << "Время сортировки отсоритированного массива" << '\n';
    printd(timeS, r);
    cout << "Время сортировки почти отсоритированного массива" << '\n';
    printd(timeAS, r);
    cout << "Время сортировки обратно отсоритированного массива" << '\n';
    printd(timeRS, r);
    cout << "Время сортировки случайно заполненного массива" << '\n';
    printd(timeR, r);
    return(0);
}
