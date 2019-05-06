import { bindActionCreators } from 'redux';

import { NEW_SESSION_INITIATED, newSessionInitiated } from './newSessionInitiated';

export const actions = {
    newSessionInitiated
};

export const actionTypes = {
    NEW_SESSION_INITIATED
};

export const mapDispatchToSessionActions = dispatch => {
    return { actions: bindActionCreators(actions, dispatch) };
};
