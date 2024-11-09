 package ddwu.com.mobileapp.week04.wordexam

import android.os.Bundle
import android.view.View
import androidx.activity.viewModels
import androidx.appcompat.app.AppCompatActivity
import androidx.lifecycle.Observer
import androidx.recyclerview.widget.LinearLayoutManager
import ddwu.com.mobileapp.week04.wordexam.databinding.ActivityMainBinding
import ddwu.com.mobileapp.week04.wordexam.data.Word
import ddwu.com.mobileapp.week04.wordexam.ui.WordAdapter
import ddwu.com.mobileapp.week04.wordexam.ui.WordViewModel
import ddwu.com.mobileapp.week04.wordexam.ui.WordViewModelFactory
import kotlinx.coroutines.CoroutineScope
import kotlinx.coroutines.Dispatchers
import kotlinx.coroutines.launch
import kotlinx.coroutines.withContext

 class MainActivity : AppCompatActivity() {

    val binding by lazy {
        ActivityMainBinding.inflate(layoutInflater)
    }

    override fun onCreate(savedInstanceState: Bundle?) {
        super.onCreate(savedInstanceState)
//        enableEdgeToEdge()
        setContentView(binding.root)
//        ViewCompat.setOnApplyWindowInsetsListener(findViewById(R.id.main)) { v, insets ->
//            val systemBars = insets.getInsets(WindowInsetsCompat.Type.systemBars())
//            v.setPadding(systemBars.left, systemBars.top, systemBars.right, systemBars.bottom)
//            insets
//        }

        // 1. wordDao 객체 생성
        //val wordDao = (application as WordApplication).wordDao
//        val wordRepo = (application as WordApplication).wordRepo
        val viewModel : WordViewModel by viewModels {
            WordViewModelFactory((application as WordApplication).wordRepo)
        }

        val adapter = WordAdapter(ArrayList<Word>())
        val layoutManager = LinearLayoutManager(this)
        layoutManager.orientation = LinearLayoutManager.VERTICAL

        adapter.setOnWordClickListener(object: WordAdapter.OnWordClickListener {
            override fun onWordClick(view: View, pos: Int) {
                // 5. rvWords 에서 클릭한 단어로 wordDao를 사용하여  DB에서 의미 검색 후 의미 칸에 표시
                val word = adapter.words[pos].word
                val meaning = adapter.words[pos].meaning
//                CoroutineScope(Dispatchers.IO).launch {
//                    val meaning = wordRepo.getWordMeaning(word)
//                    withContext(Dispatchers.Main) {
//                        binding.etMeaning.setText(meaning)
//                    }
//                }
                binding.etWord.setText(word)
                binding.etMeaning.setText(meaning)
            }
        })

        binding.rvWords.layoutManager = layoutManager
        binding.rvWords.adapter = adapter


        // 2. wordDao 객체에서 전체 word 를 가져와 rvWords(RecyclerView) 에 지정
//        val wordFlow = wordRepo.allWords
//        CoroutineScope(Dispatchers.Main).launch {
//            wordFlow.collect { words ->
//                adapter.words.clear()
//                adapter.words.addAll(words)
//                adapter.notifyDataSetChanged()
//            }
//        }
        viewModel.allWords.observe(this, Observer { words ->
            adapter.words = words
            adapter.notifyDataSetChanged()
        })
        // Flow<List<Word>> 를 사용하여 갱신 정보를 자동 반영하도록 구성


        // 3. 화면에 입력한 단어와 의미를 읽어와 Word 로 만든 후 wordDao 를 사용하여 DB 저장
        binding.btnSave.setOnClickListener {
            val wordText = binding.etWord.text.toString()
            val meaning = binding.etMeaning.text.toString()
            val word = Word(wordText, meaning)

//            CoroutineScope(Dispatchers.IO).launch {
//                wordRepo.addWord(word)
//            }

            viewModel.addWord(word)
        }

        // 4. 화면에 입력한 단어로 Word 로 만둔 후(의미는 빈문자열) wordDao 를 사용하여 DB 삭제
        binding.btnDelete.setOnClickListener {
            val wordText = binding.etWord.text.toString()
            val word = Word(wordText, "")

//            CoroutineScope(Dispatchers.IO).launch {
//                wordRepo.removeWord(word)
//            }
            viewModel.removeWord(word)
        }

        binding.btnUpdate.setOnClickListener {
            val wordText = binding.etWord.text.toString()
            val meaning = binding.etMeaning.text.toString()
            val word = Word(wordText, meaning)

//            CoroutineScope(Dispatchers.IO).launch {
//                wordRepo.modifyWord(word)
//            }

            viewModel.modifyWord(word)
        }


    }

}