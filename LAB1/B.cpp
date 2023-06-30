#include <iostream>
#include <string>

using namespace std;

class String_code {
public:
    int steps;
    string code;
    int ind;
    char current;

    void set_steps() {
        int numb = 0;
        this->ind++;
        int x = (int) this->code[this->ind] - 48;
        while (x <= 9 and x >= 0) {
            numb = numb * 10 + x;
            this->ind++;
            x = (int) this->code[this->ind] - 48;
        }
        if (numb == 0) {
            this->steps = 1;
            return;
        }
        this->steps = numb;
    }
};

int main() {
    int n, m, k;
    string m1, s1;
    auto masha = String_code();
    auto sasha = String_code();
    cin >> n >> m >> k >> m1 >> s1;
    masha.code = m1;
    sasha.code = s1;
    masha.current = masha.code[masha.ind];
    sasha.current = sasha.code[sasha.ind];
    masha.set_steps();
    sasha.set_steps();
    int count = 0;
    while (masha.ind <= n) {
        if (masha.steps < sasha.steps) {
            sasha.steps -= masha.steps;
            if (masha.current != sasha.current) {
                count += masha.steps;
            }
            masha.current = masha.code[masha.ind];
            masha.set_steps();
        } else if (masha.steps > sasha.steps) {
            masha.steps -= sasha.steps;
            if (masha.current != sasha.current) {
                count += sasha.steps;
            }
            sasha.current = sasha.code[sasha.ind];
            sasha.set_steps();
        } else {
            if (masha.current != sasha.current) {
                count += masha.steps;
            }
            masha.current = masha.code[masha.ind];
            masha.set_steps();
            sasha.current = sasha.code[sasha.ind];
            sasha.set_steps();
        }
    }
    if (k > count) {
        cout << "Yes\n";
    } else {
        cout << "No\n";
    }
    return 0;
}


