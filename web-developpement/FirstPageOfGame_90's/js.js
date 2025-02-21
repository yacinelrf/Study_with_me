
window.addEventListener('load',function(){

    document.getElementById("elm1").style.marginTop="40%"
    setTimeout(function(){
            document.getElementById("elm2").style.marginTop="55%"
    },1000);
    setTimeout(function(){
        document.getElementById("elm3").style.marginTop="40%"
    },2000);
    });
 
    document.getElementById("btn1").onclick=function(){
        document.getElementById("gif1").style.zIndex="2"
        setTimeout(
            function(){
                document.getElementById("gif2").style.zIndex="3"
            },5000
        )
        setTimeout(
            function(){
                document.getElementById("txt").style.zIndex="3"
            },10000
        )
        setTimeout(
            function(){
                document.getElementById("txt").style.zIndex="-3"
                document.getElementById("gif2").style.zIndex="-3"
                document.getElementById("gif1").style.zIndex="-2"
            },15000
        )
        
    }

   











document.querySelector( "#retrobg-sun" ).onclick = () => {
    document.querySelector( "#retrobg" ).classList.toggle( "retrobg-shutdown" );
  };