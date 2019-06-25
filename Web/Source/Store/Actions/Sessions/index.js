import { bindActionCreators } from 'redux';

import { NEW_SESSION_INITIATED, newSessionInitiated } from './newSessionInitiated';
import { NEW_SESSION_CREATED, newSessionCreated } from './newSessionCreated';
import { SESSION_PLAY_CODE, sessionPlayCode } from './sessionPlayCode';

export const actions = {
    newSessionCreated,
    newSessionInitiated,
    sessionPlayCode
};

export const actionTypes = {
    NEW_SESSION_CREATED,
    NEW_SESSION_INITIATED,
    SESSION_PLAY_CODE
};

export const mapDispatchToSessionActions = dispatch => {
    return { actions: bindActionCreators(actions, dispatch) };
};
