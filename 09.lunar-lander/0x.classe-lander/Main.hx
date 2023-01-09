import h2d.Text;
import h2d.Font;

class Main extends hxd.App {

	static function main() {
		new Main();
	}
  
  var description:Text;
  var fonte:Font;

	override function init() {
    fonte = hxd.res.DefaultFont.get();
    description = new h2d.Text(fonte, s2d);
		description.text = "Hello World!";
	}
}
