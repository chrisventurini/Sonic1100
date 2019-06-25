import * as effects from "redux-saga/effects"

import { actionTypes } from "../Actions/Sessions";
import sessionService from "../../Services/sessionService";

// TODO: Add error handling
export default function* sessionCodeRunSaga() {
    yield effects.takeEvery(actionTypes.SESSION_PLAY_CODE, function* ({ sessionId, pythonCode }) {
        sessionService.playCode(sessionId, pythonCode)
    });
}