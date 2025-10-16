#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <string.h>

int main()
{
    // Print current environment variables
    printf("Current Environment Variables:\n");
    printf("$USER: %s\n", getenv("USER"));
    printf("$TERM: %s\n", getenv("TERM"));
    printf("$PATH: %s\n", getenv("PATH"));
    printf("\n");
    
    // Capture env values we want to forward as arguments
    char *arg1 = getenv("USER");
    char *arg2 = getenv("TERM");
    char *arg3 = getenv("PATH");
    
    // Build argv vector for execve: program name + our three args + NULL
    char *script_path = "script.sh";
    char *vectorArg[] = {script_path, arg1, arg2, arg3, NULL};
    
    // Build envp vector: provide a custom variable (minimal environment)
    char *vectorEnv[] = {"OS2025=5ma32zw", NULL};
    
    printf("Executing script.sh with execve()...\n");
    printf("Arguments passed: %s, %s, %s, %s\n", 
           vectorArg[0], vectorArg[1], vectorArg[2], vectorArg[3]);
    printf("Environment variable set: %s\n", vectorEnv[0]);
    printf("\n");
    
    // Execute: on success, this process is replaced by script.sh
    if (execve("./script.sh", vectorArg, vectorEnv) == -1) {
        perror("execve failed");
        return 1;
    }
    
    return 0;
}
