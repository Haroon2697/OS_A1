# Expected Program Outputs

## Question 1: Process Tree Analysis
**Program**: `I222697_Q1.c`
**Expected Output** (order may vary):
```
3 4 2 4 1 4 4
```
**Explanation**: 
- Process 1 (Parent): Prints "2 4"
- Process 2 (First Child): Prints "3 4" 
- Process 3 (Second Child): Prints "1 4"
- Process 4 (Third Child): Prints "4"

## Question 2: Complex Fork with Logical Operators
**Program**: `I222697_Q2.c`
**Expected Output** (order may vary):
```
2 2 2 2 2 2 2
```
**Explanation**: Multiple processes print "2" due to complex logical operators

## Question 3: Dry Run Analysis
**Program**: `I222697_Q3.c`
**Expected Output** (order may vary):
```
forked
forked
forked
forked
forked
forked
```
**Explanation**: 6 processes created, each prints "forked"

## Question 4: Hello World from Specific Process
**Program**: `I222697_Q4.c`
**Expected Output**:
```
Process 1 (Parent) - PID: 1000
Process 2 (First Child) - PID: 1001
Process 4 (Second Child) - PID: 1003
Process 3 (Grandchild) - PID: 1002
Hello World!
```
**Explanation**: Only the grandchild process prints "Hello World!"

## Question 5: Hierarchical Process Tree
**Program**: `I222697_Q5.c`
**Expected Output**:
```
Root P - PID: 1000
Left Child P - PID: 1001
C2 (leaf) - PID: 1002
Left Child P (leaf) - PID: 1003
C1 - PID: 1004
Left Child C1 (leaf) - PID: 1005
C3 (leaf) - PID: 1006
Left Child P (leaf) terminating
Left Child C1 (leaf) terminating
C3 (leaf) terminating
C1 terminating
Left Child P terminating
C2 (leaf) terminating
Root P terminating
```
**Explanation**: Shows proper process hierarchy and termination order

## Question 6: Fork and execvp
**Program**: `I222697_Q6.c`
**Expected Output**:
```
Parent process - PID: 1000
First child process - PID: 1001
Second child process - PID: 1002
Executing 'ls -l' command...
[Output of ls -l command - file listing]
First child terminating
child successful
Parent process terminating
```
**Explanation**: Uses execvp() to execute ls -l command

## Question 7: execve() with Environment Variables
**Program**: `I222697_Q7.c`
**Expected Output**:
```
Current Environment Variables:
$USER: [current user]
$TERM: [terminal type]
$PATH: [current path]

Executing script.sh with execve()...
Arguments passed: script.sh, [user], [term], [path]
Environment variable set: OS2025=5ma32zw

Script executed successfully!
Arguments received:
Argument 1 (script name): ./script.sh
Argument 2 (USER): [user]
Argument 3 (TERM): [term]
Argument 4 (PATH): [path]

Current environment variables in this process:
USER: [user]
TERM: [term]
PATH: [path]
OS2025: 5ma32zw

[All environment variables from env command]
```
**Explanation**: Demonstrates environment variable manipulation and script execution

## Key Points to Remember

1. **Process IDs**: Each process gets a unique PID
2. **Fork Return Values**: 
   - Parent gets child's PID (> 0)
   - Child gets 0
3. **Output Order**: May vary due to process scheduling
4. **System Calls**: fork(), execvp(), execve(), wait() are Unix/Linux specific
5. **Process Hierarchy**: Parent-child relationships are clearly shown
6. **Termination Order**: Children should terminate before parents (Q5)

## Testing on Different Systems

- **Linux/Unix**: Full functionality
- **macOS**: Full functionality  
- **Windows**: Not supported (use WSL or VM)
- **WSL**: Full functionality
- **Docker**: Full functionality with Linux container
