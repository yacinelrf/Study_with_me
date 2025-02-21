document.getElementById("lft").addEventListener('click', function () {
    document.getElementById("lft").style.backgroundColor = "rgb(49, 49, 86)"
    document.getElementById("rgt").style.backgroundColor = "rgb(26, 26, 46)"
})

document.getElementById("rgt").addEventListener('click', function () {
    document.getElementById("rgt").style.backgroundColor = "rgb(49, 49, 86)"
    document.getElementById("lft").style.backgroundColor = "rgb(26, 26, 46)"
})


let previous = null;
const amount = document.querySelectorAll(".amount p");
amount.forEach(element => {

    element.addEventListener('click', function () {
        //reset the previos element
        if (previous) {
            previous.style.backgroundColor = "rgb(49, 49, 86)";
            previous.style.color = "white";
        }

        element.style.backgroundColor = "white";
        element.style.color = "rgb(49, 49, 86)";
        previous = element;
    })
}
);