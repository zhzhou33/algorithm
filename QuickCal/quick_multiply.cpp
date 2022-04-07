/*
 * @Author: zhzhou33
 * @Date: 2022-04-02 16:26:48
 * @LastEditors: zhzhou33
 * @LastEditTime: 2022-04-02 16:49:10
 */
#include <iostream>
using namespace std;

/*
    14 = 1110
    20 * 14 = 20*2^3*1 + 20*2^2*1 + 20*2^1*1 + 20*2^0*0
*/

// 两数相乘,每次 a*2 b/2,当b为奇数时除2会丢失当前位,因此需要做处理
long long quickMultiply(int a, int b)
{
    long long res = 0;
    // 利用 b 的二进制
    while (b > 0)
    {
        // 如果当前二进位为 1
        if (b & 1)
            res += a;
        b >>= 1;
        // 每次将 b 右移位,同时 a 左移位
        a <<= 1;
    }
    return res;
}

int main()
{
    cout << quickMultiply(20, 15) << endl;
    return 0;
}