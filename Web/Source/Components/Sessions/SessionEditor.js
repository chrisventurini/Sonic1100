import React from 'react';

export default ({onInputChange, onSubmit}) => {
    return (
        <form onSubmit={onSubmit}>
            <textarea name="pythonCode" onChange={onInputChange} /> 
            <button type="submit">Play</button>
        </form>
    )
};