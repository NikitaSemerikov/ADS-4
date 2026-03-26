// Copyright 2021 NNTU-CS
#include <iostream>
#include <chrono>
#include <algorithm>

using namespace std;

int countPairs1(int *arr, int len, int value)
{
    int count = 0;
    for (int i = 0; i < len; i++)
    {
        for (int j = i + 1; j < len; j++)
        {
            int sum = arr[i] + arr[j];
            if (sum == value)
                count++;
            else if (sum > value)
                break;
        }
    }
    return count;
}

int countPairs2(int *arr, int len, int value)
{
    int left = 0;
    int right = len - 1;
    int count = 0;

    while (left < right)
    {
        int sum = arr[left] + arr[right];
        if (sum == value)
        {
            count++;
            left++;
        }
        else if (sum < value)
        {
            left++;
        }
        else
        {
            right--;
        }
    }
    return count;
}

int binarySearch(const int *arr, int left, int right, int target)
{
    while (left <= right)
    {
        int mid = left + (right - left) / 2;
        if (arr[mid] == target)
            return mid;
        if (arr[mid] < target)
            left = mid + 1;
        else
            right = mid - 1;
    }
    return -1;
}

int countPairs3(int *arr, int len, int value)
{
    int count = 0;

    for (int i = 0; i < len; i++)
    {
        int need = value - arr[i];
        int pos = binarySearch(arr, i + 1, len - 1, need);
        if (pos != -1)
            count++;
    }
    return count;
}
