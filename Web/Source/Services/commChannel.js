const COMM_CHANNEL_KEY = Symbol.for('COMM_CHANNEL');

let globalSymbols = Object.getOwnPropertySymbols(global);

if(globalSymbols.indexOf(COMM_CHANNEL_KEY) === -1) {
	global[COMM_CHANNEL_KEY] = new QWebChannel(qt.webChannelTransport);
}

export default global[COMM_CHANNEL_KEY];