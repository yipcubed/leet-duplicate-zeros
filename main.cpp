#include <algorithm>
#include <cstring>
#include <climits>
#include <functional>
#include <iostream>
#include <map>
#include <queue>
#include <set>
#include <stack>
#include <string>
#include <vector>
#include <sstream>


#include "../utils/VectorUtils.hpp"
#include "../utils/PrintUtils.hpp"

// https://leetcode.com/problems/duplicate-zeros/

// #include "../utils/HeapUtils.hpp"
// #include "../utils/BinarySearch.hpp"
// #include "../utils/TreeUtils.hpp"

using namespace std;

#pragma GCC diagnostic ignored "-Wunknown-pragmas"

// Live coding problems, watch at
// https://www.twitch.tv/yipcubed
// https://www.youtube.com/channel/UCTV_UOPu7EWXvYWsBFxMsSA/videos
//

// makes code faster, but larger. Just for LeetCode fun!
#pragma GCC optimise ("Ofast")

// makes stdin not synced so it is faster. Just for LeetCode fun!
static auto __ __attribute__((unused)) = []() {              // NOLINT
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    return nullptr;
}();

class Solution {
public:
    // 1 0 2 3 ==> 1 0 0 2
    void duplicateZeros(vector<int> &arr) {
        int zeros = 0;
        for (int last = 0; last < arr.size(); ++last) {
            if (arr[last] == 0)
                ++zeros;
        }
        if (zeros == 0) return;
        int back = arr.size() - 1 + zeros;
        int loc = arr.size() - 1;
        while (back >= loc && loc >= 0) {
            if (back < arr.size())
                arr[back] = arr[loc];
            if (arr[loc] == 0) {
                --back;
                if (back < arr.size())
                    arr[back] = 0;
            }
            --back;
            --loc;
        }
    }

};

void test1() {
    vector<int> v1{1,0,2,3,0,4,5,0};

    Solution().duplicateZeros(v1);
    cout << "[1,0,0,2,3,0,0,4] ? \n" <<  v1 << endl;

    vector<int> v2{1,0,2,3,7,0,5,0};

    Solution().duplicateZeros(v2);
    cout << "[1,0,0,2,3,7,0,0] ? \n" <<  v2 << endl;

    vector<int> v3{0,9,0,3,7,0,5,0};

    Solution().duplicateZeros(v3);
    cout << "[0,0,9,0,0,3,7,0] ? \n" <<  v3 << endl;

    // [0,1,7,6,0,2,0,7]
    vector<int> v4{0, 1, 7, 6, 0, 2, 0, 7};
    Solution().duplicateZeros(v4);
    cout << "[0,0,1,7,6,0,0,2] ? \n" << v4 << endl;
}

void test2() {

}

void test3() {

}