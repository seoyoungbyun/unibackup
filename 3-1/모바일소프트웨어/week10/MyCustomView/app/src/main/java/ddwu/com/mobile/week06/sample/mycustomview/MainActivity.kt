package ddwu.com.mobile.week06.sample.mycustomview

import android.graphics.Color
import android.os.Bundle
import android.view.ContextMenu
import android.view.Menu
import android.view.MenuItem
import android.view.View
import android.widget.Toast
import androidx.appcompat.app.AppCompatActivity
import ddwu.com.mobile.week06.sample.mycustomview.databinding.ActivityMainBinding

class MainActivity : AppCompatActivity() {

    val binding by lazy{
        ActivityMainBinding.inflate(layoutInflater)
    }

    override fun onCreate(savedInstanceState: Bundle?) {
        super.onCreate(savedInstanceState)
        setContentView(binding.root)

        registerForContextMenu(binding.myCustomView)
    }

    override fun onCreateOptionsMenu(menu: Menu?): Boolean {
        menuInflater.inflate(R.menu.menu_option, menu)
        return super.onCreateOptionsMenu(menu)
    }

    override fun onOptionsItemSelected(item: MenuItem): Boolean {
        when (item.itemId){
            R.id.big->{
                binding.myCustomView.radius = 200f
                binding.myCustomView.invalidate()
            }

            R.id.small->{
                binding.myCustomView.radius = 50f
                binding.myCustomView.invalidate()
            }
        }

        return true
    }

    override fun onCreateContextMenu(
        menu: ContextMenu?,
        v: View?,
        menuInfo: ContextMenu.ContextMenuInfo?
    ) {
        super.onCreateContextMenu(menu, v, menuInfo)
        when (v?.id) {
            R.id.myCustomView ->{
                menuInflater.inflate(R.menu.menu_context, menu)
                menu?.setHeaderTitle("Change Color")
            }
        }

        when (selected) {
            0 -> {
                menu?.findItem(R.id.red)?.setChecked(true)
            }

            1 -> {
                menu?.findItem(R.id.green)?.setChecked(true)
            }

            2 -> {
                menu?.findItem(R.id.blue)?.setChecked(true)
            }
        }
    }

    var selected = 0

    override fun onContextItemSelected(item: MenuItem): Boolean {
        when(item.itemId) {
            R.id.red -> {
                binding.myCustomView.paintColor = Color.RED
                binding.myCustomView.invalidate()
                selected = 0
            }

            R.id.green -> {
                binding.myCustomView.paintColor = Color.GREEN
                binding.myCustomView.invalidate()
                selected = 1
            }

            R.id.blue -> {
                binding.myCustomView.paintColor = Color.BLUE
                binding.myCustomView.invalidate()
                selected = 2
            }
        }
        return true
    }

}