#include <stdio.h>
#include <stdint.h>

int main() {
    uint64_t testing = 1;
    for (uint64_t i = 1; i < 5; ++i) {
        testing *=20;
    }
    printf("%llu", testing);
    return 0;
}
