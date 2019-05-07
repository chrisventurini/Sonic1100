import { createStore, applyMiddleware, compose } from 'redux';
import createSagaMiddleware from 'redux-saga';

import defaultState from './defaultState';
import initSagas from './sagas/index';
import rootReducer from './reducers';

let sagaMiddleware = createSagaMiddleware();

const composeEnhancers =
    typeof window === 'object' &&
        window.__REDUX_DEVTOOLS_EXTENSION_COMPOSE__ ?
        window.__REDUX_DEVTOOLS_EXTENSION_COMPOSE__({
        }) : compose;

let store = createStore(rootReducer, defaultState, composeEnhancers(applyMiddleware(sagaMiddleware)));

initSagas(sagaMiddleware);

export default store;