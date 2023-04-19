#include <iostream>
#include <vector>
#include <string>
#include <map>
#include <algorithm>
#include <math.h>
#include <queue>
using namespace std;

vector<string> split_string(string);

// Complete the minimumSwaps function below.
int minimumSwaps(vector<int> arr) {
    int cnt = 0;
    vector <bool> visited(arr.size());
    for (int i=0; i<arr.size(); i++) {
        if(arr[i]!=i+1 && !visited[arr[i]]) {
            int cur = arr[i];
            while(arr[cur-1]!=arr[i]) {
                visited[arr[cur-1]] = true;
                cnt++;
                cur = arr[cur-1];
            }
        }
        visited[arr[i]] = true;
    }
    return cnt;

}

int main()
{
 
    int n;
    cin >> n;
    vector<int> arr;

    for (int i = 0; i < n; i++) {
        int arr_item; cin >> arr_item;

        arr.push_back(arr_item);
    }

    int res = minimumSwaps(arr);

    cout << res << "\n";

    return 0;
}