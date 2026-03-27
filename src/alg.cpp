// Copyright 2021 NNTU-CS
#include <cstddef>

int countPairs1(int *arr, int len, int value) {
    int count = 0;
    for (int i = 0; i < len; ++i) {
        for (int j = i + 1; j < len; ++j) {
            int sum = arr[i] + arr[j];
            if (sum == value) {
                ++count;
            } else if (sum > value) {
                break;
            }
        }
    }
    return count;
}

int countPairs2(int *arr, int len, int value) {
    int left = 0;
    int right = len - 1;
    int count = 0;

    while (left < right) {
        int sum = arr[left] + arr[right];

        if (sum == value) {
            int lv = arr[left];
            int rv = arr[right];

            if (lv == rv) {
                int n = right - left + 1;
                count += n * (n - 1) / 2;
                break;
            }

            int lc = 0;
            while (left < right && arr[left] == lv) {
                ++left;
                ++lc;
            }

            int rc = 0;
            while (right >= left && arr[right] == rv) {
                --right;
                ++rc;
            }

            count += lc * rc;
        } else if (sum < value) {
            ++left;
        } else {
            --right;
        }
    }

    return count;
}

static int binarySearchFirst(const int *arr, int left, int right, int target) {
    int pos = -1;
    while (left <= right) {
        int mid = left + (right - left) / 2;

        volatile
