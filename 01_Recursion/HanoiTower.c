#include <stdio.h>

void HanoiTower(int num, char from, char by, char to) {
    if(num == 1) {
        printf("%c -> %c\n", from, to);
    } else {
        HanoiTower(num-1, from, to, by);
        printf("%c -> %c\n", from, to);
        HanoiTower(num-1, by, from, to);
    }
}

int main() {
    HanoiTower(5,'A','B','C');
    return 0;
}