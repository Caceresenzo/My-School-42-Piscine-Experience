# Check, compile, and run

echo "--------- CHECK, COMMPILE AND RUN" $1

echo "---------- MOULINETTE"

norminette -RCheckForbiddenSourceHeader "$1" | cat

echo "---------- GCC"

gcc -Wall -Wextra -Werror "$1" | cat

echo "---------- CHMOD"

chmod +x a.out

echo "---------- EXECUTE"

./a.out
