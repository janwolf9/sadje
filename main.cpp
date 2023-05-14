#include <cstdio>
#include <fstream>
#include <iostream>
int main(int argc, char **argv) {
    int maxN = 10000;
    int maxK = 50;
    int maxM = 10000;
    int dp[maxK + 1][maxN + 1];

    int n, k, m, c, a[maxN], r, rw[maxK];
    // Read the input data.
    std::ifstream myFile;
    if (argc > 1) {
        myFile.open(argv[1]);
        if (!myFile.is_open()) {
            return 1;
        }
    } else {
        return 2;
    }
    //FILE *f = (argc > 1) ? fopen(argv[1], "rt") : stdin;
    myFile >> n;
    myFile >> k;
    myFile >> m;

    if (1 > n) {
        return 3;
    }
    if (n > maxN) {
        return 31;
    }
    if (0 > k) {
        return 4;
    }
    if (k > maxK) {
        return 41;
    }
    if (1 > m) {
        return 5;
    }
    if (m > maxM) {
        return 51;
    }

//#ifdef MODULO
//    ok_ = fscanf(f, "%d %d", &n, &k); Assert(ok_ == 2);
//	m = MODULO;
//#else
//    ok_ = fscanf(f, "%d %d %d", &n, &k, &m); Assert(ok_ == 3);
//#endif
//    Assert(1 <= n); Assert(n <= maxN);
//    Assert(0 <= k); Assert(k <= maxK);
//    Assert(1 <= m); Assert(m <= maxM);
    do {
        //c = fgetc(f);
        c = myFile.get();
    } while ((c == '\n' || c == '\r'));//&& c != EOF
    //Assert(c != EOF);
    if (c == EOF) {
        return 6;
    }
    for (int i = 0; i < n; i++) {
        //Assert(c == '0' || c == '1');
        if (c != '1' && c != '0') {
            return 7;
        }
        a[i] = c - '0';
        c = myFile.get();
        //c = fgetc(f);
    }
    while (c == '\n' || c == '\r') {
        c = myFile.get();
    }
    //Assert(c == EOF);
    if (c != EOF) {
        return 61;
    }
    //if (f != stdin) fclose(f);
    myFile.close();
    // Solve the problem.  g[j][i] is the solution of the subproblem
    // where we insert exactly j ones into the string a[0..i-1].
    dp[0][0] = 0;
    for (int i = 1; i <= n; i++) {
        if (i % m == 0) {
            dp[0][i] = dp[0][i - 1] + a[i - 1];
        } else {
            dp[0][i] = dp[0][i - 1];
        }
        //g[0][i] = g[0][i - 1] + (i % m == 0 ? a[i - 1] : 0);
    }
    for (int j = 1; j <= k; j++) {
        int tmp = j / m;
        dp[j][0] = tmp;
        //g[j][0] = j / m;
        for (int i = 1; i <= n; i++) {
            //g[j][i] = g[j - 1][i] + ((i + j) % m == 0 ? 1 : 0);
            if ((i + j) % m == 0) {
                dp[j][i] = dp[j - 1][i] + 1;
            } else {
                dp[j][i] = dp[j - 1][i];
            }
            if ((i + j) % m == 0) {
                c = dp[j][i - 1] + a[i - 1];
            } else {
                c = dp[j][i - 1];
            }
            //c = g[j][i - 1] + ((i + j) % m == 0 ? a[i - 1] : 0);
            if (c < dp[j][i]) {
                dp[j][i] = c;
            }
        }
    }
    //if (false)
    for (int j = 0; j <= k; j++) {
        std::cout << "g[" << j << "] =";
        //printf("g[%d] =", j);
        for (int i = 0; i <= n; i++) {
            std::cout << " " << dp[j][i];
            //printf(" %d", g[j][i]);
        }
        //printf("\n");
        std::cout << std::endl;
    }
    // Find the number of insertions which leads to the best solution.
    r = 0;
    for (int j = 1; j <= k; j++) {
        if (dp[j][n] < dp[r][n]) {
            r = j; /* < finds the minimum number of insertions leading to the best solution, <= finds the maximum */
        }
    }
    int j = r;
    int i = n;
    while (j > 0) {
        //Assert(i >= 0);
        if (i < 0) {
            return 8;
        }
        if ((i + j) % m == 0) {
            if (dp[j][i] == dp[j - 1][i] + 1) {
                rw[--j] = i;
            } else {
                --i;
            }
        } else {
            if (dp[j][i] == dp[j - 1][i]) {
                rw[--j] = i;
            } else {
                --i;
            }
        }

//        if (g[j][i] == g[j - 1][i] + ((i + j) % m == 0 ? 1 : 0)) //i == 0 ||
//            rw[--j] = i;
//        else --i;
    }
    // Output the results.
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
        myOutputFile << " " << rw[j] + j + 1;
        std::cout << " " << rw[j] + j + 1;
    }
    myOutputFile << "\n";
    myOutputFile.close();
    return 0;
}