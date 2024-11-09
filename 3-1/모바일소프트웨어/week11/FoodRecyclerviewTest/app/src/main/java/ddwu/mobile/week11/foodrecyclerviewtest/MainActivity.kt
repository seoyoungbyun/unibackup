package ddwu.mobile.week11.foodrecyclerviewtest

import android.content.DialogInterface
import android.os.Bundle
import android.view.View
import androidx.activity.enableEdgeToEdge
import androidx.appcompat.app.AlertDialog
import androidx.appcompat.app.AppCompatActivity
import androidx.core.view.ViewCompat
import androidx.core.view.WindowInsetsCompat
import androidx.recyclerview.widget.LinearLayoutManager
import ddwu.mobile.week11.foodrecyclerviewtest.databinding.ActivityMainBinding
import ddwu.mobile.week11.foodrecyclerviewtest.databinding.ListItemBinding

class MainActivity : AppCompatActivity() {

    val binding by lazy {
        ActivityMainBinding.inflate(layoutInflater)
    }

    override fun onCreate(savedInstanceState: Bundle?) {
        super.onCreate(savedInstanceState)
        setContentView(binding.root)

        val foods = FoodDao().foods
        val adapter = FoodAdapter(foods)

        val layoutManager = LinearLayoutManager(this)
        layoutManager.orientation = LinearLayoutManager.VERTICAL

        binding.recyclerView.layoutManager = layoutManager
        binding.recyclerView.adapter = adapter

        val longClickListener = object: FoodAdapter.OnItemLongClickListener{
            override fun onItemLongClick(view: View, position: Int): Boolean {
                val builder : AlertDialog.Builder = AlertDialog.Builder(this@MainActivity).apply {
                    title = "삭제 확인"
                    setMessage("선택하신 항목을 삭제하시겠습니까?")
                    setPositiveButton("확인") { dialogInterface: DialogInterface?, i: Int ->
                        foods.removeAt(position)
                        adapter.notifyDataSetChanged()
                    }
                    setNegativeButton("취소", null)
                }
                builder.show()
                return true
            }
        }

        adapter.setOnItemLongClickListener(longClickListener)

        binding.button.setOnClickListener{
            foods.add(FoodDto(R.drawable.food02, binding.editText.text.toString(), 10))
        }
    }
}
