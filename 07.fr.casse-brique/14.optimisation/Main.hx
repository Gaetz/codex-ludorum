import hxd.res.Sound;
import hxd.res.DefaultFont;
import h2d.Text;
import h2d.Font;
import hxd.Key;
import h2d.Tile;
import h2d.Bitmap;

class Main extends hxd.App {
	var BALLE_VITESSE = 5;
	var BALLE_TAILLE = 32;
	var BALLE_DEPART_X = 300;
	var BALLE_DEPART_Y = 400;
	var RAQUETTE_LARGEUR = 128;
	var RAQUETTE_HAUTEUR = 32;
	var RAQUETTE_VITESSE = 10;
	var RAQUETTE_Y = 520;
	var BRIQUE_LARGEUR = 100;
	var BRIQUE_HAUTEUR = 32;
	var BRIQUES_LIGNES = 5;
	var BRIQUES_COLONNES = 8;
	var BRIQUES_SEPARATEUR = 2;
	var VIES_DEPART = 3;
	var balle:Bitmap;
	var vitesseBalleX:Int;
	var vitesseBalleY:Int;
	var raquette:Bitmap;
	var briques:Array<Bitmap>;
	var vies:Int;
	var fonte:Font;
	var texteVies:Text;
	var texteNbVies:Text;
	var texteGameover:Text;
	var texteVictoire:Text;
	var nbBriques:Int;

	var sonDefaite:Sound;
	var sonRebondMur:Sound;
	var sonOut:Sound;
	var sonRebondBrique:Sound;
	var sonRecommencer:Sound;
	var sonVictoire:Sound;

	override function init() {
		// Balle
		var tileBalle = Tile.fromColor(0xFFFFFF, BALLE_TAILLE, BALLE_TAILLE);
		balle = new Bitmap(tileBalle, s2d);
		balle.x = BALLE_DEPART_X;
		balle.y = BALLE_DEPART_Y;
		vitesseBalleX = BALLE_VITESSE;
		vitesseBalleY = -BALLE_VITESSE;
		// Raquette
		var tileRaquette = Tile.fromColor(0xFFFFFF, RAQUETTE_LARGEUR, RAQUETTE_HAUTEUR);
		raquette = new Bitmap(tileRaquette, s2d);
		raquette.x = 300;
		raquette.y = RAQUETTE_Y;
		// Briques
		briques = new Array<Bitmap>();
		for (ligne in 0...BRIQUES_LIGNES) {
			for (colonne in 0...BRIQUES_COLONNES) {
				var tileBrique = Tile.fromColor(0xFFFFFF, BRIQUE_LARGEUR - BRIQUES_SEPARATEUR, BRIQUE_HAUTEUR - BRIQUES_SEPARATEUR);
				var brique = new Bitmap(tileBrique, s2d);
				brique.x = BRIQUE_LARGEUR * colonne;
				brique.y = BRIQUE_HAUTEUR * ligne;
				briques.push(brique);
			}
		}
		nbBriques = briques.length;
		// Vies
		vies = VIES_DEPART;
		fonte = DefaultFont.get();
		fonte.resizeTo(24);
		texteVies = new Text(fonte);
		texteVies.text = "Vies :";
		texteVies.x = 20;
		texteVies.y = 560;
		s2d.addChild(texteVies);
		texteNbVies = new Text(fonte);
		texteNbVies.text = Std.string(vies);
		texteNbVies.x = 90;
		texteNbVies.y = 560;
		s2d.addChild(texteNbVies);
		// Gameover
		texteGameover = new Text(fonte);
		texteGameover.text = "Game Over";
		texteGameover.x = s2d.width / 2 - 40;
		texteGameover.y = s2d.height / 2;
		texteGameover.visible = false;
		s2d.addChild(texteGameover);
		// Victoire
		texteVictoire = new Text(fonte);
		texteVictoire.text = "Victoire";
		texteVictoire.x = s2d.width / 2 - 40;
		texteVictoire.y = s2d.height / 2;
		texteVictoire.visible = false;
		s2d.addChild(texteVictoire);
		// Sons
		hxd.Res.initEmbed();
		sonDefaite = hxd.Res.sons.defaite;
		sonRebondMur = hxd.Res.sons.rebondMur;
		sonOut = hxd.Res.sons.out;
		sonRebondBrique = hxd.Res.sons.rebondBrique;
		sonRecommencer = hxd.Res.sons.recommencer;
		sonVictoire = hxd.Res.sons.victoire;
	}

