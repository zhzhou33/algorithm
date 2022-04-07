/*
 * @Author: zhzhou33
 * @Date: 2022-04-02 16:54:13
 * @LastEditors: zhzhou33
 * @LastEditTime: 2022-04-02 17:02:44
 */
#include <iostream>

using namespace std;
/*
    每次循环 b/2,即 a 的指数减半,则 a = a^2
    当b为奇数时除2会丢失当前位,因此需要做处理
*/
long long quick_power(int a, int b)
{
    long long res = 1;
    while (b)
    {
        //右移会丢失
        if (b & 1)
            res *= a;
        a *= a;
        b >>= 1;
    }
    return res;
}

int main()
{
    cout << quick_power(2, 5) << endl;
}
