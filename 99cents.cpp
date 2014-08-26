#include <iostream>

int coins[] = { 50, 25, 10, 5, 1 };
int NUM_COINS = 5;

void print_coins(int *arr) {
    int sum = 0;
    for (int i = 0; i < NUM_COINS; i++) {
        std::cout << coins[i] << " = " << arr[i] << " / ";
        sum += coins[i] * arr[i];
    }

    std::cout << " total = " << sum << std::endl;
}

int total_coins(int *arr) {
    int sum = 0;
    for (int i = 0; i < NUM_COINS; i++) {
        sum += arr[i] * coins[i];
    }
    
    return sum;
}

int num_coins(int *arr[]) {
    int sum[NUM_COINS];
    int s = 0;

    for (int i = 0; i < NUM_COINS; i++) {
        sum[i] = 0;
    }

    for (int i = 1; i <= 99; i++) {
        for (int j = 0; j < NUM_COINS; j++) {
            sum[j] += arr[i][j];
        }
    }

    for (int i = 0; i < NUM_COINS; i++) {
        std::cout << coins[i] << " = " << sum[i] << " / ";
        s += sum[i];
    }
    std::cout << "total = " << s << std::endl;

    return s;
}

void fill(int *arr, int change) {
    int i = 0;

    std::cout << "adding " << change << std::endl;

    if (total_coins(arr) + change > 100) {
        std::cerr << "add error " << total_coins(arr) << " + " << change << std::endl;
        return;
    }

    while (change > 0) {
        if (change >= coins[i]) {
            arr[i]++;
            change -= coins[i];
        } else {
            i++;
        }
        print_coins(arr);
    }
}

void remove(int *arr, int change) {
    int i = NUM_COINS - 1;
    
    std::cout << "removing " << change << std::endl;

    if (total_coins(arr) - change < 0) {
        std::cerr << "remove error " << total_coins(arr) << " - " << change << std::endl;
        return;
    }

    while (change > 0) {
        if (change >= coins[i]) {
            if (arr[i] == 0) {
                int j = i;
                while (arr[j] == 0)
                    j--;
                arr[j]--;
                fill(arr, coins[j] - coins[i]);
            } else {
                arr[i]--;
            }
            change -= coins[i];
        } else {
            i++;
        }
        print_coins(arr);
    }
}

void zero_coins(int *arr) {
    for (int i = 0; i < NUM_COINS; i++) {
        arr[i] = 0;
    }
}

void copy_coins(int *src, int *dst) {
    for (int i = 0; i < NUM_COINS; i++) {
        dst[i] = src[i];
    }
}

int main() {
    int **change = new int*[100];
    for (int i = 0; i < 100; i++)
        change[i] = new int[NUM_COINS];


    std::cout << "=== " << 99 << " ===" << std::endl;
    zero_coins(change[99]);
    fill(change[99], 99);

    for (int i = 98; i > 0; i--) {
        std::cout << "=== " << i << " ===" << std::endl;
        copy_coins(change[i+1], change[i]);
        remove(change[i], 1);
    }

    num_coins(change);

    return 0;
}
