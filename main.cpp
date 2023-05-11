#include <iostream>
#include <vector>
#include <algorithm>
#include <fstream>

using namespace std;

int main() {
    int n, k, m;

    std::ifstream inputFile("input1.txt");

    inputFile >> n >> k >> m;

    string s;
    inputFile >> s;

    vector<int> appleIndices; // shranjujemo indekse vrinjenih jabolk
    int minApplesPicked = n; // najmanjše število jabolk, ki jih Ivo pobere

    // poskusimo vrinjati dodatna jabolka na vsak možen način
    for (int i = 0; i <= n; i++) {
        vector<int> apples; // shranjujemo indekse jabolk
        int applesPicked = 0; // število pobranih jabolk

        // izračunamo število pobranih jabolk, če vrinemo dodatna jabolka
        for (int j = 0; j < n; j++) {
            if (j == i) { // vrinemo dodatna jabolka
                for (int l = 0; l < appleIndices.size(); l++) {
                    apples.push_back(appleIndices[l]);
                }
                for (int l = 0; l < m; l++) {
                    apples.push_back(j+l);
                }
                j += m - 1; // preskočimo dodana jabolka
            } else if (s[j] == '1') { // pobrano jabolko
                apples.push_back(j);
                applesPicked++;
            }
        }

        // če je bilo pobranih manj jabolk, kot smo jih doslej našli, shranimo indekse vrinjenih jabolk
        if (applesPicked < minApplesPicked) {
            minApplesPicked = applesPicked;
            appleIndices.clear();
            for (int j = 0; j < m; j++) {
                appleIndices.push_back(i+j);
            }
        }
    }

    // izpišemo rešitev
    cout << minApplesPicked << endl;
    cout << appleIndices.size() << " ";
    for (int i = 0; i < appleIndices.size(); i++) {
        cout << appleIndices[i] << " ";
    }
    cout << endl;

    return 0;
}
