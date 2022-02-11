aList = ["video1.mp4", "video2.mp4"]
titleList = ["Title1", "Title2]
descList = ["desc1", "desc2"]
let currentVideo = 0;


function loadVideo() {
    var title = document.getElementById("title");
    title.innerHTML = titleList[currentVideo];

    var desc = document.getElementById("desc");
    desc.innerHTML = descList[currentVideo];

    var video = document.getElementById("video");
    video.src = aList[currentVideo]; 
    
    video.load();
    video.play();
    return;
}

function nextVideo() {
    if (currentVideo == aList.length - 1) {
        currentVideo = -1;
    }
    currentVideo++;
    loadVideo();
}

function lastVideo() {
    if (currentVideo == 0) {
        currentVideo = aList.length;
    }
    currentVideo--;
    loadVideo();
}
