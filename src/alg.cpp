// Copyright 2021 NNTU-CS
#include <algorithm>

int countPairs1(int *arr, int len, int value) {
    if (arr == nullptr || len <= 1) {
        return 0;
    }

    int count = 0;
    for (int i = 0; i < len; ++i) {
        for (int j = i + 1; j < len; ++j) {
            if (arr[i] + arr[j] == value) {
                ++count;
            }
        }
    }
    return count;
}

int countPairs2(int *arr, int len, int value) {
    if (arr == nullptr || len <= 1) {
        return 0;
    }

    int left = 0;
    int right = len - 1;
    int count = 0;

    while (left < right) {
        int sum = arr[left] + arr[right];

        if (sum < value) {
            ++left;
        } else if (sum > value) {
            --right;
        } else {
            if (arr[left] == arr[right]) {
                int k = right - left + 1;
                count += k * (k - 1) / 2;
                break;
            } else {
                int leftVal = arr[left];
                int rightVal = arr[right];
                int leftCount = 0;
                int rightCount = 0;

                while (left <= right && arr[left] == leftVal) {
                    ++leftCount;
                    ++left;
                }
                while (right >= left && arr[right] == rightVal) {
                    ++rightCount;
                    --right;
                }
                count += leftCount * rightCount;
            }
        }
    }

    return count;
}

int countPairs3(int *arr, int len, int value) {
    if (arr == nullptr || len <= 1) {
        return 0;
    }

    int count = 0;

    for (int i = 0; i < len; ++i) {
        int first = arr[i];
        int target = value - first;

        if (target < 0) {
            continue;
        }
        if (first > value) {
            break;
        }

        int *begin = arr + i + 1;
        int *end = arr + len;

        int *low = std::lower_bound(begin, end, target);
        if (low == end || *low != target) {
            continue;
        }
        int *up = std::upper_bound(low, end, target);

        count += static_cast<int>(up - low);
    }

    return count;
}

