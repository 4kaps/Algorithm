#include <iostream>
#include <vector>

void bubbleSort(std::vector<int>& a);
void bubbleSortImproved1(std::vector<int>& a);
void bubbleSortImproved2(std::vector<int>& a);

void swap(int& a, int& b) {
    int tmp = a;
    a = b;
    b = tmp;
}

void bubbleSort(std::vector<int>& a) {
    int countCmpOps = 0; 
    int countSwaps = 0; 
    int n = a.size();
    
    for (int i = 0; i < n - 1; ++i) {
        for (int j = 0; j < n - i - 1; ++j) {
            countCmpOps++;
            if (a[j] > a[j + 1]) {
                swap(a[j], a[j + 1]);
                countSwaps++;
            }
        }
    }
    std::cout << countCmpOps << " " << countSwaps << " ";
}

void bubbleSortImproved1(std::vector<int>& a) {
    int countCmpOps = 0; 
    int countSwaps = 0; 
    int n = a.size();
    bool isSwapped = false;
    
    for (int i = 0; i < n - 1; ++i) {
        isSwapped = false;
        for (int j = 0; j < n - i - 1; ++j) {
            countCmpOps++;
            if (a[j] > a[j + 1]) {
                swap(a[j], a[j + 1]);
                countSwaps++;
                isSwapped = true;
            }
        }
        if (!isSwapped) {
            break;
        }
    }
    std::cout << countCmpOps << " " << countSwaps << " ";
}

void bubbleSortImproved2(std::vector<int>& a) {
    int countCmpOps = 0; 
    int countSwaps = 0; 
    int n = a.size();
    int tmpPos = n;
    int Spos = 0;
    
    while (tmpPos > 0) {
        Spos = 0;
        for (int i = 1; i < tmpPos; ++i) {
            countCmpOps++;
            if (a[i - 1] > a[i]) {
                swap(a[i - 1], a[i]);
                countSwaps++;
                Spos = i;
            }
        }
        tmpPos = Spos;
    }
    std::cout << countCmpOps << " " << countSwaps << " ";
}

int main() {
    int numTestCases;
    std::cin >> numTestCases;
    
    for (int i = 0; i < numTestCases; ++i) {
        int num;
        std::cin >> num;
        std::vector<int> a(num);
        
        for (int j = 0; j < num; ++j) {
            std::cin >> a[j];
        }
        
        bubbleSort(a);
        bubbleSortImproved1(a);
        bubbleSortImproved2(a);
        std::cout << std::endl;
    }
    
    return 0;
}
