export const SESSION_PLAY_CODE = 'SESSION_PLAY_CODE';

export const sessionPlayCode = (sessionId, pythonCode) => {
	return {
        pythonCode,
        sessionId,
        type: SESSION_PLAY_CODE
    }
}