export const addNote = ({ dispatch }) => {
	dispatch('ADD_NOTE')
}

export const editNote = ({ dispatch }) => {
	dispatch('EDIT_NOTE', e.target.value)
}

export const deleteNote = ({ dispatch }) => {
	dispatch('DELETE_NOTE')
}

export const updateActiveNote = ({ dispatch }) => {
	dispatch('SET_ACTIVE_NOTE', note)
}

export const toggleFavorite = ({ dispatch }) => {
	dispatch('TOGGLE_FAVORITE')
}