# outside gdb, in shell
# gdb <filename>
start gdb with file 

# gdb --pid <pid> 
attach gdb to process gdb with process id 

# inside gdb 
# run 
run the programm, start the debugging

# kill 
end the running programm, kill the running programm

# break <linenumber>
set a breakpoint at the linenumber 

# delete <breakpoint#>
remove a breakpoint

# clear 
delete all breakpoints 

# enable <breakpoint#>
enable a breakpoint

# disable <breakpoint#>
disable a breakpoint

# watch <linenumber>
set a new watchpoint at linenumber

# delete / enable / disable <watchpoint#>
same command as for breakpoints

# function_name 
    break / watch the named function 

# line_number 
    break/watch  the line number in the curent source file

# file:line_number
    break/watch the line number in the named source file 

# break /watch <linenumber> if <condition>

    break / watch at the line if the condition is true
    conditions may be almost any c expression that evaluate to true or false 


# condition <breakpoint#> <condition>

    set/change the condition of an existing break- or watchpoint

# backtrace where 
    show call stack 

# backtrace full 
# where full
    show call stack, also print the local variables in each frame

# frame <frame#>
    select the stack frame to operate on. 

# step 
    go to next instruction (source line), diving into function

# next 
    go to next instruction (source line), but dont dive into functions. 

# finish 
    continue until the current function returns

# continue 
    continue normal execution 

# print/format <variable_name / identifier > 
    print content of variable/memory location 

# display/format <variable_name / identifier > 
    like print but print the information after each stepping instruction 

# undisplay <display#> 
    remove the "display" with the given number

# enable display <display#> 
# disable display <display#> 
    en or disable the "display" with the given number


# x / nfu <address>
    print memory. 
    n: how many units to print (default 1) 
    f: format character (like "print")
    u: Unit (b: byte, h: half word(2 bytes), w: (4 bytes), g:giant word (8bytes))


# format 
a: pointer 
c: read as integer print as character 
d: integer signed decimal 
f: floating point number 
o: integer, print as octal 
s: try to treat as c string 
t: integer, print as biary (t=two)
u: integer, unsigned decimal
x: integer, print as hexadecimal

# <identifier>
    ## expression 
        almost  any c expression including function calls (must be prefixed with a cast to tell gdb the return value type)

    ## file_name::variable_name 
        content of the variable defined in the named file (static variables) 

    ## function::variable_name
        content of the variable defined in the named function (if on the stack) 

    ## {type}address
        content at adress, interpreted as being of the c type type

    ## $register
        content of named register. interesting registers are $esp (stack pointer), $ebp (frame pointer) and $eip (instruction pointer) 

# thread <thread#> 
    choose thread to operate on 


# set var <variable_name>=<value>
    change the content of a varable to the given value 

# return <expression> 
    force the current function to return imediately passing the given value

# directory <directory> 
    add directory to the list of directories that is searched for sources 

# list 
# list <filename>:<function> 
# list <filename>:<line_number>
# list <first>,<last> 
    shows the current or given source context. the filename may be omitted. if last is omitted the context starting at start is printed istead of centered around integer

# set listsize <count> 
    set how many lines to show in command "list" 

# handle <signal> <options> 
    set how to handle signals. options are: 
        (no)print: (dont) print a message when signals occurs 
        (no)stop: (dont) stop the program when signals occurs 
        (no)pass: (dont) pass the signal to the programm 



# disassemble 
# disassemble <where>
    disassemble the current function or given location 

# info args 
    print the arguments to the function of the current stack frame 

# info breakpoints 
    print informations about the break- and watchpoints 

# info display 
    print informations about the "displays" 

# info locals 
    print the local variables in the currently selected stack frame 

# info sharedlibrary 
    list loaded shared libraries 

# info signals
    list all signals and how they are currently handled 

# info threads 
    list all threads 

# show directories 
    print all directories in which gdb searches for source files 

# show listsize 
    print how many are shown in the "list" command 

whatis <variable_name> 
    print type of named variable
    
