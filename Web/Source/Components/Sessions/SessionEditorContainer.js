import React, { Component } from 'react';
import { connect } from 'react-redux';
import propTypes from 'prop-types';

import { actions, mapDispatchToSessionActions } from '../../Store/Actions/Sessions';
import SessionEditor from './SessionEditor';


class SessionEditorContainer extends Component {

    static propTypes = {
        sessionId: propTypes.string.isRequired
    };

    state = {
        sessionId: undefined 
    };

    render() {
        return (
            <SessionEditor sessionId={this.props.sessionId}/>
        );
    }

};

const mapState = () => {
    return {};
};

export default connect(mapState, mapDispatchToSessionActions)(SessionEditorContainer);
