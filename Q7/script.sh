#!/bin/bash

echo "Script executed successfully!"
echo "Arguments received:"
echo "Argument 1 (script name): $0"
echo "Argument 2 (USER): $1"
echo "Argument 3 (TERM): $2"
echo "Argument 4 (PATH): $3"
echo ""

echo "Current environment variables in this process:"
echo "USER: $USER"
echo "TERM: $TERM"
echo "PATH: $PATH"
echo "OS2025: $OS2025"
echo ""

echo "All environment variables:"
env
