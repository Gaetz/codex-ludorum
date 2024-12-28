class Main {
	static function main() {
		var chosenNumber = Std.random(100) + 1;
		trace(chosenNumber);
		trace("WHAT IS THE RIGHT NUMBER?");
		var victory = false;
		var nbTry = 0;

		while(!victory) {
			nbTry = nbTry + 1;
			trace("Input a number between 1 and 100");
			var proposal = Std.parseInt(Sys.stdin().readLine());
			trace(proposal);
			if (proposal > chosenNumber && proposal <= 100)	{
				trace("Too big");
			}	else if (proposal < chosenNumber && proposal >= 1) {
				trace("Too small");
			} else if (proposal == chosenNumber) {
				victory = true;
				trace("Won!");
				trace("Vous avez fait " + nbTry + " tentatives.");
			} else {
				trace("You did not enter a valid number.");
			}
		}
	}
}
