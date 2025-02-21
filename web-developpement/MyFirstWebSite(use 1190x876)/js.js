image_array=[
    '1.jpg',
    '2.jpg',
    '3.jpg',
    '4.jpg',
    '5.jpg'
]
image_array2=[
    '1.png',
    '2.jpg',
    '3.jpg',
    '4.jpg',
    '5.jpg'
]
image_array3=[
    '1.jpg',
    '2.jpg',
    '3.jpg',
    '4.jpg',
    '5.png'
]
dot_array=[
    'dot1.png',
    'dot2.png',
    'dot3.png',
    'dot4.png',
    'dot5.png'
]

dot=dot_array[0]
    document.getElementById('dot1').src=`${dot}`
dot=dot_array[1]
    document.getElementById('dot2').src=`${dot}`
dot=dot_array[2]
    document.getElementById('dot3').src=`${dot}`
dot=dot_array[3]
    document.getElementById('dot4').src=`${dot}`
dot=dot_array[4]
    document.getElementById('dot5').src=`${dot}`

    

    

selected_image=image_array[0]
    document.getElementById('image_shower').src=`./images/${selected_image}`



selected_image2=image_array2[1]
    document.getElementById('image2').src=`./images/${selected_image2}`


selected_image3=image_array3[-2]
    document.getElementById('image3').src=`./images/${selected_image3}`
    img=document.getElementById("g").style.marginLeft ="600px";



btnr=document.getElementById("btnr");
btnl=document.getElementById("btnl");
i=0;
document.getElementById(`dot${i+1}`).style.opacity="1"

    btnr.onclick=function(){
        img=document.getElementById("g").style.marginLeft ="520px";
        i=i+1;
        if(i<5){
        get_random_image(i);

        }else{
            i=4;
            get_random_image(i);
        }
        
    }
    btnl.onclick=function(){
        i=i-1;
        
        if(i==0){
            img=document.getElementById("g").style.marginLeft ="600px";
        }
        if(i>-1){
        get_random_image(i);
        }else{
            i=0;
            get_random_image(i);
        }
    }
    
    
function get_random_image(i){
    selected_image=image_array[i]
    selected_image2=image_array2[i+1]
    selected_image3=image_array3[i-1]
    document.getElementById('image_shower').src=`./images/${selected_image}`
    document.getElementById('image2').src=`./images/${selected_image2}`
    document.getElementById('image3').src=`./images/${selected_image3}`
    

    
    document.getElementById(`dot${i+1}`).style.opacity="1"
    for (let j = 0; j < 5; j++) {
       if(j!=i){
        document.getElementById(`dot${j+1}`).style.opacity="0.5"
       }
    }
    

}


