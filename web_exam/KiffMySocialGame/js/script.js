
/*
function identification()
{
   document.getElementById('ident').innerHTML = 
   `
      <section>
         <div class="formulaire">
            <h4>identité</h4>
            <form action="" method="get">
               <fieldset>
                  <div>
                     <center><label for="name" class="required" >Entrez votre nom: </label></center>
                     <input type="text" name="name" id="name" placeholder="nom" required >
                  </div>
                  <div>
                     <center><label for="name" class="required">Entrez votre prénom: </label></center>
                     <input type="text" name="last_name" id="last_name" placeholder="prénom" required>
                  </div>

                   <br>
                  <div id="genre"></div>
                  <br>

                  <div>
                     <center><label for="mail" class="required">Saisir votre mail:</label></center>
                     <input type="email" name="champA" id="champA" placeholder="mail" required>
                  </div>
                  <div>
                     <center><label for="mail2" class="required">Saisir à nouveau votre mail:</label></center>
                     <input type="email" name="champB" id="champB" placeholder="mail" onblur="checkMail()"required>
                     <div id="erreur" style= "color:red"></div>
                  </div>
                  <div>
                     <center><label for="ddn" class="required">Selectionnez votre date de naissance:</label></center>
                     <input type="date" name="ddn" id="ddn" required>
                  </div>
                  <div>
                     <center><label for="ddn">Saisir votre adresse postal:</label></center>
                     <input type="text" name="adresse" id="adresse" placeholder="optionnel">
                  </div>
                  <div>
                     <center><label for="tel">Saisir votre numéro de téléphone:</label></center>
                     <input type="text" name="tel" id="tel" placeholder="optionnel" pattern="[0-9]{3}-[0-9]{2}-[0-9]{3}">

                     <input type="submit" value="submit" >
                  </div>
               </fieldset>
            </form>
         </div>
      </section>


   `
}identification();

function Préférence()
{
   document.getElementById('pref').innerHTML =

   `
      <div class="formulaire">
            <h4>Préférence de jeux</h4>
            <form action="" method="get">
               <fieldset>
               <div>
                     <center><label>Quels est votre type de jeu de société favoris:</label>

                        <div id="jeux"></div>

                     <input type="submit" value="submit" onclick="checkButton() transfert()" >
               </div>
               </fieldset>
            </form>
         </div>
   `
}Préférence();

function Avis()
{
   document.getElementById('Avis').innerHTML =

   `
    <div class="formulaire">
            <h4>Avis</h4>
            <form>
               <fieldset>
                  <p>
                     <div id="avis"></div>

                        <p class="range-field">
                           <center><label>noter le jeu sur 5</label></center>
                                 <input type="range" id="test5" min="0" max="5" />
                           </p>
                        <center><label for="textarea2">Saisir votre avis</label></center>
                        <textarea id="textarea2" class="materialize-textarea" data-length="200" required></textarea>

                     <input type="submit" value="submit" onclick="checkButton() transfert()" >
                  </p>
                  </fieldset>
               </form>
         </div>
   `
}Avis();

function Genre()
{
   var tab=["Homme","Femme"];
   var text='';
   var test=document.getElementById('genre');

   for (var i = 0; i < tab.length; i++)
   {
      text= text + '<input name="genre" value="'+tab[i]+'" type="radio" "'+tab[i] +'">'+ "<span>" + tab[i] + "</span>"
   }
   test.innerHTML=text
}Genre();

function jeux()
{
   var tab=["Jeux de dés", "Jeux d’adresse", "Jeux d’ambiance", "Jeux de cartes","eux de plateau", "Jeux de mémoire", "Jeux de connaissance", "Jeux de lettres", "Jeux éducatifs", "Jeux d’enquête", "Jeux de coopération", "Jeux de bluff", "Jeux de stratégie", "Jeux de gestion", "Jeux de hasard", "Jeux de rôle", "Jeux créatifs"];
   var text='';
   var test=document.getElementById('jeux');

   for (var i = 0; i < tab.length; i++)
   {
      text= text + "<center>" + "<label>" + '<input name="genre" value="'+tab[i]+'" type="checkbox" "'+ tab[i] +'">' + "<span>" + tab[i] + "</span>" + "</label>" + "</center>"
   }
   test.innerHTML=text;
}jeux();

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
}avis();

*/

