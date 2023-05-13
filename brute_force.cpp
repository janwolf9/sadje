#include <iostream>
#include <fstream>
#include <string>

using namespace std;

void printPatternUtil(const string str, char buff[], int i, int j, int n, int k)
{
    if (i == n)
    {
        buff[j] = '\0';
        cout << buff << endl;
        return;
    }

    if (k <= 0) {
        while (j < n){
            buff[j] = str[i];
            i++;
            j++;
        }
        buff[j] = '\0';
        cout << buff << endl;
        return;
    }

    // Either put the character
    buff[j] = str[i];
    printPatternUtil(str, buff, i + 1, j + 1, n, k);

    // Or put 1
    buff[j] = '1';
    //buff[j + 1] = str[i];
    k--;
    printPatternUtil(str, buff, i + 1, j + 1, n, k);
}

void printPattern(const string str, int n, int &k)
{
    char buf[2 * n];
    char buf1[2 * n];

    buf[0] = str[0];
    printPatternUtil(str, buf, 1, 1, n, k); //pustimo 0 na zacetku

    buf1[0] = '1';
    printPatternUtil(str, buf1, 0, 1, n, k-1); //vrinemo 1 na zacetek
}

int main(int argc, char* argv[]) {

    if (argc < 2) {
        std::cout << "Please provide a file name as a command line argument.\n";
        return 1;
    }

    std::ifstream file(argv[1]);
    std::string line;

    if (!file.is_open()) {
        std::cout << "Failed to open file" << "\n";
        return 1;
    }

    int n, k, m; // n-jabolk, k-vrinjenih, m-to pobira
    string niz;
    file >> n >> k >> m;
    std::getline(file, line);
    file >> niz; // 0 - hruska, 1 - jabolko
    printPattern(niz, n,k);
    return 0;
}

