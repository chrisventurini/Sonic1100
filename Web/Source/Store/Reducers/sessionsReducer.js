import { actionTypes } from "../Actions/Sessions";
import defaultState from '../defaultState';

export default (state = defaultState.sessions, data) => {
	let newState;

    switch (data.type) {
    	case actionTypes.NEW_SESSION_CREATED:
            newState = state.slice(0);
    		newState.push(data.sessionId);
            break;
        default:
            newState = state;
    }

    return newState;
}