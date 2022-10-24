# random address 
a adress of a pointer is usually randomized in linux 

to turn off this randomization we can use 
```bash
setarch $(uname --machine) --addr-no-randomize ./name_of_the_binary
```

```
jf18j492@aitne:~/code/ostep-code/intro$ ./mem 1 
n_int_address address/index/pointer: 0x5610dab6b2a0
n_int_address actual number value: -625560928
^C
(base) jf18j492@aitne:~/code/ostep-code/intro$ ./mem 1 
n_int_address address/index/pointer: 0x558667a692a0
n_int_address actual number value: 1738969760
^C
(base) jf18j492@aitne:~/code/ostep-code/intro$ ./mem 1 
n_int_address address/index/pointer: 0x55a57904c2a0
n_int_address actual number value: 2030355104
^C
(base) jf18j492@aitne:~/code/ostep-code/intro$ ./mem 1 
n_int_address address/index/pointer: 0x561877c0b2a0
n_int_address actual number value: 2009117344
^C
(base) jf18j492@aitne:~/code/ostep-code/intro$ setarch $(uname --machine) --addr-no-randomize ./mem 1
n_int_address address/index/pointer: 0x5555555592a0
n_int_address actual number value: 1431671456
^C
(base) jf18j492@aitne:~/code/ostep-code/intro$ setarch $(uname --machine) --addr-no-randomize ./mem 1
n_int_address address/index/pointer: 0x5555555592a0
n_int_address actual number value: 1431671456
^C
(base) jf18j492@aitne:~/code/ostep-code/intro$ setarch $(uname --machine) --addr-no-randomize ./mem 1
n_int_address address/index/pointer: 0x5555555592a0
n_int_address actual number value: 1431671456
^C
(base) jf18j492@aitne:~/code/ostep-code/intro$ setarch $(uname --machine) --addr-no-randomize ./mem 1
n_int_address address/index/pointer: 0x5555555592a0
n_int_address actual number value: 1431671456
```