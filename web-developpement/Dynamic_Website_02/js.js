btn=document.getElementById("boton")
notif=document.getElementById("notif")
settings=document.getElementById("settings")
setbtn=document.getElementById("background")
ntf=document.querySelector(".bell")
body=document.getElementById("body")

btn.onclick=function(){
    document.getElementById("notif").style.marginTop="2%"
    //the notification will move down in 2000ms
    setTimeout(function() {
        notif.style.marginTop = "-5.5%";
    }, 2000);
    
}



i=0;
settings.onclick=function(){
    if(i==0){
    document.getElementById("dark").style.marginTop="47vw";
    document.getElementById("notifs").style.marginTop="-27vw";
    i=1
    x=0;
}else{
    document.getElementById("dark").style.marginTop="-20vw";
    i=0
}
}

x=0;
ntf.onclick=function(){
    if(x==0){
    document.getElementById("notifs").style.marginTop="42vw";
    document.getElementById("dark").style.marginTop="-20vw";
    i=0;
    x=1
}else{
    document.getElementById("notifs").style.marginTop="-27vw";
    x=0
}
}


j=0;
setbtn.onclick=function(){
    if(i==0){

        document.getElementById("body").style.backgroundColor="rgb(213, 233, 250)";

        document.getElementById("white").style.backgroundColor="white";
        document.getElementById("background").style.backgroundColor="rgb(53, 82, 82)";
        //green rgb(53, 82, 82)
        document.getElementById("white").style.marginLeft="0%";
        document.getElementById("dark").style.backgroundColor="rgb(53, 82, 82)";


        var bgd = document.querySelectorAll("#bgdark");
        var bgl = document.querySelectorAll("#bglight");
        var txt=document.querySelectorAll("#text");
        // Loop through each element and change its background color
        bgd.forEach(function(container) {
            container.style.backgroundColor = "rgb(53, 82, 82)";

        });
        bgl.forEach(function(container) {
            container.style.backgroundColor = "rgb(213, 233, 250)";

        });
        
        document.getElementById("settings").style.backgroundColor="rgb(213, 233, 250)";
        i=1
        txt.forEach(function(font){
            font.style.color="white"
          });






        //first click
    }else{

        document.getElementById("body").style.backgroundColor="rgb(26, 40, 40)";
        //blue rgb(213, 233, 250)
        document.getElementById("white").style.backgroundColor="rgb(53, 82, 82)";
        document.getElementById("background").style.backgroundColor="white";
        document.getElementById("white").style.marginLeft="50%";
        document.getElementById("dark").style.backgroundColor="rgb(213, 233, 250)";
        var bgd = document.querySelectorAll("#bgdark");
        var bgl = document.querySelectorAll("#bglight"); 
        var txt=document.querySelectorAll("#text");
        // Loop through each element and change its background color
        bgd.forEach(function(container) {
            container.style.backgroundColor = "rgb(213, 233, 250)";
        });
        bgl.forEach(function(container) {
            container.style.backgroundColor = "rgb(53, 82, 82)";
        });
        document.getElementById("settings").style.backgroundColor="rgb(53, 82, 82)";
        i=0
        txt.forEach(function(font){
          font.style.color="black"
        }

        );
    }
}


window.addEventListener('load',function(){
    setTimeout(function() {
        document.getElementById("firstpage").style.marginTop="-70vw"
    }, 7000);
    document.getElementById("firstpage").style.marginTop="0vw"
});