#include <stdio.h>
#include <unistd.h>

int main()
{
    // F1: fork once → 2 processes
    fork();
    // F2: A && B || C
    // A: parent(true) runs B; A's child(false) skips B but must run C
    // B: parent(true) makes (A&&B) true → skip C; B's child(false) must run C
    // C: final fork in whichever path needs it
    fork() && fork() || fork();
    // F3: final fork → doubles whatever exists
    fork();
    printf("forked\n");
    return 0;
}
