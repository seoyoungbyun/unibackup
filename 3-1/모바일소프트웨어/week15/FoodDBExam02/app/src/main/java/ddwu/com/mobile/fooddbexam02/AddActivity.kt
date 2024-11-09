package ddwu.com.mobile.fooddbexam02

import androidx.appcompat.app.AppCompatActivity
import android.os.Bundle
import ddwu.com.mobile.fooddbexam02.databinding.ActivityAddBinding

class AddActivity : AppCompatActivity() {

    val addBinding by lazy {
        ActivityAddBinding.inflate(layoutInflater)
    }

    override fun onCreate(savedInstanceState: Bundle?) {
        super.onCreate(savedInstanceState)

        setContentView(addBinding.root)

        /*EditText에서 값을 읽어와 DB에 저장*/
        addBinding.btnAddFood.setOnClickListener{

            finish()
        }

        addBinding.btnAddCancel.setOnClickListener{
            finish()
        }

    }

//    fun addFood(newDto : FoodDto) : Int {
//
//        return 0
//    }

}