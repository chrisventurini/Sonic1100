import { combineReducers } from 'redux';

import sessionsReducer from './sessionsReducer';

export default combineReducers({
    sessions: sessionsReducer
});