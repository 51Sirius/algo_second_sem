#include <iostream>
#include <vector>

struct Group {
    std::vector<std::pair<int, int>> students;
    int count_students;
    int sm;
    explicit Group() : sm(0), count_students(0) {}
};

unsigned int hash1(int key, int size) {
    return key%size;
}

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    std::cout.tie(nullptr);
    int M, Q;
    std::cin >> M >> Q;
    M++;
    Group groups[M];
    for (int i = 0; i < Q; ++i) {
        char c;
        std::cin >> c;
        int group, isu, p;
        if (c == '+') {
            std::cin >> group >> isu >> p;
            unsigned int ind = hash1(group, M);
            std::pair<int, int> a = {isu, p};
            Group& curr_group = groups[ind];
            curr_group.sm += p;
            curr_group.count_students++;
            curr_group.students.emplace_back(a);
        }
        else if (c == '-') {
            std::cin >> group >> isu;
            unsigned int ind = hash1(group,M );
            Group& curr_group = groups[ind];
            for (auto& student : curr_group.students) {
                if (student.first == isu) {
                    curr_group.sm -= student.second;
                    curr_group.count_students--;
                    student.second = student.first = 0;
                    break;
                }
            }
        }
        else if (c == 'a') {
            std::cin >> group;
            unsigned int ind = hash1(group, M);
            const Group& curr_group = groups[ind];
            if (curr_group.count_students > 0) {
                std::cout << curr_group.sm / curr_group.count_students << '\n';
            } else {
                std::cout << "0\n";
            }
        }
        if (c == 'm') {
            std::cin >> group;
            int mx = 0;
            for (auto stud: groups[group].students) {
                mx =std::max(mx, stud.second);
            }
            std::cout << mx << "\n";
        }
    }

    return 0;
}
