#pragma once

#include <vector>

template<class T>
int medianOfThree(std::vector<T>& array, int left, int right) {
    int mid = (left + right) / 2;
    T temp;
    if (array[left] > array[mid]) {
        temp = array[left];
        array[left] = array[mid];
        array[mid] = temp;
    }
    if (array[mid] > array[right]) {
        temp = array[mid];
        array[mid] = array[right];
        array[right] = temp;
    }
    if (array[left] > array[mid]) {
        temp = array[left];
        array[left] = array[mid];
        array[mid] = temp;
    }
    return mid;
}

template<class T>
int partition(std::vector<T>& array, int left, int right) {
    int mid = medianOfThree(array, left, right);
    T temp;
    temp = array[left];
    array[left] = array[mid];
    array[mid] = temp;
    int up = left + 1;
    int down = right;
    while (up < down) {
        while (array[up] <= array[left] && up != right) {
            up++;
        }
        while (array[down] > array[left] && down != left) {
            down--;
        }
        if (up < down) {
            temp = array[up];
            array[up] = array[down];
            array[down] = temp;
        }
    }
    if (right - left != 1) {
        temp = array[left];
        array[left] = array[down];
        array[down] = temp;
    }
    return down;
}


template<class T>
void sort_helper(std::vector<T>& array, int left, int right) {
    if ((right - left) >= 1) {
        int pivot = partition(array, left, right);
        sort_helper(array, left, pivot - 1);
        sort_helper(array, pivot + 1, right);
    }
}


template<class T>
void sort(std::vector<T>& array) {
    int left = 0;
    int right = array.size() - 1;
    sort_helper(array, left, right);
}


