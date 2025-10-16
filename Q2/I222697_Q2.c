#include <stdio.h>
#include <unistd.h>

int main()
{
    // Outer: A && !B
    // A: fork() → parent (true) continues to !B; child (false) skips inner block
    if (fork() && (!fork())) {
        // Inner: C || D
        // C: fork() → parent (true) short-circuits, runs body; child (false) must eval D
        // D: fork() → parent (true) runs body; child (false) skips body
        if (fork() || fork()) {
            // Body: another fork E; both parent and child proceed
            fork();
        }
    }
    printf("2 ");
    return 0;
}
