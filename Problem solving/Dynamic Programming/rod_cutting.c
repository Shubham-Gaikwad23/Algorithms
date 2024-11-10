#include <time.h>
#include <stdio.h>

int memoized;

int rod_cutting(int *price, int len, int* optimal_profit) {
    int profit = -1;
    if (len == 0) {
        return 0;
    }
    
    if (memoized && optimal_profit[len] != 0) {
        return optimal_profit[len];
    }

    for(int cut = 0; cut < len; cut++) {
        int p = price[cut] + rod_cutting(price, len - cut - 1, optimal_profit);
        if (p > profit) {
            profit = p;
        }
    }

    optimal_profit[len] = profit;
    return profit;
}

int main() {
    int price[20] = {1, 5, 8, 9, 10, 17, 17, 20, 24, 30, 34, 37, 38, 45, 45, 48, 52, 58, 62, 65};
    
    for(int len = 1; len <= 20; len++) {

        int optimal_profit[40] = {0};
        printf("Length: %d\n", len);

        // No memoized
        clock_t start = clock();
        memoized = 0;
        int profit = rod_cutting(price, len, optimal_profit);
        clock_t end = clock();
        double time_taken = ((double)(end - start)) / CLOCKS_PER_SEC;
        printf("Runtime without memoized: %f, profit: %d\n", time_taken, profit);
        
        // Memoized
        start = clock();
        memoized = 1;
        profit = rod_cutting(price, len, optimal_profit);
        end = clock();
        time_taken = ((double)(end - start)) / CLOCKS_PER_SEC;
        printf("Runtime with memoized: %f, profit: %d\n", time_taken, profit);
        printf("----------------------------------\n");
    }
    return 0;
}

/**
Length: 1
Runtime without memoized: 0.000001, profit: 1
Runtime with memoized: 0.000001, profit: 1
----------------------------------
Length: 2
Runtime without memoized: 0.000000, profit: 5
Runtime with memoized: 0.000001, profit: 5
----------------------------------
Length: 3
Runtime without memoized: 0.000001, profit: 8
Runtime with memoized: 0.000001, profit: 8
----------------------------------
Length: 4
Runtime without memoized: 0.000001, profit: 10
Runtime with memoized: 0.000000, profit: 10
----------------------------------
Length: 5
Runtime without memoized: 0.000001, profit: 13
Runtime with memoized: 0.000001, profit: 13
----------------------------------
Length: 6
Runtime without memoized: 0.000001, profit: 17
Runtime with memoized: 0.000001, profit: 17
----------------------------------
Length: 7
Runtime without memoized: 0.000001, profit: 18
Runtime with memoized: 0.000001, profit: 18
----------------------------------
Length: 8
Runtime without memoized: 0.000002, profit: 22
Runtime with memoized: 0.000001, profit: 22
----------------------------------
Length: 9
Runtime without memoized: 0.000005, profit: 25
Runtime with memoized: 0.000000, profit: 25
----------------------------------
Length: 10
Runtime without memoized: 0.000009, profit: 30
Runtime with memoized: 0.000000, profit: 30
----------------------------------
Length: 11
Runtime without memoized: 0.000018, profit: 34
Runtime with memoized: 0.000003, profit: 34
----------------------------------
Length: 12
Runtime without memoized: 0.000035, profit: 37
Runtime with memoized: 0.000001, profit: 37
----------------------------------
Length: 13
Runtime without memoized: 0.000067, profit: 39
Runtime with memoized: 0.000001, profit: 39
----------------------------------
Length: 14
Runtime without memoized: 0.000161, profit: 45
Runtime with memoized: 0.000001, profit: 45
----------------------------------
Length: 15
Runtime without memoized: 0.000273, profit: 46
Runtime with memoized: 0.000001, profit: 46
----------------------------------
Length: 16
Runtime without memoized: 0.000542, profit: 50
Runtime with memoized: 0.000001, profit: 50
----------------------------------
Length: 17
Runtime without memoized: 0.001102, profit: 53
Runtime with memoized: 0.000001, profit: 53
----------------------------------
Length: 18
Runtime without memoized: 0.002208, profit: 58
Runtime with memoized: 0.000001, profit: 58
----------------------------------
Length: 19
Runtime without memoized: 0.004291, profit: 62
Runtime with memoized: 0.000001, profit: 62
----------------------------------
Length: 20
Runtime without memoized: 0.008339, profit: 65
Runtime with memoized: 0.000001, profit: 65
----------------------------------
 */
