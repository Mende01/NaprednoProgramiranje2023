#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <random>


using namespace std;


// Strukturiranje na kartite!
struct Card {
    string suit;
    string rank;
};


// Funkcija za da se kreirat i inicijalizirat pedeset i dve karti!
vector<Card> createDeck() {
    vector<Card> deck;

    string suits[] = {"Hearts", "Clubs", "Diamonds", "Spades"};
    string ranks[] = {"Ace", "2", "3", "4", "5", "6", "7", "8", "9", "10", "Jack", "Queen", "King"};

    for (int i = 0; i < 4; i++) {
        for (int j = 0; j < 13; j++) {
            Card card;
            card.suit = suits[i];
            card.rank = ranks[j];
            deck.push_back(card);
        }
    }

    return deck;
}


// Funkcija za da se dodadat dvata dzokeri!
void addJokers(vector<Card>& deck) {
    Card joker1;
    joker1.suit = "Joker";
    joker1.rank = "1";
    deck.push_back(joker1);

    Card joker2;
    joker2.suit = "Joker";
    joker2.rank = "2";
    deck.push_back(joker2);
}


// Funkcija za da se ispise spilot na karti!
void printDeck(vector<Card>& deck) {
    for (int i = 0; i < deck.size(); i++) {
        cout << deck[i].rank << " of " << deck[i].suit << endl;
    }
}


// Funkcija za da se izmesa spilot!
void shuffleDeck(vector<Card>& deck) {
    random_device rd;
    mt19937 rng(rd());

    for (int i = deck.size() - 1; i > 0; i--) {
        uniform_int_distribution<int> distr(0, i);
        int j = distr(rng);
        swap(deck[i], deck[j]);
    }
}


// Funkcija za da se dodelat kartite do igracite!
void dealCards(vector<Card>& deck, vector<vector<Card>>& players) {
    int numPlayers = players.size();
    int numCardsPerPlayer = deck.size() / numPlayers;

    for (int i = 0; i < numPlayers; i++) {
        for (int j = 0; j < numCardsPerPlayer; j++) {
            players[i].push_back(deck[i*numCardsPerPlayer + j]);
        }
    }
}

// Funkcija za da se dodalat kartite do igracite!
void printHands(vector<vector<Card>>& players) {
    for (int i = 0; i < players.size(); i++) {
        cout << i+1 << ". Igrachot" << " gi sodrzhi kartite: ";
        for (int j = 0; j < players[i].size(); j++) {
            cout << players[i][j].rank << " of " << players[i][j].suit << " ";
        }
        cout << endl;
    }
}

int main() 
{
 
    // Kreiranje i inicijaliziranje na spil na karti!
    vector<Card> deck = createDeck();
    addJokers(deck);


    // Se pecati spilot na karti!
    cout << "Sortiran shpil na karti:" << endl;
    printDeck(deck);


    // Potreba da se ispise "shuffle" za spilot da e izmesan!
    cout << "Napishi 'shuffle' za da go izmeshash shpilot na karti." << endl;
    string input;
    cin >> input;

    if (input == "shuffle") {
        // Mesanje na spilot!
        shuffleDeck(deck);
        cout << "Shpilot e izmeshan." << endl;


        // Se dodeluvaat kartite na igracite!
        vector<vector<Card>> players(4);
        dealCards(deck, players);


        // Se pecatat kartite na igracite!
        printHands(players);
    }

    return 0;
}
