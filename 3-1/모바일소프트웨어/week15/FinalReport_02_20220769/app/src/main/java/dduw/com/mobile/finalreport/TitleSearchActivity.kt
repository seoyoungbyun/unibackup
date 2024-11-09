package dduw.com.mobile.finalreport

import android.os.Bundle
import androidx.appcompat.app.AppCompatActivity
import androidx.recyclerview.widget.LinearLayoutManager
import dduw.com.mobile.finalreport.data.BookDao
import dduw.com.mobile.finalreport.data.BookDto
import dduw.com.mobile.finalreport.databinding.ActivitySearchBinding

class TitleSearchActivity : AppCompatActivity() {

    val titleSearchBinding by lazy{
        ActivitySearchBinding.inflate(layoutInflater)
    }

    lateinit var books : ArrayList<BookDto>

    val bookDao by lazy {
        BookDao(this)
    }

    override fun onCreate(savedInstanceState: Bundle?) {
        super.onCreate(savedInstanceState)
        setContentView(titleSearchBinding.root)

        titleSearchBinding.btnSearch.setOnClickListener{
                titleSearchBinding.searchBookList.layoutManager = LinearLayoutManager(this).apply {
                    orientation = LinearLayoutManager.VERTICAL
                }

                books = bookDao.searchBook("title", titleSearchBinding.edSearch.text.toString()) 
                val adapter = BookAdapter(books)
                titleSearchBinding.searchBookList.adapter = adapter
        }

        titleSearchBinding.btnSearchCancel.setOnClickListener{
            finish()
        }
    }
}