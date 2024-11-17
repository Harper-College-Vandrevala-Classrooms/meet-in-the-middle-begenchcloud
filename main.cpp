#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <sstream>

using namespace std;

int main() {
    string filename;
    cout << "Enter the filename: ";
    cin >> filename;

    ifstream file(filename);
    if (!file.is_open()) {
        cerr << "Error: Could not open file." << endl;
        return 1;
    }

    vector<int> data;
    string line;
    string number;
    if (getline(file, line)) {
        stringstream ss(line);
        while (getline(ss, number, ',')) {
            data.push_back(stoi(number));
        }
    }
    file.close();

    if (data.empty()) {
        cerr << "Error: The dataset is empty." << endl;
        return 1;
    }

    size_t n = data.size();
    double median = (n % 2 == 1) ? data[n / 2] : (data[n / 2 - 1] + data[n / 2]) / 2.0;

    cout << "The median of the dataset is " << median << endl;
    return 0;
}
