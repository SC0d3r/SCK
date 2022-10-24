function makeTextSelectable(){
    const ps = $("p")
    for(var i=0; i<ps.length;i++){
        var elementState = $(ps[i]).css('user-select','auto');
    }
}
