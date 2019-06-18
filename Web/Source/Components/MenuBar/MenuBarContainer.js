import React, { Component } from 'react';
import { connect } from 'react-redux';
import propTypes from 'prop-types';

import MenuBar from './MenuBar';
import { mapDispatchToSessionActions } from '../../Store/Actions/Sessions';


class MenuBarContainer extends Component {

    constructor(props) {
        super(props);

        this.onNewSession = this.onNewSession.bind(this);
    }

    onNewSession() {
        this.props.actions.newSessionInitiated();
    }

    render() {
        return (
            <div>
                <MenuBar onNewSession={this.onNewSession} />
            </div>
        );
    }

};

const mapState = state => {
    return state;
};

export default connect(mapState, mapDispatchToSessionActions)(MenuBarContainer);
