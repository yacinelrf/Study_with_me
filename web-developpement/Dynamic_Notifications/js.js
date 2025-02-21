




window.addEventListener('load',function(){
setTimeout(function(){
        
        document.getElementById("notif").style.marginTop="20vw"
},100);
});
z=0
i=0
y=0


//-------------------------------------------------------------------


document.getElementById("notif").onclick=function(){
    
if(i==0){
    document.getElementById("notifs").style.marginTop="-8vw"
    document.getElementById("notifs").style.width="20%"
    document.getElementById("notifs").style.height="25vw"
    document.getElementById("notifs").style.marginLeft="37vw"
    document.getElementById("notifs").style.zIndex="31"
    document.getElementById("msgs").style.marginTop="-100%"
    document.getElementById("ansr1").style.marginLeft="0%"
    document.getElementById("ansr1").style.height="10%"
    document.getElementById("ansr1").style.zIndex="-1"
    document.getElementById("ansr3").style.marginLeft="0%"
    document.getElementById("ansr3").style.height="10%"
    document.getElementById("ansr3").style.zIndex="-1"
    document.getElementById("ansr2").style.marginLeft="0%"
    document.getElementById("ansr2").style.height="10%"
    document.getElementById("ansr2").style.zIndex="-1"
    document.getElementById("prfl").style.left="100%"
    i=1
    z=0
}else{
    document.getElementById("notifs").style.marginTop="-14vw"
    document.getElementById("notifs").style.width="5%"
    document.getElementById("notifs").style.height="4vw"
    document.getElementById("notifs").style.marginLeft="45vw"
    document.getElementById("notifs").style.zIndex="-1"
    document.getElementById("ansr1").style.marginLeft="0%"
    document.getElementById("ansr1").style.height="10%"
    document.getElementById("ansr1").style.zIndex="-1"
    document.getElementById("ansr3").style.marginLeft="0%"
    document.getElementById("ansr3").style.height="10%"
    document.getElementById("ansr3").style.zIndex="-1"
    document.getElementById("ansr2").style.marginLeft="0%"
    document.getElementById("ansr2").style.height="10%"
    document.getElementById("ansr2").style.zIndex="-1"
    i=0
    z=1

}





}
//------------------------------------------------------------

function messages(x,y){
 e=0
 f=0
 g=0
document.getElementById(`${x}1`).onclick=function(){
    if(e==0){
        document.getElementById("ansr1").style.marginLeft=`${y}%`
        document.getElementById("ansr1").style.marginTop="4%"
        document.getElementById("ansr1").style.height="25vw"
        document.getElementById("ansr1").style.zIndex="30"
        document.getElementById("ansr3").style.marginLeft=`${y-y}%`
        document.getElementById("ansr3").style.height="10%"
        document.getElementById("ansr3").style.zIndex="10"
        document.getElementById("ansr2").style.marginLeft=`${y-y}%`
        document.getElementById("ansr2").style.height="10%"
        document.getElementById("ansr2").style.zIndex="10"
        document.getElementById("prfl").style.left="100%"
        f=0
        g=0
        e=1
    }else{
        document.getElementById("ansr1").style.marginLeft=`${y-y}%`
        document.getElementById("ansr1").style.height="10%"
        document.getElementById("ansr1").style.zIndex="10"
        e=0

    }
    
}


document.getElementById(`${x}2`).onclick=function(){
    if(f==0){
        document.getElementById("ansr2").style.marginLeft=`${y}%`
        document.getElementById("ansr2").style.height="25vw"
        document.getElementById("ansr2").style.zIndex="30"
        document.getElementById("ansr2").style.marginTop="6%"
        document.getElementById("ansr3").style.marginLeft=`${y-y}%`
        document.getElementById("ansr3").style.height="10%"
        document.getElementById("ansr3").style.zIndex="10"
        document.getElementById("ansr1").style.marginLeft=`${y-y}%`
        document.getElementById("ansr1").style.height="10%"
        document.getElementById("ansr1").style.zIndex="10"
        document.getElementById("prfl").style.left="100%"
        e=0
        g=0
        f=1
    }else{
        document.getElementById("ansr2").style.marginLeft=`${y-y}%`
        document.getElementById("ansr2").style.height="10%"
        document.getElementById("ansr2").style.zIndex="10"
        
        f=0
    }
}

document.getElementById(`${x}3`).onclick=function(){
    if(g==0){
        document.getElementById("ansr3").style.marginLeft=`${y}%`
        document.getElementById("ansr3").style.height="25vw"
        document.getElementById("ansr3").style.zIndex="30"
        document.getElementById("ansr3").style.marginTop="8%"
        document.getElementById("ansr1").style.marginLeft=`${y-y}%`
        document.getElementById("ansr1").style.height="10%"
        document.getElementById("ansr1").style.zIndex="10"
        document.getElementById("ansr2").style.marginLeft=`${y-y}%`
        document.getElementById("ansr2").style.height="10%"
        document.getElementById("ansr2").style.zIndex="10"
        document.getElementById("prfl").style.left="100%"
        f=0
        e=0
        g=1
    }else{
        document.getElementById("ansr3").style.marginLeft=`${y-y}%`
        document.getElementById("ansr3").style.height="10%"
        document.getElementById("ansr3").style.zIndex="10"

        g=0
    }
}
}
messages("ntf",22)




