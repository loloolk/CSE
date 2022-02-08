aList = ["source/Justanub gets rekt_.mp4", "source/fundyclass.mp4", "source/DIDIGIVEFUNDYARELIC.mp4", "source/IWASNOTICED.mp4"]
titleList = ["A clip of Justanub getting reks on a minecraft bending server", "Fundy realising he is beinh watched by a class", "Me possibly giving Fundy a relic on the Vault Hunter's server", "Being noticed by CarlSagan"]
descList = ["This is on a Minecraft multiplayer avatar bending server. It was an air bender at the time and used my air powers to spin the TNT into the person who lit it.", "desc2", "desc3", "desc4"]
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
