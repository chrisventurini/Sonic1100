import commChannel from './commChannel';

export default {
    createSession:async () => {
        return new Promise(resolve => {
            commChannel.objects.manager.createSession((sessionId) => {
                resolve(sessionId);
            });
        });
    }
};