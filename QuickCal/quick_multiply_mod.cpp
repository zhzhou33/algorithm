/*
 * @Author: zhzhou33
 * @Date: 2022-04-02 16:49:53
 * @LastEditors: zhzhou33
 * @LastEditTime: 2022-04-02 16:53:50
 */
#include <iostream>
using namespace std;

int quick_multiply_mod(int a, int b, int m)
{
    long long res = 0;

    while (b)
    {
        if (b & 1)
            res = (res + a) % m;
        b >>= 1;
        a <<= 1;
    }
    return res;
}

int main(int argc, char const *argv[])
{
    cout << quick_multiply_mod(2, 5, 3);
    return 0;
}