	override function update(dt:Float) {
		// Game over
		if (vies <= 0) {
			if (!texteGameover.visible) {
				texteGameover.visible = true;
				sonDefaite.play();
			}
			if (Key.isPressed(Key.R)) {
				balle.x = BALLE_DEPART_X;
				balle.y = BALLE_DEPART_Y;
				vitesseBalleX = BALLE_VITESSE;
				vitesseBalleY = -BALLE_VITESSE;
				vies = VIES_DEPART;
				texteNbVies.text = Std.string(vies);
				texteGameover.visible = false;
				sonRecommencer.play();
			}
		}
		// Victoire
		else if (nbBriques <= 0) {
			if (!texteVictoire.visible) {
				texteVictoire.visible = true;
				sonVictoire.play();
			}
			if (Key.isPressed(Key.R)) {
				balle.x = BALLE_DEPART_X;
				balle.y = BALLE_DEPART_Y;
				vitesseBalleX = BALLE_VITESSE;
				vitesseBalleY = -BALLE_VITESSE;
				vies = VIES_DEPART;
				texteNbVies.text = Std.string(vies);
				for (brique in briques) {
					brique.visible = true;
				}
				nbBriques = briques.length;
				texteVictoire.visible = false;
				sonRecommencer.play();
			}
		}
		// Jeu
		else {
			// Mouvement balle
			balle.x = balle.x + vitesseBalleX;
			balle.y = balle.y + vitesseBalleY;
			// Balle bondissante
			if (balle.x + BALLE_TAILLE > s2d.width) {
				balle.x = s2d.width - BALLE_TAILLE;
				vitesseBalleX = -vitesseBalleX;
				sonRebondMur.play();
			}
			if (balle.x < 0) {
				balle.x = 0;
				vitesseBalleX = -vitesseBalleX;
				sonRebondMur.play();
			}
			if (balle.y < 0) {
				balle.y = 0;
				vitesseBalleY = -vitesseBalleY;
				sonRebondMur.play();
			}
			// Mouvement raquette
			if (Key.isDown(Key.Q)) {
				raquette.x = raquette.x - RAQUETTE_VITESSE;
				if (raquette.x < 0) {
					raquette.x = 0;
					sonRebondMur.play();
				}
			}
			if (Key.isDown(Key.D)) {
				raquette.x = raquette.x + RAQUETTE_VITESSE;
				if (raquette.x + RAQUETTE_LARGEUR > s2d.width) {
					raquette.x = s2d.width - RAQUETTE_LARGEUR;
					sonRebondMur.play();
				}
			}
			// Rebond balle-raquette
			var bornesRaquette = raquette.getBounds();
			var bornesBalle = balle.getBounds();
			if (bornesRaquette.intersects(bornesBalle)) {
				balle.y = RAQUETTE_Y - BALLE_TAILLE;
				vitesseBalleY = -vitesseBalleY;
				sonRebondMur.play();
			}
			// Collisions balle-brique
			var colonneBrique:Int = Std.int((balle.x + BALLE_TAILLE / 2) / BRIQUE_LARGEUR);
			var ligneBrique:Int = Std.int(balle.y / BRIQUE_HAUTEUR);
			var index = coordBriqueVersIndex(ligneBrique, colonneBrique);
			var briqueCollision = briques[index];
			if (briqueCollision != null && briqueCollision.visible) {
				vitesseBalleY = -vitesseBalleY;
				briqueCollision.visible = false;
				nbBriques = nbBriques - 1;
				if (nbBriques > 0) {
					sonRebondBrique.play();
				}
			}
			// Perte vie
			if (balle.y > s2d.height) {
				// Enlever une vie
				vies = vies - 1;
				if (vies > 0) {
					sonOut.play();
				}
				texteNbVies.text = Std.string(vies);
				// Replacer la balle
				balle.y = raquette.y - BALLE_TAILLE;
				balle.x = raquette.x + RAQUETTE_LARGEUR / 2 - BALLE_TAILLE / 2;
				vitesseBalleY = -vitesseBalleY;
			}
		}
	}

	function coordBriqueVersIndex(ligneBrique, colonneBrique) {
		return ligneBrique * BRIQUES_COLONNES + colonneBrique;
	}

	static function main() {
		new Main();
	}
}
