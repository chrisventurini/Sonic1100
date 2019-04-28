var qChannel = new QWebChannel(qt.webChannelTransport, function(channel) {
    window.foo = channel.objects.manager;
    window.foo.jsCallMe();
});