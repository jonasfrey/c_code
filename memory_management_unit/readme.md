# MMU 
Memory management unit 
is usually a hardware part of the cpu 

its job is to assign a memory address


## paging 
a page has a fixed size , for example 4096 bytes


## address translation 

each process has its own table 

by the virtuall adrees get the physical adress 

is in the hardware implemented 

gets offset by mask , and then shift
virtual address
- offset 
- page number


### example 
                    dec          bin
virtual address      21       010101
VPN (page number):   01           01
offset:            0101         0101


Knowing that page 1 is mapped to PFN 7 (binary: 111), the virtual
address can be translated to the physical address 1110101
(decimal: 117). o Note that oset remains the same.


## synonyms 

VPN : Virutal Page Number
PFN : Physical frame number

