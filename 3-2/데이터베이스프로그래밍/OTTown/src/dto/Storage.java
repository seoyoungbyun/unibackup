package dto;

import recommendation.OTTRecommendation;
import java.util.ArrayList;
import java.util.List;

public class Storage {
    private Long consumerId;
    private List<Content> contentList;
    
    public Storage() {}

    public Storage(Long consumerId, List<Content> contentList) {
        this.consumerId = consumerId;
        this.contentList = contentList;
    }

    public Long getConsumerId() {
        return consumerId;
    }

    public void setUserId(Long consumerId) {
        this.consumerId = consumerId;
    }

    public List<Content> getContentList() {
        return contentList;
    }

    public void setContentList(List<Content> contentList) {
        this.contentList = contentList;
    }
}


