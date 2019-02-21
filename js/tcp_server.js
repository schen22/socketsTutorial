var net = require('net');

// convenient how upon creating a server, client is returned
// in a callback and server can immediately begin listening.
var server = net.createServer(function(client) {
  console.log('Client connected.\n Client local address = ' + client.localAddress + ':' + client.localPort + '\n client remote address = ' + client.remoteAddress + ':' + client.remotePort + '\n');
  client.setEncoding('utf-8');
  client.setTimeout(1000);
  
  // Receive client data
  client.on('data', function(data){
    console.log('Received data: ' + data + '\n');
    console.log('Data byte size: ' + client.bytesRead);
    // Server sends data to client upon client ending connection:
    // client.end('Server received data: ' + data + '\n');
  });
  // Listen to when client ends connection
  client.on('end', function(data){
    console.log('Client disconnected.');              
  });
  client.on('timeout', function(){
    console.log("request timedout\n");
  })
  // Server send data to client:
  client.write('1 hello world\n');
  client.write('3 hello world');
  client.write('2 hello world\r\n');
});

// bind to port
server.listen(2222, function(){
  console.log('Listening for connections..\n');
  server.on('close', function(){
    console.log('closed connection.')
  });
  server.on('error', function(){
    console.error(JSON.stringify(error));
  });
})
