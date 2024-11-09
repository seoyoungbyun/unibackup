package dduw.com.mobile.finalreport

import android.content.ContentValues
import android.os.Bundle
import android.provider.BaseColumns
import android.widget.Toast
import androidx.appcompat.app.AppCompatActivity
import dduw.com.mobile.finalreport.data.BookDBHelper
import dduw.com.mobile.finalreport.data.BookDao
import dduw.com.mobile.finalreport.data.BookDto
import dduw.com.mobile.finalreport.databinding.ActivityUpdateBinding

class UpdateActivity : AppCompatActivity(){

    val updateBinding by lazy{
        ActivityUpdateBinding.inflate(layoutInflater)
    }

    val bookDao by lazy {
        BookDao(this)
    }

    override fun onCreate(savedInstanceState: Bundle?) {
        super.onCreate(savedInstanceState)

        setContentView(updateBinding.root)

        val dto = intent.getSerializableExtra("dto") as BookDto

        updateBinding.edUpdateTitle.setText(dto.title)
        updateBinding.edUpdateAuthor.setText(dto.author)
        updateBinding.edUpdatePublisher.setText(dto.publisher)
        updateBinding.edUpdatePrice.setText(dto.price.toString())
        updateBinding.UpdateRatingBar.rating = dto.rating
        updateBinding.imageView.setImageResource(dto.cover)

        updateBinding.btnUpdate.setOnClickListener{
            dto.title = updateBinding.edUpdateTitle.text.toString()
            dto.author = updateBinding.edUpdateAuthor.text.toString()
            dto.publisher = updateBinding.edUpdatePublisher.text.toString()
            val price = updateBinding.edUpdatePrice.text.toString()
            dto.rating = updateBinding.UpdateRatingBar.rating

            if ((dto.title).isEmpty() || (dto.author).isEmpty() || (dto.publisher).isEmpty() || price.isEmpty())
                Toast.makeText(this, "필수항목 입력이 필요합니다.", Toast.LENGTH_SHORT).show()
            else {
                dto.price = Integer.parseInt(price)

                if (bookDao.updateBook(dto) > 0) {
                    setResult(RESULT_OK)
                } else {
                    setResult(RESULT_CANCELED)
                }

                finish()
            }
        }

        updateBinding.btnUpdateCancel.setOnClickListener{
            setResult(RESULT_CANCELED)
            finish()
        }
    }
}