#include <iostream>
#include <fstream>
#include <cstring>
#include <vector>

using namespace std;

void findInsertedIndices(const std::string& original, const std::string& modified, std::vector<int> &indices) {

    int i = 0;  // Index for the original string
    int j = 0;  // Index for the modified string

    while (i < original.length() && j < modified.length()) {
        if (original[i] == modified[j]) {
            // Characters match, move to the next indices
            i++;
            j++;
        } else {
            // Character was inserted in the modified string
            indices.push_back(j+1);
            j++;
        }
    }

    // Any remaining characters in the modified string are considered inserted
    while (j < modified.length()) {
        indices.push_back(j+1);
        j++;
    }
}

int pickedCount(char buff[], int m){
    int count = 0;
    for (int i = m-1; i < strlen(buff); i+=m) {
        if (buff[i] == '1') count++;
    }
    return count;
}

void printPatternUtil(const string str, char buff[], int i, int j, int n, int k, int m, int &min, char solu[])
{
    if (i == n)
    {
        buff[j] = '\0';
        int picked = pickedCount(buff, m);
        if (picked < min) {
            min = picked;
            strcpy(solu, buff);
            //cout << buff << " " << picked << "\n";
        }
        return;
    }

    if (k <= 0) {
        while (i < n){
            buff[j] = str[i];
            i++;
            j++;
        }
        buff[j] = '\0';
        int picked = pickedCount(buff, m);
        if (picked < min) {
            min = picked;
            strcpy(solu, buff);
            //cout << buff << " " << picked << "\n";
        }
        return;
    }
    // Either put the character
    buff[j] = str[i];
    printPatternUtil(str, buff, i + 1, j + 1, n, k, m, min, solu);

    // Or put 1
    buff[j] = '1';
    //buff[j + 1] = str[i];
    printPatternUtil(str, buff, i, j + 1, n, k-1, m, min, solu);
}

void printPattern(const string& str, int n, int &k, int m, int &min, char solu[])
{
    char buf[n+k+1];
    char buf1[n+k+1];

    buf[0] = str[0];
    printPatternUtil(str, buf, 1, 1, n, k, m, min, solu); //pustimo 0 na zacetku

    buf1[0] = '1';
    printPatternUtil(str, buf1, 0, 1, n, k-1, m, min, solu); //vrinemo 1 na zacetek
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

    vector<int> insertedIndices;
    insertedIndices.reserve(k);
    int min = INT_MAX;
    char solu[n+k+1];
    printPattern(niz, n, k, m, min, solu);

    cout << min << "\n";
    findInsertedIndices(niz, solu, insertedIndices);
    cout << insertedIndices.size();
    for (int &i : insertedIndices){
        cout << " " << i;
    }
    cout << "\n";
    file.close();
    return 0;
}

