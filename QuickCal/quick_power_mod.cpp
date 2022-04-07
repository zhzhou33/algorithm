/*
 * @Author: zhzhou33
 * @Date: 2022-04-02 17:03:43
 * @LastEditors: zhzhou33
 * @LastEditTime: 2022-04-02 17:05:02
 */
#include <iostream>
using namespace std;

long long quick_power_mod(int a, int b, int m)
{
    long long res = 1;
    while (b)
    {
        if (b & 1)
            res = (res * a) % m;
        a  = 
    }
}