//
// Created by 董启宏 on 2016/10/12.
//

#include "MaxSubsequenceSum.h"
#include "util.h"

int MaxSubsequenceSum_ON3(const int A[], int N) {
    int maxSum = 0;
    for (int i = 0; i < N; ++i) {
        for (int j = i; j < N; ++j) {
            int thisSum = 0;
            for (int k = i; k <= j; ++k) {
                thisSum += A[k];
            }
            if (thisSum > maxSum) {
                maxSum = thisSum;
            }
        }
    }
    return maxSum;
}

int MaxSubsequenceSum_ON2(const int A[], int N) {
    int maxSum = 0;
    for (int i = 0; i < N; ++i) {
        int thisSum = 0;
        for (int j = i; j < N; ++j) {
            thisSum += A[j];
            if (thisSum > maxSum) {
                maxSum = thisSum;
            }
        }
    }
    return maxSum;
}

int MaxSubsequenceSum_ONLogN(const int A[], int N) {
    return MaxSubSum(A, 0, N-1);
}

static int MaxSubSum(const int A[], int left, int right) {
    if (left == right) {
        if (A[left] > 0) {
            return A[left];
        } else {
            return 0;
        }
    }

    int center = (left + right) / 2;
    int maxLeftSum = MaxSubSum(A, left, center);
    int maxRightSum = MaxSubSum(A, center+1, right);

    int maxLeftBorderSum = 0;
    int leftBorderSum = 0;
    for (int i = center; i >= left; i--) {
        leftBorderSum += A[i];
        if (leftBorderSum > maxLeftBorderSum) {
            maxLeftBorderSum = leftBorderSum;
        }
    }

    int maxRightBorderSum = 0;
    int rightBorderSum = 0;
    for (int i = center+1; i <= right; i++) {
        rightBorderSum += A[i];
        if (rightBorderSum > maxRightBorderSum) {
            maxRightBorderSum = rightBorderSum;
        }
    }

    return max3(maxLeftSum, maxRightSum, maxLeftBorderSum + maxRightBorderSum);

}

int MaxSubsequenceSum_ON(const int A[], int N) {
    int thisSum = 0;
    int maxSum = 0;
    for (int i = 0; i < N; ++i) {
        thisSum += A[i];
        if (thisSum > maxSum) {
            maxSum = thisSum;
        } else if (thisSum < 0) {
            thisSum = 0;
        }
    }

    return maxSum;
}