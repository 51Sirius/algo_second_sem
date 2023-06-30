#include <iostream>
#include <cstring>

using namespace std;

int main()
{
    int t;
    string code;
    cin >> t;
    int lenght;
    int counter = 0;
    while (cin >> code) {
        int mistake=0;
        char answer[100000];
        lenght = code.length();
        for (int i = 0; i < lenght; i ++)
            if (code[i] == '1')
                mistake ^= i + 1;
        if (mistake)
        {
            code[mistake - 1] ^= '0' ^ '1';
        }
        int info_bit = 0;
        int bit = 1;
        for (int i = 0; i < lenght; i++)
            if (i + 1 == bit)
                bit <<= 1;
            else
                answer[info_bit++] = code[i];
        answer[info_bit] = '\0';
        printf("\n%s", answer);
    }
}