/* 
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/ClientSide/javascript.js to edit this template
 */

let $li = $("#instructionsList > li");
let $input = $("textarea[name^=\"message\"]");

$(document).ready(function(){
    $li.attr("draggable", "true"); /* Adds the "draggable = true" attributes to the instructionList items */
	
    $li.on("dragstart", namePartListItemDragStartEventHandler);
	$input.on("drop", addInstructionsEventHandler);
	
    test();
    removeLine();
})





function namePartListItemDragStartEventHandler(event){
    (event.originalEvent || event).dataTransfer.setData("text", $(this).text());

}



function addInstructionsEventHandler(event){
    let namePart = (event.originalEvent || event).dataTransfer.getData("text");
    let existingTextInFullNameTextBox = $(this).val().trim();

    if (existingTextInFullNameTextBox === ""){
        $(this).val(namePart);
    }else{
        $(this). val(existingTextInFullNameTextBox + "\n" + namePart);
    }
    event.preventDefault();
}



function test(){
        document.getElementById('instructions').addEventListener('keydown', function(e){
        if (e.which != 8/* backspace*/){
            e.preventDefault();
            return false;
        }
    }, false);
}

function eraseText(){
    document.getElementById("instructions").value="";
}