#include <iostream>
#include <ctime>
#include <cstdlib>
using namespace std;

void heapify(int arr[], int n, int i) {
    int largest = i;
    int left = 2 * i + 1;
    int right = 2 * i + 2;

    if (left < n && arr[left] > arr[largest])
        largest = left;

    if (right < n && arr[right] > arr[largest])
        largest = right;

    if (largest != i) {
        swap(arr[i], arr[largest]);
        heapify(arr, n, largest);
    }
}

void heapSort(int arr[], int n) {
    for (int i = n / 2 - 1; i >= 0; i--)
        heapify(arr, n, i);

    for (int i = n - 1; i >= 0; i--) {
        swap(arr[0], arr[i]);
        heapify(arr, i, 0);
    }
}

void inputValues(int arr[], int N) {
    cout << "Enter " << N << " integer values:" << endl;
    for (int i = 0; i < N; i++) {
        cin >> arr[i];
    }
}

void generateRandomValues(int arr[], int N) {
    cout << "Generating " << N << " random integer values in the range [1, 100]:" << endl;
    for (int i = 0; i < N; i++) {
        arr[i] = rand() % 100 + 1; // Generate random values between 1 and 100
    }
}

void displayArray(int arr[], int N) {
    cout << "Array elements: ";
    for (int i = 0; i < N; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;
}

int main() {
    srand(time(0));

    int maxN = 10000;
    int arr[maxN];
    int N;

    cout << "Enter the value of N: ";
    cin >> N;

    if (N <= 0 || N > maxN) {
        cout << "Invalid value of N." << endl;
        return 1;
    }

    cout << "Enter 1 to input values manually or 2 to generate random values: ";
    int choice;
    cin >> choice;

    if (choice == 1) {
        inputValues(arr, N);
    } else if (choice == 2) {
        generateRandomValues(arr, N);
    } else {
        cout << "Invalid choice." << endl;
        return 1;
    }

    displayArray(arr, N); // Display the input array

    clock_t start = clock();
    heapSort(arr, N);
    clock_t end = clock();
    double elapsedTime = double(end - start) / CLOCKS_PER_SEC * 1000;

    cout << "Sorted array:" << endl;
    for (int i = 0; i < N; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;

    cout << "Time taken (ms): " << elapsedTime << endl;

    return 0;
}
