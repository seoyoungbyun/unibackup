package ddwu.moblie.week4.hw1

import android.os.Bundle
import android.view.View
import android.widget.TextView
import android.widget.Toast
import androidx.appcompat.app.AppCompatActivity

class MainActivity : AppCompatActivity() {
    override fun onCreate(savedInstanceState: Bundle?) {
        super.onCreate(savedInstanceState)
        setContentView(R.layout.activity_main)
    }

    fun onClickHello(view : View){
        val name: TextView = findViewById(R.id.etName)
        val tel : TextView = findViewById(R.id.etPhone)

        Toast.makeText(this, "안녕하세요, 저는 ${name.text} 입니다.\n전화번호는 ${tel.text} 입니다.", Toast.LENGTH_SHORT).show()
    }

    fun onClickExit(view : View){
        finish()
    }
}