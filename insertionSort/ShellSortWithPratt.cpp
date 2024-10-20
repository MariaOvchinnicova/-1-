#include <vector>
#include <algorithm>

using namespace std;
vector<int> generatePrattSequence(int n)
{
    std::vector<int> sequence;

    for (int i = 1; i <= n; i *= 2)
    {
        for (int j = 1; j <= n; j *= 3)
        {
            if(i * j < n)
                sequence.push_back(j);
        }
    } // Сортируем и убираем дубликаты (если есть) 
    sort(sequence.begin(), sequence.end());
    sequence.erase(unique(sequence.begin(), sequence.end()), sequence.end());
    return sequence;
}

void shellSortWithPratt(int arr[], int n)
{
    vector<int> prattSequence = generatePrattSequence(n);
    for (int gap : prattSequence)
    {
        for (int i = gap; i < n; i += 1)
        {
            int temp = arr[i];
            int j;
            for (j = i; j >= gap; j -= gap)
                if (arr[j - gap] > temp)
                    arr[j] = arr[j - gap];
                else
                    break;
            arr[j] = temp;
        }
    }

}
