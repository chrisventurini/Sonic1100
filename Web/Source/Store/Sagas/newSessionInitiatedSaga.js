import * as effects from "redux-saga/effects"

import { actions, actionTypes } from "../Actions/Sessions";
import sessionService from "../../Services/sessionService";

// TODO: Add error handling
export default function* newSessionInitiatedSaga() {
    yield effects.takeEvery(actionTypes.NEW_SESSION_INITIATED, function* () {
        let sessionId = yield sessionService.createSession();
        yield effects.put(actions.newSessionCreated(sessionId));
    });
}