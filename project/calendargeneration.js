// Function to return the correct ordinal suffix for a day
// For example: 1 → "st", 2 → "nd", 3 → "rd", 4 → "th"
function ordinal(n) {
    // Special case: 11, 12, 13 always end with "th"
    if (n >= 11 && n <= 13) return "th";

    // Check last digit of the number using modulo operator
    if (n % 10 === 1) return "st";  // 1, 21, 31 → "st"
    if (n % 10 === 2) return "nd";  // 2, 22 → "nd"
    if (n % 10 === 3) return "rd";  // 3, 23 → "rd"

    // All other numbers get "th"
    return "th";
}

// Function to create a table cell (<td>) containing a clickable day button
function createDayCell(day, monthName) {
    // 1. Create a table cell (<td>) to hold the day
    const td = document.createElement("td");
    td.className = "calendar-cell"; // Add a CSS class to <td> for styling

    // 2. Create a form element for this day
    const form = document.createElement("form");
    form.method = "GET";           // Use GET method
    form.action = "inputform.php"; // Submit to server

    // 3. Create a hidden input to store the full date
    const hidden = document.createElement("input");
    hidden.type = "hidden";                 // Hidden from user
    hidden.name = "date";                   // Form field name
    hidden.value = day + ordinal(day) + " of " + monthName; // e.g. "1st of January"

    // 4. Create the visible submit button for this day
    const submit = document.createElement("input");
    submit.type = "submit";                  // Make it clickable
    submit.value = day + ordinal(day);       // Button text: e.g. "1st"

    // 5. Add a CSS class to the button for styling
    submit.className = "calendar-day";       // Assign class "calendar-day"

    // 6. Add hidden input and button to the form
    form.appendChild(hidden);
    form.appendChild(submit);

    // 7. Add the form to the table cell
    td.appendChild(form);

    // 8. Return the completed table cell
    return td;
}


/*
function replaceJanuary() {
    // 1. Select the container div where the calendar will be displayed
    const container = document.getElementById("2");

    // 2. Create a heading element (<h2>) for the month title
    const heading = document.createElement("h2");
    heading.textContent = "January 2026"; // Set the heading text

    // 3. Create a table element for the calendar grid
    const table = document.createElement("table");

    // 4. Define the calendar layout using a 2D array
    // null = empty cell, numbers = actual days
    const rows = [
        [null,null,null,null,1,2,3],
        [4,5,6,7,8,9,10],
        [11,12,13,14,15,16,17],
        [18,19,20,21,22,23,24],
        [25,26,27,28,29,30,31]
    ];

    // 5. Loop through each week in the calendar
    for (let i = 0; i < rows.length; i++) {
        const tr = document.createElement("tr"); // Create a table row

        // 6. Loop through each day in the week
        for (let j = 0; j < rows[i].length; j++) {
            if (rows[i][j] === null) {
                // 6a. If the cell is null, create an empty <td>
                tr.appendChild(document.createElement("td"));
            } else {
                // 6b. If the cell is a day, create a clickable day cell
                tr.appendChild(createDayCell(rows[i][j], "January"));
            }
        }

        // 7. Append the completed row to the table
        table.appendChild(tr);
    }

    // 8. Replace any existing content in the container with the new heading and table
    container.replaceChildren(heading, table);
}

function replaceJanuary() {
    const container = document.getElementById("2"); // Select container
    const heading = document.createElement("h2");   // Create month heading
    heading.textContent = "January 2026";

    const table = document.createElement("table");
    table.className = "calendar-table";            // CSS class for table

    const rows = [
        [null,null,null,null,1,2,3],
        [4,5,6,7,8,9,10],
        [11,12,13,14,15,16,17],
        [18,19,20,21,22,23,24],
        [25,26,27,28,29,30,31]
    ];

    for (let i = 0; i < rows.length; i++) {
        const tr = document.createElement("tr");
        tr.className = "calendar-row";            // CSS class for row

        for (let j = 0; j < rows[i].length; j++) {
            if (rows[i][j] === null) {
                const td = document.createElement("td");
                td.className = "calendar-cell";   // CSS class for empty cell
                tr.appendChild(td);
            } else {
                tr.appendChild(createDayCell(rows[i][j], "January")); // Day cell already has class
            }
        }
        table.appendChild(tr);
    }

    container.replaceChildren(heading, table);    // Replace old content
}
*/

