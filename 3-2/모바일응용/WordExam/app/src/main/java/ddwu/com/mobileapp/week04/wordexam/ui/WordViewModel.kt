package ddwu.com.mobileapp.week04.wordexam.ui

import androidx.lifecycle.LiveData
import androidx.lifecycle.ViewModel
import androidx.lifecycle.asLiveData
import androidx.lifecycle.viewModelScope
import ddwu.com.mobileapp.week04.wordexam.data.Word
import ddwu.com.mobileapp.week04.wordexam.data.WordRepository
import kotlinx.coroutines.Deferred
import kotlinx.coroutines.async
import kotlinx.coroutines.launch

class WordViewModel (var wordRepo: WordRepository) : ViewModel() {
    var allWords : LiveData<List<Word>> = wordRepo.allWords.asLiveData()

    fun addWord(word: Word) = viewModelScope.launch {
        wordRepo.addWord(word)
    }

    fun removeWord(word: Word) = viewModelScope.launch {
        wordRepo.removeWord(word)
    }

    fun modifyWord(word: Word) = viewModelScope.launch {
        wordRepo.modifyWord(word)
    }

}