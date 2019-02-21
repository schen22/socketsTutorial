combo of tutorials:

## for C:

- [tutorialspoint](https://www.tutorialspoint.com/unix_sockets/socket_client_example.htm)
- [rpi](http://www.cs.rpi.edu/~moorthy/Courses/os98/Pgms/socket.html)
- [beej](https://beej.us/guide/bgnet/html/multi/connectman.html)

to compile c code:

`$ gcc -o server server.c`

where 'server' represents executable

What it looks like:
![c output](https://github.com/schen22/socketsTutorial/blob/master/images/c_output.png "c output")

Learnings:
- Used curl to test server without having implemented client-side
- Main bug was that program terminated immediately upon connecting to server
- Needed to add while loop to make sure server constantly accepts message
- If other clients connect to server I'll have created memory leaks since I didn't take into account forking and closing file descriptors
- When sending a message to my client, the message was at first not sent until I quit running server
  - Realized the message was getting stuck in some sort of buffer
  - Required needing to add a terminating character to hello world in form of `\n` __magic__
- Through testing server with curl found post request: ![c server test](https://github.com/schen22/socketsTutorial/blob/master/images/c_server.png "c server test")
  - could also open up webpage to point to port with localhost:2222 and display different header

## for node:
- [dev2qa](https://www.dev2qa.com/node-js-tcp-socket-client-server-example/)
- [net module library](https://nodejs.org/api/net.html)

`$ brew install node`
`$ node tcp_client.js`
`$ node tcp_server.js`

What it looks like:
![js output](https://github.com/schen22/socketsTutorial/blob/master/images/js-output.png "js output")

Learnings:
- Net library abstracts away the need to set up sockets
- Super easy to set up server since client is immediately returned in callback to begin sending/receiving messages
- Doesn't seem to care whether messages are properly truncated with `\n` or not
- Addresses are automatically converted into local/remote ports (htons is not needed to translate between host and network byte order)
- I'm sure there's a way to change communication type, but need to look up library
- Underlying net library is still c interface to talk with sockets
- Net library handles specifying message size, request, response
