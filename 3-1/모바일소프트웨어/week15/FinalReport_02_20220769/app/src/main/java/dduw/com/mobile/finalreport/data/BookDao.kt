package dduw.com.mobile.finalreport.data

import android.annotation.SuppressLint
import android.content.ContentValues
import android.content.Context
import android.provider.BaseColumns
import android.util.Log

class BookDao(val context: Context) {
    fun deleteBook(dto: BookDto) : Int {
        val helper = BookDBHelper(context)
        val db = helper.writableDatabase

        val whereClause = "${BaseColumns._ID}=?"
        val whereArgs = arrayOf(dto.id.toString())

        return db.delete(BookDBHelper.TABLE_NAME, whereClause, whereArgs)
    }

    fun addBook(newDto : BookDto) : Long {
        val helper = BookDBHelper(context)
        val db = helper.writableDatabase

        val newValue = ContentValues()
        newValue.put(BookDBHelper.COL_BOOK, newDto.title)
        newValue.put(BookDBHelper.COL_AUTHOR, newDto.author)
        newValue.put(BookDBHelper.COL_PUBLISHER, newDto.publisher)
        newValue.put(BookDBHelper.COL_PRICE, newDto.price)
        newValue.put(BookDBHelper.COL_RATING, newDto.rating)
        newValue.put(BookDBHelper.COL_COVER, newDto.cover)

        val newCount = db.insert(BookDBHelper.TABLE_NAME, null, newValue)

        helper.close()
        return newCount
    }

    fun updateBook(dto: BookDto): Int {
        val helper = BookDBHelper(context)
        val db = helper.writableDatabase

        val updateValue = ContentValues()
        updateValue.put(BookDBHelper.COL_BOOK, dto.title)
        updateValue.put(BookDBHelper.COL_AUTHOR, dto.author)
        updateValue.put(BookDBHelper.COL_PUBLISHER, dto.publisher)
        updateValue.put(BookDBHelper.COL_PRICE, dto.price)
        updateValue.put(BookDBHelper.COL_RATING, dto.rating)
        val whereClause = "${BaseColumns._ID}=?"
        val whereArgs = arrayOf(dto.id.toString())

        val resultCount =  db.update(BookDBHelper.TABLE_NAME, updateValue, whereClause, whereArgs)

        helper.close()
        return resultCount
    }

    @SuppressLint("Range")
    fun searchBook(columns : String, word : String) : ArrayList<BookDto>{
        val helper = BookDBHelper(context)
        val db = helper.readableDatabase
        val selection = "${columns}=?"
        val selectionArgs = arrayOf(word)
        val cursor = db.query(BookDBHelper.TABLE_NAME, null, selection, selectionArgs, null, null, null, null)

        val books = arrayListOf<BookDto>()
        with (cursor){
            while(moveToNext()){
                val id = getInt( getColumnIndex(BaseColumns._ID) ).toLong()
                val book = getString ( getColumnIndex(BookDBHelper.COL_BOOK) )
                val author = getString ( getColumnIndex(BookDBHelper.COL_AUTHOR) )
                val publisher = getString ( getColumnIndex(BookDBHelper.COL_PUBLISHER) )
                val price = getInt ( getColumnIndex(BookDBHelper.COL_PRICE) )
                val rating = getFloat(getColumnIndex(BookDBHelper.COL_RATING))
                val cover = getInt(getColumnIndex(BookDBHelper.COL_COVER))
                val dto = BookDto(id, book, author, publisher, price, rating, cover)
                books.add(dto)
            }
        }

        return books
    }

    @SuppressLint("Range")
    fun getAllBooks() : ArrayList<BookDto> {
        val helper = BookDBHelper(context)
        val db = helper.readableDatabase
        val cursor = db.query(BookDBHelper.TABLE_NAME, null, null, null, null, null, null)

        val books = arrayListOf<BookDto>()
        with (cursor) {
            while (moveToNext()) {
                val id = getInt( getColumnIndex(BaseColumns._ID) ).toLong()
                val book = getString ( getColumnIndex(BookDBHelper.COL_BOOK) )
                val author = getString ( getColumnIndex(BookDBHelper.COL_AUTHOR) )
                val publisher = getString ( getColumnIndex(BookDBHelper.COL_PUBLISHER) )
                val price = getInt ( getColumnIndex(BookDBHelper.COL_PRICE) )
                val rating = getFloat(getColumnIndex(BookDBHelper.COL_RATING))
                val cover = getInt(getColumnIndex(BookDBHelper.COL_COVER))
                val dto = BookDto(id, book, author, publisher, price, rating, cover)
                books.add(dto)
            }
        }
        return books
    }
}