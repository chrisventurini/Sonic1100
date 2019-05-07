import newSessionInitiatedSaga from './newSessionInitiatedSaga';

export default (sagaMiddleware) => {
    sagaMiddleware.run(newSessionInitiatedSaga);
};