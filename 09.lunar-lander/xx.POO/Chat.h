#include <string>
using namespace std;

class Chat {
public:
    static int compteChatsVivants;

    Chat(int vies, string miaulement);
    void miauler();
    void dormir();
    void mourir();

private:
    int vies { 7 };
    string miaulement { "miaou" };
};

class Demo {
public:
    void fonctionPublique();
    int variablePublique;

private:
    void fonctionPrivee();
    int variablePrivee;
};