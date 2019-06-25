import newSessionInitiatedSaga from './newSessionInitiatedSaga';
import sessionPlayCodeSaga from './sessionPlayCodeSaga';

export default (sagaMiddleware) => {
    sagaMiddleware.run(newSessionInitiatedSaga);
    sagaMiddleware.run(sessionPlayCodeSaga);
};