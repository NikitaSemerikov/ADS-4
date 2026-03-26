// Copyright 2021 NNTU-CS
#include <algorithm>

int countPairs1(const int* arr, int len, int value) {
    int* tmp = new int[len];
    std::copy(arr, arr + len, tmp);
    std::sort(tmp, tmp + len);

    int count = 0;
    for (int i = 0; i < len; i++) {
        for (int j = i + 1; j < len; j++) {
            int sum = tmp[i] + tmp[j];
            if (sum == value) {
                count++;
            } else if (sum > value) {
                break;
            }
        }
    }

    delete[] tmp;
    return count;
}

int countPairs2(const int* arr, int len, int value) {
    int* tmp = new int[len];
    std::copy(arr, arr + len, tmp);
    std::sort(tmp, tmp + len);

    int left = 0;
    int right = len - 1;
    int count = 0;

    while (left < right) {
        int sum = tmp[left] + tmp[right];
        if (sum == value) {
            count++;
            left++;
            right--;
        } else if (sum < value) {
            left++;
        } else {
            right--;
        }
    }

    delete[] tmp;
    return count;
}

int binarySearch(const int* arr, int left, int right, int target) {
    while (left <= right) {
        int mid = left + (right - left) / 2;
        if (arr[mid] == target) {
            return mid;
        }
        if (arr[mid] < target) {
            left = mid + 1;
        } else {
            right = mid - 1;
        }
    }
    return -1;
}

int countPairs3(const int* arr, int len, int value) {
    int* tmp = new int[len];
    std::copy(arr, arr + len, tmp);
    std::sort(tmp, tmp + len);

    int count = 0;
    for (int i = 0; i < len; i++) {
        int need = value - tmp[i];
        int pos = binarySearch(tmp, i + 1, len - 1, need);
        if (pos != -1) {
            count++;
        }
    }

    delete[] tmp;
    return count;
}
