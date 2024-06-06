class Solution {
public:
    bool isNStraightHand(vector<int>& hand, int groupSize) {
        int n = hand.size();
        if (n % groupSize != 0) {
            return false;
        }

        // Step 1: Count the frequency of each card
        map<int, int> cardCount;
        for (int card : hand) {
            cardCount[card]++;
        }

        // Step 2: Try to form the groups
        for (auto it = cardCount.begin(); it != cardCount.end(); ++it) {
            int card = it->first;
            int count = it->second;

            // If there are cards of this value, try to form groups
            if (count > 0) {
                for (int i = 0; i < groupSize; ++i) {
                    int currentCard = card + i;
                    if (cardCount[currentCard] < count) {
                        return false;
                    }
                    cardCount[currentCard] -= count;
                }
            }
        }

        return true;
    }
};