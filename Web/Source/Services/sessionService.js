import commChannel from './commChannel';

export default {
    createSession: async () => {
        return new Promise(resolve => {
            commChannel.objects.manager.createSession((sessionId) => {
                resolve(sessionId); 
            });
        });
    },

    playCode: async (sessionId, pythonCode) => {
        return new Promise(resolve => {
            commChannel.objects.manager.playCode(sessionId, pythonCode);
        })
    }
};