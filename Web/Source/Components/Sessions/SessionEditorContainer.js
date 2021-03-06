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

    constructor(props) {
        super(props);

        this.handleInputChange = this.handleInputChange.bind(this);
        this.handleSubmit = this.handleSubmit.bind(this);
    }

    handleInputChange({target}) {
        let { name, value } = target;

        this.setState({
            ...this.state,
            [name]: value
        });
    }
    
    handleSubmit(event) {
        event.preventDefault();

        this.props.actions.sessionPlayCode(this.props.sessionId, this.state.pythonCode);
    }

    render() {
        return (
            <SessionEditor onInputChange={this.handleInputChange} onSubmit={this.handleSubmit} />
        );
    }
};

const mapState = () => {
    return {};
};

export default connect(mapState, mapDispatchToSessionActions)(SessionEditorContainer);
