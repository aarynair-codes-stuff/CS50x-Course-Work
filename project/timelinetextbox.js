function textboxoutput(tagged_arr, x){
        for(let i = 0; i < tagged_arr.length; i++){        
        const title = document.createElement("h1");
        title.htmlFor = tagged_arr[i];
        const node = document.createTextNode(tagged_arr[i]);
        title.appendChild(node);

        const text = document.createElement("textarea");
        text.id = tagged_arr[i];
        text.name = tagged_arr[i]; 

        const br = document.createElement("br");

        const element = document.getElementById(x);
        element.appendChild(br);
        element.appendChild(title);
        element.appendChild(text);
        }
}

