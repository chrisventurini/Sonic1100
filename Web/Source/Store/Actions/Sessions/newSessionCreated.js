export const NEW_SESSION_CREATED = 'NEW_SESSION_CREATED';

export const newSessionCreated = (sessionId) => {
	return {
        type: NEW_SESSION_CREATED,
        sessionId
    }
}