function replaceJanuary() {
    // Get the container div
    const container = document.getElementById("calendar-container");

    // Create month heading
    const heading = document.createElement("h2");
    heading.textContent = "January 2026";
    heading.className = "calendar-header";

    // Create table
    const table = document.createElement("table");
    table.className = "calendar-table";

    // -------------------------
    // Weekday header row starting with Monday
    // -------------------------
    const headerRow = document.createElement("tr");
    headerRow.className = "calendar-row";
    const daysOfWeek = ["Mon","Tue","Wed","Thu","Fri","Sat","Sun"];
    for (let i = 0; i < daysOfWeek.length; i++) {
        const th = document.createElement("th");
        th.className = "calendar-cell calendar-weekday";
        th.textContent = daysOfWeek[i];
        headerRow.appendChild(th);
    }
    table.appendChild(headerRow);

    // -------------------------
    // Calendar layout for January 2026
    // Adjusted so Monday is first column
    // -------------------------
    const rows = [
        [null, null, null, 1, 2, 3, 4],    // 1st Jan 2026 is Thursday
        [5,6,7,8,9,10,11],
        [12,13,14,15,16,17,18],
        [19,20,21,22,23,24,25],
        [26,27,28,29,30,31,null]
    ];

    // Loop through weeks
    for (let i = 0; i < rows.length; i++) {
        const tr = document.createElement("tr");
        tr.className = "calendar-row";

        for (let j = 0; j < rows[i].length; j++) {
            if (rows[i][j] === null) {
                const td = document.createElement("td");
                td.className = "calendar-cell"; // Empty cell
                tr.appendChild(td);
            } else {
                tr.appendChild(createDayCell(rows[i][j], "January"));
            }
        }

        table.appendChild(tr);
    }

    // Replace container content
    container.replaceChildren(heading, table);
}





function replaceFebruary() {
    const container = document.getElementById("calendar-container");

    const heading = document.createElement("h2");
    heading.textContent = "February 2026";
    heading.className="calendar-header";

    const table=document.createElement("table");
    table.className="calendar-table";

    const headerRow=document.createElement("tr");
    headerRow.className="calendar-row";
    const daysOfWeek=["Mon","Tue","Wed","Thu","Fri","Sat","Sun"];
    for(let i=0;i<daysOfWeek.length;i++){
        const th=document.createElement("th");
        th.className="calendar-cell calendar-weekday";
        th.textContent=daysOfWeek[i];
        headerRow.appendChild(th);
    }
    table.appendChild(headerRow);

    // Feb 1, 2026 is Sunday → last column
    const rows=[
        [null,null,null,null,null,null,1],
        [2,3,4,5,6,7,8],
        [9,10,11,12,13,14,15],
        [16,17,18,19,20,21,22],
        [23,24,25,26,27,28,null]
    ];

    for(let i=0;i<rows.length;i++){
        const tr=document.createElement("tr");
        tr.className="calendar-row";

        for(let j=0;j<rows[i].length;j++){
            if(rows[i][j]===null){
                const td=document.createElement("td");
                td.className="calendar-cell";
                tr.appendChild(td);
            } else {
                tr.appendChild(createDayCell(rows[i][j],"February"));
            }
        }
        table.appendChild(tr);
    }

    container.replaceChildren(heading,table);
}





function replaceMarch() {
    const container=document.getElementById("calendar-container");

    const heading=document.createElement("h2");
    heading.textContent="March 2026";
    heading.className="calendar-header";

    const table=document.createElement("table");
    table.className="calendar-table";

    const headerRow=document.createElement("tr");
    headerRow.className="calendar-row";
    const daysOfWeek=["Mon","Tue","Wed","Thu","Fri","Sat","Sun"];
    for(let i=0;i<daysOfWeek.length;i++){
        const th=document.createElement("th");
        th.className="calendar-cell calendar-weekday";
        th.textContent=daysOfWeek[i];
        headerRow.appendChild(th);
    }
    table.appendChild(headerRow);

    // Mar 1, 2026 is Sunday → last column
    const rows=[
        [null,null,null,null,null,null,1],
        [2,3,4,5,6,7,8],
        [9,10,11,12,13,14,15],
        [16,17,18,19,20,21,22],
        [23,24,25,26,27,28,29],
        [30,31,null,null,null,null,null]
    ];

    for(let i=0;i<rows.length;i++){
        const tr=document.createElement("tr");
        tr.className="calendar-row";

        for(let j=0;j<rows[i].length;j++){
            if(rows[i][j]===null){
                const td=document.createElement("td");
                td.className="calendar-cell";
                tr.appendChild(td);
            } else {
                tr.appendChild(createDayCell(rows[i][j],"March"));
            }
        }
        table.appendChild(tr);
    }

    container.replaceChildren(heading,table);
}





