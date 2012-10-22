libasmb64
=========

A Base64 decoder written in Intel x86/x64 assembly.

This was created just for the fun of it, though with most hardware being Intel based
it could be portable enough to run on most systems that use stdcall or the System-V ABI.

Compiling
---------

libasmb64 was written and tested on Ubuntu Linux using GCC and NASM, no other operating systems have been tested. A Makefile has been included.

    $ make
    rm -f *.o 2>/dev/null
    rm -f b64_64 2>/dev/null
    nasm -f elf64 -o libasmb64.o libasmb64_64.s
    gcc -m64 -o b64_64 b64.c libasmb64.o

To compile for 32-bit on a 64-bit system, pass the ARCH= parameter to make.

    $ make ARCH=32
    rm -f *.o 2>/dev/null
    rm -f b64_32 2>/dev/null
    nasm -f elf32 -o libasmb64.o libasmb64_32.s
    gcc -m32 -o b64_32 b64.c libasmb64.o
    

Testing
-------

After compiling a binary file `b64_$ARCH` will be created in the `bin` directory. Executing this will decode some lorem ipsum.

    $ ./bin/b64_64
    (1006)   b64decode = Lorem ipsum dolor sit amet, consectetur adipiscing elit. Ut elementum, purus vel gravida pretium, ipsum nisl fermentum urna, semper dignissim nisl magna in augue. Morbi urna nunc, euismod non ultrices suscipit, malesuada ullamcorper magna. Sed tristique, mi vel tincidunt malesuada, velit leo fermentum dui, lacinia dapibus est eros eu dui. Praesent in purus diam, id euismod metus. Sed vehicula tellus a nisi fermentum eget porta lacus tincidunt. Ut adipiscing nisl a velit cursus aliquet. Sed sodales metus eget leo pharetra quis elementum urna fringilla. In metus purus, sodales ac sollicitudin non, pulvinar id lacus. Praesent consectetur tempor sapien ac aliquam. Aliquam eu felis a elit tristique rhoncus. Suspendisse potenti. Donec rhoncus mauris at leo consequat commodo. Integer ligula velit, commodo at pulvinar ac, pellentesque porttitor est. Quisque eget massa a mi imperdiet cursus. Nam ante arcu, convallis condimentum sodales et, condimentum sit amet metus. Duis tristique gravida facilisis.
    (1006) b64decode_c = Lorem ipsum dolor sit amet, consectetur adipiscing elit. Ut elementum, purus vel gravida pretium, ipsum nisl fermentum urna, semper dignissim nisl magna in augue. Morbi urna nunc, euismod non ultrices suscipit, malesuada ullamcorper magna. Sed tristique, mi vel tincidunt malesuada, velit leo fermentum dui, lacinia dapibus est eros eu dui. Praesent in purus diam, id euismod metus. Sed vehicula tellus a nisi fermentum eget porta lacus tincidunt. Ut adipiscing nisl a velit cursus aliquet. Sed sodales metus eget leo pharetra quis elementum urna fringilla. In metus purus, sodales ac sollicitudin non, pulvinar id lacus. Praesent consectetur tempor sapien ac aliquam. Aliquam eu felis a elit tristique rhoncus. Suspendisse potenti. Donec rhoncus mauris at leo consequat commodo. Integer ligula velit, commodo at pulvinar ac, pellentesque porttitor est. Quisque eget massa a mi imperdiet cursus. Nam ante arcu, convallis condimentum sodales et, condimentum sit amet metus. Duis tristique gravida facilisis.

    $ ./bin/b64_32
    (1006)   b64decode = Lorem ipsum dolor sit amet, consectetur adipiscing elit. Ut elementum, purus vel gravida pretium, ipsum nisl fermentum urna, semper dignissim nisl magna in augue. Morbi urna nunc, euismod non ultrices suscipit, malesuada ullamcorper magna. Sed tristique, mi vel tincidunt malesuada, velit leo fermentum dui, lacinia dapibus est eros eu dui. Praesent in purus diam, id euismod metus. Sed vehicula tellus a nisi fermentum eget porta lacus tincidunt. Ut adipiscing nisl a velit cursus aliquet. Sed sodales metus eget leo pharetra quis elementum urna fringilla. In metus purus, sodales ac sollicitudin non, pulvinar id lacus. Praesent consectetur tempor sapien ac aliquam. Aliquam eu felis a elit tristique rhoncus. Suspendisse potenti. Donec rhoncus mauris at leo consequat commodo. Integer ligula velit, commodo at pulvinar ac, pellentesque porttitor est. Quisque eget massa a mi imperdiet cursus. Nam ante arcu, convallis condimentum sodales et, condimentum sit amet metus. Duis tristique gravida facilisis.
    (1006) b64decode_c = Lorem ipsum dolor sit amet, consectetur adipiscing elit. Ut elementum, purus vel gravida pretium, ipsum nisl fermentum urna, semper dignissim nisl magna in augue. Morbi urna nunc, euismod non ultrices suscipit, malesuada ullamcorper magna. Sed tristique, mi vel tincidunt malesuada, velit leo fermentum dui, lacinia dapibus est eros eu dui. Praesent in purus diam, id euismod metus. Sed vehicula tellus a nisi fermentum eget porta lacus tincidunt. Ut adipiscing nisl a velit cursus aliquet. Sed sodales metus eget leo pharetra quis elementum urna fringilla. In metus purus, sodales ac sollicitudin non, pulvinar id lacus. Praesent consectetur tempor sapien ac aliquam. Aliquam eu felis a elit tristique rhoncus. Suspendisse potenti. Donec rhoncus mauris at leo consequat commodo. Integer ligula velit, commodo at pulvinar ac, pellentesque porttitor est. Quisque eget massa a mi imperdiet cursus. Nam ante arcu, convallis condimentum sodales et, condimentum sit amet metus. Duis tristique gravida facilisis.    


Support
-------

* Ubuntu Linux 32-bit / 64-bit

Anyone who wants to compile and test this on other systems like Mac OS or *BSD would be welcome.

Currently Windows is unsupported and will cause stack/register corruption due to different calling conventions.
