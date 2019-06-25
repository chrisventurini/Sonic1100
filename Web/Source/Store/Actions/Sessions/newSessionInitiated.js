import actionConsts from '../consts';

export const NEW_SESSION_INITIATED = `NEW_SESSION_INITIATED__${actionConsts.ASYNC_STARTED}`;

export const newSessionInitiated = () => {
	return {
		type: NEW_SESSION_INITIATED
    }
}