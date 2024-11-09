package ddum.com.mobile.week09.naverretrofitsample

import android.graphics.Bitmap
import android.graphics.BitmapFactory
import android.graphics.drawable.Drawable
import android.os.Bundle
import androidx.activity.enableEdgeToEdge
import androidx.appcompat.app.AppCompatActivity
import androidx.core.view.ViewCompat
import androidx.core.view.WindowInsetsCompat
import com.bumptech.glide.Glide
import com.bumptech.glide.request.target.CustomTarget
import com.bumptech.glide.request.transition.Transition
import ddum.com.mobile.week09.naverretrofitsample.data.util.FileManager
import ddum.com.mobile.week09.naverretrofitsample.data.util.FileManager.Companion.getCurrentTime
import ddum.com.mobile.week09.naverretrofitsample.databinding.ActivityDetailBinding
import java.io.File
import java.io.FileOutputStream

class DetailActivity : AppCompatActivity() {

    val detailBinding by lazy {
        ActivityDetailBinding.inflate(layoutInflater)
    }

    var imageUrl: String? = null

    override fun onCreate(savedInstanceState: Bundle?) {
        super.onCreate(savedInstanceState)
        setContentView(detailBinding.root)

        // MainActivity 로부터 전달받은 이미지의 URL
        imageUrl = intent.getStringExtra("url")

        val initImage = detailBinding.ivBookCover.drawable

        Glide.with(this)
            .load(imageUrl)
            .into(detailBinding.ivBookCover)

        FileManager.createSubDirectory(filesDir, "images")

        //파일 이름 저장
        var currTime: String? = null
        detailBinding.btnSave.setOnClickListener {
            Glide.with(this)
                .asBitmap()
                .load(imageUrl)
                .into(object : CustomTarget<Bitmap>(350, 350) {
                    override fun onResourceReady(
                        resource: Bitmap,
                        transition: Transition<in Bitmap>?
                    ) {
                        currTime = FileManager.getCurrentTime()
                        val imageFile = File("${filesDir}/images", "${currTime}.jpg")
                        val fos = FileOutputStream(imageFile)
                        resource.compress(Bitmap.CompressFormat.JPEG, 100, fos)
                        fos.close()
                    }

                    override fun onLoadCleared(placeholder: Drawable?) {
                        TODO("Not yet implemented")
                    }

                })
        }

        detailBinding.btnRead.setOnClickListener {
            val imageFile = File("${filesDir}/images", "${currTime}.jpg")
            val bitmap = BitmapFactory.decodeFile(imageFile.path)
            Glide.with(this)
                .load(bitmap)
                .into(detailBinding.ivBookCover)
        }

        detailBinding.btnInit.setOnClickListener {
            Glide.with(this)
                .load(initImage)
                .into(detailBinding.ivBookCover)
        }

        detailBinding.btnRemove.setOnClickListener {
            val deleteFile = File("${filesDir}/images", "${currTime}.jpg")
            deleteFile.delete()
        }
    }
}