function replaceApril() {
    const container = document.getElementById("calendar-container");

    const heading = document.createElement("h2");
    heading.textContent = "April 2026";
    heading.className = "calendar-header";

    const table = document.createElement("table");
    table.className = "calendar-table";

    const headerRow = document.createElement("tr");
    headerRow.className = "calendar-row";
    const daysOfWeek = ["Mon","Tue","Wed","Thu","Fri","Sat","Sun"];
    for (let i=0;i<daysOfWeek.length;i++){
        const th = document.createElement("th");
        th.className = "calendar-cell calendar-weekday";
        th.textContent = daysOfWeek[i];
        headerRow.appendChild(th);
    }
    table.appendChild(headerRow);

    // April 1, 2026 is Wednesday → 3rd column
    const rows = [
        [null,null,1,2,3,4,5],
        [6,7,8,9,10,11,12],
        [13,14,15,16,17,18,19],
        [20,21,22,23,24,25,26],
        [27,28,29,30,null,null,null]
    ];

    for(let i=0;i<rows.length;i++){
        const tr = document.createElement("tr");
        tr.className="calendar-row";

        for(let j=0;j<rows[i].length;j++){
            if(rows[i][j]===null){
                const td = document.createElement("td");
                td.className="calendar-cell";
                tr.appendChild(td);
            } else {
                tr.appendChild(createDayCell(rows[i][j],"April"));
            }
        }
        table.appendChild(tr);
    }

    container.replaceChildren(heading,table);
}





function replaceMay() {
    const container = document.getElementById("calendar-container");

    const heading = document.createElement("h2");
    heading.textContent = "May 2026";
    heading.className="calendar-header";

    const table=document.createElement("table");
    table.className="calendar-table";

    const headerRow=document.createElement("tr");
    headerRow.className="calendar-row";
    const daysOfWeek=["Mon","Tue","Wed","Thu","Fri","Sat","Sun"];
    for(let i=0;i<daysOfWeek.length;i++){
        const th=document.createElement("th");
        th.className="calendar-cell calendar-weekday";
        th.textContent=daysOfWeek[i];
        headerRow.appendChild(th);
    }
    table.appendChild(headerRow);

    // May 1, 2026 is Friday → 5th column
    const rows=[
        [null,null,null,null,1,2,3],
        [4,5,6,7,8,9,10],
        [11,12,13,14,15,16,17],
        [18,19,20,21,22,23,24],
        [25,26,27,28,29,30,31]
    ];

    for(let i=0;i<rows.length;i++){
        const tr=document.createElement("tr");
        tr.className="calendar-row";

        for(let j=0;j<rows[i].length;j++){
            if(rows[i][j]===null){
                const td=document.createElement("td");
                td.className="calendar-cell";
                tr.appendChild(td);
            } else {
                tr.appendChild(createDayCell(rows[i][j],"May"));
            }
        }
        table.appendChild(tr);
    }

    container.replaceChildren(heading,table);
}






function replaceJune() {
    const container=document.getElementById("calendar-container");

    const heading=document.createElement("h2");
    heading.textContent="June 2026";
    heading.className="calendar-header";

    const table=document.createElement("table");
    table.className="calendar-table";

    const headerRow=document.createElement("tr");
    headerRow.className="calendar-row";
    const daysOfWeek=["Mon","Tue","Wed","Thu","Fri","Sat","Sun"];
    for(let i=0;i<daysOfWeek.length;i++){
        const th=document.createElement("th");
        th.className="calendar-cell calendar-weekday";
        th.textContent=daysOfWeek[i];
        headerRow.appendChild(th);
    }
    table.appendChild(headerRow);

    // June 1, 2026 is Monday → first column
    const rows=[
        [1,2,3,4,5,6,7],
        [8,9,10,11,12,13,14],
        [15,16,17,18,19,20,21],
        [22,23,24,25,26,27,28],
        [29,30,null,null,null,null,null]
    ];

    for(let i=0;i<rows.length;i++){
        const tr=document.createElement("tr");
        tr.className="calendar-row";

        for(let j=0;j<rows[i].length;j++){
            if(rows[i][j]===null){
                const td=document.createElement("td");
                td.className="calendar-cell";
                tr.appendChild(td);
            } else {
                tr.appendChild(createDayCell(rows[i][j],"June"));
            }
        }
        table.appendChild(tr);
    }

    container.replaceChildren(heading,table);
}






