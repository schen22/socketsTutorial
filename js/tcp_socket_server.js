var net = require('net');

var server = net.createServer(function(client) {
  console.log('Client connected.\n Client local address = ' + client.localAddress + ':' + client.localPort + '\n client remote address = ' + client.remoteAddress + ':' + client.remotePort + '\n');
  client.setEncoding('utf-8');
  client.setTimeout(1000);
  
  // Receive client data
  client.on('data', function(data){
    console.log('Received data: ' + data + '\n');
    console.log('Data byte size: ' + client.bytesRead);
    client.end('Message received\n');
  });
  // Complete sending data
  client.on('end', function(data){
    console.log('Disconnected.');              
  });
  client.on('timeout', function(){
    console.log("request timedout\n");
  })
});

server.listen(2222, function(){
  console.log('Listening for connections..\n');
  server.on('close', function(){
    console.log('closed connection.')
  });
  server.on('error', function(){
    console.error(JSON.stringify(error));
  });
})
