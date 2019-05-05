import { createStore, applyMiddleware, compose } from 'redux';

import defaultState from './defaultState';

let rootReducer = (state = defaultState, action) => {
    return defaultState;
};

let store = createStore(rootReducer, defaultState);

export default store;