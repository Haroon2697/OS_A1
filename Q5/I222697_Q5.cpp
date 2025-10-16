#include <iostream>
#include <unistd.h>
#include <sys/wait.h>

using namespace std;

int main()
{
    pid_t pid1, pid2, pid3, pid4, pid5;

    cout << "Root P - PID: " << getpid() << "\n";

    // First fork: Root creates Left P
    pid1 = fork();

    if (pid1 == 0) {
        // Left P
        cout << "Left Child P - PID: " << getpid() << "\n";

        // Second fork: Left P creates its left leaf
        pid2 = fork();

        if (pid2 == 0) {
            // Left leaf under Left P
            cout << "Left Child P (leaf) - PID: " << getpid() << "\n";
            cout << "Left Child P (leaf) terminating\n";
            return 0;
        } else {
            // Third fork: Left P creates C1
            pid3 = fork();

            if (pid3 == 0) {
                // C1
                cout << "C1 - PID: " << getpid() << "\n";

                // Fourth fork: C1 creates its left leaf
                pid4 = fork();

                if (pid4 == 0) {
                    cout << "Left Child C1 (leaf) - PID: " << getpid() << "\n";
                    cout << "Left Child C1 (leaf) terminating\n";
                    return 0;
                } else {
                    // Fifth fork: C1 creates C3 (leaf)
                    pid5 = fork();

                    if (pid5 == 0) {
                        cout << "C3 (leaf) - PID: " << getpid() << "\n";
                        cout << "C3 (leaf) terminating\n";
                        return 0;
                    } else {
                        // C1 waits for its children, then exits
                        wait(nullptr);
                        wait(nullptr);
                        cout << "C1 terminating\n";
                        return 0;
                    }
                }
            } else {
                // Left P waits for its leaf and C1, then exits
                wait(nullptr);
                wait(nullptr);
                cout << "Left Child P terminating\n";
                return 0;
            }
        }
    } else {
        // Sixth fork: Root creates C2 (leaf)
        pid2 = fork();

        if (pid2 == 0) {
            cout << "C2 (leaf) - PID: " << getpid() << "\n";
            cout << "C2 (leaf) terminating\n";
            return 0;
        } else {
            // Root waits for Left P and C2, then exits
            wait(nullptr);
            wait(nullptr);
            cout << "Root P terminating\n";
            return 0;
        }
    }
}
