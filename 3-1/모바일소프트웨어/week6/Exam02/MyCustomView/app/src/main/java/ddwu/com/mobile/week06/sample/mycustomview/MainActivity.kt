package ddwu.com.mobile.week06.sample.mycustomview

import android.graphics.Color
import android.os.Bundle
import android.view.MotionEvent
import android.view.View
import androidx.appcompat.app.AppCompatActivity
import ddwu.com.mobile.week06.sample.mycustomview.databinding.ActivityMainBinding

class MainActivity : AppCompatActivity() {
    val mainBinding by lazy{
        ActivityMainBinding.inflate(layoutInflater)
    }

    override fun onCreate(savedInstanceState: Bundle?) {
        super.onCreate(savedInstanceState)
        setContentView(mainBinding.root)

       mainBinding.myCustomView.setOnTouchListener(myTouch)
        mainBinding.myCustomView.setOnLongClickListener(myLongClick)
    }

    val myTouch = object : View.OnTouchListener{
        override fun onTouch(v: View?, event: MotionEvent?): Boolean {
            mainBinding.myCustomView.posX = event!!.x
            mainBinding.myCustomView.posY = event!!.y
            mainBinding.myCustomView.invalidate()

            return false
        }
    }

    val myLongClick = object : View.OnLongClickListener{
        override fun onLongClick(v: View?): Boolean {
            mainBinding.myCustomView.paintColor = Color.BLUE
            mainBinding.myCustomView.invalidate()

            return true
        }
    }

}