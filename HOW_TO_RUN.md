# How to Run the Operating Systems Assignment Programs



### Compilation
```bash
# Navigate to the assignment directory
cd "Assignment 1"

# Compile all programs
for dir in Q1 Q2 Q3 Q4 Q5 Q6 Q7; do
    echo "Compiling $dir..."
    gcc -o $dir/I222697_${dir#Q}.exe $dir/I222697_${dir#Q}.c
done

# Make script executable (for Q7)
chmod +x Q7/script.sh
```

### Running the Programs

#### Question 1: Process Tree Analysis
```bash
cd Q1
./I222697_Q1.exe
```
**Expected Output**: Various combinations of "1", "2", "3", "4" printed by different processes

#### Question 2: Complex Fork with Logical Operators
```bash
cd Q2
./I222697_Q2.exe
```
**Expected Output**: Multiple "2" printed by different processes

#### Question 3: Dry Run Analysis
```bash
cd Q3
./I222697_Q3.exe
```
**Expected Output**: Multiple "forked" printed by different processes

#### Question 4: Hello World from Specific Process
```bash
cd Q4
./I222697_Q4.exe
```
**Expected Output**: Process IDs and "Hello World!" from the grandchild process

#### Question 5: Hierarchical Process Tree
```bash
cd Q5
./I222697_Q5.exe
```
**Expected Output**: Process hierarchy with proper termination order

#### Question 6: Fork and execvp
```bash
cd Q6
./I222697_Q6.exe
```
**Expected Output**: Process IDs and file listing using `ls -l` command

#### Question 7: execve() with Environment Variables
```bash
cd Q7
./I222697_Q7.exe
```
**Expected Output**: Environment variables and script execution

## Option 2: Windows Subsystem for Linux (WSL)

### Installation
1. Install WSL2 on Windows
2. Install Ubuntu or another Linux distribution
3. Install GCC: `sudo apt update && sudo apt install gcc`

### Running
```bash
# In WSL terminal
cd /mnt/d/uni/OS/Assignment\ 1/
# Follow the Linux instructions above
```

## Option 3: Virtual Machine

### Using VirtualBox/VMware
1. Install Ubuntu or CentOS in a virtual machine
2. Copy the assignment files to the VM
3. Follow the Linux instructions

## Option 4: Docker Container

### Create Dockerfile
```dockerfile
FROM ubuntu:20.04
RUN apt-get update && apt-get install -y gcc
WORKDIR /app
COPY . .
RUN for dir in Q1 Q2 Q3 Q4 Q5 Q6 Q7; do \
        gcc -o $dir/I222697_${dir#Q}.exe $dir/I222697_${dir#Q}.c; \
    done
RUN chmod +x Q7/script.sh
```

### Build and Run
```bash
docker build -t os-assignment .
docker run -it os-assignment
```

## Option 5: Online Linux Environment

### Using Online IDEs
- **Replit**: Upload files and run
- **CodeSandbox**: Use Linux environment
- **GitHub Codespaces**: Create a Linux environment

## Understanding the Output

### Process IDs
- Each process gets a unique Process ID (PID)
- Parent processes get child PIDs as return values from `fork()`
- Child processes get 0 as return value from `fork()`

### Process Trees
- Visual representation of parent-child relationships
- Shows which process creates which child
- Demonstrates process hierarchy

### Expected Behavior
- **Q1-Q3**: Show process creation and output order
- **Q4**: Only grandchild prints "Hello World"
- **Q5**: Children terminate before parents
- **Q6**: Uses `execvp()` to run system commands
- **Q7**: Demonstrates environment variable manipulation

## Troubleshooting

### Common Issues
1. **"fork not declared"**: You're on Windows - use Linux/WSL
2. **"Permission denied"**: Run `chmod +x filename` to make executable
3. **"No such file"**: Check file paths and current directory
4. **"execvp failed"**: Check if `ls` command is available

### Debugging
- Add `printf` statements to track execution flow
- Use `getpid()` to identify which process is running
- Check return values of system calls

## Submission
1. Test all programs on a Linux system
2. Create zip file: `I222697_SECTION.zip`
3. Include all source files and documentation
4. Be prepared for viva/evaluation
