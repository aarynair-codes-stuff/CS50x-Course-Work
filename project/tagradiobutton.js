function radiobuttonoutput(tags, x){
        for(let i = 0; i < tags.length; i++){        
        const title = document.createElement("label");
        title.htmlFor = tags[i];
        const node = document.createTextNode(tags[i]);
        title.appendChild(node);

        const input = document.createElement("input");
        input.type = "radio";
        input.name = tags[i];
        input.value = tags[i];
        input.id = tags[i];
        const element = document.getElementById(x);

        const br = document.createElement("br");

        element.appendChild(br);
        element.appendChild(title);
        element.appendChild(input);
        }
}