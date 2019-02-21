combo of tutorials:

## for C:

- [tutorialspoint](https://www.tutorialspoint.com/unix_sockets/socket_client_example.htm)
- [rpi](http://www.cs.rpi.edu/~moorthy/Courses/os98/Pgms/socket.html)
- [beej](https://beej.us/guide/bgnet/html/multi/connectman.html)

to compile c code:

`$ gcc -o server server.c`

where 'server' represents executable

What it looks like:
![alt text][images/c_output.png]

Learnings:
- Used curl to test server without having implemented client-side
- Main bug was that program terminated immediately upon connecting to server
- Needed to add while loop to make sure server constantly accepts message
- If other clients connect to server I'll have created memory leaks since I didn't take into account forking and closing file descriptors
- When sending a message to my client, the message was at first not sent until I quit running server
  - Realized the message was getting stuck in some sort of buffer
  - Required needing to add a terminating character to hello world in form of `\n` __magic__
- Through testing server with curl found post request: ![alt text][images/c_server.png]
  - could also open up webpage to point to port with localhost:2222 and display different header
