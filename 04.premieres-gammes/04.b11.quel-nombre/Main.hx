class Main {
	static function main() {
		var nombreChoisi = Std.random(100) + 1;
		trace(nombreChoisi);
		trace("QUEL EST LE BON NOMBRE ?");
		var victoire = false;
		var nbTentative = 0;

		while(!victoire) {
			nbTentative = nbTentative + 1;
			trace("Entrez un nombre entre 1 et 100");
			var proposition = Std.parseInt(Sys.stdin().readLine());
			trace(proposition);
			if (proposition > nombreChoisi && proposition <= 100)	{
				trace("Trop grand");
			}	else if (proposition < nombreChoisi && proposition >= 1) {
				trace("Trop petit");
			} else if (proposition == nombreChoisi) {
				victoire = true;
				trace("Gagné !");
				trace("Vous avez fait " + nbTentative + " tentatives.");
			} else {
				trace("Vous n'avez pas entré un nombre valide.");
			}
		}
	}
}
