#include <deque>
#include <iostream>
using namespace std;

void collectCards(deque<int>& winnerDeck, deque<int>& opponentGround,
                  deque<int>& winnerGround) {
    // 그라운드의 아래 카드부터 덱의 아래에 넣는다.
    while (!opponentGround.empty()) {
        winnerDeck.push_back(opponentGround.back());
        opponentGround.pop_back();
    }
    while (!winnerGround.empty()) {
        winnerDeck.push_back(winnerGround.back());
        winnerGround.pop_back();
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int cardCount, turnCount;
    cin >> cardCount >> turnCount;

    deque<int> doDeck, suDeck, doGround, suGround;
    for (int i = 0; i < cardCount; ++i) {
        int doCard, suCard;
        cin >> doCard >> suCard;
        doDeck.push_front(doCard);
        suDeck.push_front(suCard);
    }

    for (int turn = 0; turn < turnCount; ++turn) {
        bool doTurn = turn % 2 == 0;
        deque<int>& currentDeck = doTurn ? doDeck : suDeck;
        deque<int>& currentGround = doTurn ? doGround : suGround;

        currentGround.push_front(currentDeck.front());
        currentDeck.pop_front();
        if (currentDeck.empty()) {
            cout << (doTurn ? "su" : "do") << '\n';
            return 0;
        }

        if ((!doGround.empty() && doGround.front() == 5) ||
            (!suGround.empty() && suGround.front() == 5)) {
            collectCards(doDeck, suGround, doGround);
        } else if (!doGround.empty() && !suGround.empty() &&
                   doGround.front() + suGround.front() == 5) {
            collectCards(suDeck, doGround, suGround);
        }
    }

    if (doDeck.size() > suDeck.size()) cout << "do\n";
    else if (doDeck.size() < suDeck.size()) cout << "su\n";
    else cout << "dosu\n";

    return 0;
}
