# > Libft
Project libft (or library 42) was meant to provide us with an understanding of
how we could develop our own library of tools. The requirements listed includes the use
of a Makefile to compile the archive .a file.

---
#### > To Execute compile the executable as follows:
Provide your own main.c with the archived functions you wish to use. 
Ensure that you included the libft.h, located inside the includes subdirectory,
within your program.
```bash
make
cc main.c libft.a -Wall -Wextra -Werror -o exec
./exec
```
The above will then tell the compilor to name the resulting executable file 'exec.'
---
#### > Next steps
Beyond the final project of the 42 common core several c related projects exist. In order to complete them I have optimized my Libft and added binary tree capabilities which allows me to store data in a similar way to that of the stl Map container in c++. Read more on my implementation by redirecting yourself to the binaryTree subdirectory!