# La Polo de Jarod
Ce sera un jeu programmé en SDL. Un jeu arcade de type endless runner game, tel que Subway Surfers, Frogger.

## Inspiration:
<img width="605" alt="image" src="https://github.com/user-attachments/assets/6fdd9311-8975-4d16-b1ce-9b89a3fd0338">

<img width="200" alt="image" src="https://external-content.duckduckgo.com/iu/?u=https%3A%2F%2F66.media.tumblr.com%2Ff708fae33ab08f9925f20378503a9758%2Ftumblr_mhb6zjbkhR1qh8rq6o1_500.gif&f=1&nofb=1&ipt=4acf48ae2cd4ff2cb79215daa5f1b5965c043337e9e776b01d1a5ae82b82c5ab&ipo=images">


## Répartition des tâches

Comme nous avons plusieurs objets, nous allons les répartir par personne. Avant de répartir qui va décrire chaque objet, nous allons parler pour voir s’ils sont vraiment nécessaires

### Liste objets:

|   |   |   |   |
|---|---|---|---|
|Classes|C’est quoi?|Attributes|Méthodes|
|Voiture <br><br>player|L’objet du joueur, qui doit contenir sa quantité de points, argent, état bonus.|- Quantité d'essence.<br>    <br>- Bônus actif<br>    <br>-||
|Player|Représente le joueur comme un compte, contenant ses données personnelles et sa progression.|- nom (std::string) : Nom du joueur.<br>    <br>- id (int) : Identifiant unique du joueur.<br>    <br>- score (int) : Score actuel du joueur.<br>    <br>- highScore (int) : Meilleur score réalisé par le joueur.<br>    <br>- inventaireVoitures (std::vector<Voiture>) : Liste des voitures possédées par le joueur.<br>    <br>- voitureActive (VoiturePlayer) : La voiture actuellement utilisée par le joueur.|changerVoitureActive(Voiture& nouvelleVoiture) : Permet de sélectionner une autre voiture.<br><br>mettreAJourHighScore() : Compare le score actuel avec le meilleur score et met à jour si nécessaire.|
|Bonus / Malus|La liste de bonus et ses effets.|-||
|Liste voitures|Liste avec tous les voitures dans le jeu|- Nom<br>    <br>- Marque<br>    <br>- Couleur<br>    <br>- Prix<br>    <br>- Achetable (bool : oui -> voiture player, non -> voiture NPC)<br>    <br>- Son klaxoon||
|Enemies||- Voiture<br>    <br>- Position||
|Piste||-||
|Portefeuille/Inventory||-||
|État des jeux|Représente l’état global du jeu, comprenant les paramètres et la progression en cours.|- estEnPause (bool) : Indique si le jeu est en pause.|mettreEnPause() : Active l’état de pause.<br><br>reprendreJeu() : Relance le jeu après une pause.|
|Voiture|Une voiture générique, qu’elle soit celle du joueur ou un ennemi sur la piste.|- nom (std::string) : Nom de la voiture.<br>    <br>- marque (std::string) : Marque de la voiture.<br>    <br>- couleur (std::string) : Couleur de la voiture.<br>    <br>- prix (float) : Prix d’achat.<br>    <br>- estAchetable (bool) : Indique si la voiture peut être achetée ou non.<br>    <br>- position (float) : Position sur la piste.<br>    <br>- piste (int) : Numéro de la piste où se trouve la voiture.<br>    <br>- sonKlaxon (std::string) : Le son émis par le klaxon.<br>    <br>-|klaxonner() : Émet le son du klaxon.<br><br>avancer(float distance) : Déplace la voiture sur la piste.<br><br>changerPiste(int nouvellePiste) : Change la piste actuelle.|


## Instructions d'installation
### Installation de la librarie SDL
1. Télécharger depuis le site officiel et suivre les instructions: [Site Officiel](https://github.com/libsdl-org/SDL/releases/tag/release-2.30.11)
### Installation du jeu
1. Télecharger les fichiers depuis GitHub et deziper.
2. Placer dans le dossier où vous le voulez.

## Instructions de compilation
### Sur Mac :
1. **Aller dans le dossier du projet:** cd Users\[cheminDuProjet]
2. **Compiler le projet avec:** g++ -std=c++17 -I/Library/Frameworks/SDL2.framework/Headers -F/Library/Frameworks -framework SDL2 main.cpp -o main
3. **Executer le projet:** Utiliser le debugger de base de VS Code.