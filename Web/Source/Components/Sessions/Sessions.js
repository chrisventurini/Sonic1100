import React, { Component } from 'react';
import { connect } from 'react-redux';
import propTypes from 'prop-types';

import { actions, mapDispatchToSessionActions } from '../../Store/Actions/Sessions';
import SessionEditorContainer from './SessionEditorContainer'

export let Sessions = ({ sessions }) => {
    let sessionEditors = sessions.map((sessionId) => {
        return (<SessionEditorContainer key={sessionId} sessionId={sessionId} />)
    });

    return (
        <div>
            { sessionEditors }
        </div>
    );
};

Sessions.propTypes = {
    sessions: propTypes.array.isRequired
}

const mapState = ({ sessions }) => {
    return {sessions};
};

export default connect(mapState, mapDispatchToSessionActions)(Sessions);
