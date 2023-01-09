class Main {

  static function main() {
    var felix = new Chat(7, "Meow");
    var miaouss = new Chat(7, "Miaouss");
    // On utilise la fonction miauler de chacun
    felix.miauler();
    miaouss.miauler();
    // Un épisode de Pokemon se passe mal
    miaouss.mourir();
    // On demande à nouveaux aux chats de miauler
    felix.miauler();
    miaouss.miauler();
    // On décompte le nombre de chats vivants
    trace("Chats vivants : "+ Chat.compteChatsVivants);
  }
  
}