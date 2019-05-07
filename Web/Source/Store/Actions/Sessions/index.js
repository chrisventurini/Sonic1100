import { bindActionCreators } from 'redux';

import { NEW_SESSION_INITIATED, newSessionInitiated } from './newSessionInitiated';
import { NEW_SESSION_CREATED, newSessionCreated } from './newSessionCreated';

export const actions = {
    newSessionCreated,
    newSessionInitiated
};

export const actionTypes = {
    NEW_SESSION_CREATED,
    NEW_SESSION_INITIATED
};

export const mapDispatchToSessionActions = dispatch => {
    return { actions: bindActionCreators(actions, dispatch) };
};
