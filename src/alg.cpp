// Copyright 2021 NNTU-CS

int countPairs1(int* arr, int size, int sum) {
    int count = 0;

    for (int i = 0; i < size; ++i) {
        for (int j = i + 1; j < size; ++j) {
            int s = arr[i] + arr[j];
            if (s == sum) {
                count += 1;
            }
        }
    }
    return count;
}

int countPairs2(int* arr, int size, int sum) {
    int left = 0;
    int right = size - 1;
    int count = 0;

    while (left < right) {
        int curSum = arr[left] + arr[right];

        if (curSum == sum) {
            if (arr[left] == arr[right]) {
                int amount = right - left + 1;
                count += amount * (amount - 1) / 2;
                break;
            }

            int leftVal = arr[left];
            int rightVal = arr[right];

            int leftCnt = 0;
            while (left <= right && arr[left] == leftVal) {
                ++leftCnt;
                ++left;
            }

            int rightCnt = 0;
            while (right >= left && arr[right] == rightVal) {
                ++rightCnt;
                --right;
            }

            count += leftCnt * rightCnt;

        } else if (curSum < sum) {
            ++left;
        } else {
            --right;
        }
    }

    return count;
}

int countPairs3(int* arr, int size, int sum) {
    int count = 0;

    for (int i = 0; i < size - 1; ++i) {
        if (i > 0 && arr[i] == arr[i - 1]) {
            continue;
        }

        int need = sum - arr[i];
        if (need < arr[i]) {
            break;
        }

        int low = i + 1;
        int high = size - 1;
        int first = -1;

        while (low <= high) {
            int mid = low + (high - low) / 2;

            if (arr[mid] == need) {
                first = mid;
                high = mid - 1;
            } else if (arr[mid] < need) {
                low = mid + 1;
            } else {
                high = mid - 1;
            }
        }

        if (first == -1) {
            continue;
        }

        int last = first;
        low = first;
        high = size - 1;

        while (low <= high) {
            int mid = low + (high - low) / 2;

            if (arr[mid] == need) {
                last = mid;
                low = mid + 1;
            } else if (arr[mid] < need) {
                low = mid + 1;
            } else {
                high = mid - 1;
            }
        }

        if (arr[i] == need) {
            int len = last - i + 1;
            count += len * (len - 1) / 2;
            break;
        }

        int leftCnt = 1;
        while (i + leftCnt < size && arr[i + leftCnt] == arr[i]) {
            ++leftCnt;
        }

        count += leftCnt * (last - first + 1);
    }

    return count;
}
