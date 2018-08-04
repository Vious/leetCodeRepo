#include <iostream>
#include <algorithm>

using namespace std;

class Solution {
public:
    int divide(int dividend, int divisor) {
        /* long long dividend1 = dividend, divisor1 = divisor;
        long long res = dividend1 / divisor1;
        if (res > __INT_MAX__) {
            return __INT_MAX__;
        }
        return res; */
        if (dividend == 0) return 0;
        if (dividend == divisor) return 1;
        long long dividend1 = labs(dividend), divisor1 = labs(divisor);
        int flag = (dividend > 0) - (divisor > 0);
        long long res = 0;
        cout << dividend1 << " " << divisor1 << endl;
        while (divisor1 <= dividend1) {
            long long tmp = divisor1;
            for (int i = 0; tmp <= dividend1; i++) {
                dividend1 -= tmp;
                res += 1 << i;
                tmp = tmp << 1; 
            }

        }
        if (res >= INT32_MAX && flag == 0) return INT32_MAX;
        else if (res > __INT_MAX__ && flag != 0) return INT32_MIN;

        return flag == 0 ? res : -res;

    }
};


int main(int argc, char const *argv[])
{
    Solution sl;
    int dividend, divisor;
    cin >> dividend;
    cin >> divisor;
    cout << sl.divide(dividend, divisor) << '\n';
    return 0;
}
