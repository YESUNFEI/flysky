<template>
	<div id="note-editor">
		<textarea
			:value="activeNoteText"
			@input="editNote"
			class="form-control">
		</textarea>
	</div>
</template>

<script type="text/javascript">
	import { editNote } from '../vuex/actions'

	export default {
		vuex: {
			getters: {
				activeNoteText: state => state.activeNote.text
			},
			actions: {
				editNote
			}
		}
	}
</script>