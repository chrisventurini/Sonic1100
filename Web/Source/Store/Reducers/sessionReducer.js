import { actionTypes } from "../Actions/Sessions";
import defaultState from '../defaultState';

export default (state = defaultState.sessions, data) => {
	let newState;

    switch (data.type) {
    	case actionTypes.NEW_SESSION_CREATED:
            console.log(data.sessionId);
    		newState = state.slice(0);
    		newState.push(data.sessionId);
    	default:
            newState = state;
    }

    return newState;
}