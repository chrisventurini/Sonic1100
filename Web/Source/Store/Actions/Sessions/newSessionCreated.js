import actionConsts from '../consts';

export const NEW_SESSION_CREATED = `NEW_SESSION_CREATED__${actionConsts.ASYNC_COMPLETED}`;

export const newSessionCreated = (sessionId) => {
	return {
        type: NEW_SESSION_CREATED,
        sessionId
    }
}