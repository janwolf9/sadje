#include <cstdio>
#include <fstream>
#include <iostream>

int main(int argc, char **argv) {
    int maxN = 10000;
    int maxK = 50;
    int maxM = 10000;

    int dp[maxK + 1][maxN + 1];
    dp[0][0] = 0;

    int n, k, m;
    int c, r;
    int input[maxN];
    int indices[maxK];

    std::ifstream myFile;
    if (argc > 1) {
        myFile.open(argv[1]);
        if (!myFile.is_open()) {
            return 1;
        }
    } else {
        return 2;
    }

    myFile >> n >> k >> m;

    if (1 > n || n > maxN) {
        return 3;
    }
    if (0 > k || k > maxK) {
        return 4;
    }
    if (1 > m || m > maxM) {
        return 5;
    }

    int pos = 0;
    do{
        c = myFile.get();
        if (c == '1' || c == '0') {
            input[pos] = c - '0';
            pos++;
        }

    }while(c != EOF);

    myFile.close();

    for (int i = 1; i <= n; i++) {
        if (i % m == 0) {
            dp[0][i] = dp[0][i - 1] + input[i - 1];
        } else {
            dp[0][i] = dp[0][i - 1];
        }
    }

    for (int j = 1; j <= k; j++) {
        int tmp = j / m;
        dp[j][0] = tmp;
        for (int i = 1; i <= n; i++) {
            if ((i + j) % m == 0) {
                dp[j][i] = dp[j - 1][i] + 1;
                c = dp[j][i - 1] + input[i - 1];
            } else {
                dp[j][i] = dp[j - 1][i];
                c = dp[j][i - 1];
            }

            if (c < dp[j][i]) {
                dp[j][i] = c;
            }
        }
    }

    r = 0;
    for (int j = 1; j <= k; j++) {
        if (dp[j][n] < dp[r][n]) {
            r = j;
        }
    }

    int j = r;
    int i = n;
    while (j > 0) {

        if (i < 0) {
            return 8;
        }

        if ((i + j) % m == 0) {
            if (dp[j][i] == dp[j - 1][i] + 1) {
                indices[--j] = i;
            } else {
                --i;
            }
        } else {
            if (dp[j][i] == dp[j - 1][i]) {
                indices[--j] = i;
            } else {
                --i;
            }
        }
    }

    std::ofstream myOutputFile;
    if (argc > 2) {
        myOutputFile.open(argv[2]);
        if (!myOutputFile.is_open()) {
            return 11;
        }
    } else {
        return 21;
    }

    std::cout << dp[r][n] << "\n" << r;
    myOutputFile << dp[r][n] << "\n" << r;

    for (j = 0; j < r; j++) {
        myOutputFile << " " << indices[j] + j + 1;
        std::cout << " " << indices[j] + j + 1;
    }

    myOutputFile << "\n";
    myOutputFile.close();
    return 0;
}