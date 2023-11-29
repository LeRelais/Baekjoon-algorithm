#include <iostream>
#include <algorithm>
#include <vector>
#include <map>

using namespace std;

int n;
vector<int> numbersa;
vector<int> coordinates;

int main() {
    cin >> n;

    int coordinate;

    for (int i = 0; i < n; i++) {
        cin >> coordinate;
        numbersa.push_back(coordinate);
        coordinates.push_back(coordinate);
    }

    sort(coordinates.begin(), coordinates.end());
    coordinates.erase(unique(coordinates.begin(), coordinates.end()), coordinates.end());

    /* unique sort Ȯ�ο� */
    //for(int j = 0; j < coordinates.size(); j++){
    //    cout << coordinates[j] << endl;
    //}

    /* worst case������ 1000000 * 1000000 �̶� �ð� �ʰ� */
    // for(int i = 0; i < n; i++){
    //     int res = 0;
    //     for(int j = 0; j < coordinates.size(); j++){
    //         if(numbersa[i] > coordinates[j])
    //             res++;
    //     }
    //     cout << res << ' ';
    // }

    for (int i = 0; i < n; i++) {
        cout << lower_bound(coordinates.begin(), coordinates.end(), numbersa[i]) - coordinates.begin() << ' ';
    }
    return 0;
}