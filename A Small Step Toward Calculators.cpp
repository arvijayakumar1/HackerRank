#include <bits/stdc++.h>
using namespace std;

int main() {
	char inp[11];
    scanf("%s", inp);
    inp[0] -= '0';
    inp[2] -= '0';
    printf("%d\n", inp[1] == '+' ? inp[0] + inp[2] : inp[0] - inp[2]);
}