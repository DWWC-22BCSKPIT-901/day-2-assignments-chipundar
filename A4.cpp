#include <iostream>
#include <vector>
#include <unordered_map>
#include <algorithm>
using namespace std;

int maxHappyGroups(int batchSize, vector<int>& groups) {
    unordered_map<int, int> remainderCount;
    int happyGroups = 0;
    
    for (int groupSize : groups) {
        remainderCount[groupSize % batchSize]++;
    }

    happyGroups += remainderCount[0];
    remainderCount[0] = 0;

    for (int i = 1; i < (batchSize + 1) / 2; ++i) {
        int complement = batchSize - i;
        happyGroups += min(remainderCount[i], remainderCount[complement]);
    }

    if (batchSize % 2 == 0) {
        happyGroups += remainderCount[batchSize / 2] / 2;
    }

    return happyGroups;
}

int main() {
    int batchSize;
    cout << "Enter the batch size: ";
    cin >> batchSize;
    
    int n;
    cout << "Enter the number of groups: ";
    cin >> n;

    vector<int> groups(n);
    cout << "Enter the group sizes: ";
    for (int i = 0; i < n; ++i) {
        cin >> groups[i];
    }

    int result = maxHappyGroups(batchSize, groups);
    cout << "Maximum number of happy groups: " << result << endl;

    return 0;
}
