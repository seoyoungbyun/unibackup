package dduw.com.mobile.finalreport

import android.os.Bundle
import androidx.appcompat.app.AppCompatActivity
import androidx.recyclerview.widget.LinearLayoutManager
import dduw.com.mobile.finalreport.data.BookDao
import dduw.com.mobile.finalreport.data.BookDto
import dduw.com.mobile.finalreport.databinding.ActivitySearchBinding

class AuthorSearchActivity : AppCompatActivity(){
    val authorSearchBinding by lazy{
        ActivitySearchBinding.inflate(layoutInflater)
    }

    lateinit var books : ArrayList<BookDto>

    val bookDao by lazy {
        BookDao(this)
    }

    override fun onCreate(savedInstanceState: Bundle?) {
        super.onCreate(savedInstanceState)
        setContentView(authorSearchBinding.root)

        authorSearchBinding.btnSearch.setOnClickListener{
            authorSearchBinding.searchBookList.layoutManager = LinearLayoutManager(this).apply {
                orientation = LinearLayoutManager.VERTICAL
            }

            books = bookDao.searchBook("author", authorSearchBinding.edSearch.text.toString())
            val adapter = BookAdapter(books)        // adapter 에 데이터 설정
            authorSearchBinding.searchBookList.adapter = adapter
        }

        authorSearchBinding.btnSearchCancel.setOnClickListener{
            finish()
        }
    }
}