function replaceJuly() {
    const container = document.getElementById("calendar-container");

    const heading = document.createElement("h2");
    heading.textContent = "July 2026";
    heading.className="calendar-header";

    const table=document.createElement("table");
    table.className="calendar-table";

    const headerRow=document.createElement("tr");
    headerRow.className="calendar-row";
    const daysOfWeek=["Mon","Tue","Wed","Thu","Fri","Sat","Sun"];
    for(let i=0;i<daysOfWeek.length;i++){
        const th=document.createElement("th");
        th.className="calendar-cell calendar-weekday";
        th.textContent=daysOfWeek[i];
        headerRow.appendChild(th);
    }
    table.appendChild(headerRow);

    // July 1, 2026 is Wednesday → 3rd column
    const rows=[
        [null,null,1,2,3,4,5],
        [6,7,8,9,10,11,12],
        [13,14,15,16,17,18,19],
        [20,21,22,23,24,25,26],
        [27,28,29,30,31,null,null]
    ];

    for(let i=0;i<rows.length;i++){
        const tr=document.createElement("tr");
        tr.className="calendar-row";

        for(let j=0;j<rows[i].length;j++){
            if(rows[i][j]===null){
                const td=document.createElement("td");
                td.className="calendar-cell";
                tr.appendChild(td);
            } else {
                tr.appendChild(createDayCell(rows[i][j],"July"));
            }
        }
        table.appendChild(tr);
    }

    container.replaceChildren(heading,table);
}





function replaceAugust() {
    const container=document.getElementById("calendar-container");

    const heading=document.createElement("h2");
    heading.textContent="August 2026";
    heading.className="calendar-header";

    const table=document.createElement("table");
    table.className="calendar-table";

    const headerRow=document.createElement("tr");
    headerRow.className="calendar-row";
    const daysOfWeek=["Mon","Tue","Wed","Thu","Fri","Sat","Sun"];
    for(let i=0;i<daysOfWeek.length;i++){
        const th=document.createElement("th");
        th.className="calendar-cell calendar-weekday";
        th.textContent=daysOfWeek[i];
        headerRow.appendChild(th);
    }
    table.appendChild(headerRow);

    // August 1, 2026 is Saturday → 6th column
    const rows=[
        [null,null,null,null,null,1,2],
        [3,4,5,6,7,8,9],
        [10,11,12,13,14,15,16],
        [17,18,19,20,21,22,23],
        [24,25,26,27,28,29,30],
        [31,null,null,null,null,null,null]
    ];

    for(let i=0;i<rows.length;i++){
        const tr=document.createElement("tr");
        tr.className="calendar-row";

        for(let j=0;j<rows[i].length;j++){
            if(rows[i][j]===null){
                const td=document.createElement("td");
                td.className="calendar-cell";
                tr.appendChild(td);
            } else {
                tr.appendChild(createDayCell(rows[i][j],"August"));
            }
        }
        table.appendChild(tr);
    }

    container.replaceChildren(heading,table);
}





function replaceSeptember() {
    const container=document.getElementById("calendar-container");

    const heading=document.createElement("h2");
    heading.textContent="September 2026";
    heading.className="calendar-header";

    const table=document.createElement("table");
    table.className="calendar-table";

    const headerRow=document.createElement("tr");
    headerRow.className="calendar-row";
    const daysOfWeek=["Mon","Tue","Wed","Thu","Fri","Sat","Sun"];
    for(let i=0;i<daysOfWeek.length;i++){
        const th=document.createElement("th");
        th.className="calendar-cell calendar-weekday";
        th.textContent=daysOfWeek[i];
        headerRow.appendChild(th);
    }
    table.appendChild(headerRow);

    // September 1, 2026 is Tuesday → 2nd column
    const rows=[
        [null,1,2,3,4,5,6],
        [7,8,9,10,11,12,13],
        [14,15,16,17,18,19,20],
        [21,22,23,24,25,26,27],
        [28,29,30,null,null,null,null]
    ];

    for(let i=0;i<rows.length;i++){
        const tr=document.createElement("tr");
        tr.className="calendar-row";

        for(let j=0;j<rows[i].length;j++){
            if(rows[i][j]===null){
                const td=document.createElement("td");
                td.className="calendar-cell";
                tr.appendChild(td);
            } else {
                tr.appendChild(createDayCell(rows[i][j],"September"));
            }
        }
        table.appendChild(tr);
    }

    container.replaceChildren(heading,table);
}






