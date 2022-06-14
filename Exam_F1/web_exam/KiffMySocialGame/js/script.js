// Menu déroulant de la nav bar pour la page Saisie_Avis.html
$(".dropdown-trigger").dropdown();

// connexion de la page par l'utilisateur

// fonction pour la limite de caractère
  $(document).ready(function() {
    $('input#input_text, textarea#textarea2').characterCounter();
  });



// tableau radio
  document.querySelector('form').addEventListener('change', function () 
  {
      var elts = document.querySelectorAll('input');
      for (var i = 0; i < elts.length; i++) {
        if ( elts[i].checked === true ) break;
      }
      console.log('value => '+elts[i].value);   
  });




function checkMail()
{
var champA = document.getElementById("champA").value;
var champB = document.getElementById("champB").value;
 
  if(champA != champB)
  {
    document.getElementById("erreur").innerHTML = "Erreur !";
  }
}

function Genre()
{
   var tab=["Homme","Femme"];
   var text='';
   var test=document.getElementById('genre');

   for (var i = 0; i < tab.length; i++)
   {
      text= text +"<center> <label>" + '<input class="with-gap" value="'+tab[i]+'" name="genre" type="radio" "'+ tab[i] +'">' + "<span>" + tab[i] + "</span>" + "</label></center>"
   }
   test.innerHTML=text
}

function jeux()
{
   var tab=["Jeux de dés", "Jeux d’adresse", "Jeux d’ambiance", "Jeux de cartes","eux de plateau", "Jeux de mémoire", "Jeux de connaissance", "Jeux de lettres", "Jeux éducatifs", "Jeux d’enquête", "Jeux de coopération", "Jeux de bluff", "Jeux de stratégie", "Jeux de gestion", "Jeux de hasard", "Jeux de rôle", "Jeux créatifs"];
   var text='';
   var test=document.getElementById('jeux');

   for (var i = 0; i < tab.length; i++)
   {
      text= text + "<center>" + "<label>" + '<input name="genre" value="'+tab[i]+'" type="checkbox" "'+ tab[i] +'">' + "<span>" + tab[i] + "</span>" + "</label>" + "</center>"
   }
   test.innerHTML=text
}


function avis()
{
   var tab=["Uno","Jungle Speed", "Domino"];
   var text='';
   var test=document.getElementById('avis');

   for (var i = 0; i < tab.length; i++)
   {
      text= text +"<center> <label>" + '<input class="with-gap" name="genre" value="'+tab[i]+'" type="radio" "'+ tab[i] +'">' + "<span>" + tab[i] + "</span>" + "</label></center>"
   }
   test.innerHTML=text
}


