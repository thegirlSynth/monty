# C - Stacks, Queues - LIFO, FIFO
## Monty project
### The Monty language
Monty 0.98 is a scripting language that is first compiled into Monty byte codes (Just like Python). 
It relies on a unique stack, with specific instructions to manipulate it. 

The goal of this project is to create an interpreter for Monty ByteCodes files.
### Monty byte code files
Files containing Monty byte codes usually have the `.m` extension. Most of the industry uses this standard but it is not required by the specification of the language. 
There is not more than one instruction per line. 

There can be any number of spaces before or after the opcode and its argument:
```
thegirlsynth:/monty# cat -e bytecodes/000.m
push 0$
push 1$
push 2$
  push 3$
                   pall    $
push 4$
    push 5    $
      push    6        $
pall$
thegirlsynth:/monty#
```

Monty byte code files can contain blank lines (empty or made of spaces only, and any additional text after the opcode or its required argument is not taken into account:
```
thegirlsynth:/monty# cat -e bytecodes/001.m
push 0 Push 0 onto the stack$
push 1 Push 1 onto the stack$
$
push 2$
  push 3$
                   pall    $
$
$
                           $
push 4$
$
    push 5    $
      push    6        $
$
pall This is the end of our program. Monty is awesome!$
thegirlsynth:/monty#
```

## The Monty program
* Usage: `monty file`
  * where `file` is the path to the file containing Monty byte code
  
* If the user does not give any file or more than one argument to the program, the error message, `USAGE: monty file` is printed, followed by a newline, and the program exits with the status `EXIT_FAILURE`

* If, for any reason, it’s not possible to open the file, the error message `Error: Can't open file <file>` is printed, followed by a new line, and the program exits with the status `EXIT_FAILURE`
  * where `<file>` is the name of the file

* If the file contains an invalid instruction, the error message `L<line_number>: unknown instruction <opcode>` is printed, followed by a new line, and the program exits with the status `EXIT_FAILURE`
  * where `<line_number>` is the line number where the instruction appears.
  * Line numbers always start at 1

* The monty program runs the bytecodes line by line and stops if either:
  * it executed properly every line of the file
  * it finds an error in the file
  * an error occured


## Compilation & Output
The code will be compiled this way:
```
$ gcc -Wall -Werror -Wextra -pedantic -std=c89 *.c -o monty
```
Outputs are printed on `stdout` and error messages are printed on `stderr`.

### Allowed Opcodes
* `push` - pushes an element to top of the stack.
  * Usage: `push <int>`
    * where `<int>` is an integer
  * if `<int>` is not an integer or if there is no argument given to push, the error message `L<line_number>: usage: push integer` is printed, followed by a new line, and the program exits with the status `EXIT_FAILURE`
  
* `pall` - prints all the values on the stack, starting from the top of the stack.
  * Usage `pall`
  * If the stack is empty, nothing is printed.
  
* `pint` - prints the value at the top of the stack, followed by a new line.
  * Usage: `pint`
  * If the stack is empty, the error message `L<line_number>: can't pint, stack empty` is printed, followed by a new line, and the program exits with the status `EXIT_FAILURE`
  
* `pop` -  removes the top element of the stack.
  * Usage: `pop`
  * If the stack is empty, the error message `L<line_number>: can't pop an empty stack` is printed, followed by a new line, and the program exits with the status `EXIT_FAILURE`
  
* `swap` - swaps the top two elements of the stack.
  * Usage: `swap`
  * If the stack contains less than two elements, the error message `L<line_number>: can't swap, stack too short` is printed, followed by a new line, and the program exits with the status `EXIT_FAILURE`

### Example Outputs:
```
thegirlsynth:/monty# cat -e bytecodes/00.m
push 1 to the stack$
push 2$
push 3$
pall$
push 4$
push 5$
pint$
pop$
pall$
swap the top two elements$
pall$
thegirlsynth:/monty# ./monty bytecodes/00.m
3
2
1
5
4
3
2
1
3
4
2
1
thegirlsynth:/monty#
```

## Structs and Prototypes
