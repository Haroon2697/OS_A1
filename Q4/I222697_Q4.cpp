#include <iostream>
#include <unistd.h>
#include <sys/wait.h>

using namespace std;

int main()
{
    pid_t pid1, pid2, pid3;

    cout << "Process 1 (Parent) - PID: " << getpid() << "\n";

    // First fork: parent creates Process 2; parent will wait later, child continues
    pid1 = fork();

    if (pid1 == 0) {
        // Child process (Process 2)
        cout << "Process 2 (First Child) - PID: " << getpid() << "\n";

        // Second fork: Process 2 creates Grandchild (Process 3)
        pid2 = fork();

        if (pid2 == 0) {
            // Grandchild (Process 3) — prints the greeting
            cout << "Process 3 (Grandchild) - PID: " << getpid() << "\n";
            cout << "Hello World!\n";
        } else {
            // Process 2 waits for its child (Process 3)
            wait(nullptr);
        }
    } else {
        // Parent process (Process 1)
        // Third fork: parent creates Process 4 (second child)
        pid3 = fork();

        if (pid3 == 0) {
            // Process 4 (Second Child)
            cout << "Process 4 (Second Child) - PID: " << getpid() << "\n";
        } else {
            // Parent waits for Process 2 and Process 4 to finish
            wait(nullptr);
            wait(nullptr);
        }
    }

    return 0;
}
