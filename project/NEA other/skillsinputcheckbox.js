//ONLY CODE IF SUFFICIENT EXTRA TIME PERMITS

function checkboxoutput(skills_arr = ["Leadership", "Creativity", "Teamwork", "Initiative", ], x){
        for(let i = 0; i < tagged_arr.length; i++){        
        const title = document.createElement("h3");
        const node = document.createTextNode(tagged_arr[i]);
        title.appendChild(node);

        const text = document.createElement("textarea");
        const element = document.getElementById(x);
        element.appendChild(title);
        element.appendChild(text);
        }
}