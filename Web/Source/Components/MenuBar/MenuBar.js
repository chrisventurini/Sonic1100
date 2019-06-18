import React from 'react';

export default ({ onNewSession }) => {
    return (
        <div>
            <button onClick={onNewSession}>
                New Session
            </button> 
        </div>
    )
};