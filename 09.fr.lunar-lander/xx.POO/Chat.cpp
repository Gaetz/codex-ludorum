#include "Chat.h"

int Chat::compteChatsVivants = 0;

Chat::Chat(int viesP, string miaulementP)
    : vies { viesP }, miaulement { miaulementP }
{
    compteChatsVivants = compteChatsVivants + 1;
}

void Chat::miauler() {
    cout << "Il me reste " << vies << " vies. "
         << miaulement << " !" << endl;
}

void Chat::dormir() {
    cout << "..." << endl;
}

void Chat::mourir() {
    vies = vies - 1;
}