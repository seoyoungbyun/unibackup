package dduw.com.mobile.finalreport

import android.content.DialogInterface
import android.content.Intent
import android.os.Bundle
import android.view.Menu
import android.view.MenuItem
import android.view.View
import android.widget.Toast
import androidx.activity.enableEdgeToEdge
import androidx.appcompat.app.AlertDialog
import androidx.appcompat.app.AppCompatActivity
import androidx.core.view.ViewCompat
import androidx.core.view.WindowInsetsCompat
import androidx.recyclerview.widget.LinearLayoutManager
import dduw.com.mobile.finalreport.data.BookDao
import dduw.com.mobile.finalreport.data.BookDto
import dduw.com.mobile.finalreport.databinding.ActivityMainBinding
import dduw.com.mobile.finalreport.databinding.ActivitySearchBinding

//모바일소프트웨어 최종과제
//과제명:도서 관리 앱
//분반:02 분반
//학번:20220769 성명:변서영
//제출일:2024년 6월 21일
class MainActivity : AppCompatActivity() {

    val REQ_ADD = 100
    val REQ_UPDATE = 200

    val binding by lazy {
        ActivityMainBinding.inflate(layoutInflater)
    }

    lateinit var books : ArrayList<BookDto>

    val bookDao by lazy {
        BookDao(this)
    }

    override fun onCreate(savedInstanceState: Bundle?) {
        super.onCreate(savedInstanceState)
        setContentView(binding.root)

        binding.bookList.layoutManager = LinearLayoutManager(this).apply {
            orientation = LinearLayoutManager.VERTICAL
        }

        books = bookDao.getAllBooks()
        val adapter = BookAdapter(books)
        binding.bookList.adapter = adapter

        adapter.setOnItemLongClickListener( object: BookAdapter.OnItemLongClickListener {
            override fun onItemLongClick(view: View, position: Int): Boolean {
                AlertDialog.Builder(this@MainActivity).apply{
                    setTitle("도서 삭제")
                    setMessage(books[position].title + "를 삭제하시겠습니까?")
                    setPositiveButton("삭제"){dialogInterface:DialogInterface?, i: Int->
                        if ( bookDao.deleteBook( books[position] ) > 0 ) {
                            books.clear()
                            books.addAll(bookDao.getAllBooks())
                            binding.bookList.adapter?.notifyDataSetChanged()
                        }
                    }
                    setNegativeButton("취소", null)
                    show()
                }
                return true
            }
        })

        adapter.setOnItemClickListener(object : BookAdapter.OnItemClickListener {
            override fun onItemClick(view: View, position: Int) {
                val intent = Intent(this@MainActivity, UpdateActivity::class.java)
                intent.putExtra("dto", books.get(position))
                startActivityForResult(intent, REQ_UPDATE)
            }
        })
    }

    override fun onActivityResult(requestCode: Int, resultCode: Int, data: Intent?) {
        super.onActivityResult(requestCode, resultCode, data)

        when (requestCode) {
            REQ_UPDATE -> {
                if (resultCode == RESULT_OK) {
                    books.clear()
                    books.addAll(bookDao.getAllBooks())
                    binding.bookList.adapter?.notifyDataSetChanged()
                }
            }
            REQ_ADD->{
                if (resultCode == RESULT_OK){
                    books.clear()
                    books.addAll(bookDao.getAllBooks())
                    binding.bookList.adapter?.notifyDataSetChanged()
                }
            }
        }
    }

    override fun onCreateOptionsMenu(menu: Menu?): Boolean {
        menuInflater.inflate(R.menu.menu_main, menu)
        return super.onCreateOptionsMenu(menu)
    }

    override fun onOptionsItemSelected(item: MenuItem): Boolean {
        when (item.itemId){
            R.id.addMenu -> {
                val intent = Intent(this@MainActivity, AddActivity::class.java)
                startActivityForResult(intent, REQ_ADD)
            }
            R.id.introduceMenu ->{
                val builder : AlertDialog.Builder = AlertDialog.Builder(this).apply{
                    setTitle("개발자 소개")
                    setIcon(R.mipmap.programmer)
                    setMessage("성명:변서영\n학번:20220769\n학년:3\n분반:02")
                    setPositiveButton("확인", null)
                }
                builder.show()
            }
            R.id.exitMenu->{
                AlertDialog.Builder(this).apply {
                    setTitle("앱 종료")
                    setMessage("앱을 종료하시겠습니까?")
                    setPositiveButton("종료"){dialogInterface:DialogInterface?, i: Int->
                        finish()
                    }
                    setNegativeButton("취소", null)
                    show()
                }
            }
            R.id.TitleSearchMenu->{
                val intent = Intent(this@MainActivity, TitleSearchActivity::class.java)
                startActivity(intent)
            }
            R.id.AuthorSearchMenu->{
                val intent = Intent(this@MainActivity, AuthorSearchActivity::class.java)
                startActivity(intent)
            }
        }

        return true
    }
}
