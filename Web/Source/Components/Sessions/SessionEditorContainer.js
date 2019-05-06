import React, { Component } from 'react';
import { connect } from 'react-redux';
import PropTypes from 'prop-types';

import { actions, mapDispatchToSessionActions } from '../../Store/Actions/Sessions';
import SessionEditor from './SessionEditor';


class SessionEditorContainer extends Component {

    static propTypes = {};

    state = {
        sessionId: undefined 
    };

    componentDidMount() {
        this.props.actions.newSessionInitiated();
    }

    render() {
        return (
            <SessionEditor />
        );
    }

};

const mapState = state => {
    return state;
};

export default connect(mapState, mapDispatchToSessionActions)(SessionEditorContainer);
