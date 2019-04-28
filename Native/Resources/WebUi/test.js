var qChannel = new QWebChannel(qt.webChannelTransport); 

document.getElementById("execute").onclick = () => {
    var pyCode = document.getElementById("code").value;

    qChannel.objects.manager.executeCode(pyCode);
};

document.getElementById("setValue").onclick = () => {
    var pyValue = document.getElementById("value").value;

    qChannel.objects.manager.setVariable(pyValue);
};