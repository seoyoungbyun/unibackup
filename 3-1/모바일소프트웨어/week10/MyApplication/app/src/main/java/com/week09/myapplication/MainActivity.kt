package com.week09.myapplication

import android.os.Bundle
import android.view.ContextMenu
import android.view.Menu
import android.view.MenuItem
import android.view.View
import android.widget.Toast
import androidx.appcompat.app.AppCompatActivity
import com.week09.myapplication.databinding.ActivityMainBinding

class MainActivity : AppCompatActivity() {

    val binding by lazy{
        ActivityMainBinding.inflate(layoutInflater)
    }
    override fun onCreate(savedInstanceState: Bundle?) {
        super.onCreate(savedInstanceState)
        setContentView(binding.root)

        registerForContextMenu(binding.tvText)
    }

    override fun onCreateContextMenu(
        menu: ContextMenu?,
        v: View?,
        menuInfo: ContextMenu.ContextMenuInfo?
    ) {
        super.onCreateContextMenu(menu, v, menuInfo)
        when (v?.id) {
            R.id.tvText ->menuInflater.inflate(R.menu.menu_main, menu)
        }
    }

    override fun onContextItemSelected(item: MenuItem): Boolean {
        when(item.itemId) {
            R.id.subitem021 -> {
                Toast.makeText(this, "context01", Toast.LENGTH_SHORT).show()
            }

            R.id.subitem022 -> {
                Toast.makeText(this, "context02", Toast.LENGTH_SHORT).show()
            }
        }
        return true
    }

    //var selected = 0

    override fun onCreateOptionsMenu(menu: Menu?): Boolean {
        menuInflater.inflate(R.menu.menu_main, menu)
        return super.onCreateOptionsMenu(menu)
    }

//    override fun onPrepareOptionsMenu(menu: Menu?): Boolean {
//        when (selected) {
//            0 -> {
//                menu?.findItem(R.id.subitem021)?.setChecked(true)
//            }
//
//            1 -> {
//                menu?.findItem(R.id.subitem022)?.setChecked(true)
//            }
//        }
//
//        return super.onPrepareOptionsMenu(menu)
//    }

    override fun onOptionsItemSelected(item: MenuItem): Boolean {
        when (item.itemId){
            R.id.subitem011 -> {
                Toast.makeText(this, "간짜장이최고", Toast.LENGTH_SHORT).show()
                //selected = 0
            }
            R.id.subitem012 ->{
                Toast.makeText(this, "짬뽕은 해물짬뽕", Toast.LENGTH_SHORT).show()
                //selected = 1
            }


            R.id.subitem021 -> {
                Toast.makeText(this, "김치찌개먹고싶다", Toast.LENGTH_SHORT).show()
                //selected = 0
            }
            R.id.subitem022 ->{
                Toast.makeText(this, "맛있지..순두부찌개", Toast.LENGTH_SHORT).show()
                //selected = 1
            }
        }

        return true
    }

//    fun onMenuClick(menu:Menu?){
//        Toast.makeText(this,"item",Toast.LENGTH_SHORT).show()
//    }
}