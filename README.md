# cpp

## backtrace
Print backtrace before exit 

># ./backtrace 
>Test exit callback!

>back trace, symbols:
>#0 0x400b8f in ./backtrace(_Z16print_stacktracev+0x91) [0x400b8f]
#1 0x7f55e1bce509 in /lib/x86_64-linux-gnu/libc.so.6(+0x3c509) [0x7f55e1bce509]
#2 0x7f55e1bce555 in /lib/x86_64-linux-gnu/libc.so.6(+0x3c555) [0x7f55e1bce555]
#3 0x400ae8 in ./backtrace(_Z4fun2v+0) [0x400ae8]
#4 0x400af1 in ./backtrace(_Z4fun2v+0x9) [0x400af1]
#5 0x400afc in ./backtrace(_Z4fun3v+0x9) [0x400afc]
#6 0x400ab5 in ./backtrace(main+0x48) [0x400ab5]
#7 0x7f55e1bb3ec5 in /lib/x86_64-linux-gnu/libc.so.6(__libc_start_main+0xf5) [0x7f55e1bb3ec5]
#8 0x4009a9 in ./backtrace() [0x4009a9]


