#include <bits/stdc++.h>
using namespace std;

int count(const vector<vector<char>>& a) {
    int counter { 0 };
    for (const auto& row : a) {
        for (char i : row) {
            if (i == '#') {
                counter++;
            }
        }
    }
    return counter;
}


void solve() {
    int gridSize { 0 };
    int numberOfPieces { 0 };
    cin >> gridSize >> numberOfPieces;
    numberOfPieces++;
    vector<vector<vector<char>>> pieces (numberOfPieces, vector<vector<char>> (gridSize, vector<char> (gridSize)) );
    for (int i = 0; i < numberOfPieces; i++) {
        for (int j = 0; j < gridSize; j++) {
            for (int k = 0; k < gridSize; k++) {
                cin >> pieces[i][j][k];
            }
        }
    }
    for (int i = 1; i < numberOfPieces-1; i++) {
        for (int j = i+1; j < numberOfPieces; j++) {
            vector<vector<char>> firstPiece = pieces[i];
            vector<vector<char>> secondPiece = pieces[j];
            int firstCounter = count(firstPiece);
            int secondCounter = count(secondPiece);
            for (int firstRowShift = 0; firstRowShift < 2*gridSize-1; firstRowShift++) {
                for (int firstColumnShift = 0; firstColumnShift < 2*gridSize-1; firstColumnShift++) {
                    for (int secondRowShift = 0; secondRowShift < 2*gridSize-1; secondRowShift++) {
                        for (int secondColumnShift = 0; secondColumnShift < 2*gridSize-1; secondColumnShift++) {
                            vector<vector<char>> simulation (gridSize, vector<char> (gridSize, '.'));
                            for (int row = 0; row < gridSize; row++) {
                                for (int column = 0; column < gridSize; column++) {
                                    if (firstPiece[row][column] == '#' && row-(gridSize-1)+firstRowShift >= 0 && row-(gridSize-1)+firstRowShift < gridSize && column-(gridSize-1)+firstColumnShift >= 0 && column-(gridSize-1)+firstColumnShift < gridSize) {
                                        simulation[row-(gridSize-1)+firstRowShift][column-(gridSize-1)+firstColumnShift] = '#';
                                    }
                                    if (secondPiece[row][column] == '#' && row-(gridSize-1)+secondRowShift >= 0 && row-(gridSize-1)+secondRowShift < gridSize && column-(gridSize-1)+secondColumnShift >= 0 && column-(gridSize-1)+secondColumnShift < gridSize) {
                                        simulation[row-(gridSize-1)+secondRowShift][column-(gridSize-1)+secondColumnShift] = '#';
                                    }
                                }
                            }
                            if (count(simulation) == firstCounter + secondCounter && simulation == pieces[0]) {
                                cout << min(i, j) << " " << max(i, j) << "\n";
                            }
                        }
                    }        
                }
            }
        }
    }    
}

int main() {
    cin.tie(0)->sync_with_stdio(0);
    solve();
}