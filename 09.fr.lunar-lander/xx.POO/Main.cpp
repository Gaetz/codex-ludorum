#include "Chat.h"

int main() {
    Chat felix { 7, "Meow" };
    Chat miaouss { 7, "Miaouss" };
    // On utilise la fonction miauler de chacun
    felix.miauler();
    miaouss.miauler();
    // Un épisode se termine mal
    miaouss.mourir();
    // On demande à nouveaux aux chats de miauler
    felix.miauler();
    miaouss.miauler();

    cout << Chat::compteChatsVivants << endl;
}

