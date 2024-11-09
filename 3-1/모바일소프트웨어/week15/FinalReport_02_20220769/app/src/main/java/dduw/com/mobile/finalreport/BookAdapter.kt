package dduw.com.mobile.finalreport

import android.util.Log
import android.view.LayoutInflater
import android.view.View
import android.view.ViewGroup
import androidx.recyclerview.widget.RecyclerView
import dduw.com.mobile.finalreport.data.BookDto
import dduw.com.mobile.finalreport.databinding.ListItemBinding

class BookAdapter (val books : ArrayList<BookDto>)
    : RecyclerView.Adapter<BookAdapter.BookViewHolder>() {

    override fun getItemCount(): Int = books.size

    override fun onCreateViewHolder(parent: ViewGroup, viewType: Int): BookViewHolder {
        val itemBinding = ListItemBinding.inflate(LayoutInflater.from(parent.context), parent, false)
        return BookViewHolder(itemBinding)
    }

    override fun onBindViewHolder(holder: BookViewHolder, position: Int) {
        holder.itemBinding.cover.setImageResource(books[position].cover)
        holder.itemBinding.author.text = books[position].author
        holder.itemBinding.btitle.text = books[position].title
        holder.itemBinding.price.text = books[position].price.toString()
    }

    inner class BookViewHolder(val itemBinding: ListItemBinding)
        : RecyclerView.ViewHolder(itemBinding.root) {
        init {
            itemBinding.root.setOnClickListener{
                listener?.onItemClick(it, adapterPosition)

            }
            itemBinding.root.setOnLongClickListener {
                val result = longClickListener?.onItemLongClick(it, adapterPosition)
                true
            }
        }
    }

    interface OnItemLongClickListener{
        fun onItemLongClick(view: View, position: Int) : Boolean
    }

    lateinit var longClickListener: OnItemLongClickListener

    fun setOnItemLongClickListener (listener: OnItemLongClickListener){
        this.longClickListener = listener
    }

    var listener : OnItemClickListener? = null

    interface OnItemClickListener {
        fun onItemClick(view : View, position : Int)
    }

    fun setOnItemClickListener(listener: OnItemClickListener?) {
        this.listener = listener
    }
}