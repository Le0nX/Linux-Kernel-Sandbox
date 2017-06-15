# Chapter 03

## Question 3-1

### Question: 

When using the linux-specific reboot() system call to reboot the system, the second argument, magic2, 
must be specified as one of a set of magic numbers (e.g. LINUX_REBOOT_MAGIC2).
What is the significance of these numbers? (Converting them to hexadecimal provides a clue)

### Answer:

Theese numbers look more interesting in hex:

672274793 = 0x28121969
85072278 = 0x05121996
369367448 = 0x16041998
537993216 = 0x20112000

It's the birthday of Linus Torvalds (The developer of the Linux kernel and the Git version control) 
and his 3 daughters. works as magic numbers to reboot the system.