//----------------------------------------------------------




document.getElementById("xx").onclick=function(){
    document.getElementById("ntf3").style.marginLeft="200vw"
    document.getElementById("one").style.opacity="0"
    setTimeout(function(){
        document.getElementById("ntf2").style.marginLeft="200vw"
    },200)
    setTimeout(function(){
        document.getElementById("ntf1").style.marginLeft="200vw"
    },400)
  
}

shift=document.querySelectorAll('#xxx')
for(i==0;i<shift.length;i++){
shift[i].onclick=function(){
    document.getElementById("ansr1").style.marginLeft="0%"
    document.getElementById("ansr1").style.height="10%"
    document.getElementById("ansr1").style.zIndex="10"
    document.getElementById("ansr3").style.marginLeft="0%"
    document.getElementById("ansr3").style.height="10%"
    document.getElementById("ansr3").style.zIndex="10"
    document.getElementById("ansr2").style.marginLeft="0%"
    document.getElementById("ansr2").style.height="10%"
    document.getElementById("ansr2").style.zIndex="10"
    document.getElementById("prfl").style.left="100%"
    f=0
    g=0
    e=0
}
}


document.getElementById("messenger").onclick=function(){
    if(z==0){
    document.getElementById("msgs").style.marginTop="62%"
    document.getElementById("notifs").style.marginTop="-14vw"
    document.getElementById("notifs").style.width="5%"
    document.getElementById("notifs").style.height="4vw"
    document.getElementById("notifs").style.marginLeft="45vw"
    document.getElementById("notifs").style.zIndex="-1"
    document.getElementById("ansr1").style.marginLeft="0%"
        document.getElementById("ansr1").style.height="10%"
        document.getElementById("ansr1").style.zIndex="-1"
        document.getElementById("ansr3").style.marginLeft="0%"
        document.getElementById("ansr3").style.height="10%"
        document.getElementById("ansr3").style.zIndex="-1"
        document.getElementById("ansr2").style.marginLeft="0%"
        document.getElementById("ansr2").style.height="10%"
        document.getElementById("ansr2").style.zIndex="-1"
        document.getElementById("prfl").style.left="100%"
    z=1
    i=0
    }else{
        document.getElementById("msgs").style.marginTop="0%"
  
        document.getElementById("ansr1").style.marginLeft="0%"
        document.getElementById("ansr1").style.height="10%"
        document.getElementById("ansr1").style.zIndex="-1"
        document.getElementById("ansr3").style.marginLeft="0%"
        document.getElementById("ansr3").style.height="10%"
        document.getElementById("ansr3").style.zIndex="-1"
        document.getElementById("ansr2").style.marginLeft="0%"
        document.getElementById("ansr2").style.height="10%"
        document.getElementById("ansr2").style.zIndex="-1"
        z=0
        i=1
    }
}

document.getElementById("msg1").onclick=function(){
    messages("msg",30)
    document.getElementById("prfl").style.left="100%"

}
document.getElementById("xxxx").onclick=function(){
    document.getElementById("msgs").style.marginTop="0%"
    document.getElementById("notifs").style.marginTop="-14vw"
    document.getElementById("notifs").style.width="5%"
    document.getElementById("notifs").style.height="4vw"
    document.getElementById("notifs").style.marginLeft="45vw"
    document.getElementById("notifs").style.zIndex="-1"
    document.getElementById("ansr1").style.marginLeft="0%"
    document.getElementById("ansr1").style.height="10%"
    document.getElementById("ansr1").style.zIndex="-1"
    document.getElementById("ansr3").style.marginLeft="0%"
    document.getElementById("ansr3").style.height="10%"
    document.getElementById("ansr3").style.zIndex="-1"
    document.getElementById("ansr2").style.marginLeft="0%"
    document.getElementById("ansr2").style.height="10%"
    document.getElementById("ansr2").style.zIndex="-1"
    document.getElementById("prfl").style.left="100%"
    z=0
}



document.getElementById("profile").onclick=function(){
    if(y==0){
        document.getElementById("prfl").style.left="60%"
        document.getElementById("msgs").style.marginTop="0%"
        document.getElementById("notifs").style.marginTop="-14vw"
        document.getElementById("notifs").style.width="5%"
        document.getElementById("notifs").style.height="4vw"
        document.getElementById("notifs").style.marginLeft="45vw"
        document.getElementById("notifs").style.zIndex="-1"
        document.getElementById("ansr1").style.marginLeft="0%"
        document.getElementById("ansr1").style.height="10%"
        document.getElementById("ansr1").style.zIndex="-1"
        document.getElementById("ansr3").style.marginLeft="0%"
        document.getElementById("ansr3").style.height="10%"
        document.getElementById("ansr3").style.zIndex="-1"
        document.getElementById("ansr2").style.marginLeft="0%"
        document.getElementById("ansr2").style.height="10%"
        document.getElementById("ansr2").style.zIndex="-1"
        z=0
        y=1
    }else{
        document.getElementById("prfl").style.left="100%"
        y=0
        
    }
}