The functions that are allowed for the implementation of this function are the following:
- read 
- malloc
- free

In this function the fd will already be passed to us so we don't need to open the file. Our task is to read the first line of the file we are passed. To do so we need to utilize the function read having the following prototype:
<ssize_t read(int fd, void *buf, size_t count);>

The file descriptor is the first parameter that it accepts. As the argument, we will need to provide the descriptor used when the file was opened.

A pointer is sent in as the second parameter. The Read function will get the data from the specified file and store it where you have directed it.

As the value of this pointer, we may supply the address of the buffer area that was previously allocated. The third parameter specifies the number of bytes that should be read from the file.

The number of bytes that were successfully read from this file is returned by this file if the file was successfully read. It will return the value -1 if it does not succeed.


**What are fd in c?**
Fd also know as file descriptors are pointer like variable to access an IO (input/output) ressources, one that the process you are building will be using.

In simple words, when you open a file, the operating system creates an entry to represent that file and store the information about that opened file. So if there are 100 files opened in your OS then there will be 100 entries in OS (somewhere in kernel). These entries are represented by integers like (...100, 101, 102....). This entry number is the file descriptor. So it is just an integer number that uniquely represents an opened file for the process. If your process opens 10 files then your Process table will have 10 entries for file descriptors.

Similarly, when you open a network socket, it is also represented by an integer and it is called Socket Descriptor. I hope you understand.

Let's say in you code you opened a file to read from or to write to. This means the process needs access to a resource and it has to create a mapping/pointer for this new resource.
To do this, the kernel automatically creates a FD as soon as the file is opened by your code.

Read from stdin => read from fd 0 : Whenever we write any character from keyboard, it read from stdin through fd 0 and save to file named /dev/tty.

