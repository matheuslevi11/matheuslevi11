#include <bits/stdc++.h>

using namespace std;

int isFinalSequence(queue<long long int> q){
    if (q.size() < 3) return 0;
    if (q.front() != 4) return 0;
    q.pop();
    if (q.front() != 2) return 0;
    q.pop();
    if (q.front() != 1) return 0;
    return 1;
}

long long int ulam(long long int a) {
    queue<long long int> latest;
    long long int x = a;
    long long int size = 0;

    while(!isFinalSequence(latest))
    {
        if (x % 2 == 0) x = x/2;
        else x = 3*x + 1;
        latest.push(x);
        if(latest.size() > 3) latest.pop();
        size++;
    }
    return size;
}

int main() {
    long long int sum = 0;
    long long int biggest = 0;
    long long int index = 0;

    for(long long int i = 1; i <= 65535; i++) {
        long long int size = ulam(i);
        if (size > biggest){
            biggest = size;
            index = i;
        }
        sum += size;
    }
    printf("A média das sequências foi: %lli\n", sum/65535);
    printf("A maior sequência foi: %lli e foi gerada pelo número %lli\n", biggest, index);
}