function replaceOctober() {
    const container=document.getElementById("calendar-container");

    const heading=document.createElement("h2");
    heading.textContent="October 2026";
    heading.className="calendar-header";

    const table=document.createElement("table");
    table.className="calendar-table";

    const headerRow=document.createElement("tr");
    headerRow.className="calendar-row";
    const daysOfWeek=["Mon","Tue","Wed","Thu","Fri","Sat","Sun"];
    for(let i=0;i<daysOfWeek.length;i++){
        const th=document.createElement("th");
        th.className="calendar-cell calendar-weekday";
        th.textContent=daysOfWeek[i];
        headerRow.appendChild(th);
    }
    table.appendChild(headerRow);

    // October 1, 2026 is Thursday → 4th column
    const rows=[
        [null,null,null,1,2,3,4],
        [5,6,7,8,9,10,11],
        [12,13,14,15,16,17,18],
        [19,20,21,22,23,24,25],
        [26,27,28,29,30,31,null]
    ];

    for(let i=0;i<rows.length;i++){
        const tr=document.createElement("tr");
        tr.className="calendar-row";

        for(let j=0;j<rows[i].length;j++){
            if(rows[i][j]===null){
                const td=document.createElement("td");
                td.className="calendar-cell";
                tr.appendChild(td);
            } else {
                tr.appendChild(createDayCell(rows[i][j],"October"));
            }
        }
        table.appendChild(tr);
    }

    container.replaceChildren(heading,table);
}




function replaceNovember() {
    const container=document.getElementById("calendar-container");

    const heading=document.createElement("h2");
    heading.textContent="November 2026";
    heading.className="calendar-header";

    const table=document.createElement("table");
    table.className="calendar-table";

    const headerRow=document.createElement("tr");
    headerRow.className="calendar-row";
    const daysOfWeek=["Mon","Tue","Wed","Thu","Fri","Sat","Sun"];
    for(let i=0;i<daysOfWeek.length;i++){
        const th=document.createElement("th");
        th.className="calendar-cell calendar-weekday";
        th.textContent=daysOfWeek[i];
        headerRow.appendChild(th);
    }
    table.appendChild(headerRow);

    // November 1, 2026 is Sunday → 7th column
    const rows=[
        [null,null,null,null,null,null,1],
        [2,3,4,5,6,7,8],
        [9,10,11,12,13,14,15],
        [16,17,18,19,20,21,22],
        [23,24,25,26,27,28,29],
        [30,null,null,null,null,null,null]
    ];

    for(let i=0;i<rows.length;i++){
        const tr=document.createElement("tr");
        tr.className="calendar-row";

        for(let j=0;j<rows[i].length;j++){
            if(rows[i][j]===null){
                const td=document.createElement("td");
                td.className="calendar-cell";
                tr.appendChild(td);
            } else {
                tr.appendChild(createDayCell(rows[i][j],"November"));
            }
        }
        table.appendChild(tr);
    }

    container.replaceChildren(heading,table);
}







function replaceDecember() {
    const container=document.getElementById("calendar-container");

    const heading=document.createElement("h2");
    heading.textContent="December 2026";
    heading.className="calendar-header";

    const table=document.createElement("table");
    table.className="calendar-table";

    const headerRow=document.createElement("tr");
    headerRow.className="calendar-row";
    const daysOfWeek=["Mon","Tue","Wed","Thu","Fri","Sat","Sun"];
    for(let i=0;i<daysOfWeek.length;i++){
        const th=document.createElement("th");
        th.className="calendar-cell calendar-weekday";
        th.textContent=daysOfWeek[i];
        headerRow.appendChild(th);
    }
    table.appendChild(headerRow);

    // December 1, 2026 is Tuesday → 2nd column
    const rows=[
        [null,1,2,3,4,5,6],
        [7,8,9,10,11,12,13],
        [14,15,16,17,18,19,20],
        [21,22,23,24,25,26,27],
        [28,29,30,31,null,null,null]
    ];

    for(let i=0;i<rows.length;i++){
        const tr=document.createElement("tr");
        tr.className="calendar-row";

        for(let j=0;j<rows[i].length;j++){
            if(rows[i][j]===null){
                const td=document.createElement("td");
                td.className="calendar-cell";
                tr.appendChild(td);
            } else {
                tr.appendChild(createDayCell(rows[i][j],"December"));
            }
        }
        table.appendChild(tr);
    }

    container.replaceChildren(heading,table);
}
