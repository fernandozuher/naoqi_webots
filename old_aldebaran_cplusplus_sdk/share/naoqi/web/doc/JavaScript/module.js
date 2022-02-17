/////////////////// COOKIE HANDLING

var toggles=new Array();

function toc_toggle(modname) {
    var spanred=document.getElementById('reduce_'+modname);
    var spanexp=document.getElementById('expand_'+modname);
    var subpart=document.getElementById('l_'+modname);
    var part=document.getElementById('m_'+modname);
    if (toggles[modname]) {
	spanexp.style.display='inline';
	spanred.style.display='none';
	subpart.style.display='none';
	try {
        part.style.backgroundColor='#FFF';
	    //part.style.backgroundColor='inherit';
	} catch(e) {
	}
	//part.style.borderColor='white';
	toggles[modname]=false;
    }else {
	spanexp.style.display='none';
	spanred.style.display='inline';
	subpart.style.display='block';
	//part.style.backgroundColor='white';
	//part.style.borderColor='#CCCCCC';
	toggles[modname]=true;
    }
    return true;
}

//TODO : Hide / Show TOC

function showHideTOC() {
    var show=document.getElementById('showTOCUpperSpan');
    var hide=document.getElementById('hideTOCUpperSpan');
    var toc=document.getElementById('tocMenu');
    var content=document.getElementById('pageContent');
    if (toc.style.display=='none') {
	hide.style.display='inline';
	show.style.display='none';
	toc.style.display='block';
	content.style.marginLeft='210px';
    } else {
	hide.style.display='none';
	show.style.display='inline';
	toc.style.display='none';
	content.style.marginLeft='0';
    }

}
