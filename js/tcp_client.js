var net = require('net');

function createConnection(name) {
  var option = {
    host:'localhost',
    port: 2222
  }

  // Create client
  var client = net.createConnection(option, function(){
    console.log("connection created\n");
    console.log(name + '\'s local address : ' + client.localAddress + ":" + client.localPort);
    console.log(name + '\'s remote address : ' + client.remoteAddress + ":" + client.remotePort);
  })

  client.setTimeout(1000);
  client.setEncoding('utf8');

  client.on('data', function(data){
    console.log(name + ' received msg from server: ' + data + '\n');
  });
  client.on('end', function(){
    console.log(name + ' disconnected')
  });
  client.on('timeout', function() {
    console.log(name + '\'s connection timed out\n');
  });
  client.on('error', function(err) {
    console.error(name + 'encountered error: ' + JSON.stringify(err));
  });
  return client;
}

var bobClient = createConnection('bob');
var sallyClient = createConnection('sally');

bobClient.write("Hello from bob!\n");
sallyClient.write("Hello from sally.\n");
