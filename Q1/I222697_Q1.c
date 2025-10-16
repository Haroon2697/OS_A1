#include <stdio.h>
#include <unistd.h>

int main()
{
    // fork A: parent gets >0 (true) → enters if; child gets 0 (false) → else
    if (fork()) {
        // In parent path of A: evaluate !fork B
        //  - parent of B: fork()>0 so !true == false → else branch
        //  - child  of B: fork()==0 so !false == true → inner if branch
        if (!fork()) {
            // In B's child: fork C creates another process; both print "1 "
            fork();
            printf("1 ");
        }
        else {
            // In B's parent: prints "2 "
            printf("2 ");
        }
    }
    else {
        // In A's child: prints "3 "
        printf("3 ");
    }
    printf("4 ");
    return 0;
}
