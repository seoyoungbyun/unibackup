package dduw.com.mobile.finalreport.data

import android.content.ContentValues
import android.content.Context
import android.database.sqlite.SQLiteDatabase
import android.database.sqlite.SQLiteOpenHelper
import android.provider.BaseColumns
import android.util.Log
import dduw.com.mobile.finalreport.R

class BookDBHelper (context: Context?) : SQLiteOpenHelper(context, DB_NAME, null, 1) {

    companion object {
        const val DB_NAME = "book_db"
        const val TABLE_NAME = "book_table"
        const val COL_BOOK = "title"
        const val COL_AUTHOR = "author"
        const val COL_PUBLISHER = "publisher"
        const val COL_PRICE = "price"
        const val COL_RATING = "rating"
        const val COL_COVER = "cover"
    }

    override fun onCreate(db: SQLiteDatabase?) {

        val CREATE_TABLE =
            "CREATE TABLE $TABLE_NAME ( ${BaseColumns._ID} INTEGER PRIMARY KEY AUTOINCREMENT, " +
                    "$COL_BOOK TEXT, $COL_AUTHOR TEXT, $COL_PUBLISHER TEXT, $COL_PRICE INTEGER, $COL_RATING REAL, $COL_COVER INTEGER)"
        db?.execSQL(CREATE_TABLE)

        val arr = arrayOf(
            arrayOf("지구 끝의 온실", "김초엽", "자이언트북스", 13500, (4.0).toFloat(), R.mipmap.book1),
            arrayOf("프로젝트 헤일메리", "앤디 위어", "알에이치코리아", 19800, (4.5).toFloat(), R.mipmap.book2),
            arrayOf("천 개의 파랑", "천선란", "허블", 12600, (3.0).toFloat(), R.mipmap.book3),
            arrayOf("모순", "양귀자", "쓰다", 11700, (4.5).toFloat(), R.mipmap.book4),
            arrayOf("물고기는 존재하지 않는다", "룰루 밀러", "곰출판", 15300, (2.5).toFloat(), R.mipmap.book5)
        )

        for (book in arr){
            var newRow = ContentValues()
            newRow.put("$COL_BOOK", book[0].toString())
            newRow.put("$COL_AUTHOR", book[1].toString())
            newRow.put("$COL_PUBLISHER", book[2].toString())
            newRow.put("$COL_PRICE", book[3] as Int)
            newRow.put("$COL_RATING", book[4] as Float)
            newRow.put("$COL_COVER", book[5] as Int)
            db?.insert("$TABLE_NAME", null, newRow)
        }
    }


    override fun onUpgrade(db: SQLiteDatabase?, oldVer: Int, newVer: Int) {
        val DROP_TABLE ="DROP TABLE IF EXISTS $TABLE_NAME"
        db?.execSQL(DROP_TABLE)
        onCreate(db)
    }
}