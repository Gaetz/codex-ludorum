class Chat { 
  var vies :Int;
  public var miaulement(default, null) :String;

  public static var compteChatsVivants = 0;

  public function new(vies, miaulement) {
    this.vies = vies;
    this.miaulement = miaulement;
    compteChatsVivants++;
  }

  public function miauler() {
    trace("Il me reste " + vies + " vies. " + miaulement + " !");
  }

  public function dormir() {
    trace("...");
  }

  public function mourir() {
    vies = vies - 1;
    if(vies <= 0) {
      compteChatsVivants = compteChatsVivants - 1;
    }
  }
}