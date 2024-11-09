package dduw.com.mobile.finalreport

import android.content.ContentValues
import android.os.Bundle
import android.widget.Toast
import androidx.appcompat.app.AppCompatActivity
import dduw.com.mobile.finalreport.data.BookDBHelper
import dduw.com.mobile.finalreport.data.BookDao
import dduw.com.mobile.finalreport.data.BookDto
import dduw.com.mobile.finalreport.databinding.ActivityAddBinding

class AddActivity : AppCompatActivity(){
    val addBinding by lazy {
        ActivityAddBinding.inflate(layoutInflater)
    }

    val bookDao by lazy {
        BookDao(this)
    }

    override fun onCreate(savedInstanceState: Bundle?) {
        super.onCreate(savedInstanceState)
        setContentView(addBinding.root)

        addBinding.addImg.setImageResource(R.mipmap.new_book)

        addBinding.btnAdd.setOnClickListener{
            val title = addBinding.ediAddTitle.text.toString()
            val author = addBinding.edAddAuthor.text.toString()
            val publisher = addBinding.edAddPublisher.text.toString()
            val price = addBinding.edAddPrice.text.toString()
            val rating = addBinding.AddRatingBar.rating

            if (title.isEmpty() || author.isEmpty() || publisher.isEmpty() || price.isEmpty())
                Toast.makeText(this, "필수항목 입력이 필요합니다.", Toast.LENGTH_SHORT).show()
            else {
                if (bookDao.addBook(BookDto(0, title, author, publisher, Integer.parseInt(price), rating, R.mipmap.new_book)) > 0) {
                    setResult(AppCompatActivity.RESULT_OK)
                } else {
                    setResult(AppCompatActivity.RESULT_CANCELED)
                }
                finish()
            }
        }

        addBinding.btnAddCancel.setOnClickListener{
            setResult(AppCompatActivity.RESULT_CANCELED)
            finish()
        }

    }
}