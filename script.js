
const vert = {
    top: 80,
    getRandom: function () {
        let ret =Math.floor(Math.random() * this.top);
        // console.log("To down value:"+ret);
        return ret;
    },
};
const horz = {
    right: 90,
    getRandom: function () {
        let ret = Math.floor(Math.random() * this.right); 
        console.log("To right value :"+ret);
        return ret;
    }
}

document.querySelector(".two").addEventListener("mouseenter", (event) => {
    let horizontal = horz.getRandom();
    let vertical = vert.getRandom();
    let butn = document.querySelector(".two");
    butn.style.position = "fixed";
    butn.style.top = vertical+"vh";
    butn.style.left = horizontal+"vw";
});

document.querySelector(".one").addEventListener("click",()=>{
    alert(toSay);
});

var toSay = "Yep. I know.";

var namex = prompt("Enter your name ");
if(namex.toLowerCase() === "pelican" || namex.toLowerCase() === "haans" || namex.toLowerCase().slice(0,8) === "sanchita tewary")
{
    alert("Heh.");
    document.querySelector(".question").textContent = "Do you love me ?";
} else if (namex.toLowerCase().slice(0,7) === "chandra"){
    alert("Welcome bro.");
    document.querySelector(".question").textContent = "Now tell me , are you chutiya ?";
} else {
    document.body.innerHTML = "";
    alert("Sorry, You are not authorized.");
}
