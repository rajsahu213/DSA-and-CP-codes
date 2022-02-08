#include<bits/stdc++.h>
using namespace std;
int main() {
    int start, n, i, upper, lower, leftdif, rightdif;
    cout << "number of pages : 7";
    n = 7;
    cout << "\nhead value : 50";
    start = 50;
    cout << "\npages values : ";
    vector<int>vec = {176, 79, 34, 60, 92, 11, 41, 114};
    for (int i = 0; i < vec.size(); i++) {
        cout << vec[i] << " ";
    }
    cout << "\n";
    vec.push_back(start);
    cout << "\nlower and upper bound : 0, 199\n";
    lower = 0;
    vec.push_back(lower);
    upper = 199;
    vec.push_back(upper);
    cout << "vector size = " << vec.size() << "\n";
    sort(vec.begin(), vec.end());
    int index = find(vec.begin(), vec.end(), start) - vec.begin();
    cout << "\nindex position :" << index << "\n";
    int sum = 0, left = index - 1, right = index + 1;
    for (i = 0; i <= n + 2; i++) {
        cout << " " << vec[i];
    }
    cout << "\n";
    while (left > 0 && right <= n + 1) {
        leftdif = vec[index] - vec[left];
        rightdif = vec[right] - vec[index];
        if (leftdif < rightdif) {
            index = left;
            left--;
            sum += leftdif;
        }
        else {
            index = right;
            right++;
            sum += rightdif;
        }
    }
    if (left > 0) {
        sum += vec[n + 1] - vec[1];
    }
    if (right <= n) {
        sum += vec[n + 1] - vec[1];
    }
    cout << "\ntotal cost : " << sum << endl;
    return 0;
}