//test code web

   // création de constante

   const form = document.getElementById('form');
   const username = document.getElementById('username');
   const mdp = document.getElementById('mdp');
   const email = document.getElementById('email');
   const mdp2 = document.getElementById('mdp2');




   // mes fonction

   // fonction qui check si les inputs sont valide ou non
   function checkInputs()
   {
      // on récupère les valeurs des inputs
      const usernameValue = username.value;
      const mdpValue = mdp.value;
      const emailValue =email.value;


      // message d'erreur pour le prenom
      if(usernameValue === '')
      {
         // on montre l'erreur

         // on ajoute la fonction d'affichage d'erreur
         setErrorFor(username, "le prenom n'est pas valide");
      }else
      {
         // on ajoute la fonction d'affichage de succes
         setSuccessFor(username);
      }

      // message d'erreur pour l'email
      if(emailValue === '')
      {
         // on montre l'erreur

         // on ajoute la fonction d'affichage erreur
         setErrorFor(email, "le mail n'est pas valide");
      }else if(!isEmail(emailValue))
      {
         setErrorFor(email, "email n'est pas valide");
      }else  
      {
         setSuccessFor(email);
      }

      // message d'erreur pour le mot de passe
      if(mdpValue ==='')
      {
         setErrorFor(mdp, "mot de passe incorrect");
      }else
      {
         setSuccessFor(mdp);
      }
   }

   // fonction d'affichage des inputs non valide
   function setErrorFor(input, message)
   {
      // on récupère la classe CSS form-control
      const formControl = input.parentElement; // correspond à la classe form-control
      // on récupère le messge d'erreur
      const small = formControl.querySelector('small');

      // on ajoute le message d'erreur
      small.innerText = message;

      // on ajoute la classe erreur
      formControl.className = 'form-control erreur';

   }

   // fonction d'affichage des inputs valides
   function setSuccessFor(input)
   {
      // on récupère la classe CSS form-controle
      const formControl = input.parentElement;
      // on ajoute la classe succes
      formControl.className = 'form-control succes';
   }

   // fonction de validation de l'email
   function isEmail(email)
   {
      return /^(([^<>()\[\]\\.,;:\s@"]+(\.[^<>()\[\]\\.,;:\s@"]+)*)|(".+"))@((\[[0-9]{1,3}\.[0-9]{1,3}\.[0-9]{1,3}\.[0-9]{1,3}])|(([a-zA-Z\-0-9]+\.)+[a-zA-Z]{2,}))$/.test(email);
   }
  
  // fonction qui affiche sur la page web la liste des checkbox à coché
   function ListGame()
   {
      // on récupère l'idée de l'endroit ou on veut afficher le contenue de la liste
      document.getElementById('game').innerHTML =
      `
         <div class="form-control">
                     <center><label for="username">Selectionnez vos type de jeu favoris</label></center>
                       
                              <input type="checkbox" name="jeux" value="Jeux de dés">
                           <span >Jeux de dès</span>

                        <input type="checkbox" name="jeux" value="Jeux d’adresse">
                           <span >Jeux d’adresse</span>

                        <input type="checkbox" name="jeux" value="Jeux d’ambiance">
                           <span >Jeux d’ambiance</span>

                        <input type="checkbox" name="jeux" value="Jeux de cartes">
                           <span >Jeux de cartes</span>

                        <input type="checkbox" name="jeux" value="Jeux de plateau">
                           <span >Jeux de plateau</span>

                        <input type="checkbox" name="jeux" value="Jeux de mémoire">
                           <span >Jeux de mémoire</span>

                        <input type="checkbox" name="jeux" value="Jeux de connaissance">
                           <span >Jeux de connaissance</span>
                        
                        

                        <input type="checkbox" name="jeux" value="Jeux de lettres">
                           <span>Jeux de lettres</span>

                        <input type="checkbox" name="jeux" value="Jeux éducatifs">
                           <span>Jeux éducatifs</span>

                        <input type="checkbox" name="jeux" value="Jeux d’enquête">
                           <span>Jeux d’enquête</span>

                        <input type="checkbox" name="jeux" value="Jeux de coopération">
                           <span>Jeux de coopération</span>

                        <input type="checkbox" name="jeux" value="Jeux de bluff">
                           <span>Jeux de bluff</span>

                        <input type="checkbox" name="jeux" value="Jeux de stratégie">
                           <span>Jeux de stratégie</span>

                        <input type="checkbox" name="jeux" value="Jeux de gestion">
                           <span>Jeux de gestion</span>

                        <input type="checkbox" name="jeux" value="Jeux de hasard">
                           <span>Jeux de hasard</span>

                        <input type="checkbox" name="jeux" value="Jeux de rôle">
                           <span>Jeux de rôle</span>

                        <input type="checkbox" name="jeux" value="Jeux créatifs">
                           <span>Jeux créatifs</span>
                  </div>
      `
   }ListGame();

// fonction qui affiche sur la page web la liste des checkbox à coché
   function ListGender()
   {
      // on récupère l'idée de l'endroit ou on veut afficher le contenue de la liste
      document.getElementById('gender').innerHTML =
      `
         <div class="form-control">
                  <label for="username">Selectionner votre genre</label>
                     <input type="radio" name="genre" value="homme">
                        <span>Homme</span>
                     <input type="radio" name="genre" value="femme">
                        <span>Femme</span>
               </div>
      `
   }ListGender()

   // fonction qui affiche sur la page web la liste des checkbox à coché
   function ListCritics()
   {
      // on récupère l'idée de l'endroit ou on veut afficher le contenue de la liste
      document.getElementById('critics').innerHTML =
      `
         <div class="form-control">
                  <label for="username">Selectionner votre jeu à critiquer</label>
                     <input type="radio" name="critique" value="uno">
                        <span>Uno</span>
                     <input type="radio" name="critique" value="Dame">
                        <span>Dame</span>
                     <input type="radio" name="critique" value="echecs">
                        <span>Echecs</span>
         </div>
      `
   }ListCritics()

