/* global Cookies */
var cookies = Cookies.getJSON();

window.onload  = () => {
  if (cookies.references === undefined) {
    Cookies.set('references', []);
    cookies = Cookies.getJSON();
  }
  updateRef('references');
};

var quickRef = document.getElementById("quickRef");
var addRef = document.getElementById("addRef");


function updateRef(refname) {
  quickRef.innerHTML = "";
  Cookies.set(refname, cookies[refname]);
  for (var i = 0; i < cookies[refname].length; i++) {
    quickRef.innerHTML += '<li"><button onClick="popRef(\'references\', '+ i
    + ')" class="delref">x</button> <a href="' + cookies[refname][i].link + '">'
    + cookies[refname][i].name + '</a></li><br />';
  }
  quickRef.innerHTML += "</ul>"
}

function popRef(refname, idx) {
  cookies[refname].splice(idx, 1);
  updateRef(refname);
}

function newRef(){cookies.references.push({"name": document.getElementsByTagName("title")[0].textContent,"link": window.location.pathname});updateRef('references');}