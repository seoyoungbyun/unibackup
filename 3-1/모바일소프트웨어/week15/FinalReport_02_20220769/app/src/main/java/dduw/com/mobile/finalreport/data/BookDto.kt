package dduw.com.mobile.finalreport.data

import java.io.Serializable

data class BookDto(val id: Long, var title: String, var author: String, var publisher: String, var price: Int, var rating: Float, var cover: Int) : Serializable
